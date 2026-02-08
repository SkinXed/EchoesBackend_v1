// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OverviewWidget.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeOverviewWidget() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UOverviewRowObject();
ECHOES_API UClass* Z_Construct_UClass_UOverviewRowObject_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UOverviewRowWidget();
ECHOES_API UClass* Z_Construct_UClass_UOverviewRowWidget_NoRegister();
ECHOES_API UClass* Z_Construct_UClass_UOverviewWidget();
ECHOES_API UClass* Z_Construct_UClass_UOverviewWidget_NoRegister();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_EOverviewEntryType();
ECHOES_API UEnum* Z_Construct_UEnum_Echoes_EOverviewSortBy();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnOverviewItemDoubleClicked__DelegateSignature();
ECHOES_API UFunction* Z_Construct_UDelegateFunction_Echoes_OnOverviewSelectionChanged__DelegateSignature();
ECHOES_API UScriptStruct* Z_Construct_UScriptStruct_FOverviewRowData();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
UMG_API UClass* Z_Construct_UClass_UImage_NoRegister();
UMG_API UClass* Z_Construct_UClass_UListView_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserObjectListEntry_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_Echoes();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EOverviewEntryType ********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOverviewEntryType;
static UEnum* EOverviewEntryType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOverviewEntryType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOverviewEntryType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Echoes_EOverviewEntryType, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("EOverviewEntryType"));
	}
	return Z_Registration_Info_UEnum_EOverviewEntryType.OuterSingleton;
}
template<> ECHOES_API UEnum* StaticEnum<EOverviewEntryType>()
{
	return EOverviewEntryType_StaticEnum();
}
struct Z_Construct_UEnum_Echoes_EOverviewEntryType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Celestial.Comment", "/** Celestial object (planet, asteroid, etc.) */" },
		{ "Celestial.DisplayName", "Celestial" },
		{ "Celestial.Name", "EOverviewEntryType::Celestial" },
		{ "Celestial.ToolTip", "Celestial object (planet, asteroid, etc.)" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Overview entry type enum\n * Categorizes entities shown in overview\n */" },
#endif
		{ "Friendly.Comment", "/** Friendly NPC or player */" },
		{ "Friendly.DisplayName", "Friendly" },
		{ "Friendly.Name", "EOverviewEntryType::Friendly" },
		{ "Friendly.ToolTip", "Friendly NPC or player" },
		{ "Gate.Comment", "/** Wormhole or jump gate */" },
		{ "Gate.DisplayName", "Gate" },
		{ "Gate.Name", "EOverviewEntryType::Gate" },
		{ "Gate.ToolTip", "Wormhole or jump gate" },
		{ "Hostile.Comment", "/** Hostile/enemy entity */" },
		{ "Hostile.DisplayName", "Hostile" },
		{ "Hostile.Name", "EOverviewEntryType::Hostile" },
		{ "Hostile.ToolTip", "Hostile/enemy entity" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
		{ "Neutral.Comment", "/** Neutral entity */" },
		{ "Neutral.DisplayName", "Neutral" },
		{ "Neutral.Name", "EOverviewEntryType::Neutral" },
		{ "Neutral.ToolTip", "Neutral entity" },
		{ "Other.Comment", "/** Other/Unknown */" },
		{ "Other.DisplayName", "Other" },
		{ "Other.Name", "EOverviewEntryType::Other" },
		{ "Other.ToolTip", "Other/Unknown" },
		{ "Player.Comment", "/** Player-controlled ship */" },
		{ "Player.DisplayName", "Player" },
		{ "Player.Name", "EOverviewEntryType::Player" },
		{ "Player.ToolTip", "Player-controlled ship" },
		{ "Structure.Comment", "/** Station or structure */" },
		{ "Structure.DisplayName", "Structure" },
		{ "Structure.Name", "EOverviewEntryType::Structure" },
		{ "Structure.ToolTip", "Station or structure" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Overview entry type enum\nCategorizes entities shown in overview" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOverviewEntryType::Player", (int64)EOverviewEntryType::Player },
		{ "EOverviewEntryType::Friendly", (int64)EOverviewEntryType::Friendly },
		{ "EOverviewEntryType::Neutral", (int64)EOverviewEntryType::Neutral },
		{ "EOverviewEntryType::Hostile", (int64)EOverviewEntryType::Hostile },
		{ "EOverviewEntryType::Celestial", (int64)EOverviewEntryType::Celestial },
		{ "EOverviewEntryType::Structure", (int64)EOverviewEntryType::Structure },
		{ "EOverviewEntryType::Gate", (int64)EOverviewEntryType::Gate },
		{ "EOverviewEntryType::Other", (int64)EOverviewEntryType::Other },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Echoes_EOverviewEntryType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	"EOverviewEntryType",
	"EOverviewEntryType",
	Z_Construct_UEnum_Echoes_EOverviewEntryType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_EOverviewEntryType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_EOverviewEntryType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Echoes_EOverviewEntryType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Echoes_EOverviewEntryType()
{
	if (!Z_Registration_Info_UEnum_EOverviewEntryType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOverviewEntryType.InnerSingleton, Z_Construct_UEnum_Echoes_EOverviewEntryType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOverviewEntryType.InnerSingleton;
}
// ********** End Enum EOverviewEntryType **********************************************************

// ********** Begin Enum EOverviewSortBy ***********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EOverviewSortBy;
static UEnum* EOverviewSortBy_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EOverviewSortBy.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EOverviewSortBy.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_Echoes_EOverviewSortBy, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("EOverviewSortBy"));
	}
	return Z_Registration_Info_UEnum_EOverviewSortBy.OuterSingleton;
}
template<> ECHOES_API UEnum* StaticEnum<EOverviewSortBy>()
{
	return EOverviewSortBy_StaticEnum();
}
struct Z_Construct_UEnum_Echoes_EOverviewSortBy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Overview sorting options\n */" },
#endif
		{ "Distance.Comment", "/** Sort by distance (closest first) */" },
		{ "Distance.DisplayName", "Distance" },
		{ "Distance.Name", "EOverviewSortBy::Distance" },
		{ "Distance.ToolTip", "Sort by distance (closest first)" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
		{ "Name.Comment", "/** Sort by name (alphabetical) */" },
		{ "Name.DisplayName", "Name" },
		{ "Name.Name", "EOverviewSortBy::Name" },
		{ "Name.ToolTip", "Sort by name (alphabetical)" },
		{ "RadialVelocity.Comment", "/** Sort by radial velocity (approaching first) */" },
		{ "RadialVelocity.DisplayName", "Radial Velocity" },
		{ "RadialVelocity.Name", "EOverviewSortBy::RadialVelocity" },
		{ "RadialVelocity.ToolTip", "Sort by radial velocity (approaching first)" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Overview sorting options" },
#endif
		{ "Type.Comment", "/** Sort by type */" },
		{ "Type.DisplayName", "Type" },
		{ "Type.Name", "EOverviewSortBy::Type" },
		{ "Type.ToolTip", "Sort by type" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EOverviewSortBy::Distance", (int64)EOverviewSortBy::Distance },
		{ "EOverviewSortBy::Name", (int64)EOverviewSortBy::Name },
		{ "EOverviewSortBy::Type", (int64)EOverviewSortBy::Type },
		{ "EOverviewSortBy::RadialVelocity", (int64)EOverviewSortBy::RadialVelocity },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_Echoes_EOverviewSortBy_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	"EOverviewSortBy",
	"EOverviewSortBy",
	Z_Construct_UEnum_Echoes_EOverviewSortBy_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_EOverviewSortBy_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_Echoes_EOverviewSortBy_Statics::Enum_MetaDataParams), Z_Construct_UEnum_Echoes_EOverviewSortBy_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_Echoes_EOverviewSortBy()
{
	if (!Z_Registration_Info_UEnum_EOverviewSortBy.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EOverviewSortBy.InnerSingleton, Z_Construct_UEnum_Echoes_EOverviewSortBy_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EOverviewSortBy.InnerSingleton;
}
// ********** End Enum EOverviewSortBy *************************************************************

// ********** Begin ScriptStruct FOverviewRowData **************************************************
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FOverviewRowData;
class UScriptStruct* FOverviewRowData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FOverviewRowData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FOverviewRowData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FOverviewRowData, (UObject*)Z_Construct_UPackage__Script_Echoes(), TEXT("OverviewRowData"));
	}
	return Z_Registration_Info_UScriptStruct_FOverviewRowData.OuterSingleton;
}
struct Z_Construct_UScriptStruct_FOverviewRowData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * FOverviewRowData\n * \n * Data structure for a single overview entry\n * Used with UListView for efficient display of many entities\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "FOverviewRowData\n\nData structure for a single overview entry\nUsed with UListView for efficient display of many entities" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EntityID_MetaData[] = {
		{ "Category", "Overview" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Unique identifier for this entry */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Unique identifier for this entry" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActorReference_MetaData[] = {
		{ "Category", "Overview" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Reference to the actual actor */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reference to the actual actor" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EntryType_MetaData[] = {
		{ "Category", "Overview" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Entity type for filtering and display */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Entity type for filtering and display" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IconTexture_MetaData[] = {
		{ "Category", "Overview" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Icon texture for this entity type */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Icon texture for this entity type" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EntityName_MetaData[] = {
		{ "Category", "Overview" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Display name */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Display name" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Distance_MetaData[] = {
		{ "Category", "Overview" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Distance from player in centimeters */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Distance from player in centimeters" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RadialVelocity_MetaData[] = {
		{ "Category", "Overview" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Radial velocity (negative = approaching, positive = fleeing) in m/s */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Radial velocity (negative = approaching, positive = fleeing) in m/s" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AngularVelocity_MetaData[] = {
		{ "Category", "Overview" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Angular velocity (perpendicular velocity) in m/s */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Angular velocity (perpendicular velocity) in m/s" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_EntityID;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActorReference;
	static const UECodeGen_Private::FBytePropertyParams NewProp_EntryType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_EntryType;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IconTexture;
	static const UECodeGen_Private::FStrPropertyParams NewProp_EntityName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Distance;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RadialVelocity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AngularVelocity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FOverviewRowData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FOverviewRowData_Statics::NewProp_EntityID = { "EntityID", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOverviewRowData, EntityID), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EntityID_MetaData), NewProp_EntityID_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FOverviewRowData_Statics::NewProp_ActorReference = { "ActorReference", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOverviewRowData, ActorReference), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActorReference_MetaData), NewProp_ActorReference_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FOverviewRowData_Statics::NewProp_EntryType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FOverviewRowData_Statics::NewProp_EntryType = { "EntryType", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOverviewRowData, EntryType), Z_Construct_UEnum_Echoes_EOverviewEntryType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EntryType_MetaData), NewProp_EntryType_MetaData) }; // 2713603577
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FOverviewRowData_Statics::NewProp_IconTexture = { "IconTexture", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOverviewRowData, IconTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IconTexture_MetaData), NewProp_IconTexture_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FOverviewRowData_Statics::NewProp_EntityName = { "EntityName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOverviewRowData, EntityName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EntityName_MetaData), NewProp_EntityName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOverviewRowData_Statics::NewProp_Distance = { "Distance", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOverviewRowData, Distance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Distance_MetaData), NewProp_Distance_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOverviewRowData_Statics::NewProp_RadialVelocity = { "RadialVelocity", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOverviewRowData, RadialVelocity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RadialVelocity_MetaData), NewProp_RadialVelocity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FOverviewRowData_Statics::NewProp_AngularVelocity = { "AngularVelocity", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FOverviewRowData, AngularVelocity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AngularVelocity_MetaData), NewProp_AngularVelocity_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FOverviewRowData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOverviewRowData_Statics::NewProp_EntityID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOverviewRowData_Statics::NewProp_ActorReference,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOverviewRowData_Statics::NewProp_EntryType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOverviewRowData_Statics::NewProp_EntryType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOverviewRowData_Statics::NewProp_IconTexture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOverviewRowData_Statics::NewProp_EntityName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOverviewRowData_Statics::NewProp_Distance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOverviewRowData_Statics::NewProp_RadialVelocity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FOverviewRowData_Statics::NewProp_AngularVelocity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOverviewRowData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FOverviewRowData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
	nullptr,
	&NewStructOps,
	"OverviewRowData",
	Z_Construct_UScriptStruct_FOverviewRowData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOverviewRowData_Statics::PropPointers),
	sizeof(FOverviewRowData),
	alignof(FOverviewRowData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FOverviewRowData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FOverviewRowData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FOverviewRowData()
{
	if (!Z_Registration_Info_UScriptStruct_FOverviewRowData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FOverviewRowData.InnerSingleton, Z_Construct_UScriptStruct_FOverviewRowData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_FOverviewRowData.InnerSingleton;
}
// ********** End ScriptStruct FOverviewRowData ****************************************************

// ********** Begin Class UOverviewRowObject *******************************************************
void UOverviewRowObject::StaticRegisterNativesUOverviewRowObject()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UOverviewRowObject;
UClass* UOverviewRowObject::GetPrivateStaticClass()
{
	using TClass = UOverviewRowObject;
	if (!Z_Registration_Info_UClass_UOverviewRowObject.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("OverviewRowObject"),
			Z_Registration_Info_UClass_UOverviewRowObject.InnerSingleton,
			StaticRegisterNativesUOverviewRowObject,
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
	return Z_Registration_Info_UClass_UOverviewRowObject.InnerSingleton;
}
UClass* Z_Construct_UClass_UOverviewRowObject_NoRegister()
{
	return UOverviewRowObject::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UOverviewRowObject_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UOverviewRowObject\n * \n * Object wrapper for FOverviewRowData to use with UListView\n * Required by UListView to display data\n */" },
#endif
		{ "IncludePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UOverviewRowObject\n\nObject wrapper for FOverviewRowData to use with UListView\nRequired by UListView to display data" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RowData_MetaData[] = {
		{ "Category", "Overview" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The actual row data */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The actual row data" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_RowData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOverviewRowObject>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOverviewRowObject_Statics::NewProp_RowData = { "RowData", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOverviewRowObject, RowData), Z_Construct_UScriptStruct_FOverviewRowData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RowData_MetaData), NewProp_RowData_MetaData) }; // 322341806
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOverviewRowObject_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOverviewRowObject_Statics::NewProp_RowData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOverviewRowObject_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOverviewRowObject_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOverviewRowObject_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOverviewRowObject_Statics::ClassParams = {
	&UOverviewRowObject::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UOverviewRowObject_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UOverviewRowObject_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOverviewRowObject_Statics::Class_MetaDataParams), Z_Construct_UClass_UOverviewRowObject_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOverviewRowObject()
{
	if (!Z_Registration_Info_UClass_UOverviewRowObject.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOverviewRowObject.OuterSingleton, Z_Construct_UClass_UOverviewRowObject_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOverviewRowObject.OuterSingleton;
}
UOverviewRowObject::UOverviewRowObject(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOverviewRowObject);
UOverviewRowObject::~UOverviewRowObject() {}
// ********** End Class UOverviewRowObject *********************************************************

// ********** Begin Class UOverviewRowWidget Function GetRowData ***********************************
struct Z_Construct_UFunction_UOverviewRowWidget_GetRowData_Statics
{
	struct OverviewRowWidget_eventGetRowData_Parms
	{
		FOverviewRowData ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Overview" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get the current row data\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the current row data" },
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
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOverviewRowWidget_GetRowData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000008000582, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OverviewRowWidget_eventGetRowData_Parms, ReturnValue), Z_Construct_UScriptStruct_FOverviewRowData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) }; // 322341806
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOverviewRowWidget_GetRowData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverviewRowWidget_GetRowData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewRowWidget_GetRowData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOverviewRowWidget_GetRowData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UOverviewRowWidget, nullptr, "GetRowData", Z_Construct_UFunction_UOverviewRowWidget_GetRowData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewRowWidget_GetRowData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOverviewRowWidget_GetRowData_Statics::OverviewRowWidget_eventGetRowData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewRowWidget_GetRowData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOverviewRowWidget_GetRowData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UOverviewRowWidget_GetRowData_Statics::OverviewRowWidget_eventGetRowData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOverviewRowWidget_GetRowData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOverviewRowWidget_GetRowData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOverviewRowWidget::execGetRowData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FOverviewRowData*)Z_Param__Result=P_THIS->GetRowData();
	P_NATIVE_END;
}
// ********** End Class UOverviewRowWidget Function GetRowData *************************************

// ********** Begin Class UOverviewRowWidget Function SetRowData ***********************************
struct Z_Construct_UFunction_UOverviewRowWidget_SetRowData_Statics
{
	struct OverviewRowWidget_eventSetRowData_Parms
	{
		FOverviewRowData InRowData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Overview" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Set the row data for this widget\n\x09 * Called by the ListView when displaying this row\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set the row data for this widget\nCalled by the ListView when displaying this row" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InRowData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_InRowData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOverviewRowWidget_SetRowData_Statics::NewProp_InRowData = { "InRowData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OverviewRowWidget_eventSetRowData_Parms, InRowData), Z_Construct_UScriptStruct_FOverviewRowData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InRowData_MetaData), NewProp_InRowData_MetaData) }; // 322341806
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOverviewRowWidget_SetRowData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverviewRowWidget_SetRowData_Statics::NewProp_InRowData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewRowWidget_SetRowData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOverviewRowWidget_SetRowData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UOverviewRowWidget, nullptr, "SetRowData", Z_Construct_UFunction_UOverviewRowWidget_SetRowData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewRowWidget_SetRowData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOverviewRowWidget_SetRowData_Statics::OverviewRowWidget_eventSetRowData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewRowWidget_SetRowData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOverviewRowWidget_SetRowData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UOverviewRowWidget_SetRowData_Statics::OverviewRowWidget_eventSetRowData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOverviewRowWidget_SetRowData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOverviewRowWidget_SetRowData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOverviewRowWidget::execSetRowData)
{
	P_GET_STRUCT_REF(FOverviewRowData,Z_Param_Out_InRowData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetRowData(Z_Param_Out_InRowData);
	P_NATIVE_END;
}
// ********** End Class UOverviewRowWidget Function SetRowData *************************************

// ********** Begin Class UOverviewRowWidget Function UpdateDisplay ********************************
static FName NAME_UOverviewRowWidget_UpdateDisplay = FName(TEXT("UpdateDisplay"));
void UOverviewRowWidget::UpdateDisplay()
{
	UFunction* Func = FindFunctionChecked(NAME_UOverviewRowWidget_UpdateDisplay);
	ProcessEvent(Func,NULL);
}
struct Z_Construct_UFunction_UOverviewRowWidget_UpdateDisplay_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Overview" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Update the visual display with current row data\n\x09 * Override in Blueprint to customize appearance\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Update the visual display with current row data\nOverride in Blueprint to customize appearance" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOverviewRowWidget_UpdateDisplay_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UOverviewRowWidget, nullptr, "UpdateDisplay", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewRowWidget_UpdateDisplay_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOverviewRowWidget_UpdateDisplay_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UOverviewRowWidget_UpdateDisplay()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOverviewRowWidget_UpdateDisplay_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UOverviewRowWidget Function UpdateDisplay **********************************

// ********** Begin Class UOverviewRowWidget *******************************************************
void UOverviewRowWidget::StaticRegisterNativesUOverviewRowWidget()
{
	UClass* Class = UOverviewRowWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetRowData", &UOverviewRowWidget::execGetRowData },
		{ "SetRowData", &UOverviewRowWidget::execSetRowData },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UOverviewRowWidget;
UClass* UOverviewRowWidget::GetPrivateStaticClass()
{
	using TClass = UOverviewRowWidget;
	if (!Z_Registration_Info_UClass_UOverviewRowWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("OverviewRowWidget"),
			Z_Registration_Info_UClass_UOverviewRowWidget.InnerSingleton,
			StaticRegisterNativesUOverviewRowWidget,
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
	return Z_Registration_Info_UClass_UOverviewRowWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UOverviewRowWidget_NoRegister()
{
	return UOverviewRowWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UOverviewRowWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UOverviewRowWidget\n * \n * Individual row widget for the overview list\n * Displays entity information in a single line\n * \n * Implements IUserObjectListEntry for UListView compatibility\n */" },
#endif
		{ "IncludePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UOverviewRowWidget\n\nIndividual row widget for the overview list\nDisplays entity information in a single line\n\nImplements IUserObjectListEntry for UListView compatibility" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RowData_MetaData[] = {
		{ "Category", "Overview" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The row data being displayed */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The row data being displayed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IconImage_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "OverviewRowWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Icon image */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Icon image" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NameText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "OverviewRowWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Entity name text */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Entity name text" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistanceText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "OverviewRowWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Distance text */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Distance text" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VelocityText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "OverviewRowWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Velocity text */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Velocity text" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_RowData;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_IconImage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_NameText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DistanceText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_VelocityText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UOverviewRowWidget_GetRowData, "GetRowData" }, // 3546053998
		{ &Z_Construct_UFunction_UOverviewRowWidget_SetRowData, "SetRowData" }, // 2409829710
		{ &Z_Construct_UFunction_UOverviewRowWidget_UpdateDisplay, "UpdateDisplay" }, // 2686108396
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOverviewRowWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UOverviewRowWidget_Statics::NewProp_RowData = { "RowData", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOverviewRowWidget, RowData), Z_Construct_UScriptStruct_FOverviewRowData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RowData_MetaData), NewProp_RowData_MetaData) }; // 322341806
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOverviewRowWidget_Statics::NewProp_IconImage = { "IconImage", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOverviewRowWidget, IconImage), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IconImage_MetaData), NewProp_IconImage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOverviewRowWidget_Statics::NewProp_NameText = { "NameText", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOverviewRowWidget, NameText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NameText_MetaData), NewProp_NameText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOverviewRowWidget_Statics::NewProp_DistanceText = { "DistanceText", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOverviewRowWidget, DistanceText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistanceText_MetaData), NewProp_DistanceText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOverviewRowWidget_Statics::NewProp_VelocityText = { "VelocityText", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOverviewRowWidget, VelocityText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VelocityText_MetaData), NewProp_VelocityText_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOverviewRowWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOverviewRowWidget_Statics::NewProp_RowData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOverviewRowWidget_Statics::NewProp_IconImage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOverviewRowWidget_Statics::NewProp_NameText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOverviewRowWidget_Statics::NewProp_DistanceText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOverviewRowWidget_Statics::NewProp_VelocityText,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOverviewRowWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOverviewRowWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOverviewRowWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UOverviewRowWidget_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UUserObjectListEntry_NoRegister, (int32)VTABLE_OFFSET(UOverviewRowWidget, IUserObjectListEntry), false },  // 1900202470
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOverviewRowWidget_Statics::ClassParams = {
	&UOverviewRowWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UOverviewRowWidget_Statics::PropPointers,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UOverviewRowWidget_Statics::PropPointers),
	UE_ARRAY_COUNT(InterfaceParams),
	0x00B010A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOverviewRowWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UOverviewRowWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOverviewRowWidget()
{
	if (!Z_Registration_Info_UClass_UOverviewRowWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOverviewRowWidget.OuterSingleton, Z_Construct_UClass_UOverviewRowWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOverviewRowWidget.OuterSingleton;
}
UOverviewRowWidget::UOverviewRowWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOverviewRowWidget);
UOverviewRowWidget::~UOverviewRowWidget() {}
// ********** End Class UOverviewRowWidget *********************************************************

// ********** Begin Delegate FOnOverviewSelectionChanged *******************************************
struct Z_Construct_UDelegateFunction_Echoes_OnOverviewSelectionChanged__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnOverviewSelectionChanged_Parms
	{
		FOverviewRowData SelectedRow;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Delegate for overview selection changed\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegate for overview selection changed" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedRow_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_SelectedRow;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_Echoes_OnOverviewSelectionChanged__DelegateSignature_Statics::NewProp_SelectedRow = { "SelectedRow", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnOverviewSelectionChanged_Parms, SelectedRow), Z_Construct_UScriptStruct_FOverviewRowData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedRow_MetaData), NewProp_SelectedRow_MetaData) }; // 322341806
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnOverviewSelectionChanged__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnOverviewSelectionChanged__DelegateSignature_Statics::NewProp_SelectedRow,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnOverviewSelectionChanged__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnOverviewSelectionChanged__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnOverviewSelectionChanged__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnOverviewSelectionChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnOverviewSelectionChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnOverviewSelectionChanged__DelegateSignature_Statics::_Script_Echoes_eventOnOverviewSelectionChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnOverviewSelectionChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnOverviewSelectionChanged__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnOverviewSelectionChanged__DelegateSignature_Statics::_Script_Echoes_eventOnOverviewSelectionChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnOverviewSelectionChanged__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnOverviewSelectionChanged__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnOverviewSelectionChanged_DelegateWrapper(const FMulticastScriptDelegate& OnOverviewSelectionChanged, FOverviewRowData const& SelectedRow)
{
	struct _Script_Echoes_eventOnOverviewSelectionChanged_Parms
	{
		FOverviewRowData SelectedRow;
	};
	_Script_Echoes_eventOnOverviewSelectionChanged_Parms Parms;
	Parms.SelectedRow=SelectedRow;
	OnOverviewSelectionChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnOverviewSelectionChanged *********************************************

// ********** Begin Delegate FOnOverviewItemDoubleClicked ******************************************
struct Z_Construct_UDelegateFunction_Echoes_OnOverviewItemDoubleClicked__DelegateSignature_Statics
{
	struct _Script_Echoes_eventOnOverviewItemDoubleClicked_Parms
	{
		AActor* SelectedActor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Delegate for overview item double-clicked\n */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegate for overview item double-clicked" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectedActor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_Echoes_OnOverviewItemDoubleClicked__DelegateSignature_Statics::NewProp_SelectedActor = { "SelectedActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_Echoes_eventOnOverviewItemDoubleClicked_Parms, SelectedActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_Echoes_OnOverviewItemDoubleClicked__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_Echoes_OnOverviewItemDoubleClicked__DelegateSignature_Statics::NewProp_SelectedActor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnOverviewItemDoubleClicked__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_Echoes_OnOverviewItemDoubleClicked__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_Echoes, nullptr, "OnOverviewItemDoubleClicked__DelegateSignature", Z_Construct_UDelegateFunction_Echoes_OnOverviewItemDoubleClicked__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnOverviewItemDoubleClicked__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_Echoes_OnOverviewItemDoubleClicked__DelegateSignature_Statics::_Script_Echoes_eventOnOverviewItemDoubleClicked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_Echoes_OnOverviewItemDoubleClicked__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_Echoes_OnOverviewItemDoubleClicked__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_Echoes_OnOverviewItemDoubleClicked__DelegateSignature_Statics::_Script_Echoes_eventOnOverviewItemDoubleClicked_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_Echoes_OnOverviewItemDoubleClicked__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_Echoes_OnOverviewItemDoubleClicked__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnOverviewItemDoubleClicked_DelegateWrapper(const FMulticastScriptDelegate& OnOverviewItemDoubleClicked, AActor* SelectedActor)
{
	struct _Script_Echoes_eventOnOverviewItemDoubleClicked_Parms
	{
		AActor* SelectedActor;
	};
	_Script_Echoes_eventOnOverviewItemDoubleClicked_Parms Parms;
	Parms.SelectedActor=SelectedActor;
	OnOverviewItemDoubleClicked.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnOverviewItemDoubleClicked ********************************************

// ********** Begin Class UOverviewWidget Function AddEntry ****************************************
struct Z_Construct_UFunction_UOverviewWidget_AddEntry_Statics
{
	struct OverviewWidget_eventAddEntry_Parms
	{
		FOverviewRowData RowData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Overview" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Add an entry to the overview\n\x09 * \n\x09 * @param RowData The data for the new entry\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Add an entry to the overview\n\n@param RowData The data for the new entry" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RowData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_RowData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOverviewWidget_AddEntry_Statics::NewProp_RowData = { "RowData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OverviewWidget_eventAddEntry_Parms, RowData), Z_Construct_UScriptStruct_FOverviewRowData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RowData_MetaData), NewProp_RowData_MetaData) }; // 322341806
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOverviewWidget_AddEntry_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverviewWidget_AddEntry_Statics::NewProp_RowData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_AddEntry_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOverviewWidget_AddEntry_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UOverviewWidget, nullptr, "AddEntry", Z_Construct_UFunction_UOverviewWidget_AddEntry_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_AddEntry_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOverviewWidget_AddEntry_Statics::OverviewWidget_eventAddEntry_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_AddEntry_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOverviewWidget_AddEntry_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UOverviewWidget_AddEntry_Statics::OverviewWidget_eventAddEntry_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOverviewWidget_AddEntry()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOverviewWidget_AddEntry_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOverviewWidget::execAddEntry)
{
	P_GET_STRUCT_REF(FOverviewRowData,Z_Param_Out_RowData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddEntry(Z_Param_Out_RowData);
	P_NATIVE_END;
}
// ********** End Class UOverviewWidget Function AddEntry ******************************************

// ********** Begin Class UOverviewWidget Function ClearAll ****************************************
struct Z_Construct_UFunction_UOverviewWidget_ClearAll_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Overview" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Clear all entries\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Clear all entries" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOverviewWidget_ClearAll_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UOverviewWidget, nullptr, "ClearAll", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_ClearAll_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOverviewWidget_ClearAll_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UOverviewWidget_ClearAll()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOverviewWidget_ClearAll_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOverviewWidget::execClearAll)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearAll();
	P_NATIVE_END;
}
// ********** End Class UOverviewWidget Function ClearAll ******************************************

// ********** Begin Class UOverviewWidget Function ClientOnly_RefreshEntries ***********************
struct Z_Construct_UFunction_UOverviewWidget_ClientOnly_RefreshEntries_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Overview" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Refresh all entries (recalculate distances)\n\x09 * Called periodically by timer\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Refresh all entries (recalculate distances)\nCalled periodically by timer" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOverviewWidget_ClientOnly_RefreshEntries_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UOverviewWidget, nullptr, "ClientOnly_RefreshEntries", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_ClientOnly_RefreshEntries_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOverviewWidget_ClientOnly_RefreshEntries_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UOverviewWidget_ClientOnly_RefreshEntries()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOverviewWidget_ClientOnly_RefreshEntries_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOverviewWidget::execClientOnly_RefreshEntries)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_RefreshEntries();
	P_NATIVE_END;
}
// ********** End Class UOverviewWidget Function ClientOnly_RefreshEntries *************************

// ********** Begin Class UOverviewWidget Function ClientOnly_SortOverview *************************
struct Z_Construct_UFunction_UOverviewWidget_ClientOnly_SortOverview_Statics
{
	struct OverviewWidget_eventClientOnly_SortOverview_Parms
	{
		EOverviewSortBy SortBy;
		bool bDescending;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Overview" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * CLIENT ONLY: Sort the overview by specified criteria\n\x09 * \n\x09 * @param SortBy How to sort the entries\n\x09 * @param bDescending Sort in descending order (default: ascending)\n\x09 */" },
#endif
		{ "CPP_Default_bDescending", "false" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "CLIENT ONLY: Sort the overview by specified criteria\n\n@param SortBy How to sort the entries\n@param bDescending Sort in descending order (default: ascending)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_SortBy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SortBy;
	static void NewProp_bDescending_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDescending;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOverviewWidget_ClientOnly_SortOverview_Statics::NewProp_SortBy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOverviewWidget_ClientOnly_SortOverview_Statics::NewProp_SortBy = { "SortBy", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OverviewWidget_eventClientOnly_SortOverview_Parms, SortBy), Z_Construct_UEnum_Echoes_EOverviewSortBy, METADATA_PARAMS(0, nullptr) }; // 1401831041
void Z_Construct_UFunction_UOverviewWidget_ClientOnly_SortOverview_Statics::NewProp_bDescending_SetBit(void* Obj)
{
	((OverviewWidget_eventClientOnly_SortOverview_Parms*)Obj)->bDescending = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOverviewWidget_ClientOnly_SortOverview_Statics::NewProp_bDescending = { "bDescending", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OverviewWidget_eventClientOnly_SortOverview_Parms), &Z_Construct_UFunction_UOverviewWidget_ClientOnly_SortOverview_Statics::NewProp_bDescending_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOverviewWidget_ClientOnly_SortOverview_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverviewWidget_ClientOnly_SortOverview_Statics::NewProp_SortBy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverviewWidget_ClientOnly_SortOverview_Statics::NewProp_SortBy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverviewWidget_ClientOnly_SortOverview_Statics::NewProp_bDescending,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_ClientOnly_SortOverview_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOverviewWidget_ClientOnly_SortOverview_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UOverviewWidget, nullptr, "ClientOnly_SortOverview", Z_Construct_UFunction_UOverviewWidget_ClientOnly_SortOverview_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_ClientOnly_SortOverview_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOverviewWidget_ClientOnly_SortOverview_Statics::OverviewWidget_eventClientOnly_SortOverview_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_ClientOnly_SortOverview_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOverviewWidget_ClientOnly_SortOverview_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UOverviewWidget_ClientOnly_SortOverview_Statics::OverviewWidget_eventClientOnly_SortOverview_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOverviewWidget_ClientOnly_SortOverview()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOverviewWidget_ClientOnly_SortOverview_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOverviewWidget::execClientOnly_SortOverview)
{
	P_GET_ENUM(EOverviewSortBy,Z_Param_SortBy);
	P_GET_UBOOL(Z_Param_bDescending);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClientOnly_SortOverview(EOverviewSortBy(Z_Param_SortBy),Z_Param_bDescending);
	P_NATIVE_END;
}
// ********** End Class UOverviewWidget Function ClientOnly_SortOverview ***************************

// ********** Begin Class UOverviewWidget Function Common_FormatDistance ***************************
struct Z_Construct_UFunction_UOverviewWidget_Common_FormatDistance_Statics
{
	struct OverviewWidget_eventCommon_FormatDistance_Parms
	{
		float DistanceInCm;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Overview" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * COMMON (Pure): Format distance from cm to human-readable string\n\x09 * \n\x09 * @param DistanceInCm Distance in centimeters\n\x09 * @return Formatted string (e.g., \"450 m\", \"2.5 km\", \"0.5 AU\")\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "COMMON (Pure): Format distance from cm to human-readable string\n\n@param DistanceInCm Distance in centimeters\n@return Formatted string (e.g., \"450 m\", \"2.5 km\", \"0.5 AU\")" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DistanceInCm;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOverviewWidget_Common_FormatDistance_Statics::NewProp_DistanceInCm = { "DistanceInCm", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OverviewWidget_eventCommon_FormatDistance_Parms, DistanceInCm), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOverviewWidget_Common_FormatDistance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OverviewWidget_eventCommon_FormatDistance_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOverviewWidget_Common_FormatDistance_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverviewWidget_Common_FormatDistance_Statics::NewProp_DistanceInCm,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverviewWidget_Common_FormatDistance_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_Common_FormatDistance_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOverviewWidget_Common_FormatDistance_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UOverviewWidget, nullptr, "Common_FormatDistance", Z_Construct_UFunction_UOverviewWidget_Common_FormatDistance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_Common_FormatDistance_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOverviewWidget_Common_FormatDistance_Statics::OverviewWidget_eventCommon_FormatDistance_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_Common_FormatDistance_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOverviewWidget_Common_FormatDistance_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UOverviewWidget_Common_FormatDistance_Statics::OverviewWidget_eventCommon_FormatDistance_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOverviewWidget_Common_FormatDistance()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOverviewWidget_Common_FormatDistance_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOverviewWidget::execCommon_FormatDistance)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_DistanceInCm);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UOverviewWidget::Common_FormatDistance(Z_Param_DistanceInCm);
	P_NATIVE_END;
}
// ********** End Class UOverviewWidget Function Common_FormatDistance *****************************

// ********** Begin Class UOverviewWidget Function Common_FormatVelocity ***************************
struct Z_Construct_UFunction_UOverviewWidget_Common_FormatVelocity_Statics
{
	struct OverviewWidget_eventCommon_FormatVelocity_Parms
	{
		float VelocityInMps;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Overview" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * COMMON (Pure): Format velocity to human-readable string\n\x09 * \n\x09 * @param VelocityInMps Velocity in meters per second\n\x09 * @return Formatted string (e.g., \"125 m/s\", \"approaching\", \"fleeing\")\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "COMMON (Pure): Format velocity to human-readable string\n\n@param VelocityInMps Velocity in meters per second\n@return Formatted string (e.g., \"125 m/s\", \"approaching\", \"fleeing\")" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_VelocityInMps;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UOverviewWidget_Common_FormatVelocity_Statics::NewProp_VelocityInMps = { "VelocityInMps", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OverviewWidget_eventCommon_FormatVelocity_Parms, VelocityInMps), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UOverviewWidget_Common_FormatVelocity_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OverviewWidget_eventCommon_FormatVelocity_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOverviewWidget_Common_FormatVelocity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverviewWidget_Common_FormatVelocity_Statics::NewProp_VelocityInMps,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverviewWidget_Common_FormatVelocity_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_Common_FormatVelocity_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOverviewWidget_Common_FormatVelocity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UOverviewWidget, nullptr, "Common_FormatVelocity", Z_Construct_UFunction_UOverviewWidget_Common_FormatVelocity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_Common_FormatVelocity_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOverviewWidget_Common_FormatVelocity_Statics::OverviewWidget_eventCommon_FormatVelocity_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_Common_FormatVelocity_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOverviewWidget_Common_FormatVelocity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UOverviewWidget_Common_FormatVelocity_Statics::OverviewWidget_eventCommon_FormatVelocity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOverviewWidget_Common_FormatVelocity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOverviewWidget_Common_FormatVelocity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOverviewWidget::execCommon_FormatVelocity)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_VelocityInMps);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UOverviewWidget::Common_FormatVelocity(Z_Param_VelocityInMps);
	P_NATIVE_END;
}
// ********** End Class UOverviewWidget Function Common_FormatVelocity *****************************

// ********** Begin Class UOverviewWidget Function GetSelectedEntry ********************************
struct Z_Construct_UFunction_UOverviewWidget_GetSelectedEntry_Statics
{
	struct OverviewWidget_eventGetSelectedEntry_Parms
	{
		FOverviewRowData OutRowData;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Overview" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Get currently selected entry (if any)\n\x09 * \n\x09 * @param OutRowData The selected row data\n\x09 * @return True if an entry is selected\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get currently selected entry (if any)\n\n@param OutRowData The selected row data\n@return True if an entry is selected" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutRowData;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOverviewWidget_GetSelectedEntry_Statics::NewProp_OutRowData = { "OutRowData", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OverviewWidget_eventGetSelectedEntry_Parms, OutRowData), Z_Construct_UScriptStruct_FOverviewRowData, METADATA_PARAMS(0, nullptr) }; // 322341806
void Z_Construct_UFunction_UOverviewWidget_GetSelectedEntry_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((OverviewWidget_eventGetSelectedEntry_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOverviewWidget_GetSelectedEntry_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(OverviewWidget_eventGetSelectedEntry_Parms), &Z_Construct_UFunction_UOverviewWidget_GetSelectedEntry_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOverviewWidget_GetSelectedEntry_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverviewWidget_GetSelectedEntry_Statics::NewProp_OutRowData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverviewWidget_GetSelectedEntry_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_GetSelectedEntry_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOverviewWidget_GetSelectedEntry_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UOverviewWidget, nullptr, "GetSelectedEntry", Z_Construct_UFunction_UOverviewWidget_GetSelectedEntry_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_GetSelectedEntry_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOverviewWidget_GetSelectedEntry_Statics::OverviewWidget_eventGetSelectedEntry_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_GetSelectedEntry_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOverviewWidget_GetSelectedEntry_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UOverviewWidget_GetSelectedEntry_Statics::OverviewWidget_eventGetSelectedEntry_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOverviewWidget_GetSelectedEntry()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOverviewWidget_GetSelectedEntry_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOverviewWidget::execGetSelectedEntry)
{
	P_GET_STRUCT_REF(FOverviewRowData,Z_Param_Out_OutRowData);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetSelectedEntry(Z_Param_Out_OutRowData);
	P_NATIVE_END;
}
// ********** End Class UOverviewWidget Function GetSelectedEntry **********************************

// ********** Begin Class UOverviewWidget Function HandleItemDoubleClicked *************************
struct Z_Construct_UFunction_UOverviewWidget_HandleItemDoubleClicked_Statics
{
	struct OverviewWidget_eventHandleItemDoubleClicked_Parms
	{
		UObject* Item;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Handle list view item double-clicked\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle list view item double-clicked" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Item;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOverviewWidget_HandleItemDoubleClicked_Statics::NewProp_Item = { "Item", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OverviewWidget_eventHandleItemDoubleClicked_Parms, Item), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOverviewWidget_HandleItemDoubleClicked_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverviewWidget_HandleItemDoubleClicked_Statics::NewProp_Item,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_HandleItemDoubleClicked_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOverviewWidget_HandleItemDoubleClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UOverviewWidget, nullptr, "HandleItemDoubleClicked", Z_Construct_UFunction_UOverviewWidget_HandleItemDoubleClicked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_HandleItemDoubleClicked_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOverviewWidget_HandleItemDoubleClicked_Statics::OverviewWidget_eventHandleItemDoubleClicked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_HandleItemDoubleClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOverviewWidget_HandleItemDoubleClicked_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UOverviewWidget_HandleItemDoubleClicked_Statics::OverviewWidget_eventHandleItemDoubleClicked_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOverviewWidget_HandleItemDoubleClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOverviewWidget_HandleItemDoubleClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOverviewWidget::execHandleItemDoubleClicked)
{
	P_GET_OBJECT(UObject,Z_Param_Item);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleItemDoubleClicked(Z_Param_Item);
	P_NATIVE_END;
}
// ********** End Class UOverviewWidget Function HandleItemDoubleClicked ***************************

// ********** Begin Class UOverviewWidget Function HandleSelectionChanged **************************
struct Z_Construct_UFunction_UOverviewWidget_HandleSelectionChanged_Statics
{
	struct OverviewWidget_eventHandleSelectionChanged_Parms
	{
		UObject* Item;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Handle list view selection changed\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handle list view selection changed" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Item;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOverviewWidget_HandleSelectionChanged_Statics::NewProp_Item = { "Item", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OverviewWidget_eventHandleSelectionChanged_Parms, Item), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOverviewWidget_HandleSelectionChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverviewWidget_HandleSelectionChanged_Statics::NewProp_Item,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_HandleSelectionChanged_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOverviewWidget_HandleSelectionChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UOverviewWidget, nullptr, "HandleSelectionChanged", Z_Construct_UFunction_UOverviewWidget_HandleSelectionChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_HandleSelectionChanged_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOverviewWidget_HandleSelectionChanged_Statics::OverviewWidget_eventHandleSelectionChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_HandleSelectionChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOverviewWidget_HandleSelectionChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UOverviewWidget_HandleSelectionChanged_Statics::OverviewWidget_eventHandleSelectionChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOverviewWidget_HandleSelectionChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOverviewWidget_HandleSelectionChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOverviewWidget::execHandleSelectionChanged)
{
	P_GET_OBJECT(UObject,Z_Param_Item);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSelectionChanged(Z_Param_Item);
	P_NATIVE_END;
}
// ********** End Class UOverviewWidget Function HandleSelectionChanged ****************************

// ********** Begin Class UOverviewWidget Function HandleSortDistanceClicked ***********************
struct Z_Construct_UFunction_UOverviewWidget_HandleSortDistanceClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Sort button clicked handlers\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sort button clicked handlers" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOverviewWidget_HandleSortDistanceClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UOverviewWidget, nullptr, "HandleSortDistanceClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_HandleSortDistanceClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOverviewWidget_HandleSortDistanceClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UOverviewWidget_HandleSortDistanceClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOverviewWidget_HandleSortDistanceClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOverviewWidget::execHandleSortDistanceClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSortDistanceClicked();
	P_NATIVE_END;
}
// ********** End Class UOverviewWidget Function HandleSortDistanceClicked *************************

// ********** Begin Class UOverviewWidget Function HandleSortNameClicked ***************************
struct Z_Construct_UFunction_UOverviewWidget_HandleSortNameClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOverviewWidget_HandleSortNameClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UOverviewWidget, nullptr, "HandleSortNameClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_HandleSortNameClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOverviewWidget_HandleSortNameClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UOverviewWidget_HandleSortNameClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOverviewWidget_HandleSortNameClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOverviewWidget::execHandleSortNameClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSortNameClicked();
	P_NATIVE_END;
}
// ********** End Class UOverviewWidget Function HandleSortNameClicked *****************************

// ********** Begin Class UOverviewWidget Function HandleSortTypeClicked ***************************
struct Z_Construct_UFunction_UOverviewWidget_HandleSortTypeClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOverviewWidget_HandleSortTypeClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UOverviewWidget, nullptr, "HandleSortTypeClicked", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_HandleSortTypeClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOverviewWidget_HandleSortTypeClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UOverviewWidget_HandleSortTypeClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOverviewWidget_HandleSortTypeClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOverviewWidget::execHandleSortTypeClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleSortTypeClicked();
	P_NATIVE_END;
}
// ********** End Class UOverviewWidget Function HandleSortTypeClicked *****************************

// ********** Begin Class UOverviewWidget Function RemoveEntry *************************************
struct Z_Construct_UFunction_UOverviewWidget_RemoveEntry_Statics
{
	struct OverviewWidget_eventRemoveEntry_Parms
	{
		int32 EntityID;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Overview" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Remove an entry by entity ID\n\x09 * \n\x09 * @param EntityID The ID of the entity to remove\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Remove an entry by entity ID\n\n@param EntityID The ID of the entity to remove" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_EntityID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOverviewWidget_RemoveEntry_Statics::NewProp_EntityID = { "EntityID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OverviewWidget_eventRemoveEntry_Parms, EntityID), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOverviewWidget_RemoveEntry_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverviewWidget_RemoveEntry_Statics::NewProp_EntityID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_RemoveEntry_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOverviewWidget_RemoveEntry_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UOverviewWidget, nullptr, "RemoveEntry", Z_Construct_UFunction_UOverviewWidget_RemoveEntry_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_RemoveEntry_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOverviewWidget_RemoveEntry_Statics::OverviewWidget_eventRemoveEntry_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_RemoveEntry_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOverviewWidget_RemoveEntry_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UOverviewWidget_RemoveEntry_Statics::OverviewWidget_eventRemoveEntry_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOverviewWidget_RemoveEntry()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOverviewWidget_RemoveEntry_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOverviewWidget::execRemoveEntry)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_EntityID);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RemoveEntry(Z_Param_EntityID);
	P_NATIVE_END;
}
// ********** End Class UOverviewWidget Function RemoveEntry ***************************************

// ********** Begin Class UOverviewWidget Function SetTypeFilter ***********************************
struct Z_Construct_UFunction_UOverviewWidget_SetTypeFilter_Statics
{
	struct OverviewWidget_eventSetTypeFilter_Parms
	{
		TArray<EOverviewEntryType> AllowedTypes;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Overview" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Set filter for entity types to show\n\x09 * \n\x09 * @param AllowedTypes Array of types to display (empty = show all)\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set filter for entity types to show\n\n@param AllowedTypes Array of types to display (empty = show all)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AllowedTypes_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_AllowedTypes_Inner_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_AllowedTypes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_AllowedTypes;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UOverviewWidget_SetTypeFilter_Statics::NewProp_AllowedTypes_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UOverviewWidget_SetTypeFilter_Statics::NewProp_AllowedTypes_Inner = { "AllowedTypes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_Echoes_EOverviewEntryType, METADATA_PARAMS(0, nullptr) }; // 2713603577
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UOverviewWidget_SetTypeFilter_Statics::NewProp_AllowedTypes = { "AllowedTypes", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OverviewWidget_eventSetTypeFilter_Parms, AllowedTypes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AllowedTypes_MetaData), NewProp_AllowedTypes_MetaData) }; // 2713603577
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOverviewWidget_SetTypeFilter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverviewWidget_SetTypeFilter_Statics::NewProp_AllowedTypes_Inner_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverviewWidget_SetTypeFilter_Statics::NewProp_AllowedTypes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverviewWidget_SetTypeFilter_Statics::NewProp_AllowedTypes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_SetTypeFilter_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOverviewWidget_SetTypeFilter_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UOverviewWidget, nullptr, "SetTypeFilter", Z_Construct_UFunction_UOverviewWidget_SetTypeFilter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_SetTypeFilter_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOverviewWidget_SetTypeFilter_Statics::OverviewWidget_eventSetTypeFilter_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_SetTypeFilter_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOverviewWidget_SetTypeFilter_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UOverviewWidget_SetTypeFilter_Statics::OverviewWidget_eventSetTypeFilter_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOverviewWidget_SetTypeFilter()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOverviewWidget_SetTypeFilter_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOverviewWidget::execSetTypeFilter)
{
	P_GET_TARRAY_REF(EOverviewEntryType,Z_Param_Out_AllowedTypes);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTypeFilter(Z_Param_Out_AllowedTypes);
	P_NATIVE_END;
}
// ********** End Class UOverviewWidget Function SetTypeFilter *************************************

// ********** Begin Class UOverviewWidget Function UpdateEntry *************************************
struct Z_Construct_UFunction_UOverviewWidget_UpdateEntry_Statics
{
	struct OverviewWidget_eventUpdateEntry_Parms
	{
		int32 EntityID;
		FOverviewRowData NewRowData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Overview" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * Update an existing entry\n\x09 * \n\x09 * @param EntityID The ID of the entity to update\n\x09 * @param NewRowData The new data for the entry\n\x09 */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Update an existing entry\n\n@param EntityID The ID of the entity to update\n@param NewRowData The new data for the entry" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewRowData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_EntityID;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NewRowData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOverviewWidget_UpdateEntry_Statics::NewProp_EntityID = { "EntityID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OverviewWidget_eventUpdateEntry_Parms, EntityID), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOverviewWidget_UpdateEntry_Statics::NewProp_NewRowData = { "NewRowData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(OverviewWidget_eventUpdateEntry_Parms, NewRowData), Z_Construct_UScriptStruct_FOverviewRowData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewRowData_MetaData), NewProp_NewRowData_MetaData) }; // 322341806
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOverviewWidget_UpdateEntry_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverviewWidget_UpdateEntry_Statics::NewProp_EntityID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverviewWidget_UpdateEntry_Statics::NewProp_NewRowData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_UpdateEntry_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UOverviewWidget_UpdateEntry_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UOverviewWidget, nullptr, "UpdateEntry", Z_Construct_UFunction_UOverviewWidget_UpdateEntry_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_UpdateEntry_Statics::PropPointers), sizeof(Z_Construct_UFunction_UOverviewWidget_UpdateEntry_Statics::OverviewWidget_eventUpdateEntry_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UOverviewWidget_UpdateEntry_Statics::Function_MetaDataParams), Z_Construct_UFunction_UOverviewWidget_UpdateEntry_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UOverviewWidget_UpdateEntry_Statics::OverviewWidget_eventUpdateEntry_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UOverviewWidget_UpdateEntry()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UOverviewWidget_UpdateEntry_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UOverviewWidget::execUpdateEntry)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_EntityID);
	P_GET_STRUCT_REF(FOverviewRowData,Z_Param_Out_NewRowData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->UpdateEntry(Z_Param_EntityID,Z_Param_Out_NewRowData);
	P_NATIVE_END;
}
// ********** End Class UOverviewWidget Function UpdateEntry ***************************************

// ********** Begin Class UOverviewWidget **********************************************************
void UOverviewWidget::StaticRegisterNativesUOverviewWidget()
{
	UClass* Class = UOverviewWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AddEntry", &UOverviewWidget::execAddEntry },
		{ "ClearAll", &UOverviewWidget::execClearAll },
		{ "ClientOnly_RefreshEntries", &UOverviewWidget::execClientOnly_RefreshEntries },
		{ "ClientOnly_SortOverview", &UOverviewWidget::execClientOnly_SortOverview },
		{ "Common_FormatDistance", &UOverviewWidget::execCommon_FormatDistance },
		{ "Common_FormatVelocity", &UOverviewWidget::execCommon_FormatVelocity },
		{ "GetSelectedEntry", &UOverviewWidget::execGetSelectedEntry },
		{ "HandleItemDoubleClicked", &UOverviewWidget::execHandleItemDoubleClicked },
		{ "HandleSelectionChanged", &UOverviewWidget::execHandleSelectionChanged },
		{ "HandleSortDistanceClicked", &UOverviewWidget::execHandleSortDistanceClicked },
		{ "HandleSortNameClicked", &UOverviewWidget::execHandleSortNameClicked },
		{ "HandleSortTypeClicked", &UOverviewWidget::execHandleSortTypeClicked },
		{ "RemoveEntry", &UOverviewWidget::execRemoveEntry },
		{ "SetTypeFilter", &UOverviewWidget::execSetTypeFilter },
		{ "UpdateEntry", &UOverviewWidget::execUpdateEntry },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_UOverviewWidget;
UClass* UOverviewWidget::GetPrivateStaticClass()
{
	using TClass = UOverviewWidget;
	if (!Z_Registration_Info_UClass_UOverviewWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("OverviewWidget"),
			Z_Registration_Info_UClass_UOverviewWidget.InnerSingleton,
			StaticRegisterNativesUOverviewWidget,
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
	return Z_Registration_Info_UClass_UOverviewWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UOverviewWidget_NoRegister()
{
	return UOverviewWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UOverviewWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * UOverviewWidget\n * \n * EVE-like overview panel for space navigation\n * Displays list of entities in the current system\n * \n * Features:\n * - UListView for efficient display of large entity counts\n * - Sortable by distance, name, type, velocity\n * - Filterable by entity type\n * - Event-driven updates (no Tick)\n * - Double-click to lock target\n * \n * Architecture:\n * - Uses UListView for virtualization and performance\n * - Data stored as FOverviewRowData structs\n * - Updates via event dispatchers, not Tick\n * \n * Optimization:\n * - ListView virtualization: Only renders visible rows\n * - Distance updates: Batched, not per-frame\n * - Sorting: Only when requested or data changes\n * \n * Usage:\n * // Add entry to overview\n * FOverviewRowData NewEntry;\n * NewEntry.EntityName = TEXT(\"Hostile Frigate\");\n * NewEntry.Distance = 25000.0f * 100.0f; // 25km in cm\n * OverviewWidget->AddEntry(NewEntry);\n * \n * // Sort by distance\n * OverviewWidget->SortOverview(EOverviewSortBy::Distance);\n */" },
#endif
		{ "IncludePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UOverviewWidget\n\nEVE-like overview panel for space navigation\nDisplays list of entities in the current system\n\nFeatures:\n- UListView for efficient display of large entity counts\n- Sortable by distance, name, type, velocity\n- Filterable by entity type\n- Event-driven updates (no Tick)\n- Double-click to lock target\n\nArchitecture:\n- Uses UListView for virtualization and performance\n- Data stored as FOverviewRowData structs\n- Updates via event dispatchers, not Tick\n\nOptimization:\n- ListView virtualization: Only renders visible rows\n- Distance updates: Batched, not per-frame\n- Sorting: Only when requested or data changes\n\nUsage:\n// Add entry to overview\nFOverviewRowData NewEntry;\nNewEntry.EntityName = TEXT(\"Hostile Frigate\");\nNewEntry.Distance = 25000.0f * 100.0f; // 25km in cm\nOverviewWidget->AddEntry(NewEntry);\n\n// Sort by distance\nOverviewWidget->SortOverview(EOverviewSortBy::Distance);" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnSelectionChanged_MetaData[] = {
		{ "Category", "Overview Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when overview selection changes */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when overview selection changes" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnItemDoubleClicked_MetaData[] = {
		{ "Category", "Overview Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Fired when an item is double-clicked */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Fired when an item is double-clicked" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverviewListView_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "OverviewWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The list view widget */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The list view widget" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HeaderText_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "OverviewWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Header text showing entry count */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Header text showing entry count" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SortDistanceButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "OverviewWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sort by distance button */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sort by distance button" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SortNameButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "OverviewWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sort by name button */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sort by name button" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SortTypeButton_MetaData[] = {
		{ "BindWidgetOptional", "" },
		{ "Category", "OverviewWidget" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Sort by type button */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sort by type button" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UpdateInterval_MetaData[] = {
		{ "Category", "Overview Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Update interval for distance recalculation (seconds) */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Update interval for distance recalculation (seconds)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxDisplayedEntries_MetaData[] = {
		{ "Category", "Overview Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Maximum number of entries to display (0 = unlimited) */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Maximum number of entries to display (0 = unlimited)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EntryMap_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Map of entity ID to list object for fast lookup */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Map of entity ID to list object for fast lookup" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentSortBy_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current sort criteria */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current sort criteria" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCurrentSortDescending_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Current sort direction */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Current sort direction" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TypeFilter_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Allowed entity types (empty = all allowed) */" },
#endif
		{ "ModuleRelativePath", "UI/Widgets/SpaceHUD/OverviewWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Allowed entity types (empty = all allowed)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSelectionChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnItemDoubleClicked;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OverviewListView;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HeaderText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SortDistanceButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SortNameButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SortTypeButton;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_UpdateInterval;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxDisplayedEntries;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_EntryMap_ValueProp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_EntryMap_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_EntryMap;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentSortBy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentSortBy;
	static void NewProp_bCurrentSortDescending_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCurrentSortDescending;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TypeFilter_Inner_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TypeFilter_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_TypeFilter;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UOverviewWidget_AddEntry, "AddEntry" }, // 324100179
		{ &Z_Construct_UFunction_UOverviewWidget_ClearAll, "ClearAll" }, // 2254023170
		{ &Z_Construct_UFunction_UOverviewWidget_ClientOnly_RefreshEntries, "ClientOnly_RefreshEntries" }, // 3541877538
		{ &Z_Construct_UFunction_UOverviewWidget_ClientOnly_SortOverview, "ClientOnly_SortOverview" }, // 3887971966
		{ &Z_Construct_UFunction_UOverviewWidget_Common_FormatDistance, "Common_FormatDistance" }, // 418323772
		{ &Z_Construct_UFunction_UOverviewWidget_Common_FormatVelocity, "Common_FormatVelocity" }, // 2820338163
		{ &Z_Construct_UFunction_UOverviewWidget_GetSelectedEntry, "GetSelectedEntry" }, // 3526091928
		{ &Z_Construct_UFunction_UOverviewWidget_HandleItemDoubleClicked, "HandleItemDoubleClicked" }, // 4005306508
		{ &Z_Construct_UFunction_UOverviewWidget_HandleSelectionChanged, "HandleSelectionChanged" }, // 916123038
		{ &Z_Construct_UFunction_UOverviewWidget_HandleSortDistanceClicked, "HandleSortDistanceClicked" }, // 119915896
		{ &Z_Construct_UFunction_UOverviewWidget_HandleSortNameClicked, "HandleSortNameClicked" }, // 1649036021
		{ &Z_Construct_UFunction_UOverviewWidget_HandleSortTypeClicked, "HandleSortTypeClicked" }, // 1099123986
		{ &Z_Construct_UFunction_UOverviewWidget_RemoveEntry, "RemoveEntry" }, // 6327601
		{ &Z_Construct_UFunction_UOverviewWidget_SetTypeFilter, "SetTypeFilter" }, // 3045880763
		{ &Z_Construct_UFunction_UOverviewWidget_UpdateEntry, "UpdateEntry" }, // 2759809576
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOverviewWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UOverviewWidget_Statics::NewProp_OnSelectionChanged = { "OnSelectionChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOverviewWidget, OnSelectionChanged), Z_Construct_UDelegateFunction_Echoes_OnOverviewSelectionChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnSelectionChanged_MetaData), NewProp_OnSelectionChanged_MetaData) }; // 2420806820
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UOverviewWidget_Statics::NewProp_OnItemDoubleClicked = { "OnItemDoubleClicked", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOverviewWidget, OnItemDoubleClicked), Z_Construct_UDelegateFunction_Echoes_OnOverviewItemDoubleClicked__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnItemDoubleClicked_MetaData), NewProp_OnItemDoubleClicked_MetaData) }; // 26252171
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOverviewWidget_Statics::NewProp_OverviewListView = { "OverviewListView", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOverviewWidget, OverviewListView), Z_Construct_UClass_UListView_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverviewListView_MetaData), NewProp_OverviewListView_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOverviewWidget_Statics::NewProp_HeaderText = { "HeaderText", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOverviewWidget, HeaderText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HeaderText_MetaData), NewProp_HeaderText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOverviewWidget_Statics::NewProp_SortDistanceButton = { "SortDistanceButton", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOverviewWidget, SortDistanceButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SortDistanceButton_MetaData), NewProp_SortDistanceButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOverviewWidget_Statics::NewProp_SortNameButton = { "SortNameButton", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOverviewWidget, SortNameButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SortNameButton_MetaData), NewProp_SortNameButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOverviewWidget_Statics::NewProp_SortTypeButton = { "SortTypeButton", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOverviewWidget, SortTypeButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SortTypeButton_MetaData), NewProp_SortTypeButton_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UOverviewWidget_Statics::NewProp_UpdateInterval = { "UpdateInterval", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOverviewWidget, UpdateInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UpdateInterval_MetaData), NewProp_UpdateInterval_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UOverviewWidget_Statics::NewProp_MaxDisplayedEntries = { "MaxDisplayedEntries", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOverviewWidget, MaxDisplayedEntries), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxDisplayedEntries_MetaData), NewProp_MaxDisplayedEntries_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UOverviewWidget_Statics::NewProp_EntryMap_ValueProp = { "EntryMap", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UOverviewRowObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UOverviewWidget_Statics::NewProp_EntryMap_Key_KeyProp = { "EntryMap_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UOverviewWidget_Statics::NewProp_EntryMap = { "EntryMap", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOverviewWidget, EntryMap), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EntryMap_MetaData), NewProp_EntryMap_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UOverviewWidget_Statics::NewProp_CurrentSortBy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UOverviewWidget_Statics::NewProp_CurrentSortBy = { "CurrentSortBy", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOverviewWidget, CurrentSortBy), Z_Construct_UEnum_Echoes_EOverviewSortBy, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentSortBy_MetaData), NewProp_CurrentSortBy_MetaData) }; // 1401831041
void Z_Construct_UClass_UOverviewWidget_Statics::NewProp_bCurrentSortDescending_SetBit(void* Obj)
{
	((UOverviewWidget*)Obj)->bCurrentSortDescending = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UOverviewWidget_Statics::NewProp_bCurrentSortDescending = { "bCurrentSortDescending", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UOverviewWidget), &Z_Construct_UClass_UOverviewWidget_Statics::NewProp_bCurrentSortDescending_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCurrentSortDescending_MetaData), NewProp_bCurrentSortDescending_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UOverviewWidget_Statics::NewProp_TypeFilter_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UOverviewWidget_Statics::NewProp_TypeFilter_Inner = { "TypeFilter", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_Echoes_EOverviewEntryType, METADATA_PARAMS(0, nullptr) }; // 2713603577
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UOverviewWidget_Statics::NewProp_TypeFilter = { "TypeFilter", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UOverviewWidget, TypeFilter), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TypeFilter_MetaData), NewProp_TypeFilter_MetaData) }; // 2713603577
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UOverviewWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOverviewWidget_Statics::NewProp_OnSelectionChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOverviewWidget_Statics::NewProp_OnItemDoubleClicked,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOverviewWidget_Statics::NewProp_OverviewListView,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOverviewWidget_Statics::NewProp_HeaderText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOverviewWidget_Statics::NewProp_SortDistanceButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOverviewWidget_Statics::NewProp_SortNameButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOverviewWidget_Statics::NewProp_SortTypeButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOverviewWidget_Statics::NewProp_UpdateInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOverviewWidget_Statics::NewProp_MaxDisplayedEntries,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOverviewWidget_Statics::NewProp_EntryMap_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOverviewWidget_Statics::NewProp_EntryMap_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOverviewWidget_Statics::NewProp_EntryMap,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOverviewWidget_Statics::NewProp_CurrentSortBy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOverviewWidget_Statics::NewProp_CurrentSortBy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOverviewWidget_Statics::NewProp_bCurrentSortDescending,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOverviewWidget_Statics::NewProp_TypeFilter_Inner_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOverviewWidget_Statics::NewProp_TypeFilter_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UOverviewWidget_Statics::NewProp_TypeFilter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOverviewWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UOverviewWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Echoes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOverviewWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOverviewWidget_Statics::ClassParams = {
	&UOverviewWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UOverviewWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UOverviewWidget_Statics::PropPointers),
	0,
	0x00B010A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOverviewWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UOverviewWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UOverviewWidget()
{
	if (!Z_Registration_Info_UClass_UOverviewWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOverviewWidget.OuterSingleton, Z_Construct_UClass_UOverviewWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOverviewWidget.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UOverviewWidget);
UOverviewWidget::~UOverviewWidget() {}
// ********** End Class UOverviewWidget ************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h__Script_Echoes_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EOverviewEntryType_StaticEnum, TEXT("EOverviewEntryType"), &Z_Registration_Info_UEnum_EOverviewEntryType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2713603577U) },
		{ EOverviewSortBy_StaticEnum, TEXT("EOverviewSortBy"), &Z_Registration_Info_UEnum_EOverviewSortBy, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1401831041U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FOverviewRowData::StaticStruct, Z_Construct_UScriptStruct_FOverviewRowData_Statics::NewStructOps, TEXT("OverviewRowData"), &Z_Registration_Info_UScriptStruct_FOverviewRowData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FOverviewRowData), 322341806U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOverviewRowObject, UOverviewRowObject::StaticClass, TEXT("UOverviewRowObject"), &Z_Registration_Info_UClass_UOverviewRowObject, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOverviewRowObject), 1178050642U) },
		{ Z_Construct_UClass_UOverviewRowWidget, UOverviewRowWidget::StaticClass, TEXT("UOverviewRowWidget"), &Z_Registration_Info_UClass_UOverviewRowWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOverviewRowWidget), 3952874358U) },
		{ Z_Construct_UClass_UOverviewWidget, UOverviewWidget::StaticClass, TEXT("UOverviewWidget"), &Z_Registration_Info_UClass_UOverviewWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOverviewWidget), 1747712920U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h__Script_Echoes_438665339(TEXT("/Script/Echoes"),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h__Script_Echoes_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h__Script_Echoes_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h__Script_Echoes_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h__Script_Echoes_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h__Script_Echoes_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Reposetory_EchoesBackend_v1_Client_Echoes_Source_Echoes_UI_Widgets_SpaceHUD_OverviewWidget_h__Script_Echoes_Statics::EnumInfo));
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
