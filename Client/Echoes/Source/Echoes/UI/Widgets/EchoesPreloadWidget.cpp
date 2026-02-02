// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesPreloadWidget.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "Components/Button.h"
#include "Core/Common/Networking/EchoesAuthSubsystem.h"
#include "Core/Common/Save/EchoesLocalPlayerSettings.h"
#include "Kismet/GameplayStatics.h"
#include "JsonObjectConverter.h"
#include "Misc/ConfigCacheIni.h"

const FString ClientVersion = TEXT("0.0.1");

void UEchoesPreloadWidget::NativeConstruct()
{
	Super::NativeConstruct();

	bIsActive = true;

	// Get auth subsystem
	if (UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(GetWorld()))
	{
		AuthSubsystem = GameInstance->GetSubsystem<UEchoesAuthSubsystem>();
	}

	// Привязка кнопки Retry
	if (RetryButton)
	{
		RetryButton->OnClicked.AddDynamic(this, &UEchoesPreloadWidget::OnRetryClicked);
		RetryButton->SetVisibility(ESlateVisibility::Collapsed);
	}

	// Скрываем текст ошибки на старте
	if (ErrorText)
	{
		ErrorText->SetVisibility(ESlateVisibility::Collapsed);
	}

	// Get HTTP module
	Http = &FHttpModule::Get();

	CurrentState = EPreloadState::CheckingInternet;

	// Start preload automatically
	StartPreload();
}

void UEchoesPreloadWidget::NativeDestruct()
{
	bIsActive = false;
	Super::NativeDestruct();
}

void UEchoesPreloadWidget::StartPreload()
{
	// Сброс UI перед новой попыткой
	if (ErrorText) ErrorText->SetVisibility(ESlateVisibility::Collapsed);
	if (RetryButton) RetryButton->SetVisibility(ESlateVisibility::Collapsed);

	// Запускаем цепочку проверок
	CheckInternetConnection();
}

void UEchoesPreloadWidget::CheckAPIStatus()
{
	// Оставлен для совместимости, если захочешь вызвать отдельно
	CheckInternetConnection();
}

