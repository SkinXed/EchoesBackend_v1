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

UEchoesWindowBase::UEchoesWindowBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Enable mouse events
	bIsFocusable = true;
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

	// TODO: Implement saving to player settings/config file
	// For now, just log
	FVector2D Position = GetWindowPosition();
	FVector2D Size = GetWindowSize();
	
	UE_LOG(LogTemp, Log, TEXT("Saving window '%s' position: %s, size: %s"),
		*WindowId, *Position.ToString(), *Size.ToString());

	// Example implementation:
	// - Save to GameUserSettings
	// - Or save to custom config file
	// - Or save to player profile database
}

void UEchoesWindowBase::LoadWindowPosition()
{
	if (!bSavePosition || WindowId.IsEmpty())
	{
		return;
	}

	// TODO: Implement loading from player settings/config file
	// For now, use defaults
	
	UE_LOG(LogTemp, Log, TEXT("Loading window '%s' position (using defaults for now)"), *WindowId);

	// Example implementation:
	// - Load from GameUserSettings
	// - Or load from custom config file
	// - Or load from player profile database
	// - Then call SetWindowPosition() and SetWindowSize()
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
