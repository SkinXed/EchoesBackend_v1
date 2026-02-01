// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesPreloadWidget.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "Core/Common/Networking/EchoesAuthSubsystem.h"
#include "Core/Common/Save/EchoesLocalPlayerSettings.h"
#include "Kismet/GameplayStatics.h"
#include "JsonObjectConverter.h"

void UEchoesPreloadWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Get auth subsystem
	if (UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(GetWorld()))
	{
		AuthSubsystem = GameInstance->GetSubsystem<UEchoesAuthSubsystem>();
	}

	// Get HTTP module
	Http = &FHttpModule::Get();

	CurrentState = EPreloadState::CheckingAPI;

	// Start preload automatically
	StartPreload();
}

void UEchoesPreloadWidget::NativeDestruct()
{
	Super::NativeDestruct();
}

void UEchoesPreloadWidget::StartPreload()
{
	UpdateStatus("Connecting to server...", 0.1f);
	CheckAPIStatus();
}

void UEchoesPreloadWidget::CheckAPIStatus()
{
	CurrentState = EPreloadState::CheckingAPI;
	UpdateStatus("Checking API status...", 0.2f);

	// Create HTTP request
	TSharedRef<IHttpRequest> Request = Http->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &UEchoesPreloadWidget::OnAPIStatusResponse);
	Request->SetURL(GetApiBaseUrl() + "/api/system/status");
	Request->SetVerb("GET");
	Request->SetHeader("Content-Type", "application/json");
	Request->ProcessRequest();
}

void UEchoesPreloadWidget::OnAPIStatusResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("API status check failed"));
		UpdateStatus("Failed to connect to server", 1.0f);
		
		// Wait a moment then transition to login
		FTimerHandle TimerHandle;
		GetWorld()->GetTimerManager().SetTimer(
			TimerHandle,
			[this]()
			{
				CompletePreload(ENextState::Login);
			},
			2.0f,
			false
		);
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("API status: %s"), *Response->GetContentAsString());
	
	// Parse response
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
	
	if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
	{
		FString Status = JsonObject->GetStringField("status");
		if (Status == "online")
		{
			UpdateStatus("Server online, checking saved credentials...", 0.5f);
			
			// Check for saved token
			SavedToken = GetSavedToken();
			if (!SavedToken.IsEmpty())
			{
				ValidateSavedToken();
			}
			else
			{
				UpdateStatus("No saved credentials found", 0.9f);
				
				// No token, go to login
				FTimerHandle TimerHandle;
				GetWorld()->GetTimerManager().SetTimer(
					TimerHandle,
					[this]()
					{
						CompletePreload(ENextState::Login);
					},
					1.0f,
					false
				);
			}
		}
		else
		{
			UpdateStatus("Server degraded, please try again later", 1.0f);
			CompletePreload(ENextState::Login);
		}
	}
}

void UEchoesPreloadWidget::ValidateSavedToken()
{
	CurrentState = EPreloadState::ValidatingToken;
	UpdateStatus("Validating credentials...", 0.7f);

	// Create HTTP request
	TSharedRef<IHttpRequest> Request = Http->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &UEchoesPreloadWidget::OnTokenValidationResponse);
	Request->SetURL(GetApiBaseUrl() + "/api/auth/validate-token");
	Request->SetVerb("POST");
	Request->SetHeader("Content-Type", "application/json");
	
	// Create JSON body
	FString JsonBody = FString::Printf(TEXT("{\"token\":\"%s\"}"), *SavedToken);
	Request->SetContentAsString(JsonBody);
	
	Request->ProcessRequest();
}

void UEchoesPreloadWidget::OnTokenValidationResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("Token validation failed"));
		UpdateStatus("Session expired, please login", 0.9f);
		
		FTimerHandle TimerHandle;
		GetWorld()->GetTimerManager().SetTimer(
			TimerHandle,
			[this]()
			{
				CompletePreload(ENextState::Login);
			},
			1.5f,
			false
		);
		return;
	}

	// Parse response
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
	
	if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
	{
		bool bIsValid = JsonObject->GetBoolField("isValid");
		
		if (bIsValid && AuthSubsystem)
		{
			UE_LOG(LogTemp, Log, TEXT("Token validated successfully"));
			
			// TODO: Store character list in AuthSubsystem from response
			// For now, just set the token
			// AuthSubsystem->SetToken(SavedToken);
			
			UpdateStatus("Welcome back!", 1.0f);
			CurrentState = EPreloadState::Success;
			
			// Go directly to character select
			FTimerHandle TimerHandle;
			GetWorld()->GetTimerManager().SetTimer(
				TimerHandle,
				[this]()
				{
					CompletePreload(ENextState::CharacterSelect);
				},
				0.5f,
				false
			);
		}
		else
		{
			FString Error = JsonObject->GetStringField("error");
			UE_LOG(LogTemp, Warning, TEXT("Token invalid: %s"), *Error);
			UpdateStatus("Session expired, please login", 0.9f);
			
			FTimerHandle TimerHandle;
			GetWorld()->GetTimerManager().SetTimer(
				TimerHandle,
				[this]()
				{
					CompletePreload(ENextState::Login);
				},
				1.5f,
				false
			);
		}
	}
}

void UEchoesPreloadWidget::CompletePreload(ENextState NextState)
{
	UE_LOG(LogTemp, Log, TEXT("Preload complete, next state: %d"), (int32)NextState);
	
	// Broadcast completion
	OnPreloadComplete.Broadcast(NextState);
	
	// Remove this widget
	RemoveFromParent();
}

FString UEchoesPreloadWidget::GetSavedToken() const
{
	// Load from LocalPlayerSettings
	UEchoesLocalPlayerSettings* Settings = UEchoesLocalPlayerSettings::LoadSettings();
	
	if (Settings && Settings->IsTokenValid())
	{
		UE_LOG(LogTemp, Log, TEXT("Found valid saved token"));
		return Settings->SavedAuthToken;
	}
	
	// Fallback: check AuthSubsystem
	if (AuthSubsystem)
	{
		return AuthSubsystem->Auth_GetToken();
	}
	
	return FString();
}

void UEchoesPreloadWidget::UpdateStatus(const FString& Message, float Progress)
{
	if (StatusText)
	{
		StatusText->SetText(FText::FromString(Message));
	}

	if (ProgressBar)
	{
		ProgressBar->SetPercent(Progress);
	}

	UE_LOG(LogTemp, Log, TEXT("Preload: %s (%.0f%%)"), *Message, Progress * 100.0f);
}

FString UEchoesPreloadWidget::GetApiBaseUrl() const
{
	// TODO: Get from config
	return TEXT("http://localhost:5116");
}
