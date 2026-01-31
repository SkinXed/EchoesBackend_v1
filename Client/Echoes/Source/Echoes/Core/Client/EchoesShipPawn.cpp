// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesShipPawn.h"
#include "Core/Common/EchoesShipMovementComponent.h"
#include "Core/Common/Networking/EchoesInventorySubsystem.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Kismet/KismetMathLibrary.h"
#include "Net/UnrealNetwork.h"

AEchoesShipPawn::AEchoesShipPawn()
{
    PrimaryActorTick.bCanEverTick = true;
    
    // Enable replication
    bReplicates = true;
    SetReplicatingMovement(true);

    // Create ship mesh component
    ShipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
    RootComponent = ShipMesh;
    
    // Enable physics simulation
    ShipMesh->SetSimulatePhysics(true);
    ShipMesh->SetEnableGravity(false); // Space - no gravity
    ShipMesh->SetLinearDamping(0.1f); // Minimal damping for space feel
    ShipMesh->SetAngularDamping(0.5f);
    ShipMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    ShipMesh->SetCollisionProfileName(TEXT("PhysicsActor"));

    // Create movement component
    ShipMovement = CreateDefaultSubobject<UEchoesShipMovementComponent>(TEXT("ShipMovement"));
    ShipMovement->SetUpdatedComponent(ShipMesh);

    // Create spring arm for camera
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->TargetArmLength = CameraDistance;
    SpringArm->bEnableCameraLag = true;
    SpringArm->CameraLagSpeed = CameraLagSpeed;
    SpringArm->bEnableCameraRotationLag = true;
    SpringArm->CameraRotationLagSpeed = CameraLagSpeed;
    SpringArm->bDoCollisionTest = false; // No collision in space
    SpringArm->SetRelativeRotation(FRotator(CameraPitch, 0.0f, 0.0f));

    // Create camera
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

    // Initialize variables
    bMouseFollowActive = false;
    CurrentCameraYaw = 0.0f;
    CurrentCameraPitch = CameraPitch;
}

void AEchoesShipPawn::BeginPlay()
{
    Super::BeginPlay();

    // Set up Enhanced Input
    if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = 
            ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
        {
            if (InputMapping)
            {
                Subsystem->AddMappingContext(InputMapping, 0);
            }
        }
    }

    // Configure camera lag
    if (SpringArm)
    {
        SpringArm->bEnableCameraLag = bEnableCameraLag;
        SpringArm->CameraLagSpeed = CameraLagSpeed;
        SpringArm->TargetArmLength = CameraDistance;
    }
    
    // Subscribe to inventory updates (only on client or listen server)
    if (!HasAuthority() || GetNetMode() == NM_ListenServer)
    {
        SubscribeToInventoryUpdates();
    }
}

void AEchoesShipPawn::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    // Unsubscribe from inventory updates
    UnsubscribeFromInventoryUpdates();
    
    Super::EndPlay(EndPlayReason);
}

void AEchoesShipPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Update camera
    Client_UpdateCamera(DeltaTime);

    // Update target direction from camera if mouse follow is active AND not in free look
    if (bMouseFollowActive && !bFreeLookActive && ShipMovement)
    {
        FVector TargetDir = Client_GetCameraTargetDirection();
        ShipMovement->SetTargetDirection(TargetDir);
    }
}

void AEchoesShipPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        // Bind movement action
        if (MoveAction)
        {
            EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AEchoesShipPawn::Client_HandleMove);
        }

        // Bind look action
        if (LookAction)
        {
            EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AEchoesShipPawn::Client_HandleLook);
        }

        // Bind mouse follow toggle
        if (MouseFollowAction)
        {
            EnhancedInputComponent->BindAction(MouseFollowAction, ETriggerEvent::Started, this, &AEchoesShipPawn::Client_HandleMouseFollowToggle);
        }

        // Bind warp action
        if (WarpAction)
        {
            EnhancedInputComponent->BindAction(WarpAction, ETriggerEvent::Started, this, &AEchoesShipPawn::Client_HandleWarp);
        }

        // Bind free look action
        if (FreeLookAction)
        {
            EnhancedInputComponent->BindAction(FreeLookAction, ETriggerEvent::Started, this, &AEchoesShipPawn::Client_HandleFreeLookStarted);
            EnhancedInputComponent->BindAction(FreeLookAction, ETriggerEvent::Completed, this, &AEchoesShipPawn::Client_HandleFreeLookCompleted);
        }
    }
}

// ==================== Ship Stats ====================

FEchoesShipStats AEchoesShipPawn::GetShipStats() const
{
    if (ShipMovement)
    {
        return ShipMovement->ShipStats;
    }
    return FEchoesShipStats();
}

// ==================== Input Handlers (Client_) ====================

