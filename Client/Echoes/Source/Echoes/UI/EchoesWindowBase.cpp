// Copyright Epic Games, Inc. All Rights Reserved.

#include "UI/EchoesWindowBase.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/Border.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/NamedSlot.h"
#include "Components/Image.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/GameUserSettings.h"
#include "Misc/ConfigCacheIni.h"

UEchoesWindowBase::UEchoesWindowBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Enable mouse events
	SetIsFocusable(true);
}

void UEchoesWindowBase::NativeConstruct()
{
	Super::NativeConstruct();

	// Initialize window ID
	InitializeWindowId();

	// Bind close button
	if (CloseButton)
	{
		CloseButton->OnClicked.AddDynamic(this, &UEchoesWindowBase::OnCloseButtonClicked);
	}

	// Get canvas slot
	CanvasSlot = GetCanvasSlot();

	// Set initial size
	if (CanvasSlot)
	{
		CanvasSlot->SetSize(DefaultWindowSize);
		CanvasSlot->SetPosition(DefaultWindowPosition);
	}

	// Load saved position if enabled
	if (bSavePosition)
	{
		LoadWindowPosition();
	}

	UE_LOG(LogTemp, Log, TEXT("Window '%s' constructed at position %s, size %s"),
		*WindowId, *GetWindowPosition().ToString(), *GetWindowSize().ToString());
}

void UEchoesWindowBase::NativeDestruct()
{
	// Save position before destroying
	if (bSavePosition)
	{
		SaveWindowPosition();
	}

	// Unbind close button
	if (CloseButton)
	{
		CloseButton->OnClicked.RemoveDynamic(this, &UEchoesWindowBase::OnCloseButtonClicked);
	}

	Super::NativeDestruct();
}

FReply UEchoesWindowBase::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	FReply Reply = Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);

	// Bring to front on any click
	BringToFront();
	OnWindowFocused();

	// Left mouse button
	if (InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton))
	{
		// Check if clicking on title bar for dragging
		if (bCanDrag && IsMouseOverTitleBar(InGeometry, InMouseEvent))
		{
			bIsDragging = true;
			
			// Calculate offset from mouse to window position
			FVector2D MousePosition = InMouseEvent.GetScreenSpacePosition();
			FVector2D WindowPosition = GetWindowPosition();
			DragOffset = WindowPosition - MousePosition;

			UE_LOG(LogTemp, Verbose, TEXT("Window '%s' drag started, offset: %s"),
				*WindowId, *DragOffset.ToString());

			Reply = FReply::Handled().CaptureMouse(TakeWidget());
		}
		// Check if clicking on resize handle
		else if (bCanResize && IsMouseOverResizeHandle(InGeometry, InMouseEvent))
		{
			bIsResizing = true;
			
			// Store initial size and mouse position
			ResizeStartSize = GetWindowSize();
			ResizeStartMousePos = InMouseEvent.GetScreenSpacePosition();

			UE_LOG(LogTemp, Verbose, TEXT("Window '%s' resize started, size: %s"),
				*WindowId, *ResizeStartSize.ToString());

			Reply = FReply::Handled().CaptureMouse(TakeWidget());
		}
	}

	return Reply;
}

FReply UEchoesWindowBase::NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	FReply Reply = Super::NativeOnMouseButtonUp(InGeometry, InMouseEvent);

	// Stop dragging
	if (bIsDragging)
	{
		bIsDragging = false;
		UE_LOG(LogTemp, Verbose, TEXT("Window '%s' drag stopped at position: %s"),
			*WindowId, *GetWindowPosition().ToString());
		Reply = FReply::Handled().ReleaseMouseCapture();
	}

	// Stop resizing
	if (bIsResizing)
	{
		bIsResizing = false;
		UE_LOG(LogTemp, Verbose, TEXT("Window '%s' resize stopped at size: %s"),
			*WindowId, *GetWindowSize().ToString());
		Reply = FReply::Handled().ReleaseMouseCapture();
	}

	return Reply;
}

