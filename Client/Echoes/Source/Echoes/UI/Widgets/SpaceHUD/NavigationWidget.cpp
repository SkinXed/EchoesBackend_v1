// Copyright Epic Games, Inc. All Rights Reserved.

#include "NavigationWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/ProgressBar.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"
#include "Kismet/KismetMathLibrary.h"

UNavigationWidget::UNavigationWidget(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
, BoundShip(nullptr)
, CurrentTarget(nullptr)
, UpdateInterval(0.1f) // 10 Hz
, bShowVelocityVector(true)
, CurrentSpeed(0.0f)
, CurrentMaxSpeed(100.0f)
, CurrentVelocity(FVector::ZeroVector)
{
}

void UNavigationWidget::NativeConstruct()
{
Super::NativeConstruct();

// Bind button click events
if (AlignToButton)
{
AlignToButton->OnClicked.AddDynamic(this, &UNavigationWidget::HandleAlignToClicked);
}
if (OrbitButton)
{
OrbitButton->OnClicked.AddDynamic(this, &UNavigationWidget::HandleOrbitClicked);
}
if (WarpToButton)
{
WarpToButton->OnClicked.AddDynamic(this, &UNavigationWidget::HandleWarpToClicked);
}
if (ApproachButton)
{
ApproachButton->OnClicked.AddDynamic(this, &UNavigationWidget::HandleApproachClicked);
}
if (KeepAtRangeButton)
{
KeepAtRangeButton->OnClicked.AddDynamic(this, &UNavigationWidget::HandleKeepAtRangeClicked);
}
if (StopButton)
{
StopButton->OnClicked.AddDynamic(this, &UNavigationWidget::HandleStopClicked);
}

// Start periodic update timer
if (UWorld* World = GetWorld())
{
World->GetTimerManager().SetTimer(
UpdateTimerHandle,
this,
&UNavigationWidget::HandlePeriodicUpdate,
UpdateInterval,
true // Loop
);
}

UpdateButtonStates();
}

void UNavigationWidget::NativeDestruct()
{
UnbindFromShip();

// Clear timer
if (UWorld* World = GetWorld())
{
World->GetTimerManager().ClearTimer(UpdateTimerHandle);
}

Super::NativeDestruct();
}

void UNavigationWidget::BindToShip(AActor* Ship)
{
if (!Ship)
{
return;
}

UnbindFromShip();

BoundShip = Ship;

// Initial refresh
ClientOnly_RefreshDisplays();
}

void UNavigationWidget::UnbindFromShip()
{
BoundShip = nullptr;
}

void UNavigationWidget::SetNavigationTarget(AActor* Target)
{
CurrentTarget = Target;
UpdateButtonStates();
}

void UNavigationWidget::ClientOnly_UpdateSpeed(float CurrentSpeedValue, float MaxSpeed, FVector Velocity)
{
CurrentSpeed = CurrentSpeedValue;
CurrentMaxSpeed = MaxSpeed;
CurrentVelocity = Velocity;

// Update speed text (large display)
if (SpeedText)
{
FString SpeedStr = Common_FormatSpeed(CurrentSpeed);
SpeedText->SetText(FText::FromString(SpeedStr));
}

// Update max speed text
if (MaxSpeedText)
{
FString MaxSpeedStr = FString::Printf(TEXT("Max: %s"), *Common_FormatSpeed(MaxSpeed));
MaxSpeedText->SetText(FText::FromString(MaxSpeedStr));
}

// Update speed progress bar
if (SpeedBar)
{
float Percentage = (MaxSpeed > 0.0f) ? FMath::Clamp(CurrentSpeed / MaxSpeed, 0.0f, 1.0f) : 0.0f;
SpeedBar->SetPercent(Percentage);

// Color code based on speed
FLinearColor Color;
if (Percentage < 0.3f)
{
Color = FLinearColor::Gray; // Slow
}
else if (Percentage < 0.7f)
{
Color = FLinearColor::Yellow; // Medium
}
else
{
Color = FLinearColor::Green; // Fast
}
SpeedBar->SetFillColorAndOpacity(Color);
}

// Update velocity display
if (VelocityText && bShowVelocityVector)
{
float VelMagnitude = Velocity.Size() / 100.0f; // Convert cm/s to m/s
FString VelStr = Common_FormatSpeed(VelMagnitude);
VelocityText->SetText(FText::FromString(VelStr));
}

// Update velocity arrow
if (bShowVelocityVector)
{
UpdateVelocityArrow();
}
}

void UNavigationWidget::ClientOnly_RefreshDisplays()
{
if (!BoundShip)
{
return;
}

// Check if ship implements IShipStateInterface
if (BoundShip->Implements<UShipStateInterface>())
{
IShipStateInterface* ShipState = Cast<IShipStateInterface>(BoundShip);
if (ShipState)
{
FCommon_ShipDataStruct ShipData = ShipState->Execute_GetShipData(BoundShip);
ClientOnly_UpdateSpeed(ShipData.Speed, ShipData.MaxSpeed, ShipData.Velocity);
}
}
}

void UNavigationWidget::ServerRPC_ExecuteNavCommand(ENavigationCommand CommandType, AActor* Target)
{
// This would be implemented as actual ServerRPC in production
// For now, just broadcast the event
OnCommandIssued.Broadcast(CommandType, Target);
OnNavigationCommandExecuted(CommandType, Target);

UE_LOG(LogTemp, Log, TEXT("Navigation Command: %d issued for target: %s"), 
static_cast<int32>(CommandType), 
Target ? *Target->GetName() : TEXT("None"));
}

FString UNavigationWidget::Common_FormatSpeed(float SpeedInMps)
{
float AbsSpeed = FMath::Abs(SpeedInMps);

if (AbsSpeed < 1.0f)
{
return FString::Printf(TEXT("%.1f m/s"), AbsSpeed);
}
else if (AbsSpeed < 1000.0f)
{
return FString::Printf(TEXT("%.0f m/s"), AbsSpeed);
}
else
{
float KmPerSec = AbsSpeed / 1000.0f;
return FString::Printf(TEXT("%.1f km/s"), KmPerSec);
}
}

float UNavigationWidget::Common_GetVelocityBearing(FVector Velocity)
{
if (Velocity.SizeSquared() < 0.01f)
{
return 0.0f;
}

// Get 2D direction (top-down view, Z-up)
FVector2D Direction2D(Velocity.X, Velocity.Y);
Direction2D.Normalize();

// Convert to bearing (0 = North/+Y, clockwise)
float Angle = FMath::Atan2(Direction2D.X, Direction2D.Y);
float Bearing = FMath::RadiansToDegrees(Angle);

// Normalize to 0-360
if (Bearing < 0.0f)
{
Bearing += 360.0f;
}

return Bearing;
}

void UNavigationWidget::HandleAlignToClicked()
{
ExecuteCommand(ENavigationCommand::AlignTo);
}

void UNavigationWidget::HandleOrbitClicked()
{
ExecuteCommand(ENavigationCommand::Orbit);
}

void UNavigationWidget::HandleWarpToClicked()
{
ExecuteCommand(ENavigationCommand::WarpTo);
}

void UNavigationWidget::HandleApproachClicked()
{
ExecuteCommand(ENavigationCommand::Approach);
}

void UNavigationWidget::HandleKeepAtRangeClicked()
{
ExecuteCommand(ENavigationCommand::KeepAtRange);
}

void UNavigationWidget::HandleStopClicked()
{
ExecuteCommand(ENavigationCommand::Stop);
}

void UNavigationWidget::HandlePeriodicUpdate()
{
ClientOnly_RefreshDisplays();
}

void UNavigationWidget::UpdateButtonStates()
{
bool bHasTarget = (CurrentTarget != nullptr);

// Commands that require a target
if (AlignToButton)
{
AlignToButton->SetIsEnabled(bHasTarget);
}
if (OrbitButton)
{
OrbitButton->SetIsEnabled(bHasTarget);
}
if (WarpToButton)
{
WarpToButton->SetIsEnabled(bHasTarget);
}
if (ApproachButton)
{
ApproachButton->SetIsEnabled(bHasTarget);
}
if (KeepAtRangeButton)
{
KeepAtRangeButton->SetIsEnabled(bHasTarget);
}

// Stop command always available
if (StopButton)
{
StopButton->SetIsEnabled(true);
}
}

void UNavigationWidget::ExecuteCommand(ENavigationCommand CommandType)
{
// For commands that need a target, check if we have one
if (CommandType != ENavigationCommand::Stop && !CurrentTarget)
{
UE_LOG(LogTemp, Warning, TEXT("Cannot execute navigation command without target"));
return;
}

// Call ServerRPC
ServerRPC_ExecuteNavCommand(CommandType, CurrentTarget);
}

void UNavigationWidget::UpdateVelocityArrow()
{
if (!VelocityArrow)
{
return;
}

// Only rotate if we have significant velocity
if (CurrentVelocity.SizeSquared() < 100.0f) // Less than 1 m/s
{
VelocityArrow->SetVisibility(ESlateVisibility::Hidden);
return;
}

VelocityArrow->SetVisibility(ESlateVisibility::Visible);

// Calculate rotation angle
float Bearing = Common_GetVelocityBearing(CurrentVelocity);

// Rotate the arrow widget
VelocityArrow->SetRenderTransformAngle(Bearing);
}
