// Copyright Epic Games, Inc. All Rights Reserved.

#include "CombatServerSubsystem.h"
#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "Misc/ConfigCacheIni.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "EchoesWreck.h"

// Define custom log category
DEFINE_LOG_CATEGORY(LogEchoesCombat);

void UCombatServerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	LoadConfig();

	if (BackendURL.IsEmpty())
	{
		BackendURL = TEXT("http://localhost:5116");
		UE_LOG(LogEchoesCombat, Warning, TEXT("BackendURL not configured, using default: %s"), *BackendURL);
	}
	
	if (BackendURL.EndsWith(TEXT("/")))
	{
		BackendURL.LeftChopInline(1);
	}
	if (!BackendURL.StartsWith(TEXT("http://")) && !BackendURL.StartsWith(TEXT("https://")))
	{
		BackendURL = TEXT("http://") + BackendURL;
	}

	Http = &FHttpModule::Get();

	UE_LOG(LogEchoesCombat, Log, TEXT("CombatServerSubsystem initialized. API: %s"), *GetApiBaseUrl());

	if (!IsDedicatedServer())
	{
		UE_LOG(LogEchoesCombat, Warning, TEXT("Not a dedicated server, combat reporting disabled"));
		return;
	}

	UE_LOG(LogEchoesCombat, Log, TEXT("Combat reporting enabled for dedicated server"));
}

void UCombatServerSubsystem::Deinitialize()
{
	Super::Deinitialize();
	DamageMaps.Empty();
	UE_LOG(LogEchoesCombat, Log, TEXT("CombatServerSubsystem deinitialized"));
}

// ==================== Damage Tracking ====================

void UCombatServerSubsystem::ServerOnly_RegisterDamage(
	const FGuid& VictimId,
	const FGuid& AttackerId,
	const FString& AttackerName,
	const FGuid& AttackerCorporationId,
	int32 AttackerShipTypeId,
	const FString& AttackerShipTypeName,
	const FString& WeaponName,
	double DamageAmount)
{
	if (!IsDedicatedServer()) return;

	TMap<FGuid, FDamageMapEntry>& VictimDamageMap = DamageMaps.FindOrAdd(VictimId);

	FDamageMapEntry& Entry = VictimDamageMap.FindOrAdd(AttackerId);
	Entry.AttackerId = AttackerId;
	Entry.AttackerName = AttackerName;
	Entry.AttackerCorporationId = AttackerCorporationId;
	Entry.AttackerShipTypeId = AttackerShipTypeId;
	Entry.AttackerShipTypeName = AttackerShipTypeName;
	Entry.LastWeaponUsed = WeaponName;
	Entry.TotalDamage += DamageAmount;

	UE_LOG(LogEchoesCombat, Verbose, TEXT("[DAMAGE] %s -> %s: %.1f dmg (total: %.1f)"),
		*AttackerName, *VictimId.ToString(), DamageAmount, Entry.TotalDamage);
}

void UCombatServerSubsystem::ServerOnly_ClearDamageMap(const FGuid& VictimId)
{
	DamageMaps.Remove(VictimId);
	UE_LOG(LogEchoesCombat, Log, TEXT("[DAMAGE] Cleared damage map for %s"), *VictimId.ToString());
}

// ==================== Ship Destruction ====================

