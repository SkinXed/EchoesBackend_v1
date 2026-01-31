// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Http.h"
#include "EchoesInventoryComponent.generated.h"

/**
 * Inventory item structure for component-level storage
 * Mirrors backend Asset entity
 */
USTRUCT(BlueprintType)
struct FEchoesInventoryItem
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	FGuid AssetId;

	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	int32 TypeId = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	FString TypeName;

	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	int64 Quantity = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	float Volume = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	float TotalVolume = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	bool IsStackable = false;
};

/**
 * Container items response structure
 */
USTRUCT(BlueprintType)
struct FEchoesContainerItems
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	TArray<FEchoesInventoryItem> Items;

	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	int32 TotalCount = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Inventory")
	float TotalVolume = 0.0f;
};

// Delegates for inventory operations
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnItemsFetched, const FEchoesContainerItems&, Items);
DECLARE_DYNAMIC_DELEGATE(FOnItemMoveSuccess);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnInventoryOperationFailure, const FString&, ErrorMessage);

// Multicast delegate for UI updates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInventoryUpdated, const FEchoesContainerItems&, Items);

/**
 * UEchoesInventoryComponent
 * 
 * Actor Component for inventory management in Echoes MMO
 * Provides storage functionality for ships, stations, and containers
 * 
 * Architecture:
 * - ActorComponent: Can be attached to any Actor (ship, station, container)
 * - StorageId: Links to backend Container entity (FGuid)
 * - Capacity: Maximum volume this storage can hold
 * - Communicates with UEchoesInventorySubsystem for data fetching
 * - Provides ServerOnly_ functions for server-authoritative item operations
 * 
 * Usage:
 * - Attach to ship actors for cargo holds
 * - Attach to station actors for hangar storage
 * - Attach to container actors for item storage
 */
UCLASS(ClassGroup=(Echoes), meta=(BlueprintSpawnableComponent))
class ECHOES_API UEchoesInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// ==================== Component Lifecycle ====================
	
	UEchoesInventoryComponent();
	
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// ==================== Component Properties ====================

	/**
	 * Storage ID that maps to backend Container entity
	 * Initialize this on spawn from database
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory|Storage")
	FGuid StorageId;

	/**
	 * Maximum storage capacity in cubic meters (m³)
	 * Null/0 means unlimited capacity (e.g., station storage)
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory|Storage")
	float Capacity = 0.0f;

	/**
	 * Current used volume in cubic meters (m³)
	 * Updated after successful operations
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Inventory|Storage")
	float UsedVolume = 0.0f;

	/**
	 * Maximum distance for item transfer operations (in cm, Unreal units)
	 * Default: 250000 cm = 2500 meters
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory|Transfer")
	float MaxTransferDistance = 250000.0f;

	// ==================== Inventory Functions ====================

	/**
	 * Fetch all items in this container from backend
	 * Queries UEchoesInventorySubsystem which calls GET /api/inventory/container/{id}
	 * 
	 * @param OnSuccess - Callback with items list
	 * @param OnFailure - Callback on failure
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Inventory")
	void FetchItems(
		FOnItemsFetched OnSuccess,
		FOnInventoryOperationFailure OnFailure);

	/**
	 * Get cached items (last fetched from server)
	 * 
	 * @return Cached container items
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Inventory")
	FEchoesContainerItems GetCachedItems() const { return CachedItems; }

	/**
	 * Get available volume in this container
	 * 
	 * @return Available volume in cubic meters
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Inventory")
	float GetAvailableVolume() const { return Capacity > 0 ? FMath::Max(0.0f, Capacity - UsedVolume) : FLT_MAX; }

	/**
	 * Check if item can fit in this container
	 * 
	 * @param ItemVolume - Volume of item to check
	 * @return True if item can fit
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Inventory")
	bool CanFitItem(float ItemVolume) const;

	// ==================== Server-Side Item Transfer ====================

	/**
	 * SERVER ONLY: Move item between containers with distance check
	 * This should only be called on the server
	 * Validates distance between source and target actors
	 * Sends POST /api/inventory/move to backend
	 * 
	 * @param AssetId - ID of asset to move
	 * @param TargetActor - Target actor with inventory component
	 * @param SourceActor - Source actor (for distance check)
	 * @param Quantity - Optional: quantity to move (for splitting stacks)
	 * @param OnSuccess - Callback on successful move
	 * @param OnFailure - Callback on move failure
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Inventory|Server", meta = (DisplayName = "ServerOnly MoveItem"))
	void ServerOnly_MoveItem(
		const FGuid& AssetId,
		AActor* TargetActor,
		AActor* SourceActor,
		int64 Quantity,
		FOnItemMoveSuccess OnSuccess,
		FOnInventoryOperationFailure OnFailure);

	// ==================== Visual Sync Delegate ====================

	/**
	 * Multicast delegate triggered when inventory is updated
	 * UI widgets should bind to this for reactive updates
	 */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Inventory|Events")
	FOnInventoryUpdated OnInventoryUpdated;

	// ==================== Initialization Helpers ====================

	/**
	 * Initialize component with storage ID from database
	 * Called when spawning ships or stations
	 * 
	 * @param InStorageId - Storage ID from database
	 * @param InCapacity - Storage capacity (0 = unlimited)
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Inventory|Initialization")
	void InitializeStorage(const FGuid& InStorageId, float InCapacity);

protected:
	// ==================== HTTP Request Handlers ====================

	/**
	 * Handle items fetch response from backend
	 */
	void OnItemsFetchResponse(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bWasSuccessful,
		FOnItemsFetched OnSuccess,
		FOnInventoryOperationFailure OnFailure);

	/**
	 * Handle item move response from backend
	 */
	void OnItemMoveResponse(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bWasSuccessful,
		FOnItemMoveSuccess OnSuccess,
		FOnInventoryOperationFailure OnFailure);

	// ==================== Helper Functions ====================

	/**
	 * Parse items list JSON from backend
	 */
	bool ParseItemsList(const FString& JsonString, FEchoesContainerItems& OutItems);

	/**
	 * Get JWT token from Auth subsystem
	 */
	FString GetAuthToken() const;

	/**
	 * Get API base URL from configuration
	 */
	FString GetApiBaseUrl() const;

	/**
	 * Check distance between two actors
	 */
	bool IsWithinTransferDistance(AActor* ActorA, AActor* ActorB) const;

private:
	// ==================== Private Members ====================

	/** Cached items list */
	UPROPERTY()
	FEchoesContainerItems CachedItems;

	/** HTTP module reference */
	FHttpModule* Http;
};
