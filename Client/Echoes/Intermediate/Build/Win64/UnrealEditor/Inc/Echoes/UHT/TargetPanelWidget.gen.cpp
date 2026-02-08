// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TargetPanelWidget.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeTargetPanelWidget() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ECHOES_API UClass* Z_Construct_UClass_UTargetingComponent_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UTargetItemWidget();
ECHOES_API UClass* Z_Construct_UClass_UTargetItemWidget_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UTargetPanelWidget();
ECHOES_API UClass* Z_Construct_UClass_UTargetPanelWidget_NoRegister();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_ETargetLockState();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnTargetSelected__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnTargetStateChanged__DelegateSignature();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FTargetPanelData();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
UMG_API UClass* Z_Construct_UClass_UCircularThrobber_NoRegister();
UMG_API UClass* Z_Construct_UClass_UProgressBar_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UMG_API UClass* Z_Construct_UClass_UVerticalBox_NoRegister();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FTargetPanelData **************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FTargetPanelData;
class UScriptStruct* FTargetPanelData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FTargetPanelData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FTargetPanelData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FTargetPanelData, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("TargetPanelData"));
	}
	return Z_Registration_Info_UScriptStruct_FTargetPanelData.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FTargetPanelData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * FTargetPanelData\n * \n * Data structure for a single target in the target panel\n * Contains lock progress and target health information\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "FTargetPanelData\n\nData structure for a single target in the target panel\nContains lock progress and target health information" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetActor_MetaData[] = {
		{ "Category", "Target Panel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Target actor reference */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Target actor reference" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetName_MetaData[] = {
		{ "Category", "Target Panel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Target name/label */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Target name/label" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LockState_MetaData[] = {
		{ "Category", "Target Panel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Lock state */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lock state" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LockProgress_MetaData[] = {
		{ "Category", "Target Panel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Lock progress (0.0 to 1.0) */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lock progress (0.0 to 1.0)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShieldPct_MetaData[] = {
		{ "Category", "Target Panel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shield percentage (0.0 to 1.0) */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shield percentage (0.0 to 1.0)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ArmorPct_MetaData[] = {
		{ "Category", "Target Panel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Armor percentage (0.0 to 1.0) */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Armor percentage (0.0 to 1.0)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HullPct_MetaData[] = {
		{ "Category", "Target Panel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Hull percentage (0.0 to 1.0) */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Hull percentage (0.0 to 1.0)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Distance_MetaData[] = {
		{ "Category", "Target Panel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Distance to target in cm */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Distance to target in cm" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetActor;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TargetName;
	static const UECodeGen_Private::FBytePropertyParams NewProp_LockState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_LockState;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LockProgress;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ShieldPct;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ArmorPct;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HullPct;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Distance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FTargetPanelData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FTargetPanelData_Statics::NewProp_TargetActor = { "TargetActor", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FTargetPanelData, TargetActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetActor_MetaData), NewProp_TargetActor_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FTargetPanelData_Statics::NewProp_TargetName = { "TargetName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FTargetPanelData, TargetName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetName_MetaData), NewProp_TargetName_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FTargetPanelData_Statics::NewProp_LockState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FTargetPanelData_Statics::NewProp_LockState = { "LockState", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FTargetPanelData, LockState), Z_Construct_UEnum_Echoes_ETargetLockState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LockState_MetaData), NewProp_LockState_MetaData) }; // 2896437216
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FTargetPanelData_Statics::NewProp_LockProgress = { "LockProgress", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FTargetPanelData, LockProgress), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LockProgress_MetaData), NewProp_LockProgress_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FTargetPanelData_Statics::NewProp_ShieldPct = { "ShieldPct", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FTargetPanelData, ShieldPct), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShieldPct_MetaData), NewProp_ShieldPct_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FTargetPanelData_Statics::NewProp_ArmorPct = { "ArmorPct", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FTargetPanelData, ArmorPct), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArmorPct_MetaData), NewProp_ArmorPct_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FTargetPanelData_Statics::NewProp_HullPct = { "HullPct", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FTargetPanelData, HullPct), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HullPct_MetaData), NewProp_HullPct_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FTargetPanelData_Statics::NewProp_Distance = { "Distance", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FTargetPanelData, Distance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Distance_MetaData), NewProp_Distance_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FTargetPanelData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTargetPanelData_Statics::NewProp_TargetActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTargetPanelData_Statics::NewProp_TargetName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTargetPanelData_Statics::NewProp_LockState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTargetPanelData_Statics::NewProp_LockState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTargetPanelData_Statics::NewProp_LockProgress,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTargetPanelData_Statics::NewProp_ShieldPct,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTargetPanelData_Statics::NewProp_ArmorPct,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTargetPanelData_Statics::NewProp_HullPct,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTargetPanelData_Statics::NewProp_Distance,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTargetPanelData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FTargetPanelData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"TargetPanelData",
	Z_Construct_UScriptStruct_FTargetPanelData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTargetPanelData_Statics::PropPointers),
	sizeof(FTargetPanelData),
	alignof(FTargetPanelData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTargetPanelData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FTargetPanelData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FTargetPanelData()
{
	if (!Z_Registration_Info_UScriptStruct_FTargetPanelData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FTargetPanelData.InnerSingleton, Z_Construct_UScriptStruct_FTargetPanelData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FTargetPanelData.InnerSingleton;
}
// ********** End ScriptStruct FTargetPanelData ****************************************************

// ********** Begin Delegate FOnTargetStateChanged *************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnTargetStateChanged__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnTargetStateChanged_Parms
	{
		AActor* Target;
		FTargetPanelData TargetData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Delegate for target state changed\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegate for target state changed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_Echoes_OnTargetStateChanged__DelegateSignature_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnTargetStateChanged_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Echoes_OnTargetStateChanged__DelegateSignature_Statics::NewProp_TargetData = { "TargetData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnTargetStateChanged_Parms, TargetData), Z_Construct_UScriptStruct_FTargetPanelData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetData_MetaData), NewProp_TargetData_MetaData) }; // 3323251151
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnTargetStateChanged__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnTargetStateChanged__DelegateSignature_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnTargetStateChanged__DelegateSignature_Statics::NewProp_TargetData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnTargetStateChanged__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnTargetStateChanged__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnTargetStateChanged__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnTargetStateChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnTargetStateChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnTargetStateChanged__DelegateSignature_Statics::_Script_Echoes_eventOnTargetStateChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnTargetStateChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnTargetStateChanged__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnTargetStateChanged__DelegateSignature_Statics::_Script_Echoes_eventOnTargetStateChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnTargetStateChanged__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnTargetStateChanged__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnTargetStateChanged_DelegateWrapper(const FMulticastScriptDelegate& OnTargetStateChanged, AActor* Target, FTargetPanelData const& TargetData)
{
	struct _Script_Echoes_eventOnTargetStateChanged_Parms
	{
		AActor* Target;
		FTargetPanelData TargetData;
	};
	_Script_Echoes_eventOnTargetStateChanged_Parms Parms;
	Parms.Target=Target;
	Parms.TargetData=TargetData;
	OnTargetStateChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnTargetStateChanged ***************************************************

// ********** Begin Delegate FOnTargetSelected *****************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnTargetSelected__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnTargetSelected_Parms
	{
		AActor* Target;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Delegate for target selected\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegate for target selected" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_Echoes_OnTargetSelected__DelegateSignature_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnTargetSelected_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnTargetSelected__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnTargetSelected__DelegateSignature_Statics::NewProp_Target,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnTargetSelected__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnTargetSelected__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnTargetSelected__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnTargetSelected__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnTargetSelected__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnTargetSelected__DelegateSignature_Statics::_Script_Echoes_eventOnTargetSelected_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnTargetSelected__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnTargetSelected__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnTargetSelected__DelegateSignature_Statics::_Script_Echoes_eventOnTargetSelected_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnTargetSelected__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnTargetSelected__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnTargetSelected_DelegateWrapper(const FMulticastScriptDelegate& OnTargetSelected, AActor* Target)
{
	struct _Script_Echoes_eventOnTargetSelected_Parms
	{
		AActor* Target;
	};
	_Script_Echoes_eventOnTargetSelected_Parms Parms;
	Parms.Target=Target;
	OnTargetSelected.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnTargetSelected *******************************************************

// ********** Begin Class UTargetItemWidget Function GetTargetActor ********************************
struct Z_Construct_UFunction_UTargetItemWidget_GetTargetActor_Statics
{
	struct TargetItemWidget_eventGetTargetActor_Parms
	{
		AActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Target Item" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Get the target actor reference\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the target actor reference" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTargetItemWidget_GetTargetActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetItemWidget_eventGetTargetActor_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTargetItemWidget_GetTargetActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetItemWidget_GetTargetActor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetItemWidget_GetTargetActor_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTargetItemWidget_GetTargetActor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTargetItemWidget, nullptr, "GetTargetActor", Z_Construct_UFunction_UTargetItemWidget_GetTargetActor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetItemWidget_GetTargetActor_Statics::PropPointers), sizeof(Z_Construct_UFunction_UTargetItemWidget_GetTargetActor_Statics::TargetItemWidget_eventGetTargetActor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetItemWidget_GetTargetActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTargetItemWidget_GetTargetActor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UTargetItemWidget_GetTargetActor_Statics::TargetItemWidget_eventGetTargetActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTargetItemWidget_GetTargetActor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTargetItemWidget_GetTargetActor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTargetItemWidget::execGetTargetActor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->GetTargetActor();
	P_NATIVE_END;
}
// ********** End Class UTargetItemWidget Function GetTargetActor **********************************

// ********** Begin Class UTargetItemWidget Function GetTargetData *********************************
struct Z_Construct_UFunction_UTargetItemWidget_GetTargetData_Statics
{
	struct TargetItemWidget_eventGetTargetData_Parms
	{
		FTargetPanelData ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Target Item" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Get the current target data\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the current target data" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UTargetItemWidget_GetTargetData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000008000582, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetItemWidget_eventGetTargetData_Parms, ReturnValue), Z_Construct_UScriptStruct_FTargetPanelData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) }; // 3323251151
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTargetItemWidget_GetTargetData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetItemWidget_GetTargetData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetItemWidget_GetTargetData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTargetItemWidget_GetTargetData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTargetItemWidget, nullptr, "GetTargetData", Z_Construct_UFunction_UTargetItemWidget_GetTargetData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetItemWidget_GetTargetData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UTargetItemWidget_GetTargetData_Statics::TargetItemWidget_eventGetTargetData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetItemWidget_GetTargetData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTargetItemWidget_GetTargetData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UTargetItemWidget_GetTargetData_Statics::TargetItemWidget_eventGetTargetData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTargetItemWidget_GetTargetData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTargetItemWidget_GetTargetData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTargetItemWidget::execGetTargetData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FTargetPanelData*)Z_Param__Result=P_THIS->GetTargetData();
	P_NATIVE_END;
}
// ********** End Class UTargetItemWidget Function GetTargetData ***********************************

// ********** Begin Class UTargetItemWidget Function OnLockProgressChanged *************************
struct TargetItemWidget_eventOnLockProgressChanged_Parms
{
	float Progress;
};
static FName NAME_UTargetItemWidget_OnLockProgressChanged = FName(TEXT("OnLockProgressChanged"));
void UTargetItemWidget::OnLockProgressChanged(float Progress)
{
	TargetItemWidget_eventOnLockProgressChanged_Parms Parms;
	Parms.Progress=Progress;
	UFunction* Func = FindFunctionChecked(NAME_UTargetItemWidget_OnLockProgressChanged);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UTargetItemWidget_OnLockProgressChanged_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Target Item" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Called when lock progress changes\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when lock progress changes" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Progress;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UTargetItemWidget_OnLockProgressChanged_Statics::NewProp_Progress = { "Progress", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetItemWidget_eventOnLockProgressChanged_Parms, Progress), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTargetItemWidget_OnLockProgressChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetItemWidget_OnLockProgressChanged_Statics::NewProp_Progress,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetItemWidget_OnLockProgressChanged_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTargetItemWidget_OnLockProgressChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTargetItemWidget, nullptr, "OnLockProgressChanged", Z_Construct_UFunction_UTargetItemWidget_OnLockProgressChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetItemWidget_OnLockProgressChanged_Statics::PropPointers), sizeof(TargetItemWidget_eventOnLockProgressChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetItemWidget_OnLockProgressChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTargetItemWidget_OnLockProgressChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(TargetItemWidget_eventOnLockProgressChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTargetItemWidget_OnLockProgressChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTargetItemWidget_OnLockProgressChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UTargetItemWidget Function OnLockProgressChanged ***************************

// ********** Begin Class UTargetItemWidget Function OnLockStateChanged ****************************
struct TargetItemWidget_eventOnLockStateChanged_Parms
{
	ETargetLockState NewState;
};
static FName NAME_UTargetItemWidget_OnLockStateChanged = FName(TEXT("OnLockStateChanged"));
void UTargetItemWidget::OnLockStateChanged(ETargetLockState NewState)
{
	TargetItemWidget_eventOnLockStateChanged_Parms Parms;
	Parms.NewState=NewState;
	UFunction* Func = FindFunctionChecked(NAME_UTargetItemWidget_OnLockStateChanged);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UTargetItemWidget_OnLockStateChanged_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Target Item" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Called when lock state changes\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when lock state changes" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UTargetItemWidget_OnLockStateChanged_Statics::NewProp_NewState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UTargetItemWidget_OnLockStateChanged_Statics::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetItemWidget_eventOnLockStateChanged_Parms, NewState), Z_Construct_UEnum_Echoes_ETargetLockState, METADATA_PARAMS(0, nullptr) }; // 2896437216
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTargetItemWidget_OnLockStateChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetItemWidget_OnLockStateChanged_Statics::NewProp_NewState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetItemWidget_OnLockStateChanged_Statics::NewProp_NewState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetItemWidget_OnLockStateChanged_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTargetItemWidget_OnLockStateChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTargetItemWidget, nullptr, "OnLockStateChanged", Z_Construct_UFunction_UTargetItemWidget_OnLockStateChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetItemWidget_OnLockStateChanged_Statics::PropPointers), sizeof(TargetItemWidget_eventOnLockStateChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetItemWidget_OnLockStateChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTargetItemWidget_OnLockStateChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(TargetItemWidget_eventOnLockStateChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTargetItemWidget_OnLockStateChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTargetItemWidget_OnLockStateChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UTargetItemWidget Function OnLockStateChanged ******************************

// ********** Begin Class UTargetItemWidget Function SetTargetData *********************************
struct Z_Construct_UFunction_UTargetItemWidget_SetTargetData_Statics
{
	struct TargetItemWidget_eventSetTargetData_Parms
	{
		FTargetPanelData InTargetData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Target Item" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Set the target data for this widget\n * \n * @param InTargetData The data to display\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set the target data for this widget\n\n@param InTargetData The data to display" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InTargetData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_InTargetData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UTargetItemWidget_SetTargetData_Statics::NewProp_InTargetData = { "InTargetData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetItemWidget_eventSetTargetData_Parms, InTargetData), Z_Construct_UScriptStruct_FTargetPanelData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InTargetData_MetaData), NewProp_InTargetData_MetaData) }; // 3323251151
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTargetItemWidget_SetTargetData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetItemWidget_SetTargetData_Statics::NewProp_InTargetData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetItemWidget_SetTargetData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTargetItemWidget_SetTargetData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTargetItemWidget, nullptr, "SetTargetData", Z_Construct_UFunction_UTargetItemWidget_SetTargetData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetItemWidget_SetTargetData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UTargetItemWidget_SetTargetData_Statics::TargetItemWidget_eventSetTargetData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetItemWidget_SetTargetData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTargetItemWidget_SetTargetData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UTargetItemWidget_SetTargetData_Statics::TargetItemWidget_eventSetTargetData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTargetItemWidget_SetTargetData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTargetItemWidget_SetTargetData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTargetItemWidget::execSetTargetData)
{
	P_GET_STRUCT_REF(FTargetPanelData,Z_Param_Out_InTargetData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTargetData(Z_Param_Out_InTargetData);
	P_NATIVE_END;
}
// ********** End Class UTargetItemWidget Function SetTargetData ***********************************

// ********** Begin Class UTargetItemWidget Function UpdateDisplay *********************************
static FName NAME_UTargetItemWidget_UpdateDisplay = FName(TEXT("UpdateDisplay"));
void UTargetItemWidget::UpdateDisplay()
{
	UFunction* Func = FindFunctionChecked(NAME_UTargetItemWidget_UpdateDisplay);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_UTargetItemWidget_UpdateDisplay_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Target Item" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Update the visual display\n * Override in Blueprint to customize appearance\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Update the visual display\nOverride in Blueprint to customize appearance" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTargetItemWidget_UpdateDisplay_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTargetItemWidget, nullptr, "UpdateDisplay", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetItemWidget_UpdateDisplay_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTargetItemWidget_UpdateDisplay_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UTargetItemWidget_UpdateDisplay()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTargetItemWidget_UpdateDisplay_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UTargetItemWidget Function UpdateDisplay ***********************************

// ********** Begin Class UTargetItemWidget ********************************************************
void UTargetItemWidget::StaticRegisterNativesUTargetItemWidget()
{
	UClass* Class = UTargetItemWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetTargetActor", &UTargetItemWidget::execGetTargetActor },
		{ "GetTargetData", &UTargetItemWidget::execGetTargetData },
		{ "SetTargetData", &UTargetItemWidget::execSetTargetData },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UTargetItemWidget;
UClass* UTargetItemWidget::GetPrivateStaticClass()
{
	using TClass = UTargetItemWidget;
	if (!Z_Registration_Info_UClass_UTargetItemWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("TargetItemWidget"),
			Z_Registration_Info_UClass_UTargetItemWidget.InnerSingleton,
			StaticRegisterNativesUTargetItemWidget,
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
	return Z_Registration_Info_UClass_UTargetItemWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UTargetItemWidget_NoRegister()
{
	return UTargetItemWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UTargetItemWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UTargetItemWidget\n * \n * Individual target display widget\n * Shows lock progress ring and health bars (Shield/Armor/Hull)\n * \n * Usage:\n * This widget is dynamically created for each locked target\n * and displays in the target panel container\n */" },
#endif
		{ "IncludePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UTargetItemWidget\n\nIndividual target display widget\nShows lock progress ring and health bars (Shield/Armor/Hull)\n\nUsage:\nThis widget is dynamically created for each locked target\nand displays in the target panel container" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetData_MetaData[] = {
		{ "Category", "Target Item" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The target data being displayed */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The target data being displayed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetNameText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "TargetItemWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Target name text */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Target name text" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistanceText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "TargetItemWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Distance text */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Distance text" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LockProgressRing_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "TargetItemWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Lock progress circular bar */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lock progress circular bar" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShieldBar_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "TargetItemWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shield progress bar */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shield progress bar" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ArmorBar_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "TargetItemWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Armor progress bar */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Armor progress bar" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HullBar_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "TargetItemWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Hull progress bar */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Hull progress bar" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShieldText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "TargetItemWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shield text */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shield text" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ArmorText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "TargetItemWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Armor text */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Armor text" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HullText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "TargetItemWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Hull text */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Hull text" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetData;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetNameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DistanceText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LockProgressRing;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ShieldBar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ArmorBar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HullBar;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ShieldText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ArmorText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HullText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UTargetItemWidget_GetTargetActor, "GetTargetActor" }, // 3883245480
		{ &Z_Construct_UFunction_UTargetItemWidget_GetTargetData, "GetTargetData" }, // 2092424163
		{ &Z_Construct_UFunction_UTargetItemWidget_OnLockProgressChanged, "OnLockProgressChanged" }, // 995897819
		{ &Z_Construct_UFunction_UTargetItemWidget_OnLockStateChanged, "OnLockStateChanged" }, // 3410895085
		{ &Z_Construct_UFunction_UTargetItemWidget_SetTargetData, "SetTargetData" }, // 3177552923
		{ &Z_Construct_UFunction_UTargetItemWidget_UpdateDisplay, "UpdateDisplay" }, // 1102022606
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTargetItemWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UTargetItemWidget_Statics::NewProp_TargetData = { "TargetData", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTargetItemWidget, TargetData), Z_Construct_UScriptStruct_FTargetPanelData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetData_MetaData), NewProp_TargetData_MetaData) }; // 3323251151
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UTargetItemWidget_Statics::NewProp_TargetNameText = { "TargetNameText", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTargetItemWidget, TargetNameText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetNameText_MetaData), NewProp_TargetNameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UTargetItemWidget_Statics::NewProp_DistanceText = { "DistanceText", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTargetItemWidget, DistanceText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistanceText_MetaData), NewProp_DistanceText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UTargetItemWidget_Statics::NewProp_LockProgressRing = { "LockProgressRing", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTargetItemWidget, LockProgressRing), Z_Construct_UClass_UCircularThrobber_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LockProgressRing_MetaData), NewProp_LockProgressRing_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UTargetItemWidget_Statics::NewProp_ShieldBar = { "ShieldBar", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTargetItemWidget, ShieldBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShieldBar_MetaData), NewProp_ShieldBar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UTargetItemWidget_Statics::NewProp_ArmorBar = { "ArmorBar", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTargetItemWidget, ArmorBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArmorBar_MetaData), NewProp_ArmorBar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UTargetItemWidget_Statics::NewProp_HullBar = { "HullBar", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTargetItemWidget, HullBar), Z_Construct_UClass_UProgressBar_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HullBar_MetaData), NewProp_HullBar_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UTargetItemWidget_Statics::NewProp_ShieldText = { "ShieldText", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTargetItemWidget, ShieldText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShieldText_MetaData), NewProp_ShieldText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UTargetItemWidget_Statics::NewProp_ArmorText = { "ArmorText", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTargetItemWidget, ArmorText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArmorText_MetaData), NewProp_ArmorText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UTargetItemWidget_Statics::NewProp_HullText = { "HullText", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTargetItemWidget, HullText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HullText_MetaData), NewProp_HullText_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UTargetItemWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTargetItemWidget_Statics::NewProp_TargetData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTargetItemWidget_Statics::NewProp_TargetNameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTargetItemWidget_Statics::NewProp_DistanceText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTargetItemWidget_Statics::NewProp_LockProgressRing,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTargetItemWidget_Statics::NewProp_ShieldBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTargetItemWidget_Statics::NewProp_ArmorBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTargetItemWidget_Statics::NewProp_HullBar,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTargetItemWidget_Statics::NewProp_ShieldText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTargetItemWidget_Statics::NewProp_ArmorText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTargetItemWidget_Statics::NewProp_HullText,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTargetItemWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UTargetItemWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTargetItemWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UTargetItemWidget_Statics::ClassParams = {
	&UTargetItemWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UTargetItemWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UTargetItemWidget_Statics::PropPointers),
	0,
	0x00B010A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTargetItemWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UTargetItemWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UTargetItemWidget()
{
	if (!Z_Registration_Info_UClass_UTargetItemWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTargetItemWidget.OuterSingleton, Z_Construct_UClass_UTargetItemWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UTargetItemWidget.OuterSingleton;
}
UTargetItemWidget::UTargetItemWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UTargetItemWidget);
UTargetItemWidget::~UTargetItemWidget() {}
// ********** End Class UTargetItemWidget **********************************************************

// ********** Begin Class UTargetPanelWidget Function BindToTargetingComponent *********************
struct Z_Construct_UFunction_UTargetPanelWidget_BindToTargetingComponent_Statics
{
	struct TargetPanelWidget_eventBindToTargetingComponent_Parms
	{
		UTargetingComponent* TargetingComp;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Target Panel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Bind to a targeting component for automatic updates\n * \n * @param TargetingComp The targeting component to bind to\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Bind to a targeting component for automatic updates\n\n@param TargetingComp The targeting component to bind to" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetingComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetingComp;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTargetPanelWidget_BindToTargetingComponent_Statics::NewProp_TargetingComp = { "TargetingComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetPanelWidget_eventBindToTargetingComponent_Parms, TargetingComp), Z_Construct_UClass_UTargetingComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetingComp_MetaData), NewProp_TargetingComp_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTargetPanelWidget_BindToTargetingComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetPanelWidget_BindToTargetingComponent_Statics::NewProp_TargetingComp,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetPanelWidget_BindToTargetingComponent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTargetPanelWidget_BindToTargetingComponent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTargetPanelWidget, nullptr, "BindToTargetingComponent", Z_Construct_UFunction_UTargetPanelWidget_BindToTargetingComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetPanelWidget_BindToTargetingComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_UTargetPanelWidget_BindToTargetingComponent_Statics::TargetPanelWidget_eventBindToTargetingComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetPanelWidget_BindToTargetingComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTargetPanelWidget_BindToTargetingComponent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UTargetPanelWidget_BindToTargetingComponent_Statics::TargetPanelWidget_eventBindToTargetingComponent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTargetPanelWidget_BindToTargetingComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTargetPanelWidget_BindToTargetingComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTargetPanelWidget::execBindToTargetingComponent)
{
	P_GET_OBJECT(UTargetingComponent,Z_Param_TargetingComp);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->BindToTargetingComponent(Z_Param_TargetingComp);
	P_NATIVE_END;
}
// ********** End Class UTargetPanelWidget Function BindToTargetingComponent ***********************

// ********** Begin Class UTargetPanelWidget Function ClearAllTargets ******************************
struct Z_Construct_UFunction_UTargetPanelWidget_ClearAllTargets_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Target Panel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Clear all targets\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Clear all targets" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTargetPanelWidget_ClearAllTargets_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTargetPanelWidget, nullptr, "ClearAllTargets", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetPanelWidget_ClearAllTargets_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTargetPanelWidget_ClearAllTargets_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UTargetPanelWidget_ClearAllTargets()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTargetPanelWidget_ClearAllTargets_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTargetPanelWidget::execClearAllTargets)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearAllTargets();
	P_NATIVE_END;
}
// ********** End Class UTargetPanelWidget Function ClearAllTargets ********************************

// ********** Begin Class UTargetPanelWidget Function ClientOnly_AddTarget *************************
struct Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_AddTarget_Statics
{
	struct TargetPanelWidget_eventClientOnly_AddTarget_Parms
	{
		FTargetPanelData TargetData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Target Panel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Add a target to the panel\n * \n * @param TargetData The target data to add\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Add a target to the panel\n\n@param TargetData The target data to add" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_AddTarget_Statics::NewProp_TargetData = { "TargetData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetPanelWidget_eventClientOnly_AddTarget_Parms, TargetData), Z_Construct_UScriptStruct_FTargetPanelData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetData_MetaData), NewProp_TargetData_MetaData) }; // 3323251151
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_AddTarget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_AddTarget_Statics::NewProp_TargetData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_AddTarget_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_AddTarget_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTargetPanelWidget, nullptr, "ClientOnly_AddTarget", Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_AddTarget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_AddTarget_Statics::PropPointers), sizeof(Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_AddTarget_Statics::TargetPanelWidget_eventClientOnly_AddTarget_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_AddTarget_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_AddTarget_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_AddTarget_Statics::TargetPanelWidget_eventClientOnly_AddTarget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_AddTarget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_AddTarget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTargetPanelWidget::execClientOnly_AddTarget)
{
	P_GET_STRUCT_REF(FTargetPanelData,Z_Param_Out_TargetData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_AddTarget(Z_Param_Out_TargetData);
	P_NATIVE_END;
}
// ********** End Class UTargetPanelWidget Function ClientOnly_AddTarget ***************************

// ********** Begin Class UTargetPanelWidget Function ClientOnly_RemoveTarget **********************
struct Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_RemoveTarget_Statics
{
	struct TargetPanelWidget_eventClientOnly_RemoveTarget_Parms
	{
		AActor* Target;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Target Panel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Remove a target from the panel\n * \n * @param Target The target actor to remove\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Remove a target from the panel\n\n@param Target The target actor to remove" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_RemoveTarget_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetPanelWidget_eventClientOnly_RemoveTarget_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_RemoveTarget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_RemoveTarget_Statics::NewProp_Target,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_RemoveTarget_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_RemoveTarget_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTargetPanelWidget, nullptr, "ClientOnly_RemoveTarget", Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_RemoveTarget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_RemoveTarget_Statics::PropPointers), sizeof(Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_RemoveTarget_Statics::TargetPanelWidget_eventClientOnly_RemoveTarget_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_RemoveTarget_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_RemoveTarget_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_RemoveTarget_Statics::TargetPanelWidget_eventClientOnly_RemoveTarget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_RemoveTarget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_RemoveTarget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTargetPanelWidget::execClientOnly_RemoveTarget)
{
	P_GET_OBJECT(AActor,Z_Param_Target);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_RemoveTarget(Z_Param_Target);
	P_NATIVE_END;
}
// ********** End Class UTargetPanelWidget Function ClientOnly_RemoveTarget ************************

// ********** Begin Class UTargetPanelWidget Function ClientOnly_UpdateTarget **********************
struct Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_UpdateTarget_Statics
{
	struct TargetPanelWidget_eventClientOnly_UpdateTarget_Parms
	{
		AActor* Target;
		FTargetPanelData NewData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Target Panel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Update target data\n * \n * @param Target The target to update\n * @param NewData The new data for the target\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Update target data\n\n@param Target The target to update\n@param NewData The new data for the target" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NewData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_UpdateTarget_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetPanelWidget_eventClientOnly_UpdateTarget_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_UpdateTarget_Statics::NewProp_NewData = { "NewData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetPanelWidget_eventClientOnly_UpdateTarget_Parms, NewData), Z_Construct_UScriptStruct_FTargetPanelData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewData_MetaData), NewProp_NewData_MetaData) }; // 3323251151
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_UpdateTarget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_UpdateTarget_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_UpdateTarget_Statics::NewProp_NewData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_UpdateTarget_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_UpdateTarget_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTargetPanelWidget, nullptr, "ClientOnly_UpdateTarget", Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_UpdateTarget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_UpdateTarget_Statics::PropPointers), sizeof(Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_UpdateTarget_Statics::TargetPanelWidget_eventClientOnly_UpdateTarget_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_UpdateTarget_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_UpdateTarget_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_UpdateTarget_Statics::TargetPanelWidget_eventClientOnly_UpdateTarget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_UpdateTarget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_UpdateTarget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTargetPanelWidget::execClientOnly_UpdateTarget)
{
	P_GET_OBJECT(AActor,Z_Param_Target);
	P_GET_STRUCT_REF(FTargetPanelData,Z_Param_Out_NewData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_UpdateTarget(Z_Param_Target,Z_Param_Out_NewData);
	P_NATIVE_END;
}
// ********** End Class UTargetPanelWidget Function ClientOnly_UpdateTarget ************************

// ********** Begin Class UTargetPanelWidget Function GetTargetItemWidget **************************
struct Z_Construct_UFunction_UTargetPanelWidget_GetTargetItemWidget_Statics
{
	struct TargetPanelWidget_eventGetTargetItemWidget_Parms
	{
		AActor* Target;
		UTargetItemWidget* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Target Panel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Get target item widget for a specific target\n * \n * @param Target The target actor\n * @return The widget displaying this target, or nullptr if not found\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get target item widget for a specific target\n\n@param Target The target actor\n@return The widget displaying this target, or nullptr if not found" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTargetPanelWidget_GetTargetItemWidget_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetPanelWidget_eventGetTargetItemWidget_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTargetPanelWidget_GetTargetItemWidget_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetPanelWidget_eventGetTargetItemWidget_Parms, ReturnValue), Z_Construct_UClass_UTargetItemWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTargetPanelWidget_GetTargetItemWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetPanelWidget_GetTargetItemWidget_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetPanelWidget_GetTargetItemWidget_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetPanelWidget_GetTargetItemWidget_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTargetPanelWidget_GetTargetItemWidget_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTargetPanelWidget, nullptr, "GetTargetItemWidget", Z_Construct_UFunction_UTargetPanelWidget_GetTargetItemWidget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetPanelWidget_GetTargetItemWidget_Statics::PropPointers), sizeof(Z_Construct_UFunction_UTargetPanelWidget_GetTargetItemWidget_Statics::TargetPanelWidget_eventGetTargetItemWidget_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetPanelWidget_GetTargetItemWidget_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTargetPanelWidget_GetTargetItemWidget_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UTargetPanelWidget_GetTargetItemWidget_Statics::TargetPanelWidget_eventGetTargetItemWidget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTargetPanelWidget_GetTargetItemWidget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTargetPanelWidget_GetTargetItemWidget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTargetPanelWidget::execGetTargetItemWidget)
{
	P_GET_OBJECT(AActor,Z_Param_Target);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UTargetItemWidget**)Z_Param__Result=P_THIS->GetTargetItemWidget(Z_Param_Target);
	P_NATIVE_END;
}
// ********** End Class UTargetPanelWidget Function GetTargetItemWidget ****************************

// ********** Begin Class UTargetPanelWidget Function HandleLockCompleted **************************
struct Z_Construct_UFunction_UTargetPanelWidget_HandleLockCompleted_Statics
{
	struct TargetPanelWidget_eventHandleLockCompleted_Parms
	{
		AActor* Target;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Handle lock completed from targeting component\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle lock completed from targeting component" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTargetPanelWidget_HandleLockCompleted_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetPanelWidget_eventHandleLockCompleted_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTargetPanelWidget_HandleLockCompleted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetPanelWidget_HandleLockCompleted_Statics::NewProp_Target,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetPanelWidget_HandleLockCompleted_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTargetPanelWidget_HandleLockCompleted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTargetPanelWidget, nullptr, "HandleLockCompleted", Z_Construct_UFunction_UTargetPanelWidget_HandleLockCompleted_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetPanelWidget_HandleLockCompleted_Statics::PropPointers), sizeof(Z_Construct_UFunction_UTargetPanelWidget_HandleLockCompleted_Statics::TargetPanelWidget_eventHandleLockCompleted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetPanelWidget_HandleLockCompleted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTargetPanelWidget_HandleLockCompleted_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UTargetPanelWidget_HandleLockCompleted_Statics::TargetPanelWidget_eventHandleLockCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTargetPanelWidget_HandleLockCompleted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTargetPanelWidget_HandleLockCompleted_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTargetPanelWidget::execHandleLockCompleted)
{
	P_GET_OBJECT(AActor,Z_Param_Target);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleLockCompleted(Z_Param_Target);
	P_NATIVE_END;
}
// ********** End Class UTargetPanelWidget Function HandleLockCompleted ****************************

// ********** Begin Class UTargetPanelWidget Function HandleLockLost *******************************
struct Z_Construct_UFunction_UTargetPanelWidget_HandleLockLost_Statics
{
	struct TargetPanelWidget_eventHandleLockLost_Parms
	{
		AActor* Target;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Handle lock lost from targeting component\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle lock lost from targeting component" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTargetPanelWidget_HandleLockLost_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetPanelWidget_eventHandleLockLost_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTargetPanelWidget_HandleLockLost_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetPanelWidget_HandleLockLost_Statics::NewProp_Target,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetPanelWidget_HandleLockLost_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTargetPanelWidget_HandleLockLost_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTargetPanelWidget, nullptr, "HandleLockLost", Z_Construct_UFunction_UTargetPanelWidget_HandleLockLost_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetPanelWidget_HandleLockLost_Statics::PropPointers), sizeof(Z_Construct_UFunction_UTargetPanelWidget_HandleLockLost_Statics::TargetPanelWidget_eventHandleLockLost_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetPanelWidget_HandleLockLost_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTargetPanelWidget_HandleLockLost_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UTargetPanelWidget_HandleLockLost_Statics::TargetPanelWidget_eventHandleLockLost_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTargetPanelWidget_HandleLockLost()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTargetPanelWidget_HandleLockLost_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTargetPanelWidget::execHandleLockLost)
{
	P_GET_OBJECT(AActor,Z_Param_Target);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleLockLost(Z_Param_Target);
	P_NATIVE_END;
}
// ********** End Class UTargetPanelWidget Function HandleLockLost *********************************

// ********** Begin Class UTargetPanelWidget Function HandleLockProgress ***************************
struct Z_Construct_UFunction_UTargetPanelWidget_HandleLockProgress_Statics
{
	struct TargetPanelWidget_eventHandleLockProgress_Parms
	{
		AActor* Target;
		float Progress;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Handle lock progress from targeting component\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle lock progress from targeting component" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Progress;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTargetPanelWidget_HandleLockProgress_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetPanelWidget_eventHandleLockProgress_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UTargetPanelWidget_HandleLockProgress_Statics::NewProp_Progress = { "Progress", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetPanelWidget_eventHandleLockProgress_Parms, Progress), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTargetPanelWidget_HandleLockProgress_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetPanelWidget_HandleLockProgress_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetPanelWidget_HandleLockProgress_Statics::NewProp_Progress,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetPanelWidget_HandleLockProgress_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTargetPanelWidget_HandleLockProgress_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTargetPanelWidget, nullptr, "HandleLockProgress", Z_Construct_UFunction_UTargetPanelWidget_HandleLockProgress_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetPanelWidget_HandleLockProgress_Statics::PropPointers), sizeof(Z_Construct_UFunction_UTargetPanelWidget_HandleLockProgress_Statics::TargetPanelWidget_eventHandleLockProgress_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetPanelWidget_HandleLockProgress_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTargetPanelWidget_HandleLockProgress_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UTargetPanelWidget_HandleLockProgress_Statics::TargetPanelWidget_eventHandleLockProgress_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTargetPanelWidget_HandleLockProgress()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTargetPanelWidget_HandleLockProgress_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTargetPanelWidget::execHandleLockProgress)
{
	P_GET_OBJECT(AActor,Z_Param_Target);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Progress);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleLockProgress(Z_Param_Target,Z_Param_Progress);
	P_NATIVE_END;
}
// ********** End Class UTargetPanelWidget Function HandleLockProgress *****************************

// ********** Begin Class UTargetPanelWidget Function HandleLockStarted ****************************
struct Z_Construct_UFunction_UTargetPanelWidget_HandleLockStarted_Statics
{
	struct TargetPanelWidget_eventHandleLockStarted_Parms
	{
		AActor* Target;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Handle lock started from targeting component\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle lock started from targeting component" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTargetPanelWidget_HandleLockStarted_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetPanelWidget_eventHandleLockStarted_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTargetPanelWidget_HandleLockStarted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetPanelWidget_HandleLockStarted_Statics::NewProp_Target,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetPanelWidget_HandleLockStarted_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTargetPanelWidget_HandleLockStarted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTargetPanelWidget, nullptr, "HandleLockStarted", Z_Construct_UFunction_UTargetPanelWidget_HandleLockStarted_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetPanelWidget_HandleLockStarted_Statics::PropPointers), sizeof(Z_Construct_UFunction_UTargetPanelWidget_HandleLockStarted_Statics::TargetPanelWidget_eventHandleLockStarted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetPanelWidget_HandleLockStarted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTargetPanelWidget_HandleLockStarted_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UTargetPanelWidget_HandleLockStarted_Statics::TargetPanelWidget_eventHandleLockStarted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTargetPanelWidget_HandleLockStarted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTargetPanelWidget_HandleLockStarted_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTargetPanelWidget::execHandleLockStarted)
{
	P_GET_OBJECT(AActor,Z_Param_Target);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleLockStarted(Z_Param_Target);
	P_NATIVE_END;
}
// ********** End Class UTargetPanelWidget Function HandleLockStarted ******************************

// ********** Begin Class UTargetPanelWidget Function UnbindFromTargetingComponent *****************
struct Z_Construct_UFunction_UTargetPanelWidget_UnbindFromTargetingComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Target Panel" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Unbind from current targeting component\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Unbind from current targeting component" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTargetPanelWidget_UnbindFromTargetingComponent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTargetPanelWidget, nullptr, "UnbindFromTargetingComponent", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetPanelWidget_UnbindFromTargetingComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTargetPanelWidget_UnbindFromTargetingComponent_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UTargetPanelWidget_UnbindFromTargetingComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTargetPanelWidget_UnbindFromTargetingComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTargetPanelWidget::execUnbindFromTargetingComponent)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UnbindFromTargetingComponent();
	P_NATIVE_END;
}
// ********** End Class UTargetPanelWidget Function UnbindFromTargetingComponent *******************

// ********** Begin Class UTargetPanelWidget *******************************************************
void UTargetPanelWidget::StaticRegisterNativesUTargetPanelWidget()
{
	UClass* Class = UTargetPanelWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "BindToTargetingComponent", &UTargetPanelWidget::execBindToTargetingComponent },
		{ "ClearAllTargets", &UTargetPanelWidget::execClearAllTargets },
		{ "ClientOnly_AddTarget", &UTargetPanelWidget::execClientOnly_AddTarget },
		{ "ClientOnly_RemoveTarget", &UTargetPanelWidget::execClientOnly_RemoveTarget },
		{ "ClientOnly_UpdateTarget", &UTargetPanelWidget::execClientOnly_UpdateTarget },
		{ "GetTargetItemWidget", &UTargetPanelWidget::execGetTargetItemWidget },
		{ "HandleLockCompleted", &UTargetPanelWidget::execHandleLockCompleted },
		{ "HandleLockLost", &UTargetPanelWidget::execHandleLockLost },
		{ "HandleLockProgress", &UTargetPanelWidget::execHandleLockProgress },
		{ "HandleLockStarted", &UTargetPanelWidget::execHandleLockStarted },
		{ "UnbindFromTargetingComponent", &UTargetPanelWidget::execUnbindFromTargetingComponent },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UTargetPanelWidget;
UClass* UTargetPanelWidget::GetPrivateStaticClass()
{
	using TClass = UTargetPanelWidget;
	if (!Z_Registration_Info_UClass_UTargetPanelWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("TargetPanelWidget"),
			Z_Registration_Info_UClass_UTargetPanelWidget.InnerSingleton,
			StaticRegisterNativesUTargetPanelWidget,
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
	return Z_Registration_Info_UClass_UTargetPanelWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UTargetPanelWidget_NoRegister()
{
	return UTargetPanelWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UTargetPanelWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UTargetPanelWidget\n * \n * Panel displaying all currently locked targets\n * Dynamically creates/removes target item widgets\n * \n * Features:\n * - Dynamic container for target items\n * - Lock progress display with circular progress bar\n * - Shield/Armor/Hull bars updated via ClientRPC\n * - Event-driven updates from TargetingComponent\n * \n * Architecture:\n * - Vertical/Horizontal box container for target items\n * - Target items created on lock start\n * - Target items removed on lock lost\n * - Updates via TargetingComponent delegates\n * \n * Usage:\n * // Automatically updates when TargetingComponent fires events\n * TargetPanelWidget->BindToTargetingComponent(TargetingComponent);\n */" },
#endif
		{ "IncludePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UTargetPanelWidget\n\nPanel displaying all currently locked targets\nDynamically creates/removes target item widgets\n\nFeatures:\n- Dynamic container for target items\n- Lock progress display with circular progress bar\n- Shield/Armor/Hull bars updated via ClientRPC\n- Event-driven updates from TargetingComponent\n\nArchitecture:\n- Vertical/Horizontal box container for target items\n- Target items created on lock start\n- Target items removed on lock lost\n- Updates via TargetingComponent delegates\n\nUsage:\n// Automatically updates when TargetingComponent fires events\nTargetPanelWidget->BindToTargetingComponent(TargetingComponent);" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnTargetStateChanged_MetaData[] = {
		{ "Category", "Target Panel Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when target state changes (lock progress, health, etc.) */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when target state changes (lock progress, health, etc.)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnTargetSelected_MetaData[] = {
		{ "Category", "Target Panel Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when a target is selected/clicked */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when a target is selected/clicked" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetContainer_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "TargetPanelWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Container for target item widgets */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Container for target item widgets" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HeaderText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "TargetPanelWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Header text showing target count */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Header text showing target count" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetItemWidgetClass_MetaData[] = {
		{ "Category", "Target Panel Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Target item widget class to spawn */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Target item widget class to spawn" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxDisplayedTargets_MetaData[] = {
		{ "Category", "Target Panel Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum number of targets to display */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum number of targets to display" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetWidgets_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Map of target actor to widget */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Map of target actor to widget" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoundTargetingComponent_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current targeting component */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/TargetPanelWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current targeting component" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTargetStateChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTargetSelected;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetContainer;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HeaderText;
	static const UECodeGen_Private::FClassPropertyParams NewProp_TargetItemWidgetClass;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxDisplayedTargets;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetWidgets_ValueProp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetWidgets_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_TargetWidgets;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BoundTargetingComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UTargetPanelWidget_BindToTargetingComponent, "BindToTargetingComponent" }, // 712222522
		{ &Z_Construct_UFunction_UTargetPanelWidget_ClearAllTargets, "ClearAllTargets" }, // 253989393
		{ &Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_AddTarget, "ClientOnly_AddTarget" }, // 496060823
		{ &Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_RemoveTarget, "ClientOnly_RemoveTarget" }, // 36935395
		{ &Z_Construct_UFunction_UTargetPanelWidget_ClientOnly_UpdateTarget, "ClientOnly_UpdateTarget" }, // 87642930
		{ &Z_Construct_UFunction_UTargetPanelWidget_GetTargetItemWidget, "GetTargetItemWidget" }, // 3154243793
		{ &Z_Construct_UFunction_UTargetPanelWidget_HandleLockCompleted, "HandleLockCompleted" }, // 2325905616
		{ &Z_Construct_UFunction_UTargetPanelWidget_HandleLockLost, "HandleLockLost" }, // 1096689301
		{ &Z_Construct_UFunction_UTargetPanelWidget_HandleLockProgress, "HandleLockProgress" }, // 1011140395
		{ &Z_Construct_UFunction_UTargetPanelWidget_HandleLockStarted, "HandleLockStarted" }, // 2035893621
		{ &Z_Construct_UFunction_UTargetPanelWidget_UnbindFromTargetingComponent, "UnbindFromTargetingComponent" }, // 603618074
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTargetPanelWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UTargetPanelWidget_Statics::NewProp_OnTargetStateChanged = { "OnTargetStateChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTargetPanelWidget, OnTargetStateChanged), Z_Construct_UDelegateFunction_Echoes_OnTargetStateChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnTargetStateChanged_MetaData), NewProp_OnTargetStateChanged_MetaData) }; // 1804330461
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UTargetPanelWidget_Statics::NewProp_OnTargetSelected = { "OnTargetSelected", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTargetPanelWidget, OnTargetSelected), Z_Construct_UDelegateFunction_Echoes_OnTargetSelected__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnTargetSelected_MetaData), NewProp_OnTargetSelected_MetaData) }; // 3257283733
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UTargetPanelWidget_Statics::NewProp_TargetContainer = { "TargetContainer", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTargetPanelWidget, TargetContainer), Z_Construct_UClass_UVerticalBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetContainer_MetaData), NewProp_TargetContainer_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UTargetPanelWidget_Statics::NewProp_HeaderText = { "HeaderText", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTargetPanelWidget, HeaderText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HeaderText_MetaData), NewProp_HeaderText_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UTargetPanelWidget_Statics::NewProp_TargetItemWidgetClass = { "TargetItemWidgetClass", nullptr, (EPropertyFlags)0x0024080000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTargetPanelWidget, TargetItemWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UTargetItemWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetItemWidgetClass_MetaData), NewProp_TargetItemWidgetClass_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UTargetPanelWidget_Statics::NewProp_MaxDisplayedTargets = { "MaxDisplayedTargets", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTargetPanelWidget, MaxDisplayedTargets), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxDisplayedTargets_MetaData), NewProp_MaxDisplayedTargets_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UTargetPanelWidget_Statics::NewProp_TargetWidgets_ValueProp = { "TargetWidgets", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UTargetItemWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UTargetPanelWidget_Statics::NewProp_TargetWidgets_Key_KeyProp = { "TargetWidgets_Key", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UTargetPanelWidget_Statics::NewProp_TargetWidgets = { "TargetWidgets", nullptr, (EPropertyFlags)0x0020088000000008, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTargetPanelWidget, TargetWidgets), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetWidgets_MetaData), NewProp_TargetWidgets_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UTargetPanelWidget_Statics::NewProp_BoundTargetingComponent = { "BoundTargetingComponent", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTargetPanelWidget, BoundTargetingComponent), Z_Construct_UClass_UTargetingComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoundTargetingComponent_MetaData), NewProp_BoundTargetingComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UTargetPanelWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTargetPanelWidget_Statics::NewProp_OnTargetStateChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTargetPanelWidget_Statics::NewProp_OnTargetSelected,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTargetPanelWidget_Statics::NewProp_TargetContainer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTargetPanelWidget_Statics::NewProp_HeaderText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTargetPanelWidget_Statics::NewProp_TargetItemWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTargetPanelWidget_Statics::NewProp_MaxDisplayedTargets,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTargetPanelWidget_Statics::NewProp_TargetWidgets_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTargetPanelWidget_Statics::NewProp_TargetWidgets_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTargetPanelWidget_Statics::NewProp_TargetWidgets,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTargetPanelWidget_Statics::NewProp_BoundTargetingComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTargetPanelWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UTargetPanelWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTargetPanelWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UTargetPanelWidget_Statics::ClassParams = {
	&UTargetPanelWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UTargetPanelWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UTargetPanelWidget_Statics::PropPointers),
	0,
	0x00B010A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTargetPanelWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UTargetPanelWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UTargetPanelWidget()
{
	if (!Z_Registration_Info_UClass_UTargetPanelWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTargetPanelWidget.OuterSingleton, Z_Construct_UClass_UTargetPanelWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UTargetPanelWidget.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UTargetPanelWidget);
UTargetPanelWidget::~UTargetPanelWidget() {}
// ********** End Class UTargetPanelWidget *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_TargetPanelWidget_h__Script_Echoes_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FTargetPanelData::StaticStruct, Z_Construct_UScriptStruct_FTargetPanelData_Statics::NewStructOps, TEXT("TargetPanelData"), &Z_Registration_Info_UScriptStruct_FTargetPanelData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FTargetPanelData), 3323251151U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UTargetItemWidget, UTargetItemWidget::StaticClass, TEXT("UTargetItemWidget"), &Z_Registration_Info_UClass_UTargetItemWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTargetItemWidget), 4157702503U) },
		{ Z_Construct_UClass_UTargetPanelWidget, UTargetPanelWidget::StaticClass, TEXT("UTargetPanelWidget"), &Z_Registration_Info_UClass_UTargetPanelWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTargetPanelWidget), 152933242U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_TargetPanelWidget_h__Script_Echoes_644882792(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_TargetPanelWidget_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_TargetPanelWidget_h__Script_Echoes_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_TargetPanelWidget_h__Script_Echoes_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_TargetPanelWidget_h__Script_Echoes_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
