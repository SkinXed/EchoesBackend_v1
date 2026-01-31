// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Http.h"
#include "Core/Common/EchoesItemDefinitions.h"
#include "Engine/StreamableManager.h"
#include "EchoesInventorySubsystem.generated.h"

// Forward declarations
class UDataTable;
class UTexture2D;
class UStaticMesh;

/**
 * Ship instance structure (mirrors C# ShipInstanceDto)
 * Common_ prefix for shared data structures
 */
USTRUCT(BlueprintType)
struct FEchoesShipInstance
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Ship")
	FGuid InstanceId;

	UPROPERTY(BlueprintReadWrite, Category = "Ship")
	FString Name;

	UPROPERTY(BlueprintReadWrite, Category = "Ship")
	int32 ShipTypeId = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Ship")
	FString ShipTypeName;

	UPROPERTY(BlueprintReadWrite, Category = "Ship")
	float Mass = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Ship")
	FGuid LocationSystemId;

	UPROPERTY(BlueprintReadWrite, Category = "Ship")
	FString LocationName;

	UPROPERTY(BlueprintReadWrite, Category = "Ship")
	bool IsActive = false;

	UPROPERTY(BlueprintReadWrite, Category = "Ship")
	bool IsDocked = true;

	UPROPERTY(BlueprintReadWrite, Category = "Ship")
	int32 ModuleCount = 0;
};

/**
 * Ship list response structure
 * Wrapper for TArray to enable Blueprint support in delegates
 */
USTRUCT(BlueprintType)
struct FEchoesShipList
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Ship")
	TArray<FEchoesShipInstance> Ships;
};

/**
 * Module instance structure (mirrors C# ModuleInstanceDto)
 * Common_ prefix for shared data structures
 */
USTRUCT(BlueprintType)
struct FEchoesModule
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Module")
	FGuid InstanceId;

	UPROPERTY(BlueprintReadWrite, Category = "Module")
	int32 ModuleTypeId = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Module")
	FString TypeName;

	UPROPERTY(BlueprintReadWrite, Category = "Module")
	FString SlotType;

	UPROPERTY(BlueprintReadWrite, Category = "Module")
	int32 SlotIndex = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Module")
	bool IsOnline = false;

	UPROPERTY(BlueprintReadWrite, Category = "Module")
	float Mass = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Module")
	float ThrustBonus = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Module")
	float InertiaModifier = 1.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Module")
	float RotationBonus = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Module")
	float MaxVelocityModifier = 1.0f;
};

/**
 * Ship fitting structure (mirrors C# ShipFittingDto)
 * Detailed fitting information with all modules
 */
USTRUCT(BlueprintType)
struct FEchoesShipFitting
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Ship")
	FGuid ShipInstanceId;

	UPROPERTY(BlueprintReadWrite, Category = "Ship")
	FString ShipName;

	UPROPERTY(BlueprintReadWrite, Category = "Ship")
	int32 ShipTypeId = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Ship")
	FString ShipTypeName;

	UPROPERTY(BlueprintReadWrite, Category = "Ship")
	float BaseMass = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Ship")
	float TotalMass = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Ship")
	float Thrust = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Ship")
	float MaxVelocity = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Ship")
	float InertiaMultiplier = 1.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Ship")
	float RotationTorque = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Ship")
	TArray<FEchoesModule> Modules;
};


DECLARE_DYNAMIC_DELEGATE_OneParam(FOnIconLoaded, UTexture2D*, LoadedIcon);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnWorldMeshLoaded, UStaticMesh*, LoadedMesh);

DECLARE_DYNAMIC_DELEGATE_OneParam(FOnShipsReceived, const FEchoesShipList&, ShipList);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnShipFittingReceived, const FEchoesShipFitting&, Fitting);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnInventoryFailure, const FString&, ErrorMessage);
DECLARE_DYNAMIC_DELEGATE(FOnShipActivated);
DECLARE_DYNAMIC_DELEGATE(FOnModuleFitted);
DECLARE_DYNAMIC_DELEGATE(FOnModuleUnfitted);

// Multicast delegates for UI updates
DECLARE_MULTICAST_DELEGATE_OneParam(FOnFittingChanged, const struct FEchoesShipFitting&);