void UEchoesPreloadWidget::OnAPIStatusResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (!bIsActive)
	{
		return;
	}

	// Если мы попали сюда напрямую (минуя лямбду), делаем проверку
	if (!bWasSuccessful || !Response.IsValid())
	{
		HandleFatalError("Server is offline or unreachable.");
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("API status: %s"), *Response->GetContentAsString());

	CurrentState = EPreloadState::CheckingAPI;
	UpdateStatus("Verifying client version...", 0.3f);

	// Parse response
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());

	if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
	{
		FString Status = JsonObject->GetStringField(TEXT("status"));

		if (Status == TEXT("online"))
		{
			// CHECK VERSION
			FString MinRequiredVersion = JsonObject->GetStringField(TEXT("minClientVersion"));

			// Простая проверка версий (строковая).
			if (!MinRequiredVersion.IsEmpty() && MinRequiredVersion > ClientVersion)
			{
				HandleFatalError("Client update required!\nMin: " + MinRequiredVersion + "\nYour: " + ClientVersion);
				return;
			}

			UpdateStatus("Server online. Checking saved session...", 0.5f);

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
			// Сервер в режиме обслуживания
			FString Msg = JsonObject->GetStringField(TEXT("message"));
			HandleFatalError("Server Maintenance: " + (Msg.IsEmpty() ? "Try again later" : Msg));
		}
	}
	else
	{
		HandleFatalError("Invalid server response format.");
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
	if (!bIsActive)
	{
		return;
	}

	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("Token validation failed network check"));
		CompletePreload(ENextState::Login);
		return;
	}

	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());

	if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
	{
		bool bIsValid = JsonObject->GetBoolField(TEXT("isValid"));

		if (bIsValid && AuthSubsystem)
		{
			UE_LOG(LogTemp, Log, TEXT("Token validated successfully"));

			FGuid AccountId;
			FGuid CharacterId;
			FGuid::Parse(JsonObject->GetStringField(TEXT("accountId")), AccountId);
			FGuid::Parse(JsonObject->GetStringField(TEXT("characterId")), CharacterId);
			FString CharacterName = JsonObject->GetStringField(TEXT("characterName"));

			TArray<FCharacterInfo> Characters;
			const TArray<TSharedPtr<FJsonValue>>* CharactersArray;
			if (JsonObject->TryGetArrayField(TEXT("characters"), CharactersArray))
			{
				for (const TSharedPtr<FJsonValue>& CharValue : *CharactersArray)
				{
					const TSharedPtr<FJsonObject>& CharObj = CharValue->AsObject();
					if (CharObj.IsValid())
					{
						FCharacterInfo CharInfo;
						FGuid::Parse(CharObj->GetStringField(TEXT("characterId")), CharInfo.CharacterId);
						CharInfo.Name = CharObj->GetStringField(TEXT("name"));
						CharInfo.WalletBalance = CharObj->GetNumberField(TEXT("walletBalance"));
						CharInfo.Credits = CharObj->HasField(TEXT("credits"))
							? CharObj->GetNumberField(TEXT("credits"))
							: CharInfo.WalletBalance;
						if (CharObj->HasField(TEXT("totalSkillPoints")))
						{
							CharInfo.ExperiencePoints = CharObj->GetIntegerField(TEXT("totalSkillPoints"));
						}
						if (CharObj->HasField(TEXT("raceId")))
						{
							CharInfo.RaceId = CharObj->GetIntegerField(TEXT("raceId"));
						}
						if (CharObj->HasField(TEXT("raceName")))
						{
							CharInfo.RaceName = CharObj->GetStringField(TEXT("raceName"));
						}
						if (CharObj->HasField(TEXT("currentShipId")) && !CharObj->GetField<EJson::None>(TEXT("currentShipId"))->IsNull())
						{
							CharInfo.CurrentShipId = CharObj->GetNumberField(TEXT("currentShipId"));
						}
						CharInfo.IsMain = CharObj->GetBoolField(TEXT("isMain"));
						CharInfo.IsOnline = CharObj->GetBoolField(TEXT("isOnline"));
						Characters.Add(CharInfo);
					}
				}
			}

			AuthSubsystem->SetAuthSession(SavedToken, AccountId, CharacterId, CharacterName, Characters);

			UpdateStatus("Welcome back!", 1.0f);
			CurrentState = EPreloadState::Success;

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
			UE_LOG(LogTemp, Warning, TEXT("Token invalid or expired"));
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
	if (!bIsActive)
	{
		return;
	}

	if (IsValid(StatusText))
	{
		StatusText->SetText(FText::FromString(Message));
	}

	if (IsValid(ProgressBar))
	{
		ProgressBar->SetPercent(Progress);
	}

	UE_LOG(LogTemp, Log, TEXT("Preload: %s (%.0f%%)"), *Message, Progress * 100.0f);
}

FString UEchoesPreloadWidget::GetApiBaseUrl() const
{
	if (GConfig)
	{
		FString ConfigUrl;
		// Читаем из DefaultGame.ini секцию [Network] ключ ApiUrl
		if (GConfig->GetString(TEXT("Network"), TEXT("ApiUrl"), ConfigUrl, GGameIni))
		{
			return ConfigUrl;
		}
	}
	return TEXT("http://localhost:5116");
}

void UEchoesPreloadWidget::CheckInternetConnection()
{
	if (!bIsActive)
	{
		return;
	}

	CurrentState = EPreloadState::CheckingInternet;
	UpdateStatus("Checking connection...", 0.1f);

	// Проверяем доступность нашего же API.
	TSharedRef<IHttpRequest> Request = Http->CreateRequest();

	Request->SetURL(GetApiBaseUrl() + "/api/system/status");
	Request->SetVerb("GET");
	Request->SetTimeout(5.0f);

	Request->OnProcessRequestComplete().BindLambda([this](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess)
		{
			if (!bIsActive)
			{
				return;
			}

			if (bSuccess && Response.IsValid() && Response->GetResponseCode() == 200)
			{
				OnAPIStatusResponse(Request, Response, true);
			}
			else
			{
				FString ErrorMsg = "Connection failed. ";
				if (Response.IsValid())
				{
					ErrorMsg += FString::Printf(TEXT("Code: %d"), Response->GetResponseCode());
				}
				else
				{
					ErrorMsg += "Server unreachable.";
				}
				HandleFatalError(ErrorMsg);
			}
		});

	Request->ProcessRequest();
}

void UEchoesPreloadWidget::HandleFatalError(const FString& ErrorMessage)
{
	if (!bIsActive)
	{
		return;
	}

	CurrentState = EPreloadState::FatalError;
	UpdateStatus("Connection Error", 0.0f);

	if (IsValid(ErrorText))
	{
		ErrorText->SetText(FText::FromString(ErrorMessage));
		ErrorText->SetVisibility(ESlateVisibility::Visible);
	}

	if (IsValid(RetryButton))
	{
		RetryButton->SetVisibility(ESlateVisibility::Visible);
	}

	UE_LOG(LogTemp, Error, TEXT("Preload Fatal: %s"), *ErrorMessage);
}

void UEchoesPreloadWidget::OnRetryClicked()
{
	 StartPreload();
}