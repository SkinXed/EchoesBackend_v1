// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Core/Common/EchoesInventoryComponent.h"
#include "EchoesContextMenuWidget.generated.h"

class UVerticalBox;
class UTextBlock;
class UEchoesInventoryItemObject;
class UEchoesContextMenuWidget;

UCLASS()
class ECHOES_API UEchoesContextMenuActionButton : public UButton
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ActionId;

	UPROPERTY()
	TWeakObjectPtr<UEchoesContextMenuWidget> OwnerWidget;

	UFUNCTION()
	void HandleClicked();
};

// Delegate for context menu action
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnContextMenuActionSelected, const FString&, ActionName);

/**
 * Context menu action definition
 */
USTRUCT(BlueprintType)
struct FContextMenuAction
{
	GENERATED_BODY()

	/** Display name of the action */
	UPROPERTY(BlueprintReadWrite, Category = "ContextMenu")
	FText DisplayName;

	/** Internal action identifier */
	UPROPERTY(BlueprintReadWrite, Category = "ContextMenu")
	FString ActionId;

	/** Whether this action is currently enabled */
	UPROPERTY(BlueprintReadWrite, Category = "ContextMenu")
	bool bEnabled = true;

	/** Tooltip text */
	UPROPERTY(BlueprintReadWrite, Category = "ContextMenu")
	FText Tooltip;

	FContextMenuAction()
		: DisplayName(FText::GetEmpty())
		, ActionId(TEXT(""))
		, bEnabled(true)
		, Tooltip(FText::GetEmpty())
	{}

	FContextMenuAction(const FText& InDisplayName, const FString& InActionId, bool bInEnabled = true)
		: DisplayName(InDisplayName)
		, ActionId(InActionId)
		, bEnabled(bInEnabled)
		, Tooltip(FText::GetEmpty())
	{}
};

/**
 * UEchoesContextMenuWidget
 * 
 * Dynamic context menu for inventory items
 * Displays available actions based on item type
 * 
 * Features:
 * - Dynamic action button generation
 * - Smart positioning (stays within screen bounds)
 * - Auto-closes on focus loss or outside click
 * - Server-validated actions
 * - Singleton-like behavior (one menu at a time)
 * 
 * Usage:
 * - Create when right-clicking inventory item
 * - Initialize with item data and available actions
 * - Position at mouse cursor
 * - Handle action callbacks
 */
UCLASS()
class ECHOES_API UEchoesContextMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UEchoesContextMenuWidget(const FObjectInitializer& ObjectInitializer);

	// UUserWidget interface
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent) override;
	// End of UUserWidget interface

	/**
	 * Initialize context menu with item and actions
	 * @param InItemObject - Item the menu is for
	 * @param InSourceStorageId - Storage ID where item is located
	 * @param InSourceActor - Actor containing the item
	 * @param InActions - Available actions for this item
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|ContextMenu")
	void InitializeMenu(
		UEchoesInventoryItemObject* InItemObject,
		const FGuid& InSourceStorageId,
		AActor* InSourceActor,
		const TArray<FContextMenuAction>& InActions);

	/**
	 * Position the menu at mouse cursor with smart bounds checking
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|ContextMenu")
	void PositionAtMouse();

	/**
	 * Close the context menu
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|ContextMenu")
	void CloseMenu();

	/**
	 * Get the item this menu is for
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|ContextMenu")
	UEchoesInventoryItemObject* GetItemObject() const { return ItemObject; }

	/**
	 * Get the source storage ID
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|ContextMenu")
	FGuid GetSourceStorageId() const { return SourceStorageId; }

	/**
	 * Get the source actor
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|ContextMenu")
	AActor* GetSourceActor() const { return SourceActor; }

	/**
	 * Delegate called when an action is selected
	 */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|ContextMenu")
	FOnContextMenuActionSelected OnActionSelected;

	/**
	 * Handle action button clicked
	 */
	UFUNCTION()
	void HandleActionButtonClicked(const FString& ActionId);

protected:
	/**
	 * Build the menu UI with action buttons
	 */
	void BuildMenuContent();

	/**
	 * Create a button for an action
	 */
	UButton* CreateActionButton(const FContextMenuAction& Action);

	/**
	 * Calculate smart position within screen bounds
	 */
	FVector2D CalculateSmartPosition(const FVector2D& DesiredPosition, const FVector2D& MenuSize) const;

	/**
	 * Check if click is outside menu bounds
	 */
	bool IsClickOutsideMenu(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) const;

	/**
	 * Blueprint event when menu is initialized
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "Echoes|ContextMenu")
	void OnMenuInitialized();

	/**
	 * Blueprint event when menu is closed
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "Echoes|ContextMenu")
	void OnMenuClosed();

	// Widget bindings

	/** Container for action buttons */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Echoes|ContextMenu")
	UVerticalBox* ActionsContainer;

	/** Title text showing item name */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Echoes|ContextMenu")
	UTextBlock* TitleText;

	/** Button class to use for actions */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Echoes|ContextMenu")
	TSubclassOf<UButton> ActionButtonClass;

	/** Margin between action buttons */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Echoes|ContextMenu")
	float ButtonSpacing = 2.0f;

private:
	/** Item object this menu is for */
	UPROPERTY()
	UEchoesInventoryItemObject* ItemObject;

	/** Source storage ID */
	UPROPERTY()
	FGuid SourceStorageId;

	/** Source actor containing the item */
	UPROPERTY()
	AActor* SourceActor;

	/** Available actions */
	UPROPERTY()
	TArray<FContextMenuAction> Actions;

	/** Whether the menu is currently open */
	bool bIsOpen;

	/** Static reference to current menu (singleton-like behavior) */
	static UEchoesContextMenuWidget* CurrentMenu;
};
