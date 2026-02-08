// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "EchoesStargate.h"
#include "Engine/HitResult.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesStargate() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UClass* Z_Construct_UClass_AEchoesStargate();
ECHOES_API UClass* Z_Construct_UClass_AEchoesStargate_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesJumpSubsystem_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AEchoesStargate Function CanShipJump *************************************
struct Z_Construct_UFunction_AEchoesStargate_CanShipJump_Statics
{
	struct EchoesStargate_eventCanShipJump_Parms
	{
		AActor* Ship;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Stargate" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if a ship can jump (cooldown, distance, etc.)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesStargate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if a ship can jump (cooldown, distance, etc.)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Ship;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AEchoesStargate_CanShipJump_Statics::NewProp_Ship = { "Ship", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesStargate_eventCanShipJump_Parms, Ship), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AEchoesStargate_CanShipJump_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesStargate_eventCanShipJump_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AEchoesStargate_CanShipJump_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesStargate_eventCanShipJump_Parms), &Z_Construct_UFunction_AEchoesStargate_CanShipJump_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesStargate_CanShipJump_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesStargate_CanShipJump_Statics::NewProp_Ship,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesStargate_CanShipJump_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesStargate_CanShipJump_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesStargate_CanShipJump_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesStargate, nullptr, "CanShipJump", Z_Construct_UFunction_AEchoesStargate_CanShipJump_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesStargate_CanShipJump_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesStargate_CanShipJump_Statics::EchoesStargate_eventCanShipJump_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesStargate_CanShipJump_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesStargate_CanShipJump_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesStargate_CanShipJump_Statics::EchoesStargate_eventCanShipJump_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesStargate_CanShipJump()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesStargate_CanShipJump_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesStargate::execCanShipJump)
{
	P_GET_OBJECT(AActor,Z_Param_Ship);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CanShipJump(Z_Param_Ship);
	P_NATIVE_END;
}
// ********** End Class AEchoesStargate Function CanShipJump ***************************************

// ********** Begin Class AEchoesStargate Function GetCharacterIdFromShip **************************
struct EchoesStargate_eventGetCharacterIdFromShip_Parms
{
	AActor* Ship;
	FGuid ReturnValue;
};
static FName NAME_AEchoesStargate_GetCharacterIdFromShip = FName(TEXT("GetCharacterIdFromShip"));
FGuid AEchoesStargate::GetCharacterIdFromShip(AActor* Ship) const
{
	UFunction* Func = FindFunctionChecked(NAME_AEchoesStargate_GetCharacterIdFromShip);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		EchoesStargate_eventGetCharacterIdFromShip_Parms Parms;
		Parms.Ship=Ship;
		const_cast<AEchoesStargate*>(this)->ProcessEvent(Func,&Parms);
		return Parms.ReturnValue;
	}
	else
	{
		return const_cast<AEchoesStargate*>(this)->GetCharacterIdFromShip_Implementation(Ship);
	}
}
struct Z_Construct_UFunction_AEchoesStargate_GetCharacterIdFromShip_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Stargate" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get character ID from ship/pawn\n\x09 * Override in Blueprint or C++ for your specific character system\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesStargate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get character ID from ship/pawn\nOverride in Blueprint or C++ for your specific character system" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Ship;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AEchoesStargate_GetCharacterIdFromShip_Statics::NewProp_Ship = { "Ship", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesStargate_eventGetCharacterIdFromShip_Parms, Ship), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesStargate_GetCharacterIdFromShip_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesStargate_eventGetCharacterIdFromShip_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesStargate_GetCharacterIdFromShip_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesStargate_GetCharacterIdFromShip_Statics::NewProp_Ship,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesStargate_GetCharacterIdFromShip_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesStargate_GetCharacterIdFromShip_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesStargate_GetCharacterIdFromShip_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesStargate, nullptr, "GetCharacterIdFromShip", Z_Construct_UFunction_AEchoesStargate_GetCharacterIdFromShip_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesStargate_GetCharacterIdFromShip_Statics::PropPointers), sizeof(EchoesStargate_eventGetCharacterIdFromShip_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x48880C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesStargate_GetCharacterIdFromShip_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesStargate_GetCharacterIdFromShip_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(EchoesStargate_eventGetCharacterIdFromShip_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesStargate_GetCharacterIdFromShip()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesStargate_GetCharacterIdFromShip_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesStargate::execGetCharacterIdFromShip)
{
	P_GET_OBJECT(AActor,Z_Param_Ship);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGuid*)Z_Param__Result=P_THIS->GetCharacterIdFromShip_Implementation(Z_Param_Ship);
	P_NATIVE_END;
}
// ********** End Class AEchoesStargate Function GetCharacterIdFromShip ****************************

