// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesServerGameMode.h"
#include "EchoesServerManagementSubsystem.h"
#include "EchoesWorldGenerator.h"
#include "EchoesJumpManager.h"
#include "EchoesServerDiscoveryTypes.h"
#include "EchoesInventorySubsystem.h"
#include "EchoesAuthSubsystem.h"
#include "Core/Server/EchoesServerAuthSubsystem.h"
#include "Core/Server/EchoesHangarManager.h"
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

AEchoesServerGameMode::AEchoesServerGameMode()
{
	bWorldGenerated = false;
	bWaitingForConfig = false;
	bSubscribedToConfigDelegate = false;
	bPlayerSpawnAllowed = false;  // Only allow spawning after token validation

	// Create jump manager component
	JumpManager = CreateDefaultSubobject<UEchoesJumpManager>(TEXT("JumpManager"));

	// Get HTTP module
	Http = &FHttpModule::Get();
}

void AEchoesServerGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Only run on server
	if (!HasAuthority())
	{
		UE_LOG(LogTemp, Verbose, TEXT("EchoesServerGameMode: Running on client, skipping initialization"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("╔══════════════════════════════════════════════════════════╗"));
	UE_LOG(LogTemp, Log, TEXT("║    ECHOES SERVER GAMEMODE - INITIALIZATION              ║"));
	UE_LOG(LogTemp, Log, TEXT("╚══════════════════════════════════════════════════════════╝"));

	// Get reference to server management subsystem
	UGameInstance* GameInstance = GetWorld()->GetGameInstance();
	if (GameInstance)
	{
		ServerManagementSubsystem = GameInstance->GetSubsystem<UEchoesServerManagementSubsystem>();
		if (ServerManagementSubsystem)
		{
			UE_LOG(LogTemp, Log, TEXT("✓ ServerManagementSubsystem found"));

			// Check if server is already registered and has config
			if (ServerManagementSubsystem->IsServerRegistered())
			{
				UE_LOG(LogTemp, Log, TEXT("✓ Server already registered"));
				
				// Try to trigger world generation immediately
				InitializeWorldGeneration();
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("⚠ Server not yet registered, waiting for config..."));
				bWaitingForConfig = true;
			}

			// Subscribe to config received delegate (if not already subscribed)
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

		// Get inventory subsystem reference
		InventorySubsystem = GameInstance->GetSubsystem<UEchoesInventorySubsystem>();
		if (InventorySubsystem)
		{
			UE_LOG(LogTemp, Log, TEXT("✓ InventorySubsystem found"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("⚠ InventorySubsystem not found"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("✗ GameInstance is null"));
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
		// Spawn a new HangarManager
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
		else
		{
			UE_LOG(LogTemp, Error, TEXT("✗ Failed to spawn HangarManager"));
		}
	}

	UE_LOG(LogTemp, Log, TEXT("GameMode initialization complete. WorldGenerated: %s"),
		bWorldGenerated ? TEXT("true") : TEXT("false"));
}

void AEchoesServerGameMode::PostLogin(APlayerController* NewPlayer)
{
	if (!HasAuthority())
	{
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("╔══════════════════════════════════════════════════════════╗"));
	UE_LOG(LogTemp, Log, TEXT("║    PLAYER LOGIN - AWAITING TOKEN VALIDATION            ║"));
	UE_LOG(LogTemp, Log, TEXT("╚══════════════════════════════════════════════════════════╝"));
	UE_LOG(LogTemp, Log, TEXT("Player: %s"), NewPlayer ? *NewPlayer->GetName() : TEXT("Unknown"));

	// Reset spawn flag for this player - they must validate first
	bPlayerSpawnAllowed = false;

	// Call base class to do important initialization (but our HandleStartingNewPlayer override will prevent spawn)
	Super::PostLogin(NewPlayer);

	// Check if world is generated
	if (!bWorldGenerated)
	{
		UE_LOG(LogTemp, Warning, TEXT("⚠ World not yet generated, player may spawn in incomplete world"));
		
		// Try to trigger generation if we're still waiting
		if (bWaitingForConfig)
		{
			UE_LOG(LogTemp, Warning, TEXT("Attempting to trigger world generation..."));
			TriggerWorldGeneration();
		}
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("✓ World is generated, validating player authentication..."));
		
		// Extract login options from URL
		FString Options = NewPlayer->PlayerState ? NewPlayer->PlayerState->SavedNetworkAddress : TEXT("");
		FString Token;
		FGuid CharacterId;

		if (ExtractLoginOptions(Options, Token, CharacterId))
		{
			UE_LOG(LogTemp, Log, TEXT("Extracted Token and CharacterId: %s"), *CharacterId.ToString());
			
			// Validate token through Backend API
			UGameInstance* GameInstance = GetGameInstance();
			if (!GameInstance)
			{
				KickPlayerToMenu(NewPlayer, TEXT("GameInstance is null - cannot validate token"));
				return;
			}

			UEchoesServerAuthSubsystem* ServerAuthSubsystem = 
				GameInstance->GetSubsystem<UEchoesServerAuthSubsystem>();

			if (ServerAuthSubsystem)
			{
				ServerAuthSubsystem->ValidateClientToken(
					Token,
					// OnSuccess
					[this, NewPlayer, CharacterId](const FGuid& ValidatedCharacterId, const FGuid& AccountId)
					{
						UE_LOG(LogTemp, Log, TEXT("╔══════════════════════════════════════════════════════════╗"));
						UE_LOG(LogTemp, Log, TEXT("║    ✓ TOKEN VALIDATED - SPAWNING PLAYER                  ║"));
						UE_LOG(LogTemp, Log, TEXT("╚══════════════════════════════════════════════════════════╝"));
						UE_LOG(LogTemp, Log, TEXT("Character: %s"), *ValidatedCharacterId.ToString());
						UE_LOG(LogTemp, Log, TEXT("Account: %s"), *AccountId.ToString());
						
						// Verify the character ID matches
						if (ValidatedCharacterId == CharacterId)
						{
							// Allow spawning now that token is validated
							bPlayerSpawnAllowed = true;
							
							// Spawn player at their saved location
							// This will handle the spawn internally via RestartPlayer()
							SpawnPlayerAtLocation(NewPlayer);
						}
						else
						{
							KickPlayerToMenu(NewPlayer, FString::Printf(
								TEXT("Character ID mismatch! Expected=%s, Got=%s"),
								*CharacterId.ToString(), *ValidatedCharacterId.ToString()));
						}
					},
					// OnFailure
					[this, NewPlayer](const FString& Error)
					{
						KickPlayerToMenu(NewPlayer, FString::Printf(TEXT("Authentication failed: %s"), *Error));
					}
				);
			}
			else
			{
				KickPlayerToMenu(NewPlayer, TEXT("ServerAuthSubsystem not available"));
			}
		}
		else
		{
			KickPlayerToMenu(NewPlayer, TEXT("Failed to extract login options - no valid token"));
		}
	}
}

void AEchoesServerGameMode::HandleStartingNewPlayer(APlayerController* NewPlayer)
{
	// This override prevents automatic spawning during PostLogin
	// We only spawn after token validation by setting bPlayerSpawnAllowed = true
	// and calling SpawnPlayerAtLocation() which handles spawning internally
	
	if (!HasAuthority())
	{
		return;
	}

	// Safety check: Only allow spawn if token validation completed successfully
	if (!bPlayerSpawnAllowed)
	{
		UE_LOG(LogTemp, Warning, TEXT("HandleStartingNewPlayer called but spawning not allowed yet (awaiting token validation)"));
		return;
	}

	// If spawning is allowed, call the base class implementation
	if (NewPlayer)
	{
		UE_LOG(LogTemp, Log, TEXT("HandleStartingNewPlayer: Allowing spawn after token validation"));
		Super::HandleStartingNewPlayer(NewPlayer);
	}
}

void AEchoesServerGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);

	if (!HasAuthority())
	{
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Player logged out: %s"), Exiting ? *Exiting->GetName() : TEXT("Unknown"));
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

void AEchoesServerGameMode::QueryCharacterLocation(const FGuid& CharacterId, const FString& Token, APlayerController* PlayerController)
{
	if (!Http || !PlayerController)
	{
		UE_LOG(LogTemp, Error, TEXT("✗ QueryCharacterLocation: Invalid parameters"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Querying character location from API..."));

	// Create HTTP request
	TSharedRef<IHttpRequest> Request = Http->CreateRequest();
	Request->SetVerb(TEXT("GET"));
	Request->SetURL(GetApiBaseUrl() + FString::Printf(TEXT("/character/%s/location"), *CharacterId.ToString()));
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	Request->SetHeader(TEXT("Authorization"), TEXT("Bearer ") + Token);

	// Set timeout (10 seconds)
	Request->SetTimeout(10.0f);

	// Bind response handler with player controller context
	Request->OnProcessRequestComplete().BindUObject(
		this,
		&AEchoesServerGameMode::OnCharacterLocationReceived,
		PlayerController,
		Token);

	// Send request
	if (!Request->ProcessRequest())
	{
		UE_LOG(LogTemp, Error, TEXT("✗ Failed to send character location request"));
		
		// Safety fallback
		FVector SpawnLocation = FVector(0.0f, 0.0f, 1000.0f);
		SpawnPlayerInSpace(PlayerController, SpawnLocation, FRotator::ZeroRotator, 0);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("✓ Character location request sent"));
	}
}

void AEchoesServerGameMode::OnCharacterLocationReceived(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful,
	APlayerController* PlayerController,
	FString Token)
{
	if (!PlayerController || !PlayerController->IsValidLowLevel())
	{
		UE_LOG(LogTemp, Error, TEXT("✗ PlayerController is invalid in location response"));
		return;
	}

	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("✗ Character location request failed (timeout or network error)"));
		UE_LOG(LogTemp, Warning, TEXT("  Spawning at safety fallback location"));
		
		// Safety fallback: spawn in default location
		FVector SafetyLocation = FVector(0.0f, 0.0f, 1000.0f);
		SpawnPlayerInSpace(PlayerController, SafetyLocation, FRotator::ZeroRotator, 0);
		return;
	}

	int32 ResponseCode = Response->GetResponseCode();
	FString ResponseContent = Response->GetContentAsString();

	UE_LOG(LogTemp, Log, TEXT("Character location response: %d - %s"), ResponseCode, *ResponseContent);

	if (ResponseCode != 200)
	{
		UE_LOG(LogTemp, Error, TEXT("✗ Character location request failed with code %d"), ResponseCode);
		
		// Safety fallback
		FVector SafetyLocation = FVector(0.0f, 0.0f, 1000.0f);
		SpawnPlayerInSpace(PlayerController, SafetyLocation, FRotator::ZeroRotator, 0);
		return;
	}

	// Parse JSON response
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseContent);

	if (!FJsonSerializer::Deserialize(Reader, JsonObject) || !JsonObject.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("✗ Failed to parse character location JSON"));
		
		// Safety fallback
		FVector SafetyLocation = FVector(0.0f, 0.0f, 1000.0f);
		SpawnPlayerInSpace(PlayerController, SafetyLocation, FRotator::ZeroRotator, 0);
		return;
	}

	// Extract location data
	FCharacterLocationData LocationData;
	LocationData.IsDocked = JsonObject->GetBoolField(TEXT("isDocked"));
	LocationData.InWarp = JsonObject->GetBoolField(TEXT("inWarp"));
	LocationData.PositionX = JsonObject->GetNumberField(TEXT("positionX"));
	LocationData.PositionY = JsonObject->GetNumberField(TEXT("positionY"));
	LocationData.PositionZ = JsonObject->GetNumberField(TEXT("positionZ"));

	if (JsonObject->HasField(TEXT("stationId")) && !JsonObject->GetStringField(TEXT("stationId")).IsEmpty())
	{
		FGuid::Parse(JsonObject->GetStringField(TEXT("stationId")), LocationData.StationId);
	}

	if (JsonObject->HasField(TEXT("stationName")))
	{
		LocationData.StationName = JsonObject->GetStringField(TEXT("stationName"));
	}

	// Parse hangar instance ID for player isolation
	if (JsonObject->HasField(TEXT("hangarInstanceId")) && !JsonObject->GetStringField(TEXT("hangarInstanceId")).IsEmpty())
	{
		FGuid::Parse(JsonObject->GetStringField(TEXT("hangarInstanceId")), LocationData.HangarInstanceId);
		UE_LOG(LogTemp, Log, TEXT("✓ HangarInstanceId parsed: %s"), *LocationData.HangarInstanceId.ToString());
	}

	// Parse characterId for player identification
	if (JsonObject->HasField(TEXT("characterId")) && !JsonObject->GetStringField(TEXT("characterId")).IsEmpty())
	{
		FGuid::Parse(JsonObject->GetStringField(TEXT("characterId")), LocationData.CharacterId);
	}

	// Get active ship type ID (query from inventory or default)
	// For now, use a default ship type ID (will be improved with proper inventory query)
	LocationData.ActiveShipTypeId = 670; // Default: Ibis (Caldari rookie ship)

	UE_LOG(LogTemp, Log, TEXT("Location data: IsDocked=%s, Position=(%.1f, %.1f, %.1f), ShipTypeId=%d"),
		LocationData.IsDocked ? TEXT("true") : TEXT("false"),
		LocationData.PositionX, LocationData.PositionY, LocationData.PositionZ,
		LocationData.ActiveShipTypeId);

	// Perform spawn
	PerformSpawnWithLocationData(LocationData, PlayerController);
}

void AEchoesServerGameMode::PerformSpawnWithLocationData(
	const FCharacterLocationData& LocationData,
	APlayerController* PlayerController)
{
	if (!PlayerController)
	{
		UE_LOG(LogTemp, Error, TEXT("✗ PerformSpawnWithLocationData: PlayerController is null"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Performing spawn with location data..."));

	FVector SpawnPosition(LocationData.PositionX, LocationData.PositionY, LocationData.PositionZ);
	FRotator SpawnRotation = FRotator::ZeroRotator;

	if (LocationData.IsDocked)
	{
		UE_LOG(LogTemp, Log, TEXT("Character is docked at station: %s"), *LocationData.StationName);
		SpawnPlayerAtStation(PlayerController, LocationData.CharacterId, LocationData.StationId, LocationData.ActiveShipTypeId, LocationData.HangarInstanceId);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Character is in space at position: %s"), *SpawnPosition.ToString());
		SpawnPlayerInSpace(PlayerController, SpawnPosition, SpawnRotation, LocationData.ActiveShipTypeId);
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

void AEchoesServerGameMode::KickPlayerToMenu(APlayerController* Player, const FString& Reason)
{
	if (!Player)
	{
		UE_LOG(LogTemp, Warning, TEXT("✗ KickPlayerToMenu: Player is null (Reason: %s)"), *Reason);
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("✗ Kicking player to menu: %s"), *Reason);
	Player->ClientTravel(MenuMapPath, TRAVEL_Absolute);
}

void AEchoesServerGameMode::RequestUndock(APlayerController* PC)
{
	if (!PC)
	{
		UE_LOG(LogTemp, Error, TEXT("✗ RequestUndock: PlayerController is null"));
		return;
	}

	if (!HasAuthority())
	{
		UE_LOG(LogTemp, Error, TEXT("✗ RequestUndock: Called on client - must be server-only"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("╔══════════════════════════════════════════════════════════╗"));
	UE_LOG(LogTemp, Log, TEXT("║    PROCESSING UNDOCK REQUEST                            ║"));
	UE_LOG(LogTemp, Log, TEXT("╚══════════════════════════════════════════════════════════╝"));
	UE_LOG(LogTemp, Log, TEXT("Player: %s"), *PC->GetName());

	// Get player's pawn
	APawn* PlayerPawn = PC->GetPawn();
	if (!PlayerPawn)
	{
		UE_LOG(LogTemp, Error, TEXT("✗ Player has no pawn"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Player pawn: %s"), *PlayerPawn->GetName());

	// ==================== FIND PLAYER'S DOCKED STATION ====================
	//
	// Find the station where the player is docked by checking HangarManager
	// for the player's hangar instance which contains the StationId
	//
	// ======================================================================

	if (!HangarManager)
	{
		UE_LOG(LogTemp, Error, TEXT("✗ HangarManager not available"));
		return;
	}

	// 1. Находим персонажа по его пешке в ангаре
	FGuid CharacterId;
	if (!HangarManager->FindCharacterIdByPawn(PlayerPawn, CharacterId))
	{
		UE_LOG(LogTemp, Error, TEXT("RequestUndock: Hangar instance not found for pawn"));
		return;
	}

	FHangarInstance PlayerHangarInstance = HangarManager->GetHangarInstance(CharacterId);
	if (!PlayerHangarInstance.InstanceId.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("✗ Failed to retrieve hangar instance"));
		return;
	}

	FGuid StationId = PlayerHangarInstance.StationId;
	UE_LOG(LogTemp, Log, TEXT("✓ Found player's hangar at station: %s"), *StationId.ToString());

	// ==================== FIND STATION ACTOR ====================
	//
	// Use TActorIterator to find the station actor in the world
	//
	// ===========================================================

	AStationActor* FoundStation = nullptr;
	
	for (TActorIterator<AStationActor> It(GetWorld()); It; ++It)
	{
		AStationActor* Station = *It;
		if (Station && Station->GetStationId() == StationId)
		{
			FoundStation = Station;
			UE_LOG(LogTemp, Log, TEXT("✓ Station found: %s"), *Station->GetStationName());
			break;
		}
	}

	if (!FoundStation)
	{
		UE_LOG(LogTemp, Error, TEXT("✗ Station with ID %s not found in world"), *StationId.ToString());
		return;
	}

	// ==================== CALCULATE SAFE EXIT POINT ====================
	//
	// Calculate spawn position in front of station using forward vector
	// SafeDistance should be larger than station collision radius
	//
	// ===================================================================

	FVector StationLocation = FoundStation->GetActorLocation();
	FVector StationForward = FoundStation->GetActorForwardVector();
	
	// Safe distance: 500m (50,000 units) from station center
	// This is far enough to avoid collision with most station types
	const float SafeDistance = 50000.0f;
	
	FVector UndockLocation = StationLocation + (StationForward * SafeDistance);
	FRotator UndockRotation = FoundStation->GetActorRotation();

	UE_LOG(LogTemp, Log, TEXT("✓ Calculated undock position:"));
	UE_LOG(LogTemp, Log, TEXT("  Station Location: %s"), *StationLocation.ToString());
	UE_LOG(LogTemp, Log, TEXT("  Station Forward: %s"), *StationForward.ToString());
	UE_LOG(LogTemp, Log, TEXT("  Undock Location: %s"), *UndockLocation.ToString());
	UE_LOG(LogTemp, Log, TEXT("  Distance from station: %.1fm"), SafeDistance / 100.0f);

	// ==================== PHYSICAL ACTIVATION ====================
	//
	// Restore ship to physical world:
	// 1. Move to undock location
	// 2. Restore visibility
	// 3. Enable collision
	// 4. Enable physics simulation
	//
	// ============================================================

	// 1. Move pawn to undock location
	PlayerPawn->SetActorLocation(UndockLocation);
	PlayerPawn->SetActorRotation(UndockRotation);
	UE_LOG(LogTemp, Log, TEXT("✓ Pawn moved to undock location"));

	// 2. Restore visibility
	PlayerPawn->SetActorHiddenInGame(false);
	UE_LOG(LogTemp, Log, TEXT("✓ Pawn visibility restored"));

	// 3. Enable collision
	PlayerPawn->SetActorEnableCollision(true);
	UE_LOG(LogTemp, Log, TEXT("✓ Pawn collision enabled"));

	// 4. Enable physics simulation
	if (UPrimitiveComponent* RootPrimitive = Cast<UPrimitiveComponent>(PlayerPawn->GetRootComponent()))
	{
		RootPrimitive->SetSimulatePhysics(true);
		RootPrimitive->SetEnableGravity(false); // No gravity in space
		UE_LOG(LogTemp, Log, TEXT("✓ Physics simulation enabled"));
	}

	// 5. Restore movement if it was disabled
	if (ACharacter* Character = Cast<ACharacter>(PlayerPawn))
	{
		if (UCharacterMovementComponent* MovementComp = Character->GetCharacterMovement())
		{
			MovementComp->SetMovementMode(MOVE_Flying); // Space movement
			UE_LOG(LogTemp, Log, TEXT("✓ Character movement restored"));
		}
	}

	// ==================== CLEAR HANGAR INSTANCE ====================
	//
	// Remove player from hangar instance and clean up resources
	//
	// ===============================================================

	HangarManager->RemoveHangarInstance(CharacterId);
	UE_LOG(LogTemp, Log, TEXT("✓ Hangar instance cleared"));

	// ==================== INITIAL IMPULSE ====================
	//
	// Give ship a small forward velocity to move away from station
	// This ensures the ship doesn't immediately re-dock
	//
	// =========================================================

	if (UPrimitiveComponent* RootPrimitive = Cast<UPrimitiveComponent>(PlayerPawn->GetRootComponent()))
	{
		// Apply forward impulse (equivalent to ~10 m/s)
		const float ImpulseStrength = 1000.0f; // Adjust based on ship mass
		FVector ForwardImpulse = StationForward * ImpulseStrength;
		
		RootPrimitive->AddImpulse(ForwardImpulse, NAME_None, true);
		UE_LOG(LogTemp, Log, TEXT("✓ Initial forward impulse applied: %s"), *ForwardImpulse.ToString());
	}

	// ==================== CLOSE STATION UI ====================
	//
	// Notify station to close the menu on client
	//
	// ==========================================================

	FoundStation->ClientRPC_CloseStationMenu();
	UE_LOG(LogTemp, Log, TEXT("✓ Station menu close requested"));

	// ==================== FINALIZE ====================

	UE_LOG(LogTemp, Log, TEXT("╔══════════════════════════════════════════════════════════╗"));
	UE_LOG(LogTemp, Log, TEXT("║    PLAYER SUCCESSFULLY UNDOCKED                         ║"));
	UE_LOG(LogTemp, Log, TEXT("╚══════════════════════════════════════════════════════════╝"));
	UE_LOG(LogTemp, Log, TEXT("Player: %s"), *PC->GetName());
	UE_LOG(LogTemp, Log, TEXT("Station: %s"), *FoundStation->GetStationName());
	UE_LOG(LogTemp, Log, TEXT("Undock Location: %s"), *UndockLocation.ToString());

	// TODO: Notify backend about undocking (update character location in database)
	// This would be similar to how we notify about docking
}
