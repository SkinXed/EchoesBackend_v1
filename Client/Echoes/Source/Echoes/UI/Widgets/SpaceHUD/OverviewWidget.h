// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "OverviewWidget.generated.h"

class UListView;
class UButton;
class UTextBlock;
class UImage;

/**
 * Overview entry type enum
 * Categorizes entities shown in overview
 */
UENUM(BlueprintType)
enum class EOverviewEntryType : uint8
{
	/** Player-controlled ship */
	Player UMETA(DisplayName = "Player"),
	
	/** Friendly NPC or player */
	Friendly UMETA(DisplayName = "Friendly"),
	
	/** Neutral entity */
	Neutral UMETA(DisplayName = "Neutral"),
	
	/** Hostile/enemy entity */
	Hostile UMETA(DisplayName = "Hostile"),
	
	/** Celestial object (planet, asteroid, etc.) */
	Celestial UMETA(DisplayName = "Celestial"),
	
	/** Station or structure */
	Structure UMETA(DisplayName = "Structure"),
	
	/** Wormhole or jump gate */
	Gate UMETA(DisplayName = "Gate"),
	
	/** Other/Unknown */
	Other UMETA(DisplayName = "Other")
};

/**
 * Overview sorting options
 */
UENUM(BlueprintType)
enum class EOverviewSortBy : uint8
{
	/** Sort by distance (closest first) */
	Distance UMETA(DisplayName = "Distance"),
	
	/** Sort by name (alphabetical) */
	Name UMETA(DisplayName = "Name"),
	
	/** Sort by type */
	Type UMETA(DisplayName = "Type"),
	
	/** Sort by radial velocity (approaching first) */
	RadialVelocity UMETA(DisplayName = "Radial Velocity")
};

/**
 * FOverviewRowData
 * 
 * Data structure for a single overview entry
 * Used with UListView for efficient display of many entities
 */
USTRUCT(BlueprintType)
struct FOverviewRowData
{
	GENERATED_BODY()

	/** Unique identifier for this entry */
	UPROPERTY(BlueprintReadWrite, Category = "Overview")
	int32 EntityID;

	/** Reference to the actual actor */
	UPROPERTY(BlueprintReadWrite, Category = "Overview")
	AActor* ActorReference;

	/** Entity type for filtering and display */
	UPROPERTY(BlueprintReadWrite, Category = "Overview")
	EOverviewEntryType EntryType;

	/** Icon texture for this entity type */
	UPROPERTY(BlueprintReadWrite, Category = "Overview")
	UTexture2D* IconTexture;

	/** Display name */
	UPROPERTY(BlueprintReadWrite, Category = "Overview")
	FString EntityName;

	/** Distance from player in centimeters */
	UPROPERTY(BlueprintReadWrite, Category = "Overview")
	float Distance;

	/** Radial velocity (negative = approaching, positive = fleeing) in m/s */
	UPROPERTY(BlueprintReadWrite, Category = "Overview")
	float RadialVelocity;

	/** Angular velocity (perpendicular velocity) in m/s */
	UPROPERTY(BlueprintReadWrite, Category = "Overview")
	float AngularVelocity;

	/** Constructor */
	FOverviewRowData()
		: EntityID(0)
		, ActorReference(nullptr)
		, EntryType(EOverviewEntryType::Other)
		, IconTexture(nullptr)
		, EntityName(TEXT("Unknown"))
		, Distance(0.0f)
		, RadialVelocity(0.0f)
		, AngularVelocity(0.0f)
	{
	}

	/**
	 * Get formatted distance string
	 * Converts cm to appropriate unit (m, km, AU)
	 */
	FString GetFormattedDistance() const;

	/**
	 * Get formatted velocity string
	 */
	FString GetFormattedVelocity() const;

	/**
	 * Check if entity is approaching (negative radial velocity)
	 */
	FORCEINLINE bool IsApproaching() const
	{
		return RadialVelocity < 0.0f;
	}
};

/**
 * UOverviewRowObject
 * 
 * Object wrapper for FOverviewRowData to use with UListView
 * Required by UListView to display data
 */
