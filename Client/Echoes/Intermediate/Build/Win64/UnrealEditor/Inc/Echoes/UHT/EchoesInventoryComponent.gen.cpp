// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Core/Common/EchoesInventoryComponent.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeEchoesInventoryComponent() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
ECHOES_API UClass* Z_Construct_UClass_UEchoesInventoryComponent();
ECHOES_API UClass* Z_Construct_UClass_UEchoesInventoryComponent_NoRegister();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnInventoryOperationFailure__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnInventoryUpdated__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnItemMoveSuccess__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnItemsFetched__DelegateSignature();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FEchoesContainerItems();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FEchoesInventoryItem();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FEchoesInventoryItem **********************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FEchoesInventoryItem;
class UScriptStruct* FEchoesInventoryItem::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FEchoesInventoryItem.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FEchoesInventoryItem.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FEchoesInventoryItem, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("EchoesInventoryItem"));
	}
	return Z_Registration_Info_UScriptStruct_FEchoesInventoryItem.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FEchoesInventoryItem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Inventory item structure for component-level storage\n * Mirrors backend Asset entity\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Inventory item structure for component-level storage\nMirrors backend Asset entity" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AssetId_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TypeId_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TypeName_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Quantity_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Volume_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalVolume_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IsStackable_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_AssetId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TypeId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TypeName;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Volume;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TotalVolume;
	static void NewProp_IsStackable_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_IsStackable;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FEchoesInventoryItem>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FEchoesInventoryItem_Statics::NewProp_AssetId = { "AssetId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesInventoryItem, AssetId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AssetId_MetaData), NewProp_AssetId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FEchoesInventoryItem_Statics::NewProp_TypeId = { "TypeId", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesInventoryItem, TypeId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TypeId_MetaData), NewProp_TypeId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FEchoesInventoryItem_Statics::NewProp_TypeName = { "TypeName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesInventoryItem, TypeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TypeName_MetaData), NewProp_TypeName_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FEchoesInventoryItem_Statics::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesInventoryItem, Quantity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Quantity_MetaData), NewProp_Quantity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEchoesInventoryItem_Statics::NewProp_Volume = { "Volume", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesInventoryItem, Volume), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Volume_MetaData), NewProp_Volume_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEchoesInventoryItem_Statics::NewProp_TotalVolume = { "TotalVolume", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesInventoryItem, TotalVolume), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalVolume_MetaData), NewProp_TotalVolume_MetaData) };
