// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FFRPSession;
#ifdef UNREALFRP_FRPSubsystem_generated_h
#error "FRPSubsystem.generated.h already included, missing '#pragma once' in FRPSubsystem.h"
#endif
#define UNREALFRP_FRPSubsystem_generated_h

#define a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPSubsystem_h_13_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FFRPSession_Statics; \
	UNREALFRP_API static class UScriptStruct* StaticStruct();


template<> UNREALFRP_API UScriptStruct* StaticStruct<struct FFRPSession>();

#define a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPSubsystem_h_27_DELEGATE \
struct _Script_UnrealFRP_eventOnAddrUpdate_Parms \
{ \
	bool Success; \
	FString Addr; \
}; \
static inline void FOnAddrUpdate_DelegateWrapper(const FScriptDelegate& OnAddrUpdate, bool Success, const FString& Addr) \
{ \
	_Script_UnrealFRP_eventOnAddrUpdate_Parms Parms; \
	Parms.Success=Success ? true : false; \
	Parms.Addr=Addr; \
	OnAddrUpdate.ProcessDelegate<UObject>(&Parms); \
}


#define a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPSubsystem_h_25_DELEGATE \
struct _Script_UnrealFRP_eventOnSessionUpdate_Parms \
{ \
	TArray<FFRPSession> Session; \
}; \
static inline void FOnSessionUpdate_DelegateWrapper(const FScriptDelegate& OnSessionUpdate, TArray<FFRPSession> const& Session) \
{ \
	_Script_UnrealFRP_eventOnSessionUpdate_Parms Parms; \
	Parms.Session=Session; \
	OnSessionUpdate.ProcessDelegate<UObject>(&Parms); \
}


#define a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPSubsystem_h_32_SPARSE_DATA
#define a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPSubsystem_h_32_RPC_WRAPPERS
#define a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPSubsystem_h_32_RPC_WRAPPERS_NO_PURE_DECLS
#define a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPSubsystem_h_32_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUFRPSubsystem(); \
	friend struct Z_Construct_UClass_UFRPSubsystem_Statics; \
public: \
	DECLARE_CLASS(UFRPSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UnrealFRP"), NO_API) \
	DECLARE_SERIALIZER(UFRPSubsystem)


#define a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPSubsystem_h_32_INCLASS \
private: \
	static void StaticRegisterNativesUFRPSubsystem(); \
	friend struct Z_Construct_UClass_UFRPSubsystem_Statics; \
public: \
	DECLARE_CLASS(UFRPSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UnrealFRP"), NO_API) \
	DECLARE_SERIALIZER(UFRPSubsystem)


#define a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPSubsystem_h_32_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFRPSubsystem(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFRPSubsystem) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFRPSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFRPSubsystem); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFRPSubsystem(UFRPSubsystem&&); \
	NO_API UFRPSubsystem(const UFRPSubsystem&); \
public:


#define a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPSubsystem_h_32_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFRPSubsystem() { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFRPSubsystem(UFRPSubsystem&&); \
	NO_API UFRPSubsystem(const UFRPSubsystem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFRPSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFRPSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UFRPSubsystem)


#define a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPSubsystem_h_32_PRIVATE_PROPERTY_OFFSET
#define a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPSubsystem_h_29_PROLOG
#define a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPSubsystem_h_32_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPSubsystem_h_32_PRIVATE_PROPERTY_OFFSET \
	a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPSubsystem_h_32_SPARSE_DATA \
	a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPSubsystem_h_32_RPC_WRAPPERS \
	a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPSubsystem_h_32_INCLASS \
	a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPSubsystem_h_32_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPSubsystem_h_32_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPSubsystem_h_32_PRIVATE_PROPERTY_OFFSET \
	a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPSubsystem_h_32_SPARSE_DATA \
	a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPSubsystem_h_32_RPC_WRAPPERS_NO_PURE_DECLS \
	a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPSubsystem_h_32_INCLASS_NO_PURE_DECLS \
	a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPSubsystem_h_32_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UNREALFRP_API UClass* StaticClass<class UFRPSubsystem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPSubsystem_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
