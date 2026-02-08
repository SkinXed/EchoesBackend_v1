// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesServerGameMode.h"

#include "EchoesWorldGenerator.h"
#include "EchoesJumpManager.h"
#include "EchoesServerDiscoveryTypes.h"
#include "EchoesInventorySubsystem.h"
#include "EchoesAuthSubsystem.h"
#include "Core/Server/EchoesServerAuthSubsystem.h"
#include "Core/Common/Player/EchoesPlayerState.h"

#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Misc/ConfigCacheIni.h"
#include "GameFramework/PlayerState.h"
#include "Core/Common/Actor/StationActor.h"
#include "EngineUtils.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "UObject/SoftObjectPtr.h"
#include "UObject/Package.h"
#include "EchoesPlayerController.h"
#include "Async/Async.h"


#if WITH_SERVER_CODE
#include "EchoesServerManagementSubsystem.h"
#include "Core/Server/EchoesHangarManager.h"
#endif
AEchoesServerGameMode::AEchoesServerGameMode()
{
	bWorldGenerated = false;
	bWaitingForConfig = false;
	bSubscribedToConfigDelegate = false;

	// Create jump manager component
	JumpManager = CreateDefaultSubobject<UEchoesJumpManager>(TEXT("JumpManager"));

	// Get HTTP module
	Http = &FHttpModule::Get();

	// Use custom PlayerState that stores auth token
	PlayerStateClass = AEchoesPlayerState::StaticClass();
}

// --- 1. ФУНКЦИЯ DEV BYPASS (Вставь перед PostLogin) ---
#if WITH_EDITOR
void AEchoesServerGameMode::HandleDevBypass(APlayerController* NewPlayer)
{
	 UE_LOG(LogTemp, Warning, TEXT("=========================================="));
	 UE_LOG(LogTemp, Warning, TEXT("   DEV MODE: BYPASSING AUTHENTICATION     "));
	 UE_LOG(LogTemp, Warning, TEXT("=========================================="));

	 // Создаем фейкового персонажа "Dev Admin"
	 TArray<FCharacterInfo> DevCharacters;
	 FCharacterInfo AdminChar;
	 AdminChar.CharacterId = FGuid::NewGuid();
	 AdminChar.Name = TEXT("Dev_Admin_Pilot");
	 AdminChar.RaceId = 1; // Caldari
	 AdminChar.RaceName = TEXT("Caldari");
	 AdminChar.IsOnline = true;
	 AdminChar.IsDocked = false; // Сразу в космос
	 AdminChar.Credits = 999999999;
	 DevCharacters.Add(AdminChar);

	 if (AEchoesPlayerController* EchoPC = Cast<AEchoesPlayerController>(NewPlayer))
	 {
		  // Показываем меню выбора с нашим фейковым персонажем
		  EchoPC->Client_ShowCharacterSelection(DevCharacters);
	 }
}
#endif

FString AEchoesServerGameMode::GetPlayerOptionsSafe(APlayerController* Player) const
{
	if (!Player)
	{
		return FString();
	}

	// First try to read the connection URL (this contains ClientTravel options such as ?Token=...&CharacterId=...)
	if (Player->GetNetConnection())
	{
		// UNetConnection содержит URL, который сериализует полную строку подключения
		// Используйте ToString(), чтобы получить хост + параметры. Это самый надежный источник для Token/CharacterId.
		if (!Player->GetNetConnection()->URL.ToString().IsEmpty())
		{
			return Player->GetNetConnection()->URL.ToString();
		}

		// В качестве запасного варианта попробуйте LowLevelGetRemoteAddress, который возвращает "ip:port"
		FString RemoteAddr = Player->GetNetConnection()->LowLevelGetRemoteAddress();
		if (!RemoteAddr.IsEmpty())
		{
			return RemoteAddr;
		}
	}

	// Предпочитайте PlayerState->SavedNetworkAddress, если это возможно
	if (Player->PlayerState && !Player->PlayerState->SavedNetworkAddress.IsEmpty())
	{
		return Player->PlayerState->SavedNetworkAddress;
	}

	return FString();
}

void AEchoesServerGameMode::BeginPlay()
{
	 Super::BeginPlay();

	 // Оставляем проверку на Authority для Runtime безопасности
	 if (!HasAuthority())
	 {
		  return;
	 }

	 // ВАЖНО: Этот блок кода будет компилироваться ТОЛЬКО для Сервера и Редактора.
	 // Клиентский билд этот код просто проигнорирует, что избавит от ошибок линковки.
#if WITH_SERVER_CODE

	 UE_LOG(LogTemp, Log, TEXT("╔══════════════════════════════════════════════════════════╗"));
	 UE_LOG(LogTemp, Log, TEXT("║    ECHOES SERVER GAMEMODE - INITIALIZATION              ║"));
	 UE_LOG(LogTemp, Log, TEXT("╚══════════════════════════════════════════════════════════╝"));

	 // Get reference to server management subsystem
	 UGameInstance* GameInstance = GetWorld()->GetGameInstance();
	 if (GameInstance)
	 {
		  // Получаем ServerManagementSubsystem только внутри блока WITH_SERVER_CODE
		  ServerManagementSubsystem = GameInstance->GetSubsystem<UEchoesServerManagementSubsystem>();
		  if (ServerManagementSubsystem)
		  {
				UE_LOG(LogTemp, Log, TEXT("✓ ServerManagementSubsystem found"));


               if (ServerManagementSubsystem->IsServerRegistered())
               {
                    UE_LOG(LogTemp, Log, TEXT("✓ Server already registered"));
                    InitializeWorldGeneration();
               }
               else
               {
                    UE_LOG(LogTemp, Warning, TEXT("⚠ Server not yet registered, waiting for config..."));
                    bWaitingForConfig = true;
               }

               if (!bSubscribedToConfigDelegate)
               {
                    ServerManagementSubsystem->OnServerConfigReceived.AddDynamic(
                     this,
                     &AEchoesServerGameMode::OnServerConfigReceived);
                    bSubscribedToConfigDelegate = true;
                    UE_LOG(LogTemp, Log, TEXT("✓ Subscribed to OnServerConfigReceived delegate"));
               }
          }
		  else
		  {
				UE_LOG(LogTemp, Error, TEXT("✗ Failed to get ServerManagementSubsystem"));
		  }

		  // InventorySubsystem обычно лежит в Common, но если он ServerOnly, его тоже оставляем здесь
		  InventorySubsystem = GameInstance->GetSubsystem<UEchoesInventorySubsystem>();
		  if (InventorySubsystem)
		  {
				UE_LOG(LogTemp, Log, TEXT("✓ InventorySubsystem found"));
		  }
	 }

	 // Initialize HangarManager for player isolation
	 TArray<AActor*> FoundHangarManagers;
	 UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEchoesHangarManager::StaticClass(), FoundHangarManagers);

	 if (FoundHangarManagers.Num() > 0)
	 {
		  HangarManager = Cast<AEchoesHangarManager>(FoundHangarManagers[0]);
		  UE_LOG(LogTemp, Log, TEXT("✓ HangarManager found in level"));
	 }
	 else
	 {
		  FActorSpawnParameters SpawnParams;
		  SpawnParams.Owner = this;
		  SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		  HangarManager = GetWorld()->SpawnActor<AEchoesHangarManager>(
				AEchoesHangarManager::StaticClass(),
				FVector::ZeroVector,
				FRotator::ZeroRotator,
				SpawnParams);

		  if (HangarManager)
		  {
				UE_LOG(LogTemp, Log, TEXT("✓ HangarManager spawned successfully"));
		  }
	 }

	 UE_LOG(LogTemp, Log, TEXT("GameMode initialization complete. WorldGenerated: %s"),
		  bWorldGenerated ? TEXT("true") : TEXT("false"));