void Z_Construct_UScriptStruct_FEchoesInventoryItem_Statics::NewProp_IsStackable_SetBit(void* Obj)
{
	((FEchoesInventoryItem*)Obj)->IsStackable = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FEchoesInventoryItem_Statics::NewProp_IsStackable = { "IsStackable", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FEchoesInventoryItem), &Z_Construct_UScriptStruct_FEchoesInventoryItem_Statics::NewProp_IsStackable_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IsStackable_MetaData), NewProp_IsStackable_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FEchoesInventoryItem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesInventoryItem_Statics::NewProp_AssetId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesInventoryItem_Statics::NewProp_TypeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesInventoryItem_Statics::NewProp_TypeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesInventoryItem_Statics::NewProp_Quantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesInventoryItem_Statics::NewProp_Volume,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesInventoryItem_Statics::NewProp_TotalVolume,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesInventoryItem_Statics::NewProp_IsStackable,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEchoesInventoryItem_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FEchoesInventoryItem_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"EchoesInventoryItem",
	Z_Construct_UScriptStruct_FEchoesInventoryItem_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEchoesInventoryItem_Statics::PropPointers),
	sizeof(FEchoesInventoryItem),
	alignof(FEchoesInventoryItem),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEchoesInventoryItem_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FEchoesInventoryItem_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FEchoesInventoryItem()
{
	if (!Z_Registration_Info_UScriptStruct_FEchoesInventoryItem.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FEchoesInventoryItem.InnerSingleton, Z_Construct_UScriptStruct_FEchoesInventoryItem_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FEchoesInventoryItem.InnerSingleton;
}
// ********** End ScriptStruct FEchoesInventoryItem ************************************************

// ********** Begin ScriptStruct FEchoesContainerItems *********************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FEchoesContainerItems;
class UScriptStruct* FEchoesContainerItems::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FEchoesContainerItems.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FEchoesContainerItems.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FEchoesContainerItems, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("EchoesContainerItems"));
	}
	return Z_Registration_Info_UScriptStruct_FEchoesContainerItems.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FEchoesContainerItems_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Container items response structure\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Container items response structure" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Items_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalCount_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalVolume_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Items_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Items;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TotalCount;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TotalVolume;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FEchoesContainerItems>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FEchoesContainerItems_Statics::NewProp_Items_Inner = { "Items", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FEchoesInventoryItem, METADATA_PARAMS(0, nullptr) }; // 3518727963
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FEchoesContainerItems_Statics::NewProp_Items = { "Items", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesContainerItems, Items), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Items_MetaData), NewProp_Items_MetaData) }; // 3518727963
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FEchoesContainerItems_Statics::NewProp_TotalCount = { "TotalCount", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesContainerItems, TotalCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalCount_MetaData), NewProp_TotalCount_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FEchoesContainerItems_Statics::NewProp_TotalVolume = { "TotalVolume", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FEchoesContainerItems, TotalVolume), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalVolume_MetaData), NewProp_TotalVolume_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FEchoesContainerItems_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesContainerItems_Statics::NewProp_Items_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesContainerItems_Statics::NewProp_Items,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesContainerItems_Statics::NewProp_TotalCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FEchoesContainerItems_Statics::NewProp_TotalVolume,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEchoesContainerItems_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FEchoesContainerItems_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"EchoesContainerItems",
	Z_Construct_UScriptStruct_FEchoesContainerItems_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEchoesContainerItems_Statics::PropPointers),
	sizeof(FEchoesContainerItems),
	alignof(FEchoesContainerItems),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FEchoesContainerItems_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FEchoesContainerItems_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FEchoesContainerItems()
{
	if (!Z_Registration_Info_UScriptStruct_FEchoesContainerItems.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FEchoesContainerItems.InnerSingleton, Z_Construct_UScriptStruct_FEchoesContainerItems_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FEchoesContainerItems.InnerSingleton;
}
// ********** End ScriptStruct FEchoesContainerItems ***********************************************

// ********** Begin Delegate FOnItemsFetched *******************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnItemsFetched__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnItemsFetched_Parms
	{
		FEchoesContainerItems Items;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Delegates for inventory operations\n" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegates for inventory operations" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Items_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Items;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Echoes_OnItemsFetched__DelegateSignature_Statics::NewProp_Items = { "Items", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnItemsFetched_Parms, Items), Z_Construct_UScriptStruct_FEchoesContainerItems, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Items_MetaData), NewProp_Items_MetaData) }; // 255446170
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnItemsFetched__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnItemsFetched__DelegateSignature_Statics::NewProp_Items,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnItemsFetched__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnItemsFetched__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnItemsFetched__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnItemsFetched__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnItemsFetched__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnItemsFetched__DelegateSignature_Statics::_Script_Echoes_eventOnItemsFetched_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00520000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnItemsFetched__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnItemsFetched__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnItemsFetched__DelegateSignature_Statics::_Script_Echoes_eventOnItemsFetched_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnItemsFetched__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnItemsFetched__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnItemsFetched_DelegateWrapper(const FScriptDelegate& OnItemsFetched, FEchoesContainerItems const& Items)
{
	struct _Script_Echoes_eventOnItemsFetched_Parms
	{
		FEchoesContainerItems Items;
	};
	_Script_Echoes_eventOnItemsFetched_Parms Parms;
	Parms.Items=Items;
	OnItemsFetched.ProcessDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnItemsFetched *********************************************************

// ********** Begin Delegate FOnItemMoveSuccess ****************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnItemMoveSuccess__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnItemMoveSuccess__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnItemMoveSuccess__DelegateSignature", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnItemMoveSuccess__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnItemMoveSuccess__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_Echoes_OnItemMoveSuccess__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnItemMoveSuccess__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnItemMoveSuccess_DelegateWrapper(const FScriptDelegate& OnItemMoveSuccess)
{
	OnItemMoveSuccess.ProcessDelegate<UObject>(NULL);
}
// ********** End Delegate FOnItemMoveSuccess ******************************************************

// ********** Begin Delegate FOnInventoryOperationFailure ******************************************
struct Z_Construct_UDelegateFunction_Echoes_OnInventoryOperationFailure__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnInventoryOperationFailure_Parms
	{
		FString ErrorMessage;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_Echoes_OnInventoryOperationFailure__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnInventoryOperationFailure_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorMessage_MetaData), NewProp_ErrorMessage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnInventoryOperationFailure__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnInventoryOperationFailure__DelegateSignature_Statics::NewProp_ErrorMessage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnInventoryOperationFailure__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnInventoryOperationFailure__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnInventoryOperationFailure__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnInventoryOperationFailure__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnInventoryOperationFailure__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnInventoryOperationFailure__DelegateSignature_Statics::_Script_Echoes_eventOnInventoryOperationFailure_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnInventoryOperationFailure__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnInventoryOperationFailure__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnInventoryOperationFailure__DelegateSignature_Statics::_Script_Echoes_eventOnInventoryOperationFailure_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnInventoryOperationFailure__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnInventoryOperationFailure__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnInventoryOperationFailure_DelegateWrapper(const FScriptDelegate& OnInventoryOperationFailure, const FString& ErrorMessage)
{
	struct _Script_Echoes_eventOnInventoryOperationFailure_Parms
	{
		FString ErrorMessage;
	};
	_Script_Echoes_eventOnInventoryOperationFailure_Parms Parms;
	Parms.ErrorMessage=ErrorMessage;
	OnInventoryOperationFailure.ProcessDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnInventoryOperationFailure ********************************************

// ********** Begin Delegate FOnInventoryUpdated ***************************************************
struct Z_Construct_UDelegateFunction_Echoes_OnInventoryUpdated__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnInventoryUpdated_Parms
	{
		FEchoesContainerItems Items;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Multicast delegate for UI updates\n" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Multicast delegate for UI updates" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Items_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Items;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Echoes_OnInventoryUpdated__DelegateSignature_Statics::NewProp_Items = { "Items", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnInventoryUpdated_Parms, Items), Z_Construct_UScriptStruct_FEchoesContainerItems, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Items_MetaData), NewProp_Items_MetaData) }; // 255446170
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnInventoryUpdated__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnInventoryUpdated__DelegateSignature_Statics::NewProp_Items,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnInventoryUpdated__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnInventoryUpdated__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnInventoryUpdated__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnInventoryUpdated__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnInventoryUpdated__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnInventoryUpdated__DelegateSignature_Statics::_Script_Echoes_eventOnInventoryUpdated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnInventoryUpdated__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnInventoryUpdated__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnInventoryUpdated__DelegateSignature_Statics::_Script_Echoes_eventOnInventoryUpdated_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnInventoryUpdated__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnInventoryUpdated__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnInventoryUpdated_DelegateWrapper(const FMulticastScriptDelegate& OnInventoryUpdated, FEchoesContainerItems const& Items)
{
	struct _Script_Echoes_eventOnInventoryUpdated_Parms
	{
		FEchoesContainerItems Items;
	};
	_Script_Echoes_eventOnInventoryUpdated_Parms Parms;
	Parms.Items=Items;
	OnInventoryUpdated.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnInventoryUpdated *****************************************************

// ********** Begin Class UEchoesInventoryComponent Function CanFitItem ****************************
struct Z_Construct_UFunction_UEchoesInventoryComponent_CanFitItem_Statics
{
	struct EchoesInventoryComponent_eventCanFitItem_Parms
	{
		float ItemVolume;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Check if item can fit in this container\n\x09 * \n\x09 * @param ItemVolume - Volume of item to check\n\x09 * @return True if item can fit\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if item can fit in this container\n\n@param ItemVolume - Volume of item to check\n@return True if item can fit" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ItemVolume;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesInventoryComponent_CanFitItem_Statics::NewProp_ItemVolume = { "ItemVolume", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryComponent_eventCanFitItem_Parms, ItemVolume), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UEchoesInventoryComponent_CanFitItem_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((EchoesInventoryComponent_eventCanFitItem_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UEchoesInventoryComponent_CanFitItem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(EchoesInventoryComponent_eventCanFitItem_Parms), &Z_Construct_UFunction_UEchoesInventoryComponent_CanFitItem_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryComponent_CanFitItem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryComponent_CanFitItem_Statics::NewProp_ItemVolume,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryComponent_CanFitItem_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryComponent_CanFitItem_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryComponent_CanFitItem_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryComponent, nullptr, "CanFitItem", Z_Construct_UFunction_UEchoesInventoryComponent_CanFitItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryComponent_CanFitItem_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryComponent_CanFitItem_Statics::EchoesInventoryComponent_eventCanFitItem_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryComponent_CanFitItem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryComponent_CanFitItem_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryComponent_CanFitItem_Statics::EchoesInventoryComponent_eventCanFitItem_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryComponent_CanFitItem()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryComponent_CanFitItem_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryComponent::execCanFitItem)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_ItemVolume);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CanFitItem(Z_Param_ItemVolume);
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryComponent Function CanFitItem ******************************

// ********** Begin Class UEchoesInventoryComponent Function FetchItems ****************************
struct Z_Construct_UFunction_UEchoesInventoryComponent_FetchItems_Statics
{
	struct EchoesInventoryComponent_eventFetchItems_Parms
	{
		FScriptDelegate OnSuccess;
		FScriptDelegate OnFailure;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Fetch all items in this container from backend\n\x09 * Queries UEchoesInventorySubsystem which calls GET /api/inventory/container/{id}\n\x09 * \n\x09 * @param OnSuccess - Callback with items list\n\x09 * @param OnFailure - Callback on failure\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fetch all items in this container from backend\nQueries UEchoesInventorySubsystem which calls GET /api/inventory/container/{id}\n\n@param OnSuccess - Callback with items list\n@param OnFailure - Callback on failure" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnSuccess;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnFailure;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesInventoryComponent_FetchItems_Statics::NewProp_OnSuccess = { "OnSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryComponent_eventFetchItems_Parms, OnSuccess), Z_Construct_UDelegateFunction_Echoes_OnItemsFetched__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 2705153072
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesInventoryComponent_FetchItems_Statics::NewProp_OnFailure = { "OnFailure", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryComponent_eventFetchItems_Parms, OnFailure), Z_Construct_UDelegateFunction_Echoes_OnInventoryOperationFailure__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 3329763266
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryComponent_FetchItems_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryComponent_FetchItems_Statics::NewProp_OnSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryComponent_FetchItems_Statics::NewProp_OnFailure,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryComponent_FetchItems_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryComponent_FetchItems_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryComponent, nullptr, "FetchItems", Z_Construct_UFunction_UEchoesInventoryComponent_FetchItems_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryComponent_FetchItems_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryComponent_FetchItems_Statics::EchoesInventoryComponent_eventFetchItems_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryComponent_FetchItems_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryComponent_FetchItems_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryComponent_FetchItems_Statics::EchoesInventoryComponent_eventFetchItems_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryComponent_FetchItems()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryComponent_FetchItems_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryComponent::execFetchItems)
{
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnSuccess);
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnFailure);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->FetchItems(FOnItemsFetched(Z_Param_OnSuccess),FOnInventoryOperationFailure(Z_Param_OnFailure));
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryComponent Function FetchItems ******************************

// ********** Begin Class UEchoesInventoryComponent Function GetAvailableVolume ********************
struct Z_Construct_UFunction_UEchoesInventoryComponent_GetAvailableVolume_Statics
{
	struct EchoesInventoryComponent_eventGetAvailableVolume_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get available volume in this container\n\x09 * \n\x09 * @return Available volume in cubic meters\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get available volume in this container\n\n@return Available volume in cubic meters" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesInventoryComponent_GetAvailableVolume_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryComponent_eventGetAvailableVolume_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryComponent_GetAvailableVolume_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryComponent_GetAvailableVolume_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryComponent_GetAvailableVolume_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryComponent_GetAvailableVolume_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryComponent, nullptr, "GetAvailableVolume", Z_Construct_UFunction_UEchoesInventoryComponent_GetAvailableVolume_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryComponent_GetAvailableVolume_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryComponent_GetAvailableVolume_Statics::EchoesInventoryComponent_eventGetAvailableVolume_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryComponent_GetAvailableVolume_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryComponent_GetAvailableVolume_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryComponent_GetAvailableVolume_Statics::EchoesInventoryComponent_eventGetAvailableVolume_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryComponent_GetAvailableVolume()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryComponent_GetAvailableVolume_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryComponent::execGetAvailableVolume)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetAvailableVolume();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryComponent Function GetAvailableVolume **********************

// ********** Begin Class UEchoesInventoryComponent Function GetCachedItems ************************
struct Z_Construct_UFunction_UEchoesInventoryComponent_GetCachedItems_Statics
{
	struct EchoesInventoryComponent_eventGetCachedItems_Parms
	{
		FEchoesContainerItems ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get cached items (last fetched from server)\n\x09 * \n\x09 * @return Cached container items\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get cached items (last fetched from server)\n\n@return Cached container items" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesInventoryComponent_GetCachedItems_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryComponent_eventGetCachedItems_Parms, ReturnValue), Z_Construct_UScriptStruct_FEchoesContainerItems, METADATA_PARAMS(0, nullptr) }; // 255446170
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryComponent_GetCachedItems_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryComponent_GetCachedItems_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryComponent_GetCachedItems_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryComponent_GetCachedItems_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryComponent, nullptr, "GetCachedItems", Z_Construct_UFunction_UEchoesInventoryComponent_GetCachedItems_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryComponent_GetCachedItems_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryComponent_GetCachedItems_Statics::EchoesInventoryComponent_eventGetCachedItems_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryComponent_GetCachedItems_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryComponent_GetCachedItems_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryComponent_GetCachedItems_Statics::EchoesInventoryComponent_eventGetCachedItems_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryComponent_GetCachedItems()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryComponent_GetCachedItems_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryComponent::execGetCachedItems)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FEchoesContainerItems*)Z_Param__Result=P_THIS->GetCachedItems();
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryComponent Function GetCachedItems **************************

// ********** Begin Class UEchoesInventoryComponent Function HandleMoveRefreshFailure **************
struct Z_Construct_UFunction_UEchoesInventoryComponent_HandleMoveRefreshFailure_Statics
{
	struct EchoesInventoryComponent_eventHandleMoveRefreshFailure_Parms
	{
		FString Error;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Error_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_Error;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UEchoesInventoryComponent_HandleMoveRefreshFailure_Statics::NewProp_Error = { "Error", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryComponent_eventHandleMoveRefreshFailure_Parms, Error), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Error_MetaData), NewProp_Error_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryComponent_HandleMoveRefreshFailure_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryComponent_HandleMoveRefreshFailure_Statics::NewProp_Error,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryComponent_HandleMoveRefreshFailure_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryComponent_HandleMoveRefreshFailure_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryComponent, nullptr, "HandleMoveRefreshFailure", Z_Construct_UFunction_UEchoesInventoryComponent_HandleMoveRefreshFailure_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryComponent_HandleMoveRefreshFailure_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryComponent_HandleMoveRefreshFailure_Statics::EchoesInventoryComponent_eventHandleMoveRefreshFailure_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryComponent_HandleMoveRefreshFailure_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryComponent_HandleMoveRefreshFailure_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryComponent_HandleMoveRefreshFailure_Statics::EchoesInventoryComponent_eventHandleMoveRefreshFailure_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryComponent_HandleMoveRefreshFailure()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryComponent_HandleMoveRefreshFailure_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryComponent::execHandleMoveRefreshFailure)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Error);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleMoveRefreshFailure(Z_Param_Error);
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryComponent Function HandleMoveRefreshFailure ****************

// ********** Begin Class UEchoesInventoryComponent Function HandleMoveRefreshSuccess **************
struct Z_Construct_UFunction_UEchoesInventoryComponent_HandleMoveRefreshSuccess_Statics
{
	struct EchoesInventoryComponent_eventHandleMoveRefreshSuccess_Parms
	{
		FEchoesContainerItems Items;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Items_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Items;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesInventoryComponent_HandleMoveRefreshSuccess_Statics::NewProp_Items = { "Items", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryComponent_eventHandleMoveRefreshSuccess_Parms, Items), Z_Construct_UScriptStruct_FEchoesContainerItems, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Items_MetaData), NewProp_Items_MetaData) }; // 255446170
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryComponent_HandleMoveRefreshSuccess_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryComponent_HandleMoveRefreshSuccess_Statics::NewProp_Items,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryComponent_HandleMoveRefreshSuccess_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryComponent_HandleMoveRefreshSuccess_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryComponent, nullptr, "HandleMoveRefreshSuccess", Z_Construct_UFunction_UEchoesInventoryComponent_HandleMoveRefreshSuccess_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryComponent_HandleMoveRefreshSuccess_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryComponent_HandleMoveRefreshSuccess_Statics::EchoesInventoryComponent_eventHandleMoveRefreshSuccess_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryComponent_HandleMoveRefreshSuccess_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryComponent_HandleMoveRefreshSuccess_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryComponent_HandleMoveRefreshSuccess_Statics::EchoesInventoryComponent_eventHandleMoveRefreshSuccess_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryComponent_HandleMoveRefreshSuccess()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryComponent_HandleMoveRefreshSuccess_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryComponent::execHandleMoveRefreshSuccess)
{
	P_GET_STRUCT_REF(FEchoesContainerItems,Z_Param_Out_Items);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleMoveRefreshSuccess(Z_Param_Out_Items);
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryComponent Function HandleMoveRefreshSuccess ****************

// ********** Begin Class UEchoesInventoryComponent Function InitializeStorage *********************
struct Z_Construct_UFunction_UEchoesInventoryComponent_InitializeStorage_Statics
{
	struct EchoesInventoryComponent_eventInitializeStorage_Parms
	{
		FGuid InStorageId;
		float InCapacity;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|Initialization" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Initialize component with storage ID from database\n\x09 * Called when spawning ships or stations\n\x09 * \n\x09 * @param InStorageId - Storage ID from database\n\x09 * @param InCapacity - Storage capacity (0 = unlimited)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initialize component with storage ID from database\nCalled when spawning ships or stations\n\n@param InStorageId - Storage ID from database\n@param InCapacity - Storage capacity (0 = unlimited)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InStorageId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_InStorageId;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InCapacity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesInventoryComponent_InitializeStorage_Statics::NewProp_InStorageId = { "InStorageId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryComponent_eventInitializeStorage_Parms, InStorageId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InStorageId_MetaData), NewProp_InStorageId_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UEchoesInventoryComponent_InitializeStorage_Statics::NewProp_InCapacity = { "InCapacity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryComponent_eventInitializeStorage_Parms, InCapacity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryComponent_InitializeStorage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryComponent_InitializeStorage_Statics::NewProp_InStorageId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryComponent_InitializeStorage_Statics::NewProp_InCapacity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryComponent_InitializeStorage_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryComponent_InitializeStorage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryComponent, nullptr, "InitializeStorage", Z_Construct_UFunction_UEchoesInventoryComponent_InitializeStorage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryComponent_InitializeStorage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryComponent_InitializeStorage_Statics::EchoesInventoryComponent_eventInitializeStorage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryComponent_InitializeStorage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryComponent_InitializeStorage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryComponent_InitializeStorage_Statics::EchoesInventoryComponent_eventInitializeStorage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryComponent_InitializeStorage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryComponent_InitializeStorage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryComponent::execInitializeStorage)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_InStorageId);
	P_GET_PROPERTY(FFloatProperty,Z_Param_InCapacity);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeStorage(Z_Param_Out_InStorageId,Z_Param_InCapacity);
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryComponent Function InitializeStorage ***********************

// ********** Begin Class UEchoesInventoryComponent Function ServerOnly_JettisonItem ***************
struct Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_JettisonItem_Statics
{
	struct EchoesInventoryComponent_eventServerOnly_JettisonItem_Parms
	{
		FGuid AssetId;
		int64 Quantity;
		FScriptDelegate OnSuccess;
		FScriptDelegate OnFailure;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * SERVER ONLY: Jettison (drop) item from inventory\n\x09 * Removes item from inventory and spawns AEchoesItemActor in space\n\x09 * \n\x09 * @param AssetId - ID of asset to jettison\n\x09 * @param Quantity - Quantity to jettison (0 = all)\n\x09 * @param OnSuccess - Callback on successful jettison\n\x09 * @param OnFailure - Callback on jettison failure\n\x09 */" },
#endif
		{ "DisplayName", "ServerOnly JettisonItem" },
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "SERVER ONLY: Jettison (drop) item from inventory\nRemoves item from inventory and spawns AEchoesItemActor in space\n\n@param AssetId - ID of asset to jettison\n@param Quantity - Quantity to jettison (0 = all)\n@param OnSuccess - Callback on successful jettison\n@param OnFailure - Callback on jettison failure" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AssetId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_AssetId;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnSuccess;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnFailure;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_JettisonItem_Statics::NewProp_AssetId = { "AssetId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryComponent_eventServerOnly_JettisonItem_Parms, AssetId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AssetId_MetaData), NewProp_AssetId_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_JettisonItem_Statics::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryComponent_eventServerOnly_JettisonItem_Parms, Quantity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_JettisonItem_Statics::NewProp_OnSuccess = { "OnSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryComponent_eventServerOnly_JettisonItem_Parms, OnSuccess), Z_Construct_UDelegateFunction_Echoes_OnItemMoveSuccess__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 2353592895
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_JettisonItem_Statics::NewProp_OnFailure = { "OnFailure", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryComponent_eventServerOnly_JettisonItem_Parms, OnFailure), Z_Construct_UDelegateFunction_Echoes_OnInventoryOperationFailure__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 3329763266
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_JettisonItem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_JettisonItem_Statics::NewProp_AssetId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_JettisonItem_Statics::NewProp_Quantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_JettisonItem_Statics::NewProp_OnSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_JettisonItem_Statics::NewProp_OnFailure,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_JettisonItem_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_JettisonItem_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryComponent, nullptr, "ServerOnly_JettisonItem", Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_JettisonItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_JettisonItem_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_JettisonItem_Statics::EchoesInventoryComponent_eventServerOnly_JettisonItem_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_JettisonItem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_JettisonItem_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_JettisonItem_Statics::EchoesInventoryComponent_eventServerOnly_JettisonItem_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_JettisonItem()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_JettisonItem_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryComponent::execServerOnly_JettisonItem)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_AssetId);
	P_GET_PROPERTY(FInt64Property,Z_Param_Quantity);
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnSuccess);
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnFailure);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_JettisonItem(Z_Param_Out_AssetId,Z_Param_Quantity,FOnItemMoveSuccess(Z_Param_OnSuccess),FOnInventoryOperationFailure(Z_Param_OnFailure));
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryComponent Function ServerOnly_JettisonItem *****************

// ********** Begin Class UEchoesInventoryComponent Function ServerOnly_MoveItem *******************
struct Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_MoveItem_Statics
{
	struct EchoesInventoryComponent_eventServerOnly_MoveItem_Parms
	{
		FGuid AssetId;
		AActor* TargetActor;
		AActor* SourceActor;
		int64 Quantity;
		FScriptDelegate OnSuccess;
		FScriptDelegate OnFailure;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * SERVER ONLY: Move item between containers with distance check\n\x09 * This should only be called on the server\n\x09 * Validates distance between source and target actors\n\x09 * Sends POST /api/inventory/move to backend\n\x09 * \n\x09 * @param AssetId - ID of asset to move\n\x09 * @param TargetActor - Target actor with inventory component\n\x09 * @param SourceActor - Source actor (for distance check)\n\x09 * @param Quantity - Optional: quantity to move (for splitting stacks)\n\x09 * @param OnSuccess - Callback on successful move\n\x09 * @param OnFailure - Callback on move failure\n\x09 */" },
#endif
		{ "DisplayName", "ServerOnly MoveItem" },
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "SERVER ONLY: Move item between containers with distance check\nThis should only be called on the server\nValidates distance between source and target actors\nSends POST /api/inventory/move to backend\n\n@param AssetId - ID of asset to move\n@param TargetActor - Target actor with inventory component\n@param SourceActor - Source actor (for distance check)\n@param Quantity - Optional: quantity to move (for splitting stacks)\n@param OnSuccess - Callback on successful move\n@param OnFailure - Callback on move failure" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AssetId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_AssetId;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SourceActor;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnSuccess;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnFailure;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_MoveItem_Statics::NewProp_AssetId = { "AssetId", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryComponent_eventServerOnly_MoveItem_Parms, AssetId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AssetId_MetaData), NewProp_AssetId_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_MoveItem_Statics::NewProp_TargetActor = { "TargetActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryComponent_eventServerOnly_MoveItem_Parms, TargetActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_MoveItem_Statics::NewProp_SourceActor = { "SourceActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryComponent_eventServerOnly_MoveItem_Parms, SourceActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_MoveItem_Statics::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryComponent_eventServerOnly_MoveItem_Parms, Quantity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_MoveItem_Statics::NewProp_OnSuccess = { "OnSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryComponent_eventServerOnly_MoveItem_Parms, OnSuccess), Z_Construct_UDelegateFunction_Echoes_OnItemMoveSuccess__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 2353592895
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_MoveItem_Statics::NewProp_OnFailure = { "OnFailure", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryComponent_eventServerOnly_MoveItem_Parms, OnFailure), Z_Construct_UDelegateFunction_Echoes_OnInventoryOperationFailure__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 3329763266
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_MoveItem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_MoveItem_Statics::NewProp_AssetId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_MoveItem_Statics::NewProp_TargetActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_MoveItem_Statics::NewProp_SourceActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_MoveItem_Statics::NewProp_Quantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_MoveItem_Statics::NewProp_OnSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_MoveItem_Statics::NewProp_OnFailure,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_MoveItem_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_MoveItem_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryComponent, nullptr, "ServerOnly_MoveItem", Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_MoveItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_MoveItem_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_MoveItem_Statics::EchoesInventoryComponent_eventServerOnly_MoveItem_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_MoveItem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_MoveItem_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_MoveItem_Statics::EchoesInventoryComponent_eventServerOnly_MoveItem_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_MoveItem()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_MoveItem_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryComponent::execServerOnly_MoveItem)
{
	P_GET_STRUCT_REF(FGuid,Z_Param_Out_AssetId);
	P_GET_OBJECT(AActor,Z_Param_TargetActor);
	P_GET_OBJECT(AActor,Z_Param_SourceActor);
	P_GET_PROPERTY(FInt64Property,Z_Param_Quantity);
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnSuccess);
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnFailure);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_MoveItem(Z_Param_Out_AssetId,Z_Param_TargetActor,Z_Param_SourceActor,Z_Param_Quantity,FOnItemMoveSuccess(Z_Param_OnSuccess),FOnInventoryOperationFailure(Z_Param_OnFailure));
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryComponent Function ServerOnly_MoveItem *********************

// ********** Begin Class UEchoesInventoryComponent Function ServerOnly_StackAll *******************
struct Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_StackAll_Statics
{
	struct EchoesInventoryComponent_eventServerOnly_StackAll_Parms
	{
		int32 TypeId;
		FScriptDelegate OnSuccess;
		FScriptDelegate OnFailure;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Echoes|Inventory|Server" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * SERVER ONLY: Stack all items of same type in this container\n\x09 * Combines all items with same TypeId into single stack\n\x09 * Sends POST /api/inventory/stack-all to backend\n\x09 * \n\x09 * @param TypeId - Type ID to stack (0 = stack all types)\n\x09 * @param OnSuccess - Callback on successful stacking\n\x09 * @param OnFailure - Callback on stacking failure\n\x09 */" },
#endif
		{ "DisplayName", "ServerOnly StackAll" },
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "SERVER ONLY: Stack all items of same type in this container\nCombines all items with same TypeId into single stack\nSends POST /api/inventory/stack-all to backend\n\n@param TypeId - Type ID to stack (0 = stack all types)\n@param OnSuccess - Callback on successful stacking\n@param OnFailure - Callback on stacking failure" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_TypeId;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnSuccess;
	static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnFailure;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_StackAll_Statics::NewProp_TypeId = { "TypeId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryComponent_eventServerOnly_StackAll_Parms, TypeId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_StackAll_Statics::NewProp_OnSuccess = { "OnSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryComponent_eventServerOnly_StackAll_Parms, OnSuccess), Z_Construct_UDelegateFunction_Echoes_OnItemMoveSuccess__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 2353592895
const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_StackAll_Statics::NewProp_OnFailure = { "OnFailure", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EchoesInventoryComponent_eventServerOnly_StackAll_Parms, OnFailure), Z_Construct_UDelegateFunction_Echoes_OnInventoryOperationFailure__DelegateSignature, METADATA_PARAMS(0, nullptr) }; // 3329763266
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_StackAll_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_StackAll_Statics::NewProp_TypeId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_StackAll_Statics::NewProp_OnSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_StackAll_Statics::NewProp_OnFailure,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_StackAll_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_StackAll_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEchoesInventoryComponent, nullptr, "ServerOnly_StackAll", Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_StackAll_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_StackAll_Statics::PropPointers), sizeof(Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_StackAll_Statics::EchoesInventoryComponent_eventServerOnly_StackAll_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_StackAll_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_StackAll_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_StackAll_Statics::EchoesInventoryComponent_eventServerOnly_StackAll_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_StackAll()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_StackAll_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UEchoesInventoryComponent::execServerOnly_StackAll)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_TypeId);
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnSuccess);
	P_GET_PROPERTY(FDelegateProperty,Z_Param_OnFailure);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ServerOnly_StackAll(Z_Param_TypeId,FOnItemMoveSuccess(Z_Param_OnSuccess),FOnInventoryOperationFailure(Z_Param_OnFailure));
	P_NATIVE_END;
}
// ********** End Class UEchoesInventoryComponent Function ServerOnly_StackAll *********************