UCLASS(BlueprintType)
class ECHOES_API UOverviewRowObject : public UObject
{
	GENERATED_BODY()

public:
	/** The actual row data */
	UPROPERTY(BlueprintReadWrite, Category = "Overview")
	FOverviewRowData RowData;
};

/**
 * UOverviewRowWidget
 * 
 * Individual row widget for the overview list
 * Displays entity information in a single line
 * 
 * Implements IUserObjectListEntry for UListView compatibility
 */
UCLASS(Abstract, Blueprintable)
class ECHOES_API UOverviewRowWidget : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	/**
	 * Set the row data for this widget
	 * Called by the ListView when displaying this row
	 */
	UFUNCTION(BlueprintCallable, Category = "Overview")
	void SetRowData(const FOverviewRowData& InRowData);

	/**
	 * Get the current row data
	 */
	UFUNCTION(BlueprintPure, Category = "Overview")
	const FOverviewRowData& GetRowData() const { return RowData; }

protected:
	// IUserObjectListEntry interface
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;

	/**
	 * Update the visual display with current row data
	 * Override in Blueprint to customize appearance
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "Overview")
	void UpdateDisplay();

	/** The row data being displayed */
	UPROPERTY(BlueprintReadOnly, Category = "Overview")
	FOverviewRowData RowData;

	// Widget references (bind in Blueprint)
	
	/** Icon image */
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UImage* IconImage;

	/** Entity name text */
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* NameText;

	/** Distance text */
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* DistanceText;

	/** Velocity text */
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* VelocityText;
};

/**
 * Delegate for overview selection changed
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOverviewSelectionChanged, const FOverviewRowData&, SelectedRow);

/**
 * Delegate for overview item double-clicked
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOverviewItemDoubleClicked, AActor*, SelectedActor);

/**
 * UOverviewWidget
 * 
 * EVE-like overview panel for space navigation
 * Displays list of entities in the current system
 * 
 * Features:
 * - UListView for efficient display of large entity counts
 * - Sortable by distance, name, type, velocity
 * - Filterable by entity type
 * - Event-driven updates (no Tick)
 * - Double-click to lock target
 * 
 * Architecture:
 * - Uses UListView for virtualization and performance
 * - Data stored as FOverviewRowData structs
 * - Updates via event dispatchers, not Tick
 * 
 * Optimization:
 * - ListView virtualization: Only renders visible rows
 * - Distance updates: Batched, not per-frame
 * - Sorting: Only when requested or data changes
 * 
 * Usage:
 * // Add entry to overview
 * FOverviewRowData NewEntry;
 * NewEntry.EntityName = TEXT("Hostile Frigate");
 * NewEntry.Distance = 25000.0f * 100.0f; // 25km in cm
 * OverviewWidget->AddEntry(NewEntry);
 * 
 * // Sort by distance
 * OverviewWidget->SortOverview(EOverviewSortBy::Distance);
 */
