// Copyright Epic Games, Inc. All Rights Reserved.
// Echoes - EVE-like MMO
// Server Data Manager Implementation

#include "ServerDataManager.h"
#include "JsonObjectConverter.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

AServerDataManager::AServerDataManager()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = false; // Server-only actor
}

void AServerDataManager::BeginPlay()
{
	Super::BeginPlay();
}

bool AServerDataManager::ServerOnly_ParseFittingDataFromJSON(const FString& JsonString, FCommon_ShipFittingData& OutFittingData)
{
	// Validate server authority
	if (!HasAuthority())
	{
		UE_LOG(LogTemp, Error, TEXT("ServerDataManager: ParseFittingDataFromJSON called on client!"));
		return false;
	}

	// Parse JSON
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonString);
	
	if (!FJsonSerializer::Deserialize(Reader, JsonObject) || !JsonObject.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("ServerDataManager: Failed to parse JSON"));
		return false;
	}

	// Parse High Slots
	if (JsonObject->HasField(TEXT("highSlots")))
	{
		const TArray<TSharedPtr<FJsonValue>>* HighSlotsArray;
		if (JsonObject->TryGetArrayField(TEXT("highSlots"), HighSlotsArray))
		{
			OutFittingData.HighSlots.Empty();
			for (const TSharedPtr<FJsonValue>& Value : *HighSlotsArray)
			{
				FCommon_ItemSlot Slot;
				if (ParseModuleFromJsonValue(Value, Slot))
				{
					OutFittingData.HighSlots.Add(Slot);
				}
			}
		}
	}

	// Parse Mid Slots
	if (JsonObject->HasField(TEXT("midSlots")))
	{
		const TArray<TSharedPtr<FJsonValue>>* MidSlotsArray;
		if (JsonObject->TryGetArrayField(TEXT("midSlots"), MidSlotsArray))
		{
			OutFittingData.MidSlots.Empty();
			for (const TSharedPtr<FJsonValue>& Value : *MidSlotsArray)
			{
				FCommon_ItemSlot Slot;
				if (ParseModuleFromJsonValue(Value, Slot))
				{
					OutFittingData.MidSlots.Add(Slot);
				}
			}
		}
	}

	// Parse Low Slots
	if (JsonObject->HasField(TEXT("lowSlots")))
	{
		const TArray<TSharedPtr<FJsonValue>>* LowSlotsArray;
		if (JsonObject->TryGetArrayField(TEXT("lowSlots"), LowSlotsArray))
		{
			OutFittingData.LowSlots.Empty();
			for (const TSharedPtr<FJsonValue>& Value : *LowSlotsArray)
			{
				FCommon_ItemSlot Slot;
				if (ParseModuleFromJsonValue(Value, Slot))
				{
					OutFittingData.LowSlots.Add(Slot);
				}
			}
		}
	}

	// Parse Rig Slots
	if (JsonObject->HasField(TEXT("rigSlots")))
	{
		const TArray<TSharedPtr<FJsonValue>>* RigSlotsArray;
		if (JsonObject->TryGetArrayField(TEXT("rigSlots"), RigSlotsArray))
		{
			OutFittingData.RigSlots.Empty();
			for (const TSharedPtr<FJsonValue>& Value : *RigSlotsArray)
			{
				FCommon_ItemSlot Slot;
				if (ParseModuleFromJsonValue(Value, Slot))
				{
					OutFittingData.RigSlots.Add(Slot);
				}
			}
		}
	}

	// Parse resource usage
	OutFittingData.PowergridUsed = JsonObject->GetNumberField(TEXT("powergridUsed"));
	OutFittingData.PowergridMax = JsonObject->GetNumberField(TEXT("powergridMax"));
	OutFittingData.CPUUsed = JsonObject->GetNumberField(TEXT("cpuUsed"));
	OutFittingData.CPUMax = JsonObject->GetNumberField(TEXT("cpuMax"));

	UE_LOG(LogTemp, Log, TEXT("ServerDataManager: Successfully parsed fitting data"));
	return true;
}

