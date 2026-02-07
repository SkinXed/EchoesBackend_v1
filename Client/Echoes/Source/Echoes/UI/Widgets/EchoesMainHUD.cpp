// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesMainHUD.h"
#include "Components/WidgetSwitcher.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Components/CanvasPanel.h"
#include "Components/Overlay.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Core/Common/Components/EchoesStatsComponent.h"
#include "TimerManager.h"

UEchoesMainHUD::UEchoesMainHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// No tick needed - event-driven updates only
	bIsFocusable = false;
	
	CurrentGameState = EGameState::Unknown;
	CachedPlayerController = nullptr;
	CachedShipPawn = nullptr;
}

void UEchoesMainHUD::NativeConstruct()
{
	Super::NativeConstruct();

	// Cache player controller
	CachedPlayerController = GetOwningPlayer();

	// Initialize widgets
	InitializeWidgets();

	// Bind ship events
	BindShipEvents();

	// Set initial state
	if (CurrentGameState == EGameState::Unknown)
	{
		SetGameState(InitialGameState);
	}

	// Start periodic update timer (event-driven, not Tick)
	if (CachedPlayerController && ShipStatusUpdateRate > 0.0f)
	{
		GetWorld()->GetTimerManager().SetTimer(
			ShipStatusUpdateTimer,
			this,
			&UEchoesMainHUD::ClientOnly_RefreshAllDisplays,
			ShipStatusUpdateRate,
			true  // Loop
		);
	}
}

void UEchoesMainHUD::NativeDestruct()
{
	// Unbind events
	UnbindShipEvents();

	// Clear timer
	if (GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(ShipStatusUpdateTimer);
	}

	Super::NativeDestruct();
}

// ==================== State Management ====================

void UEchoesMainHUD::SetGameState(EGameState NewState)
{
	if (CurrentGameState == NewState)
	{
		return;  // No change
	}

	EGameState OldState = CurrentGameState;
	CurrentGameState = NewState;

	// Switch widget mode
	switch (NewState)
	{
	case EGameState::InHangar:
		SwitchToHangarMode();
		OnEnterHangar();
		break;

	case EGameState::InSpace:
		SwitchToSpaceMode();
		OnEnterSpace();
		break;

	default:
		UE_LOG(LogTemp, Warning, TEXT("UEchoesMainHUD::SetGameState: Unknown state"));
		break;
	}

	// Broadcast event
	OnGameStateChanged.Broadcast(NewState);

	// Refresh displays for new state
	ClientOnly_RefreshAllDisplays();

	UE_LOG(LogTemp, Log, TEXT("UEchoesMainHUD: State changed from %d to %d"), 
		(int32)OldState, (int32)NewState);
}

// ==================== Ship Status Updates (ClientOnly_) ====================

void UEchoesMainHUD::ClientOnly_UpdateShipStatus(const FCommon_ShipDataStruct& ShipData)
{
	// Update shield bar
	if (ShieldBar)
	{
		float ShieldPct = ShipData.GetShieldPercentage();
		UpdateProgressBar(ShieldBar, ShipData.ShieldCurrent, ShipData.ShieldMax, 
			Common_GetHealthBarColor(ShieldPct));
	}

	// Update shield text
	if (ShieldText)
	{
		UpdateValueText(ShieldText, ShipData.ShieldCurrent, ShipData.ShieldMax);
	}

	// Update armor bar
	if (ArmorBar)
	{
		float ArmorPct = ShipData.GetArmorPercentage();
		UpdateProgressBar(ArmorBar, ShipData.ArmorCurrent, ShipData.ArmorMax, 
			Common_GetHealthBarColor(ArmorPct));
	}

	// Update armor text
	if (ArmorText)
	{
		UpdateValueText(ArmorText, ShipData.ArmorCurrent, ShipData.ArmorMax);
	}

	// Update hull bar
	if (HullBar)
	{
		float HullPct = ShipData.GetStructurePercentage();
		UpdateProgressBar(HullBar, ShipData.StructureCurrent, ShipData.StructureMax, 
			Common_GetHealthBarColor(HullPct));
	}

	// Update hull text
	if (HullText)
	{
		UpdateValueText(HullText, ShipData.StructureCurrent, ShipData.StructureMax);
	}

	// Update capacitor
	ClientOnly_UpdateCapacitor(ShipData.CapacitorCurrent, ShipData.CapacitorMax);

	// Update speed
	ClientOnly_UpdateSpeed(ShipData.Speed, ShipData.MaxSpeed);

	// Update target count
	ClientOnly_UpdateTargetCount(ShipData.LockedTargetsCount, ShipData.MaxLockedTargets);

	// Store last data
	LastShipData = ShipData;

	// Broadcast event
	OnShipStatusUpdated.Broadcast(ShipData);
	OnShipDataChanged(ShipData);
}