/**
 * UEchoesInventorySubsystem
 * 
 * Inventory management subsystem for Echoes MMO
 * Handles ship hangar and fitting management
 * 
 * Architecture:
 * - GameInstanceSubsystem: Persists across level transitions
 * - Requires valid JWT token from UEchoesAuthSubsystem
 * - Communicates with ASP.NET Core backend
 * - Provides inventory data to UI and Movement Component
 * 
 * Naming Conventions:
 * - Inventory_ prefix: Inventory management functions
 * - Common_ prefix: Shared data structures
 * - ServerRPC_ prefix: Server-side operations
 */
UCLASS()
class ECHOES_API UEchoesInventorySubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	// Subsystem lifecycle
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// ==================== Inventory Functions ====================

	/**
	 * Fetch all ships for current character
	 * Sends HTTP GET to /api/inventory/ships with JWT token
	 * 
	 * @param OnSuccess - Callback with ship list
	 * @param OnFailure - Callback on request failure
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Inventory")
	void Inventory_FetchShips(
		FOnShipsReceived OnSuccess,
		FOnInventoryFailure OnFailure);

	/**
	 * Fetch detailed ship fitting with all modules
	 * Sends HTTP GET to /api/inventory/ship/{id}/fitting with JWT token
	 * This data is used to initialize the Movement Component physics
	 * 
	 * @param ShipId - Ship instance ID
	 * @param OnSuccess - Callback with detailed fitting
	 * @param OnFailure - Callback on request failure
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Inventory")
	void Inventory_FetchShipFitting(
		const FGuid& ShipId,
		FOnShipFittingReceived OnSuccess,
		FOnInventoryFailure OnFailure);

	/**
	 * Set active ship (activate ship for undocking)
	 * Sends HTTP POST to /api/inventory/ship/{id}/activate with JWT token
	 * 
	 * @param ShipId - Ship instance ID to activate
	 * @param OnSuccess - Callback on successful activation
	 * @param OnFailure - Callback on activation failure
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Inventory")
	void Inventory_SetActiveShip(
		const FGuid& ShipId,
		FOnShipActivated OnSuccess,
		FOnInventoryFailure OnFailure);

	/**
	 * Get cached ships list
	 * 
	 * @return Array of ship instances
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Inventory")
	TArray<FEchoesShipInstance> Inventory_GetCachedShips() const { return CachedShips; }

	/**
	 * Get cached ship fitting
	 * 
	 * @return Last fetched ship fitting
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Inventory")
	FEchoesShipFitting Inventory_GetCachedFitting() const { return CachedFitting; }

	/**
	 * Get active ship from cached list
	 * 
	 * @return Active ship instance (if any)
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Inventory")
	FEchoesShipInstance Inventory_GetActiveShip() const;

	/**
	 * Clear inventory cache
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Inventory")
	void Inventory_ClearCache();

	// ==================== Item Definitions System ====================

	/**
	 * Get item definition by item ID (TypeId from database)
	 * Returns visual assets and metadata for the item
	 * 
	 * @param ItemId - Item type ID as string (e.g., "34" for Tritanium)
	 * @return Item definition row, or nullptr if not found
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Inventory|ItemDefinitions")
	const FEchoesItemDefinitionRow* GetItemDefinition(const FString& ItemId) const;

	/**
	 * Get item definition by integer type ID
	 * 
	 * @param TypeId - Item type ID as integer
	 * @return Item definition row, or nullptr if not found
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Inventory|ItemDefinitions")
	const FEchoesItemDefinitionRow* GetItemDefinitionByTypeId(int32 TypeId) const;

	/**
	 * Async load item icon texture
	 * Prevents UI freezes when loading many icons
	 * 
	 * @param ItemId - Item type ID as string
	 * @param OnLoaded - Callback when texture is loaded
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Inventory|ItemDefinitions")
	void AsyncLoadItemIcon(const FString& ItemId, FOnIconLoaded OnLoaded);

	/**
	 * Async load item world mesh
	 * Used for ejected items in space
	 * 
	 * @param ItemId - Item type ID as string
	 * @param OnLoaded - Callback when mesh is loaded
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Inventory|ItemDefinitions")
	void AsyncLoadItemWorldMesh(const FString& ItemId, FOnWorldMeshLoaded OnLoaded);

	/**
	 * Check if item definition exists
	 * 
	 * @param ItemId - Item type ID as string
	 * @return True if definition exists in table
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Inventory|ItemDefinitions")
	bool HasItemDefinition(const FString& ItemId) const;

	// ==================== UI Wrapper Functions ====================

	/**
	 * UI wrapper: Fit a module to a ship
	 * Sends HTTP PUT to /api/inventory/ship/{shipId}/module/{moduleId}/fit
	 * Automatically refreshes fitting and triggers OnFittingChanged delegate
	 * 
	 * @param ShipId - Ship instance ID
	 * @param ModuleId - Module instance ID to fit
	 * @param SlotType - Slot type (High, Mid, Low, Rig)
	 * @param SlotIndex - Slot index within type
	 * @param OnSuccess - Callback on successful fit
	 * @param OnFailure - Callback on fit failure
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Inventory|UI")
	void UI_FitModule(
		const FGuid& ShipId,
		const FGuid& ModuleId,
		const FString& SlotType,
		int32 SlotIndex,
		FOnModuleFitted OnSuccess,
		FOnInventoryFailure OnFailure);

	/**
	 * UI wrapper: Unfit a module from a ship
	 * Sends HTTP DELETE to /api/inventory/ship/{shipId}/module/{moduleId}/unfit
	 * Automatically refreshes fitting and triggers OnFittingChanged delegate
	 * 
	 * @param ShipId - Ship instance ID
	 * @param ModuleId - Module instance ID to unfit
	 * @param OnSuccess - Callback on successful unfit
	 * @param OnFailure - Callback on unfit failure
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Inventory|UI")
	void UI_UnfitModule(
		const FGuid& ShipId,
		const FGuid& ModuleId,
		FOnModuleUnfitted OnSuccess,
		FOnInventoryFailure OnFailure);

	/**
	 * Multicast delegate triggered when ship fitting changes
	 * UI widgets should bind to this for reactive updates
	 */
	FOnFittingChanged OnFittingChanged;