bool AServerDataManager::ParseModuleFromJsonValue(const TSharedPtr<FJsonValue>& JsonValue, FCommon_ItemSlot& OutSlot)
{
	if (!JsonValue.IsValid() || JsonValue->Type != EJson::Object)
	{
		return false;
	}

	TSharedPtr<FJsonObject> ModuleObj = JsonValue->AsObject();
	if (!ModuleObj.IsValid())
	{
		return false;
	}

	// Parse basic fields
	OutSlot.ItemID = ModuleObj->GetIntegerField(TEXT("itemId"));
	OutSlot.ItemName = ModuleObj->GetStringField(TEXT("itemName"));
	OutSlot.SlotIndex = ModuleObj->GetIntegerField(TEXT("slotIndex"));
	
	// Parse slot type
	FString SlotTypeStr = ModuleObj->GetStringField(TEXT("slotType"));
	if (SlotTypeStr == TEXT("High"))
		OutSlot.SlotType = ESlotType::High;
	else if (SlotTypeStr == TEXT("Mid"))
		OutSlot.SlotType = ESlotType::Mid;
	else if (SlotTypeStr == TEXT("Low"))
		OutSlot.SlotType = ESlotType::Low;
	else if (SlotTypeStr == TEXT("Rig"))
		OutSlot.SlotType = ESlotType::Rig;

	// Parse module state
	FString StateStr = ModuleObj->GetStringField(TEXT("moduleState"));
	if (StateStr == TEXT("Active"))
		OutSlot.ModuleState = EModuleState::Active;
	else if (StateStr == TEXT("Overload"))
		OutSlot.ModuleState = EModuleState::Overload;
	else if (StateStr == TEXT("Cooldown"))
		OutSlot.ModuleState = EModuleState::Cooldown;
	else if (StateStr == TEXT("Damaged"))
		OutSlot.ModuleState = EModuleState::Damaged;
	else
		OutSlot.ModuleState = EModuleState::Offline;

	// Parse resources
	OutSlot.PowergridRequired = ModuleObj->GetNumberField(TEXT("powergridRequired"));
	OutSlot.CPURequired = ModuleObj->GetNumberField(TEXT("cpuRequired"));
	OutSlot.CapacitorCost = ModuleObj->GetNumberField(TEXT("capacitorCost"));

	// Parse optional fields
	if (ModuleObj->HasField(TEXT("cooldown")))
		OutSlot.Cooldown = ModuleObj->GetNumberField(TEXT("cooldown"));
	if (ModuleObj->HasField(TEXT("quantity")))
		OutSlot.Quantity = ModuleObj->GetIntegerField(TEXT("quantity"));
	if (ModuleObj->HasField(TEXT("bIsActive")))
		OutSlot.bIsActive = ModuleObj->GetBoolField(TEXT("bIsActive"));

	return true;
}

bool AServerDataManager::ServerOnly_ParseModuleFromJSON(const FString& JsonString, FCommon_ItemSlot& OutSlot)
{
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonString);
	
	if (!FJsonSerializer::Deserialize(Reader, JsonObject) || !JsonObject.IsValid())
	{
		return false;
	}

	TSharedPtr<FJsonValue> Value = MakeShared<FJsonValueObject>(JsonObject);
	return ParseModuleFromJsonValue(Value, OutSlot);
}

