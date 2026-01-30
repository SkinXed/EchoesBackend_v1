// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesShipPawn.h"
#include "Core/Common/EchoesShipMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Kismet/KismetMathLibrary.h"

AEchoesShipPawn::AEchoesShipPawn()
{
    PrimaryActorTick.bCanEverTick = true;

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
}

void AEchoesShipPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Update camera
    Client_UpdateCamera(DeltaTime);

    // Update target direction from camera if mouse follow is active
    if (bMouseFollowActive && ShipMovement)
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
    }
}

// ==================== Ship Stats ====================

void AEchoesShipPawn::InitializeShipStats(const FEchoesShipStats& Stats)
{
    if (ShipMovement)
    {
        ShipMovement->InitializeShipStats(Stats);
    }
}

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
