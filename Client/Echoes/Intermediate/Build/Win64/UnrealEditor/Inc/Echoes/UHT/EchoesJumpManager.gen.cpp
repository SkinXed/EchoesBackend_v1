// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Core/Common/EchoesJumpManager.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesJumpManager() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ECHOES_API UClass* Z_Construct_UClass_AEchoesWorldGenerator_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesJumpManager();
ECHOES_API UClass* Z_Construct_UClass_UEchoesJumpManager_NoRegister();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_EJumpState();
ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EJumpState ****************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EJumpState;
static UEnum* EJumpState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EJumpState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EJumpState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Echoes_EJumpState, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("EJumpState"));
	}
	return Z_Registration_Info_UEnum_EJumpState.OuterSingleton;
}
template<> ECHOES_API UEnum* StaticEnum<EJumpState>()
{
	return EJumpState_StaticEnum();
}
struct Z_Construct_UEnum_Echoes_EJumpState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Arriving.DisplayName", "Arriving" },
		{ "Arriving.Name", "EJumpState::Arriving" },
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Player state during jump\n */" },
#endif
		{ "Initiating.DisplayName", "Initiating" },
		{ "Initiating.Name", "EJumpState::Initiating" },
		{ "Jumping.DisplayName", "Jumping" },
		{ "Jumping.Name", "EJumpState::Jumping" },
		{ "ModuleRelativePath", "Core/Common/EchoesJumpManager.h" },
		{ "None.DisplayName", "None" },
		{ "None.Name", "EJumpState::None" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Player state during jump" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EJumpState::None", (int64)EJumpState::None },
		{ "EJumpState::Initiating", (int64)EJumpState::Initiating },
		{ "EJumpState::Jumping", (int64)EJumpState::Jumping },
		{ "EJumpState::Arriving", (int64)EJumpState::Arriving },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Echoes_EJumpState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	"EJumpState",
	"EJumpState",
	Z_Construct_UEnum_Echoes_EJumpState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_EJumpState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_EJumpState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Echoes_EJumpState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Echoes_EJumpState()
{
	if (!Z_Registration_Info_UEnum_EJumpState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EJumpState.InnerSingleton, Z_Construct_UEnum_Echoes_EJumpState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EJumpState.InnerSingleton;
}
// ********** End Enum EJumpState ******************************************************************

// ********** Begin Class UEchoesJumpManager Function ClientRPC_EndJumpSequence ********************
static FName NAME_UEchoesJumpManager_ClientRPC_EndJumpSequence = FName(TEXT("ClientRPC_EndJumpSequence"));
void UEchoesJumpManager::ClientRPC_EndJumpSequence()
{
	UFunction* Func = FindFunctionChecked(NAME_UEchoesJumpManager_ClientRPC_EndJumpSequence);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_EndJumpSequence_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * End jump sequence on client\n\x09 * Triggers fade in, unblocks input, removes effects\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesJumpManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "End jump sequence on client\nTriggers fade in, unblocks input, removes effects" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_EndJumpSequence_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesJumpManager, nullptr, "ClientRPC_EndJumpSequence", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01080CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_EndJumpSequence_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_EndJumpSequence_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_EndJumpSequence()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_EndJumpSequence_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesJumpManager::execClientRPC_EndJumpSequence)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientRPC_EndJumpSequence_Implementation();
	P_NATIVE_END;
}
// ********** End Class UEchoesJumpManager Function ClientRPC_EndJumpSequence **********************

// ********** Begin Class UEchoesJumpManager Function ClientRPC_StartJumpSequence ******************
struct EchoesJumpManager_eventClientRPC_StartJumpSequence_Parms
{
	float TransitionDuration;
};
static FName NAME_UEchoesJumpManager_ClientRPC_StartJumpSequence = FName(TEXT("ClientRPC_StartJumpSequence"));
void UEchoesJumpManager::ClientRPC_StartJumpSequence(float TransitionDuration)
{
	EchoesJumpManager_eventClientRPC_StartJumpSequence_Parms Parms;
	Parms.TransitionDuration=TransitionDuration;
	UFunction* Func = FindFunctionChecked(NAME_UEchoesJumpManager_ClientRPC_StartJumpSequence);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_StartJumpSequence_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Start jump sequence on client\n\x09 * Triggers fade out, warp tunnel effect, blocks input\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesJumpManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Start jump sequence on client\nTriggers fade out, warp tunnel effect, blocks input" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TransitionDuration;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_StartJumpSequence_Statics::NewProp_TransitionDuration = { "TransitionDuration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesJumpManager_eventClientRPC_StartJumpSequence_Parms, TransitionDuration), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_StartJumpSequence_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_StartJumpSequence_Statics::NewProp_TransitionDuration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_StartJumpSequence_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_StartJumpSequence_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesJumpManager, nullptr, "ClientRPC_StartJumpSequence", Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_StartJumpSequence_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_StartJumpSequence_Statics::PropPointers), sizeof(EchoesJumpManager_eventClientRPC_StartJumpSequence_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01080CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_StartJumpSequence_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_StartJumpSequence_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(EchoesJumpManager_eventClientRPC_StartJumpSequence_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_StartJumpSequence()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_StartJumpSequence_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesJumpManager::execClientRPC_StartJumpSequence)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_TransitionDuration);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientRPC_StartJumpSequence_Implementation(Z_Param_TransitionDuration);
	P_NATIVE_END;
}
// ********** End Class UEchoesJumpManager Function ClientRPC_StartJumpSequence ********************

