// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NavigationWidget.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeNavigationWidget() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ECHOES_API UClass* Z_Construct_UClass_UNavigationWidget();
ECHOES_API UClass* Z_Construct_UClass_UNavigationWidget_NoRegister();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_ENavigationCommand();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnNavigationCommandIssued__DelegateSignature();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
UMG_API UClass* Z_Construct_UClass_UImage_NoRegister();
UMG_API UClass* Z_Construct_UClass_UProgressBar_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum ENavigationCommand ********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ENavigationCommand;
static UEnum* ENavigationCommand_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ENavigationCommand.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ENavigationCommand.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Echoes_ENavigationCommand, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("ENavigationCommand"));
	}
	return Z_Registration_Info_UEnum_ENavigationCommand.OuterSingleton;
}
template<> ECHOES_API UEnum* StaticEnum<ENavigationCommand>()
{
	return ENavigationCommand_StaticEnum();
}
struct Z_Construct_UEnum_Echoes_ENavigationCommand_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "AlignTo.Comment", "/** Align ship to target direction */" },
		{ "AlignTo.DisplayName", "Align To" },
		{ "AlignTo.Name", "ENavigationCommand::AlignTo" },
		{ "AlignTo.ToolTip", "Align ship to target direction" },
		{ "Approach.Comment", "/** Approach target */" },
		{ "Approach.DisplayName", "Approach" },
		{ "Approach.Name", "ENavigationCommand::Approach" },
		{ "Approach.ToolTip", "Approach target" },
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * ENavigationCommand\n * \n * Navigation commands that can be issued to ship\n */" },
#endif
		{ "KeepAtRange.Comment", "/** Keep at range from target */" },
		{ "KeepAtRange.DisplayName", "Keep At Range" },
		{ "KeepAtRange.Name", "ENavigationCommand::KeepAtRange" },
		{ "KeepAtRange.ToolTip", "Keep at range from target" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
		{ "Orbit.Comment", "/** Orbit around target at specified range */" },
		{ "Orbit.DisplayName", "Orbit" },
		{ "Orbit.Name", "ENavigationCommand::Orbit" },
		{ "Orbit.ToolTip", "Orbit around target at specified range" },
		{ "Stop.Comment", "/** Stop all movement */" },
		{ "Stop.DisplayName", "Stop" },
		{ "Stop.Name", "ENavigationCommand::Stop" },
		{ "Stop.ToolTip", "Stop all movement" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "ENavigationCommand\n\nNavigation commands that can be issued to ship" },
#endif
		{ "WarpTo.Comment", "/** Warp to target location */" },
		{ "WarpTo.DisplayName", "Warp To" },
		{ "WarpTo.Name", "ENavigationCommand::WarpTo" },
		{ "WarpTo.ToolTip", "Warp to target location" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ENavigationCommand::AlignTo", (int64)ENavigationCommand::AlignTo },
		{ "ENavigationCommand::Orbit", (int64)ENavigationCommand::Orbit },
		{ "ENavigationCommand::WarpTo", (int64)ENavigationCommand::WarpTo },
		{ "ENavigationCommand::Approach", (int64)ENavigationCommand::Approach },
		{ "ENavigationCommand::KeepAtRange", (int64)ENavigationCommand::KeepAtRange },
		{ "ENavigationCommand::Stop", (int64)ENavigationCommand::Stop },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Echoes_ENavigationCommand_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	"ENavigationCommand",
	"ENavigationCommand",
	Z_Construct_UEnum_Echoes_ENavigationCommand_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_ENavigationCommand_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_ENavigationCommand_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Echoes_ENavigationCommand_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Echoes_ENavigationCommand()
{
	if (!Z_Registration_Info_UEnum_ENavigationCommand.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ENavigationCommand.InnerSingleton, Z_Construct_UEnum_Echoes_ENavigationCommand_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ENavigationCommand.InnerSingleton;
}
// ********** End Enum ENavigationCommand **********************************************************

// ********** Begin Delegate FOnNavigationCommandIssued ********************************************
struct Z_Construct_UDelegateFunction_Echoes_OnNavigationCommandIssued__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnNavigationCommandIssued_Parms
	{
		ENavigationCommand Command;
		AActor* Target;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Delegate for navigation command issued\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegate for navigation command issued" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Command_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Command;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_Echoes_OnNavigationCommandIssued__DelegateSignature_Statics::NewProp_Command_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_Echoes_OnNavigationCommandIssued__DelegateSignature_Statics::NewProp_Command = { "Command", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnNavigationCommandIssued_Parms, Command), Z_Construct_UEnum_Echoes_ENavigationCommand, METADATA_PARAMS(0, nullptr) }; // 1547577227
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_Echoes_OnNavigationCommandIssued__DelegateSignature_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnNavigationCommandIssued_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnNavigationCommandIssued__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnNavigationCommandIssued__DelegateSignature_Statics::NewProp_Command_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnNavigationCommandIssued__DelegateSignature_Statics::NewProp_Command,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnNavigationCommandIssued__DelegateSignature_Statics::NewProp_Target,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnNavigationCommandIssued__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnNavigationCommandIssued__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnNavigationCommandIssued__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnNavigationCommandIssued__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnNavigationCommandIssued__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnNavigationCommandIssued__DelegateSignature_Statics::_Script_Echoes_eventOnNavigationCommandIssued_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnNavigationCommandIssued__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnNavigationCommandIssued__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnNavigationCommandIssued__DelegateSignature_Statics::_Script_Echoes_eventOnNavigationCommandIssued_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnNavigationCommandIssued__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnNavigationCommandIssued__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnNavigationCommandIssued_DelegateWrapper(const FMulticastScriptDelegate& OnNavigationCommandIssued, ENavigationCommand Command, AActor* Target)
{
	struct _Script_Echoes_eventOnNavigationCommandIssued_Parms
	{
		ENavigationCommand Command;
		AActor* Target;
	};
	_Script_Echoes_eventOnNavigationCommandIssued_Parms Parms;
	Parms.Command=Command;
	Parms.Target=Target;
	OnNavigationCommandIssued.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnNavigationCommandIssued **********************************************

// ********** Begin Class UNavigationWidget Function BindToShip ************************************
struct Z_Construct_UFunction_UNavigationWidget_BindToShip_Statics
{
	struct NavigationWidget_eventBindToShip_Parms
	{
		AActor* Ship;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Navigation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Bind to a ship for automatic updates\n * \n * @param Ship The ship actor\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Bind to a ship for automatic updates\n\n@param Ship The ship actor" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Ship;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UNavigationWidget_BindToShip_Statics::NewProp_Ship = { "Ship", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NavigationWidget_eventBindToShip_Parms, Ship), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UNavigationWidget_BindToShip_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNavigationWidget_BindToShip_Statics::NewProp_Ship,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UNavigationWidget_BindToShip_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UNavigationWidget_BindToShip_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UNavigationWidget, nullptr, "BindToShip", Z_Construct_UFunction_UNavigationWidget_BindToShip_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UNavigationWidget_BindToShip_Statics::PropPointers), sizeof(Z_Construct_UFunction_UNavigationWidget_BindToShip_Statics::NavigationWidget_eventBindToShip_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UNavigationWidget_BindToShip_Statics::Function_MetaDataParams), Z_Construct_UFunction_UNavigationWidget_BindToShip_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UNavigationWidget_BindToShip_Statics::NavigationWidget_eventBindToShip_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UNavigationWidget_BindToShip()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UNavigationWidget_BindToShip_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UNavigationWidget::execBindToShip)
{
	P_GET_OBJECT(AActor,Z_Param_Ship);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->BindToShip(Z_Param_Ship);
	P_NATIVE_END;
}
// ********** End Class UNavigationWidget Function BindToShip **************************************

// ********** Begin Class UNavigationWidget Function ClientOnly_RefreshDisplays ********************
struct Z_Construct_UFunction_UNavigationWidget_ClientOnly_RefreshDisplays_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Navigation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * CLIENT ONLY: Refresh all displays from bound ship\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "CLIENT ONLY: Refresh all displays from bound ship" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UNavigationWidget_ClientOnly_RefreshDisplays_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UNavigationWidget, nullptr, "ClientOnly_RefreshDisplays", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UNavigationWidget_ClientOnly_RefreshDisplays_Statics::Function_MetaDataParams), Z_Construct_UFunction_UNavigationWidget_ClientOnly_RefreshDisplays_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UNavigationWidget_ClientOnly_RefreshDisplays()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UNavigationWidget_ClientOnly_RefreshDisplays_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UNavigationWidget::execClientOnly_RefreshDisplays)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_RefreshDisplays();
	P_NATIVE_END;
}
// ********** End Class UNavigationWidget Function ClientOnly_RefreshDisplays **********************

// ********** Begin Class UNavigationWidget Function ClientOnly_UpdateSpeed ************************
struct Z_Construct_UFunction_UNavigationWidget_ClientOnly_UpdateSpeed_Statics
{
	struct NavigationWidget_eventClientOnly_UpdateSpeed_Parms
	{
		float CurrentSpeed;
		float MaxSpeed;
		FVector Velocity;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Navigation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * CLIENT ONLY: Update speed display\n * \n * @param CurrentSpeed Current speed in m/s\n * @param MaxSpeed Maximum speed in m/s\n * @param Velocity Current velocity vector\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "CLIENT ONLY: Update speed display\n\n@param CurrentSpeed Current speed in m/s\n@param MaxSpeed Maximum speed in m/s\n@param Velocity Current velocity vector" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxSpeed;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Velocity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UNavigationWidget_ClientOnly_UpdateSpeed_Statics::NewProp_CurrentSpeed = { "CurrentSpeed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NavigationWidget_eventClientOnly_UpdateSpeed_Parms, CurrentSpeed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UNavigationWidget_ClientOnly_UpdateSpeed_Statics::NewProp_MaxSpeed = { "MaxSpeed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NavigationWidget_eventClientOnly_UpdateSpeed_Parms, MaxSpeed), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UNavigationWidget_ClientOnly_UpdateSpeed_Statics::NewProp_Velocity = { "Velocity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NavigationWidget_eventClientOnly_UpdateSpeed_Parms, Velocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UNavigationWidget_ClientOnly_UpdateSpeed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNavigationWidget_ClientOnly_UpdateSpeed_Statics::NewProp_CurrentSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNavigationWidget_ClientOnly_UpdateSpeed_Statics::NewProp_MaxSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNavigationWidget_ClientOnly_UpdateSpeed_Statics::NewProp_Velocity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UNavigationWidget_ClientOnly_UpdateSpeed_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UNavigationWidget_ClientOnly_UpdateSpeed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UNavigationWidget, nullptr, "ClientOnly_UpdateSpeed", Z_Construct_UFunction_UNavigationWidget_ClientOnly_UpdateSpeed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UNavigationWidget_ClientOnly_UpdateSpeed_Statics::PropPointers), sizeof(Z_Construct_UFunction_UNavigationWidget_ClientOnly_UpdateSpeed_Statics::NavigationWidget_eventClientOnly_UpdateSpeed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UNavigationWidget_ClientOnly_UpdateSpeed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UNavigationWidget_ClientOnly_UpdateSpeed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UNavigationWidget_ClientOnly_UpdateSpeed_Statics::NavigationWidget_eventClientOnly_UpdateSpeed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UNavigationWidget_ClientOnly_UpdateSpeed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UNavigationWidget_ClientOnly_UpdateSpeed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UNavigationWidget::execClientOnly_UpdateSpeed)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_CurrentSpeed);
	P_GET_PROPERTY(FFloatProperty,Z_Param_MaxSpeed);
	P_GET_STRUCT(FVector,Z_Param_Velocity);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_UpdateSpeed(Z_Param_CurrentSpeed,Z_Param_MaxSpeed,Z_Param_Velocity);
	P_NATIVE_END;
}
// ********** End Class UNavigationWidget Function ClientOnly_UpdateSpeed **************************

// ********** Begin Class UNavigationWidget Function Common_FormatSpeed ****************************
struct Z_Construct_UFunction_UNavigationWidget_Common_FormatSpeed_Statics
{
	struct NavigationWidget_eventCommon_FormatSpeed_Parms
	{
		float SpeedInMps;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Navigation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * COMMON (Pure): Format speed value to string\n * \n * @param SpeedInMps Speed in meters per second\n * @return Formatted string (e.g., \"125 m/s\", \"2.5 km/s\")\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "COMMON (Pure): Format speed value to string\n\n@param SpeedInMps Speed in meters per second\n@return Formatted string (e.g., \"125 m/s\", \"2.5 km/s\")" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SpeedInMps;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UNavigationWidget_Common_FormatSpeed_Statics::NewProp_SpeedInMps = { "SpeedInMps", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NavigationWidget_eventCommon_FormatSpeed_Parms, SpeedInMps), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UNavigationWidget_Common_FormatSpeed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NavigationWidget_eventCommon_FormatSpeed_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UNavigationWidget_Common_FormatSpeed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNavigationWidget_Common_FormatSpeed_Statics::NewProp_SpeedInMps,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNavigationWidget_Common_FormatSpeed_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UNavigationWidget_Common_FormatSpeed_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UNavigationWidget_Common_FormatSpeed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UNavigationWidget, nullptr, "Common_FormatSpeed", Z_Construct_UFunction_UNavigationWidget_Common_FormatSpeed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UNavigationWidget_Common_FormatSpeed_Statics::PropPointers), sizeof(Z_Construct_UFunction_UNavigationWidget_Common_FormatSpeed_Statics::NavigationWidget_eventCommon_FormatSpeed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UNavigationWidget_Common_FormatSpeed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UNavigationWidget_Common_FormatSpeed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UNavigationWidget_Common_FormatSpeed_Statics::NavigationWidget_eventCommon_FormatSpeed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UNavigationWidget_Common_FormatSpeed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UNavigationWidget_Common_FormatSpeed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UNavigationWidget::execCommon_FormatSpeed)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_SpeedInMps);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UNavigationWidget::Common_FormatSpeed(Z_Param_SpeedInMps);
	P_NATIVE_END;
}
// ********** End Class UNavigationWidget Function Common_FormatSpeed ******************************

// ********** Begin Class UNavigationWidget Function Common_GetVelocityBearing *********************
struct Z_Construct_UFunction_UNavigationWidget_Common_GetVelocityBearing_Statics
{
	struct NavigationWidget_eventCommon_GetVelocityBearing_Parms
	{
		FVector Velocity;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Navigation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * COMMON (Pure): Get velocity direction as compass bearing\n * \n * @param Velocity Velocity vector\n * @return Bearing in degrees (0-360)\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "COMMON (Pure): Get velocity direction as compass bearing\n\n@param Velocity Velocity vector\n@return Bearing in degrees (0-360)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Velocity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UNavigationWidget_Common_GetVelocityBearing_Statics::NewProp_Velocity = { "Velocity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NavigationWidget_eventCommon_GetVelocityBearing_Parms, Velocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UNavigationWidget_Common_GetVelocityBearing_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NavigationWidget_eventCommon_GetVelocityBearing_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UNavigationWidget_Common_GetVelocityBearing_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNavigationWidget_Common_GetVelocityBearing_Statics::NewProp_Velocity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNavigationWidget_Common_GetVelocityBearing_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UNavigationWidget_Common_GetVelocityBearing_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UNavigationWidget_Common_GetVelocityBearing_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UNavigationWidget, nullptr, "Common_GetVelocityBearing", Z_Construct_UFunction_UNavigationWidget_Common_GetVelocityBearing_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UNavigationWidget_Common_GetVelocityBearing_Statics::PropPointers), sizeof(Z_Construct_UFunction_UNavigationWidget_Common_GetVelocityBearing_Statics::NavigationWidget_eventCommon_GetVelocityBearing_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14822401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UNavigationWidget_Common_GetVelocityBearing_Statics::Function_MetaDataParams), Z_Construct_UFunction_UNavigationWidget_Common_GetVelocityBearing_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UNavigationWidget_Common_GetVelocityBearing_Statics::NavigationWidget_eventCommon_GetVelocityBearing_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UNavigationWidget_Common_GetVelocityBearing()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UNavigationWidget_Common_GetVelocityBearing_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UNavigationWidget::execCommon_GetVelocityBearing)
{
	P_GET_STRUCT(FVector,Z_Param_Velocity);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=UNavigationWidget::Common_GetVelocityBearing(Z_Param_Velocity);
	P_NATIVE_END;
}
// ********** End Class UNavigationWidget Function Common_GetVelocityBearing ***********************

// ********** Begin Class UNavigationWidget Function HandleAlignToClicked **************************
struct Z_Construct_UFunction_UNavigationWidget_HandleAlignToClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ==================== Button Click Handlers ====================\n" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "==================== Button Click Handlers ====================" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UNavigationWidget_HandleAlignToClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UNavigationWidget, nullptr, "HandleAlignToClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UNavigationWidget_HandleAlignToClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UNavigationWidget_HandleAlignToClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UNavigationWidget_HandleAlignToClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UNavigationWidget_HandleAlignToClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UNavigationWidget::execHandleAlignToClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleAlignToClicked();
	P_NATIVE_END;
}
// ********** End Class UNavigationWidget Function HandleAlignToClicked ****************************

// ********** Begin Class UNavigationWidget Function HandleApproachClicked *************************
struct Z_Construct_UFunction_UNavigationWidget_HandleApproachClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UNavigationWidget_HandleApproachClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UNavigationWidget, nullptr, "HandleApproachClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UNavigationWidget_HandleApproachClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UNavigationWidget_HandleApproachClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UNavigationWidget_HandleApproachClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UNavigationWidget_HandleApproachClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UNavigationWidget::execHandleApproachClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleApproachClicked();
	P_NATIVE_END;
}
// ********** End Class UNavigationWidget Function HandleApproachClicked ***************************

// ********** Begin Class UNavigationWidget Function HandleKeepAtRangeClicked **********************
struct Z_Construct_UFunction_UNavigationWidget_HandleKeepAtRangeClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UNavigationWidget_HandleKeepAtRangeClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UNavigationWidget, nullptr, "HandleKeepAtRangeClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UNavigationWidget_HandleKeepAtRangeClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UNavigationWidget_HandleKeepAtRangeClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UNavigationWidget_HandleKeepAtRangeClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UNavigationWidget_HandleKeepAtRangeClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UNavigationWidget::execHandleKeepAtRangeClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleKeepAtRangeClicked();
	P_NATIVE_END;
}
// ********** End Class UNavigationWidget Function HandleKeepAtRangeClicked ************************

// ********** Begin Class UNavigationWidget Function HandleOrbitClicked ****************************
struct Z_Construct_UFunction_UNavigationWidget_HandleOrbitClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UNavigationWidget_HandleOrbitClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UNavigationWidget, nullptr, "HandleOrbitClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UNavigationWidget_HandleOrbitClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UNavigationWidget_HandleOrbitClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UNavigationWidget_HandleOrbitClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UNavigationWidget_HandleOrbitClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UNavigationWidget::execHandleOrbitClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleOrbitClicked();
	P_NATIVE_END;
}
// ********** End Class UNavigationWidget Function HandleOrbitClicked ******************************

// ********** Begin Class UNavigationWidget Function HandlePeriodicUpdate **************************
struct Z_Construct_UFunction_UNavigationWidget_HandlePeriodicUpdate_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Periodic update function called by timer\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Periodic update function called by timer" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UNavigationWidget_HandlePeriodicUpdate_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UNavigationWidget, nullptr, "HandlePeriodicUpdate", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UNavigationWidget_HandlePeriodicUpdate_Statics::Function_MetaDataParams), Z_Construct_UFunction_UNavigationWidget_HandlePeriodicUpdate_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UNavigationWidget_HandlePeriodicUpdate()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UNavigationWidget_HandlePeriodicUpdate_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UNavigationWidget::execHandlePeriodicUpdate)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandlePeriodicUpdate();
	P_NATIVE_END;
}
// ********** End Class UNavigationWidget Function HandlePeriodicUpdate ****************************

// ********** Begin Class UNavigationWidget Function HandleStopClicked *****************************
struct Z_Construct_UFunction_UNavigationWidget_HandleStopClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UNavigationWidget_HandleStopClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UNavigationWidget, nullptr, "HandleStopClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UNavigationWidget_HandleStopClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UNavigationWidget_HandleStopClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UNavigationWidget_HandleStopClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UNavigationWidget_HandleStopClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UNavigationWidget::execHandleStopClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleStopClicked();
	P_NATIVE_END;
}
// ********** End Class UNavigationWidget Function HandleStopClicked *******************************

// ********** Begin Class UNavigationWidget Function HandleWarpToClicked ***************************
struct Z_Construct_UFunction_UNavigationWidget_HandleWarpToClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UNavigationWidget_HandleWarpToClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UNavigationWidget, nullptr, "HandleWarpToClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UNavigationWidget_HandleWarpToClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UNavigationWidget_HandleWarpToClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UNavigationWidget_HandleWarpToClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UNavigationWidget_HandleWarpToClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UNavigationWidget::execHandleWarpToClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleWarpToClicked();
	P_NATIVE_END;
}
// ********** End Class UNavigationWidget Function HandleWarpToClicked *****************************

