// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Core/Common/EchoesInteractableInterface.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesInteractableInterface() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
ECHOES_API UClass* Z_Construct_UClass_UEchoesInteractableInterface();
ECHOES_API UClass* Z_Construct_UClass_UEchoesInteractableInterface_NoRegister();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FEchoesInteractionResult();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FEchoesInteractionResult ******************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FEchoesInteractionResult;
class UScriptStruct* FEchoesInteractionResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FEchoesInteractionResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FEchoesInteractionResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FEchoesInteractionResult, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("EchoesInteractionResult"));
	}
	return Z_Registration_Info_UScriptStruct_FEchoesInteractionResult.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FEchoesInteractionResult_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Interaction result structure\n * Contains information about interaction success/failure\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesInteractableInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Interaction result structure\nContains information about interaction success/failure" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSuccess_MetaData[] = {
		{ "Category", "Interaction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether the interaction was successful */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesInteractableInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether the interaction was successful" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "Category", "Interaction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Message to display to player (error or info) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesInteractableInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Message to display to player (error or info)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetActor_MetaData[] = {
		{ "Category", "Interaction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Optional: actor that was interacted with */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesInteractableInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Optional: actor that was interacted with" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_bSuccess_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Message;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FEchoesInteractionResult>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
void Z_Construct_UScriptStruct_FEchoesInteractionResult_Statics::NewProp_bSuccess_SetBit(void* Obj)
{
	((FEchoesInteractionResult*)Obj)->bSuccess = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FEchoesInteractionResult_Statics::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FEchoesInteractionResult), &Z_Construct_UScriptStruct_FEchoesInteractionResult_Statics::NewProp_bSuccess_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSuccess_MetaData), NewProp_bSuccess_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FEchoesInteractionResult_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesInteractionResult, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FEchoesInteractionResult_Statics::NewProp_TargetActor = { "TargetActor", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesInteractionResult, TargetActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetActor_MetaData), NewProp_TargetActor_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FEchoesInteractionResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesInteractionResult_Statics::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesInteractionResult_Statics::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesInteractionResult_Statics::NewProp_TargetActor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEchoesInteractionResult_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FEchoesInteractionResult_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"EchoesInteractionResult",
	Z_Construct_UScriptStruct_FEchoesInteractionResult_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEchoesInteractionResult_Statics::PropPointers),
	sizeof(FEchoesInteractionResult),
	alignof(FEchoesInteractionResult),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEchoesInteractionResult_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FEchoesInteractionResult_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FEchoesInteractionResult()
{
	if (!Z_Registration_Info_UScriptStruct_FEchoesInteractionResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FEchoesInteractionResult.InnerSingleton, Z_Construct_UScriptStruct_FEchoesInteractionResult_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FEchoesInteractionResult.InnerSingleton;
}
// ********** End ScriptStruct FEchoesInteractionResult ********************************************

// ********** Begin Interface UEchoesInteractableInterface Function CanInteract ********************
struct EchoesInteractableInterface_eventCanInteract_Parms
{
	APawn* Interactor;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	EchoesInteractableInterface_eventCanInteract_Parms()
		: ReturnValue(false)
	{
	}
};
bool IEchoesInteractableInterface::CanInteract(APawn* Interactor) const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_CanInteract instead.");
	EchoesInteractableInterface_eventCanInteract_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UEchoesInteractableInterface_CanInteract = FName(TEXT("CanInteract"));
bool IEchoesInteractableInterface::Execute_CanInteract(const UObject* O, APawn* Interactor)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UEchoesInteractableInterface::StaticClass()));
	EchoesInteractableInterface_eventCanInteract_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UEchoesInteractableInterface_CanInteract);
	if (Func)
	{
		Parms.Interactor=Interactor;
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IEchoesInteractableInterface*)(O->GetNativeInterfaceAddress(UEchoesInteractableInterface::StaticClass())))
	{
		Parms.ReturnValue = I->CanInteract_Implementation(Interactor);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UEchoesInteractableInterface_CanInteract_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Interaction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if the actor can be interacted with\n\x09 * Called on both client and server\n\x09 * \n\x09 * @param Interactor - Pawn attempting to interact\n\x09 * @return True if interaction is allowed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesInteractableInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if the actor can be interacted with\nCalled on both client and server\n\n@param Interactor - Pawn attempting to interact\n@return True if interaction is allowed" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Interactor;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEchoesInteractableInterface_CanInteract_Statics::NewProp_Interactor = { "Interactor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInteractableInterface_eventCanInteract_Parms, Interactor), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UEchoesInteractableInterface_CanInteract_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesInteractableInterface_eventCanInteract_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEchoesInteractableInterface_CanInteract_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesInteractableInterface_eventCanInteract_Parms), &Z_Construct_UFunction_UEchoesInteractableInterface_CanInteract_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInteractableInterface_CanInteract_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInteractableInterface_CanInteract_Statics::NewProp_Interactor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInteractableInterface_CanInteract_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInteractableInterface_CanInteract_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInteractableInterface_CanInteract_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInteractableInterface, nullptr, "CanInteract", Z_Construct_UFunction_UEchoesInteractableInterface_CanInteract_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInteractableInterface_CanInteract_Statics::PropPointers), sizeof(EchoesInteractableInterface_eventCanInteract_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInteractableInterface_CanInteract_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInteractableInterface_CanInteract_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(EchoesInteractableInterface_eventCanInteract_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInteractableInterface_CanInteract()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInteractableInterface_CanInteract_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IEchoesInteractableInterface::execCanInteract)
{
	P_GET_OBJECT(APawn,Z_Param_Interactor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CanInteract_Implementation(Z_Param_Interactor);
	P_NATIVE_END;
}
// ********** End Interface UEchoesInteractableInterface Function CanInteract **********************

// ********** Begin Interface UEchoesInteractableInterface Function GetInteractionDistance *********
struct EchoesInteractableInterface_eventGetInteractionDistance_Parms
{
	float ReturnValue;

	/** Constructor, initializes return property only **/
	EchoesInteractableInterface_eventGetInteractionDistance_Parms()
		: ReturnValue(0)
	{
	}
};
float IEchoesInteractableInterface::GetInteractionDistance() const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetInteractionDistance instead.");
	EchoesInteractableInterface_eventGetInteractionDistance_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UEchoesInteractableInterface_GetInteractionDistance = FName(TEXT("GetInteractionDistance"));
float IEchoesInteractableInterface::Execute_GetInteractionDistance(const UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UEchoesInteractableInterface::StaticClass()));
	EchoesInteractableInterface_eventGetInteractionDistance_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UEchoesInteractableInterface_GetInteractionDistance);
	if (Func)
	{
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IEchoesInteractableInterface*)(O->GetNativeInterfaceAddress(UEchoesInteractableInterface::StaticClass())))
	{
		Parms.ReturnValue = I->GetInteractionDistance_Implementation();
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UEchoesInteractableInterface_GetInteractionDistance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Interaction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the interaction distance for this object\n\x09 * \n\x09 * @return Maximum interaction distance in cm (Unreal units)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesInteractableInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the interaction distance for this object\n\n@return Maximum interaction distance in cm (Unreal units)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesInteractableInterface_GetInteractionDistance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInteractableInterface_eventGetInteractionDistance_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInteractableInterface_GetInteractionDistance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInteractableInterface_GetInteractionDistance_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInteractableInterface_GetInteractionDistance_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInteractableInterface_GetInteractionDistance_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInteractableInterface, nullptr, "GetInteractionDistance", Z_Construct_UFunction_UEchoesInteractableInterface_GetInteractionDistance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInteractableInterface_GetInteractionDistance_Statics::PropPointers), sizeof(EchoesInteractableInterface_eventGetInteractionDistance_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInteractableInterface_GetInteractionDistance_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInteractableInterface_GetInteractionDistance_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(EchoesInteractableInterface_eventGetInteractionDistance_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInteractableInterface_GetInteractionDistance()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInteractableInterface_GetInteractionDistance_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IEchoesInteractableInterface::execGetInteractionDistance)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetInteractionDistance_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UEchoesInteractableInterface Function GetInteractionDistance ***********

// ********** Begin Interface UEchoesInteractableInterface Function GetInteractionPrompt ***********
struct EchoesInteractableInterface_eventGetInteractionPrompt_Parms
{
	FText ReturnValue;
};
FText IEchoesInteractableInterface::GetInteractionPrompt() const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetInteractionPrompt instead.");
	EchoesInteractableInterface_eventGetInteractionPrompt_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UEchoesInteractableInterface_GetInteractionPrompt = FName(TEXT("GetInteractionPrompt"));
FText IEchoesInteractableInterface::Execute_GetInteractionPrompt(const UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UEchoesInteractableInterface::StaticClass()));
	EchoesInteractableInterface_eventGetInteractionPrompt_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UEchoesInteractableInterface_GetInteractionPrompt);
	if (Func)
	{
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IEchoesInteractableInterface*)(O->GetNativeInterfaceAddress(UEchoesInteractableInterface::StaticClass())))
	{
		Parms.ReturnValue = I->GetInteractionPrompt_Implementation();
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UEchoesInteractableInterface_GetInteractionPrompt_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Interaction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the display name for interaction prompt\n\x09 * \n\x09 * @return Name to show in interaction UI\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesInteractableInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the display name for interaction prompt\n\n@return Name to show in interaction UI" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UEchoesInteractableInterface_GetInteractionPrompt_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInteractableInterface_eventGetInteractionPrompt_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInteractableInterface_GetInteractionPrompt_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInteractableInterface_GetInteractionPrompt_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInteractableInterface_GetInteractionPrompt_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInteractableInterface_GetInteractionPrompt_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInteractableInterface, nullptr, "GetInteractionPrompt", Z_Construct_UFunction_UEchoesInteractableInterface_GetInteractionPrompt_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInteractableInterface_GetInteractionPrompt_Statics::PropPointers), sizeof(EchoesInteractableInterface_eventGetInteractionPrompt_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInteractableInterface_GetInteractionPrompt_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInteractableInterface_GetInteractionPrompt_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(EchoesInteractableInterface_eventGetInteractionPrompt_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInteractableInterface_GetInteractionPrompt()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInteractableInterface_GetInteractionPrompt_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IEchoesInteractableInterface::execGetInteractionPrompt)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FText*)Z_Param__Result=P_THIS->GetInteractionPrompt_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UEchoesInteractableInterface Function GetInteractionPrompt *************

// ********** Begin Interface UEchoesInteractableInterface Function OnInteract *********************
struct EchoesInteractableInterface_eventOnInteract_Parms
{
	APawn* Interactor;
	FEchoesInteractionResult ReturnValue;
};
FEchoesInteractionResult IEchoesInteractableInterface::OnInteract(APawn* Interactor)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnInteract instead.");
	EchoesInteractableInterface_eventOnInteract_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UEchoesInteractableInterface_OnInteract = FName(TEXT("OnInteract"));
FEchoesInteractionResult IEchoesInteractableInterface::Execute_OnInteract(UObject* O, APawn* Interactor)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UEchoesInteractableInterface::StaticClass()));
	EchoesInteractableInterface_eventOnInteract_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UEchoesInteractableInterface_OnInteract);
	if (Func)
	{
		Parms.Interactor=Interactor;
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IEchoesInteractableInterface*)(O->GetNativeInterfaceAddress(UEchoesInteractableInterface::StaticClass())))
	{
		Parms.ReturnValue = I->OnInteract_Implementation(Interactor);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UEchoesInteractableInterface_OnInteract_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Interaction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Server-side interaction handler\n\x09 * Called when player interacts with this object\n\x09 * \n\x09 * @param Interactor - Pawn that initiated interaction\n\x09 * @return Interaction result\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesInteractableInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Server-side interaction handler\nCalled when player interacts with this object\n\n@param Interactor - Pawn that initiated interaction\n@return Interaction result" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Interactor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEchoesInteractableInterface_OnInteract_Statics::NewProp_Interactor = { "Interactor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInteractableInterface_eventOnInteract_Parms, Interactor), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesInteractableInterface_OnInteract_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInteractableInterface_eventOnInteract_Parms, ReturnValue), Z_Construct_UScriptStruct_FEchoesInteractionResult, METADATA_PARAMS(0, nullptr) }; // 332251469
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInteractableInterface_OnInteract_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInteractableInterface_OnInteract_Statics::NewProp_Interactor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInteractableInterface_OnInteract_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInteractableInterface_OnInteract_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInteractableInterface_OnInteract_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInteractableInterface, nullptr, "OnInteract", Z_Construct_UFunction_UEchoesInteractableInterface_OnInteract_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInteractableInterface_OnInteract_Statics::PropPointers), sizeof(EchoesInteractableInterface_eventOnInteract_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInteractableInterface_OnInteract_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInteractableInterface_OnInteract_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(EchoesInteractableInterface_eventOnInteract_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInteractableInterface_OnInteract()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInteractableInterface_OnInteract_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IEchoesInteractableInterface::execOnInteract)
{
	P_GET_OBJECT(APawn,Z_Param_Interactor);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FEchoesInteractionResult*)Z_Param__Result=P_THIS->OnInteract_Implementation(Z_Param_Interactor);
	P_NATIVE_END;
}
// ********** End Interface UEchoesInteractableInterface Function OnInteract ***********************