void AEchoesShipPawn::Client_HandleMove(const FInputActionValue& Value)
{
    if (!ShipMovement)
    {
        return;
    }

    // Get 3D movement input
    const FVector MovementVector = Value.Get<FVector>();
    
    // Pass input to movement component
    ShipMovement->SetMovementInput(MovementVector);
}

void AEchoesShipPawn::Client_HandleLook(const FInputActionValue& Value)
{
    // Get look delta
    const FVector2D LookVector = Value.Get<FVector2D>();
    
    // Update camera rotation
    CurrentCameraYaw += LookVector.X * MouseSensitivity;
    CurrentCameraPitch = FMath::Clamp(CurrentCameraPitch + LookVector.Y * MouseSensitivity, -80.0f, 0.0f);

    // Apply rotation to spring arm
    if (SpringArm)
    {
        SpringArm->SetRelativeRotation(FRotator(CurrentCameraPitch, CurrentCameraYaw, 0.0f));
    }
}

void AEchoesShipPawn::Client_HandleMouseFollowToggle()
{
    bMouseFollowActive = !bMouseFollowActive;
    
    if (ShipMovement)
    {
        ShipMovement->SetMouseFollowEnabled(bMouseFollowActive);
    }

    UE_LOG(LogTemp, Log, TEXT("Mouse follow: %s"), bMouseFollowActive ? TEXT("ON") : TEXT("OFF"));
}

void AEchoesShipPawn::Client_HandleWarp()
{
    if (!ShipMovement)
    {
        return;
    }

    // For now, warp 10km forward in current direction
    // In a real implementation, this would be a targeted warp to a selected location
    FVector CurrentLocation = GetActorLocation();
    FVector ForwardVector = GetActorForwardVector();
    FVector WarpTarget = CurrentLocation + (ForwardVector * 1000000.0f); // 10km forward

    ShipMovement->InitiateWarp(WarpTarget);
    
    UE_LOG(LogTemp, Log, TEXT("Warp initiated"));
}

void AEchoesShipPawn::Client_HandleFreeLookStarted()
{
    bFreeLookActive = true;
    
    // Disable mouse follow temporarily during free look
    if (ShipMovement && bMouseFollowActive)
    {
        ShipMovement->SetMouseFollowEnabled(false);
    }
    
    UE_LOG(LogTemp, Log, TEXT("Free look started"));
}

void AEchoesShipPawn::Client_HandleFreeLookCompleted()
{
    bFreeLookActive = false;
    
    // Re-enable mouse follow if it was active
    if (ShipMovement && bMouseFollowActive)
    {
        ShipMovement->SetMouseFollowEnabled(true);
    }
    
    UE_LOG(LogTemp, Log, TEXT("Free look completed"));
}

// ==================== Camera (Client_) ====================

void AEchoesShipPawn::Client_UpdateCamera(float DeltaTime)
{
    if (!SpringArm)
    {
        return;
    }

    // Camera lag is handled automatically by SpringArmComponent
    // The lag effect gives the sense of mass during acceleration
    
    // Update spring arm length if changed
    if (FMath::Abs(SpringArm->TargetArmLength - CameraDistance) > 1.0f)
    {
        SpringArm->TargetArmLength = FMath::FInterpTo(
            SpringArm->TargetArmLength, 
            CameraDistance, 
            DeltaTime, 
            5.0f
        );
    }

    // Update lag settings if changed
    SpringArm->bEnableCameraLag = bEnableCameraLag;
    SpringArm->CameraLagSpeed = CameraLagSpeed;
}

FVector AEchoesShipPawn::Client_GetCameraTargetDirection() const
{
    if (Camera)
    {
        // Get camera forward vector as target direction
        return Camera->GetForwardVector();
    }
    return GetActorForwardVector();
}

// ==================== Replication ====================

void AEchoesShipPawn::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    // Replicate ship stats from server to all clients
    DOREPLIFETIME(AEchoesShipPawn, ReplicatedShipStats);
}

void AEchoesShipPawn::OnRep_ShipStats()
{
    // Ship stats replicated from server - apply them locally
    UE_LOG(LogTemp, Log, TEXT("Ship stats replicated: Mass=%.1f, Thrust=%.1f"), 
        ReplicatedShipStats.TotalMass, ReplicatedShipStats.Thrust);
    
    // Apply stats to movement component and mesh
    Common_InitializeFromStats(ReplicatedShipStats);
}

// ==================== Ship Initialization ====================

