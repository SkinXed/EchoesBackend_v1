// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Http.h"
#include "EchoesInventorySubsystem.generated.h"

// Forward declarations
DECLARE_DELEGATE_OneParam(FOnShipsReceived, const TArray<struct FEchoesShipInstance>&);
DECLARE_DELEGATE_OneParam(FOnShipFittingReceived, const struct FEchoesShipFitting&);
DECLARE_DELEGATE_OneParam(FOnInventoryFailure, const FString&);
DECLARE_DELEGATE(FOnShipActivated);

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
};