bool AServerDataManager::ServerOnly_ValidateFitting(
	const FCommon_ShipFittingData& FittingData,
	float ShipBaseCPU,
	float ShipBasePowergrid,
	FString& OutErrorMessage)
{
	if (!HasAuthority())
	{
		OutErrorMessage = TEXT("Not server authority");
		return false;
	}

	// Check CPU usage
	if (FittingData.CPUUsed > ShipBaseCPU)
	{
		OutErrorMessage = FString::Printf(TEXT("CPU Overload: %.1f / %.1f"), 
			FittingData.CPUUsed, ShipBaseCPU);
		UE_LOG(LogTemp, Warning, TEXT("ServerDataManager: %s"), *OutErrorMessage);
		return false;
	}

	// Check Powergrid usage
	if (FittingData.PowergridUsed > ShipBasePowergrid)
	{
		OutErrorMessage = FString::Printf(TEXT("Powergrid Overload: %.1f / %.1f"), 
			FittingData.PowergridUsed, ShipBasePowergrid);
		UE_LOG(LogTemp, Warning, TEXT("ServerDataManager: %s"), *OutErrorMessage);
		return false;
	}

	// Validate slot types
	auto ValidateSlots = [&OutErrorMessage](const TArray<FCommon_ItemSlot>& Slots, ESlotType ExpectedType) -> bool
	{
		for (const FCommon_ItemSlot& Slot : Slots)
		{
			if (Slot.HasModule() && Slot.SlotType != ExpectedType)
			{
				OutErrorMessage = TEXT("Module in wrong slot type");
				return false;
			}
		}
		return true;
	};

	if (!ValidateSlots(FittingData.HighSlots, ESlotType::High) ||
		!ValidateSlots(FittingData.MidSlots, ESlotType::Mid) ||
		!ValidateSlots(FittingData.LowSlots, ESlotType::Low) ||
		!ValidateSlots(FittingData.RigSlots, ESlotType::Rig))
	{
		UE_LOG(LogTemp, Warning, TEXT("ServerDataManager: %s"), *OutErrorMessage);
		return false;
	}

	OutErrorMessage = TEXT("Validation successful");
	return true;
}

bool AServerDataManager::ServerOnly_ValidateModuleInstallation(
	const FCommon_ItemSlot& Module,
	ESlotType SlotType,
	const FCommon_ShipFittingData& CurrentFitting,
	float ShipBaseCPU,
	float ShipBasePowergrid,
	FString& OutErrorMessage)
{
	if (!HasAuthority())
	{
		OutErrorMessage = TEXT("Not server authority");
		return false;
	}

	// Check if module matches slot type
	if (Module.SlotType != SlotType)
	{
		OutErrorMessage = FString::Printf(TEXT("Module type mismatch: Module is %d, Slot is %d"), 
			(int32)Module.SlotType, (int32)SlotType);
		return false;
	}

	// Calculate new resource usage
	float NewCPUUsed = CurrentFitting.CPUUsed + Module.CPURequired;
	float NewPowergridUsed = CurrentFitting.PowergridUsed + Module.PowergridRequired;

	// Check CPU
	if (NewCPUUsed > ShipBaseCPU)
	{
		OutErrorMessage = FString::Printf(TEXT("Insufficient CPU: %.1f / %.1f (need %.1f more)"), 
			CurrentFitting.CPUUsed, ShipBaseCPU, NewCPUUsed - ShipBaseCPU);
		return false;
	}

	// Check Powergrid
	if (NewPowergridUsed > ShipBasePowergrid)
	{
		OutErrorMessage = FString::Printf(TEXT("Insufficient Powergrid: %.1f / %.1f (need %.1f more)"), 
			CurrentFitting.PowergridUsed, ShipBasePowergrid, NewPowergridUsed - ShipBasePowergrid);
		return false;
	}

	OutErrorMessage = TEXT("Module can be installed");
	return true;
}

