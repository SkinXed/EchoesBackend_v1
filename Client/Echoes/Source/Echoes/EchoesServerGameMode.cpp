// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesServerGameMode.h"
#include "Core/Server/EchoesServerManagementSubsystem.h"
#include "Core/Common/EchoesWorldGenerator.h"
#include "Core/Common/EchoesJumpManager.h"
#include "Core/Server/EchoesServerDiscoveryTypes.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

AEchoesServerGameMode::AEchoesServerGameMode()
{
	bWorldGenerated = false;
	bWaitingForConfig = false;
	bSubscribedToConfigDelegate = false;

	// Create jump manager component
	JumpManager = CreateDefaultSubobject<UEchoesJumpManager>(TEXT("JumpManager"));
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
	}

	// TODO: Query backend for character location
	// GET /api/character/{id}/location
	// Response: { isDocked: bool, stationId?: guid, positionX/Y/Z: double }

	// For now, spawn at default location
	FVector SpawnLocation = FVector(0.0f, 0.0f, 1000.0f);
	FRotator SpawnRotation = FRotator::ZeroRotator;
	
	// Spawn default pawn
	RestartPlayer(PlayerController);
	
	if (PlayerController->GetPawn())
	{
		PlayerController->GetPawn()->SetActorLocation(SpawnLocation);
		UE_LOG(LogTemp, Log, TEXT("✓ Player spawned at default location"));
		
		// TODO: Sync inventory component
		// TODO: If docked, open station menu
		
		// Signal entry flow complete
		OnEntryFlowComplete.Broadcast();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("✗ Failed to spawn player pawn"));
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

void AEchoesServerGameMode::SpawnPlayerAtStation(APlayerController* PC, const FGuid& StationId)
{
	if (!PC)
	{
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Spawning player at station: %s"), *StationId.ToString());

	// TODO: Find StationActor by ID
	// TODO: Call Station->DockPlayer(PC)
	// TODO: Open station menu widget

	// For now, just spawn pawn
	RestartPlayer(PC);

	if (PC->GetPawn())
	{
		UE_LOG(LogTemp, Log, TEXT("✓ Player spawned in docked state"));
		OnEntryFlowComplete.Broadcast();
	}
}

void AEchoesServerGameMode::SpawnPlayerInSpace(APlayerController* PC, const FVector& Position, const FRotator& Rotation)
{
	if (!PC)
	{
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Spawning player in space at: %s"), *Position.ToString());

	// TODO: Spawn player's ship
	// TODO: Set velocity and orientation
	// TODO: Sync inventory

	// For now, just spawn pawn at position
	RestartPlayer(PC);

	if (PC->GetPawn())
	{
		PC->GetPawn()->SetActorLocation(Position);
		PC->GetPawn()->SetActorRotation(Rotation);
		
		UE_LOG(LogTemp, Log, TEXT("✓ Player spawned in space"));
		OnEntryFlowComplete.Broadcast();
	}
}
