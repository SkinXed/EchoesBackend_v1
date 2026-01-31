// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Echoes/UI/EchoesInventoryDragDrop.h"
#include "Echoes/Core/Common/EchoesInventoryComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesInventoryDragDrop() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UClass* Z_Construct_UClass_UEchoesInventoryDragDrop();
ECHOES_API UClass* Z_Construct_UClass_UEchoesInventoryDragDrop_NoRegister();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FEchoesInventoryItem();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
UMG_API UClass* Z_Construct_UClass_UDragDropOperation();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UEchoesInventoryDragDrop Function GetItemData ****************************
struct Z_Construct_UFunction_UEchoesInventoryDragDrop_GetItemData_Statics
{
	struct EchoesInventoryDragDrop_eventGetItemData_Parms
	{
		FEchoesInventoryItem ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|DragDrop" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the item data being dragged\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryDragDrop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the item data being dragged" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesInventoryDragDrop_GetItemData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryDragDrop_eventGetItemData_Parms, ReturnValue), Z_Construct_UScriptStruct_FEchoesInventoryItem, METADATA_PARAMS(0, nullptr) }; // 3518727963
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryDragDrop_GetItemData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryDragDrop_GetItemData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryDragDrop_GetItemData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryDragDrop_GetItemData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryDragDrop, nullptr, "GetItemData", Z_Construct_UFunction_UEchoesInventoryDragDrop_GetItemData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryDragDrop_GetItemData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryDragDrop_GetItemData_Statics::EchoesInventoryDragDrop_eventGetItemData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryDragDrop_GetItemData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryDragDrop_GetItemData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryDragDrop_GetItemData_Statics::EchoesInventoryDragDrop_eventGetItemData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryDragDrop_GetItemData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryDragDrop_GetItemData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryDragDrop::execGetItemData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FEchoesInventoryItem*)Z_Param__Result=P_THIS->GetItemData();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryDragDrop Function GetItemData ******************************