FReply UEchoesWindowBase::NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	FReply Reply = Super::NativeOnMouseMove(InGeometry, InMouseEvent);

	// Handle dragging
	if (bIsDragging)
	{
		FVector2D MousePosition = InMouseEvent.GetScreenSpacePosition();
		FVector2D NewPosition = MousePosition + DragOffset;
		
		// Apply snapping if enabled
		if (bEnableSnapping)
		{
			NewPosition = ApplySnapping(NewPosition);
		}
		
		// Clamp to screen bounds
		NewPosition = ClampPositionToScreen(NewPosition);
		
		UpdateWindowPosition(NewPosition);
		Reply = FReply::Handled();
	}

	// Handle resizing
	if (bIsResizing)
	{
		FVector2D MousePosition = InMouseEvent.GetScreenSpacePosition();
		FVector2D MouseDelta = MousePosition - ResizeStartMousePos;
		FVector2D NewSize = ResizeStartSize + MouseDelta;
		
		// Clamp to min/max size
		NewSize = ClampSize(NewSize);
		
		UpdateWindowSize(NewSize);
		Reply = FReply::Handled();
	}

	return Reply;
}

void UEchoesWindowBase::SetWindowTitle(const FText& Title)
{
	if (TitleText)
	{
		TitleText->SetText(Title);
	}
}

FText UEchoesWindowBase::GetWindowTitle() const
{
	if (TitleText)
	{
		return TitleText->GetText();
	}
	return FText::GetEmpty();
}

void UEchoesWindowBase::CloseWindow()
{
	UE_LOG(LogTemp, Log, TEXT("Closing window '%s'"), *WindowId);

	// Trigger Blueprint event
	OnWindowClosed();

	// Remove from parent and destroy
	RemoveFromParent();
}

void UEchoesWindowBase::SetWindowPosition(FVector2D Position)
{
	Position = ClampPositionToScreen(Position);
	UpdateWindowPosition(Position);
}

FVector2D UEchoesWindowBase::GetWindowPosition() const
{
	if (CanvasSlot)
	{
		return CanvasSlot->GetPosition();
	}
	return FVector2D::ZeroVector;
}

void UEchoesWindowBase::SetWindowSize(FVector2D Size)
{
	Size = ClampSize(Size);
	UpdateWindowSize(Size);
}

FVector2D UEchoesWindowBase::GetWindowSize() const
{
	if (CanvasSlot)
	{
		return CanvasSlot->GetSize();
	}
	return DefaultWindowSize;
}

void UEchoesWindowBase::BringToFront()
{
	UPanelWidget* Parent = GetParent();
	if (!Parent)
	{
		return;
	}

	// Get current highest Z-order
	int32 HighestZOrder = 0;
	for (int32 i = 0; i < Parent->GetChildrenCount(); ++i)
	{
		UWidget* Child = Parent->GetChildAt(i);
		if (Child && Child != this)
		{
			if (UCanvasPanelSlot* ChildSlot = Cast<UCanvasPanelSlot>(Child->Slot))
			{
				HighestZOrder = FMath::Max(HighestZOrder, ChildSlot->GetZOrder());
			}
		}
	}

	// Set this window to highest + 1
	if (CanvasSlot)
	{
		CanvasSlot->SetZOrder(HighestZOrder + 1);
		UE_LOG(LogTemp, Verbose, TEXT("Window '%s' brought to front with Z-order: %d"),
			*WindowId, HighestZOrder + 1);
	}
}

void UEchoesWindowBase::SaveWindowPosition()
{
	if (!bSavePosition || WindowId.IsEmpty())
	{
		return;
	}

	FVector2D Position = GetWindowPosition();
	FVector2D Size = GetWindowSize();
	
	// Save to game user settings
	if (UGameUserSettings* Settings = UGameUserSettings::GetGameUserSettings())
	{
		// Use console variables for persistence
		// Format: "WindowName.Position.X WindowName.Position.Y WindowName.Size.X WindowName.Size.Y"
		FString ConfigSection = TEXT("Echoes.Windows");
		FString PositionKey = FString::Printf(TEXT("%s.Position"), *WindowId);
		FString SizeKey = FString::Printf(TEXT("%s.Size"), *WindowId);
		
		// Store as strings in config
		FString PositionValue = FString::Printf(TEXT("%.2f,%.2f"), Position.X, Position.Y);
		FString SizeValue = FString::Printf(TEXT("%.2f,%.2f"), Size.X, Size.Y);
		
		// Save to config file
		GConfig->SetString(*ConfigSection, *PositionKey, *PositionValue, GGameUserSettingsIni);
		GConfig->SetString(*ConfigSection, *SizeKey, *SizeValue, GGameUserSettingsIni);
		GConfig->Flush(false, GGameUserSettingsIni);
		
		UE_LOG(LogTemp, Log, TEXT("Saved window '%s' position: %s, size: %s to config"),
			*WindowId, *PositionValue, *SizeValue);
	}
}

