// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Core/Common/EchoesInteractableInterface.h"
#include "EchoesItemDefinitions.h"
#include "EchoesItemActor.generated.h"

// Forward declarations
class UStaticMeshComponent;
class USphereComponent;
class UEchoesInventoryComponent;
class UStaticMesh;

/**
 * AEchoesItemActor
 * 
 * Universal actor for representing items and containers in space
 * Can represent:
 * - Ejected loot containers
 * - Jettisoned cargo
 * - Wrecks with loot
 * - Deployable containers
 * 
 * Features:
 * - Dynamic mesh loading based on item definition
 * - Physics simulation for drifting in space
 * - Inventory storage via UEchoesInventoryComponent
 * - Interaction system for looting
 * - Replication for multiplayer
 * - Auto-despawn after configurable lifetime
 * 
 * Architecture:
 * - Server spawns and initializes
 * - Mesh loads asynchronously
 * - Physics enabled for realistic drift
 * - Players can interact within range
 * - Inventory synced via component
 * - Auto-cleanup after lifetime expires
 */
UCLASS()
class ECHOES_API AEchoesItemActor : public AActor, public IEchoesInteractableInterface
{
	GENERATED_BODY()
	
public:	
	AEchoesItemActor();

	// AActor interface
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	// End of AActor interface

	// ==================== Initialization ====================

	/**
	 * SERVER ONLY: Initialize the item actor with item definition
	 * Loads mesh asynchronously and configures components
	 * 
	 * @param ItemId - Item type ID from database (as string)
	 * @param InstanceId - Unique instance ID for this spawned item
	 * @param Quantity - Quantity of items in this container
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Item", meta = (DisplayName = "ServerOnly InitializeItem"))
	void ServerOnly_InitializeItem(const FString& ItemId, const FGuid& InstanceId, int64 Quantity = 1);

	/**
	 * Set the item lifetime before auto-despawn
	 * 
	 * @param LifetimeSeconds - Time in seconds (default: 7200 = 2 hours)
	 */
	UFUNCTION(BlueprintCallable, Category = "Echoes|Item")
	void SetLifetime(float LifetimeSeconds);

	// ==================== IEchoesInteractableInterface ====================

	virtual bool CanInteract_Implementation(APawn* Interactor) const override;
	virtual float GetInteractionDistance_Implementation() const override;
	virtual FText GetInteractionPrompt_Implementation() const override;
	virtual FEchoesInteractionResult OnInteract_Implementation(APawn* Interactor) override;

	// ==================== Getters ====================

	/**
	 * Get the item type ID
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Item")
	FString GetItemId() const { return ItemId; }

	/**
	 * Get the instance ID
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Item")
	FGuid GetInstanceId() const { return InstanceId; }

	/**
	 * Get the item definition data for Blueprints
	 * @return Definition data if cached, otherwise default-constructed
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Item")
	FEchoesItemDefinitionRow GetItemDefinitionData() const;

	/**
	 * Get the inventory component
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Item")
	UEchoesInventoryComponent* GetInventoryComponent() const { return InventoryComponent; }

	/**
	 * Check if this is a container (has inventory)
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Item")
	bool IsContainer() const;

	/**
	 * Get remaining lifetime in seconds
	 */
	UFUNCTION(BlueprintPure, Category = "Echoes|Item")
	float GetRemainingLifetime() const;

protected:
	/**
	 * Handle mesh loaded callback
	 */
	UFUNCTION()
	void OnMeshLoaded(UStaticMesh* LoadedMesh);

	/**
	 * Setup physics simulation
	 * Called after mesh is loaded
	 */
	void SetupPhysicsSimulation();

	/**
	 * Handle lifetime expiration
	 * Destroys the actor when lifetime expires
	 */
	UFUNCTION()
	void OnLifetimeExpired();

	/**
	 * Blueprint event called when item is initialized
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "Echoes|Item")
	void OnItemInitialized();

	/**
	 * Blueprint event called when player interacts
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "Echoes|Item")
	void OnPlayerInteracted(APawn* Interactor);

	// ==================== Components ====================

	/** Visual mesh component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* MeshComponent;

	/** Interaction collision sphere */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USphereComponent* InteractionSphere;

	/** Inventory storage component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UEchoesInventoryComponent* InventoryComponent;

	// ==================== Replicated Properties ====================

	/** Item type ID from database (replicated) */
	UPROPERTY(ReplicatedUsing = OnRep_ItemId, BlueprintReadOnly, Category = "Item")
	FString ItemId;

	/** Instance ID for this spawned item (replicated) */
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Item")
	FGuid InstanceId;

	/** Quantity of items (for stacks) */
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Item")
	int64 Quantity = 1;

	// ==================== Configuration ====================

	/** Maximum interaction distance (in cm) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	float InteractionDistance = 25000.0f; // 250 meters

	/** Lifetime before auto-despawn (in seconds, 0 = never despawn) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Lifetime")
	float Lifetime = 7200.0f; // 2 hours default

	/** Whether to enable physics simulation */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Physics")
	bool bEnablePhysics = true;

	/** Whether to apply initial random velocity */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Physics")
	bool bApplyRandomVelocity = true;

	/** Maximum random velocity magnitude (cm/s) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Physics")
	float MaxRandomVelocity = 100.0f;

	/** Whether this item is a container with inventory */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	bool bIsContainer = true;

private:
	/** Cached item definition from subsystem */
	TOptional<FEchoesItemDefinitionRow> CachedDefinition;

	/** Timer handle for lifetime despawn */
	FTimerHandle LifetimeTimerHandle;

	/** Whether the mesh has been loaded */
	bool bMeshLoaded = false;

	/** Replication notification */
	UFUNCTION()
	void OnRep_ItemId();

	/**
	 * Load item definition and mesh
	 */
	void LoadItemDefinition();

	/**
	 * Apply random initial velocity for physics
	 */
	void ApplyRandomVelocity();
};
