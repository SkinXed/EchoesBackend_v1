// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ShipFittingInterface.h"
#include "EchoesCoreTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeShipFittingInterface() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
ECHOES_API UClass* Z_Construct_UClass_UEquipmentObserver();
ECHOES_API UClass* Z_Construct_UClass_UEquipmentObserver_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UShipFittingInterface();
ECHOES_API UClass* Z_Construct_UClass_UShipFittingInterface_NoRegister();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_EModuleState();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_ESlotType();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FCommon_ItemSlot();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FCommon_ModuleStats();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FCommon_ShipFittingData();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FCosmosDefenseLayer();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum ESlotType *****************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESlotType;
static UEnum* ESlotType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ESlotType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ESlotType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Echoes_ESlotType, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("ESlotType"));
	}
	return Z_Registration_Info_UEnum_ESlotType.OuterSingleton;
}
template<> ECHOES_API UEnum* StaticEnum<ESlotType>()
{
	return ESlotType_StaticEnum();
}
struct Z_Construct_UEnum_Echoes_ESlotType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Slot type enumeration\n * Represents different equipment slot categories\n */" },
#endif
		{ "High.Comment", "/** High slots - Weapons, offensive modules */" },
		{ "High.DisplayName", "High Slot" },
		{ "High.Name", "ESlotType::High" },
		{ "High.ToolTip", "High slots - Weapons, offensive modules" },
		{ "Low.Comment", "/** Low slots - Armor, damage mods, engine upgrades */" },
		{ "Low.DisplayName", "Low Slot" },
		{ "Low.Name", "ESlotType::Low" },
		{ "Low.ToolTip", "Low slots - Armor, damage mods, engine upgrades" },
		{ "Mid.Comment", "/** Medium slots - Shields, propulsion, electronic warfare */" },
		{ "Mid.DisplayName", "Mid Slot" },
		{ "Mid.Name", "ESlotType::Mid" },
		{ "Mid.ToolTip", "Medium slots - Shields, propulsion, electronic warfare" },
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
		{ "None.Comment", "/** Invalid/unassigned */" },
		{ "None.DisplayName", "None" },
		{ "None.Name", "ESlotType::None" },
		{ "None.ToolTip", "Invalid/unassigned" },
		{ "Rig.Comment", "/** Rig slots - Permanent ship modifications */" },
		{ "Rig.DisplayName", "Rig Slot" },
		{ "Rig.Name", "ESlotType::Rig" },
		{ "Rig.ToolTip", "Rig slots - Permanent ship modifications" },
		{ "Subsystem.Comment", "/** Subsystem slots - T3 ship subsystems */" },
		{ "Subsystem.DisplayName", "Subsystem Slot" },
		{ "Subsystem.Name", "ESlotType::Subsystem" },
		{ "Subsystem.ToolTip", "Subsystem slots - T3 ship subsystems" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Slot type enumeration\nRepresents different equipment slot categories" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ESlotType::High", (int64)ESlotType::High },
		{ "ESlotType::Mid", (int64)ESlotType::Mid },
		{ "ESlotType::Low", (int64)ESlotType::Low },
		{ "ESlotType::Rig", (int64)ESlotType::Rig },
		{ "ESlotType::Subsystem", (int64)ESlotType::Subsystem },
		{ "ESlotType::None", (int64)ESlotType::None },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Echoes_ESlotType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	"ESlotType",
	"ESlotType",
	Z_Construct_UEnum_Echoes_ESlotType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_ESlotType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_ESlotType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Echoes_ESlotType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Echoes_ESlotType()
{
	if (!Z_Registration_Info_UEnum_ESlotType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESlotType.InnerSingleton, Z_Construct_UEnum_Echoes_ESlotType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ESlotType.InnerSingleton;
}
// ********** End Enum ESlotType *******************************************************************

// ********** Begin Enum EModuleState **************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EModuleState;
static UEnum* EModuleState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EModuleState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EModuleState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Echoes_EModuleState, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("EModuleState"));
	}
	return Z_Registration_Info_UEnum_EModuleState.OuterSingleton;
}
template<> ECHOES_API UEnum* StaticEnum<EModuleState>()
{
	return EModuleState_StaticEnum();
}
struct Z_Construct_UEnum_Echoes_EModuleState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "Active.Comment", "/** Module is active/running */" },
		{ "Active.DisplayName", "Active" },
		{ "Active.Name", "EModuleState::Active" },
		{ "Active.ToolTip", "Module is active/running" },
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Module state enumeration\n */" },
#endif
		{ "Cooldown.Comment", "/** Module is in cooldown */" },
		{ "Cooldown.DisplayName", "Cooldown" },
		{ "Cooldown.Name", "EModuleState::Cooldown" },
		{ "Cooldown.ToolTip", "Module is in cooldown" },
		{ "Damaged.Comment", "/** Module is damaged/burnt out */" },
		{ "Damaged.DisplayName", "Damaged" },
		{ "Damaged.Name", "EModuleState::Damaged" },
		{ "Damaged.ToolTip", "Module is damaged/burnt out" },
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
		{ "Offline.Comment", "/** Module is offline/inactive */" },
		{ "Offline.DisplayName", "Offline" },
		{ "Offline.Name", "EModuleState::Offline" },
		{ "Offline.ToolTip", "Module is offline/inactive" },
		{ "Overload.Comment", "/** Module is overloaded (increased performance, risk of burnout) */" },
		{ "Overload.DisplayName", "Overload" },
		{ "Overload.Name", "EModuleState::Overload" },
		{ "Overload.ToolTip", "Module is overloaded (increased performance, risk of burnout)" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Module state enumeration" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EModuleState::Offline", (int64)EModuleState::Offline },
		{ "EModuleState::Active", (int64)EModuleState::Active },
		{ "EModuleState::Overload", (int64)EModuleState::Overload },
		{ "EModuleState::Cooldown", (int64)EModuleState::Cooldown },
		{ "EModuleState::Damaged", (int64)EModuleState::Damaged },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Echoes_EModuleState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	"EModuleState",
	"EModuleState",
	Z_Construct_UEnum_Echoes_EModuleState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_EModuleState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_EModuleState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Echoes_EModuleState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Echoes_EModuleState()
{
	if (!Z_Registration_Info_UEnum_EModuleState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EModuleState.InnerSingleton, Z_Construct_UEnum_Echoes_EModuleState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EModuleState.InnerSingleton;
}
// ********** End Enum EModuleState ****************************************************************

// ********** Begin ScriptStruct FCommon_ItemSlot **************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FCommon_ItemSlot;
class UScriptStruct* FCommon_ItemSlot::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FCommon_ItemSlot.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FCommon_ItemSlot.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCommon_ItemSlot, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("Common_ItemSlot"));
	}
	return Z_Registration_Info_UScriptStruct_FCommon_ItemSlot.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * FCommon_ItemSlot\n * \n * Represents a single equipment slot on a ship\n * Contains module information and activation state\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "FCommon_ItemSlot\n\nRepresents a single equipment slot on a ship\nContains module information and activation state" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotIndex_MetaData[] = {
		{ "Category", "Item Slot" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Unique slot identifier (0-based index within slot type) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Unique slot identifier (0-based index within slot type)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotType_MetaData[] = {
		{ "Category", "Item Slot" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Slot type (High/Mid/Low/Rig/Subsystem) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Slot type (High/Mid/Low/Rig/Subsystem)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemID_MetaData[] = {
		{ "Category", "Item Slot" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Item/Module ID (0 = empty slot) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Item/Module ID (0 = empty slot)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemName_MetaData[] = {
		{ "Category", "Item Slot" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Item name for display */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Item name for display" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IconTexture_MetaData[] = {
		{ "Category", "Item Slot" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Icon texture for UI */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Icon texture for UI" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Quantity_MetaData[] = {
		{ "Category", "Item Slot" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Quantity/charges (for ammo, nanite paste, etc.) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Quantity/charges (for ammo, nanite paste, etc.)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Cooldown_MetaData[] = {
		{ "Category", "Item Slot" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current cooldown remaining (seconds) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current cooldown remaining (seconds)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ModuleState_MetaData[] = {
		{ "Category", "Item Slot" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Module activation state */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Module activation state" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsActive_MetaData[] = {
		{ "Category", "Item Slot" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Is this module currently active? */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Is this module currently active?" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCanActivate_MetaData[] = {
		{ "Category", "Item Slot" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Can this module be activated? (has capacitor, not in cooldown) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Can this module be activated? (has capacitor, not in cooldown)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PowergridRequired_MetaData[] = {
		{ "Category", "Item Slot" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Powergrid requirement */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Powergrid requirement" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CPURequired_MetaData[] = {
		{ "Category", "Item Slot" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** CPU requirement */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "CPU requirement" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CapacitorCost_MetaData[] = {
		{ "Category", "Item Slot" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Capacitor cost per activation */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Capacitor cost per activation" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SlotType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SlotType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ItemID;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ItemName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IconTexture;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Quantity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Cooldown;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ModuleState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ModuleState;
	static void NewProp_bIsActive_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsActive;
	static void NewProp_bCanActivate_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanActivate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PowergridRequired;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CPURequired;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CapacitorCost;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCommon_ItemSlot>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ItemSlot, SlotIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotIndex_MetaData), NewProp_SlotIndex_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_SlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_SlotType = { "SlotType", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ItemSlot, SlotType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotType_MetaData), NewProp_SlotType_MetaData) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_ItemID = { "ItemID", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ItemSlot, ItemID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemID_MetaData), NewProp_ItemID_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_ItemName = { "ItemName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ItemSlot, ItemName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemName_MetaData), NewProp_ItemName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_IconTexture = { "IconTexture", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ItemSlot, IconTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IconTexture_MetaData), NewProp_IconTexture_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_Quantity = { "Quantity", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ItemSlot, Quantity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Quantity_MetaData), NewProp_Quantity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_Cooldown = { "Cooldown", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ItemSlot, Cooldown), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Cooldown_MetaData), NewProp_Cooldown_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_ModuleState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_ModuleState = { "ModuleState", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ItemSlot, ModuleState), Z_Construct_UEnum_Echoes_EModuleState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ModuleState_MetaData), NewProp_ModuleState_MetaData) }; // 1837800180
void Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_bIsActive_SetBit(void* Obj)
{
	((FCommon_ItemSlot*)Obj)->bIsActive = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_bIsActive = { "bIsActive", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FCommon_ItemSlot), &Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_bIsActive_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsActive_MetaData), NewProp_bIsActive_MetaData) };
void Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_bCanActivate_SetBit(void* Obj)
{
	((FCommon_ItemSlot*)Obj)->bCanActivate = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_bCanActivate = { "bCanActivate", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FCommon_ItemSlot), &Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_bCanActivate_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCanActivate_MetaData), NewProp_bCanActivate_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_PowergridRequired = { "PowergridRequired", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ItemSlot, PowergridRequired), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PowergridRequired_MetaData), NewProp_PowergridRequired_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_CPURequired = { "CPURequired", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ItemSlot, CPURequired), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CPURequired_MetaData), NewProp_CPURequired_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_CapacitorCost = { "CapacitorCost", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ItemSlot, CapacitorCost), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CapacitorCost_MetaData), NewProp_CapacitorCost_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_SlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_SlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_ItemID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_ItemName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_IconTexture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_Quantity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_Cooldown,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_ModuleState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_ModuleState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_bIsActive,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_bCanActivate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_PowergridRequired,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_CPURequired,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewProp_CapacitorCost,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"Common_ItemSlot",
	Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::PropPointers),
	sizeof(FCommon_ItemSlot),
	alignof(FCommon_ItemSlot),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCommon_ItemSlot()
{
	if (!Z_Registration_Info_UScriptStruct_FCommon_ItemSlot.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FCommon_ItemSlot.InnerSingleton, Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FCommon_ItemSlot.InnerSingleton;
}
// ********** End ScriptStruct FCommon_ItemSlot ****************************************************

// ********** Begin ScriptStruct FCommon_ModuleStats ***********************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FCommon_ModuleStats;
class UScriptStruct* FCommon_ModuleStats::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FCommon_ModuleStats.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FCommon_ModuleStats.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCommon_ModuleStats, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("Common_ModuleStats"));
	}
	return Z_Registration_Info_UScriptStruct_FCommon_ModuleStats.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * FCommon_ModuleStats\n * \n * Statistics for a single module\n * Used for display and calculations\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "FCommon_ModuleStats\n\nStatistics for a single module\nUsed for display and calculations" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DPS_MetaData[] = {
		{ "Category", "Module Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** DPS contribution */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "DPS contribution" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AlphaDamage_MetaData[] = {
		{ "Category", "Module Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Alpha damage (single shot) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Alpha damage (single shot)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShieldBonus_MetaData[] = {
		{ "Category", "Module Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shield HP bonus */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shield HP bonus" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ArmorBonus_MetaData[] = {
		{ "Category", "Module Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Armor HP bonus */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Armor HP bonus" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HullBonus_MetaData[] = {
		{ "Category", "Module Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Hull HP bonus */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Hull HP bonus" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpeedMultiplier_MetaData[] = {
		{ "Category", "Module Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Speed multiplier (1.0 = no change, 1.1 = +10%) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Speed multiplier (1.0 = no change, 1.1 = +10%)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScanResolutionBonus_MetaData[] = {
		{ "Category", "Module Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Scan resolution bonus */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Scan resolution bonus" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EMResistBonus_MetaData[] = {
		{ "Category", "Module Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** EM resistance bonus */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "EM resistance bonus" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThermalResistBonus_MetaData[] = {
		{ "Category", "Module Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Thermal resistance bonus */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Thermal resistance bonus" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_KineticResistBonus_MetaData[] = {
		{ "Category", "Module Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Kinetic resistance bonus */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Kinetic resistance bonus" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExplosiveResistBonus_MetaData[] = {
		{ "Category", "Module Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Explosive resistance bonus */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Explosive resistance bonus" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DPS;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AlphaDamage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ShieldBonus;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ArmorBonus;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HullBonus;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SpeedMultiplier;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ScanResolutionBonus;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EMResistBonus;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ThermalResistBonus;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_KineticResistBonus;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ExplosiveResistBonus;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCommon_ModuleStats>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics::NewProp_DPS = { "DPS", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ModuleStats, DPS), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DPS_MetaData), NewProp_DPS_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics::NewProp_AlphaDamage = { "AlphaDamage", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ModuleStats, AlphaDamage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AlphaDamage_MetaData), NewProp_AlphaDamage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics::NewProp_ShieldBonus = { "ShieldBonus", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ModuleStats, ShieldBonus), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShieldBonus_MetaData), NewProp_ShieldBonus_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics::NewProp_ArmorBonus = { "ArmorBonus", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ModuleStats, ArmorBonus), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArmorBonus_MetaData), NewProp_ArmorBonus_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics::NewProp_HullBonus = { "HullBonus", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ModuleStats, HullBonus), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HullBonus_MetaData), NewProp_HullBonus_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics::NewProp_SpeedMultiplier = { "SpeedMultiplier", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ModuleStats, SpeedMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpeedMultiplier_MetaData), NewProp_SpeedMultiplier_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics::NewProp_ScanResolutionBonus = { "ScanResolutionBonus", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ModuleStats, ScanResolutionBonus), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScanResolutionBonus_MetaData), NewProp_ScanResolutionBonus_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics::NewProp_EMResistBonus = { "EMResistBonus", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ModuleStats, EMResistBonus), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EMResistBonus_MetaData), NewProp_EMResistBonus_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics::NewProp_ThermalResistBonus = { "ThermalResistBonus", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ModuleStats, ThermalResistBonus), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThermalResistBonus_MetaData), NewProp_ThermalResistBonus_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics::NewProp_KineticResistBonus = { "KineticResistBonus", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ModuleStats, KineticResistBonus), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_KineticResistBonus_MetaData), NewProp_KineticResistBonus_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics::NewProp_ExplosiveResistBonus = { "ExplosiveResistBonus", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ModuleStats, ExplosiveResistBonus), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExplosiveResistBonus_MetaData), NewProp_ExplosiveResistBonus_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics::NewProp_DPS,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics::NewProp_AlphaDamage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics::NewProp_ShieldBonus,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics::NewProp_ArmorBonus,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics::NewProp_HullBonus,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics::NewProp_SpeedMultiplier,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics::NewProp_ScanResolutionBonus,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics::NewProp_EMResistBonus,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics::NewProp_ThermalResistBonus,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics::NewProp_KineticResistBonus,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics::NewProp_ExplosiveResistBonus,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"Common_ModuleStats",
	Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics::PropPointers),
	sizeof(FCommon_ModuleStats),
	alignof(FCommon_ModuleStats),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCommon_ModuleStats()
{
	if (!Z_Registration_Info_UScriptStruct_FCommon_ModuleStats.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FCommon_ModuleStats.InnerSingleton, Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FCommon_ModuleStats.InnerSingleton;
}
// ********** End ScriptStruct FCommon_ModuleStats *************************************************

// ********** Begin ScriptStruct FCommon_ShipFittingData *******************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FCommon_ShipFittingData;
class UScriptStruct* FCommon_ShipFittingData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FCommon_ShipFittingData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FCommon_ShipFittingData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCommon_ShipFittingData, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("Common_ShipFittingData"));
	}
	return Z_Registration_Info_UScriptStruct_FCommon_ShipFittingData.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * FCommon_ShipFittingData\n * \n * Complete fitting data for a ship\n * Contains all equipment slots and calculated statistics\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "FCommon_ShipFittingData\n\nComplete fitting data for a ship\nContains all equipment slots and calculated statistics" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HighSlots_MetaData[] = {
		{ "Category", "Fitting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** High slots (weapons, utility) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "High slots (weapons, utility)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MidSlots_MetaData[] = {
		{ "Category", "Fitting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Medium slots (shields, propulsion, EWAR) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Medium slots (shields, propulsion, EWAR)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LowSlots_MetaData[] = {
		{ "Category", "Fitting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Low slots (armor, damage mods, engineering) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Low slots (armor, damage mods, engineering)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RigSlots_MetaData[] = {
		{ "Category", "Fitting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Rig slots (permanent modifications) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Rig slots (permanent modifications)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PowergridUsed_MetaData[] = {
		{ "Category", "Fitting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current powergrid usage */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current powergrid usage" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PowergridMax_MetaData[] = {
		{ "Category", "Fitting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum available powergrid */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum available powergrid" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CPUUsed_MetaData[] = {
		{ "Category", "Fitting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current CPU usage */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current CPU usage" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CPUMax_MetaData[] = {
		{ "Category", "Fitting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum available CPU */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum available CPU" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalDPS_MetaData[] = {
		{ "Category", "Fitting Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Total DPS (all weapons) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Total DPS (all weapons)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AlphaStrike_MetaData[] = {
		{ "Category", "Fitting Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Alpha strike damage */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Alpha strike damage" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EffectiveHP_MetaData[] = {
		{ "Category", "Fitting Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Effective HP (with resistances) */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Effective HP (with resistances)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxSpeed_MetaData[] = {
		{ "Category", "Fitting Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum speed */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum speed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WarpSpeed_MetaData[] = {
		{ "Category", "Fitting Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Warp speed */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Warp speed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScanResolution_MetaData[] = {
		{ "Category", "Fitting Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Scan resolution */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Scan resolution" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SignatureRadius_MetaData[] = {
		{ "Category", "Fitting Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Signature radius */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Signature radius" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShieldLayer_MetaData[] = {
		{ "Category", "Fitting Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Shield layer stats and resistances */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shield layer stats and resistances" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ArmorLayer_MetaData[] = {
		{ "Category", "Fitting Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Armor layer stats and resistances */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Armor layer stats and resistances" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StructureLayer_MetaData[] = {
		{ "Category", "Fitting Stats" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Structure layer stats and resistances */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Structure layer stats and resistances" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_HighSlots_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_HighSlots;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MidSlots_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_MidSlots;
	static const UECodeGen_Private::FStructPropertyParams NewProp_LowSlots_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_LowSlots;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RigSlots_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_RigSlots;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PowergridUsed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PowergridMax;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CPUUsed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CPUMax;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TotalDPS;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AlphaStrike;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_EffectiveHP;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WarpSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ScanResolution;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SignatureRadius;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ShieldLayer;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ArmorLayer;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StructureLayer;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCommon_ShipFittingData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_HighSlots_Inner = { "HighSlots", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCommon_ItemSlot, METADATA_PARAMS(0, nullptr) }; // 771062216
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_HighSlots = { "HighSlots", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipFittingData, HighSlots), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HighSlots_MetaData), NewProp_HighSlots_MetaData) }; // 771062216
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_MidSlots_Inner = { "MidSlots", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCommon_ItemSlot, METADATA_PARAMS(0, nullptr) }; // 771062216
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_MidSlots = { "MidSlots", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipFittingData, MidSlots), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MidSlots_MetaData), NewProp_MidSlots_MetaData) }; // 771062216
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_LowSlots_Inner = { "LowSlots", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCommon_ItemSlot, METADATA_PARAMS(0, nullptr) }; // 771062216
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_LowSlots = { "LowSlots", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipFittingData, LowSlots), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LowSlots_MetaData), NewProp_LowSlots_MetaData) }; // 771062216
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_RigSlots_Inner = { "RigSlots", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCommon_ItemSlot, METADATA_PARAMS(0, nullptr) }; // 771062216
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_RigSlots = { "RigSlots", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipFittingData, RigSlots), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RigSlots_MetaData), NewProp_RigSlots_MetaData) }; // 771062216
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_PowergridUsed = { "PowergridUsed", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipFittingData, PowergridUsed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PowergridUsed_MetaData), NewProp_PowergridUsed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_PowergridMax = { "PowergridMax", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipFittingData, PowergridMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PowergridMax_MetaData), NewProp_PowergridMax_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_CPUUsed = { "CPUUsed", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipFittingData, CPUUsed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CPUUsed_MetaData), NewProp_CPUUsed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_CPUMax = { "CPUMax", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipFittingData, CPUMax), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CPUMax_MetaData), NewProp_CPUMax_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_TotalDPS = { "TotalDPS", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipFittingData, TotalDPS), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalDPS_MetaData), NewProp_TotalDPS_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_AlphaStrike = { "AlphaStrike", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipFittingData, AlphaStrike), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AlphaStrike_MetaData), NewProp_AlphaStrike_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_EffectiveHP = { "EffectiveHP", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipFittingData, EffectiveHP), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EffectiveHP_MetaData), NewProp_EffectiveHP_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_MaxSpeed = { "MaxSpeed", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipFittingData, MaxSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxSpeed_MetaData), NewProp_MaxSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_WarpSpeed = { "WarpSpeed", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipFittingData, WarpSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WarpSpeed_MetaData), NewProp_WarpSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_ScanResolution = { "ScanResolution", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipFittingData, ScanResolution), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScanResolution_MetaData), NewProp_ScanResolution_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_SignatureRadius = { "SignatureRadius", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipFittingData, SignatureRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SignatureRadius_MetaData), NewProp_SignatureRadius_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_ShieldLayer = { "ShieldLayer", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipFittingData, ShieldLayer), Z_Construct_UScriptStruct_FCosmosDefenseLayer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShieldLayer_MetaData), NewProp_ShieldLayer_MetaData) }; // 3062971545
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_ArmorLayer = { "ArmorLayer", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipFittingData, ArmorLayer), Z_Construct_UScriptStruct_FCosmosDefenseLayer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArmorLayer_MetaData), NewProp_ArmorLayer_MetaData) }; // 3062971545
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_StructureLayer = { "StructureLayer", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCommon_ShipFittingData, StructureLayer), Z_Construct_UScriptStruct_FCosmosDefenseLayer, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StructureLayer_MetaData), NewProp_StructureLayer_MetaData) }; // 3062971545
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_HighSlots_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_HighSlots,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_MidSlots_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_MidSlots,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_LowSlots_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_LowSlots,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_RigSlots_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_RigSlots,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_PowergridUsed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_PowergridMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_CPUUsed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_CPUMax,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_TotalDPS,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_AlphaStrike,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_EffectiveHP,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_MaxSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_WarpSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_ScanResolution,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_SignatureRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_ShieldLayer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_ArmorLayer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewProp_StructureLayer,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"Common_ShipFittingData",
	Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::PropPointers),
	sizeof(FCommon_ShipFittingData),
	alignof(FCommon_ShipFittingData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCommon_ShipFittingData()
{
	if (!Z_Registration_Info_UScriptStruct_FCommon_ShipFittingData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FCommon_ShipFittingData.InnerSingleton, Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FCommon_ShipFittingData.InnerSingleton;
}
// ********** End ScriptStruct FCommon_ShipFittingData *********************************************

// ********** Begin Interface UShipFittingInterface Function CanInstallModule **********************
struct ShipFittingInterface_eventCanInstallModule_Parms
{
	int32 ItemID;
	ESlotType SlotType;
	int32 SlotIndex;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	ShipFittingInterface_eventCanInstallModule_Parms()
		: ReturnValue(false)
	{
	}
};
bool IShipFittingInterface::CanInstallModule(int32 ItemID, ESlotType SlotType, int32 SlotIndex) const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_CanInstallModule instead.");
	ShipFittingInterface_eventCanInstallModule_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UShipFittingInterface_CanInstallModule = FName(TEXT("CanInstallModule"));
bool IShipFittingInterface::Execute_CanInstallModule(const UObject* O, int32 ItemID, ESlotType SlotType, int32 SlotIndex)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UShipFittingInterface::StaticClass()));
	ShipFittingInterface_eventCanInstallModule_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UShipFittingInterface_CanInstallModule);
	if (Func)
	{
		Parms.ItemID=ItemID;
		Parms.SlotType=SlotType;
		Parms.SlotIndex=SlotIndex;
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IShipFittingInterface*)(O->GetNativeInterfaceAddress(UShipFittingInterface::StaticClass())))
	{
		Parms.ReturnValue = I->CanInstallModule_Implementation(ItemID,SlotType,SlotIndex);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UShipFittingInterface_CanInstallModule_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Fitting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Check if a module can be installed in a slot\n * \n * @param ItemID The module to check\n * @param SlotType Target slot type\n * @param SlotIndex Target slot index\n * @return True if module can be installed (PG/CPU available)\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Check if a module can be installed in a slot\n\n@param ItemID The module to check\n@param SlotType Target slot type\n@param SlotIndex Target slot index\n@return True if module can be installed (PG/CPU available)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_ItemID;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SlotType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SlotType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UShipFittingInterface_CanInstallModule_Statics::NewProp_ItemID = { "ItemID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipFittingInterface_eventCanInstallModule_Parms, ItemID), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UShipFittingInterface_CanInstallModule_Statics::NewProp_SlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UShipFittingInterface_CanInstallModule_Statics::NewProp_SlotType = { "SlotType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipFittingInterface_eventCanInstallModule_Parms, SlotType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(0, nullptr) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UShipFittingInterface_CanInstallModule_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipFittingInterface_eventCanInstallModule_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UShipFittingInterface_CanInstallModule_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ShipFittingInterface_eventCanInstallModule_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UShipFittingInterface_CanInstallModule_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ShipFittingInterface_eventCanInstallModule_Parms), &Z_Construct_UFunction_UShipFittingInterface_CanInstallModule_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShipFittingInterface_CanInstallModule_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipFittingInterface_CanInstallModule_Statics::NewProp_ItemID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipFittingInterface_CanInstallModule_Statics::NewProp_SlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipFittingInterface_CanInstallModule_Statics::NewProp_SlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipFittingInterface_CanInstallModule_Statics::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipFittingInterface_CanInstallModule_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipFittingInterface_CanInstallModule_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipFittingInterface_CanInstallModule_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipFittingInterface, nullptr, "CanInstallModule", Z_Construct_UFunction_UShipFittingInterface_CanInstallModule_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShipFittingInterface_CanInstallModule_Statics::PropPointers), sizeof(ShipFittingInterface_eventCanInstallModule_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipFittingInterface_CanInstallModule_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipFittingInterface_CanInstallModule_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ShipFittingInterface_eventCanInstallModule_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShipFittingInterface_CanInstallModule()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipFittingInterface_CanInstallModule_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IShipFittingInterface::execCanInstallModule)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_ItemID);
	P_GET_ENUM(ESlotType,Z_Param_SlotType);
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->CanInstallModule_Implementation(Z_Param_ItemID,ESlotType(Z_Param_SlotType),Z_Param_SlotIndex);
	P_NATIVE_END;
}
// ********** End Interface UShipFittingInterface Function CanInstallModule ************************

// ********** Begin Interface UShipFittingInterface Function GetEquipmentSlot **********************
struct ShipFittingInterface_eventGetEquipmentSlot_Parms
{
	ESlotType SlotType;
	int32 SlotIndex;
	FCommon_ItemSlot OutSlot;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	ShipFittingInterface_eventGetEquipmentSlot_Parms()
		: ReturnValue(false)
	{
	}
};
bool IShipFittingInterface::GetEquipmentSlot(ESlotType SlotType, int32 SlotIndex, FCommon_ItemSlot& OutSlot) const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetEquipmentSlot instead.");
	ShipFittingInterface_eventGetEquipmentSlot_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UShipFittingInterface_GetEquipmentSlot = FName(TEXT("GetEquipmentSlot"));
bool IShipFittingInterface::Execute_GetEquipmentSlot(const UObject* O, ESlotType SlotType, int32 SlotIndex, FCommon_ItemSlot& OutSlot)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UShipFittingInterface::StaticClass()));
	ShipFittingInterface_eventGetEquipmentSlot_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UShipFittingInterface_GetEquipmentSlot);
	if (Func)
	{
		Parms.SlotType=SlotType;
		Parms.SlotIndex=SlotIndex;
		Parms.OutSlot=OutSlot;
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
		OutSlot=Parms.OutSlot;
	}
	else if (auto I = (const IShipFittingInterface*)(O->GetNativeInterfaceAddress(UShipFittingInterface::StaticClass())))
	{
		Parms.ReturnValue = I->GetEquipmentSlot_Implementation(SlotType,SlotIndex,OutSlot);
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UShipFittingInterface_GetEquipmentSlot_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Fitting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Get a specific equipment slot\n * \n * @param SlotType The type of slot (High/Mid/Low/Rig)\n * @param SlotIndex Index within that slot type\n * @param OutSlot The slot data\n * @return True if slot exists\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get a specific equipment slot\n\n@param SlotType The type of slot (High/Mid/Low/Rig)\n@param SlotIndex Index within that slot type\n@param OutSlot The slot data\n@return True if slot exists" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_SlotType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SlotType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutSlot;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UShipFittingInterface_GetEquipmentSlot_Statics::NewProp_SlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UShipFittingInterface_GetEquipmentSlot_Statics::NewProp_SlotType = { "SlotType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipFittingInterface_eventGetEquipmentSlot_Parms, SlotType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(0, nullptr) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UShipFittingInterface_GetEquipmentSlot_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipFittingInterface_eventGetEquipmentSlot_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UShipFittingInterface_GetEquipmentSlot_Statics::NewProp_OutSlot = { "OutSlot", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipFittingInterface_eventGetEquipmentSlot_Parms, OutSlot), Z_Construct_UScriptStruct_FCommon_ItemSlot, METADATA_PARAMS(0, nullptr) }; // 771062216
void Z_Construct_UFunction_UShipFittingInterface_GetEquipmentSlot_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ShipFittingInterface_eventGetEquipmentSlot_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UShipFittingInterface_GetEquipmentSlot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ShipFittingInterface_eventGetEquipmentSlot_Parms), &Z_Construct_UFunction_UShipFittingInterface_GetEquipmentSlot_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShipFittingInterface_GetEquipmentSlot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipFittingInterface_GetEquipmentSlot_Statics::NewProp_SlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipFittingInterface_GetEquipmentSlot_Statics::NewProp_SlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipFittingInterface_GetEquipmentSlot_Statics::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipFittingInterface_GetEquipmentSlot_Statics::NewProp_OutSlot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipFittingInterface_GetEquipmentSlot_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipFittingInterface_GetEquipmentSlot_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipFittingInterface_GetEquipmentSlot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipFittingInterface, nullptr, "GetEquipmentSlot", Z_Construct_UFunction_UShipFittingInterface_GetEquipmentSlot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShipFittingInterface_GetEquipmentSlot_Statics::PropPointers), sizeof(ShipFittingInterface_eventGetEquipmentSlot_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipFittingInterface_GetEquipmentSlot_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipFittingInterface_GetEquipmentSlot_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ShipFittingInterface_eventGetEquipmentSlot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShipFittingInterface_GetEquipmentSlot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipFittingInterface_GetEquipmentSlot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IShipFittingInterface::execGetEquipmentSlot)
{
	P_GET_ENUM(ESlotType,Z_Param_SlotType);
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_GET_STRUCT_REF(FCommon_ItemSlot,Z_Param_Out_OutSlot);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetEquipmentSlot_Implementation(ESlotType(Z_Param_SlotType),Z_Param_SlotIndex,Z_Param_Out_OutSlot);
	P_NATIVE_END;
}
// ********** End Interface UShipFittingInterface Function GetEquipmentSlot ************************

// ********** Begin Interface UShipFittingInterface Function GetFittingData ************************
struct ShipFittingInterface_eventGetFittingData_Parms
{
	FCommon_ShipFittingData ReturnValue;
};
FCommon_ShipFittingData IShipFittingInterface::GetFittingData() const
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetFittingData instead.");
	ShipFittingInterface_eventGetFittingData_Parms Parms;
	return Parms.ReturnValue;
}
static FName NAME_UShipFittingInterface_GetFittingData = FName(TEXT("GetFittingData"));
FCommon_ShipFittingData IShipFittingInterface::Execute_GetFittingData(const UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UShipFittingInterface::StaticClass()));
	ShipFittingInterface_eventGetFittingData_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UShipFittingInterface_GetFittingData);
	if (Func)
	{
		const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (const IShipFittingInterface*)(O->GetNativeInterfaceAddress(UShipFittingInterface::StaticClass())))
	{
		Parms.ReturnValue = I->GetFittingData_Implementation();
	}
	return Parms.ReturnValue;
}
struct Z_Construct_UFunction_UShipFittingInterface_GetFittingData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Ship Fitting" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Get complete fitting data for this ship\n * \n * @return Fitting data with all slots and stats\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get complete fitting data for this ship\n\n@return Fitting data with all slots and stats" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UShipFittingInterface_GetFittingData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShipFittingInterface_eventGetFittingData_Parms, ReturnValue), Z_Construct_UScriptStruct_FCommon_ShipFittingData, METADATA_PARAMS(0, nullptr) }; // 1329122485
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShipFittingInterface_GetFittingData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShipFittingInterface_GetFittingData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipFittingInterface_GetFittingData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShipFittingInterface_GetFittingData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShipFittingInterface, nullptr, "GetFittingData", Z_Construct_UFunction_UShipFittingInterface_GetFittingData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UShipFittingInterface_GetFittingData_Statics::PropPointers), sizeof(ShipFittingInterface_eventGetFittingData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShipFittingInterface_GetFittingData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShipFittingInterface_GetFittingData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(ShipFittingInterface_eventGetFittingData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShipFittingInterface_GetFittingData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShipFittingInterface_GetFittingData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IShipFittingInterface::execGetFittingData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FCommon_ShipFittingData*)Z_Param__Result=P_THIS->GetFittingData_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UShipFittingInterface Function GetFittingData **************************

// ********** Begin Interface UShipFittingInterface ************************************************
void UShipFittingInterface::StaticRegisterNativesUShipFittingInterface()
{
	UClass* Class = UShipFittingInterface::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "CanInstallModule", &IShipFittingInterface::execCanInstallModule },
		{ "GetEquipmentSlot", &IShipFittingInterface::execGetEquipmentSlot },
		{ "GetFittingData", &IShipFittingInterface::execGetFittingData },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UShipFittingInterface;
UClass* UShipFittingInterface::GetPrivateStaticClass()
{
	using TClass = UShipFittingInterface;
	if (!Z_Registration_Info_UClass_UShipFittingInterface.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ShipFittingInterface"),
			Z_Registration_Info_UClass_UShipFittingInterface.InnerSingleton,
			StaticRegisterNativesUShipFittingInterface,
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
	return Z_Registration_Info_UClass_UShipFittingInterface.InnerSingleton;
}
UClass* Z_Construct_UClass_UShipFittingInterface_NoRegister()
{
	return UShipFittingInterface::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UShipFittingInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UShipFittingInterface_CanInstallModule, "CanInstallModule" }, // 3136803318
		{ &Z_Construct_UFunction_UShipFittingInterface_GetEquipmentSlot, "GetEquipmentSlot" }, // 464743073
		{ &Z_Construct_UFunction_UShipFittingInterface_GetFittingData, "GetFittingData" }, // 3722263026
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IShipFittingInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UShipFittingInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UShipFittingInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UShipFittingInterface_Statics::ClassParams = {
	&UShipFittingInterface::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UShipFittingInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UShipFittingInterface_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UShipFittingInterface()
{
	if (!Z_Registration_Info_UClass_UShipFittingInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UShipFittingInterface.OuterSingleton, Z_Construct_UClass_UShipFittingInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UShipFittingInterface.OuterSingleton;
}
UShipFittingInterface::UShipFittingInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UShipFittingInterface);
// ********** End Interface UShipFittingInterface **************************************************

// ********** Begin Interface UEquipmentObserver Function OnEquipmentChanged ***********************
struct EquipmentObserver_eventOnEquipmentChanged_Parms
{
	ESlotType SlotType;
	int32 SlotIndex;
	FCommon_ItemSlot NewSlotData;
};
void IEquipmentObserver::OnEquipmentChanged(ESlotType SlotType, int32 SlotIndex, FCommon_ItemSlot const& NewSlotData)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnEquipmentChanged instead.");
}
static FName NAME_UEquipmentObserver_OnEquipmentChanged = FName(TEXT("OnEquipmentChanged"));
void IEquipmentObserver::Execute_OnEquipmentChanged(UObject* O, ESlotType SlotType, int32 SlotIndex, FCommon_ItemSlot const& NewSlotData)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UEquipmentObserver::StaticClass()));
	EquipmentObserver_eventOnEquipmentChanged_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UEquipmentObserver_OnEquipmentChanged);
	if (Func)
	{
		Parms.SlotType=SlotType;
		Parms.SlotIndex=SlotIndex;
		Parms.NewSlotData=NewSlotData;
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IEquipmentObserver*)(O->GetNativeInterfaceAddress(UEquipmentObserver::StaticClass())))
	{
		I->OnEquipmentChanged_Implementation(SlotType,SlotIndex,NewSlotData);
	}
}
struct Z_Construct_UFunction_UEquipmentObserver_OnEquipmentChanged_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Equipment Observer" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Called when equipment is changed (installed/uninstalled)\n * \n * @param SlotType The slot type that changed\n * @param SlotIndex The slot index that changed\n * @param NewSlotData The new slot data\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when equipment is changed (installed/uninstalled)\n\n@param SlotType The slot type that changed\n@param SlotIndex The slot index that changed\n@param NewSlotData The new slot data" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewSlotData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_SlotType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SlotType;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SlotIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NewSlotData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UEquipmentObserver_OnEquipmentChanged_Statics::NewProp_SlotType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UEquipmentObserver_OnEquipmentChanged_Statics::NewProp_SlotType = { "SlotType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EquipmentObserver_eventOnEquipmentChanged_Parms, SlotType), Z_Construct_UEnum_Echoes_ESlotType, METADATA_PARAMS(0, nullptr) }; // 780113368
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UEquipmentObserver_OnEquipmentChanged_Statics::NewProp_SlotIndex = { "SlotIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EquipmentObserver_eventOnEquipmentChanged_Parms, SlotIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEquipmentObserver_OnEquipmentChanged_Statics::NewProp_NewSlotData = { "NewSlotData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EquipmentObserver_eventOnEquipmentChanged_Parms, NewSlotData), Z_Construct_UScriptStruct_FCommon_ItemSlot, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewSlotData_MetaData), NewProp_NewSlotData_MetaData) }; // 771062216
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEquipmentObserver_OnEquipmentChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentObserver_OnEquipmentChanged_Statics::NewProp_SlotType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentObserver_OnEquipmentChanged_Statics::NewProp_SlotType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentObserver_OnEquipmentChanged_Statics::NewProp_SlotIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentObserver_OnEquipmentChanged_Statics::NewProp_NewSlotData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentObserver_OnEquipmentChanged_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEquipmentObserver_OnEquipmentChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEquipmentObserver, nullptr, "OnEquipmentChanged", Z_Construct_UFunction_UEquipmentObserver_OnEquipmentChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentObserver_OnEquipmentChanged_Statics::PropPointers), sizeof(EquipmentObserver_eventOnEquipmentChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentObserver_OnEquipmentChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEquipmentObserver_OnEquipmentChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(EquipmentObserver_eventOnEquipmentChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEquipmentObserver_OnEquipmentChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEquipmentObserver_OnEquipmentChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IEquipmentObserver::execOnEquipmentChanged)
{
	P_GET_ENUM(ESlotType,Z_Param_SlotType);
	P_GET_PROPERTY(FIntProperty,Z_Param_SlotIndex);
	P_GET_STRUCT_REF(FCommon_ItemSlot,Z_Param_Out_NewSlotData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnEquipmentChanged_Implementation(ESlotType(Z_Param_SlotType),Z_Param_SlotIndex,Z_Param_Out_NewSlotData);
	P_NATIVE_END;
}
// ********** End Interface UEquipmentObserver Function OnEquipmentChanged *************************

// ********** Begin Interface UEquipmentObserver Function OnFittingStatsChanged ********************
struct EquipmentObserver_eventOnFittingStatsChanged_Parms
{
	FCommon_ShipFittingData NewFittingData;
};
void IEquipmentObserver::OnFittingStatsChanged(FCommon_ShipFittingData const& NewFittingData)
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnFittingStatsChanged instead.");
}
static FName NAME_UEquipmentObserver_OnFittingStatsChanged = FName(TEXT("OnFittingStatsChanged"));
void IEquipmentObserver::Execute_OnFittingStatsChanged(UObject* O, FCommon_ShipFittingData const& NewFittingData)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UEquipmentObserver::StaticClass()));
	EquipmentObserver_eventOnFittingStatsChanged_Parms Parms;
	UFunction* const Func = O->FindFunction(NAME_UEquipmentObserver_OnFittingStatsChanged);
	if (Func)
	{
		Parms.NewFittingData=NewFittingData;
		O->ProcessEvent(Func, &Parms);
	}
	else if (auto I = (IEquipmentObserver*)(O->GetNativeInterfaceAddress(UEquipmentObserver::StaticClass())))
	{
		I->OnFittingStatsChanged_Implementation(NewFittingData);
	}
}
struct Z_Construct_UFunction_UEquipmentObserver_OnFittingStatsChanged_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Equipment Observer" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Called when fitting stats are recalculated\n * \n * @param NewFittingData The updated fitting data with new stats\n */" },
#endif
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when fitting stats are recalculated\n\n@param NewFittingData The updated fitting data with new stats" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewFittingData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_NewFittingData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UEquipmentObserver_OnFittingStatsChanged_Statics::NewProp_NewFittingData = { "NewFittingData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EquipmentObserver_eventOnFittingStatsChanged_Parms, NewFittingData), Z_Construct_UScriptStruct_FCommon_ShipFittingData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewFittingData_MetaData), NewProp_NewFittingData_MetaData) }; // 1329122485
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UEquipmentObserver_OnFittingStatsChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UEquipmentObserver_OnFittingStatsChanged_Statics::NewProp_NewFittingData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentObserver_OnFittingStatsChanged_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UEquipmentObserver_OnFittingStatsChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UEquipmentObserver, nullptr, "OnFittingStatsChanged", Z_Construct_UFunction_UEquipmentObserver_OnFittingStatsChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentObserver_OnFittingStatsChanged_Statics::PropPointers), sizeof(EquipmentObserver_eventOnFittingStatsChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UEquipmentObserver_OnFittingStatsChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UEquipmentObserver_OnFittingStatsChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(EquipmentObserver_eventOnFittingStatsChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UEquipmentObserver_OnFittingStatsChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UEquipmentObserver_OnFittingStatsChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IEquipmentObserver::execOnFittingStatsChanged)
{
	P_GET_STRUCT_REF(FCommon_ShipFittingData,Z_Param_Out_NewFittingData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnFittingStatsChanged_Implementation(Z_Param_Out_NewFittingData);
	P_NATIVE_END;
}
// ********** End Interface UEquipmentObserver Function OnFittingStatsChanged **********************

// ********** Begin Interface UEquipmentObserver ***************************************************
void UEquipmentObserver::StaticRegisterNativesUEquipmentObserver()
{
	UClass* Class = UEquipmentObserver::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnEquipmentChanged", &IEquipmentObserver::execOnEquipmentChanged },
		{ "OnFittingStatsChanged", &IEquipmentObserver::execOnFittingStatsChanged },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UEquipmentObserver;
UClass* UEquipmentObserver::GetPrivateStaticClass()
{
	using TClass = UEquipmentObserver;
	if (!Z_Registration_Info_UClass_UEquipmentObserver.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("EquipmentObserver"),
			Z_Registration_Info_UClass_UEquipmentObserver.InnerSingleton,
			StaticRegisterNativesUEquipmentObserver,
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
	return Z_Registration_Info_UClass_UEquipmentObserver.InnerSingleton;
}
UClass* Z_Construct_UClass_UEquipmentObserver_NoRegister()
{
	return UEquipmentObserver::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UEquipmentObserver_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Core/Common/Interfaces/ShipFittingInterface.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UEquipmentObserver_OnEquipmentChanged, "OnEquipmentChanged" }, // 3032368806
		{ &Z_Construct_UFunction_UEquipmentObserver_OnFittingStatsChanged, "OnFittingStatsChanged" }, // 3986252906
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IEquipmentObserver>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UEquipmentObserver_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UEquipmentObserver_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UEquipmentObserver_Statics::ClassParams = {
	&UEquipmentObserver::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UEquipmentObserver_Statics::Class_MetaDataParams), Z_Construct_UClass_UEquipmentObserver_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UEquipmentObserver()
{
	if (!Z_Registration_Info_UClass_UEquipmentObserver.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UEquipmentObserver.OuterSingleton, Z_Construct_UClass_UEquipmentObserver_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UEquipmentObserver.OuterSingleton;
}
UEquipmentObserver::UEquipmentObserver(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UEquipmentObserver);
// ********** End Interface UEquipmentObserver *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h__Script_Echoes_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ESlotType_StaticEnum, TEXT("ESlotType"), &Z_Registration_Info_UEnum_ESlotType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 780113368U) },
		{ EModuleState_StaticEnum, TEXT("EModuleState"), &Z_Registration_Info_UEnum_EModuleState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1837800180U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FCommon_ItemSlot::StaticStruct, Z_Construct_UScriptStruct_FCommon_ItemSlot_Statics::NewStructOps, TEXT("Common_ItemSlot"), &Z_Registration_Info_UScriptStruct_FCommon_ItemSlot, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCommon_ItemSlot), 771062216U) },
		{ FCommon_ModuleStats::StaticStruct, Z_Construct_UScriptStruct_FCommon_ModuleStats_Statics::NewStructOps, TEXT("Common_ModuleStats"), &Z_Registration_Info_UScriptStruct_FCommon_ModuleStats, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCommon_ModuleStats), 3246050195U) },
		{ FCommon_ShipFittingData::StaticStruct, Z_Construct_UScriptStruct_FCommon_ShipFittingData_Statics::NewStructOps, TEXT("Common_ShipFittingData"), &Z_Registration_Info_UScriptStruct_FCommon_ShipFittingData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCommon_ShipFittingData), 1329122485U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UShipFittingInterface, UShipFittingInterface::StaticClass, TEXT("UShipFittingInterface"), &Z_Registration_Info_UClass_UShipFittingInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UShipFittingInterface), 1705428250U) },
		{ Z_Construct_UClass_UEquipmentObserver, UEquipmentObserver::StaticClass, TEXT("UEquipmentObserver"), &Z_Registration_Info_UClass_UEquipmentObserver, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UEquipmentObserver), 1124797909U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h__Script_Echoes_3248476805(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h__Script_Echoes_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h__Script_Echoes_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h__Script_Echoes_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h__Script_Echoes_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_Core_Common_Interfaces_ShipFittingInterface_h__Script_Echoes_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