// ********** Begin Class UNavigationWidget Function OnNavigationCommandExecuted *******************
struct NavigationWidget_eventOnNavigationCommandExecuted_Parms
{
	ENavigationCommand Command;
	AActor* Target;
};
static FName NAME_UNavigationWidget_OnNavigationCommandExecuted = FName(TEXT("OnNavigationCommandExecuted"));
void UNavigationWidget::OnNavigationCommandExecuted(ENavigationCommand Command, AActor* Target)
{
	NavigationWidget_eventOnNavigationCommandExecuted_Parms Parms;
	Parms.Command=Command;
	Parms.Target=Target;
	UFunction* Func = FindFunctionChecked(NAME_UNavigationWidget_OnNavigationCommandExecuted);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UNavigationWidget_OnNavigationCommandExecuted_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Navigation Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Blueprint event called when command is issued\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint event called when command is issued" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_Command_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Command;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UNavigationWidget_OnNavigationCommandExecuted_Statics::NewProp_Command_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UNavigationWidget_OnNavigationCommandExecuted_Statics::NewProp_Command = { "Command", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NavigationWidget_eventOnNavigationCommandExecuted_Parms, Command), Z_Construct_UEnum_Echoes_ENavigationCommand, METADATA_PARAMS(0, nullptr) }; // 1547577227
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UNavigationWidget_OnNavigationCommandExecuted_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NavigationWidget_eventOnNavigationCommandExecuted_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UNavigationWidget_OnNavigationCommandExecuted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNavigationWidget_OnNavigationCommandExecuted_Statics::NewProp_Command_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNavigationWidget_OnNavigationCommandExecuted_Statics::NewProp_Command,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNavigationWidget_OnNavigationCommandExecuted_Statics::NewProp_Target,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UNavigationWidget_OnNavigationCommandExecuted_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UNavigationWidget_OnNavigationCommandExecuted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UNavigationWidget, nullptr, "OnNavigationCommandExecuted", Z_Construct_UFunction_UNavigationWidget_OnNavigationCommandExecuted_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UNavigationWidget_OnNavigationCommandExecuted_Statics::PropPointers), sizeof(NavigationWidget_eventOnNavigationCommandExecuted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UNavigationWidget_OnNavigationCommandExecuted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UNavigationWidget_OnNavigationCommandExecuted_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(NavigationWidget_eventOnNavigationCommandExecuted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UNavigationWidget_OnNavigationCommandExecuted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UNavigationWidget_OnNavigationCommandExecuted_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UNavigationWidget Function OnNavigationCommandExecuted *********************

// ********** Begin Class UNavigationWidget Function ServerRPC_ExecuteNavCommand *******************
struct Z_Construct_UFunction_UNavigationWidget_ServerRPC_ExecuteNavCommand_Statics
{
	struct NavigationWidget_eventServerRPC_ExecuteNavCommand_Parms
	{
		ENavigationCommand CommandType;
		AActor* Target;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AutoCreateRefTerm", "Target" },
		{ "Category", "Navigation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * SERVER RPC: Execute navigation command\n * \n * @param CommandType The navigation command to execute\n * @param Target The target for the command (can be null for Stop)\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "SERVER RPC: Execute navigation command\n\n@param CommandType The navigation command to execute\n@param Target The target for the command (can be null for Stop)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_CommandType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CommandType;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UNavigationWidget_ServerRPC_ExecuteNavCommand_Statics::NewProp_CommandType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UNavigationWidget_ServerRPC_ExecuteNavCommand_Statics::NewProp_CommandType = { "CommandType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NavigationWidget_eventServerRPC_ExecuteNavCommand_Parms, CommandType), Z_Construct_UEnum_Echoes_ENavigationCommand, METADATA_PARAMS(0, nullptr) }; // 1547577227
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UNavigationWidget_ServerRPC_ExecuteNavCommand_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NavigationWidget_eventServerRPC_ExecuteNavCommand_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UNavigationWidget_ServerRPC_ExecuteNavCommand_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNavigationWidget_ServerRPC_ExecuteNavCommand_Statics::NewProp_CommandType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNavigationWidget_ServerRPC_ExecuteNavCommand_Statics::NewProp_CommandType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNavigationWidget_ServerRPC_ExecuteNavCommand_Statics::NewProp_Target,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UNavigationWidget_ServerRPC_ExecuteNavCommand_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UNavigationWidget_ServerRPC_ExecuteNavCommand_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UNavigationWidget, nullptr, "ServerRPC_ExecuteNavCommand", Z_Construct_UFunction_UNavigationWidget_ServerRPC_ExecuteNavCommand_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UNavigationWidget_ServerRPC_ExecuteNavCommand_Statics::PropPointers), sizeof(Z_Construct_UFunction_UNavigationWidget_ServerRPC_ExecuteNavCommand_Statics::NavigationWidget_eventServerRPC_ExecuteNavCommand_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UNavigationWidget_ServerRPC_ExecuteNavCommand_Statics::Function_MetaDataParams), Z_Construct_UFunction_UNavigationWidget_ServerRPC_ExecuteNavCommand_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UNavigationWidget_ServerRPC_ExecuteNavCommand_Statics::NavigationWidget_eventServerRPC_ExecuteNavCommand_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UNavigationWidget_ServerRPC_ExecuteNavCommand()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UNavigationWidget_ServerRPC_ExecuteNavCommand_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UNavigationWidget::execServerRPC_ExecuteNavCommand)
{
	P_GET_ENUM(ENavigationCommand,Z_Param_CommandType);
	P_GET_OBJECT(AActor,Z_Param_Target);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerRPC_ExecuteNavCommand(ENavigationCommand(Z_Param_CommandType),Z_Param_Target);
	P_NATIVE_END;
}
// ********** End Class UNavigationWidget Function ServerRPC_ExecuteNavCommand *********************

// ********** Begin Class UNavigationWidget Function SetNavigationTarget ***************************
struct Z_Construct_UFunction_UNavigationWidget_SetNavigationTarget_Statics
{
	struct NavigationWidget_eventSetNavigationTarget_Parms
	{
		AActor* Target;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Navigation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Set the current navigation target\n * \n * @param Target The target actor for navigation commands\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set the current navigation target\n\n@param Target The target actor for navigation commands" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UNavigationWidget_SetNavigationTarget_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(NavigationWidget_eventSetNavigationTarget_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UNavigationWidget_SetNavigationTarget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UNavigationWidget_SetNavigationTarget_Statics::NewProp_Target,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UNavigationWidget_SetNavigationTarget_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UNavigationWidget_SetNavigationTarget_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UNavigationWidget, nullptr, "SetNavigationTarget", Z_Construct_UFunction_UNavigationWidget_SetNavigationTarget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UNavigationWidget_SetNavigationTarget_Statics::PropPointers), sizeof(Z_Construct_UFunction_UNavigationWidget_SetNavigationTarget_Statics::NavigationWidget_eventSetNavigationTarget_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UNavigationWidget_SetNavigationTarget_Statics::Function_MetaDataParams), Z_Construct_UFunction_UNavigationWidget_SetNavigationTarget_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UNavigationWidget_SetNavigationTarget_Statics::NavigationWidget_eventSetNavigationTarget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UNavigationWidget_SetNavigationTarget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UNavigationWidget_SetNavigationTarget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UNavigationWidget::execSetNavigationTarget)
{
	P_GET_OBJECT(AActor,Z_Param_Target);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetNavigationTarget(Z_Param_Target);
	P_NATIVE_END;
}
// ********** End Class UNavigationWidget Function SetNavigationTarget *****************************

// ********** Begin Class UNavigationWidget Function UnbindFromShip ********************************
struct Z_Construct_UFunction_UNavigationWidget_UnbindFromShip_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Navigation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Unbind from current ship\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Unbind from current ship" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UNavigationWidget_UnbindFromShip_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UNavigationWidget, nullptr, "UnbindFromShip", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UNavigationWidget_UnbindFromShip_Statics::Function_MetaDataParams), Z_Construct_UFunction_UNavigationWidget_UnbindFromShip_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UNavigationWidget_UnbindFromShip()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UNavigationWidget_UnbindFromShip_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UNavigationWidget::execUnbindFromShip)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UnbindFromShip();
	P_NATIVE_END;
}
// ********** End Class UNavigationWidget Function UnbindFromShip **********************************

// ********** Begin Class UNavigationWidget ********************************************************
void UNavigationWidget::StaticRegisterNativesUNavigationWidget()
{
	UClass* Class = UNavigationWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "BindToShip", &UNavigationWidget::execBindToShip },
		{ "ClientOnly_RefreshDisplays", &UNavigationWidget::execClientOnly_RefreshDisplays },
		{ "ClientOnly_UpdateSpeed", &UNavigationWidget::execClientOnly_UpdateSpeed },
		{ "Common_FormatSpeed", &UNavigationWidget::execCommon_FormatSpeed },
		{ "Common_GetVelocityBearing", &UNavigationWidget::execCommon_GetVelocityBearing },
		{ "HandleAlignToClicked", &UNavigationWidget::execHandleAlignToClicked },
		{ "HandleApproachClicked", &UNavigationWidget::execHandleApproachClicked },
		{ "HandleKeepAtRangeClicked", &UNavigationWidget::execHandleKeepAtRangeClicked },
		{ "HandleOrbitClicked", &UNavigationWidget::execHandleOrbitClicked },
		{ "HandlePeriodicUpdate", &UNavigationWidget::execHandlePeriodicUpdate },
		{ "HandleStopClicked", &UNavigationWidget::execHandleStopClicked },
		{ "HandleWarpToClicked", &UNavigationWidget::execHandleWarpToClicked },
		{ "ServerRPC_ExecuteNavCommand", &UNavigationWidget::execServerRPC_ExecuteNavCommand },
		{ "SetNavigationTarget", &UNavigationWidget::execSetNavigationTarget },
		{ "UnbindFromShip", &UNavigationWidget::execUnbindFromShip },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UNavigationWidget;
UClass* UNavigationWidget::GetPrivateStaticClass()
{
	using TClass = UNavigationWidget;
	if (!Z_Registration_Info_UClass_UNavigationWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("NavigationWidget"),
			Z_Registration_Info_UClass_UNavigationWidget.InnerSingleton,
			StaticRegisterNativesUNavigationWidget,
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
	return Z_Registration_Info_UClass_UNavigationWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UNavigationWidget_NoRegister()
{
	return UNavigationWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UNavigationWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UNavigationWidget\n * \n * Navigation and speed display widget\n * Shows current speed, velocity vector, and navigation commands\n * \n * Features:\n * - Speedometer with current/max speed\n * - Velocity vector display\n * - Navigation command buttons (Align, Orbit, Warp, etc.)\n * - ServerRPC commands for ship control\n * - Event-driven updates\n * \n * Usage:\n * NavigationWidget->BindToShip(PlayerShip);\n * NavigationWidget->SetTarget(TargetActor);\n */" },
#endif
		{ "IncludePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UNavigationWidget\n\nNavigation and speed display widget\nShows current speed, velocity vector, and navigation commands\n\nFeatures:\n- Speedometer with current/max speed\n- Velocity vector display\n- Navigation command buttons (Align, Orbit, Warp, etc.)\n- ServerRPC commands for ship control\n- Event-driven updates\n\nUsage:\nNavigationWidget->BindToShip(PlayerShip);\nNavigationWidget->SetTarget(TargetActor);" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCommandIssued_MetaData[] = {
		{ "Category", "Navigation Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when a navigation command is issued */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when a navigation command is issued" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeedText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "NavigationWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Speed value text (large display) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Speed value text (large display)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxSpeedText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "NavigationWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Max speed text */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Max speed text" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeedBar_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "NavigationWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Speed progress bar (0 to max speed) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Speed progress bar (0 to max speed)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VelocityArrow_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "NavigationWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Velocity direction indicator (arrow/compass) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Velocity direction indicator (arrow/compass)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VelocityText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "NavigationWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Velocity magnitude text */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Velocity magnitude text" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AlignToButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "NavigationWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Align To button */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Align To button" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OrbitButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "NavigationWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Orbit button */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Orbit button" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WarpToButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "NavigationWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Warp To button */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Warp To button" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ApproachButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "NavigationWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Approach button */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Approach button" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_KeepAtRangeButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "NavigationWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Keep At Range button */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Keep At Range button" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StopButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "NavigationWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Stop button */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stop button" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UpdateInterval_MetaData[] = {
		{ "Category", "Navigation Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Update interval for speed display (seconds) */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Update interval for speed display (seconds)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShowVelocityVector_MetaData[] = {
		{ "Category", "Navigation Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Enable velocity vector display */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enable velocity vector display" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoundShip_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current bound ship */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current bound ship" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentTarget_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current navigation target */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current navigation target" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentSpeed_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current speed (for caching) */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current speed (for caching)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentMaxSpeed_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current max speed (for caching) */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current max speed (for caching)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentVelocity_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current velocity (for caching) */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/NavigationWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current velocity (for caching)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCommandIssued;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpeedText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MaxSpeedText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpeedBar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_VelocityArrow;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_VelocityText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AlignToButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OrbitButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WarpToButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ApproachButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_KeepAtRangeButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StopButton;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_UpdateInterval;
	static void NewProp_bShowVelocityVector_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowVelocityVector;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BoundShip;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentTarget;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentMaxSpeed;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentVelocity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UNavigationWidget_BindToShip, "BindToShip" }, // 1101215407
		{ &Z_Construct_UFunction_UNavigationWidget_ClientOnly_RefreshDisplays, "ClientOnly_RefreshDisplays" }, // 2397937660
		{ &Z_Construct_UFunction_UNavigationWidget_ClientOnly_UpdateSpeed, "ClientOnly_UpdateSpeed" }, // 511496197
		{ &Z_Construct_UFunction_UNavigationWidget_Common_FormatSpeed, "Common_FormatSpeed" }, // 3672445338
		{ &Z_Construct_UFunction_UNavigationWidget_Common_GetVelocityBearing, "Common_GetVelocityBearing" }, // 4000378515
		{ &Z_Construct_UFunction_UNavigationWidget_HandleAlignToClicked, "HandleAlignToClicked" }, // 2247355514
		{ &Z_Construct_UFunction_UNavigationWidget_HandleApproachClicked, "HandleApproachClicked" }, // 636456705
		{ &Z_Construct_UFunction_UNavigationWidget_HandleKeepAtRangeClicked, "HandleKeepAtRangeClicked" }, // 273635055
		{ &Z_Construct_UFunction_UNavigationWidget_HandleOrbitClicked, "HandleOrbitClicked" }, // 612288481
		{ &Z_Construct_UFunction_UNavigationWidget_HandlePeriodicUpdate, "HandlePeriodicUpdate" }, // 3499883743
		{ &Z_Construct_UFunction_UNavigationWidget_HandleStopClicked, "HandleStopClicked" }, // 1373958983
		{ &Z_Construct_UFunction_UNavigationWidget_HandleWarpToClicked, "HandleWarpToClicked" }, // 2281060977
		{ &Z_Construct_UFunction_UNavigationWidget_OnNavigationCommandExecuted, "OnNavigationCommandExecuted" }, // 3162398110
		{ &Z_Construct_UFunction_UNavigationWidget_ServerRPC_ExecuteNavCommand, "ServerRPC_ExecuteNavCommand" }, // 735619325
		{ &Z_Construct_UFunction_UNavigationWidget_SetNavigationTarget, "SetNavigationTarget" }, // 2368426122
		{ &Z_Construct_UFunction_UNavigationWidget_UnbindFromShip, "UnbindFromShip" }, // 198404838
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UNavigationWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UNavigationWidget_Statics::NewProp_OnCommandIssued = { "OnCommandIssued", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNavigationWidget, OnCommandIssued), Z_Construct_UDelegateFunction_Echoes_OnNavigationCommandIssued__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCommandIssued_MetaData), NewProp_OnCommandIssued_MetaData) }; // 2150576720
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UNavigationWidget_Statics::NewProp_SpeedText = { "SpeedText", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNavigationWidget, SpeedText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeedText_MetaData), NewProp_SpeedText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UNavigationWidget_Statics::NewProp_MaxSpeedText = { "MaxSpeedText", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNavigationWidget, MaxSpeedText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxSpeedText_MetaData), NewProp_MaxSpeedText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UNavigationWidget_Statics::NewProp_SpeedBar = { "SpeedBar", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNavigationWidget, SpeedBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeedBar_MetaData), NewProp_SpeedBar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UNavigationWidget_Statics::NewProp_VelocityArrow = { "VelocityArrow", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNavigationWidget, VelocityArrow), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VelocityArrow_MetaData), NewProp_VelocityArrow_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UNavigationWidget_Statics::NewProp_VelocityText = { "VelocityText", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNavigationWidget, VelocityText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VelocityText_MetaData), NewProp_VelocityText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UNavigationWidget_Statics::NewProp_AlignToButton = { "AlignToButton", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNavigationWidget, AlignToButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AlignToButton_MetaData), NewProp_AlignToButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UNavigationWidget_Statics::NewProp_OrbitButton = { "OrbitButton", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNavigationWidget, OrbitButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OrbitButton_MetaData), NewProp_OrbitButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UNavigationWidget_Statics::NewProp_WarpToButton = { "WarpToButton", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNavigationWidget, WarpToButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WarpToButton_MetaData), NewProp_WarpToButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UNavigationWidget_Statics::NewProp_ApproachButton = { "ApproachButton", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNavigationWidget, ApproachButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ApproachButton_MetaData), NewProp_ApproachButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UNavigationWidget_Statics::NewProp_KeepAtRangeButton = { "KeepAtRangeButton", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNavigationWidget, KeepAtRangeButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_KeepAtRangeButton_MetaData), NewProp_KeepAtRangeButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UNavigationWidget_Statics::NewProp_StopButton = { "StopButton", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNavigationWidget, StopButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StopButton_MetaData), NewProp_StopButton_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UNavigationWidget_Statics::NewProp_UpdateInterval = { "UpdateInterval", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNavigationWidget, UpdateInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UpdateInterval_MetaData), NewProp_UpdateInterval_MetaData) };
void Z_Construct_UClass_UNavigationWidget_Statics::NewProp_bShowVelocityVector_SetBit(void* Obj)
{
	((UNavigationWidget*)Obj)->bShowVelocityVector = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UNavigationWidget_Statics::NewProp_bShowVelocityVector = { "bShowVelocityVector", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UNavigationWidget), &Z_Construct_UClass_UNavigationWidget_Statics::NewProp_bShowVelocityVector_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShowVelocityVector_MetaData), NewProp_bShowVelocityVector_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UNavigationWidget_Statics::NewProp_BoundShip = { "BoundShip", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNavigationWidget, BoundShip), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoundShip_MetaData), NewProp_BoundShip_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UNavigationWidget_Statics::NewProp_CurrentTarget = { "CurrentTarget", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNavigationWidget, CurrentTarget), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentTarget_MetaData), NewProp_CurrentTarget_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UNavigationWidget_Statics::NewProp_CurrentSpeed = { "CurrentSpeed", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNavigationWidget, CurrentSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentSpeed_MetaData), NewProp_CurrentSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UNavigationWidget_Statics::NewProp_CurrentMaxSpeed = { "CurrentMaxSpeed", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNavigationWidget, CurrentMaxSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentMaxSpeed_MetaData), NewProp_CurrentMaxSpeed_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UNavigationWidget_Statics::NewProp_CurrentVelocity = { "CurrentVelocity", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UNavigationWidget, CurrentVelocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentVelocity_MetaData), NewProp_CurrentVelocity_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UNavigationWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNavigationWidget_Statics::NewProp_OnCommandIssued,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNavigationWidget_Statics::NewProp_SpeedText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNavigationWidget_Statics::NewProp_MaxSpeedText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNavigationWidget_Statics::NewProp_SpeedBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNavigationWidget_Statics::NewProp_VelocityArrow,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNavigationWidget_Statics::NewProp_VelocityText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNavigationWidget_Statics::NewProp_AlignToButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNavigationWidget_Statics::NewProp_OrbitButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNavigationWidget_Statics::NewProp_WarpToButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNavigationWidget_Statics::NewProp_ApproachButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNavigationWidget_Statics::NewProp_KeepAtRangeButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNavigationWidget_Statics::NewProp_StopButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNavigationWidget_Statics::NewProp_UpdateInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNavigationWidget_Statics::NewProp_bShowVelocityVector,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNavigationWidget_Statics::NewProp_BoundShip,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNavigationWidget_Statics::NewProp_CurrentTarget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNavigationWidget_Statics::NewProp_CurrentSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNavigationWidget_Statics::NewProp_CurrentMaxSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UNavigationWidget_Statics::NewProp_CurrentVelocity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNavigationWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UNavigationWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UNavigationWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UNavigationWidget_Statics::ClassParams = {
	&UNavigationWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UNavigationWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UNavigationWidget_Statics::PropPointers),
	0,
	0x00B010A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UNavigationWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UNavigationWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UNavigationWidget()
{
	if (!Z_Registration_Info_UClass_UNavigationWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UNavigationWidget.OuterSingleton, Z_Construct_UClass_UNavigationWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UNavigationWidget.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UNavigationWidget);
UNavigationWidget::~UNavigationWidget() {}
// ********** End Class UNavigationWidget **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_NavigationWidget_h__Script_Echoes_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ENavigationCommand_StaticEnum, TEXT("ENavigationCommand"), &Z_Registration_Info_UEnum_ENavigationCommand, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1547577227U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UNavigationWidget, UNavigationWidget::StaticClass, TEXT("UNavigationWidget"), &Z_Registration_Info_UClass_UNavigationWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UNavigationWidget), 2680717206U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_NavigationWidget_h__Script_Echoes_4215986418(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_NavigationWidget_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_NavigationWidget_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_NavigationWidget_h__Script_Echoes_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_NavigationWidget_h__Script_Echoes_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