void UEchoesMainHUD::ClientOnly_UpdateCapacitor(float Current, float Max)
{
	if (CapacitorBar)
	{
		float Percentage = Max > 0.0f ? Current / Max : 0.0f;
		CapacitorBar->SetPercent(FMath::Clamp(Percentage, 0.0f, 1.0f));
		
		// Capacitor color: Blue when full, yellow when low
		FLinearColor Color = Percentage > 0.25f ? FLinearColor(0.0f, 0.5f, 1.0f) : FLinearColor(1.0f, 1.0f, 0.0f);
		CapacitorBar->SetFillColorAndOpacity(Color);
	}
}

void UEchoesMainHUD::ClientOnly_UpdateSpeed(float Speed, float MaxSpeed)
{
	if (SpeedText)
	{
		FText FormattedSpeed = Common_FormatSpeed(Speed * 100.0f);  // Convert m/s to cm/s
		SpeedText->SetText(FormattedSpeed);
	}
}

void UEchoesMainHUD::ClientOnly_UpdateTargetCount(int32 Current, int32 Max)
{
	if (TargetCountText)
	{
		FText CountText = FText::FromString(FString::Printf(TEXT("%d/%d"), Current, Max));
		TargetCountText->SetText(CountText);
	}
}

void UEchoesMainHUD::ClientOnly_RefreshAllDisplays()
{
	// Get ship data via interface
	FCommon_ShipDataStruct ShipData = Common_GetShipData();
	
	// Update all displays
	ClientOnly_UpdateShipStatus(ShipData);
}

// ==================== Pure Calculation Functions (Common_) ====================

FVector UEchoesMainHUD::Common_GetTargetLeadIndicator(AActor* TargetActor, float ProjectileSpeed) const
{
	if (!TargetActor || ProjectileSpeed <= 0.0f)
	{
		return FVector::ZeroVector;
	}

	// Get player ship
	APawn* PlayerShip = GetPlayerShip();
	if (!PlayerShip)
	{
		return TargetActor->GetActorLocation();
	}

	// Get positions
	FVector ShooterPos = PlayerShip->GetActorLocation();
	FVector TargetPos = TargetActor->GetActorLocation();

	// Get target velocity
	FVector TargetVelocity = TargetActor->GetVelocity();
	
	// Calculate time to intercept using First-Order Intercept
	// This is the same algorithm used in CosmosWeaponComponent
	FVector ToTarget = TargetPos - ShooterPos;
	float Distance = ToTarget.Size();

	if (Distance < 1.0f)
	{
		return TargetPos;  // Too close
	}

	// Solve quadratic equation for intercept time
	// |TargetPos + TargetVel * t - ShooterPos| = ProjectileSpeed * t
	float a = TargetVelocity.SizeSquared() - (ProjectileSpeed * ProjectileSpeed);
	float b = 2.0f * FVector::DotProduct(ToTarget, TargetVelocity);
	float c = ToTarget.SizeSquared();

	// Check for valid solution
	float discriminant = (b * b) - (4.0f * a * c);
	if (discriminant < 0.0f)
	{
		// No intercept possible (target too fast)
		return TargetPos;
	}

	// Solve for t
	float t1 = (-b + FMath::Sqrt(discriminant)) / (2.0f * a);
	float t2 = (-b - FMath::Sqrt(discriminant)) / (2.0f * a);

	// Use smallest positive time
	float t = (t1 > 0.0f && (t2 <= 0.0f || t1 < t2)) ? t1 : t2;
	if (t <= 0.0f)
	{
		t = FMath::Max(t1, t2);
	}

	if (t <= 0.0f || t > 60.0f)  // Max 60 seconds lead
	{
		return TargetPos;
	}

	// Calculate predicted position
	FVector PredictedPos = TargetPos + (TargetVelocity * t);

	return PredictedPos;
}

