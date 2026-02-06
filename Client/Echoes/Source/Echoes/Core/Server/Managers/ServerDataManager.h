// Copyright Epic Games, Inc. All Rights Reserved.
// Echoes - EVE-like MMO
// Server Data Manager - Handles ASP.NET to UE Server data synchronization

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Core/Common/Interfaces/ShipFittingInterface.h"
#include "Core/Common/Types/EchoesGameState.h"
#include "Http.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "ServerDataManager.generated.h"

/**
 * Server Data Manager
 * Handles data synchronization from ASP.NET Core backend to UE Server
 * Parses JSON responses and populates game data structures
 */
UCLASS()
class ECHOES_API AServerDataManager : public AActor
{
	GENERATED_BODY()
	
public:	
	AServerDataManager();

protected:
	virtual void BeginPlay() override;

public:	
	/**
	 * Parse Fitting Data from JSON
	 * Receives JSON from ASP.NET API and populates ship fitting data
	 * @param JsonString - JSON string from API response
	 * @param OutFittingData - Populated fitting data structure
	 * @return true if parsing succeeded
	 */
	UFUNCTION(BlueprintCallable, Category = "Server|Data")
	bool ServerOnly_ParseFittingDataFromJSON(const FString& JsonString, FCommon_ShipFittingData& OutFittingData);

	/**
	 * Parse Module Data from JSON
	 * Parses individual module/item data from JSON
	 * @param JsonString - JSON string for a single module
	 * @param OutSlot - Populated slot data
	 * @return true if parsing succeeded
	 */
	UFUNCTION(BlueprintCallable, Category = "Server|Data")
	bool ServerOnly_ParseModuleFromJSON(const FString& JsonString, FCommon_ItemSlot& OutSlot);

	/**
	 * Validate Fitting Requirements
	 * Validates that a fitting meets ship requirements (CPU, Powergrid)
	 * @param FittingData - The fitting to validate
	 * @param ShipBaseCPU - Ship's base CPU capacity
	 * @param ShipBasePowergrid - Ship's base powergrid capacity
	 * @param OutErrorMessage - Error message if validation fails
	 * @return true if fitting is valid
	 */
	UFUNCTION(BlueprintCallable, Category = "Server|Data")
	bool ServerOnly_ValidateFitting(
		const FCommon_ShipFittingData& FittingData,
		float ShipBaseCPU,
		float ShipBasePowergrid,
		FString& OutErrorMessage
	);

	/**
	 * Validate Module Installation
	 * Validates that a module can be installed in a specific slot
	 * @param Module - The module to install
	 * @param SlotType - The target slot type
	 * @param CurrentFitting - Current ship fitting
	 * @param ShipBaseCPU - Ship's base CPU
	 * @param ShipBasePowergrid - Ship's base powergrid
	 * @param OutErrorMessage - Error message if validation fails
	 * @return true if module can be installed
	 */
	UFUNCTION(BlueprintCallable, Category = "Server|Data")
	bool ServerOnly_ValidateModuleInstallation(
		const FCommon_ItemSlot& Module,
		ESlotType SlotType,
		const FCommon_ShipFittingData& CurrentFitting,
		float ShipBaseCPU,
		float ShipBasePowergrid,
		FString& OutErrorMessage
	);

	/**
	 * Calculate Final Stats
	 * Calculates final ship stats from base stats + all module bonuses
	 * @param BaseShield - Base shield HP
	 * @param BaseArmor - Base armor HP
	 * @param BaseStructure - Base structure HP
	 * @param BaseCapacitor - Base capacitor
	 * @param BaseSpeed - Base max speed
	 * @param FittingData - Current fitting with all modules
	 * @param OutFinalStats - Populated with calculated stats
	 */
	UFUNCTION(BlueprintCallable, Category = "Server|Data")
	void ServerOnly_CalculateFinalStats(
		float BaseShield,
		float BaseArmor,
		float BaseStructure,
		float BaseCapacitor,
		float BaseSpeed,
		const FCommon_ShipFittingData& FittingData,
		FCommon_ShipFittingData& OutFinalStats
	);

	/**
	 * Request Fitting Data from ASP.NET API
	 * Makes HTTP GET request to backend to fetch character's fitting data
	 * @param CharacterID - Character ID to fetch fitting for
	 * @param APIBaseURLOverride - Optional API base URL override
	 */
	UFUNCTION(BlueprintCallable, Category = "Server|Data|HTTP")
	void ServerOnly_RequestFittingFromAPI(const FString& CharacterID, const FString& APIBaseURLOverride = TEXT(""));

	/**
	 * Get API Base URL from configuration
	 * Returns the configured API base URL or default
	 */
	UFUNCTION(BlueprintCallable, Category = "Server|Data|HTTP")
	FString GetAPIBaseURL() const;

	/**
	 * Get Server Secret from configuration
	 * Returns the X-Server-Secret header value
	 */
	UFUNCTION(BlueprintCallable, Category = "Server|Data|HTTP")
	FString GetServerSecret() const;

private:
	/**
	 * HTTP Response Handler for Fitting Request
	 * Called when HTTP request for fitting data completes
	 */
	void OnFittingDataReceived(
		FHttpRequestPtr Request,
		FHttpResponsePtr Response,
		bool bWasSuccessful,
		FString CharacterID
	);

	/** API Base URL (configurable) */
	UPROPERTY(EditDefaultsOnly, Category = "Server|Configuration")
	FString APIBaseURL = TEXT("http://localhost:5116");

	/** Server Secret for API authentication */
	UPROPERTY(EditDefaultsOnly, Category = "Server|Configuration")
	FString ServerSecret = TEXT("UE5-Server-Secret-Change-Me-In-Production");

private:
	/**
	 * Parse Module from JSON Value
	 * Helper to parse a single module from a JSON value
	 */
	bool ParseModuleFromJsonValue(const TSharedPtr<FJsonValue>& JsonValue, FCommon_ItemSlot& OutSlot);

	/**
	 * Apply Stat Modifiers
	 * Applies all modifiers from modules to base stats
	 */
	void ApplyStatModifiers(
		const TArray<FStatModifier>& Modifiers,
		float& OutShield,
		float& OutArmor,
		float& OutStructure,
		float& OutCapacitor,
		float& OutSpeed,
		float& OutScanResolution,
		float& OutSignatureRadius,
		float& OutDPS,
		float& OutEHP
	);

	/**
	 * Calculate Effective HP
	 * Calculates EHP based on HP and resistances
	 */
	float CalculateEffectiveHP(float HP, float EMResist, float ThermalResist, float KineticResist, float ExplosiveResist);

	/**
	 * Extract Modifiers from Slot
	 * Extracts all stat modifiers from a module slot
	 */
	void ExtractModifiersFromSlot(const FCommon_ItemSlot& Slot, TArray<FStatModifier>& OutModifiers);
};
