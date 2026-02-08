// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ShipStatsWidget.h"
#include "EchoesCoreTypes.h"
#include "ShipFittingInterface.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeShipStatsWidget() {}

// ********** Begin Cross Module References ********************************************************
ECHOES_API UClass* Z_Construct_UClass_UEquipmentObserver_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UShipFittingInterface_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UShipStatsWidget();
ECHOES_API UClass* Z_Construct_UClass_UShipStatsWidget_NoRegister();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_ECosmosDamageType();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FCommon_ShipFittingData();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FCosmosDefenseLayer();
ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
UMG_API UClass* Z_Construct_UClass_UProgressBar_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UShipStatsWidget Function ClientOnly_RefreshStats ************************
struct Z_Construct_UFunction_UShipStatsWidget_ClientOnly_RefreshStats_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ============================================================================\n// CLIENT-ONLY FUNCTIONS\n// ============================================================================\n" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "CLIENT-ONLY FUNCTIONS" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipStatsWidget_ClientOnly_RefreshStats_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipStatsWidget, nullptr, "ClientOnly_RefreshStats", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_ClientOnly_RefreshStats_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipStatsWidget_ClientOnly_RefreshStats_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UShipStatsWidget_ClientOnly_RefreshStats()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipStatsWidget_ClientOnly_RefreshStats_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShipStatsWidget::execClientOnly_RefreshStats)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_RefreshStats();
	P_NATIVE_END;
}
// ********** End Class UShipStatsWidget Function ClientOnly_RefreshStats **************************

