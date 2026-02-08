// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TargetingComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeTargetingComponent() {}

// ********** Begin Cross Module References ********************************************************
ECHOES_API UClass* Z_Construct_UClass_UTargetingComponent();
ECHOES_API UClass* Z_Construct_UClass_UTargetingComponent_NoRegister();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_ETargetLockState();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnLockCompleted__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnLockLost__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnLockProgress__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnLockStarted__DelegateSignature();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FTargetLockEntry();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum ETargetLockState **********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ETargetLockState;
static UEnum* ETargetLockState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ETargetLockState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ETargetLockState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Echoes_ETargetLockState, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("ETargetLockState"));
	}
	return Z_Registration_Info_UEnum_ETargetLockState.OuterSingleton;
}
template<> ECHOES_API UEnum* StaticEnum<ETargetLockState>()
{
	return ETargetLockState_StaticEnum();
}
struct Z_Construct_UEnum_Echoes_ETargetLockState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Target lock state enumeration\n * Represents the current state of a target lock\n */" },
#endif
		{ "Locked.Comment", "/** Lock acquired and maintained */" },
		{ "Locked.DisplayName", "Locked" },
		{ "Locked.Name", "ETargetLockState::Locked" },
		{ "Locked.ToolTip", "Lock acquired and maintained" },
		{ "Locking.Comment", "/** Lock acquisition in progress */" },
		{ "Locking.DisplayName", "Locking" },
		{ "Locking.Name", "ETargetLockState::Locking" },
		{ "Locking.ToolTip", "Lock acquisition in progress" },
		{ "Lost.Comment", "/** Lock lost (target out of range or destroyed) */" },
		{ "Lost.DisplayName", "Lost" },
		{ "Lost.Name", "ETargetLockState::Lost" },
		{ "Lost.ToolTip", "Lock lost (target out of range or destroyed)" },
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
		{ "None.Comment", "/** No lock in progress */" },
		{ "None.DisplayName", "None" },
		{ "None.Name", "ETargetLockState::None" },
		{ "None.ToolTip", "No lock in progress" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Target lock state enumeration\nRepresents the current state of a target lock" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ETargetLockState::None", (int64)ETargetLockState::None },
		{ "ETargetLockState::Locking", (int64)ETargetLockState::Locking },
		{ "ETargetLockState::Locked", (int64)ETargetLockState::Locked },
		{ "ETargetLockState::Lost", (int64)ETargetLockState::Lost },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Echoes_ETargetLockState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	"ETargetLockState",
	"ETargetLockState",
	Z_Construct_UEnum_Echoes_ETargetLockState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_ETargetLockState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_ETargetLockState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Echoes_ETargetLockState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Echoes_ETargetLockState()
{
	if (!Z_Registration_Info_UEnum_ETargetLockState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ETargetLockState.InnerSingleton, Z_Construct_UEnum_Echoes_ETargetLockState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ETargetLockState.InnerSingleton;
}
// ********** End Enum ETargetLockState ************************************************************

// ********** Begin ScriptStruct FTargetLockEntry **************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FTargetLockEntry;
class UScriptStruct* FTargetLockEntry::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FTargetLockEntry.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FTargetLockEntry.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FTargetLockEntry, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("TargetLockEntry"));
	}
	return Z_Registration_Info_UScriptStruct_FTargetLockEntry.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FTargetLockEntry_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Target lock entry structure\n * Stores information about a single target lock\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Target lock entry structure\nStores information about a single target lock" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetActor_MetaData[] = {
		{ "Category", "Targeting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Target actor being locked */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Target actor being locked" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Progress_MetaData[] = {
		{ "Category", "Targeting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Lock acquisition progress (0.0 to 1.0) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lock acquisition progress (0.0 to 1.0)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_State_MetaData[] = {
		{ "Category", "Targeting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current state of the lock */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current state of the lock" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LockStartTime_MetaData[] = {
		{ "Category", "Targeting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Time when lock started */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Time when lock started" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RequiredLockTime_MetaData[] = {
		{ "Category", "Targeting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Required time to complete lock */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Required time to complete lock" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetActor;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Progress;
	static const UECodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_State;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LockStartTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RequiredLockTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FTargetLockEntry>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FTargetLockEntry_Statics::NewProp_TargetActor = { "TargetActor", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FTargetLockEntry, TargetActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetActor_MetaData), NewProp_TargetActor_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FTargetLockEntry_Statics::NewProp_Progress = { "Progress", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FTargetLockEntry, Progress), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Progress_MetaData), NewProp_Progress_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FTargetLockEntry_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FTargetLockEntry_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FTargetLockEntry, State), Z_Construct_UEnum_Echoes_ETargetLockState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_State_MetaData), NewProp_State_MetaData) }; // 2896437216
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FTargetLockEntry_Statics::NewProp_LockStartTime = { "LockStartTime", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FTargetLockEntry, LockStartTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LockStartTime_MetaData), NewProp_LockStartTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FTargetLockEntry_Statics::NewProp_RequiredLockTime = { "RequiredLockTime", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FTargetLockEntry, RequiredLockTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RequiredLockTime_MetaData), NewProp_RequiredLockTime_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FTargetLockEntry_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTargetLockEntry_Statics::NewProp_TargetActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTargetLockEntry_Statics::NewProp_Progress,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTargetLockEntry_Statics::NewProp_State_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTargetLockEntry_Statics::NewProp_State,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTargetLockEntry_Statics::NewProp_LockStartTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTargetLockEntry_Statics::NewProp_RequiredLockTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTargetLockEntry_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FTargetLockEntry_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"TargetLockEntry",
	Z_Construct_UScriptStruct_FTargetLockEntry_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTargetLockEntry_Statics::PropPointers),
	sizeof(FTargetLockEntry),
	alignof(FTargetLockEntry),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTargetLockEntry_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FTargetLockEntry_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FTargetLockEntry()
{
	if (!Z_Registration_Info_UScriptStruct_FTargetLockEntry.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FTargetLockEntry.InnerSingleton, Z_Construct_UScriptStruct_FTargetLockEntry_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FTargetLockEntry.InnerSingleton;
}
// ********** End ScriptStruct FTargetLockEntry ****************************************************

// ********** Begin Delegate FOnLockStarted ********************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnLockStarted__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnLockStarted_Parms
	{
		AActor* Target;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Delegates for Blueprint events\n" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegates for Blueprint events" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_Echoes_OnLockStarted__DelegateSignature_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnLockStarted_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnLockStarted__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnLockStarted__DelegateSignature_Statics::NewProp_Target,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnLockStarted__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnLockStarted__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnLockStarted__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnLockStarted__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnLockStarted__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnLockStarted__DelegateSignature_Statics::_Script_Echoes_eventOnLockStarted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnLockStarted__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnLockStarted__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnLockStarted__DelegateSignature_Statics::_Script_Echoes_eventOnLockStarted_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnLockStarted__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnLockStarted__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnLockStarted_DelegateWrapper(const FMulticastScriptDelegate& OnLockStarted, AActor* Target)
{
	struct _Script_Echoes_eventOnLockStarted_Parms
	{
		AActor* Target;
	};
	_Script_Echoes_eventOnLockStarted_Parms Parms;
	Parms.Target=Target;
	OnLockStarted.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnLockStarted **********************************************************

// ********** Begin Delegate FOnLockCompleted ******************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnLockCompleted__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnLockCompleted_Parms
	{
		AActor* Target;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_Echoes_OnLockCompleted__DelegateSignature_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnLockCompleted_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnLockCompleted__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnLockCompleted__DelegateSignature_Statics::NewProp_Target,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnLockCompleted__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnLockCompleted__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnLockCompleted__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnLockCompleted__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnLockCompleted__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnLockCompleted__DelegateSignature_Statics::_Script_Echoes_eventOnLockCompleted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnLockCompleted__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnLockCompleted__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnLockCompleted__DelegateSignature_Statics::_Script_Echoes_eventOnLockCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnLockCompleted__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnLockCompleted__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnLockCompleted_DelegateWrapper(const FMulticastScriptDelegate& OnLockCompleted, AActor* Target)
{
	struct _Script_Echoes_eventOnLockCompleted_Parms
	{
		AActor* Target;
	};
	_Script_Echoes_eventOnLockCompleted_Parms Parms;
	Parms.Target=Target;
	OnLockCompleted.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnLockCompleted ********************************************************

// ********** Begin Delegate FOnLockLost ***********************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnLockLost__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnLockLost_Parms
	{
		AActor* Target;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_Echoes_OnLockLost__DelegateSignature_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnLockLost_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnLockLost__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnLockLost__DelegateSignature_Statics::NewProp_Target,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnLockLost__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnLockLost__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnLockLost__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnLockLost__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnLockLost__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnLockLost__DelegateSignature_Statics::_Script_Echoes_eventOnLockLost_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnLockLost__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnLockLost__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnLockLost__DelegateSignature_Statics::_Script_Echoes_eventOnLockLost_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnLockLost__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnLockLost__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnLockLost_DelegateWrapper(const FMulticastScriptDelegate& OnLockLost, AActor* Target)
{
	struct _Script_Echoes_eventOnLockLost_Parms
	{
		AActor* Target;
	};
	_Script_Echoes_eventOnLockLost_Parms Parms;
	Parms.Target=Target;
	OnLockLost.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnLockLost *************************************************************

// ********** Begin Delegate FOnLockProgress *******************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnLockProgress__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnLockProgress_Parms
	{
		AActor* Target;
		float Progress;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Progress;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_Echoes_OnLockProgress__DelegateSignature_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnLockProgress_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_Echoes_OnLockProgress__DelegateSignature_Statics::NewProp_Progress = { "Progress", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnLockProgress_Parms, Progress), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnLockProgress__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnLockProgress__DelegateSignature_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnLockProgress__DelegateSignature_Statics::NewProp_Progress,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnLockProgress__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnLockProgress__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnLockProgress__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnLockProgress__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnLockProgress__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnLockProgress__DelegateSignature_Statics::_Script_Echoes_eventOnLockProgress_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnLockProgress__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnLockProgress__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnLockProgress__DelegateSignature_Statics::_Script_Echoes_eventOnLockProgress_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnLockProgress__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnLockProgress__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnLockProgress_DelegateWrapper(const FMulticastScriptDelegate& OnLockProgress, AActor* Target, float Progress)
{
	struct _Script_Echoes_eventOnLockProgress_Parms
	{
		AActor* Target;
		float Progress;
	};
	_Script_Echoes_eventOnLockProgress_Parms Parms;
	Parms.Target=Target;
	Parms.Progress=Progress;
	OnLockProgress.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnLockProgress *********************************************************

// ********** Begin Class UTargetingComponent Function ClientRPC_OnLockCompleted *******************
struct TargetingComponent_eventClientRPC_OnLockCompleted_Parms
{
	AActor* Target;
};
static FName NAME_UTargetingComponent_ClientRPC_OnLockCompleted = FName(TEXT("ClientRPC_OnLockCompleted"));
void UTargetingComponent::ClientRPC_OnLockCompleted(AActor* Target)
{
	TargetingComponent_eventClientRPC_OnLockCompleted_Parms Parms;
	Parms.Target=Target;
	UFunction* Func = FindFunctionChecked(NAME_UTargetingComponent_ClientRPC_OnLockCompleted);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockCompleted_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Targeting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Notify client that lock has completed (Server \xe2\x86\x92 Client)\n\x09 * \n\x09 * @param Target - Actor that was locked\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Notify client that lock has completed (Server \xe2\x86\x92 Client)\n\n@param Target - Actor that was locked" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockCompleted_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetingComponent_eventClientRPC_OnLockCompleted_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockCompleted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockCompleted_Statics::NewProp_Target,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockCompleted_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockCompleted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTargetingComponent, nullptr, "ClientRPC_OnLockCompleted", Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockCompleted_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockCompleted_Statics::PropPointers), sizeof(TargetingComponent_eventClientRPC_OnLockCompleted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockCompleted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockCompleted_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(TargetingComponent_eventClientRPC_OnLockCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockCompleted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockCompleted_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTargetingComponent::execClientRPC_OnLockCompleted)
{
	P_GET_OBJECT(AActor,Z_Param_Target);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientRPC_OnLockCompleted_Implementation(Z_Param_Target);
	P_NATIVE_END;
}
// ********** End Class UTargetingComponent Function ClientRPC_OnLockCompleted *********************

// ********** Begin Class UTargetingComponent Function ClientRPC_OnLockLost ************************
struct TargetingComponent_eventClientRPC_OnLockLost_Parms
{
	AActor* Target;
};
static FName NAME_UTargetingComponent_ClientRPC_OnLockLost = FName(TEXT("ClientRPC_OnLockLost"));
void UTargetingComponent::ClientRPC_OnLockLost(AActor* Target)
{
	TargetingComponent_eventClientRPC_OnLockLost_Parms Parms;
	Parms.Target=Target;
	UFunction* Func = FindFunctionChecked(NAME_UTargetingComponent_ClientRPC_OnLockLost);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockLost_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Targeting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Notify client that lock was lost (Server \xe2\x86\x92 Client)\n\x09 * \n\x09 * @param Target - Actor that lost lock\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Notify client that lock was lost (Server \xe2\x86\x92 Client)\n\n@param Target - Actor that lost lock" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockLost_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetingComponent_eventClientRPC_OnLockLost_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockLost_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockLost_Statics::NewProp_Target,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockLost_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockLost_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTargetingComponent, nullptr, "ClientRPC_OnLockLost", Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockLost_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockLost_Statics::PropPointers), sizeof(TargetingComponent_eventClientRPC_OnLockLost_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockLost_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockLost_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(TargetingComponent_eventClientRPC_OnLockLost_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockLost()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockLost_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTargetingComponent::execClientRPC_OnLockLost)
{
	P_GET_OBJECT(AActor,Z_Param_Target);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientRPC_OnLockLost_Implementation(Z_Param_Target);
	P_NATIVE_END;
}
// ********** End Class UTargetingComponent Function ClientRPC_OnLockLost **************************

// ********** Begin Class UTargetingComponent Function ClientRPC_OnLockStarted *********************
struct TargetingComponent_eventClientRPC_OnLockStarted_Parms
{
	AActor* Target;
};
static FName NAME_UTargetingComponent_ClientRPC_OnLockStarted = FName(TEXT("ClientRPC_OnLockStarted"));
void UTargetingComponent::ClientRPC_OnLockStarted(AActor* Target)
{
	TargetingComponent_eventClientRPC_OnLockStarted_Parms Parms;
	Parms.Target=Target;
	UFunction* Func = FindFunctionChecked(NAME_UTargetingComponent_ClientRPC_OnLockStarted);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockStarted_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Targeting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Notify client that lock has started (Server \xe2\x86\x92 Client)\n\x09 * \n\x09 * @param Target - Actor being locked\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Notify client that lock has started (Server \xe2\x86\x92 Client)\n\n@param Target - Actor being locked" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockStarted_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetingComponent_eventClientRPC_OnLockStarted_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockStarted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockStarted_Statics::NewProp_Target,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockStarted_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockStarted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTargetingComponent, nullptr, "ClientRPC_OnLockStarted", Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockStarted_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockStarted_Statics::PropPointers), sizeof(TargetingComponent_eventClientRPC_OnLockStarted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01020CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockStarted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockStarted_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(TargetingComponent_eventClientRPC_OnLockStarted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockStarted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockStarted_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTargetingComponent::execClientRPC_OnLockStarted)
{
	P_GET_OBJECT(AActor,Z_Param_Target);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientRPC_OnLockStarted_Implementation(Z_Param_Target);
	P_NATIVE_END;
}
// ********** End Class UTargetingComponent Function ClientRPC_OnLockStarted ***********************

// ********** Begin Class UTargetingComponent Function Common_CalculateLockTime ********************
struct Z_Construct_UFunction_UTargetingComponent_Common_CalculateLockTime_Statics
{
	struct TargetingComponent_eventCommon_CalculateLockTime_Parms
	{
		AActor* Target;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Targeting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Calculate required lock time for target (Pure function)\n\x09 * Formula: T = k / (ScanResolution \xc3\x97 ln(TargetSize))\n\x09 * \n\x09 * @param Target - Target actor\n\x09 * @return Required lock time in seconds\n\x09 * \n\x09 * Notes:\n\x09 * - Uses target's signature radius if available\n\x09 * - Falls back to bounding box size if no signature\n\x09 * - Returns 0.0 if target is invalid\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Calculate required lock time for target (Pure function)\nFormula: T = k / (ScanResolution \xc3\x97 ln(TargetSize))\n\n@param Target - Target actor\n@return Required lock time in seconds\n\nNotes:\n- Uses target's signature radius if available\n- Falls back to bounding box size if no signature\n- Returns 0.0 if target is invalid" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTargetingComponent_Common_CalculateLockTime_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetingComponent_eventCommon_CalculateLockTime_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UTargetingComponent_Common_CalculateLockTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetingComponent_eventCommon_CalculateLockTime_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTargetingComponent_Common_CalculateLockTime_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetingComponent_Common_CalculateLockTime_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetingComponent_Common_CalculateLockTime_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_Common_CalculateLockTime_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTargetingComponent_Common_CalculateLockTime_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTargetingComponent, nullptr, "Common_CalculateLockTime", Z_Construct_UFunction_UTargetingComponent_Common_CalculateLockTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_Common_CalculateLockTime_Statics::PropPointers), sizeof(Z_Construct_UFunction_UTargetingComponent_Common_CalculateLockTime_Statics::TargetingComponent_eventCommon_CalculateLockTime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_Common_CalculateLockTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTargetingComponent_Common_CalculateLockTime_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UTargetingComponent_Common_CalculateLockTime_Statics::TargetingComponent_eventCommon_CalculateLockTime_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTargetingComponent_Common_CalculateLockTime()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTargetingComponent_Common_CalculateLockTime_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTargetingComponent::execCommon_CalculateLockTime)
{
	P_GET_OBJECT(AActor,Z_Param_Target);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->Common_CalculateLockTime(Z_Param_Target);
	P_NATIVE_END;
}
// ********** End Class UTargetingComponent Function Common_CalculateLockTime **********************

// ********** Begin Class UTargetingComponent Function Common_GetAvailableLockSlots ****************
struct Z_Construct_UFunction_UTargetingComponent_Common_GetAvailableLockSlots_Statics
{
	struct TargetingComponent_eventCommon_GetAvailableLockSlots_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Targeting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get number of available lock slots (Pure function)\n\x09 * \n\x09 * @return Number of remaining lock slots\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get number of available lock slots (Pure function)\n\n@return Number of remaining lock slots" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UTargetingComponent_Common_GetAvailableLockSlots_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetingComponent_eventCommon_GetAvailableLockSlots_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTargetingComponent_Common_GetAvailableLockSlots_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetingComponent_Common_GetAvailableLockSlots_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_Common_GetAvailableLockSlots_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTargetingComponent_Common_GetAvailableLockSlots_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTargetingComponent, nullptr, "Common_GetAvailableLockSlots", Z_Construct_UFunction_UTargetingComponent_Common_GetAvailableLockSlots_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_Common_GetAvailableLockSlots_Statics::PropPointers), sizeof(Z_Construct_UFunction_UTargetingComponent_Common_GetAvailableLockSlots_Statics::TargetingComponent_eventCommon_GetAvailableLockSlots_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_Common_GetAvailableLockSlots_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTargetingComponent_Common_GetAvailableLockSlots_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UTargetingComponent_Common_GetAvailableLockSlots_Statics::TargetingComponent_eventCommon_GetAvailableLockSlots_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTargetingComponent_Common_GetAvailableLockSlots()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTargetingComponent_Common_GetAvailableLockSlots_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTargetingComponent::execCommon_GetAvailableLockSlots)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->Common_GetAvailableLockSlots();
	P_NATIVE_END;
}
// ********** End Class UTargetingComponent Function Common_GetAvailableLockSlots ******************

// ********** Begin Class UTargetingComponent Function Common_GetLockedTargets *********************
struct Z_Construct_UFunction_UTargetingComponent_Common_GetLockedTargets_Statics
{
	struct TargetingComponent_eventCommon_GetLockedTargets_Parms
	{
		TArray<AActor*> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Targeting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get all locked targets (Pure function)\n\x09 * \n\x09 * @return Array of locked target actors\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get all locked targets (Pure function)\n\n@return Array of locked target actors" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTargetingComponent_Common_GetLockedTargets_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UTargetingComponent_Common_GetLockedTargets_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetingComponent_eventCommon_GetLockedTargets_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTargetingComponent_Common_GetLockedTargets_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetingComponent_Common_GetLockedTargets_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetingComponent_Common_GetLockedTargets_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_Common_GetLockedTargets_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTargetingComponent_Common_GetLockedTargets_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTargetingComponent, nullptr, "Common_GetLockedTargets", Z_Construct_UFunction_UTargetingComponent_Common_GetLockedTargets_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_Common_GetLockedTargets_Statics::PropPointers), sizeof(Z_Construct_UFunction_UTargetingComponent_Common_GetLockedTargets_Statics::TargetingComponent_eventCommon_GetLockedTargets_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_Common_GetLockedTargets_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTargetingComponent_Common_GetLockedTargets_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UTargetingComponent_Common_GetLockedTargets_Statics::TargetingComponent_eventCommon_GetLockedTargets_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTargetingComponent_Common_GetLockedTargets()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTargetingComponent_Common_GetLockedTargets_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTargetingComponent::execCommon_GetLockedTargets)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<AActor*>*)Z_Param__Result=P_THIS->Common_GetLockedTargets();
	P_NATIVE_END;
}
// ********** End Class UTargetingComponent Function Common_GetLockedTargets ***********************

// ********** Begin Class UTargetingComponent Function Common_GetLockProgress **********************
struct Z_Construct_UFunction_UTargetingComponent_Common_GetLockProgress_Statics
{
	struct TargetingComponent_eventCommon_GetLockProgress_Parms
	{
		AActor* Target;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Targeting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get lock progress for specific target (Pure function)\n\x09 * \n\x09 * @param Target - Target actor\n\x09 * @return Lock progress (0.0 to 1.0), or -1.0 if not found\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get lock progress for specific target (Pure function)\n\n@param Target - Target actor\n@return Lock progress (0.0 to 1.0), or -1.0 if not found" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTargetingComponent_Common_GetLockProgress_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetingComponent_eventCommon_GetLockProgress_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UTargetingComponent_Common_GetLockProgress_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetingComponent_eventCommon_GetLockProgress_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTargetingComponent_Common_GetLockProgress_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetingComponent_Common_GetLockProgress_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetingComponent_Common_GetLockProgress_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_Common_GetLockProgress_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTargetingComponent_Common_GetLockProgress_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTargetingComponent, nullptr, "Common_GetLockProgress", Z_Construct_UFunction_UTargetingComponent_Common_GetLockProgress_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_Common_GetLockProgress_Statics::PropPointers), sizeof(Z_Construct_UFunction_UTargetingComponent_Common_GetLockProgress_Statics::TargetingComponent_eventCommon_GetLockProgress_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_Common_GetLockProgress_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTargetingComponent_Common_GetLockProgress_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UTargetingComponent_Common_GetLockProgress_Statics::TargetingComponent_eventCommon_GetLockProgress_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTargetingComponent_Common_GetLockProgress()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTargetingComponent_Common_GetLockProgress_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTargetingComponent::execCommon_GetLockProgress)
{
	P_GET_OBJECT(AActor,Z_Param_Target);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->Common_GetLockProgress(Z_Param_Target);
	P_NATIVE_END;
}
// ********** End Class UTargetingComponent Function Common_GetLockProgress ************************

// ********** Begin Class UTargetingComponent Function Common_GetLockState *************************
struct Z_Construct_UFunction_UTargetingComponent_Common_GetLockState_Statics
{
	struct TargetingComponent_eventCommon_GetLockState_Parms
	{
		AActor* Target;
		ETargetLockState ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Targeting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get lock state for specific target (Pure function)\n\x09 * \n\x09 * @param Target - Target actor\n\x09 * @return Lock state, or None if not found\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get lock state for specific target (Pure function)\n\n@param Target - Target actor\n@return Lock state, or None if not found" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTargetingComponent_Common_GetLockState_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetingComponent_eventCommon_GetLockState_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UTargetingComponent_Common_GetLockState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UTargetingComponent_Common_GetLockState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetingComponent_eventCommon_GetLockState_Parms, ReturnValue), Z_Construct_UEnum_Echoes_ETargetLockState, METADATA_PARAMS(0, nullptr) }; // 2896437216
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTargetingComponent_Common_GetLockState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetingComponent_Common_GetLockState_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetingComponent_Common_GetLockState_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetingComponent_Common_GetLockState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_Common_GetLockState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTargetingComponent_Common_GetLockState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTargetingComponent, nullptr, "Common_GetLockState", Z_Construct_UFunction_UTargetingComponent_Common_GetLockState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_Common_GetLockState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UTargetingComponent_Common_GetLockState_Statics::TargetingComponent_eventCommon_GetLockState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_Common_GetLockState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTargetingComponent_Common_GetLockState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UTargetingComponent_Common_GetLockState_Statics::TargetingComponent_eventCommon_GetLockState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTargetingComponent_Common_GetLockState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTargetingComponent_Common_GetLockState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTargetingComponent::execCommon_GetLockState)
{
	P_GET_OBJECT(AActor,Z_Param_Target);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ETargetLockState*)Z_Param__Result=P_THIS->Common_GetLockState(Z_Param_Target);
	P_NATIVE_END;
}
// ********** End Class UTargetingComponent Function Common_GetLockState ***************************

// ********** Begin Class UTargetingComponent Function Common_GetTargetSignatureRadius *************
struct Z_Construct_UFunction_UTargetingComponent_Common_GetTargetSignatureRadius_Statics
{
	struct TargetingComponent_eventCommon_GetTargetSignatureRadius_Parms
	{
		AActor* Target;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Targeting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get target's signature radius (Pure function)\n\x09 * \n\x09 * @param Target - Target actor\n\x09 * @return Signature radius in meters\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get target's signature radius (Pure function)\n\n@param Target - Target actor\n@return Signature radius in meters" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTargetingComponent_Common_GetTargetSignatureRadius_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetingComponent_eventCommon_GetTargetSignatureRadius_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UTargetingComponent_Common_GetTargetSignatureRadius_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetingComponent_eventCommon_GetTargetSignatureRadius_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTargetingComponent_Common_GetTargetSignatureRadius_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetingComponent_Common_GetTargetSignatureRadius_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetingComponent_Common_GetTargetSignatureRadius_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_Common_GetTargetSignatureRadius_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTargetingComponent_Common_GetTargetSignatureRadius_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTargetingComponent, nullptr, "Common_GetTargetSignatureRadius", Z_Construct_UFunction_UTargetingComponent_Common_GetTargetSignatureRadius_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_Common_GetTargetSignatureRadius_Statics::PropPointers), sizeof(Z_Construct_UFunction_UTargetingComponent_Common_GetTargetSignatureRadius_Statics::TargetingComponent_eventCommon_GetTargetSignatureRadius_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_Common_GetTargetSignatureRadius_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTargetingComponent_Common_GetTargetSignatureRadius_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UTargetingComponent_Common_GetTargetSignatureRadius_Statics::TargetingComponent_eventCommon_GetTargetSignatureRadius_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTargetingComponent_Common_GetTargetSignatureRadius()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTargetingComponent_Common_GetTargetSignatureRadius_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTargetingComponent::execCommon_GetTargetSignatureRadius)
{
	P_GET_OBJECT(AActor,Z_Param_Target);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->Common_GetTargetSignatureRadius(Z_Param_Target);
	P_NATIVE_END;
}
// ********** End Class UTargetingComponent Function Common_GetTargetSignatureRadius ***************

// ********** Begin Class UTargetingComponent Function Common_IsTargetInRange **********************
struct Z_Construct_UFunction_UTargetingComponent_Common_IsTargetInRange_Statics
{
	struct TargetingComponent_eventCommon_IsTargetInRange_Parms
	{
		AActor* Target;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Targeting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if target is within lock range (Pure function)\n\x09 * \n\x09 * @param Target - Target actor\n\x09 * @return True if within MaxLockRange\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if target is within lock range (Pure function)\n\n@param Target - Target actor\n@return True if within MaxLockRange" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTargetingComponent_Common_IsTargetInRange_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetingComponent_eventCommon_IsTargetInRange_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UTargetingComponent_Common_IsTargetInRange_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((TargetingComponent_eventCommon_IsTargetInRange_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UTargetingComponent_Common_IsTargetInRange_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(TargetingComponent_eventCommon_IsTargetInRange_Parms), &Z_Construct_UFunction_UTargetingComponent_Common_IsTargetInRange_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTargetingComponent_Common_IsTargetInRange_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetingComponent_Common_IsTargetInRange_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetingComponent_Common_IsTargetInRange_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_Common_IsTargetInRange_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTargetingComponent_Common_IsTargetInRange_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTargetingComponent, nullptr, "Common_IsTargetInRange", Z_Construct_UFunction_UTargetingComponent_Common_IsTargetInRange_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_Common_IsTargetInRange_Statics::PropPointers), sizeof(Z_Construct_UFunction_UTargetingComponent_Common_IsTargetInRange_Statics::TargetingComponent_eventCommon_IsTargetInRange_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_Common_IsTargetInRange_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTargetingComponent_Common_IsTargetInRange_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UTargetingComponent_Common_IsTargetInRange_Statics::TargetingComponent_eventCommon_IsTargetInRange_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTargetingComponent_Common_IsTargetInRange()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTargetingComponent_Common_IsTargetInRange_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTargetingComponent::execCommon_IsTargetInRange)
{
	P_GET_OBJECT(AActor,Z_Param_Target);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->Common_IsTargetInRange(Z_Param_Target);
	P_NATIVE_END;
}
// ********** End Class UTargetingComponent Function Common_IsTargetInRange ************************

// ********** Begin Class UTargetingComponent Function Common_IsTargetLocked ***********************
struct Z_Construct_UFunction_UTargetingComponent_Common_IsTargetLocked_Statics
{
	struct TargetingComponent_eventCommon_IsTargetLocked_Parms
	{
		AActor* Target;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Targeting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if target is locked (Pure function)\n\x09 * \n\x09 * @param Target - Target actor\n\x09 * @return True if target is fully locked\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if target is locked (Pure function)\n\n@param Target - Target actor\n@return True if target is fully locked" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTargetingComponent_Common_IsTargetLocked_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetingComponent_eventCommon_IsTargetLocked_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UTargetingComponent_Common_IsTargetLocked_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((TargetingComponent_eventCommon_IsTargetLocked_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UTargetingComponent_Common_IsTargetLocked_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(TargetingComponent_eventCommon_IsTargetLocked_Parms), &Z_Construct_UFunction_UTargetingComponent_Common_IsTargetLocked_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTargetingComponent_Common_IsTargetLocked_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetingComponent_Common_IsTargetLocked_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetingComponent_Common_IsTargetLocked_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_Common_IsTargetLocked_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTargetingComponent_Common_IsTargetLocked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTargetingComponent, nullptr, "Common_IsTargetLocked", Z_Construct_UFunction_UTargetingComponent_Common_IsTargetLocked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_Common_IsTargetLocked_Statics::PropPointers), sizeof(Z_Construct_UFunction_UTargetingComponent_Common_IsTargetLocked_Statics::TargetingComponent_eventCommon_IsTargetLocked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_Common_IsTargetLocked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTargetingComponent_Common_IsTargetLocked_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UTargetingComponent_Common_IsTargetLocked_Statics::TargetingComponent_eventCommon_IsTargetLocked_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTargetingComponent_Common_IsTargetLocked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTargetingComponent_Common_IsTargetLocked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTargetingComponent::execCommon_IsTargetLocked)
{
	P_GET_OBJECT(AActor,Z_Param_Target);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->Common_IsTargetLocked(Z_Param_Target);
	P_NATIVE_END;
}
// ********** End Class UTargetingComponent Function Common_IsTargetLocked *************************

// ********** Begin Class UTargetingComponent Function ServerRPC_CancelLock ************************
struct TargetingComponent_eventServerRPC_CancelLock_Parms
{
	AActor* Target;
};
static FName NAME_UTargetingComponent_ServerRPC_CancelLock = FName(TEXT("ServerRPC_CancelLock"));
void UTargetingComponent::ServerRPC_CancelLock(AActor* Target)
{
	TargetingComponent_eventServerRPC_CancelLock_Parms Parms;
	Parms.Target=Target;
	UFunction* Func = FindFunctionChecked(NAME_UTargetingComponent_ServerRPC_CancelLock);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UTargetingComponent_ServerRPC_CancelLock_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Targeting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Request target lock cancellation (Client \xe2\x86\x92 Server)\n\x09 * \n\x09 * @param Target - Actor to cancel lock on\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Request target lock cancellation (Client \xe2\x86\x92 Server)\n\n@param Target - Actor to cancel lock on" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTargetingComponent_ServerRPC_CancelLock_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetingComponent_eventServerRPC_CancelLock_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTargetingComponent_ServerRPC_CancelLock_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetingComponent_ServerRPC_CancelLock_Statics::NewProp_Target,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_ServerRPC_CancelLock_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTargetingComponent_ServerRPC_CancelLock_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTargetingComponent, nullptr, "ServerRPC_CancelLock", Z_Construct_UFunction_UTargetingComponent_ServerRPC_CancelLock_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_ServerRPC_CancelLock_Statics::PropPointers), sizeof(TargetingComponent_eventServerRPC_CancelLock_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_ServerRPC_CancelLock_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTargetingComponent_ServerRPC_CancelLock_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(TargetingComponent_eventServerRPC_CancelLock_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTargetingComponent_ServerRPC_CancelLock()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTargetingComponent_ServerRPC_CancelLock_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTargetingComponent::execServerRPC_CancelLock)
{
	P_GET_OBJECT(AActor,Z_Param_Target);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerRPC_CancelLock_Implementation(Z_Param_Target);
	P_NATIVE_END;
}
// ********** End Class UTargetingComponent Function ServerRPC_CancelLock **************************

// ********** Begin Class UTargetingComponent Function ServerRPC_ClearAllLocks *********************
static FName NAME_UTargetingComponent_ServerRPC_ClearAllLocks = FName(TEXT("ServerRPC_ClearAllLocks"));
void UTargetingComponent::ServerRPC_ClearAllLocks()
{
	UFunction* Func = FindFunctionChecked(NAME_UTargetingComponent_ServerRPC_ClearAllLocks);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_UTargetingComponent_ServerRPC_ClearAllLocks_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Targeting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Clear all locks (Client \xe2\x86\x92 Server)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Clear all locks (Client \xe2\x86\x92 Server)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTargetingComponent_ServerRPC_ClearAllLocks_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTargetingComponent, nullptr, "ServerRPC_ClearAllLocks", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_ServerRPC_ClearAllLocks_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTargetingComponent_ServerRPC_ClearAllLocks_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UTargetingComponent_ServerRPC_ClearAllLocks()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTargetingComponent_ServerRPC_ClearAllLocks_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTargetingComponent::execServerRPC_ClearAllLocks)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerRPC_ClearAllLocks_Implementation();
	P_NATIVE_END;
}
// ********** End Class UTargetingComponent Function ServerRPC_ClearAllLocks ***********************

// ********** Begin Class UTargetingComponent Function ServerRPC_StartLock *************************
struct TargetingComponent_eventServerRPC_StartLock_Parms
{
	AActor* Target;
};
static FName NAME_UTargetingComponent_ServerRPC_StartLock = FName(TEXT("ServerRPC_StartLock"));
void UTargetingComponent::ServerRPC_StartLock(AActor* Target)
{
	TargetingComponent_eventServerRPC_StartLock_Parms Parms;
	Parms.Target=Target;
	UFunction* Func = FindFunctionChecked(NAME_UTargetingComponent_ServerRPC_StartLock);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UTargetingComponent_ServerRPC_StartLock_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Targeting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Request target lock acquisition (Client \xe2\x86\x92 Server)\n\x09 * Server validates distance and signature radius, then starts lock timer\n\x09 * \n\x09 * @param Target - Actor to lock onto\n\x09 * \n\x09 * Validation:\n\x09 * - Server authority check\n\x09 * - Target exists and is valid\n\x09 * - Target within MaxLockRange\n\x09 * - Not already locked/locking this target\n\x09 * - Available lock slot (< MaxSimultaneousLocks)\n\x09 * - Target has signature radius (for lock time calculation)\n\x09 * \n\x09 * Success:\n\x09 * - Adds target to TargetLocks array\n\x09 * - Calculates required lock time\n\x09 * - Notifies client via ClientRPC_OnLockStarted\n\x09 * - Broadcasts OnLockStarted event\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Request target lock acquisition (Client \xe2\x86\x92 Server)\nServer validates distance and signature radius, then starts lock timer\n\n@param Target - Actor to lock onto\n\nValidation:\n- Server authority check\n- Target exists and is valid\n- Target within MaxLockRange\n- Not already locked/locking this target\n- Available lock slot (< MaxSimultaneousLocks)\n- Target has signature radius (for lock time calculation)\n\nSuccess:\n- Adds target to TargetLocks array\n- Calculates required lock time\n- Notifies client via ClientRPC_OnLockStarted\n- Broadcasts OnLockStarted event" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UTargetingComponent_ServerRPC_StartLock_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(TargetingComponent_eventServerRPC_StartLock_Parms, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UTargetingComponent_ServerRPC_StartLock_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UTargetingComponent_ServerRPC_StartLock_Statics::NewProp_Target,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_ServerRPC_StartLock_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UTargetingComponent_ServerRPC_StartLock_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UTargetingComponent, nullptr, "ServerRPC_StartLock", Z_Construct_UFunction_UTargetingComponent_ServerRPC_StartLock_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_ServerRPC_StartLock_Statics::PropPointers), sizeof(TargetingComponent_eventServerRPC_StartLock_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UTargetingComponent_ServerRPC_StartLock_Statics::Function_MetaDataParams), Z_Construct_UFunction_UTargetingComponent_ServerRPC_StartLock_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(TargetingComponent_eventServerRPC_StartLock_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UTargetingComponent_ServerRPC_StartLock()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UTargetingComponent_ServerRPC_StartLock_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UTargetingComponent::execServerRPC_StartLock)
{
	P_GET_OBJECT(AActor,Z_Param_Target);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerRPC_StartLock_Implementation(Z_Param_Target);
	P_NATIVE_END;
}
// ********** End Class UTargetingComponent Function ServerRPC_StartLock ***************************

// ********** Begin Class UTargetingComponent ******************************************************
void UTargetingComponent::StaticRegisterNativesUTargetingComponent()
{
	UClass* Class = UTargetingComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ClientRPC_OnLockCompleted", &UTargetingComponent::execClientRPC_OnLockCompleted },
		{ "ClientRPC_OnLockLost", &UTargetingComponent::execClientRPC_OnLockLost },
		{ "ClientRPC_OnLockStarted", &UTargetingComponent::execClientRPC_OnLockStarted },
		{ "Common_CalculateLockTime", &UTargetingComponent::execCommon_CalculateLockTime },
		{ "Common_GetAvailableLockSlots", &UTargetingComponent::execCommon_GetAvailableLockSlots },
		{ "Common_GetLockedTargets", &UTargetingComponent::execCommon_GetLockedTargets },
		{ "Common_GetLockProgress", &UTargetingComponent::execCommon_GetLockProgress },
		{ "Common_GetLockState", &UTargetingComponent::execCommon_GetLockState },
		{ "Common_GetTargetSignatureRadius", &UTargetingComponent::execCommon_GetTargetSignatureRadius },
		{ "Common_IsTargetInRange", &UTargetingComponent::execCommon_IsTargetInRange },
		{ "Common_IsTargetLocked", &UTargetingComponent::execCommon_IsTargetLocked },
		{ "ServerRPC_CancelLock", &UTargetingComponent::execServerRPC_CancelLock },
		{ "ServerRPC_ClearAllLocks", &UTargetingComponent::execServerRPC_ClearAllLocks },
		{ "ServerRPC_StartLock", &UTargetingComponent::execServerRPC_StartLock },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UTargetingComponent;
UClass* UTargetingComponent::GetPrivateStaticClass()
{
	using TClass = UTargetingComponent;
	if (!Z_Registration_Info_UClass_UTargetingComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("TargetingComponent"),
			Z_Registration_Info_UClass_UTargetingComponent.InnerSingleton,
			StaticRegisterNativesUTargetingComponent,
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
	return Z_Registration_Info_UClass_UTargetingComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UTargetingComponent_NoRegister()
{
	return UTargetingComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UTargetingComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Echoes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UTargetingComponent\n * \n * EVE-like target lock system for ship-to-ship combat\n * Manages acquisition and maintenance of target locks with server authority\n * \n * Architecture:\n * - ActorComponent: Attached to ship pawns\n * - Server-authoritative: Server controls all lock timers and validation\n * - Client-initiated: Client requests lock, server validates and processes\n * - Multiple targets: Supports locking multiple targets simultaneously\n * \n * Lock Acquisition:\n * 1. Client calls ServerRPC_StartLock(Target)\n * 2. Server validates distance and signature radius\n * 3. Server calculates lock time: T = k / (ScanResolution \xc3\x97 ln(TargetSize))\n * 4. Server ticks lock progress\n * 5. Server notifies client when lock completes\n * \n * Network Model:\n * - ServerRPC_: Client requests from server\n * - ClientRPC_: Server notifies client\n * - Common_: Shared calculation functions\n * \n * Usage:\n * // Attach to ship pawn\n * TargetingComp = CreateDefaultSubobject<UTargetingComponent>(TEXT(\"Targeting\"));\n * \n * // Request lock (client)\n * TargetingComp->ServerRPC_StartLock(EnemyShip);\n * \n * // Bind UI events\n * TargetingComp->OnLockStarted.AddDynamic(this, &UWidget::HandleLockStarted);\n * TargetingComp->OnLockCompleted.AddDynamic(this, &UWidget::HandleLockCompleted);\n */" },
#endif
		{ "IncludePath", "Core/Common/Components/TargetingComponent.h" },
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UTargetingComponent\n\nEVE-like target lock system for ship-to-ship combat\nManages acquisition and maintenance of target locks with server authority\n\nArchitecture:\n- ActorComponent: Attached to ship pawns\n- Server-authoritative: Server controls all lock timers and validation\n- Client-initiated: Client requests lock, server validates and processes\n- Multiple targets: Supports locking multiple targets simultaneously\n\nLock Acquisition:\n1. Client calls ServerRPC_StartLock(Target)\n2. Server validates distance and signature radius\n3. Server calculates lock time: T = k / (ScanResolution \xc3\x97 ln(TargetSize))\n4. Server ticks lock progress\n5. Server notifies client when lock completes\n\nNetwork Model:\n- ServerRPC_: Client requests from server\n- ClientRPC_: Server notifies client\n- Common_: Shared calculation functions\n\nUsage:\n// Attach to ship pawn\nTargetingComp = CreateDefaultSubobject<UTargetingComponent>(TEXT(\"Targeting\"));\n\n// Request lock (client)\nTargetingComp->ServerRPC_StartLock(EnemyShip);\n\n// Bind UI events\nTargetingComp->OnLockStarted.AddDynamic(this, &UWidget::HandleLockStarted);\nTargetingComp->OnLockCompleted.AddDynamic(this, &UWidget::HandleLockCompleted);" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxLockRange_MetaData[] = {
		{ "Category", "Targeting|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum lock range in cm (default: 25000m = 2500000cm) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum lock range in cm (default: 25000m = 2500000cm)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScanResolution_MetaData[] = {
		{ "Category", "Targeting|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Scan resolution of this ship (affects lock speed) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Scan resolution of this ship (affects lock speed)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LockTimeConstant_MetaData[] = {
		{ "Category", "Targeting|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Lock time formula constant (k in T = k / (ScanResolution \xc3\x97 ln(TargetSize))) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lock time formula constant (k in T = k / (ScanResolution \xc3\x97 ln(TargetSize)))" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxSimultaneousLocks_MetaData[] = {
		{ "Category", "Targeting|Config" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum number of simultaneous locks */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum number of simultaneous locks" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetLocks_MetaData[] = {
		{ "Category", "Targeting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Array of current target locks */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Array of current target locks" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnLockStarted_MetaData[] = {
		{ "Category", "Targeting|Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when target lock acquisition starts */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when target lock acquisition starts" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnLockCompleted_MetaData[] = {
		{ "Category", "Targeting|Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when target lock is completed */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when target lock is completed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnLockLost_MetaData[] = {
		{ "Category", "Targeting|Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when target lock is lost */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when target lock is lost" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnLockProgress_MetaData[] = {
		{ "Category", "Targeting|Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when lock progress updates (per tick) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Components/TargetingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when lock progress updates (per tick)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxLockRange;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ScanResolution;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LockTimeConstant;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxSimultaneousLocks;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetLocks_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_TargetLocks;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnLockStarted;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnLockCompleted;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnLockLost;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnLockProgress;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockCompleted, "ClientRPC_OnLockCompleted" }, // 2413882584
		{ &Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockLost, "ClientRPC_OnLockLost" }, // 2412122769
		{ &Z_Construct_UFunction_UTargetingComponent_ClientRPC_OnLockStarted, "ClientRPC_OnLockStarted" }, // 1546835522
		{ &Z_Construct_UFunction_UTargetingComponent_Common_CalculateLockTime, "Common_CalculateLockTime" }, // 4277338306
		{ &Z_Construct_UFunction_UTargetingComponent_Common_GetAvailableLockSlots, "Common_GetAvailableLockSlots" }, // 1255742497
		{ &Z_Construct_UFunction_UTargetingComponent_Common_GetLockedTargets, "Common_GetLockedTargets" }, // 570566272
		{ &Z_Construct_UFunction_UTargetingComponent_Common_GetLockProgress, "Common_GetLockProgress" }, // 1371197366
		{ &Z_Construct_UFunction_UTargetingComponent_Common_GetLockState, "Common_GetLockState" }, // 569141416
		{ &Z_Construct_UFunction_UTargetingComponent_Common_GetTargetSignatureRadius, "Common_GetTargetSignatureRadius" }, // 586739817
		{ &Z_Construct_UFunction_UTargetingComponent_Common_IsTargetInRange, "Common_IsTargetInRange" }, // 1556395749
		{ &Z_Construct_UFunction_UTargetingComponent_Common_IsTargetLocked, "Common_IsTargetLocked" }, // 3639239179
		{ &Z_Construct_UFunction_UTargetingComponent_ServerRPC_CancelLock, "ServerRPC_CancelLock" }, // 924480706
		{ &Z_Construct_UFunction_UTargetingComponent_ServerRPC_ClearAllLocks, "ServerRPC_ClearAllLocks" }, // 2645675092
		{ &Z_Construct_UFunction_UTargetingComponent_ServerRPC_StartLock, "ServerRPC_StartLock" }, // 2373442958
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTargetingComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UTargetingComponent_Statics::NewProp_MaxLockRange = { "MaxLockRange", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTargetingComponent, MaxLockRange), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxLockRange_MetaData), NewProp_MaxLockRange_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UTargetingComponent_Statics::NewProp_ScanResolution = { "ScanResolution", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTargetingComponent, ScanResolution), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScanResolution_MetaData), NewProp_ScanResolution_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UTargetingComponent_Statics::NewProp_LockTimeConstant = { "LockTimeConstant", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTargetingComponent, LockTimeConstant), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LockTimeConstant_MetaData), NewProp_LockTimeConstant_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UTargetingComponent_Statics::NewProp_MaxSimultaneousLocks = { "MaxSimultaneousLocks", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTargetingComponent, MaxSimultaneousLocks), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxSimultaneousLocks_MetaData), NewProp_MaxSimultaneousLocks_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UTargetingComponent_Statics::NewProp_TargetLocks_Inner = { "TargetLocks", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FTargetLockEntry, METADATA_PARAMS(0, nullptr) }; // 3920724976
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UTargetingComponent_Statics::NewProp_TargetLocks = { "TargetLocks", nullptr, (EPropertyFlags)0x0010000000000034, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTargetingComponent, TargetLocks), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetLocks_MetaData), NewProp_TargetLocks_MetaData) }; // 3920724976
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UTargetingComponent_Statics::NewProp_OnLockStarted = { "OnLockStarted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTargetingComponent, OnLockStarted), Z_Construct_UDelegateFunction_Echoes_OnLockStarted__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnLockStarted_MetaData), NewProp_OnLockStarted_MetaData) }; // 656116060
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UTargetingComponent_Statics::NewProp_OnLockCompleted = { "OnLockCompleted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTargetingComponent, OnLockCompleted), Z_Construct_UDelegateFunction_Echoes_OnLockCompleted__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnLockCompleted_MetaData), NewProp_OnLockCompleted_MetaData) }; // 2431642937
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UTargetingComponent_Statics::NewProp_OnLockLost = { "OnLockLost", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTargetingComponent, OnLockLost), Z_Construct_UDelegateFunction_Echoes_OnLockLost__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnLockLost_MetaData), NewProp_OnLockLost_MetaData) }; // 1857904885
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UTargetingComponent_Statics::NewProp_OnLockProgress = { "OnLockProgress", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTargetingComponent, OnLockProgress), Z_Construct_UDelegateFunction_Echoes_OnLockProgress__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnLockProgress_MetaData), NewProp_OnLockProgress_MetaData) }; // 1524044464
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UTargetingComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTargetingComponent_Statics::NewProp_MaxLockRange,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTargetingComponent_Statics::NewProp_ScanResolution,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTargetingComponent_Statics::NewProp_LockTimeConstant,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTargetingComponent_Statics::NewProp_MaxSimultaneousLocks,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTargetingComponent_Statics::NewProp_TargetLocks_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTargetingComponent_Statics::NewProp_TargetLocks,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTargetingComponent_Statics::NewProp_OnLockStarted,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTargetingComponent_Statics::NewProp_OnLockCompleted,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTargetingComponent_Statics::NewProp_OnLockLost,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTargetingComponent_Statics::NewProp_OnLockProgress,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTargetingComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UTargetingComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTargetingComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UTargetingComponent_Statics::ClassParams = {
	&UTargetingComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UTargetingComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UTargetingComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTargetingComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UTargetingComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UTargetingComponent()
{
	if (!Z_Registration_Info_UClass_UTargetingComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTargetingComponent.OuterSingleton, Z_Construct_UClass_UTargetingComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UTargetingComponent.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void UTargetingComponent::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_TargetLocks(TEXT("TargetLocks"));
	const bool bIsValid = true
		&& Name_TargetLocks == ClassReps[(int32)ENetFields_Private::TargetLocks].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in UTargetingComponent"));
}
#endif
DEFINE_VTABLE_PTR_HELPER_CTOR(UTargetingComponent);
UTargetingComponent::~UTargetingComponent() {}
// ********** End Class UTargetingComponent ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_TargetingComponent_h__Script_Echoes_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ETargetLockState_StaticEnum, TEXT("ETargetLockState"), &Z_Registration_Info_UEnum_ETargetLockState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2896437216U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FTargetLockEntry::StaticStruct, Z_Construct_UScriptStruct_FTargetLockEntry_Statics::NewStructOps, TEXT("TargetLockEntry"), &Z_Registration_Info_UScriptStruct_FTargetLockEntry, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FTargetLockEntry), 3920724976U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UTargetingComponent, UTargetingComponent::StaticClass, TEXT("UTargetingComponent"), &Z_Registration_Info_UClass_UTargetingComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTargetingComponent), 832056974U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_TargetingComponent_h__Script_Echoes_3687214833(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_TargetingComponent_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_TargetingComponent_h__Script_Echoes_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_TargetingComponent_h__Script_Echoes_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_TargetingComponent_h__Script_Echoes_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_TargetingComponent_h__Script_Echoes_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Components_TargetingComponent_h__Script_Echoes_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