void UCombatServerSubsystem::ServerOnly_HandleDestruction(
	const FGuid& VictimId,
	const FString& VictimName,
	const FGuid& FinalStrikerId,
	const FGuid& SolarSystemId,
	const FString& SolarSystemName,
	int32 ShipTypeId,
	const FString& ShipTypeName,
	const TArray<FKillmailItem>& FittedModules,
	const TArray<FKillmailItem>& CargoItems,
	const FVector& DestructionLocation)
{
	if (!IsDedicatedServer())
	{
		UE_LOG(LogEchoesCombat, Warning, TEXT("ServerOnly_HandleDestruction called on non-dedicated server"));
		return;
	}

	UE_LOG(LogEchoesCombat, Log,
		TEXT("[DESTRUCTION] %s (%s) destroyed in %s by %s. Modules=%d, CargoItems=%d"),
		*VictimName, *ShipTypeName, *SolarSystemName,
		*FinalStrikerId.ToString(), FittedModules.Num(), CargoItems.Num());

	// 1. Build attacker list from damage map
	TArray<FKillmailAttacker> Attackers;
	TArray<FWreckAccessEntry> AccessList;

	TMap<FGuid, FDamageMapEntry>* VictimDamageMap = DamageMaps.Find(VictimId);
	if (VictimDamageMap)
	{
		for (auto& Pair : *VictimDamageMap)
		{
			const FDamageMapEntry& DmgEntry = Pair.Value;

			FKillmailAttacker Attacker;
			Attacker.CharacterId = DmgEntry.AttackerId;
			Attacker.CharacterName = DmgEntry.AttackerName;
			Attacker.CorporationId = DmgEntry.AttackerCorporationId;
			Attacker.ShipTypeId = DmgEntry.AttackerShipTypeId;
			Attacker.ShipTypeName = DmgEntry.AttackerShipTypeName;
			Attacker.WeaponTypeName = DmgEntry.LastWeaponUsed;
			Attacker.DamageDealt = DmgEntry.TotalDamage;
			Attacker.IsFinalBlow = (DmgEntry.AttackerId == FinalStrikerId);
			Attackers.Add(Attacker);

			// Add loot rights for this attacker and their corp
			FWreckAccessEntry Access;
			Access.CharacterId = DmgEntry.AttackerId;
			Access.CorporationId = DmgEntry.AttackerCorporationId;
			AccessList.Add(Access);
		}
	}
	else
	{
		// No damage map — add only the final striker
		FKillmailAttacker Attacker;
		Attacker.CharacterId = FinalStrikerId;
		Attacker.IsFinalBlow = true;
		Attackers.Add(Attacker);

		FWreckAccessEntry Access;
		Access.CharacterId = FinalStrikerId;
		AccessList.Add(Access);
	}

	// 2. Combine all items and calculate 50/50 drops
	TArray<FKillmailItem> AllItems;
	AllItems.Append(FittedModules);
	AllItems.Append(CargoItems);

	TArray<FKillmailItem> DroppedItems;
	TArray<FKillmailItem> DestroyedItems;
	CalculateItemDrops(AllItems, DroppedItems, DestroyedItems);

	// 3. Calculate total loss value
	double TotalLoss = 0.0;
	for (const FKillmailItem& Item : AllItems)
	{
		TotalLoss += Item.EstimatedValue * Item.Quantity;
	}

	UE_LOG(LogEchoesCombat, Log,
		TEXT("[DESTRUCTION] Drop results: %d dropped, %d destroyed, Total loss: %.2f ISK"),
		DroppedItems.Num(), DestroyedItems.Num(), TotalLoss);

	// 4. Spawn wreck with dropped items
	if (DroppedItems.Num() > 0)
	{
		UWorld* World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

			AEchoesWreck* Wreck = World->SpawnActor<AEchoesWreck>(
				AEchoesWreck::StaticClass(),
				DestructionLocation,
				FRotator::ZeroRotator,
				SpawnParams);

			if (Wreck)
			{
				FGuid WreckKillmailId = FGuid::NewGuid();
				Wreck->ServerOnly_InitializeWreck(DroppedItems, AccessList, WreckKillmailId);

				UE_LOG(LogEchoesCombat, Log,
					TEXT("[WRECK SPAWNED] At %s with %d items, %d access entries"),
					*DestructionLocation.ToString(), DroppedItems.Num(), AccessList.Num());
			}
		}
	}

	// 5. Build killmail data for reporting
	FKillmailData KillmailData;
	KillmailData.VictimId = VictimId;
	KillmailData.VictimName = VictimName;
	KillmailData.FinalStrikerId = FinalStrikerId;
	KillmailData.SolarSystemId = SolarSystemId;
	KillmailData.SolarSystemName = SolarSystemName;
	KillmailData.ShipTypeId = ShipTypeId;
	KillmailData.ShipTypeName = ShipTypeName;
	KillmailData.TotalLossValue = TotalLoss;
	KillmailData.Attackers = Attackers;
	KillmailData.DroppedItems = DroppedItems;
	KillmailData.DestroyedItems = DestroyedItems;
	KillmailData.KilledAt = FDateTime::UtcNow();

	// 6. Send to backend API (PascalCase JSON for ASP.NET)
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	JsonObject->SetStringField(TEXT("VictimId"), VictimId.ToString());
	JsonObject->SetStringField(TEXT("FinalStrikerId"), FinalStrikerId.ToString());
	JsonObject->SetStringField(TEXT("SolarSystemId"), SolarSystemId.ToString());
	JsonObject->SetNumberField(TEXT("ShipTypeId"), ShipTypeId);
	JsonObject->SetStringField(TEXT("ShipTypeName"), ShipTypeName);
	JsonObject->SetNumberField(TEXT("TotalLossValue"), TotalLoss);

	// Serialize attackers
	TArray<TSharedPtr<FJsonValue>> AttackersJson;
	for (const FKillmailAttacker& Att : Attackers)
	{
		TSharedPtr<FJsonObject> AttObj = MakeShareable(new FJsonObject);
		AttObj->SetStringField(TEXT("CharacterId"), Att.CharacterId.ToString());
		AttObj->SetStringField(TEXT("CharacterName"), Att.CharacterName);
		AttObj->SetStringField(TEXT("CorporationId"), Att.CorporationId.ToString());
		AttObj->SetNumberField(TEXT("ShipTypeId"), Att.ShipTypeId);
		AttObj->SetStringField(TEXT("ShipTypeName"), Att.ShipTypeName);
		AttObj->SetStringField(TEXT("WeaponTypeName"), Att.WeaponTypeName);
		AttObj->SetNumberField(TEXT("DamageDealt"), Att.DamageDealt);
		AttObj->SetBoolField(TEXT("IsFinalBlow"), Att.IsFinalBlow);
		AttackersJson.Add(MakeShareable(new FJsonValueObject(AttObj)));
	}
	JsonObject->SetArrayField(TEXT("Attackers"), AttackersJson);

	// Serialize dropped items
	auto SerializeItems = [](const TArray<FKillmailItem>& Items) -> TArray<TSharedPtr<FJsonValue>>
	{
		TArray<TSharedPtr<FJsonValue>> Result;
		for (const FKillmailItem& Item : Items)
		{
			TSharedPtr<FJsonObject> ItemObj = MakeShareable(new FJsonObject);
			ItemObj->SetNumberField(TEXT("ItemTypeId"), Item.ItemTypeId);
			ItemObj->SetStringField(TEXT("ItemName"), Item.ItemName);
			ItemObj->SetNumberField(TEXT("Quantity"), Item.Quantity);
			ItemObj->SetNumberField(TEXT("EstimatedValue"), Item.EstimatedValue);
			ItemObj->SetStringField(TEXT("Location"), Item.Location);
			Result.Add(MakeShareable(new FJsonValueObject(ItemObj)));
		}
		return Result;
	};

	JsonObject->SetArrayField(TEXT("DroppedItems"), SerializeItems(DroppedItems));
	JsonObject->SetArrayField(TEXT("DestroyedItems"), SerializeItems(DestroyedItems));

	FString JsonPayload;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonPayload);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

	FString Endpoint = GetKillmailEndpoint();
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = CreateAuthenticatedRequest(TEXT("POST"), Endpoint);
	Request->SetContentAsString(JsonPayload);
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));

	Request->OnProcessRequestComplete().BindUObject(
		this,
		&UCombatServerSubsystem::OnKillmailResponseReceived,
		KillmailData);

	if (!Request->ProcessRequest())
	{
		UE_LOG(LogEchoesCombat, Error, TEXT("[KILLMAIL FAIL] Failed to send killmail request"));
		OnKillmailReportFailed.Broadcast(TEXT("Failed to send killmail request"));
	}
	else
	{
		UE_LOG(LogEchoesCombat, Log, TEXT("[KILLMAIL SENT] Killmail report sent to %s"), *Endpoint);
	}

	// 7. Clean up damage map for this victim
	ServerOnly_ClearDamageMap(VictimId);
}