void UEchoesWindowBase::LoadWindowPosition()
{
	if (!bSavePosition || WindowId.IsEmpty())
	{
		return;
	}

	// Load from config file
	FString ConfigSection = TEXT("Echoes.Windows");
	FString PositionKey = FString::Printf(TEXT("%s.Position"), *WindowId);
	FString SizeKey = FString::Printf(TEXT("%s.Size"), *WindowId);
	
	FString PositionValue;
	FString SizeValue;
	
	if (GConfig->GetString(*ConfigSection, *PositionKey, PositionValue, GGameUserSettingsIni) &&
	    GConfig->GetString(*ConfigSection, *SizeKey, SizeValue, GGameUserSettingsIni))
	{
		// Parse position
		TArray<FString> PositionParts;
		PositionValue.ParseIntoArray(PositionParts, TEXT(","));
		
		if (PositionParts.Num() == 2)
		{
			FVector2D LoadedPosition;
			LoadedPosition.X = FCString::Atof(*PositionParts[0]);
			LoadedPosition.Y = FCString::Atof(*PositionParts[1]);
			
			// Parse size
			TArray<FString> SizeParts;
			SizeValue.ParseIntoArray(SizeParts, TEXT(","));
			
			if (SizeParts.Num() == 2)
			{
				FVector2D LoadedSize;
				LoadedSize.X = FCString::Atof(*SizeParts[0]);
				LoadedSize.Y = FCString::Atof(*SizeParts[1]);
				
				// Apply loaded values
				SetWindowPosition(LoadedPosition);
				SetWindowSize(LoadedSize);
				
				UE_LOG(LogTemp, Log, TEXT("Loaded window '%s' position: %s, size: %s from config"),
					*WindowId, *PositionValue, *SizeValue);
				return;
			}
		}
	}
	
	// If loading failed, use defaults
	UE_LOG(LogTemp, Log, TEXT("No saved position for window '%s', using defaults"), *WindowId);
}

void UEchoesWindowBase::OnCloseButtonClicked()
{
	CloseWindow();
}

bool UEchoesWindowBase::IsMouseOverTitleBar(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) const
{
	if (!TitleBar)
	{
		return false;
	}

	// Get title bar geometry
	FGeometry TitleBarGeometry = TitleBar->GetCachedGeometry();
	FVector2D LocalMousePos = TitleBarGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());
	
	// Check if mouse is within title bar bounds
	FVector2D TitleBarSize = TitleBarGeometry.GetLocalSize();
	return LocalMousePos.X >= 0 && LocalMousePos.X <= TitleBarSize.X &&
	       LocalMousePos.Y >= 0 && LocalMousePos.Y <= TitleBarSize.Y;
}

bool UEchoesWindowBase::IsMouseOverResizeHandle(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) const
{
	if (!ResizeHandle)
	{
		return false;
	}

	// Get resize handle geometry
	FGeometry ResizeGeometry = ResizeHandle->GetCachedGeometry();
	FVector2D LocalMousePos = ResizeGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());
	
	// Check if mouse is within resize handle bounds
	FVector2D HandleSize = ResizeGeometry.GetLocalSize();
	return LocalMousePos.X >= 0 && LocalMousePos.X <= HandleSize.X &&
	       LocalMousePos.Y >= 0 && LocalMousePos.Y <= HandleSize.Y;
}

void UEchoesWindowBase::UpdateWindowPosition(const FVector2D& NewPosition)
{
	if (CanvasSlot)
	{
		CanvasSlot->SetPosition(NewPosition);
	}
}

void UEchoesWindowBase::UpdateWindowSize(const FVector2D& NewSize)
{
	if (CanvasSlot)
	{
		CanvasSlot->SetSize(NewSize);
	}
}

