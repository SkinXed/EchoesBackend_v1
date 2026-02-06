// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ShipStateInterface.generated.h"

/**
 * Ship data structure for HUD display
 * Contains all relevant ship information for UI updates
 */
USTRUCT(BlueprintType)
struct FCommon_ShipDataStruct
{
	GENERATED_BODY()

	// ==================== Protection Stats ====================

	/** Shield current value */
	UPROPERTY(BlueprintReadOnly, Category = "Ship Data")
	float ShieldCurrent = 0.0f;

	/** Shield maximum value */
	UPROPERTY(BlueprintReadOnly, Category = "Ship Data")
	float ShieldMax = 100.0f;

	/** Armor current value */
	UPROPERTY(BlueprintReadOnly, Category = "Ship Data")
	float ArmorCurrent = 0.0f;

	/** Armor maximum value */
	UPROPERTY(BlueprintReadOnly, Category = "Ship Data")
	float ArmorMax = 100.0f;

	/** Structure (Hull) current value */
	UPROPERTY(BlueprintReadOnly, Category = "Ship Data")
	float StructureCurrent = 0.0f;

	/** Structure (Hull) maximum value */
	UPROPERTY(BlueprintReadOnly, Category = "Ship Data")
	float StructureMax = 100.0f;

	// ==================== Capacitor ====================

	/** Capacitor current value (energy for modules) */
	UPROPERTY(BlueprintReadOnly, Category = "Ship Data")
	float CapacitorCurrent = 0.0f;

	/** Capacitor maximum value */
	UPROPERTY(BlueprintReadOnly, Category = "Ship Data")
	float CapacitorMax = 100.0f;

	// ==================== Movement ====================

	/** Current velocity in cm/s */
	UPROPERTY(BlueprintReadOnly, Category = "Ship Data")
	FVector Velocity = FVector::ZeroVector;

	/** Current speed in m/s */
	UPROPERTY(BlueprintReadOnly, Category = "Ship Data")
	float Speed = 0.0f;

	/** Maximum speed in m/s */
	UPROPERTY(BlueprintReadOnly, Category = "Ship Data")
	float MaxSpeed = 100.0f;

	// ==================== Targeting ====================

	/** Number of locked targets */
	UPROPERTY(BlueprintReadOnly, Category = "Ship Data")
	int32 LockedTargetsCount = 0;

	/** Maximum number of targets that can be locked */
	UPROPERTY(BlueprintReadOnly, Category = "Ship Data")
	int32 MaxLockedTargets = 5;

	// ==================== Location ====================

	/** Current location in world space */
	UPROPERTY(BlueprintReadOnly, Category = "Ship Data")
	FVector Location = FVector::ZeroVector;

	/** Current rotation */
	UPROPERTY(BlueprintReadOnly, Category = "Ship Data")
	FRotator Rotation = FRotator::ZeroRotator;

	// ==================== Ship Info ====================

	/** Ship name */
	UPROPERTY(BlueprintReadOnly, Category = "Ship Data")
	FString ShipName = TEXT("Unknown Ship");

	/** Ship type/class */
	UPROPERTY(BlueprintReadOnly, Category = "Ship Data")
	FString ShipType = TEXT("Unknown Class");

	/** Constructor with default values */
	FCommon_ShipDataStruct()
	{
	}

	/**
	 * Get shield percentage (0.0 to 1.0)
	 */
	FORCEINLINE float GetShieldPercentage() const
	{
		return ShieldMax > 0.0f ? FMath::Clamp(ShieldCurrent / ShieldMax, 0.0f, 1.0f) : 0.0f;
	}

	/**
	 * Get armor percentage (0.0 to 1.0)
	 */
	FORCEINLINE float GetArmorPercentage() const
	{
		return ArmorMax > 0.0f ? FMath::Clamp(ArmorCurrent / ArmorMax, 0.0f, 1.0f) : 0.0f;
	}

	/**
	 * Get structure percentage (0.0 to 1.0)
	 */
	FORCEINLINE float GetStructurePercentage() const
	{
		return StructureMax > 0.0f ? FMath::Clamp(StructureCurrent / StructureMax, 0.0f, 1.0f) : 0.0f;
	}

	/**
	 * Get capacitor percentage (0.0 to 1.0)
	 */
	FORCEINLINE float GetCapacitorPercentage() const
	{
		return CapacitorMax > 0.0f ? FMath::Clamp(CapacitorCurrent / CapacitorMax, 0.0f, 1.0f) : 0.0f;
	}

	/**
	 * Get overall health percentage (average of all layers)
	 */
	FORCEINLINE float GetOverallHealthPercentage() const
	{
		return (GetShieldPercentage() + GetArmorPercentage() + GetStructurePercentage()) / 3.0f;
	}
};

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UShipStateInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * IShipStateInterface
 * 
 * Interface for accessing ship state data for HUD display
 * Implemented by ship pawns and components that provide ship data
 * 
 * Purpose:
 * - Decouple HUD widgets from specific component implementations
 * - Allow any actor to provide ship data to UI
 * - Support both component-based and actor-based architectures
 * 
 * Usage:
 * // In ship pawn or component
 * class AShipPawn : public APawn, public IShipStateInterface
 * {
 *     virtual FCommon_ShipDataStruct GetShipData_Implementation() const override;
 * };
 * 
 * // In HUD widget
 * if (IShipStateInterface* ShipState = Cast<IShipStateInterface>(OwningPawn))
 * {
 *     FCommon_ShipDataStruct Data = ShipState->GetShipData();
 *     UpdateShipStatus(Data);
 * }
 */
class ECHOES_API IShipStateInterface
{
	GENERATED_BODY()

public:
	/**
	 * Get current ship data for HUD display
	 * 
	 * @return Ship data structure with all relevant information
	 * 
	 * Note: This is called frequently by HUD, should be lightweight
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ship State")
	FCommon_ShipDataStruct GetShipData() const;

	/**
	 * Check if ship is currently alive
	 * 
	 * @return True if ship has structure > 0
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ship State")
	bool IsShipAlive() const;

	/**
	 * Get ship's current target (if any)
	 * 
	 * @return Currently targeted actor, or nullptr if none
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ship State")
	AActor* GetCurrentTarget() const;
};