// ********** Begin Class UEchoesJumpManager Function ClientRPC_UpdateJumpProgress *****************
struct EchoesJumpManager_eventClientRPC_UpdateJumpProgress_Parms
{
	float Progress;
};
static FName NAME_UEchoesJumpManager_ClientRPC_UpdateJumpProgress = FName(TEXT("ClientRPC_UpdateJumpProgress"));
void UEchoesJumpManager::ClientRPC_UpdateJumpProgress(float Progress)
{
	EchoesJumpManager_eventClientRPC_UpdateJumpProgress_Parms Parms;
	Parms.Progress=Progress;
	UFunction* Func = FindFunctionChecked(NAME_UEchoesJumpManager_ClientRPC_UpdateJumpProgress);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_UpdateJumpProgress_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Update jump progress on client (for HUD/effects)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesJumpManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Update jump progress on client (for HUD/effects)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Progress;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_UpdateJumpProgress_Statics::NewProp_Progress = { "Progress", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesJumpManager_eventClientRPC_UpdateJumpProgress_Parms, Progress), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_UpdateJumpProgress_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_UpdateJumpProgress_Statics::NewProp_Progress,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_UpdateJumpProgress_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_UpdateJumpProgress_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesJumpManager, nullptr, "ClientRPC_UpdateJumpProgress", Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_UpdateJumpProgress_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_UpdateJumpProgress_Statics::PropPointers), sizeof(EchoesJumpManager_eventClientRPC_UpdateJumpProgress_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01080CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_UpdateJumpProgress_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_UpdateJumpProgress_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(EchoesJumpManager_eventClientRPC_UpdateJumpProgress_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_UpdateJumpProgress()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_UpdateJumpProgress_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesJumpManager::execClientRPC_UpdateJumpProgress)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Progress);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientRPC_UpdateJumpProgress_Implementation(Z_Param_Progress);
	P_NATIVE_END;
}
// ********** End Class UEchoesJumpManager Function ClientRPC_UpdateJumpProgress *******************

// ********** Begin Class UEchoesJumpManager Function InitiateIntraServerJump **********************
struct Z_Construct_UFunction_UEchoesJumpManager_InitiateIntraServerJump_Statics
{
	struct EchoesJumpManager_eventInitiateIntraServerJump_Parms
	{
		APlayerController* PlayerController;
		FVector TargetLocation;
		FGuid TargetSystemId;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintAuthorityOnly", "" },
		{ "Category", "Jump|Execution" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Initiate an intra-server jump\n\x09 * Called by Stargate when target system is on this server\n\x09 * \n\x09 * @param PlayerController - Player requesting the jump\n\x09 * @param TargetLocation - Destination coordinates in world space\n\x09 * @param TargetSystemId - GUID of target system (for backend update)\n\x09 * @return true if jump initiated successfully\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesJumpManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initiate an intra-server jump\nCalled by Stargate when target system is on this server\n\n@param PlayerController - Player requesting the jump\n@param TargetLocation - Destination coordinates in world space\n@param TargetSystemId - GUID of target system (for backend update)\n@return true if jump initiated successfully" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetSystemId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetLocation;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetSystemId;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEchoesJumpManager_InitiateIntraServerJump_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesJumpManager_eventInitiateIntraServerJump_Parms, PlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesJumpManager_InitiateIntraServerJump_Statics::NewProp_TargetLocation = { "TargetLocation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesJumpManager_eventInitiateIntraServerJump_Parms, TargetLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetLocation_MetaData), NewProp_TargetLocation_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesJumpManager_InitiateIntraServerJump_Statics::NewProp_TargetSystemId = { "TargetSystemId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesJumpManager_eventInitiateIntraServerJump_Parms, TargetSystemId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetSystemId_MetaData), NewProp_TargetSystemId_MetaData) };
void Z_Construct_UFunction_UEchoesJumpManager_InitiateIntraServerJump_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesJumpManager_eventInitiateIntraServerJump_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEchoesJumpManager_InitiateIntraServerJump_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesJumpManager_eventInitiateIntraServerJump_Parms), &Z_Construct_UFunction_UEchoesJumpManager_InitiateIntraServerJump_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesJumpManager_InitiateIntraServerJump_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesJumpManager_InitiateIntraServerJump_Statics::NewProp_PlayerController,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesJumpManager_InitiateIntraServerJump_Statics::NewProp_TargetLocation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesJumpManager_InitiateIntraServerJump_Statics::NewProp_TargetSystemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesJumpManager_InitiateIntraServerJump_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesJumpManager_InitiateIntraServerJump_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesJumpManager_InitiateIntraServerJump_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesJumpManager, nullptr, "InitiateIntraServerJump", Z_Construct_UFunction_UEchoesJumpManager_InitiateIntraServerJump_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesJumpManager_InitiateIntraServerJump_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesJumpManager_InitiateIntraServerJump_Statics::EchoesJumpManager_eventInitiateIntraServerJump_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesJumpManager_InitiateIntraServerJump_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesJumpManager_InitiateIntraServerJump_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesJumpManager_InitiateIntraServerJump_Statics::EchoesJumpManager_eventInitiateIntraServerJump_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesJumpManager_InitiateIntraServerJump()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesJumpManager_InitiateIntraServerJump_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesJumpManager::execInitiateIntraServerJump)
{
	P_GET_OBJECT(APlayerController,Z_Param_PlayerController);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_TargetLocation);
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_TargetSystemId);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->InitiateIntraServerJump(Z_Param_PlayerController,Z_Param_Out_TargetLocation,Z_Param_Out_TargetSystemId);
	P_NATIVE_END;
}
// ********** End Class UEchoesJumpManager Function InitiateIntraServerJump ************************

