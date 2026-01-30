// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesServerGameMode.h"
#include "Core/Server/EchoesServerManagementSubsystem.h"
#include "Core/Common/EchoesWorldGenerator.h"
#include "Core/Server/EchoesServerDiscoveryTypes.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

AEchoesServerGameMode::AEchoesServerGameMode()
{
	bWorldGenerated = false;
	bWaitingForConfig = false;
	bSubscribedToConfigDelegate = false;
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
		UE_LOG(LogTemp, Log, TEXT("✓ World is generated, player can spawn safely"));
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
