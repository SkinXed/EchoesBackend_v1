// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EchoesWindowBase.h"
#include "EchoesAuthSubsystem.h"

#include "EchoesLoginWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLoginSuccessEvent, const FAuthResponse&, AuthResponse);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLoginFailureEvent, const FString&, ErrorMessage);

class UEditableTextBox;
class UButton;
class UTextBlock;
class UCheckBox;

/**
 * UEchoesLoginWidget
 * 
 * Login UI widget for Echoes MMO
 * Provides email/username and password input fields
 * Integrates with UEchoesAuthSubsystem for authentication
 * Inherits from UEchoesWindowBase for drag/focus support
 */
UCLASS()
class ECHOES_API UEchoesLoginWidget : public UEchoesWindowBase
{
	GENERATED_BODY()

public:
	// ==================== Widget Lifecycle ====================

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	// ==================== UI Bindings ====================

	/** Email or username input field */
	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* EmailUsernameInput;

	/** Password input field */
	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* PasswordInput;

	/** Remember Me checkbox */
	UPROPERTY(meta = (BindWidget))
	UCheckBox* RememberMeCheckbox;

	/** Login button */
	UPROPERTY(meta = (BindWidget))
	UButton* LoginButton;

	/** Register button */
	UPROPERTY(meta = (BindWidget))
	UButton* RegisterButton;

	/** Status text (for errors/success messages) */
	UPROPERTY(meta = (BindWidget))
	UTextBlock* StatusText;

	// ==================== Blueprint Events ====================

	/** Called when login is successful */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Login")
	FOnLoginSuccessEvent OnLoginSuccessDelegate;

	/** Called when login fails */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Login")
	FOnLoginFailureEvent OnLoginFailureDelegate;

protected:
	// ==================== Button Handlers ====================

	/**
	 * Handle login button click
	 */
	UFUNCTION()
	void OnLoginButtonClicked();

	/**
	 * Handle register button click
	 */
	UFUNCTION()
	void OnRegisterButtonClicked();

	/**
	 * Handle Enter key press in password field
	 */
	UFUNCTION()
	void OnPasswordCommitted(const FText& Text, ETextCommit::Type CommitMethod);

	// ==================== Auth Callbacks ====================

	/**
	 * Called when login succeeds
	 */
	UFUNCTION()
	void OnLoginSuccess(const FAuthResponse& AuthResponse);

	/**
	 * Called when login fails
	 */
	UFUNCTION()
	void OnLoginFailure(const FString& ErrorMessage);

	// ==================== Helper Functions ====================

	/**
	 * Validate input fields
	 * @return True if valid, false otherwise
	 */
	bool ValidateInput();

	/**
	 * Set status text and color
	 */
	void SetStatusText(const FString& Message, const FLinearColor& Color);

	/**
	 * Enable/disable UI during login process
	 */
	void SetUIEnabled(bool bEnabled);

private:
	/** Reference to auth subsystem */
	UPROPERTY()
	UEchoesAuthSubsystem* AuthSubsystem;

	/** Is login in progress? */
	bool bLoginInProgress = false;
};