// ********** Begin Class AEchoesStargate Function OnJumpFailed ************************************
struct EchoesStargate_eventOnJumpFailed_Parms
{
	AActor* Ship;
	FString Reason;
};
static FName NAME_AEchoesStargate_OnJumpFailed = FName(TEXT("OnJumpFailed"));
void AEchoesStargate::OnJumpFailed(AActor* Ship, const FString& Reason)
{
	EchoesStargate_eventOnJumpFailed_Parms Parms;
	Parms.Ship=Ship;
	Parms.Reason=Reason;
	UFunction* Func = FindFunctionChecked(NAME_AEchoesStargate_OnJumpFailed);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AEchoesStargate_OnJumpFailed_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Stargate" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Blueprint event called when jump fails\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesStargate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint event called when jump fails" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Reason_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Ship;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Reason;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AEchoesStargate_OnJumpFailed_Statics::NewProp_Ship = { "Ship", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesStargate_eventOnJumpFailed_Parms, Ship), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AEchoesStargate_OnJumpFailed_Statics::NewProp_Reason = { "Reason", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesStargate_eventOnJumpFailed_Parms, Reason), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Reason_MetaData), NewProp_Reason_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesStargate_OnJumpFailed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesStargate_OnJumpFailed_Statics::NewProp_Ship,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesStargate_OnJumpFailed_Statics::NewProp_Reason,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesStargate_OnJumpFailed_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesStargate_OnJumpFailed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesStargate, nullptr, "OnJumpFailed", Z_Construct_UFunction_AEchoesStargate_OnJumpFailed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesStargate_OnJumpFailed_Statics::PropPointers), sizeof(EchoesStargate_eventOnJumpFailed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesStargate_OnJumpFailed_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesStargate_OnJumpFailed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(EchoesStargate_eventOnJumpFailed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesStargate_OnJumpFailed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesStargate_OnJumpFailed_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class AEchoesStargate Function OnJumpFailed **************************************

// ********** Begin Class AEchoesStargate Function OnJumpInitiated *********************************
struct EchoesStargate_eventOnJumpInitiated_Parms
{
	AActor* Ship;
	FString DestinationSystemName;
};
static FName NAME_AEchoesStargate_OnJumpInitiated = FName(TEXT("OnJumpInitiated"));
void AEchoesStargate::OnJumpInitiated(AActor* Ship, const FString& DestinationSystemName)
{
	EchoesStargate_eventOnJumpInitiated_Parms Parms;
	Parms.Ship=Ship;
	Parms.DestinationSystemName=DestinationSystemName;
	UFunction* Func = FindFunctionChecked(NAME_AEchoesStargate_OnJumpInitiated);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AEchoesStargate_OnJumpInitiated_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Stargate" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Blueprint event called when jump is initiated\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesStargate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint event called when jump is initiated" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DestinationSystemName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Ship;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DestinationSystemName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AEchoesStargate_OnJumpInitiated_Statics::NewProp_Ship = { "Ship", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesStargate_eventOnJumpInitiated_Parms, Ship), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AEchoesStargate_OnJumpInitiated_Statics::NewProp_DestinationSystemName = { "DestinationSystemName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesStargate_eventOnJumpInitiated_Parms, DestinationSystemName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DestinationSystemName_MetaData), NewProp_DestinationSystemName_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesStargate_OnJumpInitiated_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesStargate_OnJumpInitiated_Statics::NewProp_Ship,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesStargate_OnJumpInitiated_Statics::NewProp_DestinationSystemName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesStargate_OnJumpInitiated_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesStargate_OnJumpInitiated_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesStargate, nullptr, "OnJumpInitiated", Z_Construct_UFunction_AEchoesStargate_OnJumpInitiated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesStargate_OnJumpInitiated_Statics::PropPointers), sizeof(EchoesStargate_eventOnJumpInitiated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesStargate_OnJumpInitiated_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesStargate_OnJumpInitiated_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(EchoesStargate_eventOnJumpInitiated_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesStargate_OnJumpInitiated()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesStargate_OnJumpInitiated_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class AEchoesStargate Function OnJumpInitiated ***********************************

// ********** Begin Class AEchoesStargate Function OnTriggerBeginOverlap ***************************
struct Z_Construct_UFunction_AEchoesStargate_OnTriggerBeginOverlap_Statics
{
	struct EchoesStargate_eventOnTriggerBeginOverlap_Parms
	{
		UPrimitiveComponent* OverlappedComponent;
		AActor* OtherActor;
		UPrimitiveComponent* OtherComp;
		int32 OtherBodyIndex;
		bool bFromSweep;
		FHitResult SweepResult;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Called when an actor enters the trigger volume\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesStargate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when an actor enters the trigger volume" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlappedComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
	static void NewProp_bFromSweep_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SweepResult;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AEchoesStargate_OnTriggerBeginOverlap_Statics::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesStargate_eventOnTriggerBeginOverlap_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverlappedComponent_MetaData), NewProp_OverlappedComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AEchoesStargate_OnTriggerBeginOverlap_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesStargate_eventOnTriggerBeginOverlap_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AEchoesStargate_OnTriggerBeginOverlap_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesStargate_eventOnTriggerBeginOverlap_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OtherComp_MetaData), NewProp_OtherComp_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AEchoesStargate_OnTriggerBeginOverlap_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesStargate_eventOnTriggerBeginOverlap_Parms, OtherBodyIndex), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AEchoesStargate_OnTriggerBeginOverlap_Statics::NewProp_bFromSweep_SetBit(void* Obj)
{
	((EchoesStargate_eventOnTriggerBeginOverlap_Parms*)Obj)->bFromSweep = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AEchoesStargate_OnTriggerBeginOverlap_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesStargate_eventOnTriggerBeginOverlap_Parms), &Z_Construct_UFunction_AEchoesStargate_OnTriggerBeginOverlap_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesStargate_OnTriggerBeginOverlap_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesStargate_eventOnTriggerBeginOverlap_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SweepResult_MetaData), NewProp_SweepResult_MetaData) }; // 267591329
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesStargate_OnTriggerBeginOverlap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesStargate_OnTriggerBeginOverlap_Statics::NewProp_OverlappedComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesStargate_OnTriggerBeginOverlap_Statics::NewProp_OtherActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesStargate_OnTriggerBeginOverlap_Statics::NewProp_OtherComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesStargate_OnTriggerBeginOverlap_Statics::NewProp_OtherBodyIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesStargate_OnTriggerBeginOverlap_Statics::NewProp_bFromSweep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesStargate_OnTriggerBeginOverlap_Statics::NewProp_SweepResult,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesStargate_OnTriggerBeginOverlap_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesStargate_OnTriggerBeginOverlap_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesStargate, nullptr, "OnTriggerBeginOverlap", Z_Construct_UFunction_AEchoesStargate_OnTriggerBeginOverlap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesStargate_OnTriggerBeginOverlap_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesStargate_OnTriggerBeginOverlap_Statics::EchoesStargate_eventOnTriggerBeginOverlap_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesStargate_OnTriggerBeginOverlap_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesStargate_OnTriggerBeginOverlap_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesStargate_OnTriggerBeginOverlap_Statics::EchoesStargate_eventOnTriggerBeginOverlap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesStargate_OnTriggerBeginOverlap()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesStargate_OnTriggerBeginOverlap_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesStargate::execOnTriggerBeginOverlap)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent);
	P_GET_OBJECT(AActor,Z_Param_OtherActor);
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
	P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
	P_GET_UBOOL(Z_Param_bFromSweep);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnTriggerBeginOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult);
	P_NATIVE_END;
}
// ********** End Class AEchoesStargate Function OnTriggerBeginOverlap *****************************