#if WITH_EDITOR
	// Editor-only: if we are still not generated (e.g. running PIE without a dedicated server),
	// force world generation for development convenience. This does not run in cooked builds.
	if (!bWorldGenerated)
	{
		UE_LOG(LogTemp, Warning, TEXT("Editor: Forcing world generation in PIE for development (editor-only fallback)"));
		InitializeWorldGeneration();
	}
#endif

#endif // WITH_SERVER_CODE
}

FString AEchoesServerGameMode::InitNewPlayer(APlayerController* NewPlayerController, const FUniqueNetIdRepl& UniqueId, const FString& Options, const FString& Portal)
{
	 // 1. Стандартная инициализация движка
	 FString ErrorMessage = Super::InitNewPlayer(NewPlayerController, UniqueId, Options, Portal);
	 if (!ErrorMessage.IsEmpty())
	 {
		  return ErrorMessage;
	 }

	 // 2. Ручной парсинг (Вместо ParseOption) для идеальной чистоты токена
	 FString Token;
	 const FString TokenKey = TEXT("Token=");

	 // Ищем "Token=" без учета регистра
	 int32 StartIndex = Options.Find(TokenKey, ESearchCase::IgnoreCase);

	 if (StartIndex != INDEX_NONE)
	 {
		  // Сдвигаем индекс на длину ключа
		  StartIndex += TokenKey.Len();

		  // Ищем ближайший разделитель (& или ?)
		  // Это гарантирует, что мы не захватим CharacterId или другие параметры
		  int32 EndIndexAmp = Options.Find(TEXT("&"), ESearchCase::IgnoreCase, ESearchDir::FromStart, StartIndex);
		  int32 EndIndexQue = Options.Find(TEXT("?"), ESearchCase::IgnoreCase, ESearchDir::FromStart, StartIndex);

		  int32 EndIndex = Options.Len(); // По умолчанию до конца строки

		  // Выбираем тот разделитель, который встречается раньше
		  if (EndIndexAmp != INDEX_NONE && EndIndexAmp < EndIndex) EndIndex = EndIndexAmp;
		  if (EndIndexQue != INDEX_NONE && EndIndexQue < EndIndex) EndIndex = EndIndexQue;

		  // Вырезаем токен
		  Token = Options.Mid(StartIndex, EndIndex - StartIndex);
	 }

	 // 3. Сохранение
	 if (!Token.IsEmpty() && NewPlayerController)
	 {
		  // Логируем только длину, чтобы не спамить токеном
		  UE_LOG(LogTemp, Log, TEXT("InitNewPlayer: Captured Token (%d chars)"), Token.Len());

		  // Сохраняем в карту для PostLogin
		  PendingTokens.Add(NewPlayerController, Token);
	 }
	 else
	 {
		  // В продакшене это Warning, в разработке может быть ОК если тестируем без авторизации
		  UE_LOG(LogTemp, Warning, TEXT("InitNewPlayer: No Token found in Options: %s"), *Options);
	 }

	 return ErrorMessage;
}

void AEchoesServerGameMode::PostLogin(APlayerController* NewPlayer)
{
	 Super::PostLogin(NewPlayer);

	 // 1. Проверки
	 if (!HasAuthority()) return;
	 if (!NewPlayer || !NewPlayer->PlayerState)
	 {
		  UE_LOG(LogTemp, Error, TEXT("PostLogin: NewPlayer is null"));
		  return;
	 }

	 // === RETRIEVE TOKEN: Prefer captured token from InitNewPlayer (fix for PIE) ===
	 FString Token;
	 if (PendingTokens.Contains(NewPlayer))
	 {
		  Token = PendingTokens[NewPlayer];
		  PendingTokens.Remove(NewPlayer);
	 }

	 // If not captured, fallback to parsing options/saved address
	 if (Token.IsEmpty())
	 {
		  FString Options = GetPlayerOptionsSafe(NewPlayer);
		  UE_LOG(LogTemp, Log, TEXT("PostLogin Raw Options: %s"), *Options);

		  // Prefer engine helper which handles various option string formats
		  Token = UGameplayStatics::ParseOption(Options, TEXT("Token"));

		  // Fallback: some transports may place options in PlayerState->SavedNetworkAddress
		  if (Token.IsEmpty() && NewPlayer->PlayerState)
		  {
				FString FromSaved = UGameplayStatics::ParseOption(NewPlayer->PlayerState->SavedNetworkAddress, TEXT("Token"));
				if (!FromSaved.IsEmpty()) Token = FromSaved;
		  }
	 }

	 // === ПРОВЕРКА ТОКЕНА И DEV BYPASS ===
	 if (Token.IsEmpty())
	 {
		  // !!! НАЧАЛО ИЗМЕНЕНИЙ: DEV BYPASS !!!
#if WITH_EDITOR
		  // Если мы в редакторе и токена нет - запускаем Dev режим
		  HandleDevBypass(NewPlayer);
		  return; // Выходим, чтобы не сработал Kick
#else
		  UE_LOG(LogTemp, Warning, TEXT("PostLogin: Token PARSING FAILED."));
		  KickPlayerToMenu(NewPlayer, TEXT("Authentication token missing"));
		  return;
#endif
		  // !!! КОНЕЦ ИЗМЕНЕНИЙ !!!

	 }

	 // CharacterId optional parsing
	 FString CharIdStr = UGameplayStatics::ParseOption(GetPlayerOptionsSafe(NewPlayer), TEXT("CharacterId"));
	 FGuid ParsedCharId;
	 if (!CharIdStr.IsEmpty())
	 {
		  FGuid::Parse(CharIdStr, ParsedCharId);
	 }
	 else if (NewPlayer->PlayerState) // Try fallback
	 {
		  FString FromSaved = UGameplayStatics::ParseOption(NewPlayer->PlayerState->SavedNetworkAddress, TEXT("CharacterId"));
		  if (!FromSaved.IsEmpty()) FGuid::Parse(FromSaved, ParsedCharId);
	 }

#if WITH_SERVER_CODE
	 // 3. Работа с Subsystem
	 if (UGameInstance* GI = GetGameInstance())
	 {
		  UEchoesServerAuthSubsystem* ServerAuth = GI->GetSubsystem<UEchoesServerAuthSubsystem>();
		  if (!ServerAuth)
		  {
				KickPlayerToMenu(NewPlayer, TEXT("Server internal error"));
				return;
		  }

		  // Используем WeakPtr для безопасности
		  TWeakObjectPtr<APlayerController> WeakPC(NewPlayer);

		  // ШАГ 1: Валидация
		  ServerAuth->ValidateClientToken(
				Token,
				// Успешная валидация ->
				[this, WeakPC, Token, ServerAuth](const FGuid& ValidatedCharId, const FGuid& AccountId)
				{
					 // ШАГ 2: Получение списка персонажей
					 ServerAuth->FetchCharacterList(
						  Token,
						  FOnCharacterListReceived::CreateLambda([this, WeakPC](const TArray<FCharacterInfo>& Characters)
								{
									 AsyncTask(ENamedThreads::GameThread, [this, WeakPC, Characters]()
										  {
												APlayerController* PC = WeakPC.Get();
												if (!PC) return;

												if (AEchoesPlayerController* EchoPC = Cast<AEchoesPlayerController>(PC))
												{
													 UE_LOG(LogTemp, Log, TEXT("PostLogin: Sending %d characters to client"), Characters.Num());
													 // ШАГ 3: Показываем UI клиенту
													 EchoPC->Client_ShowCharacterSelection(Characters);
												}
												else
												{
													 UE_LOG(LogTemp, Warning, TEXT("PostLogin: PC is not AEchoesPlayerController"));
												}
										  });
								}),
						  FOnAuthFailure::CreateLambda([this, WeakPC](const FString& Error)
								{
									 AsyncTask(ENamedThreads::GameThread, [this, WeakPC, Error]()
										  {
												APlayerController* PC = WeakPC.Get();
												if (PC)
												{
													 UE_LOG(LogTemp, Error, TEXT("Failed to fetch char list: %s"), *Error);
													 KickPlayerToMenu(PC, TEXT("Failed to retrieve character list"));
												}
										  });
								})
					 );
				},
				// Ошибка валидации ->
				[this, WeakPC](const FString& Error)
				{
					 AsyncTask(ENamedThreads::GameThread, [this, WeakPC, Error]() {
						  APlayerController* PC = WeakPC.Get();
						  if (PC) KickPlayerToMenu(PC, FString::Printf(TEXT("Auth Failed: %s"), *Error));
						  });
				}
		  );
	 }
#endif
}