// ********** Begin Interface UEchoesInteractableInterface *****************************************
void UEchoesInteractableInterface::StaticRegisterNativesUEchoesInteractableInterface()
{
	UClass* Class = UEchoesInteractableInterface::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CanInteract", &IEchoesInteractableInterface::execCanInteract },
		{ "GetInteractionDistance", &IEchoesInteractableInterface::execGetInteractionDistance },
		{ "GetInteractionPrompt", &IEchoesInteractableInterface::execGetInteractionPrompt },
		{ "OnInteract", &IEchoesInteractableInterface::execOnInteract },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesInteractableInterface;
UClass* UEchoesInteractableInterface::GetPrivateStaticClass()
{
	using TClass = UEchoesInteractableInterface;
	if (!Z_Registration_Info_UClass_UEchoesInteractableInterface.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesInteractableInterface"),
			Z_Registration_Info_UClass_UEchoesInteractableInterface.InnerSingleton,
			StaticRegisterNativesUEchoesInteractableInterface,
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
	return Z_Registration_Info_UClass_UEchoesInteractableInterface.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesInteractableInterface_NoRegister()
{
	return UEchoesInteractableInterface::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesInteractableInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Core/Common/EchoesInteractableInterface.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesInteractableInterface_CanInteract, "CanInteract" }, // 3176174516
		{ &Z_Construct_UFunction_UEchoesInteractableInterface_GetInteractionDistance, "GetInteractionDistance" }, // 382380856
		{ &Z_Construct_UFunction_UEchoesInteractableInterface_GetInteractionPrompt, "GetInteractionPrompt" }, // 2339663920
		{ &Z_Construct_UFunction_UEchoesInteractableInterface_OnInteract, "OnInteract" }, // 3328887779
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IEchoesInteractableInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UEchoesInteractableInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesInteractableInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesInteractableInterface_Statics::ClassParams = {
	&UEchoesInteractableInterface::StaticClass,
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
	0x000840A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesInteractableInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesInteractableInterface_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesInteractableInterface()
{
	if (!Z_Registration_Info_UClass_UEchoesInteractableInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesInteractableInterface.OuterSingleton, Z_Construct_UClass_UEchoesInteractableInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesInteractableInterface.OuterSingleton;
}
UEchoesInteractableInterface::UEchoesInteractableInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesInteractableInterface);
// ********** End Interface UEchoesInteractableInterface *******************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesInteractableInterface_h__Script_Echoes_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FEchoesInteractionResult::StaticStruct, Z_Construct_UScriptStruct_FEchoesInteractionResult_Statics::NewStructOps, TEXT("EchoesInteractionResult"), &Z_Registration_Info_UScriptStruct_FEchoesInteractionResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FEchoesInteractionResult), 332251469U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesInteractableInterface, UEchoesInteractableInterface::StaticClass, TEXT("UEchoesInteractableInterface"), &Z_Registration_Info_UClass_UEchoesInteractableInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesInteractableInterface), 2005703613U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesInteractableInterface_h__Script_Echoes_2632167387(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesInteractableInterface_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesInteractableInterface_h__Script_Echoes_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesInteractableInterface_h__Script_Echoes_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesInteractableInterface_h__Script_Echoes_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
