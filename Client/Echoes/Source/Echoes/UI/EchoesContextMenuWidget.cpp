// Copyright Epic Games, Inc. All Rights Reserved.

#include "UI/EchoesContextMenuWidget.h"
#include "UI/EchoesInventoryItemObject.h"
#include "Components/VerticalBox.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBoxSlot.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "GameFramework/PlayerController.h"

// Static member initialization
UEchoesContextMenuWidget* UEchoesContextMenuWidget::CurrentMenu = nullptr;

UEchoesContextMenuWidget::UEchoesContextMenuWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, ItemObject(nullptr)
	, SourceActor(nullptr)
	, bIsOpen(false)
{
	bIsFocusable = true;
}

void UEchoesContextMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Close any existing menu
	if (CurrentMenu && CurrentMenu != this)
	{
		CurrentMenu->CloseMenu();
	}

	// Set this as current menu
	CurrentMenu = this;
	bIsOpen = true;

	// Set focus to capture input
	SetKeyboardFocus();

	UE_LOG(LogTemp, Log, TEXT("Context menu constructed"));
}

void UEchoesContextMenuWidget::NativeDestruct()
{
	if (CurrentMenu == this)
	{
		CurrentMenu = nullptr;
	}

	bIsOpen = false;

	Super::NativeDestruct();
}

void UEchoesContextMenuWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	// Check if we should auto-close due to focus loss
	// This is handled by mouse clicks outside the menu
}

FReply UEchoesContextMenuWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	// Check if click is outside menu
	if (IsClickOutsideMenu(InGeometry, InMouseEvent))
	{
		CloseMenu();
		return FReply::Handled();
	}

	return Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
}

FReply UEchoesContextMenuWidget::NativeOnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
{
	// Close on Escape key
	if (InKeyEvent.GetKey() == EKeys::Escape)
	{
		CloseMenu();
		return FReply::Handled();
	}

	return Super::NativeOnKeyDown(MyGeometry, InKeyEvent);
}

void UEchoesContextMenuWidget::InitializeMenu(
	UEchoesInventoryItemObject* InItemObject,
	const FGuid& InSourceStorageId,
	AActor* InSourceActor,
	const TArray<FContextMenuAction>& InActions)
{
	if (!InItemObject)
	{
		UE_LOG(LogTemp, Error, TEXT("Context menu initialized with null item object"));
		return;
	}

	ItemObject = InItemObject;
	SourceStorageId = InSourceStorageId;
	SourceActor = InSourceActor;
	Actions = InActions;

	// Set title
	if (TitleText)
	{
		TitleText->SetText(ItemObject->GetDisplayName());
	}

	// Build menu content
	BuildMenuContent();

	// Position at mouse
	PositionAtMouse();

	// Trigger Blueprint event
	OnMenuInitialized();

	UE_LOG(LogTemp, Log, TEXT("Context menu initialized for item: %s, Actions: %d"),
		*ItemObject->GetItemName(), Actions.Num());
}

void UEchoesContextMenuWidget::PositionAtMouse()
{
	APlayerController* PC = GetOwningPlayer();
	if (!PC)
	{
		return;
	}

	// Get mouse position
	float MouseX, MouseY;
	PC->GetMousePosition(MouseX, MouseY);
	FVector2D MousePosition(MouseX, MouseY);

	// Get viewport size
	int32 ViewportSizeX, ViewportSizeY;
	PC->GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ViewportSize(ViewportSizeX, ViewportSizeY);

	// Estimate menu size (will be accurate after first tick)
	// For now, use a reasonable default
	FVector2D EstimatedMenuSize(200.0f, 100.0f + (Actions.Num() * 35.0f));

	// Calculate smart position
	FVector2D FinalPosition = CalculateSmartPosition(MousePosition, EstimatedMenuSize);

	// Set position
	SetPositionInViewport(FinalPosition, false);

	UE_LOG(LogTemp, Verbose, TEXT("Context menu positioned at: %s"), *FinalPosition.ToString());
}

