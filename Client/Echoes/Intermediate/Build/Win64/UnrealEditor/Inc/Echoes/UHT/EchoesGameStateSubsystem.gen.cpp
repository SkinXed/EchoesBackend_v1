// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Echoes/Core/Common/EchoesGameStateSubsystem.h"
#include "Engine/GameInstance.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesGameStateSubsystem() {}

// ********** Begin Cross Module References ********************************************************
ECHOES_API UClass* Z_Construct_UClass_UEchoesGameStateSubsystem();
ECHOES_API UClass* Z_Construct_UClass_UEchoesGameStateSubsystem_NoRegister();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_EEchoesGameState();
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EEchoesGameState **********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EEchoesGameState;
static UEnum* EEchoesGameState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EEchoesGameState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EEchoesGameState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Echoes_EEchoesGameState, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("EEchoesGameState"));
	}
	return Z_Registration_Info_UEnum_EEchoesGameState.OuterSingleton;
}
template<> ECHOES_API UEnum* StaticEnum<EEchoesGameState>()
{
	return EEchoesGameState_StaticEnum();
}
struct Z_Construct_UEnum_Echoes_EEchoesGameState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "CharacterSelect.DisplayName", "Character Select" },
		{ "CharacterSelect.Name", "EEchoesGameState::CharacterSelect" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Game state enum for tracking player progress through the game flow\n */" },
#endif
		{ "Hangar.DisplayName", "Hangar" },
		{ "Hangar.Name", "EEchoesGameState::Hangar" },
		{ "InSpace.DisplayName", "In Space" },
		{ "InSpace.Name", "EEchoesGameState::InSpace" },
		{ "Login.DisplayName", "Login" },
		{ "Login.Name", "EEchoesGameState::Login" },
		{ "ModuleRelativePath", "Core/Common/EchoesGameStateSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Game state enum for tracking player progress through the game flow" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EEchoesGameState::Login", (int64)EEchoesGameState::Login },
		{ "EEchoesGameState::CharacterSelect", (int64)EEchoesGameState::CharacterSelect },
		{ "EEchoesGameState::Hangar", (int64)EEchoesGameState::Hangar },
		{ "EEchoesGameState::InSpace", (int64)EEchoesGameState::InSpace },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Echoes_EEchoesGameState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	"EEchoesGameState",
	"EEchoesGameState",
	Z_Construct_UEnum_Echoes_EEchoesGameState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_EEchoesGameState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_EEchoesGameState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Echoes_EEchoesGameState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Echoes_EEchoesGameState()
{
	if (!Z_Registration_Info_UEnum_EEchoesGameState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EEchoesGameState.InnerSingleton, Z_Construct_UEnum_Echoes_EEchoesGameState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EEchoesGameState.InnerSingleton;
}
// ********** End Enum EEchoesGameState ************************************************************

// ********** Begin Class UEchoesGameStateSubsystem Function GetCurrentState ***********************
struct Z_Construct_UFunction_UEchoesGameStateSubsystem_GetCurrentState_Statics
{
	struct EchoesGameStateSubsystem_eventGetCurrentState_Parms
	{
		EEchoesGameState ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|GameState" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// State management\n" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesGameStateSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "State management" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UEchoesGameStateSubsystem_GetCurrentState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UEchoesGameStateSubsystem_GetCurrentState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesGameStateSubsystem_eventGetCurrentState_Parms, ReturnValue), Z_Construct_UEnum_Echoes_EEchoesGameState, METADATA_PARAMS(0, nullptr) }; // 939222237
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesGameStateSubsystem_GetCurrentState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesGameStateSubsystem_GetCurrentState_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesGameStateSubsystem_GetCurrentState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesGameStateSubsystem_GetCurrentState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesGameStateSubsystem_GetCurrentState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesGameStateSubsystem, nullptr, "GetCurrentState", Z_Construct_UFunction_UEchoesGameStateSubsystem_GetCurrentState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesGameStateSubsystem_GetCurrentState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesGameStateSubsystem_GetCurrentState_Statics::EchoesGameStateSubsystem_eventGetCurrentState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesGameStateSubsystem_GetCurrentState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesGameStateSubsystem_GetCurrentState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesGameStateSubsystem_GetCurrentState_Statics::EchoesGameStateSubsystem_eventGetCurrentState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesGameStateSubsystem_GetCurrentState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesGameStateSubsystem_GetCurrentState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesGameStateSubsystem::execGetCurrentState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EEchoesGameState*)Z_Param__Result=P_THIS->GetCurrentState();
	P_NATIVE_END;
}
// ********** End Class UEchoesGameStateSubsystem Function GetCurrentState *************************

// ********** Begin Class UEchoesGameStateSubsystem Function SetCurrentState ***********************
struct Z_Construct_UFunction_UEchoesGameStateSubsystem_SetCurrentState_Statics
{
	struct EchoesGameStateSubsystem_eventSetCurrentState_Parms
	{
		EEchoesGameState NewState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|GameState" },
		{ "ModuleRelativePath", "Core/Common/EchoesGameStateSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UEchoesGameStateSubsystem_SetCurrentState_Statics::NewProp_NewState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UEchoesGameStateSubsystem_SetCurrentState_Statics::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesGameStateSubsystem_eventSetCurrentState_Parms, NewState), Z_Construct_UEnum_Echoes_EEchoesGameState, METADATA_PARAMS(0, nullptr) }; // 939222237
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesGameStateSubsystem_SetCurrentState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesGameStateSubsystem_SetCurrentState_Statics::NewProp_NewState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesGameStateSubsystem_SetCurrentState_Statics::NewProp_NewState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesGameStateSubsystem_SetCurrentState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesGameStateSubsystem_SetCurrentState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesGameStateSubsystem, nullptr, "SetCurrentState", Z_Construct_UFunction_UEchoesGameStateSubsystem_SetCurrentState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesGameStateSubsystem_SetCurrentState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesGameStateSubsystem_SetCurrentState_Statics::EchoesGameStateSubsystem_eventSetCurrentState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesGameStateSubsystem_SetCurrentState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesGameStateSubsystem_SetCurrentState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesGameStateSubsystem_SetCurrentState_Statics::EchoesGameStateSubsystem_eventSetCurrentState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesGameStateSubsystem_SetCurrentState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesGameStateSubsystem_SetCurrentState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesGameStateSubsystem::execSetCurrentState)
{
	P_GET_ENUM(EEchoesGameState,Z_Param_NewState);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetCurrentState(EEchoesGameState(Z_Param_NewState));
	P_NATIVE_END;
}
// ********** End Class UEchoesGameStateSubsystem Function SetCurrentState *************************

// ********** Begin Class UEchoesGameStateSubsystem Function TransitionToCharacterSelect ***********
struct Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToCharacterSelect_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|GameState" },
		{ "ModuleRelativePath", "Core/Common/EchoesGameStateSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToCharacterSelect_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesGameStateSubsystem, nullptr, "TransitionToCharacterSelect", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToCharacterSelect_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToCharacterSelect_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToCharacterSelect()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToCharacterSelect_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesGameStateSubsystem::execTransitionToCharacterSelect)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TransitionToCharacterSelect();
	P_NATIVE_END;
}
// ********** End Class UEchoesGameStateSubsystem Function TransitionToCharacterSelect *************

// ********** Begin Class UEchoesGameStateSubsystem Function TransitionToHangar ********************
struct Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToHangar_Statics
{
	struct EchoesGameStateSubsystem_eventTransitionToHangar_Parms
	{
		FString CharacterId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|GameState" },
		{ "ModuleRelativePath", "Core/Common/EchoesGameStateSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_CharacterId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToHangar_Statics::NewProp_CharacterId = { "CharacterId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesGameStateSubsystem_eventTransitionToHangar_Parms, CharacterId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterId_MetaData), NewProp_CharacterId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToHangar_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToHangar_Statics::NewProp_CharacterId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToHangar_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToHangar_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesGameStateSubsystem, nullptr, "TransitionToHangar", Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToHangar_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToHangar_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToHangar_Statics::EchoesGameStateSubsystem_eventTransitionToHangar_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToHangar_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToHangar_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToHangar_Statics::EchoesGameStateSubsystem_eventTransitionToHangar_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToHangar()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToHangar_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesGameStateSubsystem::execTransitionToHangar)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_CharacterId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TransitionToHangar(Z_Param_CharacterId);
	P_NATIVE_END;
}
// ********** End Class UEchoesGameStateSubsystem Function TransitionToHangar **********************

// ********** Begin Class UEchoesGameStateSubsystem Function TransitionToLogin *********************
struct Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToLogin_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|GameState" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Transition functions\n" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesGameStateSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Transition functions" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToLogin_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesGameStateSubsystem, nullptr, "TransitionToLogin", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToLogin_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToLogin_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToLogin()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToLogin_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesGameStateSubsystem::execTransitionToLogin)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TransitionToLogin();
	P_NATIVE_END;
}
// ********** End Class UEchoesGameStateSubsystem Function TransitionToLogin ***********************

// ********** Begin Class UEchoesGameStateSubsystem Function TransitionToSpace *********************
struct Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToSpace_Statics
{
	struct EchoesGameStateSubsystem_eventTransitionToSpace_Parms
	{
		FString CharacterId;
		FString ShipId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|GameState" },
		{ "ModuleRelativePath", "Core/Common/EchoesGameStateSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterId_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShipId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_CharacterId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ShipId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToSpace_Statics::NewProp_CharacterId = { "CharacterId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesGameStateSubsystem_eventTransitionToSpace_Parms, CharacterId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterId_MetaData), NewProp_CharacterId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToSpace_Statics::NewProp_ShipId = { "ShipId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesGameStateSubsystem_eventTransitionToSpace_Parms, ShipId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShipId_MetaData), NewProp_ShipId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToSpace_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToSpace_Statics::NewProp_CharacterId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToSpace_Statics::NewProp_ShipId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToSpace_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToSpace_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesGameStateSubsystem, nullptr, "TransitionToSpace", Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToSpace_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToSpace_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToSpace_Statics::EchoesGameStateSubsystem_eventTransitionToSpace_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToSpace_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToSpace_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToSpace_Statics::EchoesGameStateSubsystem_eventTransitionToSpace_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToSpace()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToSpace_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesGameStateSubsystem::execTransitionToSpace)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_CharacterId);
	P_GET_PROPERTY(FStrProperty,Z_Param_ShipId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TransitionToSpace(Z_Param_CharacterId,Z_Param_ShipId);
	P_NATIVE_END;
}
// ********** End Class UEchoesGameStateSubsystem Function TransitionToSpace ***********************

// ********** Begin Class UEchoesGameStateSubsystem ************************************************
void UEchoesGameStateSubsystem::StaticRegisterNativesUEchoesGameStateSubsystem()
{
	UClass* Class = UEchoesGameStateSubsystem::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetCurrentState", &UEchoesGameStateSubsystem::execGetCurrentState },
		{ "SetCurrentState", &UEchoesGameStateSubsystem::execSetCurrentState },
		{ "TransitionToCharacterSelect", &UEchoesGameStateSubsystem::execTransitionToCharacterSelect },
		{ "TransitionToHangar", &UEchoesGameStateSubsystem::execTransitionToHangar },
		{ "TransitionToLogin", &UEchoesGameStateSubsystem::execTransitionToLogin },
		{ "TransitionToSpace", &UEchoesGameStateSubsystem::execTransitionToSpace },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesGameStateSubsystem;
UClass* UEchoesGameStateSubsystem::GetPrivateStaticClass()
{
	using TClass = UEchoesGameStateSubsystem;
	if (!Z_Registration_Info_UClass_UEchoesGameStateSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesGameStateSubsystem"),
			Z_Registration_Info_UClass_UEchoesGameStateSubsystem.InnerSingleton,
			StaticRegisterNativesUEchoesGameStateSubsystem,
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
	return Z_Registration_Info_UClass_UEchoesGameStateSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesGameStateSubsystem_NoRegister()
{
	return UEchoesGameStateSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesGameStateSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Subsystem for managing game state transitions and level flow\n * Tracks current game state and provides transition functions\n */" },
#endif
		{ "IncludePath", "Core/Common/EchoesGameStateSubsystem.h" },
		{ "ModuleRelativePath", "Core/Common/EchoesGameStateSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Subsystem for managing game state transitions and level flow\nTracks current game state and provides transition functions" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LoginLevelPath_MetaData[] = {
		{ "Category", "Echoes|GameState" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Level paths (can be configured)\n" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesGameStateSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Level paths (can be configured)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharacterSelectLevelPath_MetaData[] = {
		{ "Category", "Echoes|GameState" },
		{ "ModuleRelativePath", "Core/Common/EchoesGameStateSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HangarLevelPath_MetaData[] = {
		{ "Category", "Echoes|GameState" },
		{ "ModuleRelativePath", "Core/Common/EchoesGameStateSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpaceLevelPath_MetaData[] = {
		{ "Category", "Echoes|GameState" },
		{ "ModuleRelativePath", "Core/Common/EchoesGameStateSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentCharacterId_MetaData[] = {
		{ "Category", "Echoes|GameState" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Current context\n" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesGameStateSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current context" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentShipId_MetaData[] = {
		{ "Category", "Echoes|GameState" },
		{ "ModuleRelativePath", "Core/Common/EchoesGameStateSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentState_MetaData[] = {
		{ "ModuleRelativePath", "Core/Common/EchoesGameStateSubsystem.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_LoginLevelPath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_CharacterSelectLevelPath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_HangarLevelPath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SpaceLevelPath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_CurrentCharacterId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_CurrentShipId;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesGameStateSubsystem_GetCurrentState, "GetCurrentState" }, // 686184982
		{ &Z_Construct_UFunction_UEchoesGameStateSubsystem_SetCurrentState, "SetCurrentState" }, // 807849229
		{ &Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToCharacterSelect, "TransitionToCharacterSelect" }, // 1185026211
		{ &Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToHangar, "TransitionToHangar" }, // 2062579743
		{ &Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToLogin, "TransitionToLogin" }, // 3443372355
		{ &Z_Construct_UFunction_UEchoesGameStateSubsystem_TransitionToSpace, "TransitionToSpace" }, // 1468461822
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesGameStateSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEchoesGameStateSubsystem_Statics::NewProp_LoginLevelPath = { "LoginLevelPath", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesGameStateSubsystem, LoginLevelPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LoginLevelPath_MetaData), NewProp_LoginLevelPath_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEchoesGameStateSubsystem_Statics::NewProp_CharacterSelectLevelPath = { "CharacterSelectLevelPath", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesGameStateSubsystem, CharacterSelectLevelPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharacterSelectLevelPath_MetaData), NewProp_CharacterSelectLevelPath_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEchoesGameStateSubsystem_Statics::NewProp_HangarLevelPath = { "HangarLevelPath", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesGameStateSubsystem, HangarLevelPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HangarLevelPath_MetaData), NewProp_HangarLevelPath_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEchoesGameStateSubsystem_Statics::NewProp_SpaceLevelPath = { "SpaceLevelPath", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesGameStateSubsystem, SpaceLevelPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpaceLevelPath_MetaData), NewProp_SpaceLevelPath_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEchoesGameStateSubsystem_Statics::NewProp_CurrentCharacterId = { "CurrentCharacterId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesGameStateSubsystem, CurrentCharacterId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentCharacterId_MetaData), NewProp_CurrentCharacterId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UEchoesGameStateSubsystem_Statics::NewProp_CurrentShipId = { "CurrentShipId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesGameStateSubsystem, CurrentShipId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentShipId_MetaData), NewProp_CurrentShipId_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UEchoesGameStateSubsystem_Statics::NewProp_CurrentState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UEchoesGameStateSubsystem_Statics::NewProp_CurrentState = { "CurrentState", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesGameStateSubsystem, CurrentState), Z_Construct_UEnum_Echoes_EEchoesGameState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentState_MetaData), NewProp_CurrentState_MetaData) }; // 939222237
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesGameStateSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesGameStateSubsystem_Statics::NewProp_LoginLevelPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesGameStateSubsystem_Statics::NewProp_CharacterSelectLevelPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesGameStateSubsystem_Statics::NewProp_HangarLevelPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesGameStateSubsystem_Statics::NewProp_SpaceLevelPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesGameStateSubsystem_Statics::NewProp_CurrentCharacterId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesGameStateSubsystem_Statics::NewProp_CurrentShipId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesGameStateSubsystem_Statics::NewProp_CurrentState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesGameStateSubsystem_Statics::NewProp_CurrentState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesGameStateSubsystem_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesGameStateSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesGameStateSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesGameStateSubsystem_Statics::ClassParams = {
	&UEchoesGameStateSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UEchoesGameStateSubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesGameStateSubsystem_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesGameStateSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesGameStateSubsystem_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesGameStateSubsystem()
{
	if (!Z_Registration_Info_UClass_UEchoesGameStateSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesGameStateSubsystem.OuterSingleton, Z_Construct_UClass_UEchoesGameStateSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesGameStateSubsystem.OuterSingleton;
}
UEchoesGameStateSubsystem::UEchoesGameStateSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesGameStateSubsystem);
UEchoesGameStateSubsystem::~UEchoesGameStateSubsystem() {}
// ********** End Class UEchoesGameStateSubsystem **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesGameStateSubsystem_h__Script_Echoes_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EEchoesGameState_StaticEnum, TEXT("EEchoesGameState"), &Z_Registration_Info_UEnum_EEchoesGameState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 939222237U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesGameStateSubsystem, UEchoesGameStateSubsystem::StaticClass, TEXT("UEchoesGameStateSubsystem"), &Z_Registration_Info_UClass_UEchoesGameStateSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesGameStateSubsystem), 2927219820U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesGameStateSubsystem_h__Script_Echoes_2849196809(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesGameStateSubsystem_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesGameStateSubsystem_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesGameStateSubsystem_h__Script_Echoes_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesGameStateSubsystem_h__Script_Echoes_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
