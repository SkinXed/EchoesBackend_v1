// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/EchoesInventoryItemObject.h"
#include "Core/Common/EchoesInventoryComponent.h"
#include "Core/Common/EchoesItemDefinitions.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesInventoryItemObject() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UClass* Z_Construct_UClass_UEchoesInventoryItemObject();
ECHOES_API UClass* Z_Construct_UClass_UEchoesInventoryItemObject_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesInventorySubsystem_NoRegister();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FEchoesInventoryItem();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FEchoesItemDefinitionRow();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UEchoesInventoryItemObject Function GetAssetId ***************************
struct Z_Construct_UFunction_UEchoesInventoryItemObject_GetAssetId_Statics
{
	struct EchoesInventoryItemObject_eventGetAssetId_Parms
	{
		FGuid ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the asset ID\n\x09 * @return Asset GUID\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryItemObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the asset ID\n@return Asset GUID" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesInventoryItemObject_GetAssetId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryItemObject_eventGetAssetId_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryItemObject_GetAssetId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryItemObject_GetAssetId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetAssetId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryItemObject_GetAssetId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryItemObject, nullptr, "GetAssetId", Z_Construct_UFunction_UEchoesInventoryItemObject_GetAssetId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetAssetId_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_GetAssetId_Statics::EchoesInventoryItemObject_eventGetAssetId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetAssetId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryItemObject_GetAssetId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_GetAssetId_Statics::EchoesInventoryItemObject_eventGetAssetId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryItemObject_GetAssetId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryItemObject_GetAssetId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryItemObject::execGetAssetId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGuid*)Z_Param__Result=P_THIS->GetAssetId();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryItemObject Function GetAssetId *****************************

// ********** Begin Class UEchoesInventoryItemObject Function GetCalculatedTotalVolume *************
struct Z_Construct_UFunction_UEchoesInventoryItemObject_GetCalculatedTotalVolume_Statics
{
	struct EchoesInventoryItemObject_eventGetCalculatedTotalVolume_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get calculated total volume (Quantity * UnitVolume from definition)\n\x09 * Uses definition's UnitVolume if available, otherwise uses ItemData.Volume\n\x09 * @return Total volume in m\xc2\xb3\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryItemObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get calculated total volume (Quantity * UnitVolume from definition)\nUses definition's UnitVolume if available, otherwise uses ItemData.Volume\n@return Total volume in m\xc2\xb3" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesInventoryItemObject_GetCalculatedTotalVolume_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryItemObject_eventGetCalculatedTotalVolume_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryItemObject_GetCalculatedTotalVolume_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryItemObject_GetCalculatedTotalVolume_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetCalculatedTotalVolume_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryItemObject_GetCalculatedTotalVolume_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryItemObject, nullptr, "GetCalculatedTotalVolume", Z_Construct_UFunction_UEchoesInventoryItemObject_GetCalculatedTotalVolume_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetCalculatedTotalVolume_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_GetCalculatedTotalVolume_Statics::EchoesInventoryItemObject_eventGetCalculatedTotalVolume_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetCalculatedTotalVolume_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryItemObject_GetCalculatedTotalVolume_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_GetCalculatedTotalVolume_Statics::EchoesInventoryItemObject_eventGetCalculatedTotalVolume_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryItemObject_GetCalculatedTotalVolume()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryItemObject_GetCalculatedTotalVolume_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryItemObject::execGetCalculatedTotalVolume)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetCalculatedTotalVolume();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryItemObject Function GetCalculatedTotalVolume ***************

// ********** Begin Class UEchoesInventoryItemObject Function GetDescription ***********************
struct Z_Construct_UFunction_UEchoesInventoryItemObject_GetDescription_Statics
{
	struct EchoesInventoryItemObject_eventGetDescription_Parms
	{
		FText ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the description from item definition (localized)\n\x09 * @return Description text\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryItemObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the description from item definition (localized)\n@return Description text" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UEchoesInventoryItemObject_GetDescription_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryItemObject_eventGetDescription_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryItemObject_GetDescription_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryItemObject_GetDescription_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetDescription_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryItemObject_GetDescription_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryItemObject, nullptr, "GetDescription", Z_Construct_UFunction_UEchoesInventoryItemObject_GetDescription_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetDescription_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_GetDescription_Statics::EchoesInventoryItemObject_eventGetDescription_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetDescription_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryItemObject_GetDescription_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_GetDescription_Statics::EchoesInventoryItemObject_eventGetDescription_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryItemObject_GetDescription()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryItemObject_GetDescription_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryItemObject::execGetDescription)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FText*)Z_Param__Result=P_THIS->GetDescription();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryItemObject Function GetDescription *************************

// ********** Begin Class UEchoesInventoryItemObject Function GetDisplayName ***********************
struct Z_Construct_UFunction_UEchoesInventoryItemObject_GetDisplayName_Statics
{
	struct EchoesInventoryItemObject_eventGetDisplayName_Parms
	{
		FText ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the display name from item definition (localized)\n\x09 * Falls back to TypeName if definition not found\n\x09 * @return Display name\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryItemObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the display name from item definition (localized)\nFalls back to TypeName if definition not found\n@return Display name" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UEchoesInventoryItemObject_GetDisplayName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryItemObject_eventGetDisplayName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryItemObject_GetDisplayName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryItemObject_GetDisplayName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetDisplayName_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryItemObject_GetDisplayName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryItemObject, nullptr, "GetDisplayName", Z_Construct_UFunction_UEchoesInventoryItemObject_GetDisplayName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetDisplayName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_GetDisplayName_Statics::EchoesInventoryItemObject_eventGetDisplayName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetDisplayName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryItemObject_GetDisplayName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_GetDisplayName_Statics::EchoesInventoryItemObject_eventGetDisplayName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryItemObject_GetDisplayName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryItemObject_GetDisplayName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryItemObject::execGetDisplayName)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FText*)Z_Param__Result=P_THIS->GetDisplayName();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryItemObject Function GetDisplayName *************************

// ********** Begin Class UEchoesInventoryItemObject Function GetFormattedTotalVolume **************
struct Z_Construct_UFunction_UEchoesInventoryItemObject_GetFormattedTotalVolume_Statics
{
	struct EchoesInventoryItemObject_eventGetFormattedTotalVolume_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get formatted total volume string (e.g., \"1,205.0 m\xc2\xb3\")\n\x09 * @return Formatted total volume string\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryItemObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get formatted total volume string (e.g., \"1,205.0 m\xc2\xb3\")\n@return Formatted total volume string" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesInventoryItemObject_GetFormattedTotalVolume_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryItemObject_eventGetFormattedTotalVolume_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryItemObject_GetFormattedTotalVolume_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryItemObject_GetFormattedTotalVolume_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetFormattedTotalVolume_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryItemObject_GetFormattedTotalVolume_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryItemObject, nullptr, "GetFormattedTotalVolume", Z_Construct_UFunction_UEchoesInventoryItemObject_GetFormattedTotalVolume_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetFormattedTotalVolume_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_GetFormattedTotalVolume_Statics::EchoesInventoryItemObject_eventGetFormattedTotalVolume_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetFormattedTotalVolume_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryItemObject_GetFormattedTotalVolume_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_GetFormattedTotalVolume_Statics::EchoesInventoryItemObject_eventGetFormattedTotalVolume_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryItemObject_GetFormattedTotalVolume()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryItemObject_GetFormattedTotalVolume_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryItemObject::execGetFormattedTotalVolume)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetFormattedTotalVolume();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryItemObject Function GetFormattedTotalVolume ****************

// ********** Begin Class UEchoesInventoryItemObject Function GetFormattedVolume *******************
struct Z_Construct_UFunction_UEchoesInventoryItemObject_GetFormattedVolume_Statics
{
	struct EchoesInventoryItemObject_eventGetFormattedVolume_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get formatted volume string (e.g., \"120.5 m\xc2\xb3\")\n\x09 * @return Formatted volume string\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryItemObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get formatted volume string (e.g., \"120.5 m\xc2\xb3\")\n@return Formatted volume string" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesInventoryItemObject_GetFormattedVolume_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryItemObject_eventGetFormattedVolume_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryItemObject_GetFormattedVolume_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryItemObject_GetFormattedVolume_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetFormattedVolume_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryItemObject_GetFormattedVolume_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryItemObject, nullptr, "GetFormattedVolume", Z_Construct_UFunction_UEchoesInventoryItemObject_GetFormattedVolume_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetFormattedVolume_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_GetFormattedVolume_Statics::EchoesInventoryItemObject_eventGetFormattedVolume_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetFormattedVolume_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryItemObject_GetFormattedVolume_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_GetFormattedVolume_Statics::EchoesInventoryItemObject_eventGetFormattedVolume_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryItemObject_GetFormattedVolume()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryItemObject_GetFormattedVolume_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryItemObject::execGetFormattedVolume)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetFormattedVolume();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryItemObject Function GetFormattedVolume *********************

// ********** Begin Class UEchoesInventoryItemObject Function GetItemData **************************
struct Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemData_Statics
{
	struct EchoesInventoryItemObject_eventGetItemData_Parms
	{
		FEchoesInventoryItem ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the wrapped inventory item data\n\x09 * @return The wrapped inventory item\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryItemObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the wrapped inventory item data\n@return The wrapped inventory item" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryItemObject_eventGetItemData_Parms, ReturnValue), Z_Construct_UScriptStruct_FEchoesInventoryItem, METADATA_PARAMS(0, nullptr) }; // 3518727963
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryItemObject, nullptr, "GetItemData", Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemData_Statics::EchoesInventoryItemObject_eventGetItemData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemData_Statics::EchoesInventoryItemObject_eventGetItemData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryItemObject::execGetItemData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FEchoesInventoryItem*)Z_Param__Result=P_THIS->GetItemData();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryItemObject Function GetItemData ****************************

// ********** Begin Class UEchoesInventoryItemObject Function GetItemDefinitionData ****************
struct Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemDefinitionData_Statics
{
	struct EchoesInventoryItemObject_eventGetItemDefinitionData_Parms
	{
		FEchoesItemDefinitionRow ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the item definition data for Blueprints\n\x09 * @return Definition data if cached, otherwise default-constructed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryItemObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the item definition data for Blueprints\n@return Definition data if cached, otherwise default-constructed" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemDefinitionData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryItemObject_eventGetItemDefinitionData_Parms, ReturnValue), Z_Construct_UScriptStruct_FEchoesItemDefinitionRow, METADATA_PARAMS(0, nullptr) }; // 987535441
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemDefinitionData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemDefinitionData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemDefinitionData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemDefinitionData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryItemObject, nullptr, "GetItemDefinitionData", Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemDefinitionData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemDefinitionData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemDefinitionData_Statics::EchoesInventoryItemObject_eventGetItemDefinitionData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemDefinitionData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemDefinitionData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemDefinitionData_Statics::EchoesInventoryItemObject_eventGetItemDefinitionData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemDefinitionData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemDefinitionData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryItemObject::execGetItemDefinitionData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FEchoesItemDefinitionRow*)Z_Param__Result=P_THIS->GetItemDefinitionData();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryItemObject Function GetItemDefinitionData ******************

// ********** Begin Class UEchoesInventoryItemObject Function GetItemName **************************
struct Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemName_Statics
{
	struct EchoesInventoryItemObject_eventGetItemName_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the item type name\n\x09 * @return Item type name\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryItemObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the item type name\n@return Item type name" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryItemObject_eventGetItemName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemName_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryItemObject, nullptr, "GetItemName", Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemName_Statics::EchoesInventoryItemObject_eventGetItemName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemName_Statics::EchoesInventoryItemObject_eventGetItemName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryItemObject::execGetItemName)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetItemName();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryItemObject Function GetItemName ****************************

// ********** Begin Class UEchoesInventoryItemObject Function GetQuantity **************************
struct Z_Construct_UFunction_UEchoesInventoryItemObject_GetQuantity_Statics
{
	struct EchoesInventoryItemObject_eventGetQuantity_Parms
	{
		int64 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the item quantity\n\x09 * @return Item quantity\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryItemObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the item quantity\n@return Item quantity" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UEchoesInventoryItemObject_GetQuantity_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryItemObject_eventGetQuantity_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryItemObject_GetQuantity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryItemObject_GetQuantity_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetQuantity_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryItemObject_GetQuantity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryItemObject, nullptr, "GetQuantity", Z_Construct_UFunction_UEchoesInventoryItemObject_GetQuantity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetQuantity_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_GetQuantity_Statics::EchoesInventoryItemObject_eventGetQuantity_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetQuantity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryItemObject_GetQuantity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_GetQuantity_Statics::EchoesInventoryItemObject_eventGetQuantity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryItemObject_GetQuantity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryItemObject_GetQuantity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryItemObject::execGetQuantity)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int64*)Z_Param__Result=P_THIS->GetQuantity();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryItemObject Function GetQuantity ****************************

// ********** Begin Class UEchoesInventoryItemObject Function GetTotalMass *************************
struct Z_Construct_UFunction_UEchoesInventoryItemObject_GetTotalMass_Statics
{
	struct EchoesInventoryItemObject_eventGetTotalMass_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get total mass (Quantity * UnitMass from definition)\n\x09 * @return Total mass in kg\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryItemObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get total mass (Quantity * UnitMass from definition)\n@return Total mass in kg" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesInventoryItemObject_GetTotalMass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryItemObject_eventGetTotalMass_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryItemObject_GetTotalMass_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryItemObject_GetTotalMass_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetTotalMass_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryItemObject_GetTotalMass_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryItemObject, nullptr, "GetTotalMass", Z_Construct_UFunction_UEchoesInventoryItemObject_GetTotalMass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetTotalMass_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_GetTotalMass_Statics::EchoesInventoryItemObject_eventGetTotalMass_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetTotalMass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryItemObject_GetTotalMass_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_GetTotalMass_Statics::EchoesInventoryItemObject_eventGetTotalMass_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryItemObject_GetTotalMass()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryItemObject_GetTotalMass_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryItemObject::execGetTotalMass)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetTotalMass();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryItemObject Function GetTotalMass ***************************

// ********** Begin Class UEchoesInventoryItemObject Function GetTypeId ****************************
struct Z_Construct_UFunction_UEchoesInventoryItemObject_GetTypeId_Statics
{
	struct EchoesInventoryItemObject_eventGetTypeId_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the type ID\n\x09 * @return Type ID\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryItemObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the type ID\n@return Type ID" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEchoesInventoryItemObject_GetTypeId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryItemObject_eventGetTypeId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryItemObject_GetTypeId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryItemObject_GetTypeId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetTypeId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryItemObject_GetTypeId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryItemObject, nullptr, "GetTypeId", Z_Construct_UFunction_UEchoesInventoryItemObject_GetTypeId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetTypeId_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_GetTypeId_Statics::EchoesInventoryItemObject_eventGetTypeId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetTypeId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryItemObject_GetTypeId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_GetTypeId_Statics::EchoesInventoryItemObject_eventGetTypeId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryItemObject_GetTypeId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryItemObject_GetTypeId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryItemObject::execGetTypeId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetTypeId();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryItemObject Function GetTypeId ******************************

// ********** Begin Class UEchoesInventoryItemObject Function GetUnitVolume ************************
struct Z_Construct_UFunction_UEchoesInventoryItemObject_GetUnitVolume_Statics
{
	struct EchoesInventoryItemObject_eventGetUnitVolume_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get unit volume from item definition\n\x09 * @return Volume per unit in m\xc2\xb3\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryItemObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get unit volume from item definition\n@return Volume per unit in m\xc2\xb3" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesInventoryItemObject_GetUnitVolume_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryItemObject_eventGetUnitVolume_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryItemObject_GetUnitVolume_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryItemObject_GetUnitVolume_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetUnitVolume_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryItemObject_GetUnitVolume_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryItemObject, nullptr, "GetUnitVolume", Z_Construct_UFunction_UEchoesInventoryItemObject_GetUnitVolume_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetUnitVolume_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_GetUnitVolume_Statics::EchoesInventoryItemObject_eventGetUnitVolume_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_GetUnitVolume_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryItemObject_GetUnitVolume_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_GetUnitVolume_Statics::EchoesInventoryItemObject_eventGetUnitVolume_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryItemObject_GetUnitVolume()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryItemObject_GetUnitVolume_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryItemObject::execGetUnitVolume)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetUnitVolume();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryItemObject Function GetUnitVolume **************************

// ********** Begin Class UEchoesInventoryItemObject Function HasDefinition ************************
struct Z_Construct_UFunction_UEchoesInventoryItemObject_HasDefinition_Statics
{
	struct EchoesInventoryItemObject_eventHasDefinition_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if item definition is loaded\n\x09 * @return True if definition was found and cached\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryItemObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if item definition is loaded\n@return True if definition was found and cached" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UEchoesInventoryItemObject_HasDefinition_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesInventoryItemObject_eventHasDefinition_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEchoesInventoryItemObject_HasDefinition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesInventoryItemObject_eventHasDefinition_Parms), &Z_Construct_UFunction_UEchoesInventoryItemObject_HasDefinition_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryItemObject_HasDefinition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryItemObject_HasDefinition_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_HasDefinition_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryItemObject_HasDefinition_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryItemObject, nullptr, "HasDefinition", Z_Construct_UFunction_UEchoesInventoryItemObject_HasDefinition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_HasDefinition_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_HasDefinition_Statics::EchoesInventoryItemObject_eventHasDefinition_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_HasDefinition_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryItemObject_HasDefinition_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_HasDefinition_Statics::EchoesInventoryItemObject_eventHasDefinition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryItemObject_HasDefinition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryItemObject_HasDefinition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryItemObject::execHasDefinition)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->HasDefinition();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryItemObject Function HasDefinition **************************

// ********** Begin Class UEchoesInventoryItemObject Function InitializeWithData *******************
struct Z_Construct_UFunction_UEchoesInventoryItemObject_InitializeWithData_Statics
{
	struct EchoesInventoryItemObject_eventInitializeWithData_Parms
	{
		FEchoesInventoryItem InItemData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Initialize the object with inventory item data\n\x09 * @param InItemData - The inventory item data to wrap\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryItemObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initialize the object with inventory item data\n@param InItemData - The inventory item data to wrap" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InItemData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_InItemData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesInventoryItemObject_InitializeWithData_Statics::NewProp_InItemData = { "InItemData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryItemObject_eventInitializeWithData_Parms, InItemData), Z_Construct_UScriptStruct_FEchoesInventoryItem, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InItemData_MetaData), NewProp_InItemData_MetaData) }; // 3518727963
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryItemObject_InitializeWithData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryItemObject_InitializeWithData_Statics::NewProp_InItemData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_InitializeWithData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryItemObject_InitializeWithData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryItemObject, nullptr, "InitializeWithData", Z_Construct_UFunction_UEchoesInventoryItemObject_InitializeWithData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_InitializeWithData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_InitializeWithData_Statics::EchoesInventoryItemObject_eventInitializeWithData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_InitializeWithData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryItemObject_InitializeWithData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_InitializeWithData_Statics::EchoesInventoryItemObject_eventInitializeWithData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryItemObject_InitializeWithData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryItemObject_InitializeWithData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryItemObject::execInitializeWithData)
{
	P_GET_STRUCT_REF(FEchoesInventoryItem,Z_Param_Out_InItemData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeWithData(Z_Param_Out_InItemData);
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryItemObject Function InitializeWithData *********************

// ********** Begin Class UEchoesInventoryItemObject Function IsStackable **************************
struct Z_Construct_UFunction_UEchoesInventoryItemObject_IsStackable_Statics
{
	struct EchoesInventoryItemObject_eventIsStackable_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if item is stackable\n\x09 * @return True if stackable\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryItemObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if item is stackable\n@return True if stackable" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UEchoesInventoryItemObject_IsStackable_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesInventoryItemObject_eventIsStackable_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEchoesInventoryItemObject_IsStackable_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesInventoryItemObject_eventIsStackable_Parms), &Z_Construct_UFunction_UEchoesInventoryItemObject_IsStackable_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryItemObject_IsStackable_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryItemObject_IsStackable_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_IsStackable_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryItemObject_IsStackable_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryItemObject, nullptr, "IsStackable", Z_Construct_UFunction_UEchoesInventoryItemObject_IsStackable_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_IsStackable_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_IsStackable_Statics::EchoesInventoryItemObject_eventIsStackable_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryItemObject_IsStackable_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryItemObject_IsStackable_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryItemObject_IsStackable_Statics::EchoesInventoryItemObject_eventIsStackable_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryItemObject_IsStackable()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryItemObject_IsStackable_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryItemObject::execIsStackable)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsStackable();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryItemObject Function IsStackable ****************************

// ********** Begin Class UEchoesInventoryItemObject ***********************************************
void UEchoesInventoryItemObject::StaticRegisterNativesUEchoesInventoryItemObject()
{
	UClass* Class = UEchoesInventoryItemObject::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetAssetId", &UEchoesInventoryItemObject::execGetAssetId },
		{ "GetCalculatedTotalVolume", &UEchoesInventoryItemObject::execGetCalculatedTotalVolume },
		{ "GetDescription", &UEchoesInventoryItemObject::execGetDescription },
		{ "GetDisplayName", &UEchoesInventoryItemObject::execGetDisplayName },
		{ "GetFormattedTotalVolume", &UEchoesInventoryItemObject::execGetFormattedTotalVolume },
		{ "GetFormattedVolume", &UEchoesInventoryItemObject::execGetFormattedVolume },
		{ "GetItemData", &UEchoesInventoryItemObject::execGetItemData },
		{ "GetItemDefinitionData", &UEchoesInventoryItemObject::execGetItemDefinitionData },
		{ "GetItemName", &UEchoesInventoryItemObject::execGetItemName },
		{ "GetQuantity", &UEchoesInventoryItemObject::execGetQuantity },
		{ "GetTotalMass", &UEchoesInventoryItemObject::execGetTotalMass },
		{ "GetTypeId", &UEchoesInventoryItemObject::execGetTypeId },
		{ "GetUnitVolume", &UEchoesInventoryItemObject::execGetUnitVolume },
		{ "HasDefinition", &UEchoesInventoryItemObject::execHasDefinition },
		{ "InitializeWithData", &UEchoesInventoryItemObject::execInitializeWithData },
		{ "IsStackable", &UEchoesInventoryItemObject::execIsStackable },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesInventoryItemObject;
UClass* UEchoesInventoryItemObject::GetPrivateStaticClass()
{
	using TClass = UEchoesInventoryItemObject;
	if (!Z_Registration_Info_UClass_UEchoesInventoryItemObject.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesInventoryItemObject"),
			Z_Registration_Info_UClass_UEchoesInventoryItemObject.InnerSingleton,
			StaticRegisterNativesUEchoesInventoryItemObject,
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
	return Z_Registration_Info_UClass_UEchoesInventoryItemObject.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesInventoryItemObject_NoRegister()
{
	return UEchoesInventoryItemObject::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesInventoryItemObject_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UEchoesInventoryItemObject\n * \n * Data wrapper for FEchoesInventoryItem to be used with UListView\n * This UObject wraps the inventory item struct so it can be used with UMG ListView\n * \n * Usage:\n * - Create instances for each item in inventory\n * - Add to ListView as items\n * - Entry widgets retrieve data via getter methods\n */" },
#endif
		{ "IncludePath", "UI/EchoesInventoryItemObject.h" },
		{ "ModuleRelativePath", "UI/EchoesInventoryItemObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UEchoesInventoryItemObject\n\nData wrapper for FEchoesInventoryItem to be used with UListView\nThis UObject wraps the inventory item struct so it can be used with UMG ListView\n\nUsage:\n- Create instances for each item in inventory\n- Add to ListView as items\n- Entry widgets retrieve data via getter methods" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemData_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The wrapped inventory item data */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryItemObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The wrapped inventory item data" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InventorySubsystem_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Reference to inventory subsystem for fetching definitions */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryItemObject.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reference to inventory subsystem for fetching definitions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ItemData;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InventorySubsystem;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesInventoryItemObject_GetAssetId, "GetAssetId" }, // 3863850911
		{ &Z_Construct_UFunction_UEchoesInventoryItemObject_GetCalculatedTotalVolume, "GetCalculatedTotalVolume" }, // 2747291097
		{ &Z_Construct_UFunction_UEchoesInventoryItemObject_GetDescription, "GetDescription" }, // 858415420
		{ &Z_Construct_UFunction_UEchoesInventoryItemObject_GetDisplayName, "GetDisplayName" }, // 1652311593
		{ &Z_Construct_UFunction_UEchoesInventoryItemObject_GetFormattedTotalVolume, "GetFormattedTotalVolume" }, // 2362077509
		{ &Z_Construct_UFunction_UEchoesInventoryItemObject_GetFormattedVolume, "GetFormattedVolume" }, // 567224024
		{ &Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemData, "GetItemData" }, // 1338310867
		{ &Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemDefinitionData, "GetItemDefinitionData" }, // 3419370371
		{ &Z_Construct_UFunction_UEchoesInventoryItemObject_GetItemName, "GetItemName" }, // 3764568089
		{ &Z_Construct_UFunction_UEchoesInventoryItemObject_GetQuantity, "GetQuantity" }, // 2729205749
		{ &Z_Construct_UFunction_UEchoesInventoryItemObject_GetTotalMass, "GetTotalMass" }, // 3962847787
		{ &Z_Construct_UFunction_UEchoesInventoryItemObject_GetTypeId, "GetTypeId" }, // 244065313
		{ &Z_Construct_UFunction_UEchoesInventoryItemObject_GetUnitVolume, "GetUnitVolume" }, // 616223040
		{ &Z_Construct_UFunction_UEchoesInventoryItemObject_HasDefinition, "HasDefinition" }, // 3689454148
		{ &Z_Construct_UFunction_UEchoesInventoryItemObject_InitializeWithData, "InitializeWithData" }, // 3603063408
		{ &Z_Construct_UFunction_UEchoesInventoryItemObject_IsStackable, "IsStackable" }, // 4275079366
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesInventoryItemObject>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesInventoryItemObject_Statics::NewProp_ItemData = { "ItemData", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesInventoryItemObject, ItemData), Z_Construct_UScriptStruct_FEchoesInventoryItem, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemData_MetaData), NewProp_ItemData_MetaData) }; // 3518727963
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesInventoryItemObject_Statics::NewProp_InventorySubsystem = { "InventorySubsystem", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesInventoryItemObject, InventorySubsystem), Z_Construct_UClass_UEchoesInventorySubsystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InventorySubsystem_MetaData), NewProp_InventorySubsystem_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesInventoryItemObject_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventoryItemObject_Statics::NewProp_ItemData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventoryItemObject_Statics::NewProp_InventorySubsystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesInventoryItemObject_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesInventoryItemObject_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesInventoryItemObject_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesInventoryItemObject_Statics::ClassParams = {
	&UEchoesInventoryItemObject::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UEchoesInventoryItemObject_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesInventoryItemObject_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesInventoryItemObject_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesInventoryItemObject_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesInventoryItemObject()
{
	if (!Z_Registration_Info_UClass_UEchoesInventoryItemObject.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesInventoryItemObject.OuterSingleton, Z_Construct_UClass_UEchoesInventoryItemObject_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesInventoryItemObject.OuterSingleton;
}
UEchoesInventoryItemObject::UEchoesInventoryItemObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesInventoryItemObject);
UEchoesInventoryItemObject::~UEchoesInventoryItemObject() {}
// ********** End Class UEchoesInventoryItemObject *************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryItemObject_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesInventoryItemObject, UEchoesInventoryItemObject::StaticClass, TEXT("UEchoesInventoryItemObject"), &Z_Registration_Info_UClass_UEchoesInventoryItemObject, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesInventoryItemObject), 4153456366U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryItemObject_h__Script_Echoes_1170439757(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryItemObject_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryItemObject_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
