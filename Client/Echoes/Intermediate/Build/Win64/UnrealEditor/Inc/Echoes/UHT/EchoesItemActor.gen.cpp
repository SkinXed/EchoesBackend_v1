// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Core/Common/EchoesItemActor.h"
#include "Core/Common/EchoesItemDefinitions.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesItemActor() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UClass* Z_Construct_UClass_AEchoesItemActor();
ECHOES_API UClass* Z_Construct_UClass_AEchoesItemActor_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesInteractableInterface_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UEchoesInventoryComponent_NoRegister();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FEchoesItemDefinitionRow();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AEchoesItemActor Function GetInstanceId **********************************
struct Z_Construct_UFunction_AEchoesItemActor_GetInstanceId_Statics
{
	struct EchoesItemActor_eventGetInstanceId_Parms
	{
		FGuid ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Item" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the instance ID\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesItemActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the instance ID" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesItemActor_GetInstanceId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesItemActor_eventGetInstanceId_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesItemActor_GetInstanceId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesItemActor_GetInstanceId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_GetInstanceId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesItemActor_GetInstanceId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesItemActor, nullptr, "GetInstanceId", Z_Construct_UFunction_AEchoesItemActor_GetInstanceId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_GetInstanceId_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesItemActor_GetInstanceId_Statics::EchoesItemActor_eventGetInstanceId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_GetInstanceId_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesItemActor_GetInstanceId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesItemActor_GetInstanceId_Statics::EchoesItemActor_eventGetInstanceId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesItemActor_GetInstanceId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesItemActor_GetInstanceId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesItemActor::execGetInstanceId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGuid*)Z_Param__Result=P_THIS->GetInstanceId();
	P_NATIVE_END;
}
// ********** End Class AEchoesItemActor Function GetInstanceId ************************************

// ********** Begin Class AEchoesItemActor Function GetInventoryComponent **************************
struct Z_Construct_UFunction_AEchoesItemActor_GetInventoryComponent_Statics
{
	struct EchoesItemActor_eventGetInventoryComponent_Parms
	{
		UEchoesInventoryComponent* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Item" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the inventory component\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesItemActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the inventory component" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AEchoesItemActor_GetInventoryComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesItemActor_eventGetInventoryComponent_Parms, ReturnValue), Z_Construct_UClass_UEchoesInventoryComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesItemActor_GetInventoryComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesItemActor_GetInventoryComponent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_GetInventoryComponent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesItemActor_GetInventoryComponent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesItemActor, nullptr, "GetInventoryComponent", Z_Construct_UFunction_AEchoesItemActor_GetInventoryComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_GetInventoryComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesItemActor_GetInventoryComponent_Statics::EchoesItemActor_eventGetInventoryComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_GetInventoryComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesItemActor_GetInventoryComponent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesItemActor_GetInventoryComponent_Statics::EchoesItemActor_eventGetInventoryComponent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesItemActor_GetInventoryComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesItemActor_GetInventoryComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesItemActor::execGetInventoryComponent)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UEchoesInventoryComponent**)Z_Param__Result=P_THIS->GetInventoryComponent();
	P_NATIVE_END;
}
// ********** End Class AEchoesItemActor Function GetInventoryComponent ****************************

