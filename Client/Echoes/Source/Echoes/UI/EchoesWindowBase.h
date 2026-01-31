// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EchoesWindowBase.generated.h"

class UCanvasPanel;
class UCanvasPanelSlot;
class UBorder;
class UButton;
class UTextBlock;
class UNamedSlot;
class UImage;

/**
 * UEchoesWindowBase
 * 
 * Base class for draggable and resizable window-style UI widgets
 * Provides Windows-like window behavior with title bar, resize handles, and focus management
 * 
 * Features:
 * - Draggable via title bar
 * - Resizable from bottom-right corner
 * - Minimum size constraints
 * - Z-order focus system
 * - Close button
 * - Content slot for child widgets
 * - Position persistence (optional)
 * 
 * Usage:
 * - Create widget blueprint based on this class
 * - Add required widget bindings: TitleBar, TitleText, CloseButton, ResizeHandle, ContentSlot
 * - Set MinWindowSize and DefaultWindowSize in Blueprint
 * - Place content widgets in ContentSlot in Blueprint editor
 */
UCLASS()
class ECHOES_API UEchoesWindowBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UEchoesWindowBase(const FObjectInitializer& ObjectInitializer);

	// UUserWidget interface
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	// End of UUserWidget interface

	/**
	 * Set the window title text
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Window")
	void SetWindowTitle(const FText& Title);

	/**
	 * Get the window title text
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Window")
	FText GetWindowTitle() const;

	/**
	 * Close this window (removes from parent and destroys)
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Window")
	void CloseWindow();

	/**
	 * Set window position
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Window")
	void SetWindowPosition(FVector2D Position);

	/**
	 * Get window position
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Window")
	FVector2D GetWindowPosition() const;

	/**
	 * Set window size
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Window")
	void SetWindowSize(FVector2D Size);

	/**
	 * Get window size
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Window")
	FVector2D GetWindowSize() const;

	/**
	 * Bring this window to front (highest Z-order)
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Window")
	void BringToFront();

	/**
	 * Save window position to player settings
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Window")
	void SaveWindowPosition();

	/**
	 * Load window position from player settings
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Window")
	void LoadWindowPosition();

protected:
	/**
	 * Called when close button is clicked
	 */
	UFUNCTION()
	void OnCloseButtonClicked();

	/**
	 * Blueprint event called when window is closed
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "Echoes|Window")
	void OnWindowClosed();

	/**
	 * Blueprint event called when window gains focus
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "Echoes|Window")
	void OnWindowFocused();

	/**
	 * Check if mouse is over title bar
	 */
	bool IsMouseOverTitleBar(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) const;

	/**
	 * Check if mouse is over resize handle
	 */
	bool IsMouseOverResizeHandle(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) const;

	/**
	 * Update window position during drag
	 */
	void UpdateWindowPosition(const FVector2D& NewPosition);

	/**
	 * Update window size during resize
	 */
	void UpdateWindowSize(const FVector2D& NewSize);

	/**
	 * Clamp window position to screen bounds
	 */
	FVector2D ClampPositionToScreen(const FVector2D& Position) const;

	/**
	 * Clamp window size to min/max bounds
	 */
	FVector2D ClampSize(const FVector2D& Size) const;

	// ==================== Widget Bindings ====================

	/** Title bar border (draggable area) */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Echoes|Window")
	UBorder* TitleBar;

	/** Title text block */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Echoes|Window")
	UTextBlock* TitleText;

	/** Close button */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Echoes|Window")
	UButton* CloseButton;

	/** Resize handle (bottom-right corner) */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Echoes|Window")
	UImage* ResizeHandle;

	/** Content slot for child widgets */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Echoes|Window")
	UNamedSlot* ContentSlot;

	// ==================== Configuration ====================

	/** Minimum window size (width, height) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Echoes|Window|Config")
	FVector2D MinWindowSize = FVector2D(300.0f, 200.0f);

	/** Maximum window size (0 = no limit) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Echoes|Window|Config")
	FVector2D MaxWindowSize = FVector2D(0.0f, 0.0f);

	/** Default window size */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Echoes|Window|Config")
	FVector2D DefaultWindowSize = FVector2D(600.0f, 400.0f);

	/** Default window position (relative to screen) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Echoes|Window|Config")
	FVector2D DefaultWindowPosition = FVector2D(100.0f, 100.0f);

	/** Whether to save/load window position */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Echoes|Window|Config")
	bool bSavePosition = true;

	/** Unique window ID for position saving (auto-generated from class name) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Echoes|Window|Config")
	FString WindowId;

	/** Whether window can be resized */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Echoes|Window|Config")
	bool bCanResize = true;

	/** Whether window can be dragged */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Echoes|Window|Config")
	bool bCanDrag = true;

private:
	// ==================== Drag State ====================

	/** Whether the window is being dragged */
	bool bIsDragging = false;

	/** Offset from mouse to window position when drag started */
	FVector2D DragOffset;

	// ==================== Resize State ====================

	/** Whether the window is being resized */
	bool bIsResizing = false;

	/** Window size when resize started */
	FVector2D ResizeStartSize;

	/** Mouse position when resize started */
	FVector2D ResizeStartMousePos;

	// ==================== Canvas Panel Slot ====================

	/** Cached canvas panel slot for position/size manipulation */
	UPROPERTY()
	UCanvasPanelSlot* CanvasSlot;

	/**
	 * Get or cache the canvas panel slot
	 */
	UCanvasPanelSlot* GetCanvasSlot();

	/**
	 * Initialize window ID if not set
	 */
	void InitializeWindowId();
};