void AServerDataManager::ServerOnly_CalculateFinalStats(
	float BaseShield,
	float BaseArmor,
	float BaseStructure,
	float BaseCapacitor,
	float BaseSpeed,
	const FCommon_ShipFittingData& FittingData,
	FCommon_ShipFittingData& OutFinalStats)
{
	if (!HasAuthority())
	{
		UE_LOG(LogTemp, Error, TEXT("ServerDataManager: CalculateFinalStats called on client!"));
		return;
	}

	// Copy fitting data
	OutFinalStats = FittingData;

	// Start with base stats
	float FinalShield = BaseShield;
	float FinalArmor = BaseArmor;
	float FinalStructure = BaseStructure;
	float FinalCapacitor = BaseCapacitor;
	float FinalSpeed = BaseSpeed;
	float FinalScanResolution = 100.0f; // Default
	float FinalSignatureRadius = 100.0f; // Default
	float FinalDPS = 0.0f;
	float FinalEHP = 0.0f;

	// Extract all modifiers from all slots
	TArray<FStatModifier> AllModifiers;
	
	auto ExtractFromSlots = [&AllModifiers, this](const TArray<FCommon_ItemSlot>& Slots)
	{
		for (const FCommon_ItemSlot& Slot : Slots)
		{
			if (Slot.HasModule())
			{
				ExtractModifiersFromSlot(Slot, AllModifiers);
			}
		}
	};

	ExtractFromSlots(FittingData.HighSlots);
	ExtractFromSlots(FittingData.MidSlots);
	ExtractFromSlots(FittingData.LowSlots);
	ExtractFromSlots(FittingData.RigSlots);

	// Apply all modifiers
	ApplyStatModifiers(
		AllModifiers,
		FinalShield,
		FinalArmor,
		FinalStructure,
		FinalCapacitor,
		FinalSpeed,
		FinalScanResolution,
		FinalSignatureRadius,
		FinalDPS,
		FinalEHP
	);

	// Store final calculated stats
	OutFinalStats.TotalDPS = FinalDPS;
	OutFinalStats.AlphaStrike = FinalDPS * 3.0f; // Approximate
	OutFinalStats.EffectiveHP = FinalEHP;
	OutFinalStats.MaxSpeed = FinalSpeed;
	OutFinalStats.ScanResolution = FinalScanResolution;
	OutFinalStats.SignatureRadius = FinalSignatureRadius;

	UE_LOG(LogTemp, Log, TEXT("ServerDataManager: Calculated final stats - DPS: %.1f, EHP: %.1f, Speed: %.1f"), 
		FinalDPS, FinalEHP, FinalSpeed);
}

void AServerDataManager::ApplyStatModifiers(
	const TArray<FStatModifier>& Modifiers,
	float& OutShield,
	float& OutArmor,
	float& OutStructure,
	float& OutCapacitor,
	float& OutSpeed,
	float& OutScanResolution,
	float& OutSignatureRadius,
	float& OutDPS,
	float& OutEHP)
{
	// Apply each modifier
	for (const FStatModifier& Modifier : Modifiers)
	{
		float AppliedValue = Modifier.Value;

		// Convert percentage to multiplier if needed
		if (Modifier.ApplicationType == EModifierApplication::Percentage)
		{
			AppliedValue = AppliedValue / 100.0f;
		}

		// Apply to appropriate stat
		switch (Modifier.ModifierType)
		{
		case EStatModifierType::ShieldBoost:
			if (Modifier.ApplicationType == EModifierApplication::Multiplicative || 
				Modifier.ApplicationType == EModifierApplication::Percentage)
			{
				OutShield *= (1.0f + AppliedValue);
			}
			else
			{
				OutShield += AppliedValue;
			}
			break;

		case EStatModifierType::ArmorBoost:
			if (Modifier.ApplicationType == EModifierApplication::Multiplicative || 
				Modifier.ApplicationType == EModifierApplication::Percentage)
			{
				OutArmor *= (1.0f + AppliedValue);
			}
			else
			{
				OutArmor += AppliedValue;
			}
			break;

		case EStatModifierType::StructureBoost:
			if (Modifier.ApplicationType == EModifierApplication::Multiplicative || 
				Modifier.ApplicationType == EModifierApplication::Percentage)
			{
				OutStructure *= (1.0f + AppliedValue);
			}
			else
			{
				OutStructure += AppliedValue;
			}
			break;

		case EStatModifierType::CapacitorBoost:
			if (Modifier.ApplicationType == EModifierApplication::Multiplicative || 
				Modifier.ApplicationType == EModifierApplication::Percentage)
			{
				OutCapacitor *= (1.0f + AppliedValue);
			}
			else
			{
				OutCapacitor += AppliedValue;
			}
			break;

		case EStatModifierType::SpeedBoost:
			if (Modifier.ApplicationType == EModifierApplication::Multiplicative || 
				Modifier.ApplicationType == EModifierApplication::Percentage)
			{
				OutSpeed *= (1.0f + AppliedValue);
			}
			else
			{
				OutSpeed += AppliedValue;
			}
			break;

		case EStatModifierType::DamageBoost:
		case EStatModifierType::ROFBoost:
			// Both contribute to DPS
			OutDPS += AppliedValue;
			break;

		case EStatModifierType::ScanResolutionBoost:
			if (Modifier.ApplicationType == EModifierApplication::Multiplicative || 
				Modifier.ApplicationType == EModifierApplication::Percentage)
			{
				OutScanResolution *= (1.0f + AppliedValue);
			}
			else
			{
				OutScanResolution += AppliedValue;
			}
			break;

		case EStatModifierType::SignatureRadiusReduction:
			if (Modifier.ApplicationType == EModifierApplication::Multiplicative || 
				Modifier.ApplicationType == EModifierApplication::Percentage)
			{
				OutSignatureRadius *= (1.0f - AppliedValue); // Reduction
			}
			else
			{
				OutSignatureRadius -= AppliedValue;
			}
			break;

		default:
			break;
		}
	}

	// Calculate Effective HP (simplified - assumes average resistance of 0.25)
	float AvgResistance = 0.25f;
	OutEHP = (OutShield + OutArmor + OutStructure) / (1.0f - AvgResistance);
}

