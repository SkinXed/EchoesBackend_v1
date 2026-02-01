// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/Texture2D.h"
#include "Engine/StaticMesh.h"
#include "EchoesItemDefinitions.generated.h"

/**
 * Item category enumeration
 * Categorizes items for filtering and organization
 */
UENUM(BlueprintType)
enum class EEchoesItemCategory : uint8
{
	None = 0 UMETA(DisplayName = "None"),
	Ore UMETA(DisplayName = "Ore"),
	Mineral UMETA(DisplayName = "Mineral"),
	Module UMETA(DisplayName = "Module"),
	Ammo UMETA(DisplayName = "Ammunition"),
	Ship UMETA(DisplayName = "Ship"),
	Blueprint UMETA(DisplayName = "Blueprint"),
	Component UMETA(DisplayName = "Component"),
	Commodity UMETA(DisplayName = "Commodity"),
	Implant UMETA(DisplayName = "Implant"),
	Skill UMETA(DisplayName = "Skill"),
	Charge UMETA(DisplayName = "Charge"),
	Drone UMETA(DisplayName = "Drone"),
	Fighter UMETA(DisplayName = "Fighter"),
	Structure UMETA(DisplayName = "Structure"),
	Subsystem UMETA(DisplayName = "Subsystem"),
	Rig UMETA(DisplayName = "Rig"),
	MAX UMETA(Hidden)
};

/**
 * FEchoesItemDefinitionRow
 * 
 * Data table row structure for item definitions
 * Maps database item IDs to visual assets and metadata
 * 
 * Usage:
 * - Create Data Table asset in Unreal Editor based on this struct
 * - Row names should match database TypeId (as string)
 * - Fill in visual assets (icons, meshes) and metadata
 * - Reference table in UEchoesInventorySubsystem
 * 
 * Example Data Table Setup:
 * Row Name: "34" (Tritanium TypeId)
 * DisplayName: "Tritanium"
 * Description: "The most common ore in space..."
 * Icon: T_Icon_Tritanium
 * WorldMesh: SM_Ore_Tritanium
 * UnitVolume: 0.01
 * UnitMass: 0.01
 * Category: Ore
 */
USTRUCT(BlueprintType)
struct ECHOES_API FEchoesItemDefinitionRow : public FTableRowBase
{
	GENERATED_BODY()

	/**
	 * Localized display name for the item
	 * Supports localization for different languages
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Definition")
	FText DisplayName;

	/**
	 * Localized description of the item
	 * Displayed in tooltips and detail panels
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Definition")
	FText Description;

	/**
	 * Icon texture for UI display (ListView, tooltips, etc.)
	 * Soft reference for async loading to prevent freezes
	 * Recommended size: 64x64 or 128x128
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Definition|Visual")
	TSoftObjectPtr<UTexture2D> Icon;

	/**
	 * 3D mesh for world representation
	 * Used when item is ejected into space or displayed in 3D
	 * Soft reference for streaming
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Definition|Visual")
	TSoftObjectPtr<UStaticMesh> WorldMesh;

	/**
	 * Volume of a single unit (in cubic meters)
	 * Used for cargo capacity calculations
	 * TotalVolume = Quantity * UnitVolume
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Definition|Physics")
	float UnitVolume = 0.01f;

	/**
	 * Mass of a single unit (in kilograms)
	 * Used for physics and ship mass calculations
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Definition|Physics")
	float UnitMass = 0.01f;

	/**
	 * Item category for organization and filtering
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Definition")
	EEchoesItemCategory Category = EEchoesItemCategory::None;

	/**
	 * Optional: Market group ID for market categorization
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Definition|Market")
	int32 MarketGroupId = 0;

	/**
	 * Optional: Tech level of the item (0-5, where 5 is highest tech)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Definition|Meta")
	int32 TechLevel = 1;

	/**
	 * Optional: Meta level (0 = regular, 1+ = special variants)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Definition|Meta")
	int32 MetaLevel = 0;

	/**
	 * Whether this item can be stacked in inventory
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Definition")
	bool bIsStackable = true;

	/**
	 * Maximum stack size (0 = unlimited)
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Definition")
	int32 MaxStackSize = 0;

	// Constructor
	FEchoesItemDefinitionRow()
		: DisplayName(FText::FromString(TEXT("Unknown Item")))
		, Description(FText::FromString(TEXT("No description available.")))
		, UnitVolume(0.01f)
		, UnitMass(0.01f)
		, Category(EEchoesItemCategory::None)
		, MarketGroupId(0)
		, TechLevel(1)
		, MetaLevel(0)
		, bIsStackable(true)
		, MaxStackSize(0)
	{
	}
};