FCommon_ShipDataStruct UEchoesMainHUD::Common_GetShipData() const
{
	FCommon_ShipDataStruct DefaultData;

	// Get ship state interface
	IShipStateInterface* ShipState = GetShipStateInterface();
	if (ShipState)
	{
		return ShipState->Execute_GetShipData(Cast<UObject>(ShipState));
	}

	// Fallback: Try to get data from components directly
	APawn* Ship = GetPlayerShip();
	if (Ship)
	{
		// Try to get stats component
		UEchoesStatsComponent* StatsComp = Ship->FindComponentByClass<UEchoesStatsComponent>();
		if (StatsComp)
		{
			DefaultData.ShieldCurrent = StatsComp->ShieldCurrent;
			DefaultData.ShieldMax = StatsComp->ShieldMax;
			DefaultData.ArmorCurrent = StatsComp->ArmorCurrent;
			DefaultData.ArmorMax = StatsComp->ArmorMax;
			DefaultData.StructureCurrent = StatsComp->StructureCurrent;
			DefaultData.StructureMax = StatsComp->StructureMax;
		}

		// Get velocity
		DefaultData.Velocity = Ship->GetVelocity();
		DefaultData.Speed = DefaultData.Velocity.Size() / 100.0f;  // Convert to m/s

		// Get location and rotation
		DefaultData.Location = Ship->GetActorLocation();
		DefaultData.Rotation = Ship->GetActorRotation();

		// Get ship name
		DefaultData.ShipName = Ship->GetName();
	}

	return DefaultData;
}

bool UEchoesMainHUD::Common_HasShipData() const
{
	return GetShipStateInterface() != nullptr || GetPlayerShip() != nullptr;
}

FLinearColor UEchoesMainHUD::Common_GetHealthBarColor(float Percentage) const
{
	// Color coding:
	// Green: > 50%
	// Yellow: 25-50%
	// Red: < 25%
	
	if (Percentage > 0.5f)
	{
		// Green
		return FLinearColor(0.0f, 1.0f, 0.0f);
	}
	else if (Percentage > 0.25f)
	{
		// Yellow
		return FLinearColor(1.0f, 1.0f, 0.0f);
	}
	else
	{
		// Red
		return FLinearColor(1.0f, 0.0f, 0.0f);
	}
}

FText UEchoesMainHUD::Common_FormatSpeed(float SpeedCmPerSec) const
{
	// Convert cm/s to m/s
	float SpeedMPerSec = SpeedCmPerSec / 100.0f;
	
	// Format with 1 decimal place
	FString FormattedSpeed = FString::Printf(TEXT("%.1f m/s"), SpeedMPerSec);
	
	return FText::FromString(FormattedSpeed);
}

FText UEchoesMainHUD::Common_FormatDistance(float DistanceCm) const
{
	// Convert to meters
	float DistanceM = DistanceCm / 100.0f;
	
	// If > 1000m, show in km
	if (DistanceM >= 1000.0f)
	{
		float DistanceKm = DistanceM / 1000.0f;
		FString FormattedDist = FString::Printf(TEXT("%.2f km"), DistanceKm);
		return FText::FromString(FormattedDist);
	}
	else
	{
		FString FormattedDist = FString::Printf(TEXT("%.0f m"), DistanceM);
		return FText::FromString(FormattedDist);
	}
}

// ==================== Internal Functions ====================

void UEchoesMainHUD::InitializeWidgets()
{
	// Validate widget bindings
	if (!ModeSwitcher)
	{
		UE_LOG(LogTemp, Warning, TEXT("UEchoesMainHUD: ModeSwitcher not bound! Widget switching will not work."));
	}

	if (!HangarHUD)
	{
		UE_LOG(LogTemp, Warning, TEXT("UEchoesMainHUD: HangarHUD not bound!"));
	}

	if (!SpaceHUD)
	{
		UE_LOG(LogTemp, Warning, TEXT("UEchoesMainHUD: SpaceHUD not bound!"));
	}

	// Log widget status
	if (bShowDebugInfo)
	{
		UE_LOG(LogTemp, Log, TEXT("UEchoesMainHUD: Initialized. ModeSwitcher=%s, HangarHUD=%s, SpaceHUD=%s"),
			ModeSwitcher ? TEXT("OK") : TEXT("NULL"),
			HangarHUD ? TEXT("OK") : TEXT("NULL"),
			SpaceHUD ? TEXT("OK") : TEXT("NULL"));
	}
}