float AServerDataManager::CalculateEffectiveHP(float HP, float EMResist, float ThermalResist, float KineticResist, float ExplosiveResist)
{
	// Average resistance across all damage types
	float AvgResistance = (EMResist + ThermalResist + KineticResist + ExplosiveResist) / 4.0f;
	
	// EHP formula: HP / (1 - AvgResistance)
	return HP / FMath::Max(0.01f, 1.0f - AvgResistance);
}

void AServerDataManager::ExtractModifiersFromSlot(const FCommon_ItemSlot& Slot, TArray<FStatModifier>& OutModifiers)
{
	// This would normally parse module stats from database or item definition
	// For now, we'll create example modifiers based on slot type and item ID
	
	// Example: Shield boosters add shield HP
	if (Slot.ItemName.Contains(TEXT("Shield"), ESearchCase::IgnoreCase))
	{
		OutModifiers.Add(FStatModifier(EStatModifierType::ShieldBoost, EModifierApplication::Percentage, 10.0f));
	}
	
	// Example: Armor plates add armor HP
	if (Slot.ItemName.Contains(TEXT("Armor"), ESearchCase::IgnoreCase) || 
		Slot.ItemName.Contains(TEXT("Plate"), ESearchCase::IgnoreCase))
	{
		OutModifiers.Add(FStatModifier(EStatModifierType::ArmorBoost, EModifierApplication::Percentage, 15.0f));
	}
	
	// Example: Propulsion modules increase speed
	if (Slot.ItemName.Contains(TEXT("Afterburner"), ESearchCase::IgnoreCase) || 
		Slot.ItemName.Contains(TEXT("MWD"), ESearchCase::IgnoreCase))
	{
		OutModifiers.Add(FStatModifier(EStatModifierType::SpeedBoost, EModifierApplication::Multiplicative, 0.5f));
	}
	
	// Example: Weapons add DPS
	if (Slot.SlotType == ESlotType::High && 
		(Slot.ItemName.Contains(TEXT("Blaster"), ESearchCase::IgnoreCase) || 
		 Slot.ItemName.Contains(TEXT("Laser"), ESearchCase::IgnoreCase) ||
		 Slot.ItemName.Contains(TEXT("Missile"), ESearchCase::IgnoreCase)))
	{
		OutModifiers.Add(FStatModifier(EStatModifierType::DamageBoost, EModifierApplication::Additive, 50.0f));
	}

	// In production, this would query a database or item definition system
	// to get the actual stat modifiers for each module type
}

