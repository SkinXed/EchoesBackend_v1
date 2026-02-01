// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UI/EchoesStationMenuWidget.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesStationMenuWidget() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UClass* Z_Construct_UClass_UEchoesStationMenuWidget();
ECHOES_API UClass* Z_Construct_UClass_UEchoesStationMenuWidget_NoRegister();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnInventoryButtonClicked__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnRepairButtonClicked__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnUndockButtonClicked__DelegateSignature();
UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnInventoryButtonClicked *********************************************
struct Z_Construct_UDelegateFunction_Echoes_OnInventoryButtonClicked__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Delegates for button actions\n" },
#endif
		{ "ModuleRelativePath", "UI/EchoesStationMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegates for button actions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnInventoryButtonClicked__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnInventoryButtonClicked__DelegateSignature", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnInventoryButtonClicked__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnInventoryButtonClicked__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_Echoes_OnInventoryButtonClicked__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnInventoryButtonClicked__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnInventoryButtonClicked_DelegateWrapper(const FMulticastScriptDelegate& OnInventoryButtonClicked)
{
	OnInventoryButtonClicked.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FOnInventoryButtonClicked ***********************************************

// ********** Begin Delegate FOnUndockButtonClicked ************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnUndockButtonClicked__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/EchoesStationMenuWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnUndockButtonClicked__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnUndockButtonClicked__DelegateSignature", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnUndockButtonClicked__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnUndockButtonClicked__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_Echoes_OnUndockButtonClicked__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnUndockButtonClicked__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnUndockButtonClicked_DelegateWrapper(const FMulticastScriptDelegate& OnUndockButtonClicked)
{
	OnUndockButtonClicked.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FOnUndockButtonClicked **************************************************

// ********** Begin Delegate FOnRepairButtonClicked ************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnRepairButtonClicked__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/EchoesStationMenuWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnRepairButtonClicked__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnRepairButtonClicked__DelegateSignature", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnRepairButtonClicked__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnRepairButtonClicked__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_Echoes_OnRepairButtonClicked__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnRepairButtonClicked__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnRepairButtonClicked_DelegateWrapper(const FMulticastScriptDelegate& OnRepairButtonClicked)
{
	OnRepairButtonClicked.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FOnRepairButtonClicked **************************************************

// ********** Begin Class UEchoesStationMenuWidget Function GetHangarStorageId *********************
struct Z_Construct_UFunction_UEchoesStationMenuWidget_GetHangarStorageId_Statics
{
	struct EchoesStationMenuWidget_eventGetHangarStorageId_Parms
	{
		FGuid ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Station|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the hangar storage ID for inventory operations\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesStationMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the hangar storage ID for inventory operations" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesStationMenuWidget_GetHangarStorageId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesStationMenuWidget_eventGetHangarStorageId_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesStationMenuWidget_GetHangarStorageId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesStationMenuWidget_GetHangarStorageId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStationMenuWidget_GetHangarStorageId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesStationMenuWidget_GetHangarStorageId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesStationMenuWidget, nullptr, "GetHangarStorageId", Z_Construct_UFunction_UEchoesStationMenuWidget_GetHangarStorageId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStationMenuWidget_GetHangarStorageId_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesStationMenuWidget_GetHangarStorageId_Statics::EchoesStationMenuWidget_eventGetHangarStorageId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStationMenuWidget_GetHangarStorageId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesStationMenuWidget_GetHangarStorageId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesStationMenuWidget_GetHangarStorageId_Statics::EchoesStationMenuWidget_eventGetHangarStorageId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesStationMenuWidget_GetHangarStorageId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesStationMenuWidget_GetHangarStorageId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesStationMenuWidget::execGetHangarStorageId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGuid*)Z_Param__Result=P_THIS->GetHangarStorageId();
	P_NATIVE_END;
}
// ********** End Class UEchoesStationMenuWidget Function GetHangarStorageId ***********************

// ********** Begin Class UEchoesStationMenuWidget Function GetStationId ***************************
struct Z_Construct_UFunction_UEchoesStationMenuWidget_GetStationId_Statics
{
	struct EchoesStationMenuWidget_eventGetStationId_Parms
	{
		FGuid ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Station|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the station ID\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesStationMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the station ID" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesStationMenuWidget_GetStationId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesStationMenuWidget_eventGetStationId_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesStationMenuWidget_GetStationId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesStationMenuWidget_GetStationId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStationMenuWidget_GetStationId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesStationMenuWidget_GetStationId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesStationMenuWidget, nullptr, "GetStationId", Z_Construct_UFunction_UEchoesStationMenuWidget_GetStationId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStationMenuWidget_GetStationId_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesStationMenuWidget_GetStationId_Statics::EchoesStationMenuWidget_eventGetStationId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStationMenuWidget_GetStationId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesStationMenuWidget_GetStationId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesStationMenuWidget_GetStationId_Statics::EchoesStationMenuWidget_eventGetStationId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesStationMenuWidget_GetStationId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesStationMenuWidget_GetStationId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesStationMenuWidget::execGetStationId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGuid*)Z_Param__Result=P_THIS->GetStationId();
	P_NATIVE_END;
}
// ********** End Class UEchoesStationMenuWidget Function GetStationId *****************************

// ********** Begin Class UEchoesStationMenuWidget Function InitializeStationMenu ******************
struct Z_Construct_UFunction_UEchoesStationMenuWidget_InitializeStationMenu_Statics
{
	struct EchoesStationMenuWidget_eventInitializeStationMenu_Parms
	{
		FGuid InStationId;
		FString InStationName;
		FString InStationType;
		FGuid InHangarStorageId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Station|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Initialize the station menu with station data\n\x09 * Called when the menu is opened\n\x09 * \n\x09 * @param InStationId - Station GUID\n\x09 * @param InStationName - Display name of station\n\x09 * @param InStationType - Type of station (Trading, Military, etc.)\n\x09 * @param InHangarStorageId - Container ID of personal hangar at this station\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesStationMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initialize the station menu with station data\nCalled when the menu is opened\n\n@param InStationId - Station GUID\n@param InStationName - Display name of station\n@param InStationType - Type of station (Trading, Military, etc.)\n@param InHangarStorageId - Container ID of personal hangar at this station" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InStationId_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InStationName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InStationType_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InHangarStorageId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_InStationId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InStationName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InStationType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InHangarStorageId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesStationMenuWidget_InitializeStationMenu_Statics::NewProp_InStationId = { "InStationId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesStationMenuWidget_eventInitializeStationMenu_Parms, InStationId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InStationId_MetaData), NewProp_InStationId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesStationMenuWidget_InitializeStationMenu_Statics::NewProp_InStationName = { "InStationName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesStationMenuWidget_eventInitializeStationMenu_Parms, InStationName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InStationName_MetaData), NewProp_InStationName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesStationMenuWidget_InitializeStationMenu_Statics::NewProp_InStationType = { "InStationType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesStationMenuWidget_eventInitializeStationMenu_Parms, InStationType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InStationType_MetaData), NewProp_InStationType_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesStationMenuWidget_InitializeStationMenu_Statics::NewProp_InHangarStorageId = { "InHangarStorageId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesStationMenuWidget_eventInitializeStationMenu_Parms, InHangarStorageId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InHangarStorageId_MetaData), NewProp_InHangarStorageId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesStationMenuWidget_InitializeStationMenu_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesStationMenuWidget_InitializeStationMenu_Statics::NewProp_InStationId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesStationMenuWidget_InitializeStationMenu_Statics::NewProp_InStationName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesStationMenuWidget_InitializeStationMenu_Statics::NewProp_InStationType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesStationMenuWidget_InitializeStationMenu_Statics::NewProp_InHangarStorageId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStationMenuWidget_InitializeStationMenu_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesStationMenuWidget_InitializeStationMenu_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesStationMenuWidget, nullptr, "InitializeStationMenu", Z_Construct_UFunction_UEchoesStationMenuWidget_InitializeStationMenu_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStationMenuWidget_InitializeStationMenu_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesStationMenuWidget_InitializeStationMenu_Statics::EchoesStationMenuWidget_eventInitializeStationMenu_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStationMenuWidget_InitializeStationMenu_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesStationMenuWidget_InitializeStationMenu_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesStationMenuWidget_InitializeStationMenu_Statics::EchoesStationMenuWidget_eventInitializeStationMenu_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesStationMenuWidget_InitializeStationMenu()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesStationMenuWidget_InitializeStationMenu_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesStationMenuWidget::execInitializeStationMenu)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_InStationId);
	P_GET_PROPERTY(FStrProperty,Z_Param_InStationName);
	P_GET_PROPERTY(FStrProperty,Z_Param_InStationType);
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_InHangarStorageId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeStationMenu(Z_Param_Out_InStationId,Z_Param_InStationName,Z_Param_InStationType,Z_Param_Out_InHangarStorageId);
	P_NATIVE_END;
}
// ********** End Class UEchoesStationMenuWidget Function InitializeStationMenu ********************

// ********** Begin Class UEchoesStationMenuWidget Function OnInventoryButtonPressed ***************
struct Z_Construct_UFunction_UEchoesStationMenuWidget_OnInventoryButtonPressed_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Handle Inventory button clicked\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesStationMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle Inventory button clicked" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesStationMenuWidget_OnInventoryButtonPressed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesStationMenuWidget, nullptr, "OnInventoryButtonPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStationMenuWidget_OnInventoryButtonPressed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesStationMenuWidget_OnInventoryButtonPressed_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesStationMenuWidget_OnInventoryButtonPressed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesStationMenuWidget_OnInventoryButtonPressed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesStationMenuWidget::execOnInventoryButtonPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnInventoryButtonPressed();
	P_NATIVE_END;
}
// ********** End Class UEchoesStationMenuWidget Function OnInventoryButtonPressed *****************

// ********** Begin Class UEchoesStationMenuWidget Function OnRepairButtonPressed ******************
struct Z_Construct_UFunction_UEchoesStationMenuWidget_OnRepairButtonPressed_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Handle Repair button clicked\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesStationMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle Repair button clicked" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesStationMenuWidget_OnRepairButtonPressed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesStationMenuWidget, nullptr, "OnRepairButtonPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStationMenuWidget_OnRepairButtonPressed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesStationMenuWidget_OnRepairButtonPressed_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesStationMenuWidget_OnRepairButtonPressed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesStationMenuWidget_OnRepairButtonPressed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesStationMenuWidget::execOnRepairButtonPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRepairButtonPressed();
	P_NATIVE_END;
}
// ********** End Class UEchoesStationMenuWidget Function OnRepairButtonPressed ********************

// ********** Begin Class UEchoesStationMenuWidget Function OnStationMenuInitialized ***************
static FName NAME_UEchoesStationMenuWidget_OnStationMenuInitialized = FName(TEXT("OnStationMenuInitialized"));
void UEchoesStationMenuWidget::OnStationMenuInitialized()
{
	UFunction* Func = FindFunctionChecked(NAME_UEchoesStationMenuWidget_OnStationMenuInitialized);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_UEchoesStationMenuWidget_OnStationMenuInitialized_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Station|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Blueprint event called when station menu is initialized\n\x09 * Override in Blueprint for custom initialization\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesStationMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint event called when station menu is initialized\nOverride in Blueprint for custom initialization" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesStationMenuWidget_OnStationMenuInitialized_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesStationMenuWidget, nullptr, "OnStationMenuInitialized", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStationMenuWidget_OnStationMenuInitialized_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesStationMenuWidget_OnStationMenuInitialized_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesStationMenuWidget_OnStationMenuInitialized()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesStationMenuWidget_OnStationMenuInitialized_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UEchoesStationMenuWidget Function OnStationMenuInitialized *****************

// ********** Begin Class UEchoesStationMenuWidget Function OnUndockButtonPressed ******************
struct Z_Construct_UFunction_UEchoesStationMenuWidget_OnUndockButtonPressed_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Handle Undock button clicked\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesStationMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle Undock button clicked" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesStationMenuWidget_OnUndockButtonPressed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesStationMenuWidget, nullptr, "OnUndockButtonPressed", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStationMenuWidget_OnUndockButtonPressed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesStationMenuWidget_OnUndockButtonPressed_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesStationMenuWidget_OnUndockButtonPressed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesStationMenuWidget_OnUndockButtonPressed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesStationMenuWidget::execOnUndockButtonPressed)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnUndockButtonPressed();
	P_NATIVE_END;
}
// ********** End Class UEchoesStationMenuWidget Function OnUndockButtonPressed ********************

// ********** Begin Class UEchoesStationMenuWidget Function OpenPersonalHangar *********************
struct Z_Construct_UFunction_UEchoesStationMenuWidget_OpenPersonalHangar_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Station|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Open personal hangar window\n\x09 * Creates a new window with inventory widget showing hangar contents\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesStationMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Open personal hangar window\nCreates a new window with inventory widget showing hangar contents" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesStationMenuWidget_OpenPersonalHangar_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesStationMenuWidget, nullptr, "OpenPersonalHangar", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStationMenuWidget_OpenPersonalHangar_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesStationMenuWidget_OpenPersonalHangar_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesStationMenuWidget_OpenPersonalHangar()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesStationMenuWidget_OpenPersonalHangar_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesStationMenuWidget::execOpenPersonalHangar)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OpenPersonalHangar();
	P_NATIVE_END;
}
// ********** End Class UEchoesStationMenuWidget Function OpenPersonalHangar ***********************

// ********** Begin Class UEchoesStationMenuWidget Function OpenShipCargo **************************
struct Z_Construct_UFunction_UEchoesStationMenuWidget_OpenShipCargo_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Station|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Open ship cargo window\n\x09 * Creates a new window with inventory widget showing ship cargo\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesStationMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Open ship cargo window\nCreates a new window with inventory widget showing ship cargo" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesStationMenuWidget_OpenShipCargo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesStationMenuWidget, nullptr, "OpenShipCargo", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStationMenuWidget_OpenShipCargo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesStationMenuWidget_OpenShipCargo_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesStationMenuWidget_OpenShipCargo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesStationMenuWidget_OpenShipCargo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesStationMenuWidget::execOpenShipCargo)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OpenShipCargo();
	P_NATIVE_END;
}
// ********** End Class UEchoesStationMenuWidget Function OpenShipCargo ****************************

// ********** Begin Class UEchoesStationMenuWidget Function RequestUndock **************************
struct Z_Construct_UFunction_UEchoesStationMenuWidget_RequestUndock_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Station|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Request undock from server\n\x09 * Calls ServerRPC on StationActor\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesStationMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Request undock from server\nCalls ServerRPC on StationActor" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesStationMenuWidget_RequestUndock_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesStationMenuWidget, nullptr, "RequestUndock", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesStationMenuWidget_RequestUndock_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesStationMenuWidget_RequestUndock_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesStationMenuWidget_RequestUndock()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesStationMenuWidget_RequestUndock_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesStationMenuWidget::execRequestUndock)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RequestUndock();
	P_NATIVE_END;
}
// ********** End Class UEchoesStationMenuWidget Function RequestUndock ****************************

// ********** Begin Class UEchoesStationMenuWidget *************************************************
void UEchoesStationMenuWidget::StaticRegisterNativesUEchoesStationMenuWidget()
{
	UClass* Class = UEchoesStationMenuWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetHangarStorageId", &UEchoesStationMenuWidget::execGetHangarStorageId },
		{ "GetStationId", &UEchoesStationMenuWidget::execGetStationId },
		{ "InitializeStationMenu", &UEchoesStationMenuWidget::execInitializeStationMenu },
		{ "OnInventoryButtonPressed", &UEchoesStationMenuWidget::execOnInventoryButtonPressed },
		{ "OnRepairButtonPressed", &UEchoesStationMenuWidget::execOnRepairButtonPressed },
		{ "OnUndockButtonPressed", &UEchoesStationMenuWidget::execOnUndockButtonPressed },
		{ "OpenPersonalHangar", &UEchoesStationMenuWidget::execOpenPersonalHangar },
		{ "OpenShipCargo", &UEchoesStationMenuWidget::execOpenShipCargo },
		{ "RequestUndock", &UEchoesStationMenuWidget::execRequestUndock },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesStationMenuWidget;
UClass* UEchoesStationMenuWidget::GetPrivateStaticClass()
{
	using TClass = UEchoesStationMenuWidget;
	if (!Z_Registration_Info_UClass_UEchoesStationMenuWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesStationMenuWidget"),
			Z_Registration_Info_UClass_UEchoesStationMenuWidget.InnerSingleton,
			StaticRegisterNativesUEchoesStationMenuWidget,
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
	return Z_Registration_Info_UClass_UEchoesStationMenuWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesStationMenuWidget_NoRegister()
{
	return UEchoesStationMenuWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesStationMenuWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UEchoesStationMenuWidget\n * \n * Station menu widget for player interaction with stations\n * Provides access to inventory, undocking, and station services\n * \n * Features:\n * - Inventory button: Opens personal hangar at current station\n * - Undock button: Initiates undocking sequence\n * - Repair button: Station services (stub for now)\n * - Displays current station info (Name, Type)\n * \n * Usage:\n * - Create widget blueprint based on this class\n * - Add buttons: InventoryButton, UndockButton, RepairButton\n * - Add text blocks: StationNameText, StationTypeText\n * - Widget is opened via ClientRPC from StationActor upon docking\n */" },
#endif
		{ "IncludePath", "UI/EchoesStationMenuWidget.h" },
		{ "ModuleRelativePath", "UI/EchoesStationMenuWidget.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UEchoesStationMenuWidget\n\nStation menu widget for player interaction with stations\nProvides access to inventory, undocking, and station services\n\nFeatures:\n- Inventory button: Opens personal hangar at current station\n- Undock button: Initiates undocking sequence\n- Repair button: Station services (stub for now)\n- Displays current station info (Name, Type)\n\nUsage:\n- Create widget blueprint based on this class\n- Add buttons: InventoryButton, UndockButton, RepairButton\n- Add text blocks: StationNameText, StationTypeText\n- Widget is opened via ClientRPC from StationActor upon docking" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnInventoryButtonClicked_MetaData[] = {
		{ "Category", "Echoes|Station|Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Triggered when Inventory button is clicked\n\x09 * Blueprint should open hangar inventory UI\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesStationMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Triggered when Inventory button is clicked\nBlueprint should open hangar inventory UI" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnUndockButtonClicked_MetaData[] = {
		{ "Category", "Echoes|Station|Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Triggered when Undock button is clicked\n\x09 * Blueprint should initiate undocking sequence\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesStationMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Triggered when Undock button is clicked\nBlueprint should initiate undocking sequence" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnRepairButtonClicked_MetaData[] = {
		{ "Category", "Echoes|Station|Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Triggered when Repair button is clicked\n\x09 * Blueprint should open repair/services UI\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesStationMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Triggered when Repair button is clicked\nBlueprint should open repair/services UI" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InventoryButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|Station|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Button to open inventory/hangar */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesStationMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Button to open inventory/hangar" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UndockButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|Station|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Button to undock from station */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesStationMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Button to undock from station" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RepairButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|Station|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Button for repair/services (stub) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesStationMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Button for repair/services (stub)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StationNameText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|Station|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Text block displaying station name */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesStationMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Text block displaying station name" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StationTypeText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "Echoes|Station|UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Text block displaying station type */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/EchoesStationMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Text block displaying station type" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StationId_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current station ID */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesStationMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current station ID" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StationName_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Station name */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesStationMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Station name" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StationType_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Station type */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesStationMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Station type" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HangarStorageId_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Personal hangar storage ID at this station */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesStationMenuWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Personal hangar storage ID at this station" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnInventoryButtonClicked;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnUndockButtonClicked;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnRepairButtonClicked;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InventoryButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_UndockButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RepairButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StationNameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StationTypeText;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StationId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_StationName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_StationType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_HangarStorageId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesStationMenuWidget_GetHangarStorageId, "GetHangarStorageId" }, // 968842352
		{ &Z_Construct_UFunction_UEchoesStationMenuWidget_GetStationId, "GetStationId" }, // 765782141
		{ &Z_Construct_UFunction_UEchoesStationMenuWidget_InitializeStationMenu, "InitializeStationMenu" }, // 1548763660
		{ &Z_Construct_UFunction_UEchoesStationMenuWidget_OnInventoryButtonPressed, "OnInventoryButtonPressed" }, // 1077758705
		{ &Z_Construct_UFunction_UEchoesStationMenuWidget_OnRepairButtonPressed, "OnRepairButtonPressed" }, // 2691397763
		{ &Z_Construct_UFunction_UEchoesStationMenuWidget_OnStationMenuInitialized, "OnStationMenuInitialized" }, // 1359939120
		{ &Z_Construct_UFunction_UEchoesStationMenuWidget_OnUndockButtonPressed, "OnUndockButtonPressed" }, // 434453442
		{ &Z_Construct_UFunction_UEchoesStationMenuWidget_OpenPersonalHangar, "OpenPersonalHangar" }, // 899008183
		{ &Z_Construct_UFunction_UEchoesStationMenuWidget_OpenShipCargo, "OpenShipCargo" }, // 970630485
		{ &Z_Construct_UFunction_UEchoesStationMenuWidget_RequestUndock, "RequestUndock" }, // 502295419
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesStationMenuWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesStationMenuWidget_Statics::NewProp_OnInventoryButtonClicked = { "OnInventoryButtonClicked", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesStationMenuWidget, OnInventoryButtonClicked), Z_Construct_UDelegateFunction_Echoes_OnInventoryButtonClicked__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnInventoryButtonClicked_MetaData), NewProp_OnInventoryButtonClicked_MetaData) }; // 1160635909
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesStationMenuWidget_Statics::NewProp_OnUndockButtonClicked = { "OnUndockButtonClicked", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesStationMenuWidget, OnUndockButtonClicked), Z_Construct_UDelegateFunction_Echoes_OnUndockButtonClicked__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnUndockButtonClicked_MetaData), NewProp_OnUndockButtonClicked_MetaData) }; // 3306517124
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesStationMenuWidget_Statics::NewProp_OnRepairButtonClicked = { "OnRepairButtonClicked", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesStationMenuWidget, OnRepairButtonClicked), Z_Construct_UDelegateFunction_Echoes_OnRepairButtonClicked__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnRepairButtonClicked_MetaData), NewProp_OnRepairButtonClicked_MetaData) }; // 3142367974
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesStationMenuWidget_Statics::NewProp_InventoryButton = { "InventoryButton", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesStationMenuWidget, InventoryButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InventoryButton_MetaData), NewProp_InventoryButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesStationMenuWidget_Statics::NewProp_UndockButton = { "UndockButton", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesStationMenuWidget, UndockButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UndockButton_MetaData), NewProp_UndockButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesStationMenuWidget_Statics::NewProp_RepairButton = { "RepairButton", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesStationMenuWidget, RepairButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RepairButton_MetaData), NewProp_RepairButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesStationMenuWidget_Statics::NewProp_StationNameText = { "StationNameText", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesStationMenuWidget, StationNameText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StationNameText_MetaData), NewProp_StationNameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesStationMenuWidget_Statics::NewProp_StationTypeText = { "StationTypeText", nullptr, (EPropertyFlags)0x002008000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesStationMenuWidget, StationTypeText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StationTypeText_MetaData), NewProp_StationTypeText_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesStationMenuWidget_Statics::NewProp_StationId = { "StationId", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesStationMenuWidget, StationId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StationId_MetaData), NewProp_StationId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEchoesStationMenuWidget_Statics::NewProp_StationName = { "StationName", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesStationMenuWidget, StationName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StationName_MetaData), NewProp_StationName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEchoesStationMenuWidget_Statics::NewProp_StationType = { "StationType", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesStationMenuWidget, StationType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StationType_MetaData), NewProp_StationType_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesStationMenuWidget_Statics::NewProp_HangarStorageId = { "HangarStorageId", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesStationMenuWidget, HangarStorageId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HangarStorageId_MetaData), NewProp_HangarStorageId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesStationMenuWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesStationMenuWidget_Statics::NewProp_OnInventoryButtonClicked,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesStationMenuWidget_Statics::NewProp_OnUndockButtonClicked,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesStationMenuWidget_Statics::NewProp_OnRepairButtonClicked,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesStationMenuWidget_Statics::NewProp_InventoryButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesStationMenuWidget_Statics::NewProp_UndockButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesStationMenuWidget_Statics::NewProp_RepairButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesStationMenuWidget_Statics::NewProp_StationNameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesStationMenuWidget_Statics::NewProp_StationTypeText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesStationMenuWidget_Statics::NewProp_StationId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesStationMenuWidget_Statics::NewProp_StationName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesStationMenuWidget_Statics::NewProp_StationType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesStationMenuWidget_Statics::NewProp_HangarStorageId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesStationMenuWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesStationMenuWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesStationMenuWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesStationMenuWidget_Statics::ClassParams = {
	&UEchoesStationMenuWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UEchoesStationMenuWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesStationMenuWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesStationMenuWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesStationMenuWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesStationMenuWidget()
{
	if (!Z_Registration_Info_UClass_UEchoesStationMenuWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesStationMenuWidget.OuterSingleton, Z_Construct_UClass_UEchoesStationMenuWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesStationMenuWidget.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesStationMenuWidget);
UEchoesStationMenuWidget::~UEchoesStationMenuWidget() {}
// ********** End Class UEchoesStationMenuWidget ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesStationMenuWidget_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesStationMenuWidget, UEchoesStationMenuWidget::StaticClass, TEXT("UEchoesStationMenuWidget"), &Z_Registration_Info_UClass_UEchoesStationMenuWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesStationMenuWidget), 305910390U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesStationMenuWidget_h__Script_Echoes_529550722(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesStationMenuWidget_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesStationMenuWidget_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
