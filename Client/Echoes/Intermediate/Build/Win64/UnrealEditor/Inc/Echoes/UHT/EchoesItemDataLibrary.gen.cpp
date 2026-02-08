// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesItemDataLibrary.h"
#include "EchoesItemDefinitions.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesItemDataLibrary() {}

// ********** Begin Cross Module References ********************************************************
ECHOES_API UClass* Z_Construct_UClass_UEchoesItemDataLibrary();
ECHOES_API UClass* Z_Construct_UClass_UEchoesItemDataLibrary_NoRegister();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_EEchoesSlotType();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FCompleteModuleData();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FEchoesItemDefinitionRow();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FWeaponAttributesRow();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
ENGINE_API UClass* Z_Construct_UClass_UDataTable_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FCompleteModuleData ***********************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FCompleteModuleData;
class UScriptStruct* FCompleteModuleData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FCompleteModuleData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FCompleteModuleData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCompleteModuleData, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("CompleteModuleData"));
	}
	return Z_Registration_Info_UScriptStruct_FCompleteModuleData.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FCompleteModuleData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * FCompleteModuleData\n * \n * Combined data structure containing both base item definition\n * and weapon/module-specific attributes\n * \n * Used by Common_GetCompleteModuleData to return all relevant\n * data for a module in a single call\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Libraries/EchoesItemDataLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "FCompleteModuleData\n\nCombined data structure containing both base item definition\nand weapon/module-specific attributes\n\nUsed by Common_GetCompleteModuleData to return all relevant\ndata for a module in a single call" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemDefinition_MetaData[] = {
		{ "Category", "Module Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Base item definition (name, icon, volume, etc.) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Libraries/EchoesItemDataLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Base item definition (name, icon, volume, etc.)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WeaponAttributes_MetaData[] = {
		{ "Category", "Module Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Weapon/module specific attributes (damage, range, etc.) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Libraries/EchoesItemDataLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Weapon/module specific attributes (damage, range, etc.)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bItemFound_MetaData[] = {
		{ "Category", "Module Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether the item was found in the definitions table */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Libraries/EchoesItemDataLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether the item was found in the definitions table" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bWeaponAttributesFound_MetaData[] = {
		{ "Category", "Module Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether weapon attributes were found (only for modules) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Libraries/EchoesItemDataLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether weapon attributes were found (only for modules)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsCompleteModule_MetaData[] = {
		{ "Category", "Module Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether this is a valid module with both definitions */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Libraries/EchoesItemDataLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether this is a valid module with both definitions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ItemDefinition;
	static const UECodeGen_Private::FStructPropertyParams NewProp_WeaponAttributes;
	static void NewProp_bItemFound_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bItemFound;
	static void NewProp_bWeaponAttributesFound_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bWeaponAttributesFound;
	static void NewProp_bIsCompleteModule_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsCompleteModule;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCompleteModuleData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCompleteModuleData_Statics::NewProp_ItemDefinition = { "ItemDefinition", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCompleteModuleData, ItemDefinition), Z_Construct_UScriptStruct_FEchoesItemDefinitionRow, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemDefinition_MetaData), NewProp_ItemDefinition_MetaData) }; // 132594848
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCompleteModuleData_Statics::NewProp_WeaponAttributes = { "WeaponAttributes", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCompleteModuleData, WeaponAttributes), Z_Construct_UScriptStruct_FWeaponAttributesRow, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WeaponAttributes_MetaData), NewProp_WeaponAttributes_MetaData) }; // 27770086
void Z_Construct_UScriptStruct_FCompleteModuleData_Statics::NewProp_bItemFound_SetBit(void* Obj)
{
	((FCompleteModuleData*)Obj)->bItemFound = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FCompleteModuleData_Statics::NewProp_bItemFound = { "bItemFound", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FCompleteModuleData), &Z_Construct_UScriptStruct_FCompleteModuleData_Statics::NewProp_bItemFound_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bItemFound_MetaData), NewProp_bItemFound_MetaData) };
void Z_Construct_UScriptStruct_FCompleteModuleData_Statics::NewProp_bWeaponAttributesFound_SetBit(void* Obj)
{
	((FCompleteModuleData*)Obj)->bWeaponAttributesFound = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FCompleteModuleData_Statics::NewProp_bWeaponAttributesFound = { "bWeaponAttributesFound", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FCompleteModuleData), &Z_Construct_UScriptStruct_FCompleteModuleData_Statics::NewProp_bWeaponAttributesFound_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bWeaponAttributesFound_MetaData), NewProp_bWeaponAttributesFound_MetaData) };
