// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesServerGameMode.h"
#include "Core/Server/EchoesServerManagementSubsystem.h"
#include "Core/Common/EchoesWorldGenerator.h"
#include "Core/Common/EchoesJumpManager.h"
#include "Core/Server/EchoesServerDiscoveryTypes.h"
#include "Core/Common/Networking/EchoesInventorySubsystem.h"
#include "Core/Common/Networking/EchoesAuthSubsystem.h"
#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Misc/ConfigCacheIni.h"
#include "GameFramework/PlayerState.h"

AEchoesServerGameMode::AEchoesServerGameMode()
{
	bWorldGenerated = false;
	bWaitingForConfig = false;
	bSubscribedToConfigDelegate = false;

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

	UE_LOG(LogTemp, Log, TEXT("GameMode initialization complete. WorldGenerated: %s"),
		bWorldGenerated ? TEXT("true") : TEXT("false"));
}

void AEchoesServerGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	if (!HasAuthority())
	{
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Player logged in: %s"), NewPlayer ? *NewPlayer->GetName() : TEXT("Unknown"));

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
		UE_LOG(LogTemp, Log, TEXT("✓ World is generated, spawning player..."));
		
		// Extract login options from URL
		FString Options = NewPlayer->PlayerState ? NewPlayer->PlayerState->SavedNetworkAddress : TEXT("");
		FString Token;
		FGuid CharacterId;

		if (ExtractLoginOptions(Options, Token, CharacterId))
		{
			UE_LOG(LogTemp, Log, TEXT("Extracted CharacterId: %s"), *CharacterId.ToString());
			
			// Spawn player at their saved location
			SpawnPlayerAtLocation(NewPlayer);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to extract login options, using default spawn"));
			SpawnPlayerAtLocation(NewPlayer);
		}
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
		SpawnPlayerAtStation(PlayerController, LocationData.StationId, LocationData.ActiveShipTypeId);
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

void AEchoesServerGameMode::SpawnPlayerAtStation(APlayerController* PC, const FGuid& StationId, int32 ShipTypeId)
{
	if (!PC)
	{
		UE_LOG(LogTemp, Error, TEXT("✗ SpawnPlayerAtStation: PlayerController is null"));
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Spawning player at station: %s (ShipTypeId: %d)"), *StationId.ToString(), ShipTypeId);

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

	// TODO: Find StationActor by ID
	// TODO: Call Station->DockPlayer(PC)
	// TODO: Open station menu widget

	// For now, spawn pawn in docked state
	RestartPlayer(PC);

	if (PC->GetPawn())
	{
		UE_LOG(LogTemp, Log, TEXT("✓ Player spawned in docked state"));
		
		// TODO: Apply ship mesh from ShipDef->WorldMesh if available
		// TODO: Sync inventory: InventorySubsystem->Inventory_FetchShips()
		
		OnEntryFlowComplete.Broadcast();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("✗ Failed to spawn player pawn at station"));
	}
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