// ********** Begin Class AEchoesItemActor Function GetItemDefinitionData **************************
struct Z_Construct_UFunction_AEchoesItemActor_GetItemDefinitionData_Statics
{
	struct EchoesItemActor_eventGetItemDefinitionData_Parms
	{
		FEchoesItemDefinitionRow ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Item" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the item definition data for Blueprints\n\x09 * @return Definition data if cached, otherwise default-constructed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesItemActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the item definition data for Blueprints\n@return Definition data if cached, otherwise default-constructed" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesItemActor_GetItemDefinitionData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesItemActor_eventGetItemDefinitionData_Parms, ReturnValue), Z_Construct_UScriptStruct_FEchoesItemDefinitionRow, METADATA_PARAMS(0, nullptr) }; // 987535441
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesItemActor_GetItemDefinitionData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesItemActor_GetItemDefinitionData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_GetItemDefinitionData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesItemActor_GetItemDefinitionData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesItemActor, nullptr, "GetItemDefinitionData", Z_Construct_UFunction_AEchoesItemActor_GetItemDefinitionData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_GetItemDefinitionData_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesItemActor_GetItemDefinitionData_Statics::EchoesItemActor_eventGetItemDefinitionData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_GetItemDefinitionData_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesItemActor_GetItemDefinitionData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesItemActor_GetItemDefinitionData_Statics::EchoesItemActor_eventGetItemDefinitionData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesItemActor_GetItemDefinitionData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesItemActor_GetItemDefinitionData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesItemActor::execGetItemDefinitionData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FEchoesItemDefinitionRow*)Z_Param__Result=P_THIS->GetItemDefinitionData();
	P_NATIVE_END;
}
// ********** End Class AEchoesItemActor Function GetItemDefinitionData ****************************

// ********** Begin Class AEchoesItemActor Function GetItemId **************************************
struct Z_Construct_UFunction_AEchoesItemActor_GetItemId_Statics
{
	struct EchoesItemActor_eventGetItemId_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Item" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the item type ID\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesItemActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the item type ID" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AEchoesItemActor_GetItemId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesItemActor_eventGetItemId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesItemActor_GetItemId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesItemActor_GetItemId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_GetItemId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesItemActor_GetItemId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesItemActor, nullptr, "GetItemId", Z_Construct_UFunction_AEchoesItemActor_GetItemId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_GetItemId_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesItemActor_GetItemId_Statics::EchoesItemActor_eventGetItemId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_GetItemId_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesItemActor_GetItemId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesItemActor_GetItemId_Statics::EchoesItemActor_eventGetItemId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesItemActor_GetItemId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesItemActor_GetItemId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesItemActor::execGetItemId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=P_THIS->GetItemId();
	P_NATIVE_END;
}
// ********** End Class AEchoesItemActor Function GetItemId ****************************************

// ********** Begin Class AEchoesItemActor Function GetRemainingLifetime ***************************
struct Z_Construct_UFunction_AEchoesItemActor_GetRemainingLifetime_Statics
{
	struct EchoesItemActor_eventGetRemainingLifetime_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Item" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get remaining lifetime in seconds\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesItemActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get remaining lifetime in seconds" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AEchoesItemActor_GetRemainingLifetime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesItemActor_eventGetRemainingLifetime_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesItemActor_GetRemainingLifetime_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesItemActor_GetRemainingLifetime_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_GetRemainingLifetime_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesItemActor_GetRemainingLifetime_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesItemActor, nullptr, "GetRemainingLifetime", Z_Construct_UFunction_AEchoesItemActor_GetRemainingLifetime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_GetRemainingLifetime_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesItemActor_GetRemainingLifetime_Statics::EchoesItemActor_eventGetRemainingLifetime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_GetRemainingLifetime_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesItemActor_GetRemainingLifetime_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesItemActor_GetRemainingLifetime_Statics::EchoesItemActor_eventGetRemainingLifetime_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesItemActor_GetRemainingLifetime()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesItemActor_GetRemainingLifetime_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesItemActor::execGetRemainingLifetime)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetRemainingLifetime();
	P_NATIVE_END;
}
// ********** End Class AEchoesItemActor Function GetRemainingLifetime *****************************

// ********** Begin Class AEchoesItemActor Function IsContainer ************************************
struct Z_Construct_UFunction_AEchoesItemActor_IsContainer_Statics
{
	struct EchoesItemActor_eventIsContainer_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Item" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if this is a container (has inventory)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesItemActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if this is a container (has inventory)" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AEchoesItemActor_IsContainer_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesItemActor_eventIsContainer_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AEchoesItemActor_IsContainer_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesItemActor_eventIsContainer_Parms), &Z_Construct_UFunction_AEchoesItemActor_IsContainer_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesItemActor_IsContainer_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesItemActor_IsContainer_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_IsContainer_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesItemActor_IsContainer_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesItemActor, nullptr, "IsContainer", Z_Construct_UFunction_AEchoesItemActor_IsContainer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_IsContainer_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesItemActor_IsContainer_Statics::EchoesItemActor_eventIsContainer_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_IsContainer_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesItemActor_IsContainer_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesItemActor_IsContainer_Statics::EchoesItemActor_eventIsContainer_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesItemActor_IsContainer()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesItemActor_IsContainer_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesItemActor::execIsContainer)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsContainer();
	P_NATIVE_END;
}
// ********** End Class AEchoesItemActor Function IsContainer **************************************