// ********** Begin Class UEchoesInventoryDragDrop Function GetQuantity ****************************
struct Z_Construct_UFunction_UEchoesInventoryDragDrop_GetQuantity_Statics
{
	struct EchoesInventoryDragDrop_eventGetQuantity_Parms
	{
		int64 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|DragDrop" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the quantity being moved\n\x09 * @return Quantity to move (0 means all/full stack)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryDragDrop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the quantity being moved\n@return Quantity to move (0 means all/full stack)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UEchoesInventoryDragDrop_GetQuantity_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryDragDrop_eventGetQuantity_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryDragDrop_GetQuantity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryDragDrop_GetQuantity_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryDragDrop_GetQuantity_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryDragDrop_GetQuantity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryDragDrop, nullptr, "GetQuantity", Z_Construct_UFunction_UEchoesInventoryDragDrop_GetQuantity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryDragDrop_GetQuantity_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryDragDrop_GetQuantity_Statics::EchoesInventoryDragDrop_eventGetQuantity_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryDragDrop_GetQuantity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryDragDrop_GetQuantity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryDragDrop_GetQuantity_Statics::EchoesInventoryDragDrop_eventGetQuantity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryDragDrop_GetQuantity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryDragDrop_GetQuantity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryDragDrop::execGetQuantity)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int64*)Z_Param__Result=P_THIS->GetQuantity();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryDragDrop Function GetQuantity ******************************

// ********** Begin Class UEchoesInventoryDragDrop Function GetSourceActor *************************
struct Z_Construct_UFunction_UEchoesInventoryDragDrop_GetSourceActor_Statics
{
	struct EchoesInventoryDragDrop_eventGetSourceActor_Parms
	{
		AActor* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|DragDrop" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the source actor\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryDragDrop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the source actor" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEchoesInventoryDragDrop_GetSourceActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryDragDrop_eventGetSourceActor_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryDragDrop_GetSourceActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryDragDrop_GetSourceActor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryDragDrop_GetSourceActor_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryDragDrop_GetSourceActor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryDragDrop, nullptr, "GetSourceActor", Z_Construct_UFunction_UEchoesInventoryDragDrop_GetSourceActor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryDragDrop_GetSourceActor_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryDragDrop_GetSourceActor_Statics::EchoesInventoryDragDrop_eventGetSourceActor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryDragDrop_GetSourceActor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryDragDrop_GetSourceActor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryDragDrop_GetSourceActor_Statics::EchoesInventoryDragDrop_eventGetSourceActor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryDragDrop_GetSourceActor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryDragDrop_GetSourceActor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryDragDrop::execGetSourceActor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AActor**)Z_Param__Result=P_THIS->GetSourceActor();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryDragDrop Function GetSourceActor ***************************

// ********** Begin Class UEchoesInventoryDragDrop Function GetSourceStorageId *********************
struct Z_Construct_UFunction_UEchoesInventoryDragDrop_GetSourceStorageId_Statics
{
	struct EchoesInventoryDragDrop_eventGetSourceStorageId_Parms
	{
		FGuid ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|DragDrop" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the source storage ID\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryDragDrop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the source storage ID" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesInventoryDragDrop_GetSourceStorageId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryDragDrop_eventGetSourceStorageId_Parms, ReturnValue), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryDragDrop_GetSourceStorageId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryDragDrop_GetSourceStorageId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryDragDrop_GetSourceStorageId_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryDragDrop_GetSourceStorageId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryDragDrop, nullptr, "GetSourceStorageId", Z_Construct_UFunction_UEchoesInventoryDragDrop_GetSourceStorageId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryDragDrop_GetSourceStorageId_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryDragDrop_GetSourceStorageId_Statics::EchoesInventoryDragDrop_eventGetSourceStorageId_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryDragDrop_GetSourceStorageId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryDragDrop_GetSourceStorageId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryDragDrop_GetSourceStorageId_Statics::EchoesInventoryDragDrop_eventGetSourceStorageId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryDragDrop_GetSourceStorageId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryDragDrop_GetSourceStorageId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryDragDrop::execGetSourceStorageId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGuid*)Z_Param__Result=P_THIS->GetSourceStorageId();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryDragDrop Function GetSourceStorageId ***********************

// ********** Begin Class UEchoesInventoryDragDrop Function InitializeDragOperation ****************
struct Z_Construct_UFunction_UEchoesInventoryDragDrop_InitializeDragOperation_Statics
{
	struct EchoesInventoryDragDrop_eventInitializeDragOperation_Parms
	{
		FEchoesInventoryItem InItemData;
		FGuid InSourceStorageId;
		AActor* InSourceActor;
		int64 InQuantity;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|DragDrop" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Initialize the drag operation with item data\n\x09 * @param InItemData - The item being dragged\n\x09 * @param InSourceStorageId - Storage ID where item originates\n\x09 * @param InSourceActor - Actor containing the source inventory\n\x09 * @param InQuantity - Quantity to move (0 = all)\n\x09 */" },
#endif
		{ "CPP_Default_InQuantity", "0" },
		{ "ModuleRelativePath", "UI/EchoesInventoryDragDrop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initialize the drag operation with item data\n@param InItemData - The item being dragged\n@param InSourceStorageId - Storage ID where item originates\n@param InSourceActor - Actor containing the source inventory\n@param InQuantity - Quantity to move (0 = all)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InItemData_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InSourceStorageId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_InItemData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InSourceStorageId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InSourceActor;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_InQuantity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesInventoryDragDrop_InitializeDragOperation_Statics::NewProp_InItemData = { "InItemData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryDragDrop_eventInitializeDragOperation_Parms, InItemData), Z_Construct_UScriptStruct_FEchoesInventoryItem, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InItemData_MetaData), NewProp_InItemData_MetaData) }; // 3518727963
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesInventoryDragDrop_InitializeDragOperation_Statics::NewProp_InSourceStorageId = { "InSourceStorageId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryDragDrop_eventInitializeDragOperation_Parms, InSourceStorageId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InSourceStorageId_MetaData), NewProp_InSourceStorageId_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEchoesInventoryDragDrop_InitializeDragOperation_Statics::NewProp_InSourceActor = { "InSourceActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryDragDrop_eventInitializeDragOperation_Parms, InSourceActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UEchoesInventoryDragDrop_InitializeDragOperation_Statics::NewProp_InQuantity = { "InQuantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryDragDrop_eventInitializeDragOperation_Parms, InQuantity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryDragDrop_InitializeDragOperation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryDragDrop_InitializeDragOperation_Statics::NewProp_InItemData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryDragDrop_InitializeDragOperation_Statics::NewProp_InSourceStorageId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryDragDrop_InitializeDragOperation_Statics::NewProp_InSourceActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryDragDrop_InitializeDragOperation_Statics::NewProp_InQuantity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryDragDrop_InitializeDragOperation_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryDragDrop_InitializeDragOperation_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryDragDrop, nullptr, "InitializeDragOperation", Z_Construct_UFunction_UEchoesInventoryDragDrop_InitializeDragOperation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryDragDrop_InitializeDragOperation_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryDragDrop_InitializeDragOperation_Statics::EchoesInventoryDragDrop_eventInitializeDragOperation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryDragDrop_InitializeDragOperation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryDragDrop_InitializeDragOperation_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryDragDrop_InitializeDragOperation_Statics::EchoesInventoryDragDrop_eventInitializeDragOperation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryDragDrop_InitializeDragOperation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryDragDrop_InitializeDragOperation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryDragDrop::execInitializeDragOperation)
{
	P_GET_STRUCT_REF(FEchoesInventoryItem,Z_Param_Out_InItemData);
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_InSourceStorageId);
	P_GET_OBJECT(AActor,Z_Param_InSourceActor);
	P_GET_PROPERTY(FInt64Property,Z_Param_InQuantity);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeDragOperation(Z_Param_Out_InItemData,Z_Param_Out_InSourceStorageId,Z_Param_InSourceActor,Z_Param_InQuantity);
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryDragDrop Function InitializeDragOperation ******************

// ********** Begin Class UEchoesInventoryDragDrop Function IsPartialStack *************************
struct Z_Construct_UFunction_UEchoesInventoryDragDrop_IsPartialStack_Statics
{
	struct EchoesInventoryDragDrop_eventIsPartialStack_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|DragDrop" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if this is a partial stack move\n\x09 * @return True if quantity is less than total item quantity\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryDragDrop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if this is a partial stack move\n@return True if quantity is less than total item quantity" },
#endif
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_UEchoesInventoryDragDrop_IsPartialStack_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesInventoryDragDrop_eventIsPartialStack_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEchoesInventoryDragDrop_IsPartialStack_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesInventoryDragDrop_eventIsPartialStack_Parms), &Z_Construct_UFunction_UEchoesInventoryDragDrop_IsPartialStack_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryDragDrop_IsPartialStack_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryDragDrop_IsPartialStack_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryDragDrop_IsPartialStack_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryDragDrop_IsPartialStack_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryDragDrop, nullptr, "IsPartialStack", Z_Construct_UFunction_UEchoesInventoryDragDrop_IsPartialStack_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryDragDrop_IsPartialStack_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryDragDrop_IsPartialStack_Statics::EchoesInventoryDragDrop_eventIsPartialStack_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryDragDrop_IsPartialStack_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryDragDrop_IsPartialStack_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryDragDrop_IsPartialStack_Statics::EchoesInventoryDragDrop_eventIsPartialStack_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryDragDrop_IsPartialStack()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryDragDrop_IsPartialStack_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryDragDrop::execIsPartialStack)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsPartialStack();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryDragDrop Function IsPartialStack ***************************

// ********** Begin Class UEchoesInventoryDragDrop Function SetQuantity ****************************
struct Z_Construct_UFunction_UEchoesInventoryDragDrop_SetQuantity_Statics
{
	struct EchoesInventoryDragDrop_eventSetQuantity_Parms
	{
		int64 InQuantity;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|DragDrop" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Set the quantity being moved (for stack splitting)\n\x09 * @param InQuantity - New quantity to move\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryDragDrop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set the quantity being moved (for stack splitting)\n@param InQuantity - New quantity to move" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FInt64PropertyParams NewProp_InQuantity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UEchoesInventoryDragDrop_SetQuantity_Statics::NewProp_InQuantity = { "InQuantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryDragDrop_eventSetQuantity_Parms, InQuantity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryDragDrop_SetQuantity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryDragDrop_SetQuantity_Statics::NewProp_InQuantity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryDragDrop_SetQuantity_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryDragDrop_SetQuantity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryDragDrop, nullptr, "SetQuantity", Z_Construct_UFunction_UEchoesInventoryDragDrop_SetQuantity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryDragDrop_SetQuantity_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryDragDrop_SetQuantity_Statics::EchoesInventoryDragDrop_eventSetQuantity_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryDragDrop_SetQuantity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryDragDrop_SetQuantity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryDragDrop_SetQuantity_Statics::EchoesInventoryDragDrop_eventSetQuantity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryDragDrop_SetQuantity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryDragDrop_SetQuantity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryDragDrop::execSetQuantity)
{
	P_GET_PROPERTY(FInt64Property,Z_Param_InQuantity);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetQuantity(Z_Param_InQuantity);
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryDragDrop Function SetQuantity ******************************

// ********** Begin Class UEchoesInventoryDragDrop *************************************************
void UEchoesInventoryDragDrop::StaticRegisterNativesUEchoesInventoryDragDrop()
{
	UClass* Class = UEchoesInventoryDragDrop::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetItemData", &UEchoesInventoryDragDrop::execGetItemData },
		{ "GetQuantity", &UEchoesInventoryDragDrop::execGetQuantity },
		{ "GetSourceActor", &UEchoesInventoryDragDrop::execGetSourceActor },
		{ "GetSourceStorageId", &UEchoesInventoryDragDrop::execGetSourceStorageId },
		{ "InitializeDragOperation", &UEchoesInventoryDragDrop::execInitializeDragOperation },
		{ "IsPartialStack", &UEchoesInventoryDragDrop::execIsPartialStack },
		{ "SetQuantity", &UEchoesInventoryDragDrop::execSetQuantity },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesInventoryDragDrop;
UClass* UEchoesInventoryDragDrop::GetPrivateStaticClass()
{
	using TClass = UEchoesInventoryDragDrop;
	if (!Z_Registration_Info_UClass_UEchoesInventoryDragDrop.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesInventoryDragDrop"),
			Z_Registration_Info_UClass_UEchoesInventoryDragDrop.InnerSingleton,
			StaticRegisterNativesUEchoesInventoryDragDrop,
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
	return Z_Registration_Info_UClass_UEchoesInventoryDragDrop.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesInventoryDragDrop_NoRegister()
{
	return UEchoesInventoryDragDrop::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesInventoryDragDrop_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UEchoesInventoryDragDrop\n * \n * Drag and drop operation for inventory items\n * Carries item data and source storage information\n * Provides visual feedback during drag\n * \n * Features:\n * - Holds inventory item data\n * - Tracks source storage ID\n * - Supports partial quantity for stack splitting\n * - Visual feedback with item icon\n * \n * Usage:\n * - Create when drag starts in inventory entry widget\n * - Set item data and source storage\n * - Set quantity (defaults to full stack)\n * - Receive in drop target (inventory widget)\n */" },
#endif
		{ "IncludePath", "UI/EchoesInventoryDragDrop.h" },
		{ "ModuleRelativePath", "UI/EchoesInventoryDragDrop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UEchoesInventoryDragDrop\n\nDrag and drop operation for inventory items\nCarries item data and source storage information\nProvides visual feedback during drag\n\nFeatures:\n- Holds inventory item data\n- Tracks source storage ID\n- Supports partial quantity for stack splitting\n- Visual feedback with item icon\n\nUsage:\n- Create when drag starts in inventory entry widget\n- Set item data and source storage\n- Set quantity (defaults to full stack)\n- Receive in drop target (inventory widget)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemData_MetaData[] = {
		{ "Category", "Echoes|Inventory|DragDrop" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The inventory item being dragged */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryDragDrop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The inventory item being dragged" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceStorageId_MetaData[] = {
		{ "Category", "Echoes|Inventory|DragDrop" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Storage ID where the item originates */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryDragDrop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Storage ID where the item originates" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceActor_MetaData[] = {
		{ "Category", "Echoes|Inventory|DragDrop" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Actor containing the source inventory component */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryDragDrop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Actor containing the source inventory component" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Quantity_MetaData[] = {
		{ "Category", "Echoes|Inventory|DragDrop" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Quantity being moved (0 = all) */" },
#endif
		{ "ModuleRelativePath", "UI/EchoesInventoryDragDrop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Quantity being moved (0 = all)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ItemData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SourceStorageId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SourceActor;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesInventoryDragDrop_GetItemData, "GetItemData" }, // 1197970389
		{ &Z_Construct_UFunction_UEchoesInventoryDragDrop_GetQuantity, "GetQuantity" }, // 2907746207
		{ &Z_Construct_UFunction_UEchoesInventoryDragDrop_GetSourceActor, "GetSourceActor" }, // 2872217117
		{ &Z_Construct_UFunction_UEchoesInventoryDragDrop_GetSourceStorageId, "GetSourceStorageId" }, // 3820372156
		{ &Z_Construct_UFunction_UEchoesInventoryDragDrop_InitializeDragOperation, "InitializeDragOperation" }, // 2695983061
		{ &Z_Construct_UFunction_UEchoesInventoryDragDrop_IsPartialStack, "IsPartialStack" }, // 2139831679
		{ &Z_Construct_UFunction_UEchoesInventoryDragDrop_SetQuantity, "SetQuantity" }, // 2041223007
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesInventoryDragDrop>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesInventoryDragDrop_Statics::NewProp_ItemData = { "ItemData", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesInventoryDragDrop, ItemData), Z_Construct_UScriptStruct_FEchoesInventoryItem, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemData_MetaData), NewProp_ItemData_MetaData) }; // 3518727963
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesInventoryDragDrop_Statics::NewProp_SourceStorageId = { "SourceStorageId", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesInventoryDragDrop, SourceStorageId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceStorageId_MetaData), NewProp_SourceStorageId_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UEchoesInventoryDragDrop_Statics::NewProp_SourceActor = { "SourceActor", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesInventoryDragDrop, SourceActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceActor_MetaData), NewProp_SourceActor_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UClass_UEchoesInventoryDragDrop_Statics::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesInventoryDragDrop, Quantity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Quantity_MetaData), NewProp_Quantity_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesInventoryDragDrop_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventoryDragDrop_Statics::NewProp_ItemData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventoryDragDrop_Statics::NewProp_SourceStorageId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventoryDragDrop_Statics::NewProp_SourceActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventoryDragDrop_Statics::NewProp_Quantity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesInventoryDragDrop_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesInventoryDragDrop_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDragDropOperation,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesInventoryDragDrop_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesInventoryDragDrop_Statics::ClassParams = {
	&UEchoesInventoryDragDrop::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UEchoesInventoryDragDrop_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesInventoryDragDrop_Statics::PropPointers),
	0,
	0x009000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesInventoryDragDrop_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesInventoryDragDrop_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesInventoryDragDrop()
{
	if (!Z_Registration_Info_UClass_UEchoesInventoryDragDrop.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesInventoryDragDrop.OuterSingleton, Z_Construct_UClass_UEchoesInventoryDragDrop_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesInventoryDragDrop.OuterSingleton;
}
UEchoesInventoryDragDrop::UEchoesInventoryDragDrop(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesInventoryDragDrop);
UEchoesInventoryDragDrop::~UEchoesInventoryDragDrop() {}
// ********** End Class UEchoesInventoryDragDrop ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryDragDrop_h__Script_Echoes_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesInventoryDragDrop, UEchoesInventoryDragDrop::StaticClass, TEXT("UEchoesInventoryDragDrop"), &Z_Registration_Info_UClass_UEchoesInventoryDragDrop, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesInventoryDragDrop), 1447291682U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryDragDrop_h__Script_Echoes_1718921984(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryDragDrop_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_EchoesInventoryDragDrop_h__Script_Echoes_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
