// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Core/Common/EchoesShipTypes.h"
#include "EchoesShipPawn.generated.h"

class UEchoesShipMovementComponent;
class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

/**
 * Ship pawn with physics-based movement and camera
 * Client-side implementation with Enhanced Input
 */
UCLASS()
class ECHOES_API AEchoesShipPawn : public APawn
{
    GENERATED_BODY()

public:
    AEchoesShipPawn();

protected:
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    // ==================== Components ====================
    
    /** Ship mesh with physics simulation */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* ShipMesh;

    /** Custom ship movement component */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UEchoesShipMovementComponent* ShipMovement;

    /** Spring arm for camera (provides lag and smoothing) */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    USpringArmComponent* SpringArm;

    /** Camera component */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UCameraComponent* Camera;

    // ==================== Enhanced Input ====================
    
    /** Input Mapping Context */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    UInputMappingContext* InputMapping;

    /** Move action (WASD) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    UInputAction* MoveAction;

    /** Look action (Mouse) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    UInputAction* LookAction;

    /** Mouse follow toggle action */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    UInputAction* MouseFollowAction;

    /** Warp action */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    UInputAction* WarpAction;

    /** Free look action (Alt key) */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    UInputAction* FreeLookAction;

    // ==================== Configuration ====================
    
    /** Camera distance from ship */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
    float CameraDistance = 1000.0f;

    /** Camera lag speed (provides mass feel on acceleration) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
    float CameraLagSpeed = 3.0f;

    /** Whether camera lag is enabled */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
    bool bEnableCameraLag = true;

    /** Camera pitch angle (degrees) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
    float CameraPitch = -30.0f;

    /** Mouse sensitivity for camera control */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    float MouseSensitivity = 1.0f;

    /** Whether free look is currently active */
    UPROPERTY(BlueprintReadOnly, Category = "Camera")
    bool bFreeLookActive = false;

    // ==================== Ship Stats ====================
    
    /** Initialize ship from backend stats (Common - can be called on any side) */
    UFUNCTION(BlueprintCallable, Category = "Ship")
    void Common_InitializeFromStats(const FEchoesShipStats& Stats);
    
    /** Legacy function name for backward compatibility */
    UFUNCTION(BlueprintCallable, Category = "Ship")
    void InitializeShipStats(const FEchoesShipStats& Stats);

    /** Get current ship stats */
    UFUNCTION(BlueprintPure, Category = "Ship")
    FEchoesShipStats GetShipStats() const;
    
    /** Server RPC to request ship initialization with ownership verification */
    UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Ship")
    void ServerRPC_RequestShipInitialization(const FString& ShipId);
    
    /** Implementation of server RPC */
    void ServerRPC_RequestShipInitialization_Implementation(const FString& ShipId);
    
protected:
    /** Replicated ship stats - authoritative on server */
    UPROPERTY(ReplicatedUsing = OnRep_ShipStats, BlueprintReadOnly, Category = "Ship")
    FEchoesShipStats ReplicatedShipStats;
    
    /** Called when ship stats are replicated from server to client */
    UFUNCTION()
    void OnRep_ShipStats();
    
    /** Subscribe to inventory subsystem for fitting updates */
    void SubscribeToInventoryUpdates();
    
    /** Unsubscribe from inventory subsystem */
    void UnsubscribeFromInventoryUpdates();
    
    /** Handle fitting received from inventory subsystem */
    UFUNCTION()
    void OnFittingReceived(const FEchoesShipStats& Stats);
    
public:
    /** Override to replicate properties */
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    // ==================== Input Handlers ====================
    
    /** Called for movement input (WASD) */
    void Client_HandleMove(const FInputActionValue& Value);

    /** Called for look input (Mouse) */
    void Client_HandleLook(const FInputActionValue& Value);

    /** Called to toggle mouse follow */
    void Client_HandleMouseFollowToggle();

    /** Called to initiate warp */
    void Client_HandleWarp();

    /** Called when free look is started */
    void Client_HandleFreeLookStarted();

    /** Called when free look is completed */
    void Client_HandleFreeLookCompleted();

    // ==================== Camera ====================
    
    /** Update camera to follow ship with lag */
    void Client_UpdateCamera(float DeltaTime);

    /** Calculate target direction from camera forward vector */
    FVector Client_GetCameraTargetDirection() const;

private:
    /** Whether mouse follow is currently active */
    bool bMouseFollowActive;

    /** Current camera yaw offset */
    float CurrentCameraYaw;

    /** Current camera pitch offset */
    float CurrentCameraPitch;
};