// ********** Begin Class AEchoesItemActor Function OnItemInitialized ******************************
static FName NAME_AEchoesItemActor_OnItemInitialized = FName(TEXT("OnItemInitialized"));
void AEchoesItemActor::OnItemInitialized()
{
	UFunction* Func = FindFunctionChecked(NAME_AEchoesItemActor_OnItemInitialized);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_AEchoesItemActor_OnItemInitialized_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Item" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Blueprint event called when item is initialized\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesItemActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint event called when item is initialized" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesItemActor_OnItemInitialized_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesItemActor, nullptr, "OnItemInitialized", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_OnItemInitialized_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesItemActor_OnItemInitialized_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AEchoesItemActor_OnItemInitialized()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesItemActor_OnItemInitialized_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class AEchoesItemActor Function OnItemInitialized ********************************

// ********** Begin Class AEchoesItemActor Function OnLifetimeExpired ******************************
struct Z_Construct_UFunction_AEchoesItemActor_OnLifetimeExpired_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Handle lifetime expiration\n\x09 * Destroys the actor when lifetime expires\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesItemActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle lifetime expiration\nDestroys the actor when lifetime expires" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesItemActor_OnLifetimeExpired_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesItemActor, nullptr, "OnLifetimeExpired", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_OnLifetimeExpired_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesItemActor_OnLifetimeExpired_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AEchoesItemActor_OnLifetimeExpired()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesItemActor_OnLifetimeExpired_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesItemActor::execOnLifetimeExpired)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnLifetimeExpired();
	P_NATIVE_END;
}
// ********** End Class AEchoesItemActor Function OnLifetimeExpired ********************************