FVector2D UEchoesWindowBase::ClampPositionToScreen(const FVector2D& Position) const
{
	// Get viewport size
	APlayerController* PC = GetOwningPlayer();
	if (!PC)
	{
		return Position;
	}

	int32 ViewportSizeX, ViewportSizeY;
	PC->GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ViewportSize(ViewportSizeX, ViewportSizeY);

	// Get window size
	FVector2D WindowSize = GetWindowSize();

	// Clamp position so window stays on screen
	FVector2D ClampedPosition;
	ClampedPosition.X = FMath::Clamp(Position.X, 0.0f, ViewportSize.X - WindowSize.X);
	ClampedPosition.Y = FMath::Clamp(Position.Y, 0.0f, ViewportSize.Y - WindowSize.Y);

	return ClampedPosition;
}

FVector2D UEchoesWindowBase::ClampSize(const FVector2D& Size) const
{
	FVector2D ClampedSize = Size;

	// Clamp to minimum size
	ClampedSize.X = FMath::Max(ClampedSize.X, MinWindowSize.X);
	ClampedSize.Y = FMath::Max(ClampedSize.Y, MinWindowSize.Y);

	// Clamp to maximum size (if set)
	if (MaxWindowSize.X > 0.0f)
	{
		ClampedSize.X = FMath::Min(ClampedSize.X, MaxWindowSize.X);
	}
	if (MaxWindowSize.Y > 0.0f)
	{
		ClampedSize.Y = FMath::Min(ClampedSize.Y, MaxWindowSize.Y);
	}

	return ClampedSize;
}

UCanvasPanelSlot* UEchoesWindowBase::GetCanvasSlot()
{
	if (CanvasSlot)
	{
		return CanvasSlot;
	}

	// Try to get canvas panel slot from parent
	if (UPanelSlot* PanelSlot = Slot)
	{
		CanvasSlot = Cast<UCanvasPanelSlot>(PanelSlot);
	}

	if (!CanvasSlot)
	{
		UE_LOG(LogTemp, Warning, TEXT("Window '%s' is not in a CanvasPanel! Dragging and resizing will not work."), *WindowId);
	}

	return CanvasSlot;
}

void UEchoesWindowBase::InitializeWindowId()
{
	if (WindowId.IsEmpty())
	{
		// Auto-generate window ID from class name
		WindowId = GetClass()->GetName();
		UE_LOG(LogTemp, Log, TEXT("Auto-generated window ID: %s"), *WindowId);
	}
}

FVector2D UEchoesWindowBase::ApplySnapping(const FVector2D& Position) const
{
	FVector2D SnappedPosition = Position;

	// Snap to screen edges first
	if (bSnapToScreenEdges)
	{
		SnappedPosition = SnapToScreenEdges(SnappedPosition);
	}

	// Then snap to other windows (if not snapped to screen)
	if (bSnapToOtherWindows && SnappedPosition == Position)
	{
		SnappedPosition = SnapToOtherWindows(SnappedPosition);
	}

	return SnappedPosition;
}

FVector2D UEchoesWindowBase::SnapToScreenEdges(const FVector2D& Position) const
{
	// Get viewport size
	APlayerController* PC = GetOwningPlayer();
	if (!PC)
	{
		return Position;
	}

	int32 ViewportSizeX, ViewportSizeY;
	PC->GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D WindowSize = GetWindowSize();

	FVector2D SnappedPosition = Position;

	// Snap to left edge
	if (FMath::Abs(Position.X) < SnapThreshold)
	{
		SnappedPosition.X = 0.0f;
		UE_LOG(LogTemp, Verbose, TEXT("Window '%s' snapped to left edge"), *WindowId);
	}

	// Snap to right edge
	float RightEdge = ViewportSize.X - WindowSize.X;
	if (FMath::Abs(Position.X - RightEdge) < SnapThreshold)
	{
		SnappedPosition.X = RightEdge;
		UE_LOG(LogTemp, Verbose, TEXT("Window '%s' snapped to right edge"), *WindowId);
	}

	// Snap to top edge
	if (FMath::Abs(Position.Y) < SnapThreshold)
	{
		SnappedPosition.Y = 0.0f;
		UE_LOG(LogTemp, Verbose, TEXT("Window '%s' snapped to top edge"), *WindowId);
	}

	// Snap to bottom edge
	float BottomEdge = ViewportSize.Y - WindowSize.Y;
	if (FMath::Abs(Position.Y - BottomEdge) < SnapThreshold)
	{
		SnappedPosition.Y = BottomEdge;
		UE_LOG(LogTemp, Verbose, TEXT("Window '%s' snapped to bottom edge"), *WindowId);
	}

	return SnappedPosition;
}