// ********** Begin Class UEchoesJumpManager *******************************************************
void UEchoesJumpManager::StaticRegisterNativesUEchoesJumpManager()
{
	UClass* Class = UEchoesJumpManager::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "ClientRPC_EndJumpSequence", &UEchoesJumpManager::execClientRPC_EndJumpSequence },
		{ "ClientRPC_StartJumpSequence", &UEchoesJumpManager::execClientRPC_StartJumpSequence },
		{ "ClientRPC_UpdateJumpProgress", &UEchoesJumpManager::execClientRPC_UpdateJumpProgress },
		{ "InitiateIntraServerJump", &UEchoesJumpManager::execInitiateIntraServerJump },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesJumpManager;
UClass* UEchoesJumpManager::GetPrivateStaticClass()
{
	using TClass = UEchoesJumpManager;
	if (!Z_Registration_Info_UClass_UEchoesJumpManager.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesJumpManager"),
			Z_Registration_Info_UClass_UEchoesJumpManager.InnerSingleton,
			StaticRegisterNativesUEchoesJumpManager,
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
	return Z_Registration_Info_UClass_UEchoesJumpManager.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesJumpManager_NoRegister()
{
	return UEchoesJumpManager::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesJumpManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UEchoesJumpManager\n * \n * Manages seamless intra-server jumps between star systems in Regional Clusters\n * Handles three-phase jump system: Initiation \xe2\x86\x92 Shift \xe2\x86\x92 Arrival\n * \n * Architecture:\n * - Component attached to GameMode\n * - Server authoritative with client RPCs for visual effects\n * - Integrates with backend for location persistence\n * - Handles physics teleportation safely\n * - Manages player state during jump (invulnerable, input blocked)\n * \n * Three-Phase Jump System:\n * 1. Initiation (ClientOnly): Fade out, warp tunnel effect, block input\n * 2. The Shift (ServerOnly): Instant teleportation with physics handling\n * 3. Arrival (ClientOnly): Asset loading check, fade in, unblock input\n */" },
#endif
		{ "IncludePath", "Core/Common/EchoesJumpManager.h" },
		{ "ModuleRelativePath", "Core/Common/EchoesJumpManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UEchoesJumpManager\n\nManages seamless intra-server jumps between star systems in Regional Clusters\nHandles three-phase jump system: Initiation \xe2\x86\x92 Shift \xe2\x86\x92 Arrival\n\nArchitecture:\n- Component attached to GameMode\n- Server authoritative with client RPCs for visual effects\n- Integrates with backend for location persistence\n- Handles physics teleportation safely\n- Manages player state during jump (invulnerable, input blocked)\n\nThree-Phase Jump System:\n1. Initiation (ClientOnly): Fade out, warp tunnel effect, block input\n2. The Shift (ServerOnly): Instant teleportation with physics handling\n3. Arrival (ClientOnly): Asset loading check, fade in, unblock input" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TransitionTime_MetaData[] = {
		{ "Category", "Jump|Configuration" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Transition time for fade effects (seconds)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesJumpManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Transition time for fade effects (seconds)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AssetLoadWaitTime_MetaData[] = {
		{ "Category", "Jump|Configuration" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Time to wait for asset loading at destination (seconds)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesJumpManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Time to wait for asset loading at destination (seconds)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CollisionCheckRadius_MetaData[] = {
		{ "Category", "Jump|Configuration" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Maximum distance for collision check (cm)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesJumpManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum distance for collision check (cm)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpingPlayers_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Map of players currently jumping */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesJumpManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Map of players currently jumping" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldGenerator_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Reference to world generator for asset management */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesJumpManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reference to world generator for asset management" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TransitionTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AssetLoadWaitTime;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CollisionCheckRadius;
	static const UECodeGen_Private::FBytePropertyParams NewProp_JumpingPlayers_ValueProp_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_JumpingPlayers_ValueProp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpingPlayers_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_JumpingPlayers;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldGenerator;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_EndJumpSequence, "ClientRPC_EndJumpSequence" }, // 3512149451
		{ &Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_StartJumpSequence, "ClientRPC_StartJumpSequence" }, // 2986902569
		{ &Z_Construct_UFunction_UEchoesJumpManager_ClientRPC_UpdateJumpProgress, "ClientRPC_UpdateJumpProgress" }, // 3708858234
		{ &Z_Construct_UFunction_UEchoesJumpManager_InitiateIntraServerJump, "InitiateIntraServerJump" }, // 59778741
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesJumpManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEchoesJumpManager_Statics::NewProp_TransitionTime = { "TransitionTime", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesJumpManager, TransitionTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TransitionTime_MetaData), NewProp_TransitionTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEchoesJumpManager_Statics::NewProp_AssetLoadWaitTime = { "AssetLoadWaitTime", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesJumpManager, AssetLoadWaitTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AssetLoadWaitTime_MetaData), NewProp_AssetLoadWaitTime_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEchoesJumpManager_Statics::NewProp_CollisionCheckRadius = { "CollisionCheckRadius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesJumpManager, CollisionCheckRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CollisionCheckRadius_MetaData), NewProp_CollisionCheckRadius_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UEchoesJumpManager_Statics::NewProp_JumpingPlayers_ValueProp_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UEchoesJumpManager_Statics::NewProp_JumpingPlayers_ValueProp = { "JumpingPlayers", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UEnum_Echoes_EJumpState, METADATA_PARAMS(0, nullptr) }; // 685698400
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesJumpManager_Statics::NewProp_JumpingPlayers_Key_KeyProp = { "JumpingPlayers_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UEchoesJumpManager_Statics::NewProp_JumpingPlayers = { "JumpingPlayers", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesJumpManager, JumpingPlayers), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpingPlayers_MetaData), NewProp_JumpingPlayers_MetaData) }; // 685698400
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesJumpManager_Statics::NewProp_WorldGenerator = { "WorldGenerator", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesJumpManager, WorldGenerator), Z_Construct_UClass_AEchoesWorldGenerator_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldGenerator_MetaData), NewProp_WorldGenerator_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesJumpManager_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesJumpManager_Statics::NewProp_TransitionTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesJumpManager_Statics::NewProp_AssetLoadWaitTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesJumpManager_Statics::NewProp_CollisionCheckRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesJumpManager_Statics::NewProp_JumpingPlayers_ValueProp_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesJumpManager_Statics::NewProp_JumpingPlayers_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesJumpManager_Statics::NewProp_JumpingPlayers_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesJumpManager_Statics::NewProp_JumpingPlayers,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesJumpManager_Statics::NewProp_WorldGenerator,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesJumpManager_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesJumpManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesJumpManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesJumpManager_Statics::ClassParams = {
	&UEchoesJumpManager::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UEchoesJumpManager_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesJumpManager_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesJumpManager_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesJumpManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesJumpManager()
{
	if (!Z_Registration_Info_UClass_UEchoesJumpManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesJumpManager.OuterSingleton, Z_Construct_UClass_UEchoesJumpManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesJumpManager.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesJumpManager);
UEchoesJumpManager::~UEchoesJumpManager() {}
// ********** End Class UEchoesJumpManager *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesJumpManager_h__Script_Echoes_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EJumpState_StaticEnum, TEXT("EJumpState"), &Z_Registration_Info_UEnum_EJumpState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 685698400U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesJumpManager, UEchoesJumpManager::StaticClass, TEXT("UEchoesJumpManager"), &Z_Registration_Info_UClass_UEchoesJumpManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesJumpManager), 1844634413U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesJumpManager_h__Script_Echoes_3663850595(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesJumpManager_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesJumpManager_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesJumpManager_h__Script_Echoes_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesJumpManager_h__Script_Echoes_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