void AEchoesShipPawn::Common_InitializeFromStats(const FEchoesShipStats& Stats)
{
    UE_LOG(LogTemp, Log, TEXT("Initializing ship with stats: Mass=%.1f, Thrust=%.1f, Inertia=%.3f"), 
        Stats.TotalMass, Stats.Thrust, Stats.InertiaMultiplier);
    
    // Apply stats to movement component
    if (ShipMovement)
    {
        ShipMovement->InitializeShipStats(Stats);
    }
    
    // Update mesh mass and physics properties
    if (ShipMesh)
    {
        // Set mass directly on physics body
        ShipMesh->SetMassOverrideInKg(NAME_None, Stats.TotalMass, true);
        
        // Update linear damping based on inertia multiplier
        // Higher inertia = more damping for realistic "heavy" feel
        float LinearDamping = Stats.InertiaMultiplier * 0.1f;
        ShipMesh->SetLinearDamping(LinearDamping);
        
        UE_LOG(LogTemp, Log, TEXT("Updated mesh mass to %.1f kg, linear damping to %.3f"), 
            Stats.TotalMass, LinearDamping);
    }
    
    // If we're the server, update the replicated stats
    if (HasAuthority())
    {
        ReplicatedShipStats = Stats;
    }
}

void AEchoesShipPawn::InitializeShipStats(const FEchoesShipStats& Stats)
{
    // Legacy function - redirect to new function
    Common_InitializeFromStats(Stats);
}

void AEchoesShipPawn::HandleShipFittingReceived(const FEchoesShipFitting& Fitting)
{
    // Convert ShipFitting to ShipStats
    FEchoesShipStats Stats;
    Stats.TotalMass = Fitting.TotalMass;
    Stats.Thrust = Fitting.Thrust;
    Stats.InertiaMultiplier = Fitting.InertiaMultiplier;
    Stats.RotationSpeed = Fitting.RotationTorque;
    Stats.MaxVelocity = Fitting.MaxVelocity;
    Stats.WarpSpeed = 1000000.0f; // Default warp speed
    
    UE_LOG(LogTemp, Log, TEXT("Server verified ship ownership and fetched stats. Initializing physics."));
    
    // Initialize physics (this will replicate to clients)
    Common_InitializeFromStats(Stats);
}

void AEchoesShipPawn::HandleShipFittingFailed(const FString& Error)
{
    UE_LOG(LogTemp, Error, TEXT("Server failed to verify ship ownership: %s"), *Error);
    // Don't initialize - ship ownership not verified
}

void AEchoesShipPawn::ServerRPC_RequestShipInitialization_Implementation(const FString& ShipId)
{
    // Server-side: Verify ship ownership and initialize physics
    UE_LOG(LogTemp, Log, TEXT("Server received ship initialization request for ShipId: %s"), *ShipId);
    
    // Get the inventory subsystem
    if (UGameInstance* GameInstance = GetGameInstance())
    {
        if (UEchoesInventorySubsystem* InventorySubsystem = GameInstance->GetSubsystem<UEchoesInventorySubsystem>())
        {
            // First, verify ownership
            // Fetch ship fitting from backend (this will verify ownership via JWT)
            FOnShipFittingReceived OnSuccess;
            OnSuccess.BindDynamic(this, &AEchoesShipPawn::HandleShipFittingReceived);
            
            FOnInventoryFailure OnFailure;
            OnFailure.BindDynamic(this, &AEchoesShipPawn::HandleShipFittingFailed);
            
            // Attempt to fetch ship fitting (includes ownership verification)
            FGuid ShipGuid;
            if (FGuid::Parse(ShipId, ShipGuid))
            {
                InventorySubsystem->Inventory_FetchShipFitting(ShipGuid, OnSuccess, OnFailure);
            }
            else
            {
                UE_LOG(LogTemp, Error, TEXT("Invalid ship GUID format: %s"), *ShipId);
            }
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("Inventory subsystem not found on server"));
        }
    }
}

// ==================== Inventory Integration ====================

void AEchoesShipPawn::SubscribeToInventoryUpdates()
{
    if (UGameInstance* GameInstance = GetGameInstance())
    {
        if (UEchoesInventorySubsystem* InventorySubsystem = GameInstance->GetSubsystem<UEchoesInventorySubsystem>())
        {
            // Subscribe to fitting updates
            // Note: This is a simplified subscription - in production you'd want a proper delegate system
            UE_LOG(LogTemp, Log, TEXT("Subscribed to inventory updates"));
        }
    }
}

void AEchoesShipPawn::UnsubscribeFromInventoryUpdates()
{
    // Unsubscribe from inventory subsystem
    // Note: In production, unbind delegates here
    UE_LOG(LogTemp, Log, TEXT("Unsubscribed from inventory updates"));
}

void AEchoesShipPawn::OnFittingReceived(const FEchoesShipStats& Stats)
{
    // Handle fitting update from inventory subsystem
    UE_LOG(LogTemp, Log, TEXT("Received fitting update from inventory subsystem"));
    
    // If we're on a client, request server to initialize
    if (!HasAuthority())
    {
        // TODO: Get actual ship ID from inventory subsystem
        // For now, this is a placeholder
        UE_LOG(LogTemp, Log, TEXT("Client requesting server initialization"));
    }
    else
    {
        // Server can initialize directly
        Common_InitializeFromStats(Stats);
    }
}