void AEchoesServerGameMode::HandleStartingNewPlayer(APlayerController* NewPlayer)
{
    // Override to prevent automatic Pawn spawn until client is authorized and selected character
    // Intentionally empty to block default behavior
}

void AEchoesServerGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);

	if (!HasAuthority())
	{
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Player logged out: %s"), Exiting ? *Exiting->GetName() : TEXT("Unknown"));

	// Clean up authorization tracking for this player
	APlayerController* PC = Cast<APlayerController>(Exiting);
	if (PC && PlayerSpawnAuthorization.Contains(PC))
	{
		PlayerSpawnAuthorization.Remove(PC);
		UE_LOG(LogTemp, Log, TEXT("Removed player from authorization tracking"));
	}

	// Также удаляем любой ожидающий токен
	if (PC)
	{
		PendingTokens.Remove(PC);
	}
}

void AEchoesServerGameMode::OnServerConfigReceived(const FServerSystemConfig& Config)
{
	if (!HasAuthority())
	{
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("╔══════════════════════════════════════════════════════════╗"));
	UE_LOG(LogTemp, Log, TEXT("║    SERVER CONFIG RECEIVED - TRIGGERING WORLD GEN        ║"));
	UE_LOG(LogTemp, Log, TEXT("╚══════════════════════════════════════════════════════════╝"));
	UE_LOG(LogTemp, Log, TEXT("System: %s"), *Config.SystemName);

	bWaitingForConfig = false;

	// Trigger world generation
	InitializeWorldGeneration();
}