FVector2D UEchoesWindowBase::SnapToOtherWindows(const FVector2D& Position) const
{
	TArray<UEchoesWindowBase*> OtherWindows = GetOtherWindows();
	if (OtherWindows.Num() == 0)
	{
		return Position;
	}

	FVector2D WindowSize = GetWindowSize();
	FVector2D SnappedPosition = Position;
	bool bSnapped = false;

	for (UEchoesWindowBase* OtherWindow : OtherWindows)
	{
		if (!OtherWindow || OtherWindow == this)
		{
			continue;
		}

		FVector2D OtherPos = OtherWindow->GetWindowPosition();
		FVector2D OtherSize = OtherWindow->GetWindowSize();

		// Calculate edges
		float ThisRight = Position.X + WindowSize.X;
		float ThisBottom = Position.Y + WindowSize.Y;
		float OtherRight = OtherPos.X + OtherSize.X;
		float OtherBottom = OtherPos.Y + OtherSize.Y;

		// Snap to left edge of other window (align right edge of this to left edge of other)
		if (FMath::Abs(ThisRight - OtherPos.X) < SnapThreshold &&
		    FMath::Abs(Position.Y - OtherPos.Y) < SnapThreshold * 2)
		{
			SnappedPosition.X = OtherPos.X - WindowSize.X;
			bSnapped = true;
			UE_LOG(LogTemp, Verbose, TEXT("Window '%s' snapped to left of '%s'"), 
				*WindowId, *OtherWindow->WindowId);
		}

		// Snap to right edge of other window (align left edge of this to right edge of other)
		if (FMath::Abs(Position.X - OtherRight) < SnapThreshold &&
		    FMath::Abs(Position.Y - OtherPos.Y) < SnapThreshold * 2)
		{
			SnappedPosition.X = OtherRight;
			bSnapped = true;
			UE_LOG(LogTemp, Verbose, TEXT("Window '%s' snapped to right of '%s'"), 
				*WindowId, *OtherWindow->WindowId);
		}

		// Snap to top edge of other window
		if (FMath::Abs(ThisBottom - OtherPos.Y) < SnapThreshold &&
		    FMath::Abs(Position.X - OtherPos.X) < SnapThreshold * 2)
		{
			SnappedPosition.Y = OtherPos.Y - WindowSize.Y;
			bSnapped = true;
			UE_LOG(LogTemp, Verbose, TEXT("Window '%s' snapped to top of '%s'"), 
				*WindowId, *OtherWindow->WindowId);
		}

		// Snap to bottom edge of other window
		if (FMath::Abs(Position.Y - OtherBottom) < SnapThreshold &&
		    FMath::Abs(Position.X - OtherPos.X) < SnapThreshold * 2)
		{
			SnappedPosition.Y = OtherBottom;
			bSnapped = true;
			UE_LOG(LogTemp, Verbose, TEXT("Window '%s' snapped to bottom of '%s'"), 
				*WindowId, *OtherWindow->WindowId);
		}

		if (bSnapped)
		{
			break; // Snap to first matching window
		}
	}

	return SnappedPosition;
}

TArray<UEchoesWindowBase*> UEchoesWindowBase::GetOtherWindows() const
{
	TArray<UEchoesWindowBase*> OtherWindows;

	UPanelWidget* Parent = GetParent();
	if (!Parent)
	{
		return OtherWindows;
	}

	// Find all other EchoesWindowBase widgets in the same parent
	for (int32 i = 0; i < Parent->GetChildrenCount(); ++i)
	{
		UWidget* Child = Parent->GetChildAt(i);
		if (UEchoesWindowBase* WindowChild = Cast<UEchoesWindowBase>(Child))
		{
			if (WindowChild != this)
			{
				OtherWindows.Add(WindowChild);
			}
		}
	}

	return OtherWindows;
}