// ********** Begin Class UShipStatsWidget Function ClientOnly_UpdateDPSDisplay ********************
struct Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateDPSDisplay_Statics
{
	struct ShipStatsWidget_eventClientOnly_UpdateDPSDisplay_Parms
	{
		float Alpha;
		float Sustained;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Stats" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Alpha;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Sustained;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateDPSDisplay_Statics::NewProp_Alpha = { "Alpha", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatsWidget_eventClientOnly_UpdateDPSDisplay_Parms, Alpha), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateDPSDisplay_Statics::NewProp_Sustained = { "Sustained", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatsWidget_eventClientOnly_UpdateDPSDisplay_Parms, Sustained), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateDPSDisplay_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateDPSDisplay_Statics::NewProp_Alpha,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateDPSDisplay_Statics::NewProp_Sustained,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateDPSDisplay_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateDPSDisplay_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipStatsWidget, nullptr, "ClientOnly_UpdateDPSDisplay", Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateDPSDisplay_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateDPSDisplay_Statics::PropPointers), sizeof(Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateDPSDisplay_Statics::ShipStatsWidget_eventClientOnly_UpdateDPSDisplay_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateDPSDisplay_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateDPSDisplay_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateDPSDisplay_Statics::ShipStatsWidget_eventClientOnly_UpdateDPSDisplay_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateDPSDisplay()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateDPSDisplay_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShipStatsWidget::execClientOnly_UpdateDPSDisplay)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Alpha);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Sustained);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_UpdateDPSDisplay(Z_Param_Alpha,Z_Param_Sustained);
	P_NATIVE_END;
}
// ********** End Class UShipStatsWidget Function ClientOnly_UpdateDPSDisplay **********************

// ********** Begin Class UShipStatsWidget Function ClientOnly_UpdateEHPDisplay ********************
struct Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateEHPDisplay_Statics
{
	struct ShipStatsWidget_eventClientOnly_UpdateEHPDisplay_Parms
	{
		float EHP;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Stats" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EHP;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateEHPDisplay_Statics::NewProp_EHP = { "EHP", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatsWidget_eventClientOnly_UpdateEHPDisplay_Parms, EHP), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateEHPDisplay_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateEHPDisplay_Statics::NewProp_EHP,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateEHPDisplay_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateEHPDisplay_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipStatsWidget, nullptr, "ClientOnly_UpdateEHPDisplay", Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateEHPDisplay_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateEHPDisplay_Statics::PropPointers), sizeof(Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateEHPDisplay_Statics::ShipStatsWidget_eventClientOnly_UpdateEHPDisplay_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateEHPDisplay_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateEHPDisplay_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateEHPDisplay_Statics::ShipStatsWidget_eventClientOnly_UpdateEHPDisplay_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateEHPDisplay()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateEHPDisplay_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShipStatsWidget::execClientOnly_UpdateEHPDisplay)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_EHP);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_UpdateEHPDisplay(Z_Param_EHP);
	P_NATIVE_END;
}
// ********** End Class UShipStatsWidget Function ClientOnly_UpdateEHPDisplay **********************

// ********** Begin Class UShipStatsWidget Function ClientOnly_UpdateResistanceDisplay *************
struct Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateResistanceDisplay_Statics
{
	struct ShipStatsWidget_eventClientOnly_UpdateResistanceDisplay_Parms
	{
		ECosmosDamageType Type;
		float Resistance;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Stats" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Type_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Type;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Resistance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateResistanceDisplay_Statics::NewProp_Type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateResistanceDisplay_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatsWidget_eventClientOnly_UpdateResistanceDisplay_Parms, Type), Z_Construct_UEnum_Echoes_ECosmosDamageType, METADATA_PARAMS(0, nullptr) }; // 4170051619
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateResistanceDisplay_Statics::NewProp_Resistance = { "Resistance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatsWidget_eventClientOnly_UpdateResistanceDisplay_Parms, Resistance), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateResistanceDisplay_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateResistanceDisplay_Statics::NewProp_Type_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateResistanceDisplay_Statics::NewProp_Type,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateResistanceDisplay_Statics::NewProp_Resistance,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateResistanceDisplay_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateResistanceDisplay_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipStatsWidget, nullptr, "ClientOnly_UpdateResistanceDisplay", Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateResistanceDisplay_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateResistanceDisplay_Statics::PropPointers), sizeof(Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateResistanceDisplay_Statics::ShipStatsWidget_eventClientOnly_UpdateResistanceDisplay_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateResistanceDisplay_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateResistanceDisplay_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateResistanceDisplay_Statics::ShipStatsWidget_eventClientOnly_UpdateResistanceDisplay_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateResistanceDisplay()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateResistanceDisplay_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShipStatsWidget::execClientOnly_UpdateResistanceDisplay)
{
	P_GET_ENUM(ECosmosDamageType,Z_Param_Type);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Resistance);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_UpdateResistanceDisplay(ECosmosDamageType(Z_Param_Type),Z_Param_Resistance);
	P_NATIVE_END;
}
// ********** End Class UShipStatsWidget Function ClientOnly_UpdateResistanceDisplay ***************

// ********** Begin Class UShipStatsWidget Function ClientOnly_UpdateScanningDisplay ***************
struct Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateScanningDisplay_Statics
{
	struct ShipStatsWidget_eventClientOnly_UpdateScanningDisplay_Parms
	{
		float ScanResolution;
		float SignatureRadius;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Stats" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ScanResolution;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SignatureRadius;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateScanningDisplay_Statics::NewProp_ScanResolution = { "ScanResolution", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatsWidget_eventClientOnly_UpdateScanningDisplay_Parms, ScanResolution), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateScanningDisplay_Statics::NewProp_SignatureRadius = { "SignatureRadius", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatsWidget_eventClientOnly_UpdateScanningDisplay_Parms, SignatureRadius), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateScanningDisplay_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateScanningDisplay_Statics::NewProp_ScanResolution,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateScanningDisplay_Statics::NewProp_SignatureRadius,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateScanningDisplay_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateScanningDisplay_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipStatsWidget, nullptr, "ClientOnly_UpdateScanningDisplay", Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateScanningDisplay_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateScanningDisplay_Statics::PropPointers), sizeof(Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateScanningDisplay_Statics::ShipStatsWidget_eventClientOnly_UpdateScanningDisplay_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateScanningDisplay_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateScanningDisplay_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateScanningDisplay_Statics::ShipStatsWidget_eventClientOnly_UpdateScanningDisplay_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateScanningDisplay()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateScanningDisplay_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShipStatsWidget::execClientOnly_UpdateScanningDisplay)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_ScanResolution);
	P_GET_PROPERTY(FFloatProperty,Z_Param_SignatureRadius);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_UpdateScanningDisplay(Z_Param_ScanResolution,Z_Param_SignatureRadius);
	P_NATIVE_END;
}
// ********** End Class UShipStatsWidget Function ClientOnly_UpdateScanningDisplay *****************

// ********** Begin Class UShipStatsWidget Function ClientOnly_UpdateSpeedDisplay ******************
struct Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateSpeedDisplay_Statics
{
	struct ShipStatsWidget_eventClientOnly_UpdateSpeedDisplay_Parms
	{
		float MaxSpeed;
		float WarpSpeed;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Stats" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WarpSpeed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateSpeedDisplay_Statics::NewProp_MaxSpeed = { "MaxSpeed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatsWidget_eventClientOnly_UpdateSpeedDisplay_Parms, MaxSpeed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateSpeedDisplay_Statics::NewProp_WarpSpeed = { "WarpSpeed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatsWidget_eventClientOnly_UpdateSpeedDisplay_Parms, WarpSpeed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateSpeedDisplay_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateSpeedDisplay_Statics::NewProp_MaxSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateSpeedDisplay_Statics::NewProp_WarpSpeed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateSpeedDisplay_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateSpeedDisplay_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipStatsWidget, nullptr, "ClientOnly_UpdateSpeedDisplay", Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateSpeedDisplay_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateSpeedDisplay_Statics::PropPointers), sizeof(Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateSpeedDisplay_Statics::ShipStatsWidget_eventClientOnly_UpdateSpeedDisplay_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateSpeedDisplay_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateSpeedDisplay_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateSpeedDisplay_Statics::ShipStatsWidget_eventClientOnly_UpdateSpeedDisplay_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateSpeedDisplay()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateSpeedDisplay_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShipStatsWidget::execClientOnly_UpdateSpeedDisplay)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_MaxSpeed);
	P_GET_PROPERTY(FFloatProperty,Z_Param_WarpSpeed);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_UpdateSpeedDisplay(Z_Param_MaxSpeed,Z_Param_WarpSpeed);
	P_NATIVE_END;
}
// ********** End Class UShipStatsWidget Function ClientOnly_UpdateSpeedDisplay ********************

// ********** Begin Class UShipStatsWidget Function Common_CalculateDPS ****************************
struct Z_Construct_UFunction_UShipStatsWidget_Common_CalculateDPS_Statics
{
	struct ShipStatsWidget_eventCommon_CalculateDPS_Parms
	{
		FCommon_ShipFittingData FittingData;
		float OutAlpha;
		float OutSustained;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Calculate DPS (Alpha and Sustained)\n     */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Calculate DPS (Alpha and Sustained)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FittingData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_FittingData;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OutAlpha;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OutSustained;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UShipStatsWidget_Common_CalculateDPS_Statics::NewProp_FittingData = { "FittingData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatsWidget_eventCommon_CalculateDPS_Parms, FittingData), Z_Construct_UScriptStruct_FCommon_ShipFittingData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FittingData_MetaData), NewProp_FittingData_MetaData) }; // 1329122485
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatsWidget_Common_CalculateDPS_Statics::NewProp_OutAlpha = { "OutAlpha", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatsWidget_eventCommon_CalculateDPS_Parms, OutAlpha), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatsWidget_Common_CalculateDPS_Statics::NewProp_OutSustained = { "OutSustained", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatsWidget_eventCommon_CalculateDPS_Parms, OutSustained), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShipStatsWidget_Common_CalculateDPS_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatsWidget_Common_CalculateDPS_Statics::NewProp_FittingData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatsWidget_Common_CalculateDPS_Statics::NewProp_OutAlpha,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatsWidget_Common_CalculateDPS_Statics::NewProp_OutSustained,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_Common_CalculateDPS_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipStatsWidget_Common_CalculateDPS_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipStatsWidget, nullptr, "Common_CalculateDPS", Z_Construct_UFunction_UShipStatsWidget_Common_CalculateDPS_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_Common_CalculateDPS_Statics::PropPointers), sizeof(Z_Construct_UFunction_UShipStatsWidget_Common_CalculateDPS_Statics::ShipStatsWidget_eventCommon_CalculateDPS_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_Common_CalculateDPS_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipStatsWidget_Common_CalculateDPS_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UShipStatsWidget_Common_CalculateDPS_Statics::ShipStatsWidget_eventCommon_CalculateDPS_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShipStatsWidget_Common_CalculateDPS()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipStatsWidget_Common_CalculateDPS_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShipStatsWidget::execCommon_CalculateDPS)
{
	P_GET_STRUCT_REF(FCommon_ShipFittingData,Z_Param_Out_FittingData);
	P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_OutAlpha);
	P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_OutSustained);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Common_CalculateDPS(Z_Param_Out_FittingData,Z_Param_Out_OutAlpha,Z_Param_Out_OutSustained);
	P_NATIVE_END;
}
// ********** End Class UShipStatsWidget Function Common_CalculateDPS ******************************

// ********** Begin Class UShipStatsWidget Function Common_CalculateEffectiveHP ********************
struct Z_Construct_UFunction_UShipStatsWidget_Common_CalculateEffectiveHP_Statics
{
	struct ShipStatsWidget_eventCommon_CalculateEffectiveHP_Parms
	{
		FCommon_ShipFittingData FittingData;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Calculate effective HP considering resistances\n     */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Calculate effective HP considering resistances" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FittingData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_FittingData;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UShipStatsWidget_Common_CalculateEffectiveHP_Statics::NewProp_FittingData = { "FittingData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatsWidget_eventCommon_CalculateEffectiveHP_Parms, FittingData), Z_Construct_UScriptStruct_FCommon_ShipFittingData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FittingData_MetaData), NewProp_FittingData_MetaData) }; // 1329122485
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatsWidget_Common_CalculateEffectiveHP_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatsWidget_eventCommon_CalculateEffectiveHP_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShipStatsWidget_Common_CalculateEffectiveHP_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatsWidget_Common_CalculateEffectiveHP_Statics::NewProp_FittingData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatsWidget_Common_CalculateEffectiveHP_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_Common_CalculateEffectiveHP_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipStatsWidget_Common_CalculateEffectiveHP_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipStatsWidget, nullptr, "Common_CalculateEffectiveHP", Z_Construct_UFunction_UShipStatsWidget_Common_CalculateEffectiveHP_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_Common_CalculateEffectiveHP_Statics::PropPointers), sizeof(Z_Construct_UFunction_UShipStatsWidget_Common_CalculateEffectiveHP_Statics::ShipStatsWidget_eventCommon_CalculateEffectiveHP_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_Common_CalculateEffectiveHP_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipStatsWidget_Common_CalculateEffectiveHP_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UShipStatsWidget_Common_CalculateEffectiveHP_Statics::ShipStatsWidget_eventCommon_CalculateEffectiveHP_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShipStatsWidget_Common_CalculateEffectiveHP()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipStatsWidget_Common_CalculateEffectiveHP_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShipStatsWidget::execCommon_CalculateEffectiveHP)
{
	P_GET_STRUCT_REF(FCommon_ShipFittingData,Z_Param_Out_FittingData);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->Common_CalculateEffectiveHP(Z_Param_Out_FittingData);
	P_NATIVE_END;
}
// ********** End Class UShipStatsWidget Function Common_CalculateEffectiveHP **********************

// ********** Begin Class UShipStatsWidget Function Common_CalculateTotalStats *********************
struct Z_Construct_UFunction_UShipStatsWidget_Common_CalculateTotalStats_Statics
{
	struct ShipStatsWidget_eventCommon_CalculateTotalStats_Parms
	{
		FCommon_ShipFittingData ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Calculate total ship statistics from fitting\n     * This is the core stat calculation function\n     */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Calculate total ship statistics from fitting\nThis is the core stat calculation function" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UShipStatsWidget_Common_CalculateTotalStats_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatsWidget_eventCommon_CalculateTotalStats_Parms, ReturnValue), Z_Construct_UScriptStruct_FCommon_ShipFittingData, METADATA_PARAMS(0, nullptr) }; // 1329122485
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShipStatsWidget_Common_CalculateTotalStats_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatsWidget_Common_CalculateTotalStats_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_Common_CalculateTotalStats_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipStatsWidget_Common_CalculateTotalStats_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipStatsWidget, nullptr, "Common_CalculateTotalStats", Z_Construct_UFunction_UShipStatsWidget_Common_CalculateTotalStats_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_Common_CalculateTotalStats_Statics::PropPointers), sizeof(Z_Construct_UFunction_UShipStatsWidget_Common_CalculateTotalStats_Statics::ShipStatsWidget_eventCommon_CalculateTotalStats_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_Common_CalculateTotalStats_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipStatsWidget_Common_CalculateTotalStats_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UShipStatsWidget_Common_CalculateTotalStats_Statics::ShipStatsWidget_eventCommon_CalculateTotalStats_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShipStatsWidget_Common_CalculateTotalStats()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipStatsWidget_Common_CalculateTotalStats_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShipStatsWidget::execCommon_CalculateTotalStats)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FCommon_ShipFittingData*)Z_Param__Result=P_THIS->Common_CalculateTotalStats();
	P_NATIVE_END;
}
// ********** End Class UShipStatsWidget Function Common_CalculateTotalStats ***********************

// ********** Begin Class UShipStatsWidget Function Common_FormatNumber ****************************
struct Z_Construct_UFunction_UShipStatsWidget_Common_FormatNumber_Statics
{
	struct ShipStatsWidget_eventCommon_FormatNumber_Parms
	{
		float Value;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Format large numbers with k/M/B suffixes\n     */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Format large numbers with k/M/B suffixes" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatsWidget_Common_FormatNumber_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatsWidget_eventCommon_FormatNumber_Parms, Value), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UShipStatsWidget_Common_FormatNumber_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatsWidget_eventCommon_FormatNumber_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShipStatsWidget_Common_FormatNumber_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatsWidget_Common_FormatNumber_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatsWidget_Common_FormatNumber_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_Common_FormatNumber_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipStatsWidget_Common_FormatNumber_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipStatsWidget, nullptr, "Common_FormatNumber", Z_Construct_UFunction_UShipStatsWidget_Common_FormatNumber_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_Common_FormatNumber_Statics::PropPointers), sizeof(Z_Construct_UFunction_UShipStatsWidget_Common_FormatNumber_Statics::ShipStatsWidget_eventCommon_FormatNumber_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_Common_FormatNumber_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipStatsWidget_Common_FormatNumber_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UShipStatsWidget_Common_FormatNumber_Statics::ShipStatsWidget_eventCommon_FormatNumber_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShipStatsWidget_Common_FormatNumber()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipStatsWidget_Common_FormatNumber_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShipStatsWidget::execCommon_FormatNumber)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->Common_FormatNumber(Z_Param_Value);
	P_NATIVE_END;
}
// ********** End Class UShipStatsWidget Function Common_FormatNumber ******************************

// ********** Begin Class UShipStatsWidget Function Common_GetAverageResistance ********************
struct Z_Construct_UFunction_UShipStatsWidget_Common_GetAverageResistance_Statics
{
	struct ShipStatsWidget_eventCommon_GetAverageResistance_Parms
	{
		FCosmosDefenseLayer Layer;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Get average resistance across all damage types\n     */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get average resistance across all damage types" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Layer_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Layer;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UShipStatsWidget_Common_GetAverageResistance_Statics::NewProp_Layer = { "Layer", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatsWidget_eventCommon_GetAverageResistance_Parms, Layer), Z_Construct_UScriptStruct_FCosmosDefenseLayer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Layer_MetaData), NewProp_Layer_MetaData) }; // 3062971545
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UShipStatsWidget_Common_GetAverageResistance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatsWidget_eventCommon_GetAverageResistance_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShipStatsWidget_Common_GetAverageResistance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatsWidget_Common_GetAverageResistance_Statics::NewProp_Layer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatsWidget_Common_GetAverageResistance_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_Common_GetAverageResistance_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipStatsWidget_Common_GetAverageResistance_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipStatsWidget, nullptr, "Common_GetAverageResistance", Z_Construct_UFunction_UShipStatsWidget_Common_GetAverageResistance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_Common_GetAverageResistance_Statics::PropPointers), sizeof(Z_Construct_UFunction_UShipStatsWidget_Common_GetAverageResistance_Statics::ShipStatsWidget_eventCommon_GetAverageResistance_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_Common_GetAverageResistance_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipStatsWidget_Common_GetAverageResistance_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UShipStatsWidget_Common_GetAverageResistance_Statics::ShipStatsWidget_eventCommon_GetAverageResistance_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShipStatsWidget_Common_GetAverageResistance()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipStatsWidget_Common_GetAverageResistance_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShipStatsWidget::execCommon_GetAverageResistance)
{
	P_GET_STRUCT_REF(FCosmosDefenseLayer,Z_Param_Out_Layer);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->Common_GetAverageResistance(Z_Param_Out_Layer);
	P_NATIVE_END;
}
// ********** End Class UShipStatsWidget Function Common_GetAverageResistance **********************

// ********** Begin Class UShipStatsWidget Function Common_GetShipFittingInterface *****************
struct Z_Construct_UFunction_UShipStatsWidget_Common_GetShipFittingInterface_Statics
{
	struct ShipStatsWidget_eventCommon_GetShipFittingInterface_Parms
	{
		TScriptInterface<IShipFittingInterface> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Get ship fitting interface\n     */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get ship fitting interface" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FInterfacePropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UFunction_UShipStatsWidget_Common_GetShipFittingInterface_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0014000000000580, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatsWidget_eventCommon_GetShipFittingInterface_Parms, ReturnValue), Z_Construct_UClass_UShipFittingInterface_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShipStatsWidget_Common_GetShipFittingInterface_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatsWidget_Common_GetShipFittingInterface_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_Common_GetShipFittingInterface_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipStatsWidget_Common_GetShipFittingInterface_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipStatsWidget, nullptr, "Common_GetShipFittingInterface", Z_Construct_UFunction_UShipStatsWidget_Common_GetShipFittingInterface_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_Common_GetShipFittingInterface_Statics::PropPointers), sizeof(Z_Construct_UFunction_UShipStatsWidget_Common_GetShipFittingInterface_Statics::ShipStatsWidget_eventCommon_GetShipFittingInterface_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_Common_GetShipFittingInterface_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipStatsWidget_Common_GetShipFittingInterface_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UShipStatsWidget_Common_GetShipFittingInterface_Statics::ShipStatsWidget_eventCommon_GetShipFittingInterface_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShipStatsWidget_Common_GetShipFittingInterface()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipStatsWidget_Common_GetShipFittingInterface_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShipStatsWidget::execCommon_GetShipFittingInterface)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TScriptInterface<IShipFittingInterface>*)Z_Param__Result=P_THIS->Common_GetShipFittingInterface();
	P_NATIVE_END;
}
// ********** End Class UShipStatsWidget Function Common_GetShipFittingInterface *******************

// ********** Begin Class UShipStatsWidget Function OnStatsCalculated ******************************
struct ShipStatsWidget_eventOnStatsCalculated_Parms
{
	FCommon_ShipFittingData Stats;
};
static FName NAME_UShipStatsWidget_OnStatsCalculated = FName(TEXT("OnStatsCalculated"));
void UShipStatsWidget::OnStatsCalculated(FCommon_ShipFittingData const& Stats)
{
	ShipStatsWidget_eventOnStatsCalculated_Parms Parms;
	Parms.Stats=Stats;
	UFunction* Func = FindFunctionChecked(NAME_UShipStatsWidget_OnStatsCalculated);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UShipStatsWidget_OnStatsCalculated_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Stats|Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ============================================================================\n// EVENTS\n// ============================================================================\n" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "EVENTS" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Stats_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Stats;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UShipStatsWidget_OnStatsCalculated_Statics::NewProp_Stats = { "Stats", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipStatsWidget_eventOnStatsCalculated_Parms, Stats), Z_Construct_UScriptStruct_FCommon_ShipFittingData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Stats_MetaData), NewProp_Stats_MetaData) }; // 1329122485
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShipStatsWidget_OnStatsCalculated_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipStatsWidget_OnStatsCalculated_Statics::NewProp_Stats,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_OnStatsCalculated_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipStatsWidget_OnStatsCalculated_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipStatsWidget, nullptr, "OnStatsCalculated", Z_Construct_UFunction_UShipStatsWidget_OnStatsCalculated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_OnStatsCalculated_Statics::PropPointers), sizeof(ShipStatsWidget_eventOnStatsCalculated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipStatsWidget_OnStatsCalculated_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipStatsWidget_OnStatsCalculated_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ShipStatsWidget_eventOnStatsCalculated_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShipStatsWidget_OnStatsCalculated()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipStatsWidget_OnStatsCalculated_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UShipStatsWidget Function OnStatsCalculated ********************************

// ********** Begin Class UShipStatsWidget *********************************************************
void UShipStatsWidget::StaticRegisterNativesUShipStatsWidget()
{
	UClass* Class = UShipStatsWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ClientOnly_RefreshStats", &UShipStatsWidget::execClientOnly_RefreshStats },
		{ "ClientOnly_UpdateDPSDisplay", &UShipStatsWidget::execClientOnly_UpdateDPSDisplay },
		{ "ClientOnly_UpdateEHPDisplay", &UShipStatsWidget::execClientOnly_UpdateEHPDisplay },
		{ "ClientOnly_UpdateResistanceDisplay", &UShipStatsWidget::execClientOnly_UpdateResistanceDisplay },
		{ "ClientOnly_UpdateScanningDisplay", &UShipStatsWidget::execClientOnly_UpdateScanningDisplay },
		{ "ClientOnly_UpdateSpeedDisplay", &UShipStatsWidget::execClientOnly_UpdateSpeedDisplay },
		{ "Common_CalculateDPS", &UShipStatsWidget::execCommon_CalculateDPS },
		{ "Common_CalculateEffectiveHP", &UShipStatsWidget::execCommon_CalculateEffectiveHP },
		{ "Common_CalculateTotalStats", &UShipStatsWidget::execCommon_CalculateTotalStats },
		{ "Common_FormatNumber", &UShipStatsWidget::execCommon_FormatNumber },
		{ "Common_GetAverageResistance", &UShipStatsWidget::execCommon_GetAverageResistance },
		{ "Common_GetShipFittingInterface", &UShipStatsWidget::execCommon_GetShipFittingInterface },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UShipStatsWidget;
UClass* UShipStatsWidget::GetPrivateStaticClass()
{
	using TClass = UShipStatsWidget;
	if (!Z_Registration_Info_UClass_UShipStatsWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ShipStatsWidget"),
			Z_Registration_Info_UClass_UShipStatsWidget.InnerSingleton,
			StaticRegisterNativesUShipStatsWidget,
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
	return Z_Registration_Info_UClass_UShipStatsWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UShipStatsWidget_NoRegister()
{
	return UShipStatsWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UShipStatsWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AlphaDPSText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "ShipStatsWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ============================================================================\n// WIDGET REFERENCES\n// ============================================================================\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "WIDGET REFERENCES" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SustainedDPSText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "ShipStatsWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EffectiveHPText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "ShipStatsWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxSpeedText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "ShipStatsWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WarpSpeedText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "ShipStatsWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScanResolutionText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "ShipStatsWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SignatureRadiusText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "ShipStatsWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CapacitorText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "ShipStatsWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EMResistanceBar_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "ShipStatsWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Resistance bars\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Resistance bars" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EMResistanceText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "ShipStatsWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThermalResistanceBar_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "ShipStatsWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThermalResistanceText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "ShipStatsWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_KineticResistanceBar_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "ShipStatsWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_KineticResistanceText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "ShipStatsWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExplosiveResistanceBar_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "ShipStatsWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExplosiveResistanceText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "ShipStatsWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UpdateRate_MetaData[] = {
		{ "Category", "Ship Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ============================================================================\n// CONFIGURATION\n// ============================================================================\n" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "CONFIGURATION" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CachedPlayerController_MetaData[] = {
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CachedShipPawn_MetaData[] = {
		{ "ModuleRelativePath", "UI/Widgets/Fitting/ShipStatsWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AlphaDPSText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SustainedDPSText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EffectiveHPText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MaxSpeedText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WarpSpeedText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ScanResolutionText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SignatureRadiusText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CapacitorText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EMResistanceBar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EMResistanceText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ThermalResistanceBar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ThermalResistanceText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_KineticResistanceBar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_KineticResistanceText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ExplosiveResistanceBar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ExplosiveResistanceText;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_UpdateRate;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CachedPlayerController;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CachedShipPawn;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UShipStatsWidget_ClientOnly_RefreshStats, "ClientOnly_RefreshStats" }, // 395009056
		{ &Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateDPSDisplay, "ClientOnly_UpdateDPSDisplay" }, // 918213199
		{ &Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateEHPDisplay, "ClientOnly_UpdateEHPDisplay" }, // 514271177
		{ &Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateResistanceDisplay, "ClientOnly_UpdateResistanceDisplay" }, // 1930514230
		{ &Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateScanningDisplay, "ClientOnly_UpdateScanningDisplay" }, // 2489178683
		{ &Z_Construct_UFunction_UShipStatsWidget_ClientOnly_UpdateSpeedDisplay, "ClientOnly_UpdateSpeedDisplay" }, // 2717766176
		{ &Z_Construct_UFunction_UShipStatsWidget_Common_CalculateDPS, "Common_CalculateDPS" }, // 3399350715
		{ &Z_Construct_UFunction_UShipStatsWidget_Common_CalculateEffectiveHP, "Common_CalculateEffectiveHP" }, // 1452461173
		{ &Z_Construct_UFunction_UShipStatsWidget_Common_CalculateTotalStats, "Common_CalculateTotalStats" }, // 2030000156
		{ &Z_Construct_UFunction_UShipStatsWidget_Common_FormatNumber, "Common_FormatNumber" }, // 3927981984
		{ &Z_Construct_UFunction_UShipStatsWidget_Common_GetAverageResistance, "Common_GetAverageResistance" }, // 869628633
		{ &Z_Construct_UFunction_UShipStatsWidget_Common_GetShipFittingInterface, "Common_GetShipFittingInterface" }, // 1429156217
		{ &Z_Construct_UFunction_UShipStatsWidget_OnStatsCalculated, "OnStatsCalculated" }, // 3467186273
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UShipStatsWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_AlphaDPSText = { "AlphaDPSText", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatsWidget, AlphaDPSText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AlphaDPSText_MetaData), NewProp_AlphaDPSText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_SustainedDPSText = { "SustainedDPSText", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatsWidget, SustainedDPSText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SustainedDPSText_MetaData), NewProp_SustainedDPSText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_EffectiveHPText = { "EffectiveHPText", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatsWidget, EffectiveHPText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EffectiveHPText_MetaData), NewProp_EffectiveHPText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_MaxSpeedText = { "MaxSpeedText", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatsWidget, MaxSpeedText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxSpeedText_MetaData), NewProp_MaxSpeedText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_WarpSpeedText = { "WarpSpeedText", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatsWidget, WarpSpeedText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WarpSpeedText_MetaData), NewProp_WarpSpeedText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_ScanResolutionText = { "ScanResolutionText", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatsWidget, ScanResolutionText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScanResolutionText_MetaData), NewProp_ScanResolutionText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_SignatureRadiusText = { "SignatureRadiusText", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatsWidget, SignatureRadiusText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SignatureRadiusText_MetaData), NewProp_SignatureRadiusText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_CapacitorText = { "CapacitorText", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatsWidget, CapacitorText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CapacitorText_MetaData), NewProp_CapacitorText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_EMResistanceBar = { "EMResistanceBar", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatsWidget, EMResistanceBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EMResistanceBar_MetaData), NewProp_EMResistanceBar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_EMResistanceText = { "EMResistanceText", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatsWidget, EMResistanceText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EMResistanceText_MetaData), NewProp_EMResistanceText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_ThermalResistanceBar = { "ThermalResistanceBar", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatsWidget, ThermalResistanceBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThermalResistanceBar_MetaData), NewProp_ThermalResistanceBar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_ThermalResistanceText = { "ThermalResistanceText", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatsWidget, ThermalResistanceText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThermalResistanceText_MetaData), NewProp_ThermalResistanceText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_KineticResistanceBar = { "KineticResistanceBar", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatsWidget, KineticResistanceBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_KineticResistanceBar_MetaData), NewProp_KineticResistanceBar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_KineticResistanceText = { "KineticResistanceText", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatsWidget, KineticResistanceText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_KineticResistanceText_MetaData), NewProp_KineticResistanceText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_ExplosiveResistanceBar = { "ExplosiveResistanceBar", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatsWidget, ExplosiveResistanceBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExplosiveResistanceBar_MetaData), NewProp_ExplosiveResistanceBar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_ExplosiveResistanceText = { "ExplosiveResistanceText", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatsWidget, ExplosiveResistanceText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExplosiveResistanceText_MetaData), NewProp_ExplosiveResistanceText_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_UpdateRate = { "UpdateRate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatsWidget, UpdateRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UpdateRate_MetaData), NewProp_UpdateRate_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_CachedPlayerController = { "CachedPlayerController", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatsWidget, CachedPlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CachedPlayerController_MetaData), NewProp_CachedPlayerController_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_CachedShipPawn = { "CachedShipPawn", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UShipStatsWidget, CachedShipPawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CachedShipPawn_MetaData), NewProp_CachedShipPawn_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UShipStatsWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_AlphaDPSText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_SustainedDPSText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_EffectiveHPText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_MaxSpeedText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_WarpSpeedText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_ScanResolutionText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_SignatureRadiusText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_CapacitorText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_EMResistanceBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_EMResistanceText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_ThermalResistanceBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_ThermalResistanceText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_KineticResistanceBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_KineticResistanceText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_ExplosiveResistanceBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_ExplosiveResistanceText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_UpdateRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_CachedPlayerController,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UShipStatsWidget_Statics::NewProp_CachedShipPawn,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UShipStatsWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UShipStatsWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UShipStatsWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UShipStatsWidget_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UEquipmentObserver_NoRegister, (int32)VTABLE_OFFSET(UShipStatsWidget, IEquipmentObserver), false },  // 1124797909
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_UShipStatsWidget_Statics::ClassParams = {
	&UShipStatsWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UShipStatsWidget_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UShipStatsWidget_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UShipStatsWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UShipStatsWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UShipStatsWidget()
{
	if (!Z_Registration_Info_UClass_UShipStatsWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UShipStatsWidget.OuterSingleton, Z_Construct_UClass_UShipStatsWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UShipStatsWidget.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UShipStatsWidget);
UShipStatsWidget::~UShipStatsWidget() {}
// ********** End Class UShipStatsWidget ***********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ShipStatsWidget_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UShipStatsWidget, UShipStatsWidget::StaticClass, TEXT("UShipStatsWidget"), &Z_Registration_Info_UClass_UShipStatsWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UShipStatsWidget), 3741754986U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ShipStatsWidget_h__Script_Echoes_3279676525(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ShipStatsWidget_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_Fitting_ShipStatsWidget_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
