// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/EchoesWindowBase.h"
#include "Http.h"
#include "EchoesPreloadWidget.generated.h"

class UTextBlock;
class UProgressBar;
class UEchoesAuthSubsystem;

/**
 * Preload state enum
 */
UENUM(BlueprintType)
enum class EPreloadState : uint8
{
	CheckingAPI,
	ValidatingToken,
	Success,
	Failed
};

/**
 * Next state after preload
 */
UENUM(BlueprintType)
enum class ENextState : uint8
{
	Login,
	CharacterSelect
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPreloadComplete, ENextState, NextState);

/**
 * UEchoesPreloadWidget
 * 
 * Preload widget for cold start validation
 * Checks API connectivity and validates saved JWT token
 * 
 * Flow:
 * 1. Check API status (/api/system/status)
 * 2. If token exists in LocalPlayerSettings, validate it (/api/auth/validate-token)
 * 3. On success -> Character Select
 * 4. On failure -> Login
 */
UCLASS()
class ECHOES_API UEchoesPreloadWidget : public UEchoesWindowBase
{
	GENERATED_BODY()

public:
	// ==================== Widget Lifecycle ====================

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	// ==================== UI Bindings ====================

	/** Status message text */
	UPROPERTY(meta = (BindWidget))
	UTextBlock* StatusText;

	/** Loading progress bar */
	UPROPERTY(meta = (BindWidget))
	UProgressBar* ProgressBar;

	// ==================== Events ====================

	/** Called when preload is complete */
	UPROPERTY(BlueprintAssignable, Category = "Echoes|Preload")
	FOnPreloadComplete OnPreloadComplete;

	// ==================== Public Methods ====================

	/**
	 * Start the preload process
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Preload")
	void StartPreload();

protected:
	// ==================== Preload Steps ====================

	/**
	 * Step 1: Check API status
	 */
	void CheckAPIStatus();

	/**
	 * Step 2: Validate saved token
	 */
	void ValidateSavedToken();

	/**
	 * Complete preload with next state
	 */
	void CompletePreload(ENextState NextState);

	// ==================== HTTP Callbacks ====================

	/**
	 * Handle API status response
	 */
	void OnAPIStatusResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	/**
	 * Handle token validation response
	 */
	void OnTokenValidationResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	// ==================== Helper Functions ====================

	/**
	 * Get saved JWT token from LocalPlayerSettings
	 */
	FString GetSavedToken() const;

	/**
	 * Update status text and progress
	 */
	void UpdateStatus(const FString& Message, float Progress);

	/**
	 * Get API base URL
	 */
	FString GetApiBaseUrl() const;

private:
	/** Reference to auth subsystem */
	UPROPERTY()
	UEchoesAuthSubsystem* AuthSubsystem;

	/** HTTP module reference */
	FHttpModule* Http;

	/** Current preload state */
	EPreloadState CurrentState;

	/** Saved JWT token */
	FString SavedToken;
};