void UEchoesMainHUD::BindShipEvents()
{
	// Get ship pawn
	APawn* Ship = GetPlayerShip();
	if (!Ship)
	{
		return;
	}

	// Cache ship reference
	CachedShipPawn = Ship;

	// Try to bind to stats component events
	UEchoesStatsComponent* StatsComp = Ship->FindComponentByClass<UEchoesStatsComponent>();
	if (StatsComp)
	{
		StatsComp->OnStatsChanged.AddDynamic(this, &UEchoesMainHUD::OnShipStatsChanged);
		
		if (bShowDebugInfo)
		{
			UE_LOG(LogTemp, Log, TEXT("UEchoesMainHUD: Bound to ship stats events"));
		}
	}
}

void UEchoesMainHUD::UnbindShipEvents()
{
	if (CachedShipPawn)
	{
		UEchoesStatsComponent* StatsComp = CachedShipPawn->FindComponentByClass<UEchoesStatsComponent>();
		if (StatsComp)
		{
			StatsComp->OnStatsChanged.RemoveDynamic(this, &UEchoesMainHUD::OnShipStatsChanged);
		}
	}

	CachedShipPawn = nullptr;
}

APawn* UEchoesMainHUD::GetPlayerShip() const
{
	if (CachedPlayerController)
	{
		return CachedPlayerController->GetPawn();
	}
	return nullptr;
}

IShipStateInterface* UEchoesMainHUD::GetShipStateInterface() const
{
	APawn* Ship = GetPlayerShip();
	if (Ship)
	{
		return Cast<IShipStateInterface>(Ship);
	}
	return nullptr;
}

void UEchoesMainHUD::UpdateProgressBar(UProgressBar* Bar, float Current, float Max, const FLinearColor& Color)
{
	if (Bar)
	{
		float Percentage = Max > 0.0f ? Current / Max : 0.0f;
		Bar->SetPercent(FMath::Clamp(Percentage, 0.0f, 1.0f));
		Bar->SetFillColorAndOpacity(Color);
	}
}

void UEchoesMainHUD::UpdateValueText(UTextBlock* TextBlock, float Current, float Max)
{
	if (TextBlock)
	{
		FString ValueString = FString::Printf(TEXT("%.0f/%.0f"), Current, Max);
		TextBlock->SetText(FText::FromString(ValueString));
	}
}

void UEchoesMainHUD::SwitchToHangarMode()
{
	if (ModeSwitcher)
	{
		ModeSwitcher->SetActiveWidgetIndex(0);  // Index 0 = HangarHUD
		
		if (bShowDebugInfo)
		{
			UE_LOG(LogTemp, Log, TEXT("UEchoesMainHUD: Switched to Hangar mode"));
		}
	}
}

void UEchoesMainHUD::SwitchToSpaceMode()
{
	if (ModeSwitcher)
	{
		ModeSwitcher->SetActiveWidgetIndex(1);  // Index 1 = SpaceHUD
		
		if (bShowDebugInfo)
		{
			UE_LOG(LogTemp, Log, TEXT("UEchoesMainHUD: Switched to Space mode"));
		}
	}
}

void UEchoesMainHUD::OnShipStatsChanged(float ShieldPct, float ArmorPct, float StructPct)
{
	// Event-driven update triggered by ship component
	// This is more efficient than Tick
	
	if (bShowDebugInfo)
	{
		UE_LOG(LogTemp, Verbose, TEXT("UEchoesMainHUD: Ship stats changed - Shield=%.1f%%, Armor=%.1f%%, Struct=%.1f%%"),
			ShieldPct * 100.0f, ArmorPct * 100.0f, StructPct * 100.0f);
	}

	// Refresh all displays
	ClientOnly_RefreshAllDisplays();
}
