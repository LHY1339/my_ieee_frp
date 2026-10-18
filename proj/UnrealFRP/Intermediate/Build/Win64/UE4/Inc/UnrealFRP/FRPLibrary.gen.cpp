// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealFRP/Source/FRPLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFRPLibrary() {}
// Cross Module References
	UNREALFRP_API UClass* Z_Construct_UClass_UFRPLibrary_NoRegister();
	UNREALFRP_API UClass* Z_Construct_UClass_UFRPLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_UnrealFRP();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	UNREALFRP_API UFunction* Z_Construct_UDelegateFunction_UnrealFRP_OnAddrUpdate__DelegateSignature();
	UNREALFRP_API UFunction* Z_Construct_UDelegateFunction_UnrealFRP_OnSessionUpdate__DelegateSignature();
	UNREALFRP_API UScriptStruct* Z_Construct_UScriptStruct_FFRPSession();
// End Cross Module References
	DEFINE_FUNCTION(UFRPLibrary::execConnectSession)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_Addr);
		P_FINISH;
		P_NATIVE_BEGIN;
		UFRPLibrary::ConnectSession(Z_Param_WorldContextObject,Z_Param_Addr);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFRPLibrary::execUnbindOnAddrUpdate)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_FINISH;
		P_NATIVE_BEGIN;
		UFRPLibrary::UnbindOnAddrUpdate(Z_Param_WorldContextObject);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFRPLibrary::execBindOnAddrUpdate)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_Delegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		UFRPLibrary::BindOnAddrUpdate(Z_Param_WorldContextObject,FOnAddrUpdate(Z_Param_Delegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFRPLibrary::execAskForAddress)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_ID);
		P_GET_PROPERTY(FStrProperty,Z_Param_Password);
		P_FINISH;
		P_NATIVE_BEGIN;
		UFRPLibrary::AskForAddress(Z_Param_WorldContextObject,Z_Param_ID,Z_Param_Password);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFRPLibrary::execSetSessionPropertyAppend)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_PropertyAppend);
		P_FINISH;
		P_NATIVE_BEGIN;
		UFRPLibrary::SetSessionPropertyAppend(Z_Param_WorldContextObject,Z_Param_PropertyAppend);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFRPLibrary::execSetSessionPassword)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_Password);
		P_FINISH;
		P_NATIVE_BEGIN;
		UFRPLibrary::SetSessionPassword(Z_Param_WorldContextObject,Z_Param_Password);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFRPLibrary::execSetSessionProperty)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_Property);
		P_FINISH;
		P_NATIVE_BEGIN;
		UFRPLibrary::SetSessionProperty(Z_Param_WorldContextObject,Z_Param_Property);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFRPLibrary::execCloseSession)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_FINISH;
		P_NATIVE_BEGIN;
		UFRPLibrary::CloseSession(Z_Param_WorldContextObject);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFRPLibrary::execOpenSession)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_FINISH;
		P_NATIVE_BEGIN;
		UFRPLibrary::OpenSession(Z_Param_WorldContextObject);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFRPLibrary::execSetBaseIP)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_IP);
		P_FINISH;
		P_NATIVE_BEGIN;
		UFRPLibrary::SetBaseIP(Z_Param_WorldContextObject,Z_Param_IP);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFRPLibrary::execSetMsgAddress)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FIntProperty,Z_Param_Port);
		P_FINISH;
		P_NATIVE_BEGIN;
		UFRPLibrary::SetMsgAddress(Z_Param_WorldContextObject,Z_Param_Port);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFRPLibrary::execSetAppAddress)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FIntProperty,Z_Param_Port);
		P_FINISH;
		P_NATIVE_BEGIN;
		UFRPLibrary::SetAppAddress(Z_Param_WorldContextObject,Z_Param_Port);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFRPLibrary::execGetSessionList)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FFRPSession>*)Z_Param__Result=UFRPLibrary::GetSessionList(Z_Param_WorldContextObject);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFRPLibrary::execUnbindOnSessionListUpdate)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_FINISH;
		P_NATIVE_BEGIN;
		UFRPLibrary::UnbindOnSessionListUpdate(Z_Param_WorldContextObject);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFRPLibrary::execBindOnSessionListUpdate)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FDelegateProperty,Z_Param_Delegate);
		P_FINISH;
		P_NATIVE_BEGIN;
		UFRPLibrary::BindOnSessionListUpdate(Z_Param_WorldContextObject,FOnSessionUpdate(Z_Param_Delegate));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFRPLibrary::execFlushFRPSessionList)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_FINISH;
		P_NATIVE_BEGIN;
		UFRPLibrary::FlushFRPSessionList(Z_Param_WorldContextObject);
		P_NATIVE_END;
	}
	void UFRPLibrary::StaticRegisterNativesUFRPLibrary()
	{
		UClass* Class = UFRPLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AskForAddress", &UFRPLibrary::execAskForAddress },
			{ "BindOnAddrUpdate", &UFRPLibrary::execBindOnAddrUpdate },
			{ "BindOnSessionListUpdate", &UFRPLibrary::execBindOnSessionListUpdate },
			{ "CloseSession", &UFRPLibrary::execCloseSession },
			{ "ConnectSession", &UFRPLibrary::execConnectSession },
			{ "FlushFRPSessionList", &UFRPLibrary::execFlushFRPSessionList },
			{ "GetSessionList", &UFRPLibrary::execGetSessionList },
			{ "OpenSession", &UFRPLibrary::execOpenSession },
			{ "SetAppAddress", &UFRPLibrary::execSetAppAddress },
			{ "SetBaseIP", &UFRPLibrary::execSetBaseIP },
			{ "SetMsgAddress", &UFRPLibrary::execSetMsgAddress },
			{ "SetSessionPassword", &UFRPLibrary::execSetSessionPassword },
			{ "SetSessionProperty", &UFRPLibrary::execSetSessionProperty },
			{ "SetSessionPropertyAppend", &UFRPLibrary::execSetSessionPropertyAppend },
			{ "UnbindOnAddrUpdate", &UFRPLibrary::execUnbindOnAddrUpdate },
			{ "UnbindOnSessionListUpdate", &UFRPLibrary::execUnbindOnSessionListUpdate },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UFRPLibrary_AskForAddress_Statics
	{
		struct FRPLibrary_eventAskForAddress_Parms
		{
			UObject* WorldContextObject;
			FString ID;
			FString Password;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ID_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ID;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Password_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Password;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFRPLibrary_AskForAddress_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRPLibrary_eventAskForAddress_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFRPLibrary_AskForAddress_Statics::NewProp_ID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFRPLibrary_AskForAddress_Statics::NewProp_ID = { "ID", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRPLibrary_eventAskForAddress_Parms, ID), METADATA_PARAMS(Z_Construct_UFunction_UFRPLibrary_AskForAddress_Statics::NewProp_ID_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_AskForAddress_Statics::NewProp_ID_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFRPLibrary_AskForAddress_Statics::NewProp_Password_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFRPLibrary_AskForAddress_Statics::NewProp_Password = { "Password", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRPLibrary_eventAskForAddress_Parms, Password), METADATA_PARAMS(Z_Construct_UFunction_UFRPLibrary_AskForAddress_Statics::NewProp_Password_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_AskForAddress_Statics::NewProp_Password_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFRPLibrary_AskForAddress_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFRPLibrary_AskForAddress_Statics::NewProp_WorldContextObject,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFRPLibrary_AskForAddress_Statics::NewProp_ID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFRPLibrary_AskForAddress_Statics::NewProp_Password,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFRPLibrary_AskForAddress_Statics::Function_MetaDataParams[] = {
		{ "Category", "UnrealFRP" },
		{ "ModuleRelativePath", "Source/FRPLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFRPLibrary_AskForAddress_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFRPLibrary, nullptr, "AskForAddress", nullptr, nullptr, sizeof(FRPLibrary_eventAskForAddress_Parms), Z_Construct_UFunction_UFRPLibrary_AskForAddress_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_AskForAddress_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFRPLibrary_AskForAddress_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_AskForAddress_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFRPLibrary_AskForAddress()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFRPLibrary_AskForAddress_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFRPLibrary_BindOnAddrUpdate_Statics
	{
		struct FRPLibrary_eventBindOnAddrUpdate_Parms
		{
			UObject* WorldContextObject;
			FScriptDelegate Delegate;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FDelegatePropertyParams NewProp_Delegate;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFRPLibrary_BindOnAddrUpdate_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRPLibrary_eventBindOnAddrUpdate_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UFRPLibrary_BindOnAddrUpdate_Statics::NewProp_Delegate = { "Delegate", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRPLibrary_eventBindOnAddrUpdate_Parms, Delegate), Z_Construct_UDelegateFunction_UnrealFRP_OnAddrUpdate__DelegateSignature, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFRPLibrary_BindOnAddrUpdate_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFRPLibrary_BindOnAddrUpdate_Statics::NewProp_WorldContextObject,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFRPLibrary_BindOnAddrUpdate_Statics::NewProp_Delegate,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFRPLibrary_BindOnAddrUpdate_Statics::Function_MetaDataParams[] = {
		{ "Category", "UnrealFRP" },
		{ "ModuleRelativePath", "Source/FRPLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFRPLibrary_BindOnAddrUpdate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFRPLibrary, nullptr, "BindOnAddrUpdate", nullptr, nullptr, sizeof(FRPLibrary_eventBindOnAddrUpdate_Parms), Z_Construct_UFunction_UFRPLibrary_BindOnAddrUpdate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_BindOnAddrUpdate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFRPLibrary_BindOnAddrUpdate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_BindOnAddrUpdate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFRPLibrary_BindOnAddrUpdate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFRPLibrary_BindOnAddrUpdate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFRPLibrary_BindOnSessionListUpdate_Statics
	{
		struct FRPLibrary_eventBindOnSessionListUpdate_Parms
		{
			UObject* WorldContextObject;
			FScriptDelegate Delegate;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FDelegatePropertyParams NewProp_Delegate;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFRPLibrary_BindOnSessionListUpdate_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRPLibrary_eventBindOnSessionListUpdate_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UFRPLibrary_BindOnSessionListUpdate_Statics::NewProp_Delegate = { "Delegate", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRPLibrary_eventBindOnSessionListUpdate_Parms, Delegate), Z_Construct_UDelegateFunction_UnrealFRP_OnSessionUpdate__DelegateSignature, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFRPLibrary_BindOnSessionListUpdate_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFRPLibrary_BindOnSessionListUpdate_Statics::NewProp_WorldContextObject,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFRPLibrary_BindOnSessionListUpdate_Statics::NewProp_Delegate,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFRPLibrary_BindOnSessionListUpdate_Statics::Function_MetaDataParams[] = {
		{ "Category", "UnrealFRP" },
		{ "ModuleRelativePath", "Source/FRPLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFRPLibrary_BindOnSessionListUpdate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFRPLibrary, nullptr, "BindOnSessionListUpdate", nullptr, nullptr, sizeof(FRPLibrary_eventBindOnSessionListUpdate_Parms), Z_Construct_UFunction_UFRPLibrary_BindOnSessionListUpdate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_BindOnSessionListUpdate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFRPLibrary_BindOnSessionListUpdate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_BindOnSessionListUpdate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFRPLibrary_BindOnSessionListUpdate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFRPLibrary_BindOnSessionListUpdate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFRPLibrary_CloseSession_Statics
	{
		struct FRPLibrary_eventCloseSession_Parms
		{
			UObject* WorldContextObject;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFRPLibrary_CloseSession_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRPLibrary_eventCloseSession_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFRPLibrary_CloseSession_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFRPLibrary_CloseSession_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFRPLibrary_CloseSession_Statics::Function_MetaDataParams[] = {
		{ "Category", "UnrealFRP" },
		{ "ModuleRelativePath", "Source/FRPLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFRPLibrary_CloseSession_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFRPLibrary, nullptr, "CloseSession", nullptr, nullptr, sizeof(FRPLibrary_eventCloseSession_Parms), Z_Construct_UFunction_UFRPLibrary_CloseSession_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_CloseSession_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFRPLibrary_CloseSession_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_CloseSession_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFRPLibrary_CloseSession()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFRPLibrary_CloseSession_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFRPLibrary_ConnectSession_Statics
	{
		struct FRPLibrary_eventConnectSession_Parms
		{
			UObject* WorldContextObject;
			FString Addr;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Addr;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFRPLibrary_ConnectSession_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRPLibrary_eventConnectSession_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFRPLibrary_ConnectSession_Statics::NewProp_Addr = { "Addr", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRPLibrary_eventConnectSession_Parms, Addr), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFRPLibrary_ConnectSession_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFRPLibrary_ConnectSession_Statics::NewProp_WorldContextObject,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFRPLibrary_ConnectSession_Statics::NewProp_Addr,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFRPLibrary_ConnectSession_Statics::Function_MetaDataParams[] = {
		{ "Category", "UnrealFRP" },
		{ "ModuleRelativePath", "Source/FRPLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFRPLibrary_ConnectSession_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFRPLibrary, nullptr, "ConnectSession", nullptr, nullptr, sizeof(FRPLibrary_eventConnectSession_Parms), Z_Construct_UFunction_UFRPLibrary_ConnectSession_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_ConnectSession_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFRPLibrary_ConnectSession_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_ConnectSession_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFRPLibrary_ConnectSession()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFRPLibrary_ConnectSession_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFRPLibrary_FlushFRPSessionList_Statics
	{
		struct FRPLibrary_eventFlushFRPSessionList_Parms
		{
			const UObject* WorldContextObject;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFRPLibrary_FlushFRPSessionList_Statics::NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFRPLibrary_FlushFRPSessionList_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRPLibrary_eventFlushFRPSessionList_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UFRPLibrary_FlushFRPSessionList_Statics::NewProp_WorldContextObject_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_FlushFRPSessionList_Statics::NewProp_WorldContextObject_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFRPLibrary_FlushFRPSessionList_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFRPLibrary_FlushFRPSessionList_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFRPLibrary_FlushFRPSessionList_Statics::Function_MetaDataParams[] = {
		{ "Category", "UnrealFRP" },
		{ "ModuleRelativePath", "Source/FRPLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFRPLibrary_FlushFRPSessionList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFRPLibrary, nullptr, "FlushFRPSessionList", nullptr, nullptr, sizeof(FRPLibrary_eventFlushFRPSessionList_Parms), Z_Construct_UFunction_UFRPLibrary_FlushFRPSessionList_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_FlushFRPSessionList_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFRPLibrary_FlushFRPSessionList_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_FlushFRPSessionList_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFRPLibrary_FlushFRPSessionList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFRPLibrary_FlushFRPSessionList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFRPLibrary_GetSessionList_Statics
	{
		struct FRPLibrary_eventGetSessionList_Parms
		{
			UObject* WorldContextObject;
			TArray<FFRPSession> ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFRPLibrary_GetSessionList_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRPLibrary_eventGetSessionList_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFRPLibrary_GetSessionList_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FFRPSession, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UFRPLibrary_GetSessionList_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRPLibrary_eventGetSessionList_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFRPLibrary_GetSessionList_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFRPLibrary_GetSessionList_Statics::NewProp_WorldContextObject,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFRPLibrary_GetSessionList_Statics::NewProp_ReturnValue_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFRPLibrary_GetSessionList_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFRPLibrary_GetSessionList_Statics::Function_MetaDataParams[] = {
		{ "Category", "UnrealFRP" },
		{ "ModuleRelativePath", "Source/FRPLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFRPLibrary_GetSessionList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFRPLibrary, nullptr, "GetSessionList", nullptr, nullptr, sizeof(FRPLibrary_eventGetSessionList_Parms), Z_Construct_UFunction_UFRPLibrary_GetSessionList_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_GetSessionList_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFRPLibrary_GetSessionList_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_GetSessionList_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFRPLibrary_GetSessionList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFRPLibrary_GetSessionList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFRPLibrary_OpenSession_Statics
	{
		struct FRPLibrary_eventOpenSession_Parms
		{
			UObject* WorldContextObject;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFRPLibrary_OpenSession_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRPLibrary_eventOpenSession_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFRPLibrary_OpenSession_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFRPLibrary_OpenSession_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFRPLibrary_OpenSession_Statics::Function_MetaDataParams[] = {
		{ "Category", "UnrealFRP" },
		{ "ModuleRelativePath", "Source/FRPLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFRPLibrary_OpenSession_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFRPLibrary, nullptr, "OpenSession", nullptr, nullptr, sizeof(FRPLibrary_eventOpenSession_Parms), Z_Construct_UFunction_UFRPLibrary_OpenSession_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_OpenSession_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFRPLibrary_OpenSession_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_OpenSession_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFRPLibrary_OpenSession()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFRPLibrary_OpenSession_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFRPLibrary_SetAppAddress_Statics
	{
		struct FRPLibrary_eventSetAppAddress_Parms
		{
			UObject* WorldContextObject;
			int32 Port;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Port;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFRPLibrary_SetAppAddress_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRPLibrary_eventSetAppAddress_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UFRPLibrary_SetAppAddress_Statics::NewProp_Port = { "Port", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRPLibrary_eventSetAppAddress_Parms, Port), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFRPLibrary_SetAppAddress_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFRPLibrary_SetAppAddress_Statics::NewProp_WorldContextObject,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFRPLibrary_SetAppAddress_Statics::NewProp_Port,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFRPLibrary_SetAppAddress_Statics::Function_MetaDataParams[] = {
		{ "Category", "UnrealFRP" },
		{ "ModuleRelativePath", "Source/FRPLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFRPLibrary_SetAppAddress_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFRPLibrary, nullptr, "SetAppAddress", nullptr, nullptr, sizeof(FRPLibrary_eventSetAppAddress_Parms), Z_Construct_UFunction_UFRPLibrary_SetAppAddress_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_SetAppAddress_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFRPLibrary_SetAppAddress_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_SetAppAddress_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFRPLibrary_SetAppAddress()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFRPLibrary_SetAppAddress_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFRPLibrary_SetBaseIP_Statics
	{
		struct FRPLibrary_eventSetBaseIP_Parms
		{
			UObject* WorldContextObject;
			FString IP;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_IP;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFRPLibrary_SetBaseIP_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRPLibrary_eventSetBaseIP_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFRPLibrary_SetBaseIP_Statics::NewProp_IP = { "IP", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRPLibrary_eventSetBaseIP_Parms, IP), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFRPLibrary_SetBaseIP_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFRPLibrary_SetBaseIP_Statics::NewProp_WorldContextObject,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFRPLibrary_SetBaseIP_Statics::NewProp_IP,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFRPLibrary_SetBaseIP_Statics::Function_MetaDataParams[] = {
		{ "Category", "UnrealFRP" },
		{ "ModuleRelativePath", "Source/FRPLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFRPLibrary_SetBaseIP_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFRPLibrary, nullptr, "SetBaseIP", nullptr, nullptr, sizeof(FRPLibrary_eventSetBaseIP_Parms), Z_Construct_UFunction_UFRPLibrary_SetBaseIP_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_SetBaseIP_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFRPLibrary_SetBaseIP_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_SetBaseIP_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFRPLibrary_SetBaseIP()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFRPLibrary_SetBaseIP_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFRPLibrary_SetMsgAddress_Statics
	{
		struct FRPLibrary_eventSetMsgAddress_Parms
		{
			UObject* WorldContextObject;
			int32 Port;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Port;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFRPLibrary_SetMsgAddress_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRPLibrary_eventSetMsgAddress_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UFRPLibrary_SetMsgAddress_Statics::NewProp_Port = { "Port", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRPLibrary_eventSetMsgAddress_Parms, Port), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFRPLibrary_SetMsgAddress_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFRPLibrary_SetMsgAddress_Statics::NewProp_WorldContextObject,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFRPLibrary_SetMsgAddress_Statics::NewProp_Port,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFRPLibrary_SetMsgAddress_Statics::Function_MetaDataParams[] = {
		{ "Category", "UnrealFRP" },
		{ "ModuleRelativePath", "Source/FRPLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFRPLibrary_SetMsgAddress_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFRPLibrary, nullptr, "SetMsgAddress", nullptr, nullptr, sizeof(FRPLibrary_eventSetMsgAddress_Parms), Z_Construct_UFunction_UFRPLibrary_SetMsgAddress_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_SetMsgAddress_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFRPLibrary_SetMsgAddress_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_SetMsgAddress_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFRPLibrary_SetMsgAddress()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFRPLibrary_SetMsgAddress_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFRPLibrary_SetSessionPassword_Statics
	{
		struct FRPLibrary_eventSetSessionPassword_Parms
		{
			UObject* WorldContextObject;
			FString Password;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Password;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFRPLibrary_SetSessionPassword_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRPLibrary_eventSetSessionPassword_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFRPLibrary_SetSessionPassword_Statics::NewProp_Password = { "Password", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRPLibrary_eventSetSessionPassword_Parms, Password), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFRPLibrary_SetSessionPassword_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFRPLibrary_SetSessionPassword_Statics::NewProp_WorldContextObject,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFRPLibrary_SetSessionPassword_Statics::NewProp_Password,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFRPLibrary_SetSessionPassword_Statics::Function_MetaDataParams[] = {
		{ "Category", "UnrealFRP" },
		{ "ModuleRelativePath", "Source/FRPLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFRPLibrary_SetSessionPassword_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFRPLibrary, nullptr, "SetSessionPassword", nullptr, nullptr, sizeof(FRPLibrary_eventSetSessionPassword_Parms), Z_Construct_UFunction_UFRPLibrary_SetSessionPassword_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_SetSessionPassword_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFRPLibrary_SetSessionPassword_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_SetSessionPassword_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFRPLibrary_SetSessionPassword()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFRPLibrary_SetSessionPassword_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFRPLibrary_SetSessionProperty_Statics
	{
		struct FRPLibrary_eventSetSessionProperty_Parms
		{
			UObject* WorldContextObject;
			FString Property;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Property;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFRPLibrary_SetSessionProperty_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRPLibrary_eventSetSessionProperty_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFRPLibrary_SetSessionProperty_Statics::NewProp_Property = { "Property", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRPLibrary_eventSetSessionProperty_Parms, Property), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFRPLibrary_SetSessionProperty_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFRPLibrary_SetSessionProperty_Statics::NewProp_WorldContextObject,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFRPLibrary_SetSessionProperty_Statics::NewProp_Property,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFRPLibrary_SetSessionProperty_Statics::Function_MetaDataParams[] = {
		{ "Category", "UnrealFRP" },
		{ "ModuleRelativePath", "Source/FRPLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFRPLibrary_SetSessionProperty_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFRPLibrary, nullptr, "SetSessionProperty", nullptr, nullptr, sizeof(FRPLibrary_eventSetSessionProperty_Parms), Z_Construct_UFunction_UFRPLibrary_SetSessionProperty_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_SetSessionProperty_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFRPLibrary_SetSessionProperty_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_SetSessionProperty_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFRPLibrary_SetSessionProperty()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFRPLibrary_SetSessionProperty_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFRPLibrary_SetSessionPropertyAppend_Statics
	{
		struct FRPLibrary_eventSetSessionPropertyAppend_Parms
		{
			UObject* WorldContextObject;
			FString PropertyAppend;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_PropertyAppend;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFRPLibrary_SetSessionPropertyAppend_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRPLibrary_eventSetSessionPropertyAppend_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFRPLibrary_SetSessionPropertyAppend_Statics::NewProp_PropertyAppend = { "PropertyAppend", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRPLibrary_eventSetSessionPropertyAppend_Parms, PropertyAppend), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFRPLibrary_SetSessionPropertyAppend_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFRPLibrary_SetSessionPropertyAppend_Statics::NewProp_WorldContextObject,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFRPLibrary_SetSessionPropertyAppend_Statics::NewProp_PropertyAppend,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFRPLibrary_SetSessionPropertyAppend_Statics::Function_MetaDataParams[] = {
		{ "Category", "UnrealFRP" },
		{ "ModuleRelativePath", "Source/FRPLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFRPLibrary_SetSessionPropertyAppend_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFRPLibrary, nullptr, "SetSessionPropertyAppend", nullptr, nullptr, sizeof(FRPLibrary_eventSetSessionPropertyAppend_Parms), Z_Construct_UFunction_UFRPLibrary_SetSessionPropertyAppend_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_SetSessionPropertyAppend_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFRPLibrary_SetSessionPropertyAppend_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_SetSessionPropertyAppend_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFRPLibrary_SetSessionPropertyAppend()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFRPLibrary_SetSessionPropertyAppend_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFRPLibrary_UnbindOnAddrUpdate_Statics
	{
		struct FRPLibrary_eventUnbindOnAddrUpdate_Parms
		{
			UObject* WorldContextObject;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFRPLibrary_UnbindOnAddrUpdate_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRPLibrary_eventUnbindOnAddrUpdate_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFRPLibrary_UnbindOnAddrUpdate_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFRPLibrary_UnbindOnAddrUpdate_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFRPLibrary_UnbindOnAddrUpdate_Statics::Function_MetaDataParams[] = {
		{ "Category", "UnrealFRP" },
		{ "ModuleRelativePath", "Source/FRPLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFRPLibrary_UnbindOnAddrUpdate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFRPLibrary, nullptr, "UnbindOnAddrUpdate", nullptr, nullptr, sizeof(FRPLibrary_eventUnbindOnAddrUpdate_Parms), Z_Construct_UFunction_UFRPLibrary_UnbindOnAddrUpdate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_UnbindOnAddrUpdate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFRPLibrary_UnbindOnAddrUpdate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_UnbindOnAddrUpdate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFRPLibrary_UnbindOnAddrUpdate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFRPLibrary_UnbindOnAddrUpdate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFRPLibrary_UnbindOnSessionListUpdate_Statics
	{
		struct FRPLibrary_eventUnbindOnSessionListUpdate_Parms
		{
			UObject* WorldContextObject;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFRPLibrary_UnbindOnSessionListUpdate_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FRPLibrary_eventUnbindOnSessionListUpdate_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFRPLibrary_UnbindOnSessionListUpdate_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFRPLibrary_UnbindOnSessionListUpdate_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFRPLibrary_UnbindOnSessionListUpdate_Statics::Function_MetaDataParams[] = {
		{ "Category", "UnrealFRP" },
		{ "ModuleRelativePath", "Source/FRPLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFRPLibrary_UnbindOnSessionListUpdate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFRPLibrary, nullptr, "UnbindOnSessionListUpdate", nullptr, nullptr, sizeof(FRPLibrary_eventUnbindOnSessionListUpdate_Parms), Z_Construct_UFunction_UFRPLibrary_UnbindOnSessionListUpdate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_UnbindOnSessionListUpdate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFRPLibrary_UnbindOnSessionListUpdate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFRPLibrary_UnbindOnSessionListUpdate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFRPLibrary_UnbindOnSessionListUpdate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFRPLibrary_UnbindOnSessionListUpdate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UFRPLibrary_NoRegister()
	{
		return UFRPLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UFRPLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFRPLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealFRP,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UFRPLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UFRPLibrary_AskForAddress, "AskForAddress" }, // 1342183151
		{ &Z_Construct_UFunction_UFRPLibrary_BindOnAddrUpdate, "BindOnAddrUpdate" }, // 3819564081
		{ &Z_Construct_UFunction_UFRPLibrary_BindOnSessionListUpdate, "BindOnSessionListUpdate" }, // 1036573123
		{ &Z_Construct_UFunction_UFRPLibrary_CloseSession, "CloseSession" }, // 3218120078
		{ &Z_Construct_UFunction_UFRPLibrary_ConnectSession, "ConnectSession" }, // 2707424379
		{ &Z_Construct_UFunction_UFRPLibrary_FlushFRPSessionList, "FlushFRPSessionList" }, // 977839328
		{ &Z_Construct_UFunction_UFRPLibrary_GetSessionList, "GetSessionList" }, // 1569695074
		{ &Z_Construct_UFunction_UFRPLibrary_OpenSession, "OpenSession" }, // 725486522
		{ &Z_Construct_UFunction_UFRPLibrary_SetAppAddress, "SetAppAddress" }, // 1859361329
		{ &Z_Construct_UFunction_UFRPLibrary_SetBaseIP, "SetBaseIP" }, // 1103248649
		{ &Z_Construct_UFunction_UFRPLibrary_SetMsgAddress, "SetMsgAddress" }, // 769171398
		{ &Z_Construct_UFunction_UFRPLibrary_SetSessionPassword, "SetSessionPassword" }, // 2767030469
		{ &Z_Construct_UFunction_UFRPLibrary_SetSessionProperty, "SetSessionProperty" }, // 2493164004
		{ &Z_Construct_UFunction_UFRPLibrary_SetSessionPropertyAppend, "SetSessionPropertyAppend" }, // 4039000475
		{ &Z_Construct_UFunction_UFRPLibrary_UnbindOnAddrUpdate, "UnbindOnAddrUpdate" }, // 361970738
		{ &Z_Construct_UFunction_UFRPLibrary_UnbindOnSessionListUpdate, "UnbindOnSessionListUpdate" }, // 3000885320
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFRPLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Source/FRPLibrary.h" },
		{ "ModuleRelativePath", "Source/FRPLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFRPLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFRPLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UFRPLibrary_Statics::ClassParams = {
		&UFRPLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UFRPLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UFRPLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFRPLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UFRPLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFRPLibrary, 2448593782);
	template<> UNREALFRP_API UClass* StaticClass<UFRPLibrary>()
	{
		return UFRPLibrary::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFRPLibrary(Z_Construct_UClass_UFRPLibrary, &UFRPLibrary::StaticClass, TEXT("/Script/UnrealFRP"), TEXT("UFRPLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFRPLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