// ==================== Drop Calculation ====================

void UCombatServerSubsystem::CalculateItemDrops(
	const TArray<FKillmailItem>& AllItems,
	TArray<FKillmailItem>& OutDroppedItems,
	TArray<FKillmailItem>& OutDestroyedItems)
{
	for (const FKillmailItem& Item : AllItems)
	{
		// 50/50 chance: FMath::RandBool() returns true/false with equal probability
		if (FMath::RandBool())
		{
			OutDroppedItems.Add(Item);
			UE_LOG(LogEchoesCombat, Verbose, TEXT("[DROP] SURVIVED: %d x %s (%s)"),
				Item.Quantity, *Item.ItemName, *Item.Location);
		}
		else
		{
			OutDestroyedItems.Add(Item);
			UE_LOG(LogEchoesCombat, Verbose, TEXT("[DROP] DESTROYED: %d x %s (%s)"),
				Item.Quantity, *Item.ItemName, *Item.Location);
		}
	}
}

// ==================== Legacy Kill Reporting ====================

void UCombatServerSubsystem::ServerOnly_ReportKill(
	int32 VictimID,
	int32 KillerID,
	int32 SolarSystemID,
	const FString& ShipType)
{
	if (!IsDedicatedServer())
	{
		UE_LOG(LogEchoesCombat, Warning, TEXT("ServerOnly_ReportKill called on non-dedicated server"));
		return;
	}

	UE_LOG(LogEchoesCombat, Log, 
		TEXT("Reporting kill (legacy): Victim=%d, Killer=%d, System=%d, Ship=%s"),
		VictimID, KillerID, SolarSystemID, *ShipType);

	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
	JsonObject->SetStringField(TEXT("VictimId"), FGuid::NewGuid().ToString());
	JsonObject->SetStringField(TEXT("FinalStrikerId"), FGuid::NewGuid().ToString());
	JsonObject->SetStringField(TEXT("SolarSystemId"), FGuid::NewGuid().ToString());
	JsonObject->SetNumberField(TEXT("ShipTypeId"), 0);
	JsonObject->SetStringField(TEXT("ShipTypeName"), ShipType);
	JsonObject->SetNumberField(TEXT("TotalLossValue"), 0);
	JsonObject->SetArrayField(TEXT("Attackers"), TArray<TSharedPtr<FJsonValue>>());
	JsonObject->SetArrayField(TEXT("DroppedItems"), TArray<TSharedPtr<FJsonValue>>());
	JsonObject->SetArrayField(TEXT("DestroyedItems"), TArray<TSharedPtr<FJsonValue>>());

	FString JsonPayload;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&JsonPayload);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

	FString Endpoint = GetKillmailEndpoint();
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = CreateAuthenticatedRequest(TEXT("POST"), Endpoint);
	Request->SetContentAsString(JsonPayload);
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));

	FKillmailData EmptyData;
	Request->OnProcessRequestComplete().BindUObject(
		this,
		&UCombatServerSubsystem::OnKillmailResponseReceived,
		EmptyData);

	if (!Request->ProcessRequest())
	{
		UE_LOG(LogEchoesCombat, Error, TEXT("Failed to send killmail request"));
	}
	else
	{
		UE_LOG(LogEchoesCombat, Log, TEXT("Killmail request sent to: %s"), *Endpoint);
	}
}