void AEchoesServerGameMode::InitializeWorldGeneration()
{
	if (!HasAuthority())
	{
		UE_LOG(LogTemp, Error, TEXT("✗ InitializeWorldGeneration called on client!"));
		return;
	}

	if (bWorldGenerated)
	{
		UE_LOG(LogTemp, Warning, TEXT("⚠ World already generated, skipping"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Initializing world generation..."));

	// Get or create world generator
	WorldGenerator = GetOrCreateWorldGenerator();
	if (!WorldGenerator)
	{
		UE_LOG(LogTemp, Error, TEXT("✗ Failed to get or create WorldGenerator"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("✓ WorldGenerator ready"));

	// World generator will handle generation automatically via its own subscription
	// to OnServerConfigReceived. We just mark that generation is in progress.
	bWorldGenerated = true; // Mark as generated (WorldGenerator handles the actual spawning)

	UE_LOG(LogTemp, Log, TEXT("✓ World generation initialized"));
}

AEchoesWorldGenerator* AEchoesServerGameMode::GetOrCreateWorldGenerator()
{
	// First, try to find existing world generator in level
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEchoesWorldGenerator::StaticClass(), FoundActors);

	if (FoundActors.Num() > 0)
	{
		UE_LOG(LogTemp, Log, TEXT("✓ Found existing WorldGenerator in level"));
		return Cast<AEchoesWorldGenerator>(FoundActors[0]);
	}

	// If not found, spawn a new one
	UE_LOG(LogTemp, Log, TEXT("WorldGenerator not found, spawning new instance..."));

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AEchoesWorldGenerator* NewGenerator = GetWorld()->SpawnActor<AEchoesWorldGenerator>(
		AEchoesWorldGenerator::StaticClass(),
		FVector::ZeroVector,
		FRotator::ZeroRotator,
		SpawnParams);

	if (NewGenerator)
	{
		UE_LOG(LogTemp, Log, TEXT("✓ WorldGenerator spawned successfully"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("✗ Failed to spawn WorldGenerator"));
	}

	return NewGenerator;
}

void AEchoesServerGameMode::TriggerWorldGeneration()
{
	if (!HasAuthority())
	{
		UE_LOG(LogTemp, Error, TEXT("✗ TriggerWorldGeneration called on client!"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Manual world generation trigger requested"));
	InitializeWorldGeneration();
}

void AEchoesServerGameMode::SpawnPlayerAtLocation(APlayerController* PlayerController)
{
	if (!PlayerController)
	{
		UE_LOG(LogTemp, Error, TEXT("✗ SpawnPlayerAtLocation: PlayerController is null"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("╔══════════════════════════════════════════════════════════╗"));
	UE_LOG(LogTemp, Log, TEXT("║    SPAWNING PLAYER AT LOCATION                          ║"));
	UE_LOG(LogTemp, Log, TEXT("╚══════════════════════════════════════════════════════════╝"));

	// Extract character info from connection options
	FString Options = PlayerController->PlayerState ? PlayerController->PlayerState->SavedNetworkAddress : TEXT("");
	FString Token;
	FGuid CharacterId;

	if (!ExtractLoginOptions(Options, Token, CharacterId))
	{
		UE_LOG(LogTemp, Warning, TEXT("⚠ Could not extract character info from connection"));
		UE_LOG(LogTemp, Warning, TEXT("  Using default spawn location as safety fallback"));
		
		// Safety fallback: spawn at default location
		FVector SpawnLocation = FVector(0.0f, 0.0f, 1000.0f);
		FRotator SpawnRotation = FRotator::ZeroRotator;
		RestartPlayer(PlayerController);
		
		if (PlayerController->GetPawn())
		{
			PlayerController->GetPawn()->SetActorLocation(SpawnLocation);
			UE_LOG(LogTemp, Log, TEXT("✓ Player spawned at safety fallback location"));
			OnEntryFlowComplete.Broadcast();
		}
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Extracted CharacterId: %s"), *CharacterId.ToString());

	// Query backend for character location
	QueryCharacterLocation(CharacterId, Token, PlayerController);
}

void AEchoesServerGameMode::SpawnPlayerShip(APlayerController* PC, const FGuid& CharacterId)
{
    if (!HasAuthority())
    {
        UE_LOG(LogTemp, Warning, TEXT("SpawnPlayerShip called on non-authority"));
        return;
    }

    if (!PC)
    {
        UE_LOG(LogTemp, Error, TEXT("SpawnPlayerShip: PlayerController is null"));
        return;
    }

    if (!CharacterId.IsValid())
    {
        UE_LOG(LogTemp, Warning, TEXT("SpawnPlayerShip: invalid CharacterId"));
        KickPlayerToMenu(PC, TEXT("Invalid character selected"));
        return;
    }

    // Mark player as authorized to spawn (simple tracking; could be extended with timeouts)
    PlayerSpawnAuthorization.Add(PC, true);

    // Extract token from connection options if present (client should have provided it during travel)
    FString Options = GetPlayerOptionsSafe(PC);
    FString Token = UGameplayStatics::ParseOption(Options, TEXT("Token"));

    // Also prefer pending token if captured earlier
    if (Token.IsEmpty() && PendingTokens.Contains(PC))
    {
        Token = PendingTokens[PC];
    }

    // Query backend for character location to determine spawn type
    QueryCharacterLocation(CharacterId, Token, PC);
}

void AEchoesServerGameMode::QueryCharacterLocation(const FGuid& CharacterId, const FString& Token, APlayerController* PlayerController)
{
    if (!Http)
    {
        UE_LOG(LogTemp, Error, TEXT("QueryCharacterLocation: HTTP module not available"));
        KickPlayerToMenu(PlayerController, TEXT("Server internal error"));
        return;
    }

    if (!PlayerController)
    {
        UE_LOG(LogTemp, Warning, TEXT("QueryCharacterLocation: PlayerController is null"));
        return;
    }

    const FString Url = FString::Printf(TEXT("%s/character/%s/location"), *GetApiBaseUrl(), *CharacterId.ToString());

    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Http->CreateRequest();
    Request->SetVerb(TEXT("GET"));
    Request->SetURL(Url);
    Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));

    if (!Token.IsEmpty())
    {
        Request->SetHeader(TEXT("Authorization"), TEXT("Bearer ") + Token);
    }

    // Bind response handler and pass PlayerController and Token as extra params
    Request->OnProcessRequestComplete().BindUObject(
        this,
        &AEchoesServerGameMode::OnCharacterLocationReceived,
        PlayerController,
        Token
    );

    if (!Request->ProcessRequest())
    {
        UE_LOG(LogTemp, Error, TEXT("QueryCharacterLocation: Failed to send request to %s"), *Url);
        KickPlayerToMenu(PlayerController, TEXT("Failed to query character location"));
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("QueryCharacterLocation: Sent request for character %s"), *CharacterId.ToString());
    }
}

void AEchoesServerGameMode::OnCharacterLocationReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful, APlayerController* PlayerController, FString Token)
{
    if (!PlayerController)
    {
        UE_LOG(LogTemp, Warning, TEXT("OnCharacterLocationReceived: PlayerController no longer valid"));
        return;
    }

    if (!bWasSuccessful || !Response.IsValid())
    {
        UE_LOG(LogTemp, Error, TEXT("OnCharacterLocationReceived: HTTP request failed"));
        KickPlayerToMenu(PlayerController, TEXT("Failed to retrieve character location"));
        return;
    }

    const int32 ResponseCode = Response->GetResponseCode();
    const FString ResponseBody = Response->GetContentAsString();

    UE_LOG(LogTemp, Log, TEXT("OnCharacterLocationReceived: Code=%d Body=%s"), ResponseCode, *ResponseBody);

    if (ResponseCode != 200)
    {
        UE_LOG(LogTemp, Warning, TEXT("OnCharacterLocationReceived: Unexpected response code: %d"), ResponseCode);
        KickPlayerToMenu(PlayerController, FString::Printf(TEXT("Failed to get location: %d"), ResponseCode));
        return;
    }

    // Parse JSON and build FCharacterLocationData
    TSharedPtr<FJsonObject> JsonObject;
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseBody);

    if (!FJsonSerializer::Deserialize(Reader, JsonObject) || !JsonObject.IsValid())
    {
        UE_LOG(LogTemp, Error, TEXT("OnCharacterLocationReceived: Failed to parse JSON response"));
        KickPlayerToMenu(PlayerController, TEXT("Invalid character location response"));
        return;
    }

    FCharacterLocationData LocationData;

    // Safe parsing with TryGet... helpers
    bool bIsDocked = false;
    if (JsonObject->TryGetBoolField(TEXT("isDocked"), bIsDocked))
    {
        LocationData.IsDocked = bIsDocked;
    }

    bool bInWarp = false;
    if (JsonObject->TryGetBoolField(TEXT("inWarp"), bInWarp))
    {
        LocationData.InWarp = bInWarp;
    }

    FString StationIdStr;
    if (JsonObject->TryGetStringField(TEXT("stationId"), StationIdStr))
    {
        FGuid::Parse(StationIdStr, LocationData.StationId);
    }

    FString StationName;
    if (JsonObject->TryGetStringField(TEXT("stationName"), StationName))
    {
        LocationData.StationName = StationName;
    }

    FString SolarSystemIdStr;
    if (JsonObject->TryGetStringField(TEXT("solarSystemId"), SolarSystemIdStr))
    {
        FGuid::Parse(SolarSystemIdStr, LocationData.SolarSystemId);
    }

    double PosX = 0.0, PosY = 0.0, PosZ = 0.0;
    JsonObject->TryGetNumberField(TEXT("positionX"), PosX);
    JsonObject->TryGetNumberField(TEXT("positionY"), PosY);
    JsonObject->TryGetNumberField(TEXT("positionZ"), PosZ);
    LocationData.PositionX = PosX;
    LocationData.PositionY = PosY;
    LocationData.PositionZ = PosZ;

    FString HangarInstanceIdStr;
    if (JsonObject->TryGetStringField(TEXT("hangarInstanceId"), HangarInstanceIdStr))
    {
        FGuid::Parse(HangarInstanceIdStr, LocationData.HangarInstanceId);
    }

    int32 ActiveShipTypeId = 0;
    if (JsonObject->TryGetNumberField(TEXT("activeShipTypeId"), ActiveShipTypeId))
    {
        LocationData.ActiveShipTypeId = ActiveShipTypeId;
    }

    // Ensure spawn logic runs on the game thread
    AsyncTask(ENamedThreads::GameThread, [this, LocationData, PlayerController]() {
        PerformSpawnWithLocationData(LocationData, PlayerController);
    });
}

void AEchoesServerGameMode::PerformSpawnWithLocationData(const FCharacterLocationData& LocationData, APlayerController* PlayerController)
{
    if (!PlayerController || !HasAuthority())
    {
        UE_LOG(LogTemp, Warning, TEXT("PerformSpawnWithLocationData: invalid state or missing authority"));
        return;
    }

    // Basic safety: ensure player is authorized to spawn
    bool* bAuthorized = PlayerSpawnAuthorization.Find(PlayerController);
    if (!bAuthorized || !(*bAuthorized))
    {
        UE_LOG(LogTemp, Warning, TEXT("PerformSpawnWithLocationData: Player not authorized to spawn"));
        KickPlayerToMenu(PlayerController, TEXT("Not authorized to spawn"));
        return;
    }

    // If docked: spawn into hangar/station logic
    if (LocationData.IsDocked)
    {
        UE_LOG(LogTemp, Log, TEXT("PerformSpawnWithLocationData: Spawning docked player at station %s"), *LocationData.StationId.ToString());

        // Spawn player's pawn using default restart behavior
        RestartPlayer(PlayerController);

        APawn* Pawn = PlayerController->GetPawn();
        if (!Pawn)
        {
            UE_LOG(LogTemp, Error, TEXT("PerformSpawnWithLocationData: RestartPlayer failed to spawn pawn"));
            KickPlayerToMenu(PlayerController, TEXT("Failed to spawn pawn"));
            return;
        }

        // Apply hangar spatial isolation if HangarManager available
        if (HangarManager)
        {
            FVector Offset = HangarManager->GetOrCreateHangarInstance(LocationData.CharacterId, LocationData.StationId, LocationData.HangarInstanceId);
            HangarManager->BindShipPawnToHangar(LocationData.CharacterId, Pawn);
            Pawn->SetActorLocation(Pawn->GetActorLocation() + Offset);
        }

        // Hide pawn and disable physics to represent docked/hangar state
        Pawn->SetActorHiddenInGame(true);
        Pawn->SetActorEnableCollision(false);
        if (UPrimitiveComponent* RootPrim = Cast<UPrimitiveComponent>(Pawn->GetRootComponent()))
        {
            RootPrim->SetSimulatePhysics(false);
            RootPrim->SetEnableGravity(false);
        }

        // Try to find station actor and open station menu for player
        for (TActorIterator<AStationActor> It(GetWorld()); It; ++It)
        {
            AStationActor* Station = *It;
            if (Station && Station->GetStationId() == LocationData.StationId)
            {
                Station->ClientRPC_OpenStationMenu(LocationData.StationName, Station->GetStationType(), LocationData.HangarInstanceId);
                break;
            }
        }

        // Broadcast entry flow completion
        OnEntryFlowComplete.Broadcast();
        return;
    }

    // Otherwise spawn in space
    {
        FVector SpawnPos = FVector((float)LocationData.PositionX, (float)LocationData.PositionY, (float)LocationData.PositionZ);
        FRotator SpawnRot = FRotator::ZeroRotator;

        UE_LOG(LogTemp, Log, TEXT("PerformSpawnWithLocationData: Spawning in space at %s"), *SpawnPos.ToString());

        // Spawn/possess pawn
        RestartPlayer(PlayerController);
        APawn* Pawn = PlayerController->GetPawn();
        if (!Pawn)
        {
            UE_LOG(LogTemp, Error, TEXT("PerformSpawnWithLocationData: Failed to spawn pawn for space"));
            KickPlayerToMenu(PlayerController, TEXT("Failed to spawn pawn"));
            return;
        }

        // Position pawn at requested coordinates
        Pawn->SetActorLocation(SpawnPos);
        Pawn->SetActorRotation(SpawnRot);

        // Ensure physics enabled for ship pawn
        if (UPrimitiveComponent* RootPrim = Cast<UPrimitiveComponent>(Pawn->GetRootComponent()))
        {
            RootPrim->SetSimulatePhysics(true);
            RootPrim->SetEnableGravity(false);
            RootPrim->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
        }

        // Optionally initialize ship stats/fitting via InventorySubsystem (left as hook)
        if (InventorySubsystem)
        {
            // InventorySubsystem->Inventory_FetchShipFitting(...)
        }

        OnEntryFlowComplete.Broadcast();
    }
}

bool AEchoesServerGameMode::ExtractLoginOptions(const FString& Options, FString& OutToken, FGuid& OutCharacterId)
{
	// Parse URL options for Token and CharacterId
	// Format: ?Token=xxx&CharacterId=yyy
	
	bool bFoundToken = false;
	bool bFoundCharacterId = false;

	// Extract Token
	FString TokenKey = TEXT("Token=");
	int32 TokenIndex = Options.Find(TokenKey);
	if (TokenIndex != INDEX_NONE)
	{
		int32 StartIndex = TokenIndex + TokenKey.Len();
		int32 EndIndex = Options.Find(TEXT("&"), ESearchCase::IgnoreCase, ESearchDir::FromStart, StartIndex);
		
		if (EndIndex == INDEX_NONE)
		{
			EndIndex = Options.Find(TEXT("?"), ESearchCase::IgnoreCase, ESearchDir::FromStart, StartIndex);
		}
		
		if (EndIndex == INDEX_NONE)
		{
			EndIndex = Options.Len();
		}

		OutToken = Options.Mid(StartIndex, EndIndex - StartIndex);
		bFoundToken = !OutToken.IsEmpty();
	}

	// Extract CharacterId
	FString CharacterIdKey = TEXT("CharacterId=");
	int32 CharIdIndex = Options.Find(CharacterIdKey);
	if (CharIdIndex != INDEX_NONE)
	{
		int32 StartIndex = CharIdIndex + CharacterIdKey.Len();
		int32 EndIndex = Options.Find(TEXT("&"), ESearchCase::IgnoreCase, ESearchDir::FromStart, StartIndex);
		
		if (EndIndex == INDEX_NONE)
		{
			EndIndex = Options.Find(TEXT("?"), ESearchCase::IgnoreCase, ESearchDir::FromStart, StartIndex);
		}
		
		if (EndIndex == INDEX_NONE)
		{
			EndIndex = Options.Len();
		}

		FString CharIdStr = Options.Mid(StartIndex, EndIndex - StartIndex);
		bFoundCharacterId = FGuid::Parse(CharIdStr, OutCharacterId);
	}

	UE_LOG(LogTemp, Log, TEXT("ExtractLoginOptions: Token=%s, CharacterId=%s"), 
		bFoundToken ? TEXT("found") : TEXT("not found"),
		bFoundCharacterId ? TEXT("found") : TEXT("not found"));

	return bFoundToken && bFoundCharacterId;
}

void AEchoesServerGameMode::SpawnPlayerAtStation(APlayerController* PC, const FGuid& CharacterId, const FGuid& StationId, int32 ShipTypeId, const FGuid& HangarInstanceId)
{
	if (!PC)
	{
		UE_LOG(LogTemp, Error, TEXT("✗ SpawnPlayerAtStation: PlayerController is null"));
		return;
	}

	if (!HasAuthority())
	{
		UE_LOG(LogTemp, Error, TEXT("✗ SpawnPlayerAtStation: Called on client - must be server-only"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("╔══════════════════════════════════════════════════════════╗"));
	UE_LOG(LogTemp, Log, TEXT("║    SPAWNING PLAYER AT STATION (DOCKED STATE)            ║"));
	UE_LOG(LogTemp, Log, TEXT("╚══════════════════════════════════════════════════════════╝"));
	UE_LOG(LogTemp, Log, TEXT("CharacterId: %s"), *CharacterId.ToString());
	UE_LOG(LogTemp, Log, TEXT("StationId: %s"), *StationId.ToString());
	UE_LOG(LogTemp, Log, TEXT("ShipTypeId: %d"), ShipTypeId);
	UE_LOG(LogTemp, Log, TEXT("HangarInstanceId: %s"), *HangarInstanceId.ToString());

	// Try to get ship definition from ItemTypeRegistry (with nullptr safety check)
	FEchoesItemDefinitionRow ShipDef;
	bool bHasShipDef = false;
	if (InventorySubsystem)
	{
		bHasShipDef = InventorySubsystem->TryGetItemFromRegistry(ShipTypeId, ShipDef);
		if (bHasShipDef)
		{
			UE_LOG(LogTemp, Log, TEXT("✓ Ship definition found: %s"), *ShipDef.DisplayName.ToString());
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("⚠ Ship definition not found for TypeId %d"), ShipTypeId);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("⚠ InventorySubsystem not available for ship lookup"));
	}

	// ==================== STATION SEARCH LOGIC ====================
	// 
	// Use TActorIterator to find the station actor by StationId
	// This ensures we spawn the player at the correct station in the world
	//
	// =============================================================
	
	AStationActor* FoundStation = nullptr;
	UE_LOG(LogTemp, Log, TEXT("Searching for station in world..."));

	for (TActorIterator<AStationActor> It(GetWorld()); It; ++It)
	{
		AStationActor* Station = *It;
		if (Station && Station->GetStationId() == StationId)
		{
			FoundStation = Station;
			UE_LOG(LogTemp, Log, TEXT("✓ Station found: %s (Type: %s)"), 
				*Station->GetStationName(), 
				*Station->GetStationType());
			break;
		}
	}

	if (!FoundStation)
	{
		UE_LOG(LogTemp, Warning, TEXT("⚠ Station with ID %s not found in world!"), *StationId.ToString());
		UE_LOG(LogTemp, Warning, TEXT("  This may occur if world generation is incomplete"));
		UE_LOG(LogTemp, Warning, TEXT("  Falling back to safe spawn in open space at (0, 0, 0)"));

		// Safety fallback: spawn in open space at origin
		FVector SafetySpawnLocation = FVector(0.0f, 0.0f, 0.0f);
		SpawnPlayerInSpace(PC, SafetySpawnLocation, FRotator::ZeroRotator, ShipTypeId);
		return;
	}

	// ==================== SPAWN PLAYER PAWN ====================
	// 
	// Call RestartPlayer to create the ship pawn for this player
	// The pawn will initially spawn at the default spawn point
	//
	// ===========================================================
	
	UE_LOG(LogTemp, Log, TEXT("Creating player pawn..."));
	RestartPlayer(PC);

	APawn* PlayerPawn = PC->GetPawn();
	if (!PlayerPawn)
	{
		UE_LOG(LogTemp, Error, TEXT("✗ Failed to spawn player pawn"));
		UE_LOG(LogTemp, Warning, TEXT("  Falling back to safe spawn"));
		
		FVector SafetySpawnLocation = FVector(0.0f, 0.0f, 0.0f);
		SpawnPlayerInSpace(PC, SafetySpawnLocation, FRotator::ZeroRotator, ShipTypeId);
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("✓ Player pawn created: %s"), *PlayerPawn->GetName());

	// ==================== HANGAR INSTANCE ISOLATION ====================
	//	
	// Create or retrieve the player's unique hangar instance with spatial isolation
	// 	
	// Process:
	// 1. HangarManager calculates deterministic spatial offset from HangarInstanceId
	// 2. Uses 100x100x20 grid with 10km separation (1,000,000 UE units per cell)
	// 3. Returns offset vector that will be applied to ship pawn location
	//	
	// Formula: TargetLocation = StationLocation + SpatialOffset
	//	
	// This ensures each player has their own isolated hangar instance at the
	// same station without visual/audio interference from other players.
	//	
	// ===================================================================
	
	FVector HangarOffset = FVector::ZeroVector;
	if (HangarManager && CharacterId.IsValid())
	{
		// Get spatial offset for this player's hangar instance
		HangarOffset = HangarManager->GetOrCreateHangarInstance(CharacterId, StationId, HangarInstanceId);
		UE_LOG(LogTemp, Log, TEXT("✓ Hangar instance offset calculated: %s"), *HangarOffset.ToString());
	}
	else
	{
		if (!HangarManager)
		{
			UE_LOG(LogTemp, Warning, TEXT("⚠ HangarManager not available - no spatial isolation"));
		}
		if (!CharacterId.IsValid())
		{
			UE_LOG(LogTemp, Warning, TEXT("⚠ CharacterId invalid - no spatial isolation"));
		}
	}

	// ==================== MOVE PAWN TO STATION ====================
	//
	// Position the ship pawn at the station location
	// The hangar offset will be applied by BindShipPawnToHangar
	//
	// ==============================================================
	
	FVector StationLocation = FoundStation->GetActorLocation();
	FRotator StationRotation = FoundStation->GetActorRotation();
	
	// Set pawn to station location (offset will be applied next)
	PlayerPawn->SetActorLocation(StationLocation);
	PlayerPawn->SetActorRotation(StationRotation);
	
	// Bind pawn to hangar instance for spatial isolation
	// This applies the spatial offset and configures visibility settings
	if (HangarManager && CharacterId.IsValid())
	{
		HangarManager->BindShipPawnToHangar(CharacterId, PlayerPawn);
		UE_LOG(LogTemp, Log, TEXT("✓ Ship pawn bound to hangar instance with spatial isolation"));
	}
	
	UE_LOG(LogTemp, Log, TEXT("✓ Pawn positioned at station (with spatial offset)"));

	// ==================== DOCKED STATE SETUP ====================
	//
	// Configure the ship pawn for docked state:
	// - Hidden: Player is "inside" the station, ship should not be visible
	// - No collision: Prevents physics interactions while docked
	// - No physics: Disables physics simulation while in station
	// - No movement: Disables character movement component if present
	//
	// This ensures the player is physically isolated and cannot interact
	// with the world while viewing the station menu.
	//
	// ============================================================
	
	// 1. Hide the pawn visually (player is inside station)
	PlayerPawn->SetActorHiddenInGame(true);
	UE_LOG(LogTemp, Log, TEXT("✓ Pawn hidden (inside station)"));

	// 2. Disable collision
	PlayerPawn->SetActorEnableCollision(false);
	UE_LOG(LogTemp, Log, TEXT("✓ Pawn collision disabled"));

	// 3. Disable physics and movement
	if (UPrimitiveComponent* RootPrimitive = Cast<UPrimitiveComponent>(PlayerPawn->GetRootComponent()))
	{
		RootPrimitive->SetSimulatePhysics(false);
		RootPrimitive->SetEnableGravity(false);
		UE_LOG(LogTemp, Log, TEXT("✓ Physics disabled on pawn"));
	}

	// 4. If it's a character, disable movement component
	if (ACharacter* Character = Cast<ACharacter>(PlayerPawn))
	{
		if (UCharacterMovementComponent* MovementComp = Character->GetCharacterMovement())
		{
			MovementComp->DisableMovement();
			UE_LOG(LogTemp, Log, TEXT("✓ Character movement disabled"));
		}
	}

	// ==================== OPEN STATION MENU ====================
	//
	// Call ClientRPC to open station menu on the player's client
	// This is called AFTER the ship has been successfully:
	// 1. Spawned
	// 2. Moved to station location with spatial offset
	// 3. Hidden and physics disabled
	//
	// Network Security:
	// - ClientRPC ensures only the specific player receives the menu
	// - HangarInstanceId links the UI to the player's personal hangar storage
	// - Menu operations will use this ID to ensure inventory isolation
	//
	// ==========================================================
	
	UE_LOG(LogTemp, Log, TEXT("Opening station menu for player..."));

	// Use the HangarInstanceId from backend for inventory association
	// This ensures the player sees their personal hangar inventory
	FoundStation->ClientRPC_OpenStationMenu(
		FoundStation->GetStationName(),
		FoundStation->GetStationType(),
		HangarInstanceId);

	UE_LOG(LogTemp, Log, TEXT("✓ Station menu opened with HangarInstanceId: %s"), *HangarInstanceId.ToString());

	// ==================== FINALIZE ====================
	
	UE_LOG(LogTemp, Log, TEXT("╔══════════════════════════════════════════════════════════╗"));
	UE_LOG(LogTemp, Log, TEXT("║    PLAYER SUCCESSFULLY SPAWNED IN DOCKED STATE          ║"));
	UE_LOG(LogTemp, Log, TEXT("╚══════════════════════════════════════════════════════════╝"));
	UE_LOG(LogTemp, Log, TEXT("Player: %s"), *PC->GetName());
	UE_LOG(LogTemp, Log, TEXT("Station: %s"), *FoundStation->GetStationName());
	UE_LOG(LogTemp, Log, TEXT("Location: %s (with spatial offset)"), *StationLocation.ToString());
	UE_LOG(LogTemp, Log, TEXT("Hangar Instance: %s"), *HangarInstanceId.ToString());

	// Broadcast entry flow complete
	OnEntryFlowComplete.Broadcast();
}

void AEchoesServerGameMode::SpawnPlayerInSpace(APlayerController* PC, const FVector& Position, const FRotator& Rotation, int32 ShipTypeId)
{
	if (!PC)
	{
		UE_LOG(LogTemp, Error, TEXT("✗ SpawnPlayerInSpace: PlayerController is null"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Spawning player in space at: %s (ShipTypeId: %d)"), *Position.ToString(), ShipTypeId);

	// Try to get ship definition from ItemTypeRegistry (with nullptr safety check)
	FEchoesItemDefinitionRow ShipDef;
bool bHasShipDef = false;
if (InventorySubsystem)
{
	bHasShipDef = InventorySubsystem->TryGetItemFromRegistry(ShipTypeId, ShipDef);
	if (bHasShipDef)
	{
		UE_LOG(LogTemp, Log, TEXT("✓ Ship definition found: %s"), *ShipDef.DisplayName.ToString());
		UE_LOG(LogTemp, Log, TEXT("  Ship mesh: %s"), ShipDef.WorldMesh.IsNull() ? TEXT("None") : TEXT("Available"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("⚠ Ship definition not found for TypeId %d, using default pawn"), ShipTypeId);
	}
}
else
{
	UE_LOG(LogTemp, Warning, TEXT("⚠ InventorySubsystem not available for ship lookup"));
}

	// Spawn pawn at position
	RestartPlayer(PC);

	if (PC->GetPawn())
	{
		PC->GetPawn()->SetActorLocation(Position);
		PC->GetPawn()->SetActorRotation(Rotation);
		
		// TODO: Apply ship mesh from ShipDef->WorldMesh if available
		// This would require:
		// 1. Getting the mesh component from the pawn
		// 2. Async loading the mesh if not already loaded
		// 3. Setting the mesh once loaded
		// For example:
		// if (ShipDef && !ShipDef->WorldMesh.IsNull())
		// {
		//     UStaticMeshComponent* MeshComp = PC->GetPawn()->FindComponentByClass<UStaticMeshComponent>();
		//     if (MeshComp)
		//     {
		//         // Load mesh asynchronously
		//         InventorySubsystem->AsyncLoadItemWorldMesh(
		//             FString::FromInt(ShipTypeId),
		//             FOnWorldMeshLoaded::CreateLambda([MeshComp](UStaticMesh* LoadedMesh) {
		//                 if (MeshComp && LoadedMesh)
		//                 {
		//                     MeshComp->SetStaticMesh(LoadedMesh);
		//                 }
		//             })
		//         );
		//     }
		// }
		
		UE_LOG(LogTemp, Log, TEXT("✓ Player spawned in space"));
		
		// TODO: Sync inventory: InventorySubsystem->Inventory_FetchShips()
		// TODO: Set velocity and orientation based on last saved state
		
		OnEntryFlowComplete.Broadcast();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("✗ Failed to spawn player pawn in space"));
	}
}

FString AEchoesServerGameMode::GetApiBaseUrl() const
{
	FString ApiBaseUrl;
	
	// Try to read from config
	if (GConfig->GetString(
		TEXT("/Script/Echoes.EchoesAuthSubsystem"),
		TEXT("ApiBaseUrl"),
		ApiBaseUrl,
		GGameIni))
	{
		return ApiBaseUrl;
	}

	// Default to localhost
	return TEXT("http://localhost:5116/api");
}

FString AEchoesServerGameMode::GetMapPath(const TSoftObjectPtr<UWorld>& Map) const
{
    if (Map.IsNull())
    {
        return FString();
    }

    // If the asset is already loaded, get long package name from the object
    UObject* Resolved = Map.Get();
    if (Resolved)
    {
        UPackage* Package = Resolved->GetOutermost();
        if (Package)
        {
            return Package->GetName();
        }
    }

    // Fallback: use the asset reference string and convert to long package name
    // The ToString returns something like "World'/Game/Maps/MenuMap.MenuMap'" or "/Game/Maps/MenuMap"
    FString AssetPath = Map.ToSoftObjectPath().ToString();
    if (AssetPath.StartsWith(TEXT("/")))
    {
        // Convert '/Game/Maps/MenuMap.MenuMap' or '/Game/Maps/MenuMap' to long package name
        // Ensure we strip any class prefix like 'World\'' and trailing asset name
        // Use FPackageName utilities if available
        FString LongPackageName = AssetPath;

        // If contains a dot, strip suffix after dot
        int32 DotIndex;
        if (LongPackageName.FindChar(TEXT('.'), DotIndex))
        {
            LongPackageName = LongPackageName.Left(DotIndex);
        }

        return LongPackageName;
    }

    return FString();
}

void AEchoesServerGameMode::KickPlayerToMenu(APlayerController* Player, const FString& Reason)
{
    if (!Player)
    {
        UE_LOG(LogTemp, Warning, TEXT("✗ KickPlayerToMenu: Player is null (Reason: %s)"), *Reason);
        return;
    }

    UE_LOG(LogTemp, Warning, TEXT("✗ Kicking player to menu: %s"), *Reason);

    // Validate MenuMap soft pointer
    if (MenuMap.IsNull())
    {
        UE_LOG(LogTemp, Error, TEXT("KickPlayerToMenu: MenuMap is not set. Cannot travel to menu."));
        return;
    }

    // Resolve path
    FString MapPath = GetMapPath(MenuMap);
    if (MapPath.IsEmpty())
    {
        UE_LOG(LogTemp, Error, TEXT("KickPlayerToMenu: Failed to resolve MenuMap path from TSoftObjectPtr."));
        return;
    }

    // Perform client travel safely
    UE_LOG(LogTemp, Log, TEXT("KickPlayerToMenu: Traveling player %s to map: %s"), *Player->GetName(), *MapPath);
    Player->ClientTravel(MapPath, TRAVEL_Absolute);
}

// Implement RequestUndock - server authoritative undocking logic
void AEchoesServerGameMode::RequestUndock(APlayerController* PC)
{
    if (!HasAuthority())
    {
        UE_LOG(LogTemp, Error, TEXT("✗ RequestUndock called on client - aborting"));
        return;
    }

    if (!PC)
    {
        UE_LOG(LogTemp, Error, TEXT("✗ RequestUndock: PlayerController is null"));
        return;
    }

    APawn* PlayerPawn = PC->GetPawn();
    if (!PlayerPawn)
    {
        UE_LOG(LogTemp, Error, TEXT("✗ RequestUndock: Player has no pawn"));
        return;
    }

    if (!HangarManager)
    {
        UE_LOG(LogTemp, Error, TEXT("✗ RequestUndock: HangarManager not available"));
        return;
    }

    // Find character id associated with this pawn (hangar instance lookup)
    FGuid CharacterId;
    if (!HangarManager->FindCharacterIdByPawn(PlayerPawn, CharacterId))
    {
        UE_LOG(LogTemp, Error, TEXT("✗ RequestUndock: Could not find character id for pawn %s"), *PlayerPawn->GetName());
        return;
    }

    // Get hangar instance data
    FHangarInstance Instance = HangarManager->GetHangarInstance(CharacterId);

    // Validate station id
    if (!Instance.StationId.IsValid())
    {
        UE_LOG(LogTemp, Error, TEXT("✗ RequestUndock: Hangar instance has invalid StationId for character %s"), *CharacterId.ToString());
        return;
    }

    // Find station actor in world
    AStationActor* FoundStation = nullptr;
    for (TActorIterator<AStationActor> It(GetWorld()); It; ++It)
    {
        AStationActor* Station = *It;
        if (Station && Station->GetStationId() == Instance.StationId)
        {
            FoundStation = Station;
            break;
        }
    }

    if (!FoundStation)
    {
        UE_LOG(LogTemp, Error, TEXT("✗ RequestUndock: Station with ID %s not found"), *Instance.StationId.ToString());
        return;
    }

    // Calculate safe exit point
    const float SafeDistance = 50000.0f; // 500m
    const float ImpulseStrength = 1000.0f;

    FVector StationLocation = FoundStation->GetActorLocation();
    FVector StationForward = FoundStation->GetActorForwardVector();

    FVector UndockLocation = StationLocation + (StationForward * SafeDistance);
    FRotator UndockRotation = FoundStation->GetActorRotation();

    UE_LOG(LogTemp, Log, TEXT("RequestUndock: Moving pawn to undock location %s"), *UndockLocation.ToString());

    // Position and restore pawn
    PlayerPawn->SetActorLocation(UndockLocation);
    PlayerPawn->SetActorRotation(UndockRotation);
    PlayerPawn->SetActorHiddenInGame(false);
    PlayerPawn->SetActorEnableCollision(true);

    // Enable physics on root primitive if present
    if (UPrimitiveComponent* RootPrimitive = Cast<UPrimitiveComponent>(PlayerPawn->GetRootComponent()))
    {
        RootPrimitive->SetSimulatePhysics(true);
        RootPrimitive->SetEnableGravity(false);

        // Apply initial impulse away from station
        FVector Impulse = StationForward * ImpulseStrength;
        RootPrimitive->AddImpulse(Impulse, NAME_None, true);
        UE_LOG(LogTemp, Log, TEXT("RequestUndock: Applied impulse %s to pawn"), *Impulse.ToString());
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("RequestUndock: Pawn root is not a primitive - cannot apply physics impulse"));
    }

    // If pawn is character, enable movement
    if (ACharacter* Character = Cast<ACharacter>(PlayerPawn))
    {
        if (UCharacterMovementComponent* MovementComp = Character->GetCharacterMovement())
        {
            MovementComp->SetMovementMode(MOVE_Flying);
            UE_LOG(LogTemp, Log, TEXT("RequestUndock: Character movement set to flying"));
        }
    }

    // Cleanup hangar instance
    HangarManager->RemoveHangarInstance(CharacterId);
    UE_LOG(LogTemp, Log, TEXT("RequestUndock: Removed hangar instance for character %s"), *CharacterId.ToString());

    // Close station menu on client
    FoundStation->ClientRPC_CloseStationMenu();

    UE_LOG(LogTemp, Log, TEXT("RequestUndock: Undock sequence complete for player %s"), *PC->GetName());
}