// ============================================================================
// HTTP Request Implementation
// ============================================================================

void AServerDataManager::ServerOnly_RequestFittingFromAPI(const FString& CharacterID, const FString& APIBaseURLOverride)
{
	// Validate server authority
	if (!HasAuthority())
	{
		UE_LOG(LogTemp, Error, TEXT("ServerDataManager: RequestFittingFromAPI called on client!"));
		return;
	}

	// Validate parameters
	if (CharacterID.IsEmpty())
	{
		UE_LOG(LogTemp, Error, TEXT("ServerDataManager: Character ID is empty!"));
		return;
	}

	// Determine API base URL
	FString BaseURL = APIBaseURLOverride.IsEmpty() ? APIBaseURL : APIBaseURLOverride;
	if (BaseURL.IsEmpty())
	{
		UE_LOG(LogTemp, Error, TEXT("ServerDataManager: API Base URL is not configured!"));
		return;
	}

	// Construct full URL
	FString URL = FString::Printf(TEXT("%s/api/fitting/%s"), *BaseURL, *CharacterID);
	
	UE_LOG(LogTemp, Log, TEXT("ServerDataManager: Requesting fitting data from: %s"), *URL);

	// Create HTTP request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
	HttpRequest->SetVerb(TEXT("GET"));
	HttpRequest->SetURL(URL);
	
	// Add X-Server-Secret header for authentication
	if (!ServerSecret.IsEmpty())
	{
		HttpRequest->SetHeader(TEXT("X-Server-Secret"), ServerSecret);
		UE_LOG(LogTemp, Log, TEXT("ServerDataManager: Added X-Server-Secret header"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ServerDataManager: Server secret is not configured! Request may fail authentication."));
	}
	
	// Add content type header
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	
	// Set timeout (30 seconds)
	HttpRequest->SetTimeout(30.0f);
	
	// Bind callback
	HttpRequest->OnProcessRequestComplete().BindUObject(
		this,
		&AServerDataManager::OnFittingDataReceived,
		CharacterID
	);
	
	// Send request
	if (HttpRequest->ProcessRequest())
	{
		UE_LOG(LogTemp, Log, TEXT("ServerDataManager: HTTP request sent for character %s"), *CharacterID);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("ServerDataManager: Failed to send HTTP request for character %s"), *CharacterID);
	}
}

void AServerDataManager::OnFittingDataReceived(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful,
	FString CharacterID)
{
	// Validate server authority
	if (!HasAuthority())
	{
		UE_LOG(LogTemp, Error, TEXT("ServerDataManager: OnFittingDataReceived called on client!"));
		return;
	}

	// Check if request was successful
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("ServerDataManager: HTTP request failed for character %s"), *CharacterID);
		UE_LOG(LogTemp, Error, TEXT("ServerDataManager: Request was not successful or response is invalid"));
		
		// TODO: Handle failure - kick player or return to hangar
		// For now, just log the error
		return;
	}

	// Check HTTP status code
	int32 ResponseCode = Response->GetResponseCode();
	FString ResponseContent = Response->GetContentAsString();
	
	UE_LOG(LogTemp, Log, TEXT("ServerDataManager: Received response code %d for character %s"), ResponseCode, *CharacterID);
	
	// Handle different response codes
	if (ResponseCode == 200)
	{
		// Success - parse the fitting data
		UE_LOG(LogTemp, Log, TEXT("ServerDataManager: Successfully received fitting data for character %s"), *CharacterID);
		UE_LOG(LogTemp, Verbose, TEXT("ServerDataManager: Response content: %s"), *ResponseContent);
		
		// Parse JSON response
		FCommon_ShipFittingData FittingData;
		if (ServerOnly_ParseFittingDataFromJSON(ResponseContent, FittingData))
		{
			UE_LOG(LogTemp, Log, TEXT("ServerDataManager: Successfully parsed fitting data for character %s"), *CharacterID);
			UE_LOG(LogTemp, Log, TEXT("ServerDataManager: High slots: %d, Mid slots: %d, Low slots: %d, Rig slots: %d"),
				FittingData.HighSlots.Num(),
				FittingData.MidSlots.Num(),
				FittingData.LowSlots.Num(),
				FittingData.RigSlots.Num());
			
			// Validate fitting data
			if (!FittingData.IsValid())
			{
				UE_LOG(LogTemp, Error, TEXT("ServerDataManager: Fitting data validation failed for character %s (PG: %.2f/%.2f, CPU: %.2f/%.2f)"),
					*CharacterID,
					FittingData.PowergridUsed,
					FittingData.PowergridMax,
					FittingData.CPUUsed,
					FittingData.CPUMax);
				
				// Data is corrupted or invalid - kick player back to hangar
				UE_LOG(LogTemp, Error, TEXT("ServerDataManager: Invalid fitting detected. Player should be returned to hangar for safety."));
				
				// TODO: Implement player kickback to hangar
				// This would involve calling a game mode function or player controller RPC
				// For example: GameMode->ReturnPlayerToHangar(CharacterID);
				return;
			}
			
			// Fitting data is valid - synchronize to client
			UE_LOG(LogTemp, Log, TEXT("ServerDataManager: Fitting data is valid. Ready for client synchronization."));
			
			// TODO: Call ClientRPC_SyncFitting to send data to the player's client
			// This requires access to the player's controller or pawn
			// For example: PlayerController->ClientRPC_SyncFitting(FittingData);
			
			// Note: The actual synchronization would be done by the EquipmentManagerComponent
			// which should have a reference to this ServerDataManager
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("ServerDataManager: Failed to parse fitting JSON for character %s"), *CharacterID);
			UE_LOG(LogTemp, Error, TEXT("ServerDataManager: JSON content: %s"), *ResponseContent);
			
			// Parsing failed - data might be corrupted
			UE_LOG(LogTemp, Error, TEXT("ServerDataManager: Corrupted fitting data detected. Player should be returned to hangar for safety."));
			
			// TODO: Implement player kickback to hangar
			return;
		}
	}
	else if (ResponseCode == 404)
	{
		UE_LOG(LogTemp, Warning, TEXT("ServerDataManager: Character %s not found or has no active ship"), *CharacterID);
		
		// Character not found or has no ship - return to hangar
		UE_LOG(LogTemp, Warning, TEXT("ServerDataManager: Player should be returned to hangar (no ship found)."));
		
		// TODO: Implement player kickback to hangar
	}
	else if (ResponseCode == 401)
	{
		UE_LOG(LogTemp, Error, TEXT("ServerDataManager: Authentication failed (401 Unauthorized) for character %s"), *CharacterID);
		UE_LOG(LogTemp, Error, TEXT("ServerDataManager: Check X-Server-Secret configuration!"));
		
		// Authentication failed - this is a configuration error
		// Should not happen in production
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("ServerDataManager: Unexpected response code %d for character %s"), ResponseCode, *CharacterID);
		UE_LOG(LogTemp, Error, TEXT("ServerDataManager: Response: %s"), *ResponseContent);
		
		// Unexpected error - return to hangar for safety
		UE_LOG(LogTemp, Error, TEXT("ServerDataManager: Unexpected error. Player should be returned to hangar for safety."));
		
		// TODO: Implement player kickback to hangar
	}
}

FString AServerDataManager::GetAPIBaseURL() const
{
	return APIBaseURL;
}

FString AServerDataManager::GetServerSecret() const
{
	return ServerSecret;
}
