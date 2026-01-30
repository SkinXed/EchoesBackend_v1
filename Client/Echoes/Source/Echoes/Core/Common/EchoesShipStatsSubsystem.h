// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Core/Common/EchoesShipTypes.h"
#include "EchoesShipStatsSubsystem.generated.h"

// Delegate types for async callbacks (must be declared before class)
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnShipStatsFetched, const FEchoesShipStats&, Stats);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnModuleAdded, bool, bSuccess);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnApiError, const FString&, ErrorMessage);

/**
 * Subsystem for communicating with Ship Controller API
 * "Зеркальность" - Mirrors backend ShipController
 * 
 * Handles fetching ship stats from ASP.NET Core backend
 */

UCLASS(Config = Game)
class ECHOES_API UEchoesShipStatsSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    // ==================== API Configuration ====================
    
    /** Backend API URL */
    UPROPERTY(Config, EditAnywhere, Category = "API")
    FString ApiBaseUrl = TEXT("http://localhost:5116/api");

    /** Server secret for authentication */
    UPROPERTY(Config, EditAnywhere, Category = "API")
    FString ServerSecret = TEXT("UE5-Server-Secret-Change-Me-In-Production");

    // ==================== API Methods ====================
    
    /**
     * Fetch ship stats from backend
     * GET /api/ship/{id}/stats
     * @param ShipInstanceId - Ship instance GUID
     * @param OnSuccess - Called when stats are successfully fetched
     * @param OnError - Called on error
     */
    UFUNCTION(BlueprintCallable, Category = "Ship Stats")
    void FetchShipStats(
        FGuid ShipInstanceId,
        const FOnShipStatsFetched& OnSuccess,
        const FOnApiError& OnError
    );

    /**
     * Add module to ship
     * POST /api/ship/{id}/modules
     */
    UFUNCTION(BlueprintCallable, Category = "Ship Stats")
    void AddModule(
        FGuid ShipInstanceId,
        int32 ModuleTypeId,
        float Mass,
        FString Slot,
        const FOnModuleAdded& OnSuccess,
        const FOnApiError& OnError
    );

protected:
    /** Internal method to make HTTP request with authentication */
    void MakeAuthenticatedRequest(
        const FString& Endpoint,
        const FString& Verb,
        const FString& Content,
        TFunction<void(const FString&)> OnSuccess,
        TFunction<void(const FString&)> OnError
    );

    /** Parse JSON response to ship stats */
    bool ParseShipStatsJson(const FString& JsonString, FEchoesShipStats& OutStats);
};