// ********** Begin Class UEchoesInventoryComponent ************************************************
void UEchoesInventoryComponent::StaticRegisterNativesUEchoesInventoryComponent()
{
	UClass* Class = UEchoesInventoryComponent::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CanFitItem", &UEchoesInventoryComponent::execCanFitItem },
		{ "FetchItems", &UEchoesInventoryComponent::execFetchItems },
		{ "GetAvailableVolume", &UEchoesInventoryComponent::execGetAvailableVolume },
		{ "GetCachedItems", &UEchoesInventoryComponent::execGetCachedItems },
		{ "HandleMoveRefreshFailure", &UEchoesInventoryComponent::execHandleMoveRefreshFailure },
		{ "HandleMoveRefreshSuccess", &UEchoesInventoryComponent::execHandleMoveRefreshSuccess },
		{ "InitializeStorage", &UEchoesInventoryComponent::execInitializeStorage },
		{ "ServerOnly_JettisonItem", &UEchoesInventoryComponent::execServerOnly_JettisonItem },
		{ "ServerOnly_MoveItem", &UEchoesInventoryComponent::execServerOnly_MoveItem },
		{ "ServerOnly_StackAll", &UEchoesInventoryComponent::execServerOnly_StackAll },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEchoesInventoryComponent;
UClass* UEchoesInventoryComponent::GetPrivateStaticClass()
{
	using TClass = UEchoesInventoryComponent;
	if (!Z_Registration_Info_UClass_UEchoesInventoryComponent.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EchoesInventoryComponent"),
			Z_Registration_Info_UClass_UEchoesInventoryComponent.InnerSingleton,
			StaticRegisterNativesUEchoesInventoryComponent,
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
	return Z_Registration_Info_UClass_UEchoesInventoryComponent.InnerSingleton;
}
UClass* Z_Construct_UClass_UEchoesInventoryComponent_NoRegister()
{
	return UEchoesInventoryComponent::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEchoesInventoryComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Echoes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UEchoesInventoryComponent\n * \n * Actor Component for inventory management in Echoes MMO\n * Provides storage functionality for ships, stations, and containers\n * \n * Architecture:\n * - ActorComponent: Can be attached to any Actor (ship, station, container)\n * - StorageId: Links to backend Container entity (FGuid)\n * - Capacity: Maximum volume this storage can hold\n * - Communicates with UEchoesInventorySubsystem for data fetching\n * - Provides ServerOnly_ functions for server-authoritative item operations\n * \n * Usage:\n * - Attach to ship actors for cargo holds\n * - Attach to station actors for hangar storage\n * - Attach to container actors for item storage\n */" },
#endif
		{ "IncludePath", "Core/Common/EchoesInventoryComponent.h" },
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UEchoesInventoryComponent\n\nActor Component for inventory management in Echoes MMO\nProvides storage functionality for ships, stations, and containers\n\nArchitecture:\n- ActorComponent: Can be attached to any Actor (ship, station, container)\n- StorageId: Links to backend Container entity (FGuid)\n- Capacity: Maximum volume this storage can hold\n- Communicates with UEchoesInventorySubsystem for data fetching\n- Provides ServerOnly_ functions for server-authoritative item operations\n\nUsage:\n- Attach to ship actors for cargo holds\n- Attach to station actors for hangar storage\n- Attach to container actors for item storage" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StorageId_MetaData[] = {
		{ "Category", "Inventory|Storage" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Storage ID that maps to backend Container entity\n\x09 * Initialize this on spawn from database\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Storage ID that maps to backend Container entity\nInitialize this on spawn from database" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Capacity_MetaData[] = {
		{ "Category", "Inventory|Storage" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Maximum storage capacity in cubic meters (m\xc2\xb3)\n\x09 * Null/0 means unlimited capacity (e.g., station storage)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum storage capacity in cubic meters (m\xc2\xb3)\nNull/0 means unlimited capacity (e.g., station storage)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UsedVolume_MetaData[] = {
		{ "Category", "Inventory|Storage" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Current used volume in cubic meters (m\xc2\xb3)\n\x09 * Updated after successful operations\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current used volume in cubic meters (m\xc2\xb3)\nUpdated after successful operations" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxTransferDistance_MetaData[] = {
		{ "Category", "Inventory|Transfer" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Maximum distance for item transfer operations (in cm, Unreal units)\n\x09 * Default: 250000 cm = 2500 meters\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum distance for item transfer operations (in cm, Unreal units)\nDefault: 250000 cm = 2500 meters" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnInventoryUpdated_MetaData[] = {
		{ "Category", "Echoes|Inventory|Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Multicast delegate triggered when inventory is updated\n\x09 * UI widgets should bind to this for reactive updates\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Multicast delegate triggered when inventory is updated\nUI widgets should bind to this for reactive updates" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CachedItems_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Cached items list */" },
#endif
		{ "ModuleRelativePath", "Core/Common/EchoesInventoryComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Cached items list" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_StorageId;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Capacity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_UsedVolume;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxTransferDistance;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnInventoryUpdated;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CachedItems;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEchoesInventoryComponent_CanFitItem, "CanFitItem" }, // 2702297884
		{ &Z_Construct_UFunction_UEchoesInventoryComponent_FetchItems, "FetchItems" }, // 1179103527
		{ &Z_Construct_UFunction_UEchoesInventoryComponent_GetAvailableVolume, "GetAvailableVolume" }, // 3725079514
		{ &Z_Construct_UFunction_UEchoesInventoryComponent_GetCachedItems, "GetCachedItems" }, // 2523739166
		{ &Z_Construct_UFunction_UEchoesInventoryComponent_HandleMoveRefreshFailure, "HandleMoveRefreshFailure" }, // 3064735412
		{ &Z_Construct_UFunction_UEchoesInventoryComponent_HandleMoveRefreshSuccess, "HandleMoveRefreshSuccess" }, // 4191017057
		{ &Z_Construct_UFunction_UEchoesInventoryComponent_InitializeStorage, "InitializeStorage" }, // 3046700570
		{ &Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_JettisonItem, "ServerOnly_JettisonItem" }, // 4235737200
		{ &Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_MoveItem, "ServerOnly_MoveItem" }, // 2995778485
		{ &Z_Construct_UFunction_UEchoesInventoryComponent_ServerOnly_StackAll, "ServerOnly_StackAll" }, // 1688501223
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UEchoesInventoryComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesInventoryComponent_Statics::NewProp_StorageId = { "StorageId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesInventoryComponent, StorageId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StorageId_MetaData), NewProp_StorageId_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEchoesInventoryComponent_Statics::NewProp_Capacity = { "Capacity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesInventoryComponent, Capacity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Capacity_MetaData), NewProp_Capacity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEchoesInventoryComponent_Statics::NewProp_UsedVolume = { "UsedVolume", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesInventoryComponent, UsedVolume), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UsedVolume_MetaData), NewProp_UsedVolume_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UEchoesInventoryComponent_Statics::NewProp_MaxTransferDistance = { "MaxTransferDistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesInventoryComponent, MaxTransferDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxTransferDistance_MetaData), NewProp_MaxTransferDistance_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UEchoesInventoryComponent_Statics::NewProp_OnInventoryUpdated = { "OnInventoryUpdated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesInventoryComponent, OnInventoryUpdated), Z_Construct_UDelegateFunction_Echoes_OnInventoryUpdated__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnInventoryUpdated_MetaData), NewProp_OnInventoryUpdated_MetaData) }; // 946450413
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UEchoesInventoryComponent_Statics::NewProp_CachedItems = { "CachedItems", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UEchoesInventoryComponent, CachedItems), Z_Construct_UScriptStruct_FEchoesContainerItems, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CachedItems_MetaData), NewProp_CachedItems_MetaData) }; // 255446170
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UEchoesInventoryComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventoryComponent_Statics::NewProp_StorageId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventoryComponent_Statics::NewProp_Capacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventoryComponent_Statics::NewProp_UsedVolume,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventoryComponent_Statics::NewProp_MaxTransferDistance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventoryComponent_Statics::NewProp_OnInventoryUpdated,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UEchoesInventoryComponent_Statics::NewProp_CachedItems,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesInventoryComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UEchoesInventoryComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesInventoryComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEchoesInventoryComponent_Statics::ClassParams = {
	&UEchoesInventoryComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UEchoesInventoryComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesInventoryComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEchoesInventoryComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UEchoesInventoryComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEchoesInventoryComponent()
{
	if (!Z_Registration_Info_UClass_UEchoesInventoryComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEchoesInventoryComponent.OuterSingleton, Z_Construct_UClass_UEchoesInventoryComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEchoesInventoryComponent.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEchoesInventoryComponent);
UEchoesInventoryComponent::~UEchoesInventoryComponent() {}
// ********** End Class UEchoesInventoryComponent **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesInventoryComponent_h__Script_Echoes_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FEchoesInventoryItem::StaticStruct, Z_Construct_UScriptStruct_FEchoesInventoryItem_Statics::NewStructOps, TEXT("EchoesInventoryItem"), &Z_Registration_Info_UScriptStruct_FEchoesInventoryItem, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FEchoesInventoryItem), 3518727963U) },
		{ FEchoesContainerItems::StaticStruct, Z_Construct_UScriptStruct_FEchoesContainerItems_Statics::NewStructOps, TEXT("EchoesContainerItems"), &Z_Registration_Info_UScriptStruct_FEchoesContainerItems, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FEchoesContainerItems), 255446170U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UEchoesInventoryComponent, UEchoesInventoryComponent::StaticClass, TEXT("UEchoesInventoryComponent"), &Z_Registration_Info_UClass_UEchoesInventoryComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEchoesInventoryComponent), 880132349U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesInventoryComponent_h__Script_Echoes_2637190715(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesInventoryComponent_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesInventoryComponent_h__Script_Echoes_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesInventoryComponent_h__Script_Echoes_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_EchoesInventoryComponent_h__Script_Echoes_Statics::ScriptStructInfo),
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
