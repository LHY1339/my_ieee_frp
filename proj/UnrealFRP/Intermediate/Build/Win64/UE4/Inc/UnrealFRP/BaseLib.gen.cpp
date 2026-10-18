// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealFRP/Source/BaseLib.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBaseLib() {}
// Cross Module References
	UNREALFRP_API UClass* Z_Construct_UClass_UBaseLib_NoRegister();
	UNREALFRP_API UClass* Z_Construct_UClass_UBaseLib();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_UnrealFRP();
// End Cross Module References
	void UBaseLib::StaticRegisterNativesUBaseLib()
	{
	}
	UClass* Z_Construct_UClass_UBaseLib_NoRegister()
	{
		return UBaseLib::StaticClass();
	}
	struct Z_Construct_UClass_UBaseLib_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBaseLib_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealFRP,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBaseLib_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Source/BaseLib.h" },
		{ "ModuleRelativePath", "Source/BaseLib.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBaseLib_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBaseLib>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UBaseLib_Statics::ClassParams = {
		&UBaseLib::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UBaseLib_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UBaseLib_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UBaseLib()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UBaseLib_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UBaseLib, 2736149945);
	template<> UNREALFRP_API UClass* StaticClass<UBaseLib>()
	{
		return UBaseLib::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UBaseLib(Z_Construct_UClass_UBaseLib, &UBaseLib::StaticClass, TEXT("/Script/UnrealFRP"), TEXT("UBaseLib"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBaseLib);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