// ==================== HTTP Response Handlers ====================

void UCombatServerSubsystem::OnKillmailResponseReceived(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful,
	FKillmailData KillmailData)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogEchoesCombat, Error, TEXT("[KILLMAIL FAIL] Request failed (network error)"));
		OnKillmailReportFailed.Broadcast(TEXT("Network error"));
		return;
	}

	int32 ResponseCode = Response->GetResponseCode();
	FString ResponseBody = Response->GetContentAsString();

	UE_LOG(LogEchoesCombat, Log, TEXT("[KILLMAIL RESPONSE] Code=%d"), ResponseCode);

	if (ResponseCode == 200)
	{
		TSharedPtr<FJsonObject> JsonObject;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseBody);
		
		if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
		{
			FGuid::Parse(JsonObject->GetStringField(TEXT("KillmailId")), KillmailData.KillmailId);
			
			UE_LOG(LogEchoesCombat, Log, 
				TEXT("[KILLMAIL SUCCESS] Id=%s, Victim=%s, Loss=%.2f ISK"),
				*KillmailData.KillmailId.ToString(),
				*KillmailData.VictimName,
				KillmailData.TotalLossValue);

			OnKillmailReported.Broadcast(KillmailData);
		}
	}
	else if (ResponseCode == 401)
	{
		UE_LOG(LogEchoesCombat, Error, TEXT("[KILLMAIL FAIL] Unauthorized - check X-Server-Secret"));
		OnKillmailReportFailed.Broadcast(TEXT("Unauthorized"));
	}
	else
	{
		UE_LOG(LogEchoesCombat, Error, TEXT("[KILLMAIL FAIL] Code=%d: %s"), ResponseCode, *ResponseBody);
		OnKillmailReportFailed.Broadcast(FString::Printf(TEXT("Server error: %d"), ResponseCode));
	}
}

// ==================== Helper Functions ====================

FString UCombatServerSubsystem::GetApiBaseUrl() const
{
	return BackendURL;
}

FString UCombatServerSubsystem::GetServerSecret() const
{
	if (ServerSecret.IsEmpty())
	{
		UE_LOG(LogEchoesCombat, Error, TEXT("ServerSecret not configured - authentication will fail"));
		return TEXT("");
	}
	return ServerSecret;
}

FString UCombatServerSubsystem::GetKillmailEndpoint() const
{
	if (!KillmailEndpoint.IsEmpty())
	{
		return GetApiBaseUrl() + KillmailEndpoint;
	}
	return GetApiBaseUrl() + TEXT("/api/combat/killmail");
}

bool UCombatServerSubsystem::IsDedicatedServer() const
{
	UWorld* World = GetWorld();
	if (!World)
	{
		return false;
	}
	return World->GetNetMode() == NM_DedicatedServer;
}

TSharedRef<IHttpRequest, ESPMode::ThreadSafe> UCombatServerSubsystem::CreateAuthenticatedRequest(
	const FString& Verb,
	const FString& Endpoint)
{
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Http->CreateRequest();
	Request->SetVerb(Verb);
	Request->SetURL(Endpoint);
	Request->SetHeader(TEXT("X-Server-Secret"), GetServerSecret());
	return Request;
}
