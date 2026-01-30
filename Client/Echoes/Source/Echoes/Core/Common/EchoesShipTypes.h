// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EchoesShipTypes.generated.h"

/**
 * Warp state enum - mirrors ship warp lifecycle
 * Used by movement component to track warp progression
 */
UENUM(BlueprintType)
enum class EWarpState : uint8
{
    Idle UMETA(DisplayName = "Idle"),
    Aligning UMETA(DisplayName = "Aligning"),
    Warping UMETA(DisplayName = "Warping"),
    Exiting UMETA(DisplayName = "Exiting")
};

/**
 * Ship statistics struct
 * MIRRORS C# ShipStatsDto - Keep in sync with backend!
 * Used to initialize ship physics from backend data
 */
USTRUCT(BlueprintType)
struct FEchoesShipStats
{
    GENERATED_BODY()

    /** Total mass including base mass and all module masses (kg) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship Stats")
    float TotalMass = 1000000.0f;

    /** Base mass without modules (kg) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship Stats")
    float BaseMass = 1000000.0f;

    /** Thrust force in Newtons */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship Stats")
    float Thrust = 500000.0f;

    /** Maximum rotation speed in degrees per second */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship Stats")
    float RotationSpeed = 30.0f;

    /** Maximum warp speed multiplier (AU/s) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship Stats")
    float WarpSpeed = 3.0f;

    /** Inertia multiplier affecting acceleration/deceleration */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship Stats")
    float InertiaMultiplier = 1.0f;

    /** Maximum velocity in meters per second */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship Stats")
    float MaxVelocity = 100.0f;

    /** Agility modifier (lower is more agile) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship Stats")
    float Agility = 1.0f;

    /** Ship instance ID from backend */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship Stats")
    FGuid ShipId;

    /** Ship instance name */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship Stats")
    FString ShipName;

    /** Ship type ID from backend */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship Stats")
    int32 ShipTypeId = 0;

    /** Ship type name */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship Stats")
    FString ShipTypeName;

    FEchoesShipStats()
    {
        ShipId = FGuid();
        ShipName = TEXT("Unknown Ship");
        ShipTypeName = TEXT("Unknown Type");
    }
};
