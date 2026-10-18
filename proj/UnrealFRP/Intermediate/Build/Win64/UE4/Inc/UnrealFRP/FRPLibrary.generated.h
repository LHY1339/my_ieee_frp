// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
struct FFRPSession;
#ifdef UNREALFRP_FRPLibrary_generated_h
#error "FRPLibrary.generated.h already included, missing '#pragma once' in FRPLibrary.h"
#endif
#define UNREALFRP_FRPLibrary_generated_h

#define a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPLibrary_h_11_SPARSE_DATA
#define a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPLibrary_h_11_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execConnectSession); \
	DECLARE_FUNCTION(execUnbindOnAddrUpdate); \
	DECLARE_FUNCTION(execBindOnAddrUpdate); \
	DECLARE_FUNCTION(execAskForAddress); \
	DECLARE_FUNCTION(execSetSessionPropertyAppend); \
	DECLARE_FUNCTION(execSetSessionPassword); \
	DECLARE_FUNCTION(execSetSessionProperty); \
	DECLARE_FUNCTION(execCloseSession); \
	DECLARE_FUNCTION(execOpenSession); \
	DECLARE_FUNCTION(execSetBaseIP); \
	DECLARE_FUNCTION(execSetMsgAddress); \
	DECLARE_FUNCTION(execSetAppAddress); \
	DECLARE_FUNCTION(execGetSessionList); \
	DECLARE_FUNCTION(execUnbindOnSessionListUpdate); \
	DECLARE_FUNCTION(execBindOnSessionListUpdate); \
	DECLARE_FUNCTION(execFlushFRPSessionList);


#define a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPLibrary_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execConnectSession); \
	DECLARE_FUNCTION(execUnbindOnAddrUpdate); \
	DECLARE_FUNCTION(execBindOnAddrUpdate); \
	DECLARE_FUNCTION(execAskForAddress); \
	DECLARE_FUNCTION(execSetSessionPropertyAppend); \
	DECLARE_FUNCTION(execSetSessionPassword); \
	DECLARE_FUNCTION(execSetSessionProperty); \
	DECLARE_FUNCTION(execCloseSession); \
	DECLARE_FUNCTION(execOpenSession); \
	DECLARE_FUNCTION(execSetBaseIP); \
	DECLARE_FUNCTION(execSetMsgAddress); \
	DECLARE_FUNCTION(execSetAppAddress); \
	DECLARE_FUNCTION(execGetSessionList); \
	DECLARE_FUNCTION(execUnbindOnSessionListUpdate); \
	DECLARE_FUNCTION(execBindOnSessionListUpdate); \
	DECLARE_FUNCTION(execFlushFRPSessionList);


#define a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPLibrary_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUFRPLibrary(); \
	friend struct Z_Construct_UClass_UFRPLibrary_Statics; \
public: \
	DECLARE_CLASS(UFRPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UnrealFRP"), NO_API) \
	DECLARE_SERIALIZER(UFRPLibrary)


#define a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPLibrary_h_11_INCLASS \
private: \
	static void StaticRegisterNativesUFRPLibrary(); \
	friend struct Z_Construct_UClass_UFRPLibrary_Statics; \
public: \
	DECLARE_CLASS(UFRPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UnrealFRP"), NO_API) \
	DECLARE_SERIALIZER(UFRPLibrary)


#define a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPLibrary_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFRPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFRPLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFRPLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFRPLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFRPLibrary(UFRPLibrary&&); \
	NO_API UFRPLibrary(const UFRPLibrary&); \
public:


#define a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPLibrary_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFRPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFRPLibrary(UFRPLibrary&&); \
	NO_API UFRPLibrary(const UFRPLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFRPLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFRPLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFRPLibrary)


#define a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPLibrary_h_11_PRIVATE_PROPERTY_OFFSET
#define a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPLibrary_h_8_PROLOG
#define a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPLibrary_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPLibrary_h_11_PRIVATE_PROPERTY_OFFSET \
	a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPLibrary_h_11_SPARSE_DATA \
	a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPLibrary_h_11_RPC_WRAPPERS \
	a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPLibrary_h_11_INCLASS \
	a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPLibrary_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPLibrary_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPLibrary_h_11_PRIVATE_PROPERTY_OFFSET \
	a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPLibrary_h_11_SPARSE_DATA \
	a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPLibrary_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPLibrary_h_11_INCLASS_NO_PURE_DECLS \
	a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPLibrary_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UNREALFRP_API UClass* StaticClass<class UFRPLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID a1cpp_Plugins_UnrealFRP_Source_UnrealFRP_Source_FRPLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
