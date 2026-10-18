#include "app.h"
#include "lib/netlib/netlib.h"
#include "src/global/gdefine.h"
#include "lib/baselib/baselib.h"

void app::run()
{
	//创建socket
	//create socket
	main_socket = netlib::make_socket(APP_PORT, false);
	printf("<app> run at port [%d]\n", netlib::get_port(main_socket));

	//执行tick事件
	//execute tick event
	auto last_time = std::chrono::high_resolution_clock::now();
	while (true)
	{
		auto now_time = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> duration = now_time - last_time;

		const float delta_time = duration.count();
		tick(delta_time);

		last_time = now_time;
	}
}

std::string app::to_string()
{
    std::lock_guard<std::mutex> lock(session_mutex);
	//遍历session列表序列化到string
	//iterate session list and serialize to string
	std::string value = "";
	for (session* ses : session_list)
	{
		value += ses->to_string() + "/";
	}
	return value;
}

std::string app::ask_addr(const std::string id, const std::string pass)
{
    std::lock_guard<std::mutex> lock(session_mutex);
	//遍历session列表
	//iterate session list
	for (session* ses : session_list)
	{
		//找到id对应的session
		//find session by id
		if (ses->id == id)
		{
			//判断密码是否正确或者不需要密码
			//check password or no password required
			if (ses->password == "" || ses->password == pass)
			{
				return std::to_string(netlib::get_port(ses->listen_socket));
			}
			break;
		}
	}
	return "error";
}

void app::handle(const char* buffer, int recvlen, const sockaddr_in& addr)
{
	//分割接收的字符串
	//split received string
	std::string temp_str(buffer, recvlen);
	std::vector<std::string> param = baselib::split_string(temp_str, '/');

	//如果参数数量<=0则直接抛弃
	//discard if param size <= 0
	if (param.size() <= 0)
	{
		return;
	}
	//如果为@id则用do_id接管
	//if @id then use do_id
	if (param[0] == "@id" && param.size() == 1)
	{
		do_id(param, buffer, recvlen, addr);
		return;
	}
	//如果为@reg则用do_reg接管
	//if @reg then use do_reg
	if (param[0] == "@reg" && param.size() == 4)
	{
		do_reg(param, buffer, recvlen, addr);
		return;
	}
	printf("error recv : %s\n", std::string(buffer, recvlen).c_str());
}

void app::do_id(const std::vector<std::string>& param, const char* buffer, int recvlen, const sockaddr_in& addr)
{
	//获取一个新id并且发回
	//get new id and send back
	std::string id = "@id/" + std::to_string(new_player_id());
	netlib::send(main_socket, addr, id.c_str(), (int)id.size());
}

void app::do_reg(const std::vector<std::string>& param, const char* buffer, int recvlen, const sockaddr_in& addr)
{
    std::lock_guard<std::mutex> lock(session_mutex);
	//获取传入的参数列表
	//get param list
	const std::string id = param[1];
	const std::string pass = param[2];
	const std::string prop = param[3];

	//遍历列表
	//iterate list
	for (session* ses : session_list)
	{
		//如果找到session则重置死亡计时并且将对应的port发回
		//if found session then reset death timer and send port back
		if (ses->is_me(id))
		{
			ses->resume_time();
			ses->property = prop;
			const std::string sendback = "@os/" + std::to_string(netlib::get_port(ses->owner_socket));
			netlib::send(main_socket, addr, sendback.c_str(), (int)sendback.size());
			return;
		}
	}

	//如果未找到则创建一个新的session
	//if not found then create new session
	session* new_ses = new session();
	new_ses->id = id;
	new_ses->password = pass;
	new_ses->property = prop;
	new_ses->resume_time();
	session_list.emplace_back(new_ses);
	new_ses->run();
}

int app::new_player_id()
{
	//累加并返回玩家id
	//increment and return player id
	player_id++;
	return player_id;
}

void app::tick(const float& delta_time)
{
	//tick执行
	//tick execute
	tick_recv();
	tick_timer(delta_time);
}

void app::tick_recv()
{
	//接收消息并且给handle接管
	//receive message and pass to handle
	char buffer[2048] = { 0 };
	sockaddr_in addr = sockaddr_in();
	int recvlen = -1;
	if (netlib::recv(main_socket, buffer, sizeof(buffer), addr, recvlen))
	{
		handle(buffer, recvlen, addr);
	}
}

void app::tick_timer(const float& delta_time)
{
	//计时器
	//timer
	static float timer = 0;
	timer += delta_time;
	if (timer < 1)
	{
		return;
	}
	timer = 0;

	//先在锁内推进计时、把死亡session移出列表，再在锁外销毁
	//destroy()里会join线程，持锁等待会和msg线程一起卡死
	//advance timers and detach dead sessions under the lock, then destroy
	//outside it: destroy() joins a thread, and joining while holding the
	//mutex would stall the browser threads too
	std::vector<session*> dead;
	{
		std::lock_guard<std::mutex> lock(session_mutex);
		for (session* ses : session_list)
		{
			ses->do_timer();
		}
		for (auto it = session_list.begin(); it != session_list.end();)
		{
			if ((*it)->is_dead())
			{
				dead.push_back(*it);
				it = session_list.erase(it);
			}
			else
			{
				++it;
			}
		}
	}

	for (session* ses : dead)
	{
		ses->destroy();
	}
}