void Z_Construct_UScriptStruct_FCompleteModuleData_Statics::NewProp_bIsCompleteModule_SetBit(void* Obj)
{
	((FCompleteModuleData*)Obj)->bIsCompleteModule = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FCompleteModuleData_Statics::NewProp_bIsCompleteModule = { "bIsCompleteModule", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FCompleteModuleData), &Z_Construct_UScriptStruct_FCompleteModuleData_Statics::NewProp_bIsCompleteModule_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsCompleteModule_MetaData), NewProp_bIsCompleteModule_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCompleteModuleData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCompleteModuleData_Statics::NewProp_ItemDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCompleteModuleData_Statics::NewProp_WeaponAttributes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCompleteModuleData_Statics::NewProp_bItemFound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCompleteModuleData_Statics::NewProp_bWeaponAttributesFound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCompleteModuleData_Statics::NewProp_bIsCompleteModule,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCompleteModuleData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCompleteModuleData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"CompleteModuleData",
	Z_Construct_UScriptStruct_FCompleteModuleData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCompleteModuleData_Statics::PropPointers),
	sizeof(FCompleteModuleData),
	alignof(FCompleteModuleData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCompleteModuleData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCompleteModuleData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCompleteModuleData()
{
	if (!Z_Registration_Info_UScriptStruct_FCompleteModuleData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FCompleteModuleData.InnerSingleton, Z_Construct_UScriptStruct_FCompleteModuleData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FCompleteModuleData.InnerSingleton;
}
// ********** End ScriptStruct FCompleteModuleData *************************************************

// ********** Begin Class UEchoesItemDataLibrary Function ClearCache *******************************
struct Z_Construct_UFunction_UEchoesItemDataLibrary_ClearCache_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Item Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Clear cached data\n\x09 * Call this when data tables are reloaded or changed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Libraries/EchoesItemDataLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Clear cached data\nCall this when data tables are reloaded or changed" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesItemDataLibrary_ClearCache_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesItemDataLibrary, nullptr, "ClearCache", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_ClearCache_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesItemDataLibrary_ClearCache_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesItemDataLibrary_ClearCache()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesItemDataLibrary_ClearCache_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesItemDataLibrary::execClearCache)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	UEchoesItemDataLibrary::ClearCache();
	P_NATIVE_END;
}
// ********** End Class UEchoesItemDataLibrary Function ClearCache *********************************

// ********** Begin Class UEchoesItemDataLibrary Function Common_GetCompleteModuleData *************
struct Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCompleteModuleData_Statics
{
	struct EchoesItemDataLibrary_eventCommon_GetCompleteModuleData_Parms
	{
		int32 TypeId;
		FCompleteModuleData ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Item Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get complete module data (base + weapon attributes)\n\x09 * Combines both data tables into a single result\n\x09 * \n\x09 * First looks up base item data (icon, name, fit slot)\n\x09 * Then looks up weapon attributes if item is a module\n\x09 * \n\x09 * @param TypeId - Database item type ID\n\x09 * @return Complete module data structure with validity flags\n\x09 */" },
#endif
		{ "CompactNodeTitle", "Get Complete Module Data" },
		{ "ModuleRelativePath", "Core/Common/Libraries/EchoesItemDataLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get complete module data (base + weapon attributes)\nCombines both data tables into a single result\n\nFirst looks up base item data (icon, name, fit slot)\nThen looks up weapon attributes if item is a module\n\n@param TypeId - Database item type ID\n@return Complete module data structure with validity flags" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_TypeId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCompleteModuleData_Statics::NewProp_TypeId = { "TypeId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesItemDataLibrary_eventCommon_GetCompleteModuleData_Parms, TypeId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCompleteModuleData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesItemDataLibrary_eventCommon_GetCompleteModuleData_Parms, ReturnValue), Z_Construct_UScriptStruct_FCompleteModuleData, METADATA_PARAMS(0, nullptr) }; // 2636409476
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCompleteModuleData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCompleteModuleData_Statics::NewProp_TypeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCompleteModuleData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCompleteModuleData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCompleteModuleData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesItemDataLibrary, nullptr, "Common_GetCompleteModuleData", Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCompleteModuleData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCompleteModuleData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCompleteModuleData_Statics::EchoesItemDataLibrary_eventCommon_GetCompleteModuleData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCompleteModuleData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCompleteModuleData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCompleteModuleData_Statics::EchoesItemDataLibrary_eventCommon_GetCompleteModuleData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCompleteModuleData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCompleteModuleData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesItemDataLibrary::execCommon_GetCompleteModuleData)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_TypeId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FCompleteModuleData*)Z_Param__Result=UEchoesItemDataLibrary::Common_GetCompleteModuleData(Z_Param_TypeId);
	P_NATIVE_END;
}
// ********** End Class UEchoesItemDataLibrary Function Common_GetCompleteModuleData ***************

// ********** Begin Class UEchoesItemDataLibrary Function Common_GetCPURequired ********************
struct Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCPURequired_Statics
{
	struct EchoesItemDataLibrary_eventCommon_GetCPURequired_Parms
	{
		int32 TypeId;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Item Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get CPU requirement for a module\n\x09 * Returns 0 if not a module or module not found\n\x09 * \n\x09 * @param TypeId - Database item type ID\n\x09 * @return CPU requirement in tf\n\x09 */" },
#endif
		{ "CompactNodeTitle", "Get CPU Required" },
		{ "ModuleRelativePath", "Core/Common/Libraries/EchoesItemDataLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get CPU requirement for a module\nReturns 0 if not a module or module not found\n\n@param TypeId - Database item type ID\n@return CPU requirement in tf" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_TypeId;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCPURequired_Statics::NewProp_TypeId = { "TypeId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesItemDataLibrary_eventCommon_GetCPURequired_Parms, TypeId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCPURequired_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesItemDataLibrary_eventCommon_GetCPURequired_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCPURequired_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCPURequired_Statics::NewProp_TypeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCPURequired_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCPURequired_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCPURequired_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesItemDataLibrary, nullptr, "Common_GetCPURequired", Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCPURequired_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCPURequired_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCPURequired_Statics::EchoesItemDataLibrary_eventCommon_GetCPURequired_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCPURequired_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCPURequired_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCPURequired_Statics::EchoesItemDataLibrary_eventCommon_GetCPURequired_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCPURequired()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCPURequired_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesItemDataLibrary::execCommon_GetCPURequired)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_TypeId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=UEchoesItemDataLibrary::Common_GetCPURequired(Z_Param_TypeId);
	P_NATIVE_END;
}
// ********** End Class UEchoesItemDataLibrary Function Common_GetCPURequired **********************

// ********** Begin Class UEchoesItemDataLibrary Function Common_GetFitSlot ************************
struct Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetFitSlot_Statics
{
	struct EchoesItemDataLibrary_eventCommon_GetFitSlot_Parms
	{
		int32 TypeId;
		EEchoesSlotType ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Item Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the fit slot type for an item\n\x09 * Returns None if item is not fittable\n\x09 * \n\x09 * @param TypeId - Database item type ID\n\x09 * @return Slot type (High, Mid, Low, Rig, Subsystem, or None)\n\x09 */" },
#endif
		{ "CompactNodeTitle", "Get Fit Slot" },
		{ "ModuleRelativePath", "Core/Common/Libraries/EchoesItemDataLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the fit slot type for an item\nReturns None if item is not fittable\n\n@param TypeId - Database item type ID\n@return Slot type (High, Mid, Low, Rig, Subsystem, or None)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_TypeId;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetFitSlot_Statics::NewProp_TypeId = { "TypeId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesItemDataLibrary_eventCommon_GetFitSlot_Parms, TypeId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetFitSlot_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetFitSlot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesItemDataLibrary_eventCommon_GetFitSlot_Parms, ReturnValue), Z_Construct_UEnum_Echoes_EEchoesSlotType, METADATA_PARAMS(0, nullptr) }; // 3231457299
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetFitSlot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetFitSlot_Statics::NewProp_TypeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetFitSlot_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetFitSlot_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetFitSlot_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetFitSlot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesItemDataLibrary, nullptr, "Common_GetFitSlot", Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetFitSlot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetFitSlot_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetFitSlot_Statics::EchoesItemDataLibrary_eventCommon_GetFitSlot_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetFitSlot_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetFitSlot_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetFitSlot_Statics::EchoesItemDataLibrary_eventCommon_GetFitSlot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetFitSlot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetFitSlot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesItemDataLibrary::execCommon_GetFitSlot)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_TypeId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EEchoesSlotType*)Z_Param__Result=UEchoesItemDataLibrary::Common_GetFitSlot(Z_Param_TypeId);
	P_NATIVE_END;
}
// ********** End Class UEchoesItemDataLibrary Function Common_GetFitSlot **************************

// ********** Begin Class UEchoesItemDataLibrary Function Common_GetItemDefinition *****************
struct Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemDefinition_Statics
{
	struct EchoesItemDataLibrary_eventCommon_GetItemDefinition_Parms
	{
		int32 TypeId;
		FEchoesItemDefinitionRow OutItemDefinition;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Item Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get base item definition by TypeId\n\x09 * Returns item name, icon, volume, mass, category, etc.\n\x09 * \n\x09 * @param TypeId - Database item type ID\n\x09 * @param OutItemDefinition - Output structure with item data\n\x09 * @return True if item was found, false otherwise\n\x09 */" },
#endif
		{ "CompactNodeTitle", "Get Item Definition" },
		{ "ModuleRelativePath", "Core/Common/Libraries/EchoesItemDataLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get base item definition by TypeId\nReturns item name, icon, volume, mass, category, etc.\n\n@param TypeId - Database item type ID\n@param OutItemDefinition - Output structure with item data\n@return True if item was found, false otherwise" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_TypeId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutItemDefinition;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemDefinition_Statics::NewProp_TypeId = { "TypeId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesItemDataLibrary_eventCommon_GetItemDefinition_Parms, TypeId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemDefinition_Statics::NewProp_OutItemDefinition = { "OutItemDefinition", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesItemDataLibrary_eventCommon_GetItemDefinition_Parms, OutItemDefinition), Z_Construct_UScriptStruct_FEchoesItemDefinitionRow, METADATA_PARAMS(0, nullptr) }; // 132594848
void Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemDefinition_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesItemDataLibrary_eventCommon_GetItemDefinition_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemDefinition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesItemDataLibrary_eventCommon_GetItemDefinition_Parms), &Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemDefinition_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemDefinition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemDefinition_Statics::NewProp_TypeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemDefinition_Statics::NewProp_OutItemDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemDefinition_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemDefinition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemDefinition_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesItemDataLibrary, nullptr, "Common_GetItemDefinition", Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemDefinition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemDefinition_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemDefinition_Statics::EchoesItemDataLibrary_eventCommon_GetItemDefinition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemDefinition_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemDefinition_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemDefinition_Statics::EchoesItemDataLibrary_eventCommon_GetItemDefinition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemDefinition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemDefinition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesItemDataLibrary::execCommon_GetItemDefinition)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_TypeId);
	P_GET_STRUCT_REF(FEchoesItemDefinitionRow,Z_Param_Out_OutItemDefinition);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UEchoesItemDataLibrary::Common_GetItemDefinition(Z_Param_TypeId,Z_Param_Out_OutItemDefinition);
	P_NATIVE_END;
}
// ********** End Class UEchoesItemDataLibrary Function Common_GetItemDefinition *******************

// ********** Begin Class UEchoesItemDataLibrary Function Common_GetItemIcon ***********************
struct Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemIcon_Statics
{
	struct EchoesItemDataLibrary_eventCommon_GetItemIcon_Parms
	{
		int32 TypeId;
		UTexture2D* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Item Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get item icon texture\n\x09 * Returns nullptr if not found or icon not set\n\x09 * \n\x09 * @param TypeId - Database item type ID\n\x09 * @return Icon texture (soft object ptr resolved)\n\x09 */" },
#endif
		{ "CompactNodeTitle", "Get Item Icon" },
		{ "ModuleRelativePath", "Core/Common/Libraries/EchoesItemDataLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get item icon texture\nReturns nullptr if not found or icon not set\n\n@param TypeId - Database item type ID\n@return Icon texture (soft object ptr resolved)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_TypeId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemIcon_Statics::NewProp_TypeId = { "TypeId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesItemDataLibrary_eventCommon_GetItemIcon_Parms, TypeId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemIcon_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesItemDataLibrary_eventCommon_GetItemIcon_Parms, ReturnValue), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemIcon_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemIcon_Statics::NewProp_TypeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemIcon_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemIcon_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemIcon_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesItemDataLibrary, nullptr, "Common_GetItemIcon", Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemIcon_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemIcon_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemIcon_Statics::EchoesItemDataLibrary_eventCommon_GetItemIcon_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemIcon_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemIcon_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemIcon_Statics::EchoesItemDataLibrary_eventCommon_GetItemIcon_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemIcon()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemIcon_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesItemDataLibrary::execCommon_GetItemIcon)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_TypeId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UTexture2D**)Z_Param__Result=UEchoesItemDataLibrary::Common_GetItemIcon(Z_Param_TypeId);
	P_NATIVE_END;
}
// ********** End Class UEchoesItemDataLibrary Function Common_GetItemIcon *************************

// ********** Begin Class UEchoesItemDataLibrary Function Common_GetItemName ***********************
struct Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemName_Statics
{
	struct EchoesItemDataLibrary_eventCommon_GetItemName_Parms
	{
		int32 TypeId;
		FText ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Item Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get item display name\n\x09 * Returns \"Unknown Item\" if not found\n\x09 * \n\x09 * @param TypeId - Database item type ID\n\x09 * @return Localized display name\n\x09 */" },
#endif
		{ "CompactNodeTitle", "Get Item Name" },
		{ "ModuleRelativePath", "Core/Common/Libraries/EchoesItemDataLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get item display name\nReturns \"Unknown Item\" if not found\n\n@param TypeId - Database item type ID\n@return Localized display name" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_TypeId;
	static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemName_Statics::NewProp_TypeId = { "TypeId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesItemDataLibrary_eventCommon_GetItemName_Parms, TypeId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesItemDataLibrary_eventCommon_GetItemName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemName_Statics::NewProp_TypeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemName_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesItemDataLibrary, nullptr, "Common_GetItemName", Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemName_Statics::EchoesItemDataLibrary_eventCommon_GetItemName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemName_Statics::EchoesItemDataLibrary_eventCommon_GetItemName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesItemDataLibrary::execCommon_GetItemName)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_TypeId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FText*)Z_Param__Result=UEchoesItemDataLibrary::Common_GetItemName(Z_Param_TypeId);
	P_NATIVE_END;
}
// ********** End Class UEchoesItemDataLibrary Function Common_GetItemName *************************

// ********** Begin Class UEchoesItemDataLibrary Function Common_GetPowergridRequired **************
struct Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetPowergridRequired_Statics
{
	struct EchoesItemDataLibrary_eventCommon_GetPowergridRequired_Parms
	{
		int32 TypeId;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Item Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get powergrid requirement for a module\n\x09 * Returns 0 if not a module or module not found\n\x09 * \n\x09 * @param TypeId - Database item type ID\n\x09 * @return Powergrid requirement in MW\n\x09 */" },
#endif
		{ "CompactNodeTitle", "Get PG Required" },
		{ "ModuleRelativePath", "Core/Common/Libraries/EchoesItemDataLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get powergrid requirement for a module\nReturns 0 if not a module or module not found\n\n@param TypeId - Database item type ID\n@return Powergrid requirement in MW" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_TypeId;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetPowergridRequired_Statics::NewProp_TypeId = { "TypeId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesItemDataLibrary_eventCommon_GetPowergridRequired_Parms, TypeId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetPowergridRequired_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesItemDataLibrary_eventCommon_GetPowergridRequired_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetPowergridRequired_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetPowergridRequired_Statics::NewProp_TypeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetPowergridRequired_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetPowergridRequired_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetPowergridRequired_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesItemDataLibrary, nullptr, "Common_GetPowergridRequired", Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetPowergridRequired_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetPowergridRequired_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetPowergridRequired_Statics::EchoesItemDataLibrary_eventCommon_GetPowergridRequired_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetPowergridRequired_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetPowergridRequired_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetPowergridRequired_Statics::EchoesItemDataLibrary_eventCommon_GetPowergridRequired_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetPowergridRequired()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetPowergridRequired_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesItemDataLibrary::execCommon_GetPowergridRequired)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_TypeId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=UEchoesItemDataLibrary::Common_GetPowergridRequired(Z_Param_TypeId);
	P_NATIVE_END;
}
// ********** End Class UEchoesItemDataLibrary Function Common_GetPowergridRequired ****************

// ********** Begin Class UEchoesItemDataLibrary Function Common_GetWeaponAttributes ***************
struct Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetWeaponAttributes_Statics
{
	struct EchoesItemDataLibrary_eventCommon_GetWeaponAttributes_Parms
	{
		int32 TypeId;
		FWeaponAttributesRow OutWeaponAttributes;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Item Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get weapon/module attributes by TypeId\n\x09 * Returns damage, range, tracking, capacitor cost, etc.\n\x09 * Only populated for modules/weapons\n\x09 * \n\x09 * @param TypeId - Database item type ID\n\x09 * @param OutWeaponAttributes - Output structure with weapon stats\n\x09 * @return True if weapon attributes were found, false otherwise\n\x09 */" },
#endif
		{ "CompactNodeTitle", "Get Weapon Attributes" },
		{ "ModuleRelativePath", "Core/Common/Libraries/EchoesItemDataLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get weapon/module attributes by TypeId\nReturns damage, range, tracking, capacitor cost, etc.\nOnly populated for modules/weapons\n\n@param TypeId - Database item type ID\n@param OutWeaponAttributes - Output structure with weapon stats\n@return True if weapon attributes were found, false otherwise" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_TypeId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutWeaponAttributes;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetWeaponAttributes_Statics::NewProp_TypeId = { "TypeId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesItemDataLibrary_eventCommon_GetWeaponAttributes_Parms, TypeId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetWeaponAttributes_Statics::NewProp_OutWeaponAttributes = { "OutWeaponAttributes", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesItemDataLibrary_eventCommon_GetWeaponAttributes_Parms, OutWeaponAttributes), Z_Construct_UScriptStruct_FWeaponAttributesRow, METADATA_PARAMS(0, nullptr) }; // 27770086
void Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetWeaponAttributes_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesItemDataLibrary_eventCommon_GetWeaponAttributes_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetWeaponAttributes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesItemDataLibrary_eventCommon_GetWeaponAttributes_Parms), &Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetWeaponAttributes_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetWeaponAttributes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetWeaponAttributes_Statics::NewProp_TypeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetWeaponAttributes_Statics::NewProp_OutWeaponAttributes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetWeaponAttributes_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetWeaponAttributes_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetWeaponAttributes_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesItemDataLibrary, nullptr, "Common_GetWeaponAttributes", Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetWeaponAttributes_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetWeaponAttributes_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetWeaponAttributes_Statics::EchoesItemDataLibrary_eventCommon_GetWeaponAttributes_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetWeaponAttributes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetWeaponAttributes_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetWeaponAttributes_Statics::EchoesItemDataLibrary_eventCommon_GetWeaponAttributes_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetWeaponAttributes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetWeaponAttributes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesItemDataLibrary::execCommon_GetWeaponAttributes)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_TypeId);
	P_GET_STRUCT_REF(FWeaponAttributesRow,Z_Param_Out_OutWeaponAttributes);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UEchoesItemDataLibrary::Common_GetWeaponAttributes(Z_Param_TypeId,Z_Param_Out_OutWeaponAttributes);
	P_NATIVE_END;
}
// ********** End Class UEchoesItemDataLibrary Function Common_GetWeaponAttributes *****************

// ********** Begin Class UEchoesItemDataLibrary Function Common_IsFittableModule ******************
struct Z_Construct_UFunction_UEchoesItemDataLibrary_Common_IsFittableModule_Statics
{
	struct EchoesItemDataLibrary_eventCommon_IsFittableModule_Parms
	{
		int32 TypeId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Item Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if an item is a fittable module\n\x09 * Returns true if item has a FitSlot other than None\n\x09 * \n\x09 * @param TypeId - Database item type ID\n\x09 * @return True if item can be fitted to a ship\n\x09 */" },
#endif
		{ "CompactNodeTitle", "Is Fittable Module" },
		{ "ModuleRelativePath", "Core/Common/Libraries/EchoesItemDataLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if an item is a fittable module\nReturns true if item has a FitSlot other than None\n\n@param TypeId - Database item type ID\n@return True if item can be fitted to a ship" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_TypeId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_IsFittableModule_Statics::NewProp_TypeId = { "TypeId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesItemDataLibrary_eventCommon_IsFittableModule_Parms, TypeId), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UEchoesItemDataLibrary_Common_IsFittableModule_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesItemDataLibrary_eventCommon_IsFittableModule_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_IsFittableModule_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesItemDataLibrary_eventCommon_IsFittableModule_Parms), &Z_Construct_UFunction_UEchoesItemDataLibrary_Common_IsFittableModule_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesItemDataLibrary_Common_IsFittableModule_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesItemDataLibrary_Common_IsFittableModule_Statics::NewProp_TypeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesItemDataLibrary_Common_IsFittableModule_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_IsFittableModule_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_IsFittableModule_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesItemDataLibrary, nullptr, "Common_IsFittableModule", Z_Construct_UFunction_UEchoesItemDataLibrary_Common_IsFittableModule_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_IsFittableModule_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_IsFittableModule_Statics::EchoesItemDataLibrary_eventCommon_IsFittableModule_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_IsFittableModule_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesItemDataLibrary_Common_IsFittableModule_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_IsFittableModule_Statics::EchoesItemDataLibrary_eventCommon_IsFittableModule_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesItemDataLibrary_Common_IsFittableModule()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesItemDataLibrary_Common_IsFittableModule_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesItemDataLibrary::execCommon_IsFittableModule)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_TypeId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UEchoesItemDataLibrary::Common_IsFittableModule(Z_Param_TypeId);
	P_NATIVE_END;
}
// ********** End Class UEchoesItemDataLibrary Function Common_IsFittableModule ********************

// ********** Begin Class UEchoesItemDataLibrary Function Common_ItemExists ************************
struct Z_Construct_UFunction_UEchoesItemDataLibrary_Common_ItemExists_Statics
{
	struct EchoesItemDataLibrary_eventCommon_ItemExists_Parms
	{
		int32 TypeId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Item Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if item exists in database\n\x09 * \n\x09 * @param TypeId - Database item type ID\n\x09 * @return True if item definition exists\n\x09 */" },
#endif
		{ "CompactNodeTitle", "Item Exists" },
		{ "ModuleRelativePath", "Core/Common/Libraries/EchoesItemDataLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if item exists in database\n\n@param TypeId - Database item type ID\n@return True if item definition exists" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_TypeId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_ItemExists_Statics::NewProp_TypeId = { "TypeId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesItemDataLibrary_eventCommon_ItemExists_Parms, TypeId), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UEchoesItemDataLibrary_Common_ItemExists_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesItemDataLibrary_eventCommon_ItemExists_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_ItemExists_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesItemDataLibrary_eventCommon_ItemExists_Parms), &Z_Construct_UFunction_UEchoesItemDataLibrary_Common_ItemExists_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesItemDataLibrary_Common_ItemExists_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesItemDataLibrary_Common_ItemExists_Statics::NewProp_TypeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesItemDataLibrary_Common_ItemExists_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_ItemExists_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesItemDataLibrary_Common_ItemExists_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesItemDataLibrary, nullptr, "Common_ItemExists", Z_Construct_UFunction_UEchoesItemDataLibrary_Common_ItemExists_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_ItemExists_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_ItemExists_Statics::EchoesItemDataLibrary_eventCommon_ItemExists_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_ItemExists_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesItemDataLibrary_Common_ItemExists_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesItemDataLibrary_Common_ItemExists_Statics::EchoesItemDataLibrary_eventCommon_ItemExists_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesItemDataLibrary_Common_ItemExists()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesItemDataLibrary_Common_ItemExists_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesItemDataLibrary::execCommon_ItemExists)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_TypeId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UEchoesItemDataLibrary::Common_ItemExists(Z_Param_TypeId);
	P_NATIVE_END;
}
// ********** End Class UEchoesItemDataLibrary Function Common_ItemExists **************************

// ********** Begin Class UEchoesItemDataLibrary Function SetDataTableReferences *******************
struct Z_Construct_UFunction_UEchoesItemDataLibrary_SetDataTableReferences_Statics
{
	struct EchoesItemDataLibrary_eventSetDataTableReferences_Parms
	{
		UDataTable* ItemDefinitionsTable;
		UDataTable* WeaponAttributesTable;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Item Data" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Initialize data table references for the library\n\x09 * Must be called before using any other functions\n\x09 * \n\x09 * @param ItemDefinitionsTable - Data table containing FEchoesItemDefinitionRow entries\n\x09 * @param WeaponAttributesTable - Data table containing FWeaponAttributesRow entries\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Libraries/EchoesItemDataLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initialize data table references for the library\nMust be called before using any other functions\n\n@param ItemDefinitionsTable - Data table containing FEchoesItemDefinitionRow entries\n@param WeaponAttributesTable - Data table containing FWeaponAttributesRow entries" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemDefinitionsTable;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WeaponAttributesTable;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEchoesItemDataLibrary_SetDataTableReferences_Statics::NewProp_ItemDefinitionsTable = { "ItemDefinitionsTable", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesItemDataLibrary_eventSetDataTableReferences_Parms, ItemDefinitionsTable), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEchoesItemDataLibrary_SetDataTableReferences_Statics::NewProp_WeaponAttributesTable = { "WeaponAttributesTable", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesItemDataLibrary_eventSetDataTableReferences_Parms, WeaponAttributesTable), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesItemDataLibrary_SetDataTableReferences_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesItemDataLibrary_SetDataTableReferences_Statics::NewProp_ItemDefinitionsTable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesItemDataLibrary_SetDataTableReferences_Statics::NewProp_WeaponAttributesTable,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_SetDataTableReferences_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesItemDataLibrary_SetDataTableReferences_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesItemDataLibrary, nullptr, "SetDataTableReferences", Z_Construct_UFunction_UEchoesItemDataLibrary_SetDataTableReferences_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_SetDataTableReferences_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesItemDataLibrary_SetDataTableReferences_Statics::EchoesItemDataLibrary_eventSetDataTableReferences_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesItemDataLibrary_SetDataTableReferences_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesItemDataLibrary_SetDataTableReferences_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesItemDataLibrary_SetDataTableReferences_Statics::EchoesItemDataLibrary_eventSetDataTableReferences_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesItemDataLibrary_SetDataTableReferences()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesItemDataLibrary_SetDataTableReferences_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesItemDataLibrary::execSetDataTableReferences)
{
	P_GET_OBJECT(UDataTable,Z_Param_ItemDefinitionsTable);
	P_GET_OBJECT(UDataTable,Z_Param_WeaponAttributesTable);
	P_FINISH;
	P_NATIVE_BEGIN;
	UEchoesItemDataLibrary::SetDataTableReferences(Z_Param_ItemDefinitionsTable,Z_Param_WeaponAttributesTable);
	P_NATIVE_END;
}
// ********** End Class UEchoesItemDataLibrary Function SetDataTableReferences *********************

// ********** Begin Class UEchoesItemDataLibrary ***************************************************
void UEchoesItemDataLibrary::StaticRegisterNativesUEchoesItemDataLibrary()
{
	UClass* Class = UEchoesItemDataLibrary::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ClearCache", &UEchoesItemDataLibrary::execClearCache },
		{ "Common_GetCompleteModuleData", &UEchoesItemDataLibrary::execCommon_GetCompleteModuleData },
		{ "Common_GetCPURequired", &UEchoesItemDataLibrary::execCommon_GetCPURequired },
		{ "Common_GetFitSlot", &UEchoesItemDataLibrary::execCommon_GetFitSlot },
		{ "Common_GetItemDefinition", &UEchoesItemDataLibrary::execCommon_GetItemDefinition },
		{ "Common_GetItemIcon", &UEchoesItemDataLibrary::execCommon_GetItemIcon },
		{ "Common_GetItemName", &UEchoesItemDataLibrary::execCommon_GetItemName },
		{ "Common_GetPowergridRequired", &UEchoesItemDataLibrary::execCommon_GetPowergridRequired },
		{ "Common_GetWeaponAttributes", &UEchoesItemDataLibrary::execCommon_GetWeaponAttributes },
		{ "Common_IsFittableModule", &UEchoesItemDataLibrary::execCommon_IsFittableModule },
		{ "Common_ItemExists", &UEchoesItemDataLibrary::execCommon_ItemExists },
		{ "SetDataTableReferences", &UEchoesItemDataLibrary::execSetDataTableReferences },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesItemDataLibrary;
UClass* UEchoesItemDataLibrary::GetPrivateStaticClass()
{
	using TClass = UEchoesItemDataLibrary;
	if (!Z_Registration_Info_UClass_UEchoesItemDataLibrary.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesItemDataLibrary"),
			Z_Registration_Info_UClass_UEchoesItemDataLibrary.InnerSingleton,
			StaticRegisterNativesUEchoesItemDataLibrary,
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
	return Z_Registration_Info_UClass_UEchoesItemDataLibrary.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesItemDataLibrary_NoRegister()
{
	return UEchoesItemDataLibrary::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesItemDataLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UEchoesItemDataLibrary\n * \n * Blueprint Function Library for accessing item and module data\n * Provides Common_ helper functions to query data tables and combine information\n * \n * Naming Convention: All functions use Common_ prefix to indicate\n * they are pure calculation/data access functions\n * \n * Usage:\n * 1. Configure data table references in Project Settings or Game Instance\n * 2. Call SetDataTableReferences() to initialize the library\n * 3. Use Common_GetItemDefinition() for base item data\n * 4. Use Common_GetWeaponAttributes() for weapon stats\n * 5. Use Common_GetCompleteModuleData() for combined data\n */" },
#endif
		{ "IncludePath", "Core/Common/Libraries/EchoesItemDataLibrary.h" },
		{ "ModuleRelativePath", "Core/Common/Libraries/EchoesItemDataLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UEchoesItemDataLibrary\n\nBlueprint Function Library for accessing item and module data\nProvides Common_ helper functions to query data tables and combine information\n\nNaming Convention: All functions use Common_ prefix to indicate\nthey are pure calculation/data access functions\n\nUsage:\n1. Configure data table references in Project Settings or Game Instance\n2. Call SetDataTableReferences() to initialize the library\n3. Use Common_GetItemDefinition() for base item data\n4. Use Common_GetWeaponAttributes() for weapon stats\n5. Use Common_GetCompleteModuleData() for combined data" },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesItemDataLibrary_ClearCache, "ClearCache" }, // 2103310200
		{ &Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCompleteModuleData, "Common_GetCompleteModuleData" }, // 2552009727
		{ &Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetCPURequired, "Common_GetCPURequired" }, // 35395979
		{ &Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetFitSlot, "Common_GetFitSlot" }, // 3239595284
		{ &Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemDefinition, "Common_GetItemDefinition" }, // 984425091
		{ &Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemIcon, "Common_GetItemIcon" }, // 342610907
		{ &Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetItemName, "Common_GetItemName" }, // 4286933760
		{ &Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetPowergridRequired, "Common_GetPowergridRequired" }, // 1350106916
		{ &Z_Construct_UFunction_UEchoesItemDataLibrary_Common_GetWeaponAttributes, "Common_GetWeaponAttributes" }, // 2833884108
		{ &Z_Construct_UFunction_UEchoesItemDataLibrary_Common_IsFittableModule, "Common_IsFittableModule" }, // 1180096064
		{ &Z_Construct_UFunction_UEchoesItemDataLibrary_Common_ItemExists, "Common_ItemExists" }, // 1319546058
		{ &Z_Construct_UFunction_UEchoesItemDataLibrary_SetDataTableReferences, "SetDataTableReferences" }, // 2648344965
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesItemDataLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UEchoesItemDataLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesItemDataLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesItemDataLibrary_Statics::ClassParams = {
	&UEchoesItemDataLibrary::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesItemDataLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesItemDataLibrary_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesItemDataLibrary()
{
	if (!Z_Registration_Info_UClass_UEchoesItemDataLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesItemDataLibrary.OuterSingleton, Z_Construct_UClass_UEchoesItemDataLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesItemDataLibrary.OuterSingleton;
}
UEchoesItemDataLibrary::UEchoesItemDataLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesItemDataLibrary);
UEchoesItemDataLibrary::~UEchoesItemDataLibrary() {}
// ********** End Class UEchoesItemDataLibrary *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Libraries_EchoesItemDataLibrary_h__Script_Echoes_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FCompleteModuleData::StaticStruct, Z_Construct_UScriptStruct_FCompleteModuleData_Statics::NewStructOps, TEXT("CompleteModuleData"), &Z_Registration_Info_UScriptStruct_FCompleteModuleData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCompleteModuleData), 2636409476U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesItemDataLibrary, UEchoesItemDataLibrary::StaticClass, TEXT("UEchoesItemDataLibrary"), &Z_Registration_Info_UClass_UEchoesItemDataLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesItemDataLibrary), 3333333588U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Libraries_EchoesItemDataLibrary_h__Script_Echoes_4162387862(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Libraries_EchoesItemDataLibrary_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Libraries_EchoesItemDataLibrary_h__Script_Echoes_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Libraries_EchoesItemDataLibrary_h__Script_Echoes_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Libraries_EchoesItemDataLibrary_h__Script_Echoes_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