void UEchoesContextMenuWidget::CloseMenu()
{
	if (!bIsOpen)
	{
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Context menu closing"));

	// Trigger Blueprint event
	OnMenuClosed();

	// Remove from parent
	RemoveFromParent();
}

void UEchoesContextMenuWidget::BuildMenuContent()
{
	if (!ActionsContainer)
	{
		UE_LOG(LogTemp, Error, TEXT("Context menu: ActionsContainer not bound"));
		return;
	}

	// Clear existing content
	ActionsContainer->ClearChildren();

	// Create button for each action
	for (const FContextMenuAction& Action : Actions)
	{
		UButton* ActionButton = CreateActionButton(Action);
		if (ActionButton)
		{
			// Add to container
			UVerticalBoxSlot* Slot = ActionsContainer->AddChildToVerticalBox(ActionButton);
			if (Slot)
			{
				Slot->SetPadding(FMargin(0.0f, ButtonSpacing));
			}
		}
	}

	UE_LOG(LogTemp, Verbose, TEXT("Context menu: Built %d action buttons"), Actions.Num());
}

void UEchoesContextMenuWidget::OnActionButtonClicked(const FString& ActionId)
{
	UE_LOG(LogTemp, Log, TEXT("Context menu action selected: %s"), *ActionId);

	// Broadcast action selection
	OnActionSelected.Broadcast(ActionId);

	// Close menu after action
	CloseMenu();
}

UButton* UEchoesContextMenuWidget::CreateActionButton(const FContextMenuAction& Action)
{
	// Create button
	UButton* Button = NewObject<UButton>(this, ActionButtonClass ? ActionButtonClass : UButton::StaticClass());
	if (!Button)
	{
		return nullptr;
	}

	// Create text label
	UTextBlock* ButtonText = NewObject<UTextBlock>(Button);
	if (ButtonText)
	{
		ButtonText->SetText(Action.DisplayName);
		Button->AddChild(ButtonText);
	}

	// Bind click event
	// We need to capture ActionId for the lambda
	FString ActionIdCopy = Action.ActionId;
	Button->OnClicked.AddDynamic(this, &UEchoesContextMenuWidget::OnActionButtonClicked);
	
	// Store action ID in button's tag for retrieval in callback
	// Note: We'll need to modify OnActionButtonClicked to retrieve from sender
	// For now, use a simple binding approach

	// Enable/disable based on action state
	Button->SetIsEnabled(Action.bEnabled);

	return Button;
}

FVector2D UEchoesContextMenuWidget::CalculateSmartPosition(const FVector2D& DesiredPosition, const FVector2D& MenuSize) const
{
	APlayerController* PC = GetOwningPlayer();
	if (!PC)
	{
		return DesiredPosition;
	}

	// Get viewport size
	int32 ViewportSizeX, ViewportSizeY;
	PC->GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D FinalPosition = DesiredPosition;

	// Add small offset from cursor
	FinalPosition.X += 5.0f;
	FinalPosition.Y += 5.0f;

	// Check right edge
	if (FinalPosition.X + MenuSize.X > ViewportSize.X)
	{
		// Shift left
		FinalPosition.X = ViewportSize.X - MenuSize.X - 10.0f;
		
		// If still doesn't fit, position to left of cursor
		if (FinalPosition.X < 0)
		{
			FinalPosition.X = DesiredPosition.X - MenuSize.X - 5.0f;
			FinalPosition.X = FMath::Max(FinalPosition.X, 10.0f);
		}
	}

	// Check bottom edge
	if (FinalPosition.Y + MenuSize.Y > ViewportSize.Y)
	{
		// Shift up
		FinalPosition.Y = ViewportSize.Y - MenuSize.Y - 10.0f;
		
		// If still doesn't fit, position above cursor
		if (FinalPosition.Y < 0)
		{
			FinalPosition.Y = DesiredPosition.Y - MenuSize.Y - 5.0f;
			FinalPosition.Y = FMath::Max(FinalPosition.Y, 10.0f);
		}
	}

	// Ensure minimum position (don't go off left/top edge)
	FinalPosition.X = FMath::Max(FinalPosition.X, 10.0f);
	FinalPosition.Y = FMath::Max(FinalPosition.Y, 10.0f);

	return FinalPosition;
}

bool UEchoesContextMenuWidget::IsClickOutsideMenu(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) const
{
	// Get mouse position in widget space
	FVector2D LocalMousePos = InGeometry.AbsoluteToLocal(InMouseEvent.GetScreenSpacePosition());
	
	// Get widget size
	FVector2D WidgetSize = InGeometry.GetLocalSize();

	// Check if click is outside bounds
	bool bOutside = LocalMousePos.X < 0 || LocalMousePos.X > WidgetSize.X ||
	                LocalMousePos.Y < 0 || LocalMousePos.Y > WidgetSize.Y;

	return bOutside;
}