// ********** Begin Class AEchoesItemActor Function OnMeshLoaded ***********************************
struct Z_Construct_UFunction_AEchoesItemActor_OnMeshLoaded_Statics
{
	struct EchoesItemActor_eventOnMeshLoaded_Parms
	{
		UStaticMesh* LoadedMesh;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Handle mesh loaded callback\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesItemActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle mesh loaded callback" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LoadedMesh;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AEchoesItemActor_OnMeshLoaded_Statics::NewProp_LoadedMesh = { "LoadedMesh", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesItemActor_eventOnMeshLoaded_Parms, LoadedMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesItemActor_OnMeshLoaded_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesItemActor_OnMeshLoaded_Statics::NewProp_LoadedMesh,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_OnMeshLoaded_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesItemActor_OnMeshLoaded_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesItemActor, nullptr, "OnMeshLoaded", Z_Construct_UFunction_AEchoesItemActor_OnMeshLoaded_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_OnMeshLoaded_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesItemActor_OnMeshLoaded_Statics::EchoesItemActor_eventOnMeshLoaded_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_OnMeshLoaded_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesItemActor_OnMeshLoaded_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesItemActor_OnMeshLoaded_Statics::EchoesItemActor_eventOnMeshLoaded_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesItemActor_OnMeshLoaded()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesItemActor_OnMeshLoaded_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesItemActor::execOnMeshLoaded)
{
	P_GET_OBJECT(UStaticMesh,Z_Param_LoadedMesh);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnMeshLoaded(Z_Param_LoadedMesh);
	P_NATIVE_END;
}
// ********** End Class AEchoesItemActor Function OnMeshLoaded *************************************

// ********** Begin Class AEchoesItemActor Function OnPlayerInteracted *****************************
struct EchoesItemActor_eventOnPlayerInteracted_Parms
{
	APawn* Interactor;
};
static FName NAME_AEchoesItemActor_OnPlayerInteracted = FName(TEXT("OnPlayerInteracted"));
void AEchoesItemActor::OnPlayerInteracted(APawn* Interactor)
{
	EchoesItemActor_eventOnPlayerInteracted_Parms Parms;
	Parms.Interactor=Interactor;
	UFunction* Func = FindFunctionChecked(NAME_AEchoesItemActor_OnPlayerInteracted);
	ProcessEvent(Func,&Parms);
}
struct Z_Construct_UFunction_AEchoesItemActor_OnPlayerInteracted_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Item" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Blueprint event called when player interacts\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesItemActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint event called when player interacts" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Interactor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AEchoesItemActor_OnPlayerInteracted_Statics::NewProp_Interactor = { "Interactor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesItemActor_eventOnPlayerInteracted_Parms, Interactor), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesItemActor_OnPlayerInteracted_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesItemActor_OnPlayerInteracted_Statics::NewProp_Interactor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_OnPlayerInteracted_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesItemActor_OnPlayerInteracted_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesItemActor, nullptr, "OnPlayerInteracted", Z_Construct_UFunction_AEchoesItemActor_OnPlayerInteracted_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_OnPlayerInteracted_Statics::PropPointers), sizeof(EchoesItemActor_eventOnPlayerInteracted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_OnPlayerInteracted_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesItemActor_OnPlayerInteracted_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(EchoesItemActor_eventOnPlayerInteracted_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesItemActor_OnPlayerInteracted()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesItemActor_OnPlayerInteracted_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class AEchoesItemActor Function OnPlayerInteracted *******************************

// ********** Begin Class AEchoesItemActor Function OnRep_ItemId ***********************************
struct Z_Construct_UFunction_AEchoesItemActor_OnRep_ItemId_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Replication notification */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesItemActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Replication notification" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesItemActor_OnRep_ItemId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesItemActor, nullptr, "OnRep_ItemId", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_OnRep_ItemId_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesItemActor_OnRep_ItemId_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_AEchoesItemActor_OnRep_ItemId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesItemActor_OnRep_ItemId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesItemActor::execOnRep_ItemId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRep_ItemId();
	P_NATIVE_END;
}
// ********** End Class AEchoesItemActor Function OnRep_ItemId *************************************

// ********** Begin Class AEchoesItemActor Function ServerOnly_InitializeItem **********************
struct Z_Construct_UFunction_AEchoesItemActor_ServerOnly_InitializeItem_Statics
{
	struct EchoesItemActor_eventServerOnly_InitializeItem_Parms
	{
		FString ItemId;
		FGuid InstanceId;
		int64 Quantity;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Item" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * SERVER ONLY: Initialize the item actor with item definition\n\x09 * Loads mesh asynchronously and configures components\n\x09 * \n\x09 * @param ItemId - Item type ID from database (as string)\n\x09 * @param InstanceId - Unique instance ID for this spawned item\n\x09 * @param Quantity - Quantity of items in this container\n\x09 */" },
#endif
		{ "CPP_Default_Quantity", "1" },
		{ "DisplayName", "ServerOnly InitializeItem" },
		{ "ModuleRelativePath", "Core/Common/EchoesItemActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "SERVER ONLY: Initialize the item actor with item definition\nLoads mesh asynchronously and configures components\n\n@param ItemId - Item type ID from database (as string)\n@param InstanceId - Unique instance ID for this spawned item\n@param Quantity - Quantity of items in this container" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemId_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InstanceId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ItemId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InstanceId;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AEchoesItemActor_ServerOnly_InitializeItem_Statics::NewProp_ItemId = { "ItemId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesItemActor_eventServerOnly_InitializeItem_Parms, ItemId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemId_MetaData), NewProp_ItemId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEchoesItemActor_ServerOnly_InitializeItem_Statics::NewProp_InstanceId = { "InstanceId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesItemActor_eventServerOnly_InitializeItem_Parms, InstanceId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InstanceId_MetaData), NewProp_InstanceId_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_AEchoesItemActor_ServerOnly_InitializeItem_Statics::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesItemActor_eventServerOnly_InitializeItem_Parms, Quantity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesItemActor_ServerOnly_InitializeItem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesItemActor_ServerOnly_InitializeItem_Statics::NewProp_ItemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesItemActor_ServerOnly_InitializeItem_Statics::NewProp_InstanceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesItemActor_ServerOnly_InitializeItem_Statics::NewProp_Quantity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_ServerOnly_InitializeItem_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesItemActor_ServerOnly_InitializeItem_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesItemActor, nullptr, "ServerOnly_InitializeItem", Z_Construct_UFunction_AEchoesItemActor_ServerOnly_InitializeItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_ServerOnly_InitializeItem_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesItemActor_ServerOnly_InitializeItem_Statics::EchoesItemActor_eventServerOnly_InitializeItem_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_ServerOnly_InitializeItem_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesItemActor_ServerOnly_InitializeItem_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesItemActor_ServerOnly_InitializeItem_Statics::EchoesItemActor_eventServerOnly_InitializeItem_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesItemActor_ServerOnly_InitializeItem()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesItemActor_ServerOnly_InitializeItem_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesItemActor::execServerOnly_InitializeItem)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ItemId);
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_InstanceId);
	P_GET_PROPERTY(FInt64Property,Z_Param_Quantity);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_InitializeItem(Z_Param_ItemId,Z_Param_Out_InstanceId,Z_Param_Quantity);
	P_NATIVE_END;
}
// ********** End Class AEchoesItemActor Function ServerOnly_InitializeItem ************************

// ********** Begin Class AEchoesItemActor Function SetLifetime ************************************
struct Z_Construct_UFunction_AEchoesItemActor_SetLifetime_Statics
{
	struct EchoesItemActor_eventSetLifetime_Parms
	{
		float LifetimeSeconds;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Item" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Set the item lifetime before auto-despawn\n\x09 * \n\x09 * @param LifetimeSeconds - Time in seconds (default: 7200 = 2 hours)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesItemActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set the item lifetime before auto-despawn\n\n@param LifetimeSeconds - Time in seconds (default: 7200 = 2 hours)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LifetimeSeconds;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AEchoesItemActor_SetLifetime_Statics::NewProp_LifetimeSeconds = { "LifetimeSeconds", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesItemActor_eventSetLifetime_Parms, LifetimeSeconds), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEchoesItemActor_SetLifetime_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEchoesItemActor_SetLifetime_Statics::NewProp_LifetimeSeconds,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_SetLifetime_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEchoesItemActor_SetLifetime_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_AEchoesItemActor, nullptr, "SetLifetime", Z_Construct_UFunction_AEchoesItemActor_SetLifetime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_SetLifetime_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEchoesItemActor_SetLifetime_Statics::EchoesItemActor_eventSetLifetime_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEchoesItemActor_SetLifetime_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEchoesItemActor_SetLifetime_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_AEchoesItemActor_SetLifetime_Statics::EchoesItemActor_eventSetLifetime_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AEchoesItemActor_SetLifetime()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEchoesItemActor_SetLifetime_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AEchoesItemActor::execSetLifetime)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_LifetimeSeconds);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetLifetime(Z_Param_LifetimeSeconds);
	P_NATIVE_END;
}
// ********** End Class AEchoesItemActor Function SetLifetime **************************************

// ********** Begin Class AEchoesItemActor *********************************************************
void AEchoesItemActor::StaticRegisterNativesAEchoesItemActor()
{
	UClass* Class = AEchoesItemActor::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetInstanceId", &AEchoesItemActor::execGetInstanceId },
		{ "GetInventoryComponent", &AEchoesItemActor::execGetInventoryComponent },
		{ "GetItemDefinitionData", &AEchoesItemActor::execGetItemDefinitionData },
		{ "GetItemId", &AEchoesItemActor::execGetItemId },
		{ "GetRemainingLifetime", &AEchoesItemActor::execGetRemainingLifetime },
		{ "IsContainer", &AEchoesItemActor::execIsContainer },
		{ "OnLifetimeExpired", &AEchoesItemActor::execOnLifetimeExpired },
		{ "OnMeshLoaded", &AEchoesItemActor::execOnMeshLoaded },
		{ "OnRep_ItemId", &AEchoesItemActor::execOnRep_ItemId },
		{ "ServerOnly_InitializeItem", &AEchoesItemActor::execServerOnly_InitializeItem },
		{ "SetLifetime", &AEchoesItemActor::execSetLifetime },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_AEchoesItemActor;
UClass* AEchoesItemActor::GetPrivateStaticClass()
{
	using TClass = AEchoesItemActor;
	if (!Z_Registration_Info_UClass_AEchoesItemActor.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesItemActor"),
			Z_Registration_Info_UClass_AEchoesItemActor.InnerSingleton,
			StaticRegisterNativesAEchoesItemActor,
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
	return Z_Registration_Info_UClass_AEchoesItemActor.InnerSingleton;
}
UClass* Z_Construct_UClass_AEchoesItemActor_NoRegister()
{
	return AEchoesItemActor::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AEchoesItemActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * AEchoesItemActor\n * \n * Universal actor for representing items and containers in space\n * Can represent:\n * - Ejected loot containers\n * - Jettisoned cargo\n * - Wrecks with loot\n * - Deployable containers\n * \n * Features:\n * - Dynamic mesh loading based on item definition\n * - Physics simulation for drifting in space\n * - Inventory storage via UEchoesInventoryComponent\n * - Interaction system for looting\n * - Replication for multiplayer\n * - Auto-despawn after configurable lifetime\n * \n * Architecture:\n * - Server spawns and initializes\n * - Mesh loads asynchronously\n * - Physics enabled for realistic drift\n * - Players can interact within range\n * - Inventory synced via component\n * - Auto-cleanup after lifetime expires\n */" },
#endif
		{ "IncludePath", "Core/Common/EchoesItemActor.h" },
		{ "ModuleRelativePath", "Core/Common/EchoesItemActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "AEchoesItemActor\n\nUniversal actor for representing items and containers in space\nCan represent:\n- Ejected loot containers\n- Jettisoned cargo\n- Wrecks with loot\n- Deployable containers\n\nFeatures:\n- Dynamic mesh loading based on item definition\n- Physics simulation for drifting in space\n- Inventory storage via UEchoesInventoryComponent\n- Interaction system for looting\n- Replication for multiplayer\n- Auto-despawn after configurable lifetime\n\nArchitecture:\n- Server spawns and initializes\n- Mesh loads asynchronously\n- Physics enabled for realistic drift\n- Players can interact within range\n- Inventory synced via component\n- Auto-cleanup after lifetime expires" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MeshComponent_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Visual mesh component */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/EchoesItemActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Visual mesh component" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionSphere_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Interaction collision sphere */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/EchoesItemActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Interaction collision sphere" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InventoryComponent_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Inventory storage component */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Core/Common/EchoesItemActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Inventory storage component" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemId_MetaData[] = {
		{ "Category", "Item" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Item type ID from database (replicated) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesItemActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Item type ID from database (replicated)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InstanceId_MetaData[] = {
		{ "Category", "Item" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Instance ID for this spawned item (replicated) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesItemActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Instance ID for this spawned item (replicated)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Quantity_MetaData[] = {
		{ "Category", "Item" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Quantity of items (for stacks) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesItemActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Quantity of items (for stacks)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InteractionDistance_MetaData[] = {
		{ "Category", "Interaction" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum interaction distance (in cm) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesItemActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum interaction distance (in cm)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Lifetime_MetaData[] = {
		{ "Category", "Item|Lifetime" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Lifetime before auto-despawn (in seconds, 0 = never despawn) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesItemActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Lifetime before auto-despawn (in seconds, 0 = never despawn)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnablePhysics_MetaData[] = {
		{ "Category", "Item|Physics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether to enable physics simulation */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesItemActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether to enable physics simulation" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bApplyRandomVelocity_MetaData[] = {
		{ "Category", "Item|Physics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether to apply initial random velocity */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesItemActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether to apply initial random velocity" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxRandomVelocity_MetaData[] = {
		{ "Category", "Item|Physics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum random velocity magnitude (cm/s) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesItemActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum random velocity magnitude (cm/s)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsContainer_MetaData[] = {
		{ "Category", "Item" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Whether this item is a container with inventory */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesItemActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether this item is a container with inventory" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MeshComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InteractionSphere;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InventoryComponent;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ItemId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InstanceId;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InteractionDistance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Lifetime;
	static void NewProp_bEnablePhysics_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnablePhysics;
	static void NewProp_bApplyRandomVelocity_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bApplyRandomVelocity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxRandomVelocity;
	static void NewProp_bIsContainer_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsContainer;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AEchoesItemActor_GetInstanceId, "GetInstanceId" }, // 1247060346
		{ &Z_Construct_UFunction_AEchoesItemActor_GetInventoryComponent, "GetInventoryComponent" }, // 2070979764
		{ &Z_Construct_UFunction_AEchoesItemActor_GetItemDefinitionData, "GetItemDefinitionData" }, // 2766042347
		{ &Z_Construct_UFunction_AEchoesItemActor_GetItemId, "GetItemId" }, // 725325789
		{ &Z_Construct_UFunction_AEchoesItemActor_GetRemainingLifetime, "GetRemainingLifetime" }, // 3756903387
		{ &Z_Construct_UFunction_AEchoesItemActor_IsContainer, "IsContainer" }, // 2376058612
		{ &Z_Construct_UFunction_AEchoesItemActor_OnItemInitialized, "OnItemInitialized" }, // 3097694575
		{ &Z_Construct_UFunction_AEchoesItemActor_OnLifetimeExpired, "OnLifetimeExpired" }, // 4212119958
		{ &Z_Construct_UFunction_AEchoesItemActor_OnMeshLoaded, "OnMeshLoaded" }, // 3055086339
		{ &Z_Construct_UFunction_AEchoesItemActor_OnPlayerInteracted, "OnPlayerInteracted" }, // 3060250139
		{ &Z_Construct_UFunction_AEchoesItemActor_OnRep_ItemId, "OnRep_ItemId" }, // 1259217287
		{ &Z_Construct_UFunction_AEchoesItemActor_ServerOnly_InitializeItem, "ServerOnly_InitializeItem" }, // 671087272
		{ &Z_Construct_UFunction_AEchoesItemActor_SetLifetime, "SetLifetime" }, // 3021001973
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEchoesItemActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesItemActor_Statics::NewProp_MeshComponent = { "MeshComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesItemActor, MeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MeshComponent_MetaData), NewProp_MeshComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesItemActor_Statics::NewProp_InteractionSphere = { "InteractionSphere", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesItemActor, InteractionSphere), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionSphere_MetaData), NewProp_InteractionSphere_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEchoesItemActor_Statics::NewProp_InventoryComponent = { "InventoryComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesItemActor, InventoryComponent), Z_Construct_UClass_UEchoesInventoryComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InventoryComponent_MetaData), NewProp_InventoryComponent_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AEchoesItemActor_Statics::NewProp_ItemId = { "ItemId", "OnRep_ItemId", (EPropertyFlags)0x0020080100000034, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesItemActor, ItemId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemId_MetaData), NewProp_ItemId_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AEchoesItemActor_Statics::NewProp_InstanceId = { "InstanceId", nullptr, (EPropertyFlags)0x0020080000000034, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesItemActor, InstanceId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InstanceId_MetaData), NewProp_InstanceId_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UClass_AEchoesItemActor_Statics::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0020080000000034, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesItemActor, Quantity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Quantity_MetaData), NewProp_Quantity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEchoesItemActor_Statics::NewProp_InteractionDistance = { "InteractionDistance", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesItemActor, InteractionDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InteractionDistance_MetaData), NewProp_InteractionDistance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEchoesItemActor_Statics::NewProp_Lifetime = { "Lifetime", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesItemActor, Lifetime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Lifetime_MetaData), NewProp_Lifetime_MetaData) };
void Z_Construct_UClass_AEchoesItemActor_Statics::NewProp_bEnablePhysics_SetBit(void* Obj)
{
	((AEchoesItemActor*)Obj)->bEnablePhysics = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AEchoesItemActor_Statics::NewProp_bEnablePhysics = { "bEnablePhysics", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AEchoesItemActor), &Z_Construct_UClass_AEchoesItemActor_Statics::NewProp_bEnablePhysics_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnablePhysics_MetaData), NewProp_bEnablePhysics_MetaData) };
void Z_Construct_UClass_AEchoesItemActor_Statics::NewProp_bApplyRandomVelocity_SetBit(void* Obj)
{
	((AEchoesItemActor*)Obj)->bApplyRandomVelocity = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AEchoesItemActor_Statics::NewProp_bApplyRandomVelocity = { "bApplyRandomVelocity", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AEchoesItemActor), &Z_Construct_UClass_AEchoesItemActor_Statics::NewProp_bApplyRandomVelocity_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bApplyRandomVelocity_MetaData), NewProp_bApplyRandomVelocity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEchoesItemActor_Statics::NewProp_MaxRandomVelocity = { "MaxRandomVelocity", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEchoesItemActor, MaxRandomVelocity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxRandomVelocity_MetaData), NewProp_MaxRandomVelocity_MetaData) };
void Z_Construct_UClass_AEchoesItemActor_Statics::NewProp_bIsContainer_SetBit(void* Obj)
{
	((AEchoesItemActor*)Obj)->bIsContainer = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AEchoesItemActor_Statics::NewProp_bIsContainer = { "bIsContainer", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AEchoesItemActor), &Z_Construct_UClass_AEchoesItemActor_Statics::NewProp_bIsContainer_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsContainer_MetaData), NewProp_bIsContainer_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEchoesItemActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesItemActor_Statics::NewProp_MeshComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesItemActor_Statics::NewProp_InteractionSphere,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesItemActor_Statics::NewProp_InventoryComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesItemActor_Statics::NewProp_ItemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesItemActor_Statics::NewProp_InstanceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesItemActor_Statics::NewProp_Quantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesItemActor_Statics::NewProp_InteractionDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesItemActor_Statics::NewProp_Lifetime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesItemActor_Statics::NewProp_bEnablePhysics,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesItemActor_Statics::NewProp_bApplyRandomVelocity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesItemActor_Statics::NewProp_MaxRandomVelocity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEchoesItemActor_Statics::NewProp_bIsContainer,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesItemActor_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AEchoesItemActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesItemActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AEchoesItemActor_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UEchoesInteractableInterface_NoRegister, (int32)VTABLE_OFFSET(AEchoesItemActor, IEchoesInteractableInterface), false },  // 2005703613
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEchoesItemActor_Statics::ClassParams = {
	&AEchoesItemActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AEchoesItemActor_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesItemActor_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x009001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEchoesItemActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AEchoesItemActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEchoesItemActor()
{
	if (!Z_Registration_Info_UClass_AEchoesItemActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEchoesItemActor.OuterSingleton, Z_Construct_UClass_AEchoesItemActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEchoesItemActor.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void AEchoesItemActor::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_ItemId(TEXT("ItemId"));
	static FName Name_InstanceId(TEXT("InstanceId"));
	static FName Name_Quantity(TEXT("Quantity"));
	const bool bIsValid = true
		&& Name_ItemId == ClassReps[(int32)ENetFields_Private::ItemId].Property->GetFName()
		&& Name_InstanceId == ClassReps[(int32)ENetFields_Private::InstanceId].Property->GetFName()
		&& Name_Quantity == ClassReps[(int32)ENetFields_Private::Quantity].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AEchoesItemActor"));
}
#endif
DEFINE_VTABLE_PTR_HELPER_CTOR(AEchoesItemActor);
AEchoesItemActor::~AEchoesItemActor() {}
// ********** End Class AEchoesItemActor ***********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesItemActor_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEchoesItemActor, AEchoesItemActor::StaticClass, TEXT("AEchoesItemActor"), &Z_Registration_Info_UClass_AEchoesItemActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEchoesItemActor), 3064193951U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesItemActor_h__Script_Echoes_1028386781(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesItemActor_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesItemActor_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