// ********** Begin Class AEchoesStargate Function OnTriggerEndOverlap *****************************
struct Z_Construct_UFunction_AEchoesStargate_OnTriggerEndOverlap_Statics
{
	struct EchoesStargate_eventOnTriggerEndOverlap_Parms
	{
		UPrimitiveComponent* OverlappedComponent;
		AActor* OtherActor;
		UPrimitiveComponent* OtherComp;
		int32 OtherBodyIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Called when an actor leaves the trigger volume\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesStargate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when an actor leaves the trigger volume" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlappedComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AEchoesStargate_OnTriggerEndOverlap_Statics::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesStargate_eventOnTriggerEndOverlap_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverlappedComponent_MetaData), NewProp_OverlappedComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AEchoesStargate_OnTriggerEndOverlap_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesStargate_eventOnTriggerEndOverlap_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AEchoesStargate_OnTriggerEndOverlap_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesStargate_eventOnTriggerEndOverlap_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OtherComp_MetaData), NewProp_OtherComp_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AEchoesStargate_OnTriggerEndOverlap_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesStargate_eventOnTriggerEndOverlap_Parms, OtherBodyIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesStargate_OnTriggerEndOverlap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesStargate_OnTriggerEndOverlap_Statics::NewProp_OverlappedComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesStargate_OnTriggerEndOverlap_Statics::NewProp_OtherActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesStargate_OnTriggerEndOverlap_Statics::NewProp_OtherComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesStargate_OnTriggerEndOverlap_Statics::NewProp_OtherBodyIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesStargate_OnTriggerEndOverlap_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesStargate_OnTriggerEndOverlap_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesStargate, nullptr, "OnTriggerEndOverlap", Z_Construct_UFunction_AEchoesStargate_OnTriggerEndOverlap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesStargate_OnTriggerEndOverlap_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesStargate_OnTriggerEndOverlap_Statics::EchoesStargate_eventOnTriggerEndOverlap_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesStargate_OnTriggerEndOverlap_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesStargate_OnTriggerEndOverlap_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesStargate_OnTriggerEndOverlap_Statics::EchoesStargate_eventOnTriggerEndOverlap_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesStargate_OnTriggerEndOverlap()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesStargate_OnTriggerEndOverlap_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesStargate::execOnTriggerEndOverlap)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent);
	P_GET_OBJECT(AActor,Z_Param_OtherActor);
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
	P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnTriggerEndOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex);
	P_NATIVE_END;
}
// ********** End Class AEchoesStargate Function OnTriggerEndOverlap *******************************

