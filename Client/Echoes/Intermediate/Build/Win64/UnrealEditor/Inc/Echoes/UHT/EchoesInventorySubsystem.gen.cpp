// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Echoes/Core/Common/Networking/EchoesInventorySubsystem.h"
#include "Echoes/Core/Common/EchoesItemDefinitions.h"
#include "Engine/GameInstance.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesInventorySubsystem() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UClass* Z_Construct_UClass_UEchoesInventorySubsystem();
ECHOES_API UClass* Z_Construct_UClass_UEchoesInventorySubsystem_NoRegister();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnHangarReceived__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnIconLoaded__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnInventoryFailure__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnModuleFitted__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnModuleUnfitted__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnShipActivated__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnShipFittingReceived__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnShipsReceived__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnWorldMeshLoaded__DelegateSignature();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FEchoesItemDefinitionRow();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FEchoesModule();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FEchoesShipFitting();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FEchoesShipInstance();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FEchoesShipList();
ENGINE_API UClass* Z_Construct_UClass_UDataTable_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FEchoesShipInstance ***********************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FEchoesShipInstance;
class UScriptStruct* FEchoesShipInstance::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FEchoesShipInstance.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FEchoesShipInstance.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FEchoesShipInstance, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("EchoesShipInstance"));
	}
	return Z_Registration_Info_UScriptStruct_FEchoesShipInstance.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FEchoesShipInstance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Ship instance structure (mirrors C# ShipInstanceDto)\n * Common_ prefix for shared data structures\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ship instance structure (mirrors C# ShipInstanceDto)\nCommon_ prefix for shared data structures" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InstanceId_MetaData[] = {
		{ "Category", "Ship" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "Ship" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipTypeId_MetaData[] = {
		{ "Category", "Ship" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipTypeName_MetaData[] = {
		{ "Category", "Ship" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mass_MetaData[] = {
		{ "Category", "Ship" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LocationSystemId_MetaData[] = {
		{ "Category", "Ship" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LocationName_MetaData[] = {
		{ "Category", "Ship" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IsActive_MetaData[] = {
		{ "Category", "Ship" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IsDocked_MetaData[] = {
		{ "Category", "Ship" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ModuleCount_MetaData[] = {
		{ "Category", "Ship" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_InstanceId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ShipTypeId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ShipTypeName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Mass;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LocationSystemId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_LocationName;
	static void NewProp_IsActive_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsActive;
	static void NewProp_IsDocked_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsDocked;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ModuleCount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FEchoesShipInstance>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::NewProp_InstanceId = { "InstanceId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipInstance, InstanceId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InstanceId_MetaData), NewProp_InstanceId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipInstance, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::NewProp_ShipTypeId = { "ShipTypeId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipInstance, ShipTypeId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipTypeId_MetaData), NewProp_ShipTypeId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::NewProp_ShipTypeName = { "ShipTypeName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipInstance, ShipTypeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipTypeName_MetaData), NewProp_ShipTypeName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::NewProp_Mass = { "Mass", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipInstance, Mass), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mass_MetaData), NewProp_Mass_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::NewProp_LocationSystemId = { "LocationSystemId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipInstance, LocationSystemId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LocationSystemId_MetaData), NewProp_LocationSystemId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::NewProp_LocationName = { "LocationName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipInstance, LocationName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LocationName_MetaData), NewProp_LocationName_MetaData) };
void Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::NewProp_IsActive_SetBit(void* Obj)
{
	((FEchoesShipInstance*)Obj)->IsActive = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::NewProp_IsActive = { "IsActive", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FEchoesShipInstance), &Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::NewProp_IsActive_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IsActive_MetaData), NewProp_IsActive_MetaData) };
void Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::NewProp_IsDocked_SetBit(void* Obj)
{
	((FEchoesShipInstance*)Obj)->IsDocked = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::NewProp_IsDocked = { "IsDocked", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FEchoesShipInstance), &Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::NewProp_IsDocked_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IsDocked_MetaData), NewProp_IsDocked_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::NewProp_ModuleCount = { "ModuleCount", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipInstance, ModuleCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ModuleCount_MetaData), NewProp_ModuleCount_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::NewProp_InstanceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::NewProp_ShipTypeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::NewProp_ShipTypeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::NewProp_Mass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::NewProp_LocationSystemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::NewProp_LocationName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::NewProp_IsActive,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::NewProp_IsDocked,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::NewProp_ModuleCount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"EchoesShipInstance",
	Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::PropPointers),
	sizeof(FEchoesShipInstance),
	alignof(FEchoesShipInstance),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FEchoesShipInstance()
{
	if (!Z_Registration_Info_UScriptStruct_FEchoesShipInstance.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FEchoesShipInstance.InnerSingleton, Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FEchoesShipInstance.InnerSingleton;
}
// ********** End ScriptStruct FEchoesShipInstance *************************************************

// ********** Begin ScriptStruct FEchoesShipList ***************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FEchoesShipList;
class UScriptStruct* FEchoesShipList::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FEchoesShipList.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FEchoesShipList.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FEchoesShipList, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("EchoesShipList"));
	}
	return Z_Registration_Info_UScriptStruct_FEchoesShipList.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FEchoesShipList_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Ship list response structure\n * Wrapper for TArray to enable Blueprint support in delegates\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ship list response structure\nWrapper for TArray to enable Blueprint support in delegates" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Ships_MetaData[] = {
		{ "Category", "Ship" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Ships_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Ships;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FEchoesShipList>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FEchoesShipList_Statics::NewProp_Ships_Inner = { "Ships", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FEchoesShipInstance, METADATA_PARAMS(0, nullptr) }; // 219373969
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FEchoesShipList_Statics::NewProp_Ships = { "Ships", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipList, Ships), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Ships_MetaData), NewProp_Ships_MetaData) }; // 219373969
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FEchoesShipList_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipList_Statics::NewProp_Ships_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipList_Statics::NewProp_Ships,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEchoesShipList_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FEchoesShipList_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"EchoesShipList",
	Z_Construct_UScriptStruct_FEchoesShipList_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEchoesShipList_Statics::PropPointers),
	sizeof(FEchoesShipList),
	alignof(FEchoesShipList),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEchoesShipList_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FEchoesShipList_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FEchoesShipList()
{
	if (!Z_Registration_Info_UScriptStruct_FEchoesShipList.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FEchoesShipList.InnerSingleton, Z_Construct_UScriptStruct_FEchoesShipList_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FEchoesShipList.InnerSingleton;
}
// ********** End ScriptStruct FEchoesShipList *****************************************************

// ********** Begin ScriptStruct FEchoesModule *****************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FEchoesModule;
class UScriptStruct* FEchoesModule::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FEchoesModule.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FEchoesModule.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FEchoesModule, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("EchoesModule"));
	}
	return Z_Registration_Info_UScriptStruct_FEchoesModule.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FEchoesModule_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Module instance structure (mirrors C# ModuleInstanceDto)\n * Common_ prefix for shared data structures\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Module instance structure (mirrors C# ModuleInstanceDto)\nCommon_ prefix for shared data structures" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InstanceId_MetaData[] = {
		{ "Category", "Module" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ModuleTypeId_MetaData[] = {
		{ "Category", "Module" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TypeName_MetaData[] = {
		{ "Category", "Module" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotType_MetaData[] = {
		{ "Category", "Module" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotIndex_MetaData[] = {
		{ "Category", "Module" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IsOnline_MetaData[] = {
		{ "Category", "Module" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mass_MetaData[] = {
		{ "Category", "Module" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThrustBonus_MetaData[] = {
		{ "Category", "Module" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InertiaModifier_MetaData[] = {
		{ "Category", "Module" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotationBonus_MetaData[] = {
		{ "Category", "Module" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxVelocityModifier_MetaData[] = {
		{ "Category", "Module" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_InstanceId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ModuleTypeId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TypeName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SlotType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static void NewProp_IsOnline_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsOnline;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Mass;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ThrustBonus;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InertiaModifier;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RotationBonus;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxVelocityModifier;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FEchoesModule>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FEchoesModule_Statics::NewProp_InstanceId = { "InstanceId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesModule, InstanceId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InstanceId_MetaData), NewProp_InstanceId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FEchoesModule_Statics::NewProp_ModuleTypeId = { "ModuleTypeId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesModule, ModuleTypeId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ModuleTypeId_MetaData), NewProp_ModuleTypeId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FEchoesModule_Statics::NewProp_TypeName = { "TypeName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesModule, TypeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TypeName_MetaData), NewProp_TypeName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FEchoesModule_Statics::NewProp_SlotType = { "SlotType", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesModule, SlotType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotType_MetaData), NewProp_SlotType_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FEchoesModule_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesModule, SlotIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotIndex_MetaData), NewProp_SlotIndex_MetaData) };
void Z_Construct_UScriptStruct_FEchoesModule_Statics::NewProp_IsOnline_SetBit(void* Obj)
{
	((FEchoesModule*)Obj)->IsOnline = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FEchoesModule_Statics::NewProp_IsOnline = { "IsOnline", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FEchoesModule), &Z_Construct_UScriptStruct_FEchoesModule_Statics::NewProp_IsOnline_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IsOnline_MetaData), NewProp_IsOnline_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEchoesModule_Statics::NewProp_Mass = { "Mass", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesModule, Mass), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mass_MetaData), NewProp_Mass_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEchoesModule_Statics::NewProp_ThrustBonus = { "ThrustBonus", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesModule, ThrustBonus), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThrustBonus_MetaData), NewProp_ThrustBonus_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEchoesModule_Statics::NewProp_InertiaModifier = { "InertiaModifier", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesModule, InertiaModifier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InertiaModifier_MetaData), NewProp_InertiaModifier_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEchoesModule_Statics::NewProp_RotationBonus = { "RotationBonus", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesModule, RotationBonus), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotationBonus_MetaData), NewProp_RotationBonus_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEchoesModule_Statics::NewProp_MaxVelocityModifier = { "MaxVelocityModifier", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesModule, MaxVelocityModifier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxVelocityModifier_MetaData), NewProp_MaxVelocityModifier_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FEchoesModule_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesModule_Statics::NewProp_InstanceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesModule_Statics::NewProp_ModuleTypeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesModule_Statics::NewProp_TypeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesModule_Statics::NewProp_SlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesModule_Statics::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesModule_Statics::NewProp_IsOnline,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesModule_Statics::NewProp_Mass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesModule_Statics::NewProp_ThrustBonus,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesModule_Statics::NewProp_InertiaModifier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesModule_Statics::NewProp_RotationBonus,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesModule_Statics::NewProp_MaxVelocityModifier,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEchoesModule_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FEchoesModule_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"EchoesModule",
	Z_Construct_UScriptStruct_FEchoesModule_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEchoesModule_Statics::PropPointers),
	sizeof(FEchoesModule),
	alignof(FEchoesModule),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEchoesModule_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FEchoesModule_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FEchoesModule()
{
	if (!Z_Registration_Info_UScriptStruct_FEchoesModule.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FEchoesModule.InnerSingleton, Z_Construct_UScriptStruct_FEchoesModule_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FEchoesModule.InnerSingleton;
}
// ********** End ScriptStruct FEchoesModule *******************************************************

// ********** Begin ScriptStruct FEchoesShipFitting ************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FEchoesShipFitting;
class UScriptStruct* FEchoesShipFitting::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FEchoesShipFitting.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FEchoesShipFitting.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FEchoesShipFitting, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("EchoesShipFitting"));
	}
	return Z_Registration_Info_UScriptStruct_FEchoesShipFitting.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FEchoesShipFitting_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Ship fitting structure (mirrors C# ShipFittingDto)\n * Detailed fitting information with all modules\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ship fitting structure (mirrors C# ShipFittingDto)\nDetailed fitting information with all modules" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipInstanceId_MetaData[] = {
		{ "Category", "Ship" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipName_MetaData[] = {
		{ "Category", "Ship" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipTypeId_MetaData[] = {
		{ "Category", "Ship" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipTypeName_MetaData[] = {
		{ "Category", "Ship" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseMass_MetaData[] = {
		{ "Category", "Ship" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalMass_MetaData[] = {
		{ "Category", "Ship" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Thrust_MetaData[] = {
		{ "Category", "Ship" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxVelocity_MetaData[] = {
		{ "Category", "Ship" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InertiaMultiplier_MetaData[] = {
		{ "Category", "Ship" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotationTorque_MetaData[] = {
		{ "Category", "Ship" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Modules_MetaData[] = {
		{ "Category", "Ship" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ShipInstanceId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ShipName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ShipTypeId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ShipTypeName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BaseMass;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TotalMass;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Thrust;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxVelocity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InertiaMultiplier;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RotationTorque;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Modules_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Modules;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FEchoesShipFitting>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::NewProp_ShipInstanceId = { "ShipInstanceId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipFitting, ShipInstanceId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipInstanceId_MetaData), NewProp_ShipInstanceId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::NewProp_ShipName = { "ShipName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipFitting, ShipName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipName_MetaData), NewProp_ShipName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::NewProp_ShipTypeId = { "ShipTypeId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipFitting, ShipTypeId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipTypeId_MetaData), NewProp_ShipTypeId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::NewProp_ShipTypeName = { "ShipTypeName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipFitting, ShipTypeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipTypeName_MetaData), NewProp_ShipTypeName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::NewProp_BaseMass = { "BaseMass", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipFitting, BaseMass), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseMass_MetaData), NewProp_BaseMass_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::NewProp_TotalMass = { "TotalMass", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipFitting, TotalMass), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalMass_MetaData), NewProp_TotalMass_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::NewProp_Thrust = { "Thrust", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipFitting, Thrust), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Thrust_MetaData), NewProp_Thrust_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::NewProp_MaxVelocity = { "MaxVelocity", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipFitting, MaxVelocity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxVelocity_MetaData), NewProp_MaxVelocity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::NewProp_InertiaMultiplier = { "InertiaMultiplier", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipFitting, InertiaMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InertiaMultiplier_MetaData), NewProp_InertiaMultiplier_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::NewProp_RotationTorque = { "RotationTorque", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipFitting, RotationTorque), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotationTorque_MetaData), NewProp_RotationTorque_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::NewProp_Modules_Inner = { "Modules", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FEchoesModule, METADATA_PARAMS(0, nullptr) }; // 474672524
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::NewProp_Modules = { "Modules", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesShipFitting, Modules), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Modules_MetaData), NewProp_Modules_MetaData) }; // 474672524
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::NewProp_ShipInstanceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::NewProp_ShipName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::NewProp_ShipTypeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::NewProp_ShipTypeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::NewProp_BaseMass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::NewProp_TotalMass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::NewProp_Thrust,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::NewProp_MaxVelocity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::NewProp_InertiaMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::NewProp_RotationTorque,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::NewProp_Modules_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::NewProp_Modules,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"EchoesShipFitting",
	Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::PropPointers),
	sizeof(FEchoesShipFitting),
	alignof(FEchoesShipFitting),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FEchoesShipFitting()
{
	if (!Z_Registration_Info_UScriptStruct_FEchoesShipFitting.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FEchoesShipFitting.InnerSingleton, Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FEchoesShipFitting.InnerSingleton;
}
// ********** End ScriptStruct FEchoesShipFitting **************************************************

// ********** Begin Delegate FOnIconLoaded *********************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnIconLoaded__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnIconLoaded_Parms
	{
		UTexture2D* LoadedIcon;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LoadedIcon;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_Echoes_OnIconLoaded__DelegateSignature_Statics::NewProp_LoadedIcon = { "LoadedIcon", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnIconLoaded_Parms, LoadedIcon), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnIconLoaded__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnIconLoaded__DelegateSignature_Statics::NewProp_LoadedIcon,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnIconLoaded__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnIconLoaded__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnIconLoaded__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnIconLoaded__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnIconLoaded__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnIconLoaded__DelegateSignature_Statics::_Script_Echoes_eventOnIconLoaded_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnIconLoaded__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnIconLoaded__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnIconLoaded__DelegateSignature_Statics::_Script_Echoes_eventOnIconLoaded_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnIconLoaded__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnIconLoaded__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnIconLoaded_DelegateWrapper(const FScriptDelegate& OnIconLoaded, UTexture2D* LoadedIcon)
{
	struct _Script_Echoes_eventOnIconLoaded_Parms
	{
		UTexture2D* LoadedIcon;
	};
	_Script_Echoes_eventOnIconLoaded_Parms Parms;
	Parms.LoadedIcon=LoadedIcon;
	OnIconLoaded.ProcessDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnIconLoaded ***********************************************************

// ********** Begin Delegate FOnWorldMeshLoaded ****************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnWorldMeshLoaded__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnWorldMeshLoaded_Parms
	{
		UStaticMesh* LoadedMesh;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LoadedMesh;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_Echoes_OnWorldMeshLoaded__DelegateSignature_Statics::NewProp_LoadedMesh = { "LoadedMesh", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnWorldMeshLoaded_Parms, LoadedMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnWorldMeshLoaded__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnWorldMeshLoaded__DelegateSignature_Statics::NewProp_LoadedMesh,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnWorldMeshLoaded__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnWorldMeshLoaded__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnWorldMeshLoaded__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnWorldMeshLoaded__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnWorldMeshLoaded__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnWorldMeshLoaded__DelegateSignature_Statics::_Script_Echoes_eventOnWorldMeshLoaded_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnWorldMeshLoaded__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnWorldMeshLoaded__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnWorldMeshLoaded__DelegateSignature_Statics::_Script_Echoes_eventOnWorldMeshLoaded_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnWorldMeshLoaded__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnWorldMeshLoaded__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnWorldMeshLoaded_DelegateWrapper(const FScriptDelegate& OnWorldMeshLoaded, UStaticMesh* LoadedMesh)
{
	struct _Script_Echoes_eventOnWorldMeshLoaded_Parms
	{
		UStaticMesh* LoadedMesh;
	};
	_Script_Echoes_eventOnWorldMeshLoaded_Parms Parms;
	Parms.LoadedMesh=LoadedMesh;
	OnWorldMeshLoaded.ProcessDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnWorldMeshLoaded ******************************************************

// ********** Begin Delegate FOnShipsReceived ******************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnShipsReceived__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnShipsReceived_Parms
	{
		FEchoesShipList ShipList;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipList_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ShipList;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Echoes_OnShipsReceived__DelegateSignature_Statics::NewProp_ShipList = { "ShipList", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnShipsReceived_Parms, ShipList), Z_Construct_UScriptStruct_FEchoesShipList, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipList_MetaData), NewProp_ShipList_MetaData) }; // 2870318589
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnShipsReceived__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnShipsReceived__DelegateSignature_Statics::NewProp_ShipList,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnShipsReceived__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnShipsReceived__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnShipsReceived__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnShipsReceived__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnShipsReceived__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnShipsReceived__DelegateSignature_Statics::_Script_Echoes_eventOnShipsReceived_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00520000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnShipsReceived__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnShipsReceived__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnShipsReceived__DelegateSignature_Statics::_Script_Echoes_eventOnShipsReceived_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnShipsReceived__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnShipsReceived__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnShipsReceived_DelegateWrapper(const FScriptDelegate& OnShipsReceived, FEchoesShipList const& ShipList)
{
	struct _Script_Echoes_eventOnShipsReceived_Parms
	{
		FEchoesShipList ShipList;
	};
	_Script_Echoes_eventOnShipsReceived_Parms Parms;
	Parms.ShipList=ShipList;
	OnShipsReceived.ProcessDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnShipsReceived ********************************************************

// ********** Begin Delegate FOnShipFittingReceived ************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnShipFittingReceived__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnShipFittingReceived_Parms
	{
		FEchoesShipFitting Fitting;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Fitting_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Fitting;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Echoes_OnShipFittingReceived__DelegateSignature_Statics::NewProp_Fitting = { "Fitting", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnShipFittingReceived_Parms, Fitting), Z_Construct_UScriptStruct_FEchoesShipFitting, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Fitting_MetaData), NewProp_Fitting_MetaData) }; // 2094547099
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnShipFittingReceived__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnShipFittingReceived__DelegateSignature_Statics::NewProp_Fitting,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnShipFittingReceived__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnShipFittingReceived__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnShipFittingReceived__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnShipFittingReceived__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnShipFittingReceived__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnShipFittingReceived__DelegateSignature_Statics::_Script_Echoes_eventOnShipFittingReceived_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00520000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnShipFittingReceived__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnShipFittingReceived__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnShipFittingReceived__DelegateSignature_Statics::_Script_Echoes_eventOnShipFittingReceived_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnShipFittingReceived__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnShipFittingReceived__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnShipFittingReceived_DelegateWrapper(const FScriptDelegate& OnShipFittingReceived, FEchoesShipFitting const& Fitting)
{
	struct _Script_Echoes_eventOnShipFittingReceived_Parms
	{
		FEchoesShipFitting Fitting;
	};
	_Script_Echoes_eventOnShipFittingReceived_Parms Parms;
	Parms.Fitting=Fitting;
	OnShipFittingReceived.ProcessDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnShipFittingReceived **************************************************

// ********** Begin Delegate FOnInventoryFailure ***************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnInventoryFailure__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnInventoryFailure_Parms
	{
		FString ErrorMessage;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_Echoes_OnInventoryFailure__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnInventoryFailure_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorMessage_MetaData), NewProp_ErrorMessage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnInventoryFailure__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnInventoryFailure__DelegateSignature_Statics::NewProp_ErrorMessage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnInventoryFailure__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnInventoryFailure__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnInventoryFailure__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnInventoryFailure__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnInventoryFailure__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnInventoryFailure__DelegateSignature_Statics::_Script_Echoes_eventOnInventoryFailure_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnInventoryFailure__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnInventoryFailure__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnInventoryFailure__DelegateSignature_Statics::_Script_Echoes_eventOnInventoryFailure_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnInventoryFailure__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnInventoryFailure__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnInventoryFailure_DelegateWrapper(const FScriptDelegate& OnInventoryFailure, const FString& ErrorMessage)
{
	struct _Script_Echoes_eventOnInventoryFailure_Parms
	{
		FString ErrorMessage;
	};
	_Script_Echoes_eventOnInventoryFailure_Parms Parms;
	Parms.ErrorMessage=ErrorMessage;
	OnInventoryFailure.ProcessDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnInventoryFailure *****************************************************

// ********** Begin Delegate FOnShipActivated ******************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnShipActivated__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnShipActivated__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnShipActivated__DelegateSignature", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnShipActivated__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnShipActivated__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_Echoes_OnShipActivated__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnShipActivated__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnShipActivated_DelegateWrapper(const FScriptDelegate& OnShipActivated)
{
	OnShipActivated.ProcessDelegate<UObject>(NULL);
}
// ********** End Delegate FOnShipActivated ********************************************************

// ********** Begin Delegate FOnModuleFitted *******************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnModuleFitted__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnModuleFitted__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnModuleFitted__DelegateSignature", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnModuleFitted__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnModuleFitted__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_Echoes_OnModuleFitted__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnModuleFitted__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnModuleFitted_DelegateWrapper(const FScriptDelegate& OnModuleFitted)
{
	OnModuleFitted.ProcessDelegate<UObject>(NULL);
}
// ********** End Delegate FOnModuleFitted *********************************************************

// ********** Begin Delegate FOnModuleUnfitted *****************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnModuleUnfitted__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnModuleUnfitted__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnModuleUnfitted__DelegateSignature", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnModuleUnfitted__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnModuleUnfitted__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_Echoes_OnModuleUnfitted__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnModuleUnfitted__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnModuleUnfitted_DelegateWrapper(const FScriptDelegate& OnModuleUnfitted)
{
	OnModuleUnfitted.ProcessDelegate<UObject>(NULL);
}
// ********** End Delegate FOnModuleUnfitted *******************************************************

// ********** Begin Delegate FOnHangarReceived *****************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnHangarReceived__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnHangarReceived_Parms
	{
		FGuid HangarStorageId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HangarStorageId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_HangarStorageId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Echoes_OnHangarReceived__DelegateSignature_Statics::NewProp_HangarStorageId = { "HangarStorageId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnHangarReceived_Parms, HangarStorageId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HangarStorageId_MetaData), NewProp_HangarStorageId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnHangarReceived__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnHangarReceived__DelegateSignature_Statics::NewProp_HangarStorageId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnHangarReceived__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnHangarReceived__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnHangarReceived__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnHangarReceived__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnHangarReceived__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnHangarReceived__DelegateSignature_Statics::_Script_Echoes_eventOnHangarReceived_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00520000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnHangarReceived__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnHangarReceived__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnHangarReceived__DelegateSignature_Statics::_Script_Echoes_eventOnHangarReceived_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnHangarReceived__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnHangarReceived__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnHangarReceived_DelegateWrapper(const FScriptDelegate& OnHangarReceived, FGuid const& HangarStorageId)
{
	struct _Script_Echoes_eventOnHangarReceived_Parms
	{
		FGuid HangarStorageId;
	};
	_Script_Echoes_eventOnHangarReceived_Parms Parms;
	Parms.HangarStorageId=HangarStorageId;
	OnHangarReceived.ProcessDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnHangarReceived *******************************************************

// ********** Begin Class UEchoesInventorySubsystem Function AsyncLoadItemIcon *********************
struct Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemIcon_Statics
{
	struct EchoesInventorySubsystem_eventAsyncLoadItemIcon_Parms
	{
		FString ItemId;
		FScriptDelegate OnLoaded;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|ItemDefinitions" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Async load item icon texture\n\x09 * Prevents UI freezes when loading many icons\n\x09 * \n\x09 * @param ItemId - Item type ID as string\n\x09 * @param OnLoaded - Callback when texture is loaded\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Async load item icon texture\nPrevents UI freezes when loading many icons\n\n@param ItemId - Item type ID as string\n@param OnLoaded - Callback when texture is loaded" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ItemId;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnLoaded;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemIcon_Statics::NewProp_ItemId = { "ItemId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventAsyncLoadItemIcon_Parms, ItemId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemId_MetaData), NewProp_ItemId_MetaData) };
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemIcon_Statics::NewProp_OnLoaded = { "OnLoaded", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventAsyncLoadItemIcon_Parms, OnLoaded), Z_Construct_UDelegateFunction_Echoes_OnIconLoaded__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 918840736
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemIcon_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemIcon_Statics::NewProp_ItemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemIcon_Statics::NewProp_OnLoaded,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemIcon_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemIcon_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventorySubsystem, nullptr, "AsyncLoadItemIcon", Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemIcon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemIcon_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemIcon_Statics::EchoesInventorySubsystem_eventAsyncLoadItemIcon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemIcon_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemIcon_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemIcon_Statics::EchoesInventorySubsystem_eventAsyncLoadItemIcon_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemIcon()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemIcon_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventorySubsystem::execAsyncLoadItemIcon)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ItemId);
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnLoaded);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AsyncLoadItemIcon(Z_Param_ItemId,FOnIconLoaded(Z_Param_OnLoaded));
	P_NATIVE_END;
}
// ********** End Class UEchoesInventorySubsystem Function AsyncLoadItemIcon ***********************

// ********** Begin Class UEchoesInventorySubsystem Function AsyncLoadItemWorldMesh ****************
struct Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemWorldMesh_Statics
{
	struct EchoesInventorySubsystem_eventAsyncLoadItemWorldMesh_Parms
	{
		FString ItemId;
		FScriptDelegate OnLoaded;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|ItemDefinitions" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Async load item world mesh\n\x09 * Used for ejected items in space\n\x09 * \n\x09 * @param ItemId - Item type ID as string\n\x09 * @param OnLoaded - Callback when mesh is loaded\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Async load item world mesh\nUsed for ejected items in space\n\n@param ItemId - Item type ID as string\n@param OnLoaded - Callback when mesh is loaded" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ItemId;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnLoaded;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemWorldMesh_Statics::NewProp_ItemId = { "ItemId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventAsyncLoadItemWorldMesh_Parms, ItemId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemId_MetaData), NewProp_ItemId_MetaData) };
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemWorldMesh_Statics::NewProp_OnLoaded = { "OnLoaded", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventAsyncLoadItemWorldMesh_Parms, OnLoaded), Z_Construct_UDelegateFunction_Echoes_OnWorldMeshLoaded__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 1175307942
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemWorldMesh_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemWorldMesh_Statics::NewProp_ItemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemWorldMesh_Statics::NewProp_OnLoaded,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemWorldMesh_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemWorldMesh_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventorySubsystem, nullptr, "AsyncLoadItemWorldMesh", Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemWorldMesh_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemWorldMesh_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemWorldMesh_Statics::EchoesInventorySubsystem_eventAsyncLoadItemWorldMesh_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemWorldMesh_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemWorldMesh_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemWorldMesh_Statics::EchoesInventorySubsystem_eventAsyncLoadItemWorldMesh_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemWorldMesh()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemWorldMesh_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventorySubsystem::execAsyncLoadItemWorldMesh)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ItemId);
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnLoaded);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AsyncLoadItemWorldMesh(Z_Param_ItemId,FOnWorldMeshLoaded(Z_Param_OnLoaded));
	P_NATIVE_END;
}
// ********** End Class UEchoesInventorySubsystem Function AsyncLoadItemWorldMesh ******************

// ********** Begin Class UEchoesInventorySubsystem Function GetItemDefinitionData *****************
struct Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionData_Statics
{
	struct EchoesInventorySubsystem_eventGetItemDefinitionData_Parms
	{
		FString ItemId;
		FEchoesItemDefinitionRow ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|ItemDefinitions" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Try to get item definition by item ID for Blueprints\n\x09 * \n\x09 * @param ItemId - Item type ID as string (e.g., \"34\" for Tritanium)\n\x09 * @return Definition data if found, otherwise default-constructed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Try to get item definition by item ID for Blueprints\n\n@param ItemId - Item type ID as string (e.g., \"34\" for Tritanium)\n@return Definition data if found, otherwise default-constructed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ItemId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionData_Statics::NewProp_ItemId = { "ItemId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventGetItemDefinitionData_Parms, ItemId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemId_MetaData), NewProp_ItemId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventGetItemDefinitionData_Parms, ReturnValue), Z_Construct_UScriptStruct_FEchoesItemDefinitionRow, METADATA_PARAMS(0, nullptr) }; // 987535441
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionData_Statics::NewProp_ItemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventorySubsystem, nullptr, "GetItemDefinitionData", Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionData_Statics::EchoesInventorySubsystem_eventGetItemDefinitionData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionData_Statics::EchoesInventorySubsystem_eventGetItemDefinitionData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventorySubsystem::execGetItemDefinitionData)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ItemId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FEchoesItemDefinitionRow*)Z_Param__Result=P_THIS->GetItemDefinitionData(Z_Param_ItemId);
	P_NATIVE_END;
}
// ********** End Class UEchoesInventorySubsystem Function GetItemDefinitionData *******************

// ********** Begin Class UEchoesInventorySubsystem Function GetItemDefinitionDataByTypeId *********
struct Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionDataByTypeId_Statics
{
	struct EchoesInventorySubsystem_eventGetItemDefinitionDataByTypeId_Parms
	{
		int32 TypeId;
		FEchoesItemDefinitionRow ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|ItemDefinitions" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get item definition by integer type ID for Blueprints\n\x09 * \n\x09 * @param TypeId - Item type ID as integer\n\x09 * @return Definition data if found, otherwise default-constructed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get item definition by integer type ID for Blueprints\n\n@param TypeId - Item type ID as integer\n@return Definition data if found, otherwise default-constructed" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_TypeId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionDataByTypeId_Statics::NewProp_TypeId = { "TypeId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventGetItemDefinitionDataByTypeId_Parms, TypeId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionDataByTypeId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventGetItemDefinitionDataByTypeId_Parms, ReturnValue), Z_Construct_UScriptStruct_FEchoesItemDefinitionRow, METADATA_PARAMS(0, nullptr) }; // 987535441
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionDataByTypeId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionDataByTypeId_Statics::NewProp_TypeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionDataByTypeId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionDataByTypeId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionDataByTypeId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventorySubsystem, nullptr, "GetItemDefinitionDataByTypeId", Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionDataByTypeId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionDataByTypeId_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionDataByTypeId_Statics::EchoesInventorySubsystem_eventGetItemDefinitionDataByTypeId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionDataByTypeId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionDataByTypeId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionDataByTypeId_Statics::EchoesInventorySubsystem_eventGetItemDefinitionDataByTypeId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionDataByTypeId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionDataByTypeId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventorySubsystem::execGetItemDefinitionDataByTypeId)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_TypeId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FEchoesItemDefinitionRow*)Z_Param__Result=P_THIS->GetItemDefinitionDataByTypeId(Z_Param_TypeId);
	P_NATIVE_END;
}
// ********** End Class UEchoesInventorySubsystem Function GetItemDefinitionDataByTypeId ***********

// ********** Begin Class UEchoesInventorySubsystem Function GetItemFromRegistryData ***************
struct Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemFromRegistryData_Statics
{
	struct EchoesInventorySubsystem_eventGetItemFromRegistryData_Parms
	{
		int32 TypeId;
		FEchoesItemDefinitionRow ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|ItemDefinitions" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get item definition from typed registry by integer TypeId for Blueprints\n\x09 * \n\x09 * @param TypeId - Item type ID as integer\n\x09 * @return Definition data if found, otherwise default-constructed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get item definition from typed registry by integer TypeId for Blueprints\n\n@param TypeId - Item type ID as integer\n@return Definition data if found, otherwise default-constructed" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_TypeId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemFromRegistryData_Statics::NewProp_TypeId = { "TypeId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventGetItemFromRegistryData_Parms, TypeId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemFromRegistryData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventGetItemFromRegistryData_Parms, ReturnValue), Z_Construct_UScriptStruct_FEchoesItemDefinitionRow, METADATA_PARAMS(0, nullptr) }; // 987535441
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemFromRegistryData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemFromRegistryData_Statics::NewProp_TypeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemFromRegistryData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemFromRegistryData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemFromRegistryData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventorySubsystem, nullptr, "GetItemFromRegistryData", Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemFromRegistryData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemFromRegistryData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemFromRegistryData_Statics::EchoesInventorySubsystem_eventGetItemFromRegistryData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemFromRegistryData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemFromRegistryData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemFromRegistryData_Statics::EchoesInventorySubsystem_eventGetItemFromRegistryData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemFromRegistryData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemFromRegistryData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventorySubsystem::execGetItemFromRegistryData)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_TypeId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FEchoesItemDefinitionRow*)Z_Param__Result=P_THIS->GetItemFromRegistryData(Z_Param_TypeId);
	P_NATIVE_END;
}
// ********** End Class UEchoesInventorySubsystem Function GetItemFromRegistryData *****************

// ********** Begin Class UEchoesInventorySubsystem Function GetPersonalHangarId *******************
struct Z_Construct_UFunction_UEchoesInventorySubsystem_GetPersonalHangarId_Statics
{
	struct EchoesInventorySubsystem_eventGetPersonalHangarId_Parms
	{
		int32 StationId;
		FGuid ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get personal hangar ID for a specific station (synchronous)\n\x09 * Returns cached hangar ID if available, otherwise returns invalid GUID\n\x09 * Use Inventory_RequestPersonalHangar for async retrieval\n\x09 * \n\x09 * @param StationId - Station ID to get hangar for\n\x09 * @return Hangar storage ID (may be invalid if not cached)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get personal hangar ID for a specific station (synchronous)\nReturns cached hangar ID if available, otherwise returns invalid GUID\nUse Inventory_RequestPersonalHangar for async retrieval\n\n@param StationId - Station ID to get hangar for\n@return Hangar storage ID (may be invalid if not cached)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_StationId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_GetPersonalHangarId_Statics::NewProp_StationId = { "StationId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventGetPersonalHangarId_Parms, StationId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_GetPersonalHangarId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventGetPersonalHangarId_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventorySubsystem_GetPersonalHangarId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_GetPersonalHangarId_Statics::NewProp_StationId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_GetPersonalHangarId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_GetPersonalHangarId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventorySubsystem_GetPersonalHangarId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventorySubsystem, nullptr, "GetPersonalHangarId", Z_Construct_UFunction_UEchoesInventorySubsystem_GetPersonalHangarId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_GetPersonalHangarId_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_GetPersonalHangarId_Statics::EchoesInventorySubsystem_eventGetPersonalHangarId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_GetPersonalHangarId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventorySubsystem_GetPersonalHangarId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_GetPersonalHangarId_Statics::EchoesInventorySubsystem_eventGetPersonalHangarId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventorySubsystem_GetPersonalHangarId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventorySubsystem_GetPersonalHangarId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventorySubsystem::execGetPersonalHangarId)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_StationId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGuid*)Z_Param__Result=P_THIS->GetPersonalHangarId(Z_Param_StationId);
	P_NATIVE_END;
}
// ********** End Class UEchoesInventorySubsystem Function GetPersonalHangarId *********************

// ********** Begin Class UEchoesInventorySubsystem Function HasItemDefinition *********************
struct Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemDefinition_Statics
{
	struct EchoesInventorySubsystem_eventHasItemDefinition_Parms
	{
		FString ItemId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|ItemDefinitions" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if item definition exists\n\x09 * \n\x09 * @param ItemId - Item type ID as string\n\x09 * @return True if definition exists in table\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if item definition exists\n\n@param ItemId - Item type ID as string\n@return True if definition exists in table" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ItemId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemDefinition_Statics::NewProp_ItemId = { "ItemId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventHasItemDefinition_Parms, ItemId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemId_MetaData), NewProp_ItemId_MetaData) };
void Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemDefinition_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesInventorySubsystem_eventHasItemDefinition_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemDefinition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesInventorySubsystem_eventHasItemDefinition_Parms), &Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemDefinition_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemDefinition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemDefinition_Statics::NewProp_ItemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemDefinition_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemDefinition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemDefinition_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventorySubsystem, nullptr, "HasItemDefinition", Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemDefinition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemDefinition_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemDefinition_Statics::EchoesInventorySubsystem_eventHasItemDefinition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemDefinition_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemDefinition_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemDefinition_Statics::EchoesInventorySubsystem_eventHasItemDefinition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemDefinition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemDefinition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventorySubsystem::execHasItemDefinition)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ItemId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->HasItemDefinition(Z_Param_ItemId);
	P_NATIVE_END;
}
// ********** End Class UEchoesInventorySubsystem Function HasItemDefinition ***********************

// ********** Begin Class UEchoesInventorySubsystem Function HasItemInRegistry *********************
struct Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemInRegistry_Statics
{
	struct EchoesInventorySubsystem_eventHasItemInRegistry_Parms
	{
		int32 TypeId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|ItemDefinitions" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if item exists in typed registry\n\x09 * \n\x09 * @param TypeId - Item type ID as integer\n\x09 * @return True if definition exists in registry\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if item exists in typed registry\n\n@param TypeId - Item type ID as integer\n@return True if definition exists in registry" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_TypeId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemInRegistry_Statics::NewProp_TypeId = { "TypeId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventHasItemInRegistry_Parms, TypeId), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemInRegistry_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesInventorySubsystem_eventHasItemInRegistry_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemInRegistry_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesInventorySubsystem_eventHasItemInRegistry_Parms), &Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemInRegistry_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemInRegistry_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemInRegistry_Statics::NewProp_TypeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemInRegistry_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemInRegistry_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemInRegistry_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventorySubsystem, nullptr, "HasItemInRegistry", Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemInRegistry_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemInRegistry_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemInRegistry_Statics::EchoesInventorySubsystem_eventHasItemInRegistry_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemInRegistry_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemInRegistry_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemInRegistry_Statics::EchoesInventorySubsystem_eventHasItemInRegistry_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemInRegistry()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemInRegistry_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventorySubsystem::execHasItemInRegistry)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_TypeId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->HasItemInRegistry(Z_Param_TypeId);
	P_NATIVE_END;
}
// ********** End Class UEchoesInventorySubsystem Function HasItemInRegistry ***********************

// ********** Begin Class UEchoesInventorySubsystem Function Inventory_ClearCache ******************
struct Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_ClearCache_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Clear inventory cache\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Clear inventory cache" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_ClearCache_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventorySubsystem, nullptr, "Inventory_ClearCache", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_ClearCache_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_ClearCache_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_ClearCache()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_ClearCache_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventorySubsystem::execInventory_ClearCache)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Inventory_ClearCache();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventorySubsystem Function Inventory_ClearCache ********************

// ********** Begin Class UEchoesInventorySubsystem Function Inventory_FetchShipFitting ************
struct Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShipFitting_Statics
{
	struct EchoesInventorySubsystem_eventInventory_FetchShipFitting_Parms
	{
		FGuid ShipId;
		FScriptDelegate OnSuccess;
		FScriptDelegate OnFailure;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Fetch detailed ship fitting with all modules\n\x09 * Sends HTTP GET to /api/inventory/ship/{id}/fitting with JWT token\n\x09 * This data is used to initialize the Movement Component physics\n\x09 * \n\x09 * @param ShipId - Ship instance ID\n\x09 * @param OnSuccess - Callback with detailed fitting\n\x09 * @param OnFailure - Callback on request failure\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fetch detailed ship fitting with all modules\nSends HTTP GET to /api/inventory/ship/{id}/fitting with JWT token\nThis data is used to initialize the Movement Component physics\n\n@param ShipId - Ship instance ID\n@param OnSuccess - Callback with detailed fitting\n@param OnFailure - Callback on request failure" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ShipId;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnSuccess;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnFailure;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShipFitting_Statics::NewProp_ShipId = { "ShipId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventInventory_FetchShipFitting_Parms, ShipId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipId_MetaData), NewProp_ShipId_MetaData) };
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShipFitting_Statics::NewProp_OnSuccess = { "OnSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventInventory_FetchShipFitting_Parms, OnSuccess), Z_Construct_UDelegateFunction_Echoes_OnShipFittingReceived__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 395400533
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShipFitting_Statics::NewProp_OnFailure = { "OnFailure", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventInventory_FetchShipFitting_Parms, OnFailure), Z_Construct_UDelegateFunction_Echoes_OnInventoryFailure__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 3872701800
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShipFitting_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShipFitting_Statics::NewProp_ShipId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShipFitting_Statics::NewProp_OnSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShipFitting_Statics::NewProp_OnFailure,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShipFitting_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShipFitting_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventorySubsystem, nullptr, "Inventory_FetchShipFitting", Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShipFitting_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShipFitting_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShipFitting_Statics::EchoesInventorySubsystem_eventInventory_FetchShipFitting_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShipFitting_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShipFitting_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShipFitting_Statics::EchoesInventorySubsystem_eventInventory_FetchShipFitting_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShipFitting()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShipFitting_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventorySubsystem::execInventory_FetchShipFitting)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_ShipId);
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnSuccess);
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnFailure);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Inventory_FetchShipFitting(Z_Param_Out_ShipId,FOnShipFittingReceived(Z_Param_OnSuccess),FOnInventoryFailure(Z_Param_OnFailure));
	P_NATIVE_END;
}
// ********** End Class UEchoesInventorySubsystem Function Inventory_FetchShipFitting **************

// ********** Begin Class UEchoesInventorySubsystem Function Inventory_FetchShips ******************
struct Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShips_Statics
{
	struct EchoesInventorySubsystem_eventInventory_FetchShips_Parms
	{
		FScriptDelegate OnSuccess;
		FScriptDelegate OnFailure;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Fetch all ships for current character\n\x09 * Sends HTTP GET to /api/inventory/ships with JWT token\n\x09 * \n\x09 * @param OnSuccess - Callback with ship list\n\x09 * @param OnFailure - Callback on request failure\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fetch all ships for current character\nSends HTTP GET to /api/inventory/ships with JWT token\n\n@param OnSuccess - Callback with ship list\n@param OnFailure - Callback on request failure" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnSuccess;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnFailure;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShips_Statics::NewProp_OnSuccess = { "OnSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventInventory_FetchShips_Parms, OnSuccess), Z_Construct_UDelegateFunction_Echoes_OnShipsReceived__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 3676293021
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShips_Statics::NewProp_OnFailure = { "OnFailure", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventInventory_FetchShips_Parms, OnFailure), Z_Construct_UDelegateFunction_Echoes_OnInventoryFailure__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 3872701800
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShips_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShips_Statics::NewProp_OnSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShips_Statics::NewProp_OnFailure,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShips_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShips_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventorySubsystem, nullptr, "Inventory_FetchShips", Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShips_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShips_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShips_Statics::EchoesInventorySubsystem_eventInventory_FetchShips_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShips_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShips_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShips_Statics::EchoesInventorySubsystem_eventInventory_FetchShips_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShips()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShips_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventorySubsystem::execInventory_FetchShips)
{
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnSuccess);
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnFailure);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Inventory_FetchShips(FOnShipsReceived(Z_Param_OnSuccess),FOnInventoryFailure(Z_Param_OnFailure));
	P_NATIVE_END;
}
// ********** End Class UEchoesInventorySubsystem Function Inventory_FetchShips ********************

// ********** Begin Class UEchoesInventorySubsystem Function Inventory_GetActiveShip ***************
struct Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetActiveShip_Statics
{
	struct EchoesInventorySubsystem_eventInventory_GetActiveShip_Parms
	{
		FEchoesShipInstance ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get active ship from cached list\n\x09 * \n\x09 * @return Active ship instance (if any)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get active ship from cached list\n\n@return Active ship instance (if any)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetActiveShip_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventInventory_GetActiveShip_Parms, ReturnValue), Z_Construct_UScriptStruct_FEchoesShipInstance, METADATA_PARAMS(0, nullptr) }; // 219373969
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetActiveShip_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetActiveShip_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetActiveShip_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetActiveShip_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventorySubsystem, nullptr, "Inventory_GetActiveShip", Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetActiveShip_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetActiveShip_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetActiveShip_Statics::EchoesInventorySubsystem_eventInventory_GetActiveShip_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetActiveShip_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetActiveShip_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetActiveShip_Statics::EchoesInventorySubsystem_eventInventory_GetActiveShip_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetActiveShip()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetActiveShip_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventorySubsystem::execInventory_GetActiveShip)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FEchoesShipInstance*)Z_Param__Result=P_THIS->Inventory_GetActiveShip();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventorySubsystem Function Inventory_GetActiveShip *****************

// ********** Begin Class UEchoesInventorySubsystem Function Inventory_GetCachedFitting ************
struct Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedFitting_Statics
{
	struct EchoesInventorySubsystem_eventInventory_GetCachedFitting_Parms
	{
		FEchoesShipFitting ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get cached ship fitting\n\x09 * \n\x09 * @return Last fetched ship fitting\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get cached ship fitting\n\n@return Last fetched ship fitting" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedFitting_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventInventory_GetCachedFitting_Parms, ReturnValue), Z_Construct_UScriptStruct_FEchoesShipFitting, METADATA_PARAMS(0, nullptr) }; // 2094547099
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedFitting_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedFitting_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedFitting_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedFitting_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventorySubsystem, nullptr, "Inventory_GetCachedFitting", Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedFitting_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedFitting_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedFitting_Statics::EchoesInventorySubsystem_eventInventory_GetCachedFitting_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedFitting_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedFitting_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedFitting_Statics::EchoesInventorySubsystem_eventInventory_GetCachedFitting_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedFitting()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedFitting_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventorySubsystem::execInventory_GetCachedFitting)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FEchoesShipFitting*)Z_Param__Result=P_THIS->Inventory_GetCachedFitting();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventorySubsystem Function Inventory_GetCachedFitting **************

// ********** Begin Class UEchoesInventorySubsystem Function Inventory_GetCachedShips **************
struct Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedShips_Statics
{
	struct EchoesInventorySubsystem_eventInventory_GetCachedShips_Parms
	{
		TArray<FEchoesShipInstance> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get cached ships list\n\x09 * \n\x09 * @return Array of ship instances\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get cached ships list\n\n@return Array of ship instances" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedShips_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FEchoesShipInstance, METADATA_PARAMS(0, nullptr) }; // 219373969
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedShips_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventInventory_GetCachedShips_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 219373969
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedShips_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedShips_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedShips_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedShips_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedShips_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventorySubsystem, nullptr, "Inventory_GetCachedShips", Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedShips_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedShips_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedShips_Statics::EchoesInventorySubsystem_eventInventory_GetCachedShips_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedShips_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedShips_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedShips_Statics::EchoesInventorySubsystem_eventInventory_GetCachedShips_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedShips()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedShips_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventorySubsystem::execInventory_GetCachedShips)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FEchoesShipInstance>*)Z_Param__Result=P_THIS->Inventory_GetCachedShips();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventorySubsystem Function Inventory_GetCachedShips ****************

// ********** Begin Class UEchoesInventorySubsystem Function Inventory_RequestPersonalHangar *******
struct Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_RequestPersonalHangar_Statics
{
	struct EchoesInventorySubsystem_eventInventory_RequestPersonalHangar_Parms
	{
		int32 StationId;
		FScriptDelegate OnSuccess;
		FScriptDelegate OnFailure;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Request personal hangar storage ID at a station\n\x09 * Sends HTTP GET to /api/inventory/hangar/{stationId} with JWT token\n\x09 * Backend will return or create the player's personal hangar container\n\x09 * \n\x09 * @param StationId - Station ID to get hangar for\n\x09 * @param OnSuccess - Callback with hangar storage ID\n\x09 * @param OnFailure - Callback on request failure\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Request personal hangar storage ID at a station\nSends HTTP GET to /api/inventory/hangar/{stationId} with JWT token\nBackend will return or create the player's personal hangar container\n\n@param StationId - Station ID to get hangar for\n@param OnSuccess - Callback with hangar storage ID\n@param OnFailure - Callback on request failure" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_StationId;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnSuccess;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnFailure;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_RequestPersonalHangar_Statics::NewProp_StationId = { "StationId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventInventory_RequestPersonalHangar_Parms, StationId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_RequestPersonalHangar_Statics::NewProp_OnSuccess = { "OnSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventInventory_RequestPersonalHangar_Parms, OnSuccess), Z_Construct_UDelegateFunction_Echoes_OnHangarReceived__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 479979742
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_RequestPersonalHangar_Statics::NewProp_OnFailure = { "OnFailure", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventInventory_RequestPersonalHangar_Parms, OnFailure), Z_Construct_UDelegateFunction_Echoes_OnInventoryFailure__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 3872701800
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_RequestPersonalHangar_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_RequestPersonalHangar_Statics::NewProp_StationId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_RequestPersonalHangar_Statics::NewProp_OnSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_RequestPersonalHangar_Statics::NewProp_OnFailure,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_RequestPersonalHangar_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_RequestPersonalHangar_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventorySubsystem, nullptr, "Inventory_RequestPersonalHangar", Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_RequestPersonalHangar_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_RequestPersonalHangar_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_RequestPersonalHangar_Statics::EchoesInventorySubsystem_eventInventory_RequestPersonalHangar_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_RequestPersonalHangar_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_RequestPersonalHangar_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_RequestPersonalHangar_Statics::EchoesInventorySubsystem_eventInventory_RequestPersonalHangar_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_RequestPersonalHangar()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_RequestPersonalHangar_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventorySubsystem::execInventory_RequestPersonalHangar)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_StationId);
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnSuccess);
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnFailure);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Inventory_RequestPersonalHangar(Z_Param_StationId,FOnHangarReceived(Z_Param_OnSuccess),FOnInventoryFailure(Z_Param_OnFailure));
	P_NATIVE_END;
}
// ********** End Class UEchoesInventorySubsystem Function Inventory_RequestPersonalHangar *********

// ********** Begin Class UEchoesInventorySubsystem Function Inventory_SetActiveShip ***************
struct Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_SetActiveShip_Statics
{
	struct EchoesInventorySubsystem_eventInventory_SetActiveShip_Parms
	{
		FGuid ShipId;
		FScriptDelegate OnSuccess;
		FScriptDelegate OnFailure;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Set active ship (activate ship for undocking)\n\x09 * Sends HTTP POST to /api/inventory/ship/{id}/activate with JWT token\n\x09 * \n\x09 * @param ShipId - Ship instance ID to activate\n\x09 * @param OnSuccess - Callback on successful activation\n\x09 * @param OnFailure - Callback on activation failure\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set active ship (activate ship for undocking)\nSends HTTP POST to /api/inventory/ship/{id}/activate with JWT token\n\n@param ShipId - Ship instance ID to activate\n@param OnSuccess - Callback on successful activation\n@param OnFailure - Callback on activation failure" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ShipId;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnSuccess;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnFailure;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_SetActiveShip_Statics::NewProp_ShipId = { "ShipId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventInventory_SetActiveShip_Parms, ShipId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipId_MetaData), NewProp_ShipId_MetaData) };
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_SetActiveShip_Statics::NewProp_OnSuccess = { "OnSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventInventory_SetActiveShip_Parms, OnSuccess), Z_Construct_UDelegateFunction_Echoes_OnShipActivated__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 1119293813
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_SetActiveShip_Statics::NewProp_OnFailure = { "OnFailure", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventInventory_SetActiveShip_Parms, OnFailure), Z_Construct_UDelegateFunction_Echoes_OnInventoryFailure__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 3872701800
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_SetActiveShip_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_SetActiveShip_Statics::NewProp_ShipId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_SetActiveShip_Statics::NewProp_OnSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_SetActiveShip_Statics::NewProp_OnFailure,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_SetActiveShip_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_SetActiveShip_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventorySubsystem, nullptr, "Inventory_SetActiveShip", Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_SetActiveShip_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_SetActiveShip_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_SetActiveShip_Statics::EchoesInventorySubsystem_eventInventory_SetActiveShip_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_SetActiveShip_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_SetActiveShip_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_SetActiveShip_Statics::EchoesInventorySubsystem_eventInventory_SetActiveShip_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_SetActiveShip()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_SetActiveShip_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventorySubsystem::execInventory_SetActiveShip)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_ShipId);
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnSuccess);
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnFailure);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Inventory_SetActiveShip(Z_Param_Out_ShipId,FOnShipActivated(Z_Param_OnSuccess),FOnInventoryFailure(Z_Param_OnFailure));
	P_NATIVE_END;
}
// ********** End Class UEchoesInventorySubsystem Function Inventory_SetActiveShip *****************

// ********** Begin Class UEchoesInventorySubsystem Function UI_FitModule **************************
struct Z_Construct_UFunction_UEchoesInventorySubsystem_UI_FitModule_Statics
{
	struct EchoesInventorySubsystem_eventUI_FitModule_Parms
	{
		FGuid ShipId;
		FGuid ModuleId;
		FString SlotType;
		int32 SlotIndex;
		FScriptDelegate OnSuccess;
		FScriptDelegate OnFailure;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * UI wrapper: Fit a module to a ship\n\x09 * Sends HTTP PUT to /api/inventory/ship/{shipId}/module/{moduleId}/fit\n\x09 * Automatically refreshes fitting and triggers OnFittingChanged delegate\n\x09 * \n\x09 * @param ShipId - Ship instance ID\n\x09 * @param ModuleId - Module instance ID to fit\n\x09 * @param SlotType - Slot type (High, Mid, Low, Rig)\n\x09 * @param SlotIndex - Slot index within type\n\x09 * @param OnSuccess - Callback on successful fit\n\x09 * @param OnFailure - Callback on fit failure\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UI wrapper: Fit a module to a ship\nSends HTTP PUT to /api/inventory/ship/{shipId}/module/{moduleId}/fit\nAutomatically refreshes fitting and triggers OnFittingChanged delegate\n\n@param ShipId - Ship instance ID\n@param ModuleId - Module instance ID to fit\n@param SlotType - Slot type (High, Mid, Low, Rig)\n@param SlotIndex - Slot index within type\n@param OnSuccess - Callback on successful fit\n@param OnFailure - Callback on fit failure" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipId_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ModuleId_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotType_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ShipId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ModuleId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SlotType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnSuccess;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnFailure;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_UI_FitModule_Statics::NewProp_ShipId = { "ShipId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventUI_FitModule_Parms, ShipId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipId_MetaData), NewProp_ShipId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_UI_FitModule_Statics::NewProp_ModuleId = { "ModuleId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventUI_FitModule_Parms, ModuleId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ModuleId_MetaData), NewProp_ModuleId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_UI_FitModule_Statics::NewProp_SlotType = { "SlotType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventUI_FitModule_Parms, SlotType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotType_MetaData), NewProp_SlotType_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_UI_FitModule_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventUI_FitModule_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_UI_FitModule_Statics::NewProp_OnSuccess = { "OnSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventUI_FitModule_Parms, OnSuccess), Z_Construct_UDelegateFunction_Echoes_OnModuleFitted__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 1812756143
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_UI_FitModule_Statics::NewProp_OnFailure = { "OnFailure", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventUI_FitModule_Parms, OnFailure), Z_Construct_UDelegateFunction_Echoes_OnInventoryFailure__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 3872701800
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventorySubsystem_UI_FitModule_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_UI_FitModule_Statics::NewProp_ShipId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_UI_FitModule_Statics::NewProp_ModuleId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_UI_FitModule_Statics::NewProp_SlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_UI_FitModule_Statics::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_UI_FitModule_Statics::NewProp_OnSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_UI_FitModule_Statics::NewProp_OnFailure,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_UI_FitModule_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventorySubsystem_UI_FitModule_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventorySubsystem, nullptr, "UI_FitModule", Z_Construct_UFunction_UEchoesInventorySubsystem_UI_FitModule_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_UI_FitModule_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_UI_FitModule_Statics::EchoesInventorySubsystem_eventUI_FitModule_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_UI_FitModule_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventorySubsystem_UI_FitModule_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_UI_FitModule_Statics::EchoesInventorySubsystem_eventUI_FitModule_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventorySubsystem_UI_FitModule()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventorySubsystem_UI_FitModule_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventorySubsystem::execUI_FitModule)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_ShipId);
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_ModuleId);
	P_GET_PROPERTY(FStrProperty,Z_Param_SlotType);
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnSuccess);
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnFailure);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UI_FitModule(Z_Param_Out_ShipId,Z_Param_Out_ModuleId,Z_Param_SlotType,Z_Param_SlotIndex,FOnModuleFitted(Z_Param_OnSuccess),FOnInventoryFailure(Z_Param_OnFailure));
	P_NATIVE_END;
}
// ********** End Class UEchoesInventorySubsystem Function UI_FitModule ****************************

// ********** Begin Class UEchoesInventorySubsystem Function UI_UnfitModule ************************
struct Z_Construct_UFunction_UEchoesInventorySubsystem_UI_UnfitModule_Statics
{
	struct EchoesInventorySubsystem_eventUI_UnfitModule_Parms
	{
		FGuid ShipId;
		FGuid ModuleId;
		FScriptDelegate OnSuccess;
		FScriptDelegate OnFailure;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * UI wrapper: Unfit a module from a ship\n\x09 * Sends HTTP DELETE to /api/inventory/ship/{shipId}/module/{moduleId}/unfit\n\x09 * Automatically refreshes fitting and triggers OnFittingChanged delegate\n\x09 * \n\x09 * @param ShipId - Ship instance ID\n\x09 * @param ModuleId - Module instance ID to unfit\n\x09 * @param OnSuccess - Callback on successful unfit\n\x09 * @param OnFailure - Callback on unfit failure\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UI wrapper: Unfit a module from a ship\nSends HTTP DELETE to /api/inventory/ship/{shipId}/module/{moduleId}/unfit\nAutomatically refreshes fitting and triggers OnFittingChanged delegate\n\n@param ShipId - Ship instance ID\n@param ModuleId - Module instance ID to unfit\n@param OnSuccess - Callback on successful unfit\n@param OnFailure - Callback on unfit failure" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipId_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ModuleId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ShipId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ModuleId;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnSuccess;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnFailure;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_UI_UnfitModule_Statics::NewProp_ShipId = { "ShipId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventUI_UnfitModule_Parms, ShipId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipId_MetaData), NewProp_ShipId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_UI_UnfitModule_Statics::NewProp_ModuleId = { "ModuleId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventUI_UnfitModule_Parms, ModuleId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ModuleId_MetaData), NewProp_ModuleId_MetaData) };
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_UI_UnfitModule_Statics::NewProp_OnSuccess = { "OnSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventUI_UnfitModule_Parms, OnSuccess), Z_Construct_UDelegateFunction_Echoes_OnModuleUnfitted__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 4126736980
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesInventorySubsystem_UI_UnfitModule_Statics::NewProp_OnFailure = { "OnFailure", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventorySubsystem_eventUI_UnfitModule_Parms, OnFailure), Z_Construct_UDelegateFunction_Echoes_OnInventoryFailure__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 3872701800
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventorySubsystem_UI_UnfitModule_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_UI_UnfitModule_Statics::NewProp_ShipId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_UI_UnfitModule_Statics::NewProp_ModuleId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_UI_UnfitModule_Statics::NewProp_OnSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventorySubsystem_UI_UnfitModule_Statics::NewProp_OnFailure,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_UI_UnfitModule_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventorySubsystem_UI_UnfitModule_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventorySubsystem, nullptr, "UI_UnfitModule", Z_Construct_UFunction_UEchoesInventorySubsystem_UI_UnfitModule_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_UI_UnfitModule_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_UI_UnfitModule_Statics::EchoesInventorySubsystem_eventUI_UnfitModule_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventorySubsystem_UI_UnfitModule_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventorySubsystem_UI_UnfitModule_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventorySubsystem_UI_UnfitModule_Statics::EchoesInventorySubsystem_eventUI_UnfitModule_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventorySubsystem_UI_UnfitModule()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventorySubsystem_UI_UnfitModule_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventorySubsystem::execUI_UnfitModule)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_ShipId);
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_ModuleId);
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnSuccess);
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnFailure);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UI_UnfitModule(Z_Param_Out_ShipId,Z_Param_Out_ModuleId,FOnModuleUnfitted(Z_Param_OnSuccess),FOnInventoryFailure(Z_Param_OnFailure));
	P_NATIVE_END;
}
// ********** End Class UEchoesInventorySubsystem Function UI_UnfitModule **************************

// ********** Begin Class UEchoesInventorySubsystem ************************************************
void UEchoesInventorySubsystem::StaticRegisterNativesUEchoesInventorySubsystem()
{
	UClass* Class = UEchoesInventorySubsystem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AsyncLoadItemIcon", &UEchoesInventorySubsystem::execAsyncLoadItemIcon },
		{ "AsyncLoadItemWorldMesh", &UEchoesInventorySubsystem::execAsyncLoadItemWorldMesh },
		{ "GetItemDefinitionData", &UEchoesInventorySubsystem::execGetItemDefinitionData },
		{ "GetItemDefinitionDataByTypeId", &UEchoesInventorySubsystem::execGetItemDefinitionDataByTypeId },
		{ "GetItemFromRegistryData", &UEchoesInventorySubsystem::execGetItemFromRegistryData },
		{ "GetPersonalHangarId", &UEchoesInventorySubsystem::execGetPersonalHangarId },
		{ "HasItemDefinition", &UEchoesInventorySubsystem::execHasItemDefinition },
		{ "HasItemInRegistry", &UEchoesInventorySubsystem::execHasItemInRegistry },
		{ "Inventory_ClearCache", &UEchoesInventorySubsystem::execInventory_ClearCache },
		{ "Inventory_FetchShipFitting", &UEchoesInventorySubsystem::execInventory_FetchShipFitting },
		{ "Inventory_FetchShips", &UEchoesInventorySubsystem::execInventory_FetchShips },
		{ "Inventory_GetActiveShip", &UEchoesInventorySubsystem::execInventory_GetActiveShip },
		{ "Inventory_GetCachedFitting", &UEchoesInventorySubsystem::execInventory_GetCachedFitting },
		{ "Inventory_GetCachedShips", &UEchoesInventorySubsystem::execInventory_GetCachedShips },
		{ "Inventory_RequestPersonalHangar", &UEchoesInventorySubsystem::execInventory_RequestPersonalHangar },
		{ "Inventory_SetActiveShip", &UEchoesInventorySubsystem::execInventory_SetActiveShip },
		{ "UI_FitModule", &UEchoesInventorySubsystem::execUI_FitModule },
		{ "UI_UnfitModule", &UEchoesInventorySubsystem::execUI_UnfitModule },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesInventorySubsystem;
UClass* UEchoesInventorySubsystem::GetPrivateStaticClass()
{
	using TClass = UEchoesInventorySubsystem;
	if (!Z_Registration_Info_UClass_UEchoesInventorySubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesInventorySubsystem"),
			Z_Registration_Info_UClass_UEchoesInventorySubsystem.InnerSingleton,
			StaticRegisterNativesUEchoesInventorySubsystem,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UEchoesInventorySubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesInventorySubsystem_NoRegister()
{
	return UEchoesInventorySubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesInventorySubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UEchoesInventorySubsystem\n * \n * Inventory management subsystem for Echoes MMO\n * Handles ship hangar and fitting management\n * \n * Architecture:\n * - GameInstanceSubsystem: Persists across level transitions\n * - Requires valid JWT token from UEchoesAuthSubsystem\n * - Communicates with ASP.NET Core backend\n * - Provides inventory data to UI and Movement Component\n * \n * Naming Conventions:\n * - Inventory_ prefix: Inventory management functions\n * - Common_ prefix: Shared data structures\n * - ServerRPC_ prefix: Server-side operations\n */" },
#endif
		{ "IncludePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UEchoesInventorySubsystem\n\nInventory management subsystem for Echoes MMO\nHandles ship hangar and fitting management\n\nArchitecture:\n- GameInstanceSubsystem: Persists across level transitions\n- Requires valid JWT token from UEchoesAuthSubsystem\n- Communicates with ASP.NET Core backend\n- Provides inventory data to UI and Movement Component\n\nNaming Conventions:\n- Inventory_ prefix: Inventory management functions\n- Common_ prefix: Shared data structures\n- ServerRPC_ prefix: Server-side operations" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CachedShips_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cached ships list */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached ships list" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CachedFitting_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cached ship fitting (last fetched) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached ship fitting (last fetched)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CachedHangarIds_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cached personal hangar IDs by station ID */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached personal hangar IDs by station ID" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemDefinitionsTable_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Item Definitions" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Data table containing item definitions\n\x09 * Maps TypeId to visual assets and metadata\n\x09 * Set this in Project Settings or Game Instance\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Data table containing item definitions\nMaps TypeId to visual assets and metadata\nSet this in Project Settings or Game Instance" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemTypeRegistry_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Typed item registry for type-safe access\n\x09 * Key: ItemTypeId (TypeId as integer), Value: Definition row\n\x09 * Provides strongly-typed access pattern for item definitions\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Networking/EchoesInventorySubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Typed item registry for type-safe access\nKey: ItemTypeId (TypeId as integer), Value: Definition row\nProvides strongly-typed access pattern for item definitions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_CachedShips_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_CachedShips;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CachedFitting;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CachedHangarIds_ValueProp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CachedHangarIds_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_CachedHangarIds;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemDefinitionsTable;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ItemTypeRegistry_ValueProp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ItemTypeRegistry_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ItemTypeRegistry;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemIcon, "AsyncLoadItemIcon" }, // 3625409161
		{ &Z_Construct_UFunction_UEchoesInventorySubsystem_AsyncLoadItemWorldMesh, "AsyncLoadItemWorldMesh" }, // 3306346290
		{ &Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionData, "GetItemDefinitionData" }, // 2453761004
		{ &Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemDefinitionDataByTypeId, "GetItemDefinitionDataByTypeId" }, // 2617795425
		{ &Z_Construct_UFunction_UEchoesInventorySubsystem_GetItemFromRegistryData, "GetItemFromRegistryData" }, // 1634449037
		{ &Z_Construct_UFunction_UEchoesInventorySubsystem_GetPersonalHangarId, "GetPersonalHangarId" }, // 2254671601
		{ &Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemDefinition, "HasItemDefinition" }, // 2850417126
		{ &Z_Construct_UFunction_UEchoesInventorySubsystem_HasItemInRegistry, "HasItemInRegistry" }, // 1983660015
		{ &Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_ClearCache, "Inventory_ClearCache" }, // 529228144
		{ &Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShipFitting, "Inventory_FetchShipFitting" }, // 2873828685
		{ &Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_FetchShips, "Inventory_FetchShips" }, // 2505205704
		{ &Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetActiveShip, "Inventory_GetActiveShip" }, // 3294980606
		{ &Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedFitting, "Inventory_GetCachedFitting" }, // 576491551
		{ &Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_GetCachedShips, "Inventory_GetCachedShips" }, // 1205811476
		{ &Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_RequestPersonalHangar, "Inventory_RequestPersonalHangar" }, // 3170819074
		{ &Z_Construct_UFunction_UEchoesInventorySubsystem_Inventory_SetActiveShip, "Inventory_SetActiveShip" }, // 3980991257
		{ &Z_Construct_UFunction_UEchoesInventorySubsystem_UI_FitModule, "UI_FitModule" }, // 3371009046
		{ &Z_Construct_UFunction_UEchoesInventorySubsystem_UI_UnfitModule, "UI_UnfitModule" }, // 175438068
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesInventorySubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesInventorySubsystem_Statics::NewProp_CachedShips_Inner = { "CachedShips", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FEchoesShipInstance, METADATA_PARAMS(0, nullptr) }; // 219373969
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UEchoesInventorySubsystem_Statics::NewProp_CachedShips = { "CachedShips", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesInventorySubsystem, CachedShips), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CachedShips_MetaData), NewProp_CachedShips_MetaData) }; // 219373969
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesInventorySubsystem_Statics::NewProp_CachedFitting = { "CachedFitting", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesInventorySubsystem, CachedFitting), Z_Construct_UScriptStruct_FEchoesShipFitting, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CachedFitting_MetaData), NewProp_CachedFitting_MetaData) }; // 2094547099
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesInventorySubsystem_Statics::NewProp_CachedHangarIds_ValueProp = { "CachedHangarIds", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UEchoesInventorySubsystem_Statics::NewProp_CachedHangarIds_Key_KeyProp = { "CachedHangarIds_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UEchoesInventorySubsystem_Statics::NewProp_CachedHangarIds = { "CachedHangarIds", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesInventorySubsystem, CachedHangarIds), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CachedHangarIds_MetaData), NewProp_CachedHangarIds_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesInventorySubsystem_Statics::NewProp_ItemDefinitionsTable = { "ItemDefinitionsTable", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesInventorySubsystem, ItemDefinitionsTable), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemDefinitionsTable_MetaData), NewProp_ItemDefinitionsTable_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesInventorySubsystem_Statics::NewProp_ItemTypeRegistry_ValueProp = { "ItemTypeRegistry", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FEchoesItemDefinitionRow, METADATA_PARAMS(0, nullptr) }; // 987535441
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UEchoesInventorySubsystem_Statics::NewProp_ItemTypeRegistry_Key_KeyProp = { "ItemTypeRegistry_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UEchoesInventorySubsystem_Statics::NewProp_ItemTypeRegistry = { "ItemTypeRegistry", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesInventorySubsystem, ItemTypeRegistry), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemTypeRegistry_MetaData), NewProp_ItemTypeRegistry_MetaData) }; // 987535441
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesInventorySubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventorySubsystem_Statics::NewProp_CachedShips_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventorySubsystem_Statics::NewProp_CachedShips,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventorySubsystem_Statics::NewProp_CachedFitting,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventorySubsystem_Statics::NewProp_CachedHangarIds_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventorySubsystem_Statics::NewProp_CachedHangarIds_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventorySubsystem_Statics::NewProp_CachedHangarIds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventorySubsystem_Statics::NewProp_ItemDefinitionsTable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventorySubsystem_Statics::NewProp_ItemTypeRegistry_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventorySubsystem_Statics::NewProp_ItemTypeRegistry_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventorySubsystem_Statics::NewProp_ItemTypeRegistry,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesInventorySubsystem_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesInventorySubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesInventorySubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesInventorySubsystem_Statics::ClassParams = {
	&UEchoesInventorySubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UEchoesInventorySubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesInventorySubsystem_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesInventorySubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesInventorySubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesInventorySubsystem()
{
	if (!Z_Registration_Info_UClass_UEchoesInventorySubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesInventorySubsystem.OuterSingleton, Z_Construct_UClass_UEchoesInventorySubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesInventorySubsystem.OuterSingleton;
}
UEchoesInventorySubsystem::UEchoesInventorySubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesInventorySubsystem);
UEchoesInventorySubsystem::~UEchoesInventorySubsystem() {}
// ********** End Class UEchoesInventorySubsystem **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesInventorySubsystem_h__Script_Echoes_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FEchoesShipInstance::StaticStruct, Z_Construct_UScriptStruct_FEchoesShipInstance_Statics::NewStructOps, TEXT("EchoesShipInstance"), &Z_Registration_Info_UScriptStruct_FEchoesShipInstance, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FEchoesShipInstance), 219373969U) },
		{ FEchoesShipList::StaticStruct, Z_Construct_UScriptStruct_FEchoesShipList_Statics::NewStructOps, TEXT("EchoesShipList"), &Z_Registration_Info_UScriptStruct_FEchoesShipList, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FEchoesShipList), 2870318589U) },
		{ FEchoesModule::StaticStruct, Z_Construct_UScriptStruct_FEchoesModule_Statics::NewStructOps, TEXT("EchoesModule"), &Z_Registration_Info_UScriptStruct_FEchoesModule, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FEchoesModule), 474672524U) },
		{ FEchoesShipFitting::StaticStruct, Z_Construct_UScriptStruct_FEchoesShipFitting_Statics::NewStructOps, TEXT("EchoesShipFitting"), &Z_Registration_Info_UScriptStruct_FEchoesShipFitting, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FEchoesShipFitting), 2094547099U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesInventorySubsystem, UEchoesInventorySubsystem::StaticClass, TEXT("UEchoesInventorySubsystem"), &Z_Registration_Info_UClass_UEchoesInventorySubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesInventorySubsystem), 3672484356U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesInventorySubsystem_h__Script_Echoes_2939552473(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesInventorySubsystem_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesInventorySubsystem_h__Script_Echoes_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesInventorySubsystem_h__Script_Echoes_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Networking_EchoesInventorySubsystem_h__Script_Echoes_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