protected:
	// ==================== HTTP Request Handlers ====================

	/**
	 * Handle ships list response from backend
	 */
	void OnShipsReceived(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bWasSuccessful,
		FOnShipsReceived OnSuccess,
		FOnInventoryFailure OnFailure);

	/**
	 * Handle ship fitting response from backend
	 */
	void OnShipFittingReceived(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bWasSuccessful,
		FOnShipFittingReceived OnSuccess,
		FOnInventoryFailure OnFailure);

	/**
	 * Handle ship activation response from backend
	 */
	void OnShipActivationReceived(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bWasSuccessful,
		FOnShipActivated OnSuccess,
		FOnInventoryFailure OnFailure);

	/**
	 * Handle module fit response from backend
	 */
	void OnModuleFitReceived(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bWasSuccessful,
		const FGuid& ShipId,
		FOnModuleFitted OnSuccess,
		FOnInventoryFailure OnFailure);

	/**
	 * Handle module unfit response from backend
	 */
	void OnModuleUnfitReceived(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bWasSuccessful,
		const FGuid& ShipId,
		FOnModuleUnfitted OnSuccess,
		FOnInventoryFailure OnFailure);

	// ==================== Helper Functions ====================

	/**
	 * Parse ships list JSON from backend
	 */
	bool ParseShipsList(const FString& JsonString, TArray<FEchoesShipInstance>& OutShips);

	/**
	 * Parse ship fitting JSON from backend
	 */
	bool ParseShipFitting(const FString& JsonString, FEchoesShipFitting& OutFitting);

	/**
	 * Get JWT token from Auth subsystem
	 */
	FString GetAuthToken() const;

	/**
	 * Get API base URL from configuration
	 */
	FString GetApiBaseUrl() const;

private:
	// ==================== Private Members ====================

	/** Cached ships list */
	UPROPERTY()
	TArray<FEchoesShipInstance> CachedShips;

	/** Cached ship fitting (last fetched) */
	UPROPERTY()
	FEchoesShipFitting CachedFitting;

	/** HTTP module reference */
	FHttpModule* Http;

	// ==================== Item Definitions ====================

	/**
	 * Data table containing item definitions
	 * Maps TypeId to visual assets and metadata
	 * Set this in Project Settings or Game Instance
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Definitions", meta = (AllowPrivateAccess = "true"))
	UDataTable* ItemDefinitionsTable;

	/**
	 * Streamable manager for async asset loading
	 * Prevents freezes when loading icons and meshes
	 */
	FStreamableManager StreamableManager;

	/**
	 * Cache of loaded item definitions for quick access
	 * Key: ItemId (TypeId as string), Value: Definition row
	 */
	TMap<FString, const FEchoesItemDefinitionRow*> DefinitionCache;

	/**
	 * Build definition cache from data table
	 */
	void BuildDefinitionCache();
};