// ********** Begin Class AEchoesStargate Function PlayIdleEffect **********************************
static FName NAME_AEchoesStargate_PlayIdleEffect = FName(TEXT("PlayIdleEffect"));
void AEchoesStargate::PlayIdleEffect()
{
	UFunction* Func = FindFunctionChecked(NAME_AEchoesStargate_PlayIdleEffect);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
	ProcessEvent(Func,NULL);
	}
	else
	{
		PlayIdleEffect_Implementation();
	}
}
struct Z_Construct_UFunction_AEchoesStargate_PlayIdleEffect_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Stargate|Effects" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Visual effect for idle stargate\n\x09 * Override in Blueprint for custom effects\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesStargate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Visual effect for idle stargate\nOverride in Blueprint for custom effects" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesStargate_PlayIdleEffect_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesStargate, nullptr, "PlayIdleEffect", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesStargate_PlayIdleEffect_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesStargate_PlayIdleEffect_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AEchoesStargate_PlayIdleEffect()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesStargate_PlayIdleEffect_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesStargate::execPlayIdleEffect)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PlayIdleEffect_Implementation();
	P_NATIVE_END;
}
// ********** End Class AEchoesStargate Function PlayIdleEffect ************************************

// ********** Begin Class AEchoesStargate Function PlayJumpEffect **********************************
struct EchoesStargate_eventPlayJumpEffect_Parms
{
	AActor* Ship;
};
static FName NAME_AEchoesStargate_PlayJumpEffect = FName(TEXT("PlayJumpEffect"));
void AEchoesStargate::PlayJumpEffect(AActor* Ship)
{
	UFunction* Func = FindFunctionChecked(NAME_AEchoesStargate_PlayJumpEffect);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		EchoesStargate_eventPlayJumpEffect_Parms Parms;
		Parms.Ship=Ship;
	ProcessEvent(Func,&Parms);
	}
	else
	{
		PlayJumpEffect_Implementation(Ship);
	}
}
struct Z_Construct_UFunction_AEchoesStargate_PlayJumpEffect_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Stargate|Effects" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Visual effect when jump is initiated\n\x09 * Override in Blueprint for custom effects\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesStargate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Visual effect when jump is initiated\nOverride in Blueprint for custom effects" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Ship;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AEchoesStargate_PlayJumpEffect_Statics::NewProp_Ship = { "Ship", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesStargate_eventPlayJumpEffect_Parms, Ship), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesStargate_PlayJumpEffect_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesStargate_PlayJumpEffect_Statics::NewProp_Ship,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesStargate_PlayJumpEffect_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesStargate_PlayJumpEffect_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesStargate, nullptr, "PlayJumpEffect", Z_Construct_UFunction_AEchoesStargate_PlayJumpEffect_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesStargate_PlayJumpEffect_Statics::PropPointers), sizeof(EchoesStargate_eventPlayJumpEffect_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesStargate_PlayJumpEffect_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesStargate_PlayJumpEffect_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(EchoesStargate_eventPlayJumpEffect_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesStargate_PlayJumpEffect()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesStargate_PlayJumpEffect_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesStargate::execPlayJumpEffect)
{
	P_GET_OBJECT(AActor,Z_Param_Ship);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->PlayJumpEffect_Implementation(Z_Param_Ship);
	P_NATIVE_END;
}
// ********** End Class AEchoesStargate Function PlayJumpEffect ************************************

// ********** Begin Class AEchoesStargate Function ServerOnly_InitiateJump *************************
struct Z_Construct_UFunction_AEchoesStargate_ServerOnly_InitiateJump_Statics
{
	struct EchoesStargate_eventServerOnly_InitiateJump_Parms
	{
		AActor* Ship;
		FGuid CharacterId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Stargate" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Initiate jump for a ship (SERVER ONLY)\n\x09 * Called when ship enters trigger and meets requirements\n\x09 * \n\x09 * @param Ship - Ship actor to jump\n\x09 * @param CharacterId - Character ID of the pilot\n\x09 */" },
#endif
		{ "DisplayName", "ServerOnly - Initiate Jump" },
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesStargate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initiate jump for a ship (SERVER ONLY)\nCalled when ship enters trigger and meets requirements\n\n@param Ship - Ship actor to jump\n@param CharacterId - Character ID of the pilot" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Ship;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CharacterId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AEchoesStargate_ServerOnly_InitiateJump_Statics::NewProp_Ship = { "Ship", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesStargate_eventServerOnly_InitiateJump_Parms, Ship), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesStargate_ServerOnly_InitiateJump_Statics::NewProp_CharacterId = { "CharacterId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesStargate_eventServerOnly_InitiateJump_Parms, CharacterId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesStargate_ServerOnly_InitiateJump_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesStargate_ServerOnly_InitiateJump_Statics::NewProp_Ship,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesStargate_ServerOnly_InitiateJump_Statics::NewProp_CharacterId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesStargate_ServerOnly_InitiateJump_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesStargate_ServerOnly_InitiateJump_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesStargate, nullptr, "ServerOnly_InitiateJump", Z_Construct_UFunction_AEchoesStargate_ServerOnly_InitiateJump_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesStargate_ServerOnly_InitiateJump_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesStargate_ServerOnly_InitiateJump_Statics::EchoesStargate_eventServerOnly_InitiateJump_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04880401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesStargate_ServerOnly_InitiateJump_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesStargate_ServerOnly_InitiateJump_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesStargate_ServerOnly_InitiateJump_Statics::EchoesStargate_eventServerOnly_InitiateJump_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesStargate_ServerOnly_InitiateJump()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesStargate_ServerOnly_InitiateJump_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesStargate::execServerOnly_InitiateJump)
{
	P_GET_OBJECT(AActor,Z_Param_Ship);
	P_GET_STRUCT(FGuid,Z_Param_CharacterId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_InitiateJump(Z_Param_Ship,Z_Param_CharacterId);
	P_NATIVE_END;
}
// ********** End Class AEchoesStargate Function ServerOnly_InitiateJump ***************************

// ********** Begin Class AEchoesStargate **********************************************************
void AEchoesStargate::StaticRegisterNativesAEchoesStargate()
{
	UClass* Class = AEchoesStargate::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CanShipJump", &AEchoesStargate::execCanShipJump },
		{ "GetCharacterIdFromShip", &AEchoesStargate::execGetCharacterIdFromShip },
		{ "OnTriggerBeginOverlap", &AEchoesStargate::execOnTriggerBeginOverlap },
		{ "OnTriggerEndOverlap", &AEchoesStargate::execOnTriggerEndOverlap },
		{ "PlayIdleEffect", &AEchoesStargate::execPlayIdleEffect },
		{ "PlayJumpEffect", &AEchoesStargate::execPlayJumpEffect },
		{ "ServerOnly_InitiateJump", &AEchoesStargate::execServerOnly_InitiateJump },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_AEchoesStargate;
UClass* AEchoesStargate::GetPrivateStaticClass()
{
	using TClass = AEchoesStargate;
	if (!Z_Registration_Info_UClass_AEchoesStargate.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesStargate"),
			Z_Registration_Info_UClass_AEchoesStargate.InnerSingleton,
			StaticRegisterNativesAEchoesStargate,
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
	return Z_Registration_Info_UClass_AEchoesStargate.InnerSingleton;
}
UClass* Z_Construct_UClass_AEchoesStargate_NoRegister()
{
	return AEchoesStargate::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AEchoesStargate_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Echoes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * AEchoesStargate\n * \n * Stargate actor that triggers interstellar jumps when ships enter.\n * Handles jump initiation and visual effects.\n * \n * Setup:\n * 1. Place in level at desired location\n * 2. Configure DestinationSystemId in details panel\n * 3. Set StargateId to match database entry\n * 4. Adjust trigger volume size as needed\n */" },
#endif
		{ "IncludePath", "Core/Common/Actor/EchoesStargate.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesStargate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "AEchoesStargate\n\nStargate actor that triggers interstellar jumps when ships enter.\nHandles jump initiation and visual effects.\n\nSetup:\n1. Place in level at desired location\n2. Configure DestinationSystemId in details panel\n3. Set StargateId to match database entry\n4. Adjust trigger volume size as needed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StargateId_MetaData[] = {
		{ "Category", "Stargate" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Stargate ID (must match database entry)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesStargate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stargate ID (must match database entry)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceSystemId_MetaData[] = {
		{ "Category", "Stargate" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Source system ID (current system)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesStargate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Source system ID (current system)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DestinationSystemId_MetaData[] = {
		{ "Category", "Stargate" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Destination system ID (where jumps lead to)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesStargate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Destination system ID (where jumps lead to)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsOperational_MetaData[] = {
		{ "Category", "Stargate" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Whether the stargate is currently operational\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesStargate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether the stargate is currently operational" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StargateName_MetaData[] = {
		{ "Category", "Stargate" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Stargate name for display\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesStargate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Stargate name for display" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpCooldownSeconds_MetaData[] = {
		{ "Category", "Stargate|Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Cooldown time between jumps (per ship)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesStargate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cooldown time between jumps (per ship)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRequireConfirmation_MetaData[] = {
		{ "Category", "Stargate|Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Whether to require player confirmation before jump\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesStargate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether to require player confirmation before jump" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinJumpDistance_MetaData[] = {
		{ "Category", "Stargate|Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Minimum distance to stargate center to allow jump (meters)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesStargate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Minimum distance to stargate center to allow jump (meters)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxJumpDistance_MetaData[] = {
		{ "Category", "Stargate|Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Maximum distance from stargate center to allow jump (meters)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesStargate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum distance from stargate center to allow jump (meters)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TriggerVolume_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Trigger box for detecting ships\n\x09 */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesStargate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Trigger box for detecting ships" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StargateMesh_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Static mesh component for visual representation\n\x09 */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesStargate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Static mesh component for visual representation" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LastJumpTimes_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Map of actors and their last jump time (for cooldown)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesStargate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Map of actors and their last jump time (for cooldown)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpSubsystem_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Cached jump subsystem reference\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Actor/EchoesStargate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached jump subsystem reference" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_StargateId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SourceSystemId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DestinationSystemId;
	static void NewProp_bIsOperational_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsOperational;
	static const UECodeGen_Private::FStrPropertyParams NewProp_StargateName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_JumpCooldownSeconds;
	static void NewProp_bRequireConfirmation_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRequireConfirmation;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinJumpDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxJumpDistance;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TriggerVolume;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_StargateMesh;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LastJumpTimes_ValueProp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LastJumpTimes_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_LastJumpTimes;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpSubsystem;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AEchoesStargate_CanShipJump, "CanShipJump" }, // 3133126051
		{ &Z_Construct_UFunction_AEchoesStargate_GetCharacterIdFromShip, "GetCharacterIdFromShip" }, // 4244575781
		{ &Z_Construct_UFunction_AEchoesStargate_OnJumpFailed, "OnJumpFailed" }, // 481815457
		{ &Z_Construct_UFunction_AEchoesStargate_OnJumpInitiated, "OnJumpInitiated" }, // 1916033729
		{ &Z_Construct_UFunction_AEchoesStargate_OnTriggerBeginOverlap, "OnTriggerBeginOverlap" }, // 1940903286
		{ &Z_Construct_UFunction_AEchoesStargate_OnTriggerEndOverlap, "OnTriggerEndOverlap" }, // 3159913001
		{ &Z_Construct_UFunction_AEchoesStargate_PlayIdleEffect, "PlayIdleEffect" }, // 965797541
		{ &Z_Construct_UFunction_AEchoesStargate_PlayJumpEffect, "PlayJumpEffect" }, // 3558772464
		{ &Z_Construct_UFunction_AEchoesStargate_ServerOnly_InitiateJump, "ServerOnly_InitiateJump" }, // 1244750603
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEchoesStargate>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEchoesStargate_Statics::NewProp_StargateId = { "StargateId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesStargate, StargateId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StargateId_MetaData), NewProp_StargateId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEchoesStargate_Statics::NewProp_SourceSystemId = { "SourceSystemId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesStargate, SourceSystemId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceSystemId_MetaData), NewProp_SourceSystemId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEchoesStargate_Statics::NewProp_DestinationSystemId = { "DestinationSystemId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesStargate, DestinationSystemId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DestinationSystemId_MetaData), NewProp_DestinationSystemId_MetaData) };
void Z_Construct_UClass_AEchoesStargate_Statics::NewProp_bIsOperational_SetBit(void* Obj)
{
	((AEchoesStargate*)Obj)->bIsOperational = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AEchoesStargate_Statics::NewProp_bIsOperational = { "bIsOperational", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AEchoesStargate), &Z_Construct_UClass_AEchoesStargate_Statics::NewProp_bIsOperational_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsOperational_MetaData), NewProp_bIsOperational_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AEchoesStargate_Statics::NewProp_StargateName = { "StargateName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesStargate, StargateName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StargateName_MetaData), NewProp_StargateName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEchoesStargate_Statics::NewProp_JumpCooldownSeconds = { "JumpCooldownSeconds", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesStargate, JumpCooldownSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpCooldownSeconds_MetaData), NewProp_JumpCooldownSeconds_MetaData) };
void Z_Construct_UClass_AEchoesStargate_Statics::NewProp_bRequireConfirmation_SetBit(void* Obj)
{
	((AEchoesStargate*)Obj)->bRequireConfirmation = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AEchoesStargate_Statics::NewProp_bRequireConfirmation = { "bRequireConfirmation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AEchoesStargate), &Z_Construct_UClass_AEchoesStargate_Statics::NewProp_bRequireConfirmation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRequireConfirmation_MetaData), NewProp_bRequireConfirmation_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEchoesStargate_Statics::NewProp_MinJumpDistance = { "MinJumpDistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesStargate, MinJumpDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinJumpDistance_MetaData), NewProp_MinJumpDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEchoesStargate_Statics::NewProp_MaxJumpDistance = { "MaxJumpDistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesStargate, MaxJumpDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxJumpDistance_MetaData), NewProp_MaxJumpDistance_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesStargate_Statics::NewProp_TriggerVolume = { "TriggerVolume", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesStargate, TriggerVolume), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TriggerVolume_MetaData), NewProp_TriggerVolume_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesStargate_Statics::NewProp_StargateMesh = { "StargateMesh", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesStargate, StargateMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StargateMesh_MetaData), NewProp_StargateMesh_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEchoesStargate_Statics::NewProp_LastJumpTimes_ValueProp = { "LastJumpTimes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesStargate_Statics::NewProp_LastJumpTimes_Key_KeyProp = { "LastJumpTimes_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_AEchoesStargate_Statics::NewProp_LastJumpTimes = { "LastJumpTimes", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesStargate, LastJumpTimes), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LastJumpTimes_MetaData), NewProp_LastJumpTimes_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesStargate_Statics::NewProp_JumpSubsystem = { "JumpSubsystem", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesStargate, JumpSubsystem), Z_Construct_UClass_UEchoesJumpSubsystem_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpSubsystem_MetaData), NewProp_JumpSubsystem_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEchoesStargate_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesStargate_Statics::NewProp_StargateId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesStargate_Statics::NewProp_SourceSystemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesStargate_Statics::NewProp_DestinationSystemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesStargate_Statics::NewProp_bIsOperational,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesStargate_Statics::NewProp_StargateName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesStargate_Statics::NewProp_JumpCooldownSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesStargate_Statics::NewProp_bRequireConfirmation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesStargate_Statics::NewProp_MinJumpDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesStargate_Statics::NewProp_MaxJumpDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesStargate_Statics::NewProp_TriggerVolume,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesStargate_Statics::NewProp_StargateMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesStargate_Statics::NewProp_LastJumpTimes_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesStargate_Statics::NewProp_LastJumpTimes_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesStargate_Statics::NewProp_LastJumpTimes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesStargate_Statics::NewProp_JumpSubsystem,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesStargate_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AEchoesStargate_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesStargate_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEchoesStargate_Statics::ClassParams = {
	&AEchoesStargate::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AEchoesStargate_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesStargate_Statics::PropPointers),
	0,
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesStargate_Statics::Class_MetaDataParams), Z_Construct_UClass_AEchoesStargate_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEchoesStargate()
{
	if (!Z_Registration_Info_UClass_AEchoesStargate.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEchoesStargate.OuterSingleton, Z_Construct_UClass_AEchoesStargate_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEchoesStargate.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEchoesStargate);
AEchoesStargate::~AEchoesStargate() {}
// ********** End Class AEchoesStargate ************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesStargate_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEchoesStargate, AEchoesStargate::StaticClass, TEXT("AEchoesStargate"), &Z_Registration_Info_UClass_AEchoesStargate, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEchoesStargate), 760796892U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesStargate_h__Script_Echoes_1780076543(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesStargate_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Actor_EchoesStargate_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