UCLASS(Abstract, Blueprintable)
class ECHOES_API UOverviewWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UOverviewWidget(const FObjectInitializer& ObjectInitializer);

	//~ Begin UUserWidget Interface
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	//~ End UUserWidget Interface

	// ==================== Public API ====================

	/**
	 * Add an entry to the overview
	 * 
	 * @param RowData The data for the new entry
	 */
	UFUNCTION(BlueprintCallable, Category = "Overview")
	void AddEntry(const FOverviewRowData& RowData);

	/**
	 * Remove an entry by entity ID
	 * 
	 * @param EntityID The ID of the entity to remove
	 */
	UFUNCTION(BlueprintCallable, Category = "Overview")
	void RemoveEntry(int32 EntityID);

	/**
	 * Update an existing entry
	 * 
	 * @param EntityID The ID of the entity to update
	 * @param NewRowData The new data for the entry
	 */
	UFUNCTION(BlueprintCallable, Category = "Overview")
	void UpdateEntry(int32 EntityID, const FOverviewRowData& NewRowData);

	/**
	 * Clear all entries
	 */
	UFUNCTION(BlueprintCallable, Category = "Overview")
	void ClearAll();

	/**
	 * CLIENT ONLY: Sort the overview by specified criteria
	 * 
	 * @param SortBy How to sort the entries
	 * @param bDescending Sort in descending order (default: ascending)
	 */
	UFUNCTION(BlueprintCallable, Category = "Overview")
	void ClientOnly_SortOverview(EOverviewSortBy SortBy, bool bDescending = false);

	/**
	 * COMMON (Pure): Format distance from cm to human-readable string
	 * 
	 * @param DistanceInCm Distance in centimeters
	 * @return Formatted string (e.g., "450 m", "2.5 km", "0.5 AU")
	 */
	UFUNCTION(BlueprintPure, Category = "Overview")
	static FString Common_FormatDistance(float DistanceInCm);

	/**
	 * COMMON (Pure): Format velocity to human-readable string
	 * 
	 * @param VelocityInMps Velocity in meters per second
	 * @return Formatted string (e.g., "125 m/s", "approaching", "fleeing")
	 */
	UFUNCTION(BlueprintPure, Category = "Overview")
	static FString Common_FormatVelocity(float VelocityInMps);

	/**
	 * Get currently selected entry (if any)
	 * 
	 * @param OutRowData The selected row data
	 * @return True if an entry is selected
	 */
	UFUNCTION(BlueprintPure, Category = "Overview")
	bool GetSelectedEntry(FOverviewRowData& OutRowData) const;

	/**
	 * Set filter for entity types to show
	 * 
	 * @param AllowedTypes Array of types to display (empty = show all)
	 */
	UFUNCTION(BlueprintCallable, Category = "Overview")
	void SetTypeFilter(const TArray<EOverviewEntryType>& AllowedTypes);

	/**
	 * Refresh all entries (recalculate distances)
	 * Called periodically by timer
	 */
	UFUNCTION(BlueprintCallable, Category = "Overview")
	void ClientOnly_RefreshEntries();

	// ==================== Events ====================

	/** Fired when overview selection changes */
	UPROPERTY(BlueprintAssignable, Category = "Overview Events")
	FOnOverviewSelectionChanged OnSelectionChanged;

	/** Fired when an item is double-clicked */
	UPROPERTY(BlueprintAssignable, Category = "Overview Events")
	FOnOverviewItemDoubleClicked OnItemDoubleClicked;

protected:
	// ==================== Widget References ====================

	/** The list view widget */
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UListView* OverviewListView;

	/** Header text showing entry count */
	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
	UTextBlock* HeaderText;

	/** Sort by distance button */
	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
	UButton* SortDistanceButton;

	/** Sort by name button */
	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
	UButton* SortNameButton;

	/** Sort by type button */
	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional))
	UButton* SortTypeButton;

	// ==================== Configuration ====================

	/** Update interval for distance recalculation (seconds) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Overview Settings")
	float UpdateInterval;

	/** Maximum number of entries to display (0 = unlimited) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Overview Settings")
	int32 MaxDisplayedEntries;

	// ==================== Internal State ====================

	/** Map of entity ID to list object for fast lookup */
	UPROPERTY()
	TMap<int32, UOverviewRowObject*> EntryMap;

	/** Current sort criteria */
	UPROPERTY()
	EOverviewSortBy CurrentSortBy;

	/** Current sort direction */
	UPROPERTY()
	bool bCurrentSortDescending;

	/** Allowed entity types (empty = all allowed) */
	UPROPERTY()
	TArray<EOverviewEntryType> TypeFilter;

	/** Timer handle for periodic updates */
	FTimerHandle UpdateTimerHandle;

	// ==================== Internal Functions ====================

	/**
	 * Handle list view selection changed
	 */
	UFUNCTION()
	void HandleSelectionChanged(UObject* Item);

	/**
	 * Handle list view item double-clicked
	 */
	UFUNCTION()
	void HandleItemDoubleClicked(UObject* Item);

	/**
	 * Sort button clicked handlers
	 */
	UFUNCTION()
	void HandleSortDistanceClicked();

	UFUNCTION()
	void HandleSortNameClicked();

	UFUNCTION()
	void HandleSortTypeClicked();

	/**
	 * Update header text with entry count
	 */
	void UpdateHeaderText();

	/**
	 * Check if an entry passes the current type filter
	 */
	bool PassesTypeFilter(const FOverviewRowData& RowData) const;

	/**
	 * Get player ship position for distance calculations
	 */
	FVector GetPlayerPosition() const;
};
