// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesInventorySubsystem.h"
#include "EchoesAuthSubsystem.h"
#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "JsonObjectConverter.h"
#include "Misc/ConfigCacheIni.h"

void UEchoesInventorySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	Http = &FHttpModule::Get();

	// Build item definition cache if table is set
	if (ItemDefinitionsTable)
	{
		BuildDefinitionCache();
		UE_LOG(LogTemp, Log, TEXT("EchoesInventorySubsystem: Loaded %d item definitions"), DefinitionCache.Num());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesInventorySubsystem: No ItemDefinitionsTable set"));
	}

	UE_LOG(LogTemp, Log, TEXT("EchoesInventorySubsystem initialized"));
}

void UEchoesInventorySubsystem::Deinitialize()
{
	Inventory_ClearCache();

	Super::Deinitialize();

	UE_LOG(LogTemp, Log, TEXT("EchoesInventorySubsystem deinitialized"));
}

void UEchoesInventorySubsystem::Inventory_FetchShips(
	FOnShipsReceived OnSuccess,
	FOnInventoryFailure OnFailure)
{
	// Get JWT token from Auth subsystem
	FString Token = GetAuthToken();
	if (Token.IsEmpty())
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot fetch ships: No valid JWT token"));
		OnFailure.ExecuteIfBound(TEXT("Not logged in"));
		return;
	}

	// Create HTTP request
	TSharedRef<IHttpRequest> Request = Http->CreateRequest();
	Request->SetVerb(TEXT("GET"));
	Request->SetURL(GetApiBaseUrl() + TEXT("/inventory/ships"));
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	Request->SetHeader(TEXT("Authorization"), TEXT("Bearer ") + Token);

	// Bind response handler
	Request->OnProcessRequestComplete().BindUObject(
		this,
		&UEchoesInventorySubsystem::OnShipsReceived,
		OnSuccess,
		OnFailure);

	// Send request
	if (!Request->ProcessRequest())
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to send ships request"));
		OnFailure.ExecuteIfBound(TEXT("Failed to send request"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Fetching ships from backend..."));
	}
}

void UEchoesInventorySubsystem::Inventory_FetchShipFitting(
	const FGuid& ShipId,
	FOnShipFittingReceived OnSuccess,
	FOnInventoryFailure OnFailure)
{
	if (!ShipId.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot fetch ship fitting: Invalid ship ID"));
		OnFailure.ExecuteIfBound(TEXT("Invalid ship ID"));
		return;
	}

	// Get JWT token from Auth subsystem
	FString Token = GetAuthToken();
	if (Token.IsEmpty())
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot fetch ship fitting: No valid JWT token"));
		OnFailure.ExecuteIfBound(TEXT("Not logged in"));
		return;
	}

	// Create HTTP request
	TSharedRef<IHttpRequest> Request = Http->CreateRequest();
	Request->SetVerb(TEXT("GET"));
	Request->SetURL(GetApiBaseUrl() + FString::Printf(TEXT("/inventory/ship/%s/fitting"), *ShipId.ToString()));
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	Request->SetHeader(TEXT("Authorization"), TEXT("Bearer ") + Token);

	// Bind response handler
	Request->OnProcessRequestComplete().BindUObject(
		this,
		&UEchoesInventorySubsystem::OnShipFittingReceived,
		OnSuccess,
		OnFailure);

	// Send request
	if (!Request->ProcessRequest())
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to send ship fitting request"));
		OnFailure.ExecuteIfBound(TEXT("Failed to send request"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Fetching ship fitting for %s from backend..."), *ShipId.ToString());
	}
}

void UEchoesInventorySubsystem::Inventory_SetActiveShip(
	const FGuid& ShipId,
	FOnShipActivated OnSuccess,
	FOnInventoryFailure OnFailure)
{
	if (!ShipId.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot activate ship: Invalid ship ID"));
		OnFailure.ExecuteIfBound(TEXT("Invalid ship ID"));
		return;
	}

	// Get JWT token from Auth subsystem
	FString Token = GetAuthToken();
	if (Token.IsEmpty())
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot activate ship: No valid JWT token"));
		OnFailure.ExecuteIfBound(TEXT("Not logged in"));
		return;
	}

	// Create HTTP request
	TSharedRef<IHttpRequest> Request = Http->CreateRequest();
	Request->SetVerb(TEXT("POST"));
	Request->SetURL(GetApiBaseUrl() + FString::Printf(TEXT("/inventory/ship/%s/activate"), *ShipId.ToString()));
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	Request->SetHeader(TEXT("Authorization"), TEXT("Bearer ") + Token);

	// Bind response handler
	Request->OnProcessRequestComplete().BindUObject(
		this,
		&UEchoesInventorySubsystem::OnShipActivationReceived,
		OnSuccess,
		OnFailure);

	// Send request
	if (!Request->ProcessRequest())
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to send ship activation request"));
		OnFailure.ExecuteIfBound(TEXT("Failed to send request"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Activating ship %s..."), *ShipId.ToString());
	}
}

FEchoesShipInstance UEchoesInventorySubsystem::Inventory_GetActiveShip() const
{
	for (const auto& Ship : CachedShips)
	{
		if (Ship.IsActive)
		{
			return Ship;
		}
	}

	return FEchoesShipInstance();
}

void UEchoesInventorySubsystem::Inventory_ClearCache()
{
	CachedShips.Empty();
	CachedFitting = FEchoesShipFitting();
	CachedHangarIds.Empty();
	UE_LOG(LogTemp, Log, TEXT("Inventory cache cleared"));
}

FGuid UEchoesInventorySubsystem::GetPersonalHangarId(int32 StationId) const
{
	if (const FGuid* CachedId = CachedHangarIds.Find(StationId))
	{
		return *CachedId;
	}
	
	// Return invalid GUID if not cached
	return FGuid();
}

void UEchoesInventorySubsystem::Inventory_RequestPersonalHangar(
	int32 StationId,
	FOnHangarReceived OnSuccess,
	FOnInventoryFailure OnFailure)
{
	// Get JWT token from Auth subsystem
	FString Token = GetAuthToken();
	if (Token.IsEmpty())
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot request personal hangar: No valid JWT token"));
		OnFailure.ExecuteIfBound(TEXT("Not logged in"));
		return;
	}

	// Create HTTP request
	TSharedRef<IHttpRequest> Request = Http->CreateRequest();
	Request->SetVerb(TEXT("GET"));
	Request->SetURL(GetApiBaseUrl() + FString::Printf(TEXT("/inventory/hangar/%d"), StationId));
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	Request->SetHeader(TEXT("Authorization"), TEXT("Bearer ") + Token);

	// Bind response handler
	Request->OnProcessRequestComplete().BindUObject(
		this,
		&UEchoesInventorySubsystem::OnPersonalHangarReceived,
		OnSuccess,
		OnFailure);

	// Send request
	if (!Request->ProcessRequest())
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to send personal hangar request"));
		OnFailure.ExecuteIfBound(TEXT("Failed to send request"));
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Requesting personal hangar from backend for station %d..."), StationId);
	}
}

void UEchoesInventorySubsystem::OnShipsReceived(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful,
	FOnShipsReceived OnSuccess,
	FOnInventoryFailure OnFailure)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Ships request failed"));
		OnFailure.ExecuteIfBound(TEXT("Request failed"));
		return;
	}

	int32 ResponseCode = Response->GetResponseCode();
	FString ResponseContent = Response->GetContentAsString();

	UE_LOG(LogTemp, Log, TEXT("Ships response: HTTP %d"), ResponseCode);

	if (ResponseCode == 200)
	{
		TArray<FEchoesShipInstance> Ships;
		if (ParseShipsList(ResponseContent, Ships))
		{
			// Cache ships
			CachedShips = Ships;

			// Wrap ships in FEchoesShipList for delegate
			FEchoesShipList ShipList;
			ShipList.Ships = Ships;

			UE_LOG(LogTemp, Log, TEXT("Successfully parsed %d ships"), Ships.Num());
			OnSuccess.ExecuteIfBound(ShipList);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to parse ships list"));
			OnFailure.ExecuteIfBound(TEXT("Failed to parse response"));
		}
	}
	else if (ResponseCode == 401)
	{
		UE_LOG(LogTemp, Error, TEXT("Unauthorized: Invalid or expired token"));
		OnFailure.ExecuteIfBound(TEXT("Authentication failed"));
	}
	else
	{
		FString ErrorMsg = FString::Printf(TEXT("HTTP %d: %s"), ResponseCode, *ResponseContent);
		UE_LOG(LogTemp, Error, TEXT("Ships request failed: %s"), *ErrorMsg);
		OnFailure.ExecuteIfBound(ErrorMsg);
	}
}

void UEchoesInventorySubsystem::OnShipFittingReceived(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful,
	FOnShipFittingReceived OnSuccess,
	FOnInventoryFailure OnFailure)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Ship fitting request failed"));
		OnFailure.ExecuteIfBound(TEXT("Request failed"));
		return;
	}

	int32 ResponseCode = Response->GetResponseCode();
	FString ResponseContent = Response->GetContentAsString();

	UE_LOG(LogTemp, Log, TEXT("Ship fitting response: HTTP %d"), ResponseCode);

	if (ResponseCode == 200)
	{
		FEchoesShipFitting Fitting;
		if (ParseShipFitting(ResponseContent, Fitting))
		{
			// Cache fitting
			CachedFitting = Fitting;

			UE_LOG(LogTemp, Log, TEXT("Successfully parsed ship fitting: %s with %d modules"), 
				*Fitting.ShipName, Fitting.Modules.Num());
			OnSuccess.ExecuteIfBound(Fitting);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to parse ship fitting"));
			OnFailure.ExecuteIfBound(TEXT("Failed to parse response"));
		}
	}
	else if (ResponseCode == 401)
	{
		UE_LOG(LogTemp, Error, TEXT("Unauthorized: Invalid or expired token"));
		OnFailure.ExecuteIfBound(TEXT("Authentication failed"));
	}
	else if (ResponseCode == 404)
	{
		UE_LOG(LogTemp, Error, TEXT("Ship not found"));
		OnFailure.ExecuteIfBound(TEXT("Ship not found"));
	}
	else
	{
		FString ErrorMsg = FString::Printf(TEXT("HTTP %d: %s"), ResponseCode, *ResponseContent);
		UE_LOG(LogTemp, Error, TEXT("Ship fitting request failed: %s"), *ErrorMsg);
		OnFailure.ExecuteIfBound(ErrorMsg);
	}
}

void UEchoesInventorySubsystem::OnShipActivationReceived(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful,
	FOnShipActivated OnSuccess,
	FOnInventoryFailure OnFailure)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Ship activation request failed"));
		OnFailure.ExecuteIfBound(TEXT("Request failed"));
		return;
	}

	int32 ResponseCode = Response->GetResponseCode();
	FString ResponseContent = Response->GetContentAsString();

	UE_LOG(LogTemp, Log, TEXT("Ship activation response: HTTP %d"), ResponseCode);

	if (ResponseCode == 200)
	{
		UE_LOG(LogTemp, Log, TEXT("Ship activated successfully"));
		
		// Refresh ships list to update active status
		// Note: In a real implementation, you might want to update the cache directly
		// For now, we'll just notify success
		
		OnSuccess.ExecuteIfBound();
	}
	else if (ResponseCode == 401)
	{
		UE_LOG(LogTemp, Error, TEXT("Unauthorized: Invalid or expired token"));
		OnFailure.ExecuteIfBound(TEXT("Authentication failed"));
	}
	else if (ResponseCode == 404)
	{
		UE_LOG(LogTemp, Error, TEXT("Ship not found"));
		OnFailure.ExecuteIfBound(TEXT("Ship not found"));
	}
	else
	{
		FString ErrorMsg = FString::Printf(TEXT("HTTP %d: %s"), ResponseCode, *ResponseContent);
		UE_LOG(LogTemp, Error, TEXT("Ship activation failed: %s"), *ErrorMsg);
		OnFailure.ExecuteIfBound(ErrorMsg);
	}
}

bool UEchoesInventorySubsystem::ParseShipsList(const FString& JsonString, TArray<FEchoesShipInstance>& OutShips)
{
	TArray<TSharedPtr<FJsonValue>> JsonArray;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonString);

	if (!FJsonSerializer::Deserialize(Reader, JsonArray))
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to deserialize ships JSON array"));
		return false;
	}

	OutShips.Empty();

	for (const auto& JsonValue : JsonArray)
	{
		TSharedPtr<FJsonObject> JsonObject = JsonValue->AsObject();
		if (!JsonObject.IsValid())
		{
			continue;
		}

		FEchoesShipInstance Ship;

		// Parse ship instance data
		FString InstanceIdStr;
		if (JsonObject->TryGetStringField(TEXT("instanceId"), InstanceIdStr))
		{
			FGuid::Parse(InstanceIdStr, Ship.InstanceId);
		}

		JsonObject->TryGetStringField(TEXT("name"), Ship.Name);
		
		int32 ShipTypeIdInt = 0;
		if (JsonObject->TryGetNumberField(TEXT("shipTypeId"), ShipTypeIdInt))
		{
			Ship.ShipTypeId = ShipTypeIdInt;
		}

		JsonObject->TryGetStringField(TEXT("shipTypeName"), Ship.ShipTypeName);

		double MassDouble = 0.0;
		if (JsonObject->TryGetNumberField(TEXT("mass"), MassDouble))
		{
			Ship.Mass = static_cast<float>(MassDouble);
		}

		FString LocationIdStr;
		if (JsonObject->TryGetStringField(TEXT("locationSystemId"), LocationIdStr))
		{
			FGuid::Parse(LocationIdStr, Ship.LocationSystemId);
		}

		JsonObject->TryGetStringField(TEXT("locationName"), Ship.LocationName);
		JsonObject->TryGetBoolField(TEXT("isActive"), Ship.IsActive);
		JsonObject->TryGetBoolField(TEXT("isDocked"), Ship.IsDocked);

		int32 ModuleCountInt = 0;
		if (JsonObject->TryGetNumberField(TEXT("moduleCount"), ModuleCountInt))
		{
			Ship.ModuleCount = ModuleCountInt;
		}

		OutShips.Add(Ship);
	}

	return true;
}

bool UEchoesInventorySubsystem::ParseShipFitting(const FString& JsonString, FEchoesShipFitting& OutFitting)
{
	TSharedPtr<FJsonObject> JsonObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonString);

	if (!FJsonSerializer::Deserialize(Reader, JsonObject) || !JsonObject.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to deserialize ship fitting JSON"));
		return false;
	}

	// Parse ship fitting data
	FString ShipInstanceIdStr;
	if (JsonObject->TryGetStringField(TEXT("shipInstanceId"), ShipInstanceIdStr))
	{
		FGuid::Parse(ShipInstanceIdStr, OutFitting.ShipInstanceId);
	}

	JsonObject->TryGetStringField(TEXT("shipName"), OutFitting.ShipName);

	int32 ShipTypeIdInt = 0;
	if (JsonObject->TryGetNumberField(TEXT("shipTypeId"), ShipTypeIdInt))
	{
		OutFitting.ShipTypeId = ShipTypeIdInt;
	}

	JsonObject->TryGetStringField(TEXT("shipTypeName"), OutFitting.ShipTypeName);

	double BaseMassDouble = 0.0;
	if (JsonObject->TryGetNumberField(TEXT("baseMass"), BaseMassDouble))
	{
		OutFitting.BaseMass = static_cast<float>(BaseMassDouble);
	}

	double TotalMassDouble = 0.0;
	if (JsonObject->TryGetNumberField(TEXT("totalMass"), TotalMassDouble))
	{
		OutFitting.TotalMass = static_cast<float>(TotalMassDouble);
	}

	double ThrustDouble = 0.0;
	if (JsonObject->TryGetNumberField(TEXT("thrust"), ThrustDouble))
	{
		OutFitting.Thrust = static_cast<float>(ThrustDouble);
	}

	double MaxVelocityDouble = 0.0;
	if (JsonObject->TryGetNumberField(TEXT("maxVelocity"), MaxVelocityDouble))
	{
		OutFitting.MaxVelocity = static_cast<float>(MaxVelocityDouble);
	}

	double InertiaMultiplierDouble = 0.0;
	if (JsonObject->TryGetNumberField(TEXT("inertiaMultiplier"), InertiaMultiplierDouble))
	{
		OutFitting.InertiaMultiplier = static_cast<float>(InertiaMultiplierDouble);
	}

	double RotationTorqueDouble = 0.0;
	if (JsonObject->TryGetNumberField(TEXT("rotationTorque"), RotationTorqueDouble))
	{
		OutFitting.RotationTorque = static_cast<float>(RotationTorqueDouble);
	}

	// Parse modules array
	const TArray<TSharedPtr<FJsonValue>>* ModulesArray;
	if (JsonObject->TryGetArrayField(TEXT("modules"), ModulesArray))
	{
		for (const auto& ModuleValue : *ModulesArray)
		{
			TSharedPtr<FJsonObject> ModuleObject = ModuleValue->AsObject();
			if (!ModuleObject.IsValid())
			{
				continue;
			}

			FEchoesModule Module;

			FString ModuleInstanceIdStr;
			if (ModuleObject->TryGetStringField(TEXT("instanceId"), ModuleInstanceIdStr))
			{
				FGuid::Parse(ModuleInstanceIdStr, Module.InstanceId);
			}

			int32 ModuleTypeIdInt = 0;
			if (ModuleObject->TryGetNumberField(TEXT("moduleTypeId"), ModuleTypeIdInt))
			{
				Module.ModuleTypeId = ModuleTypeIdInt;
			}

			ModuleObject->TryGetStringField(TEXT("typeName"), Module.TypeName);
			ModuleObject->TryGetStringField(TEXT("slot"), Module.SlotType);

			int32 SlotIndexInt = 0;
			if (ModuleObject->TryGetNumberField(TEXT("slotIndex"), SlotIndexInt))
			{
				Module.SlotIndex = SlotIndexInt;
			}

			ModuleObject->TryGetBoolField(TEXT("isOnline"), Module.IsOnline);

			double ModuleMassDouble = 0.0;
			if (ModuleObject->TryGetNumberField(TEXT("mass"), ModuleMassDouble))
			{
				Module.Mass = static_cast<float>(ModuleMassDouble);
			}

			double ThrustBonusDouble = 0.0;
			if (ModuleObject->TryGetNumberField(TEXT("thrustBonus"), ThrustBonusDouble))
			{
				Module.ThrustBonus = static_cast<float>(ThrustBonusDouble);
			}

			double InertiaModifierDouble = 1.0;
			if (ModuleObject->TryGetNumberField(TEXT("inertiaModifier"), InertiaModifierDouble))
			{
				Module.InertiaModifier = static_cast<float>(InertiaModifierDouble);
			}

			double RotationBonusDouble = 0.0;
			if (ModuleObject->TryGetNumberField(TEXT("rotationBonus"), RotationBonusDouble))
			{
				Module.RotationBonus = static_cast<float>(RotationBonusDouble);
			}

			double MaxVelocityModifierDouble = 1.0;
			if (ModuleObject->TryGetNumberField(TEXT("maxVelocityModifier"), MaxVelocityModifierDouble))
			{
				Module.MaxVelocityModifier = static_cast<float>(MaxVelocityModifierDouble);
			}

			OutFitting.Modules.Add(Module);
		}
	}

	return true;
}

FString UEchoesInventorySubsystem::GetAuthToken() const
{
	// Get Auth subsystem from same game instance
	auto AuthSubsystem = GetGameInstance()->GetSubsystem<UEchoesAuthSubsystem>();
	if (AuthSubsystem)
	{
		return AuthSubsystem->Auth_GetToken();
	}

	UE_LOG(LogTemp, Error, TEXT("Auth subsystem not found"));
	return FString();
}

FString UEchoesInventorySubsystem::GetApiBaseUrl() const
{
	FString ApiBaseUrl;
	if (GConfig)
	{
		GConfig->GetString(
			TEXT("/Script/Echoes.EchoesAuthSubsystem"),
			TEXT("ApiBaseUrl"),
			ApiBaseUrl,
			GGameIni);
	}

	if (ApiBaseUrl.IsEmpty())
	{
		ApiBaseUrl = TEXT("http://localhost:5116/api");
		UE_LOG(LogTemp, Warning, TEXT("Using default API base URL: %s"), *ApiBaseUrl);
	}

	return ApiBaseUrl;
}

// ==================== UI Wrapper Functions ====================

void UEchoesInventorySubsystem::UI_FitModule(
	const FGuid& ShipId,
	const FGuid& ModuleId,
	const FString& SlotType,
	int32 SlotIndex,
	FOnModuleFitted OnSuccess,
	FOnInventoryFailure OnFailure)
{
	if (!Http)
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesInventorySubsystem: HTTP module not initialized"));
		OnFailure.ExecuteIfBound(TEXT("HTTP module not initialized"));
		return;
	}

	// Get JWT token from Auth subsystem
	FString Token = GetAuthToken();
	if (Token.IsEmpty())
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesInventorySubsystem: No JWT token available"));
		OnFailure.ExecuteIfBound(TEXT("Not authenticated"));
		return;
	}

	// Prepare request URL
	FString ApiUrl = GetApiBaseUrl();
	FString Url = FString::Printf(TEXT("%s/inventory/ship/%s/module/%s/fit"), 
		*ApiUrl, *ShipId.ToString(), *ModuleId.ToString());

	// Create HTTP request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Http->CreateRequest();
	Request->SetVerb(TEXT("PUT"));
	Request->SetURL(Url);
	Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
	Request->SetHeader(TEXT("Authorization"), FString::Printf(TEXT("Bearer %s"), *Token));

	// Prepare request body
	FString RequestBody = FString::Printf(
		TEXT("{\"slotType\":\"%s\",\"slotIndex\":%d}"),
		*SlotType, SlotIndex);
	Request->SetContentAsString(RequestBody);

	// Bind response handler
	Request->OnProcessRequestComplete().BindUObject(
		this,
		&UEchoesInventorySubsystem::OnModuleFitReceived,
		ShipId,
		OnSuccess,
		OnFailure);

	// Send request
	if (Request->ProcessRequest())
	{
		UE_LOG(LogTemp, Log, TEXT("EchoesInventorySubsystem: Fitting module %s to ship %s in %s slot %d"),
			*ModuleId.ToString(), *ShipId.ToString(), *SlotType, SlotIndex);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesInventorySubsystem: Failed to send fit module request"));
		OnFailure.ExecuteIfBound(TEXT("Failed to send request"));
	}
}

void UEchoesInventorySubsystem::UI_UnfitModule(
	const FGuid& ShipId,
	const FGuid& ModuleId,
	FOnModuleUnfitted OnSuccess,
	FOnInventoryFailure OnFailure)
{
	if (!Http)
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesInventorySubsystem: HTTP module not initialized"));
		OnFailure.ExecuteIfBound(TEXT("HTTP module not initialized"));
		return;
	}

	// Get JWT token from Auth subsystem
	FString Token = GetAuthToken();
	if (Token.IsEmpty())
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesInventorySubsystem: No JWT token available"));
		OnFailure.ExecuteIfBound(TEXT("Not authenticated"));
		return;
	}

	// Prepare request URL
	FString ApiUrl = GetApiBaseUrl();
	FString Url = FString::Printf(TEXT("%s/inventory/ship/%s/module/%s/unfit"),
		*ApiUrl, *ShipId.ToString(), *ModuleId.ToString());

	// Create HTTP request
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Http->CreateRequest();
	Request->SetVerb(TEXT("DELETE"));
	Request->SetURL(Url);
	Request->SetHeader(TEXT("Authorization"), FString::Printf(TEXT("Bearer %s"), *Token));

	// Bind response handler
	Request->OnProcessRequestComplete().BindUObject(
		this,
		&UEchoesInventorySubsystem::OnModuleUnfitReceived,
		ShipId,
		OnSuccess,
		OnFailure);

	// Send request
	if (Request->ProcessRequest())
	{
		UE_LOG(LogTemp, Log, TEXT("EchoesInventorySubsystem: Unfitting module %s from ship %s"),
			*ModuleId.ToString(), *ShipId.ToString());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesInventorySubsystem: Failed to send unfit module request"));
		OnFailure.ExecuteIfBound(TEXT("Failed to send request"));
	}
}

void UEchoesInventorySubsystem::OnModuleFitReceived(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful,
   const FGuid& ShipId,
	FOnModuleFitted OnSuccess,
	FOnInventoryFailure OnFailure)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesInventorySubsystem: Module fit request failed"));
		OnFailure.ExecuteIfBound(TEXT("Request failed"));
		return;
	}

	int32 ResponseCode = Response->GetResponseCode();
	FString ResponseContent = Response->GetContentAsString();

	UE_LOG(LogTemp, Log, TEXT("EchoesInventorySubsystem: Module fit response: %d - %s"),
		ResponseCode, *ResponseContent);

	if (ResponseCode == 200)
	{
		// Success! Now refresh the ship fitting to get updated stats
		FOnShipFittingReceived RefreshSuccess;
		RefreshSuccess.BindLambda([this, OnSuccess](const FEchoesShipFitting& Fitting)
		{
			// Cache updated fitting
			CachedFitting = Fitting;
			
			// Trigger fitting changed delegate for UI updates
			OnFittingChanged.Broadcast(Fitting);
			
			// Call success callback
			OnSuccess.ExecuteIfBound();
			
			UE_LOG(LogTemp, Log, TEXT("EchoesInventorySubsystem: Module fitted and fitting updated"));
		});

		FOnInventoryFailure RefreshFailure;
		RefreshFailure.BindLambda([OnSuccess](const FString& Error)
		{
			UE_LOG(LogTemp, Warning, TEXT("EchoesInventorySubsystem: Module fitted but failed to refresh fitting: %s"), *Error);
			// Still call success since the fit operation succeeded
			OnSuccess.ExecuteIfBound();
		});

		Inventory_FetchShipFitting(ShipId, RefreshSuccess, RefreshFailure);
	}
	else if (ResponseCode == 400)
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesInventorySubsystem: Invalid fit request: %s"), *ResponseContent);
		OnFailure.ExecuteIfBound(TEXT("Invalid fit request"));
	}
	else if (ResponseCode == 401)
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesInventorySubsystem: Unauthorized - token may be expired"));
		OnFailure.ExecuteIfBound(TEXT("Unauthorized"));
	}
	else if (ResponseCode == 404)
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesInventorySubsystem: Ship or module not found"));
		OnFailure.ExecuteIfBound(TEXT("Ship or module not found"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesInventorySubsystem: Unexpected response code: %d"), ResponseCode);
		OnFailure.ExecuteIfBound(FString::Printf(TEXT("Server error: %d"), ResponseCode));
	}
}

void UEchoesInventorySubsystem::OnModuleUnfitReceived(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful,
	const FGuid& ShipId, // Исправлено: добавлена ссылка
	FOnModuleUnfitted OnSuccess,
	FOnInventoryFailure OnFailure)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesInventorySubsystem: Module unfit request failed"));
		OnFailure.ExecuteIfBound(TEXT("Request failed"));
		return;
	}

	int32 ResponseCode = Response->GetResponseCode();
	FString ResponseContent = Response->GetContentAsString();

	UE_LOG(LogTemp, Log, TEXT("EchoesInventorySubsystem: Module unfit response: %d - %s"),
		ResponseCode, *ResponseContent);

	if (ResponseCode == 200)
	{
		// Success! Now refresh the ship fitting to get updated stats
		FOnShipFittingReceived RefreshSuccess;
		RefreshSuccess.BindLambda([this, OnSuccess](const FEchoesShipFitting& Fitting)
		{
			// Cache updated fitting
			CachedFitting = Fitting;
			
			// Trigger fitting changed delegate for UI updates
			OnFittingChanged.Broadcast(Fitting);
			
			// Call success callback
			OnSuccess.ExecuteIfBound();
			
			UE_LOG(LogTemp, Log, TEXT("EchoesInventorySubsystem: Module unfitted and fitting updated"));
		});

		FOnInventoryFailure RefreshFailure;
		RefreshFailure.BindLambda([OnSuccess](const FString& Error)
		{
			UE_LOG(LogTemp, Warning, TEXT("EchoesInventorySubsystem: Module unfitted but failed to refresh fitting: %s"), *Error);
			// Still call success since the unfit operation succeeded
			OnSuccess.ExecuteIfBound();
		});

		Inventory_FetchShipFitting(ShipId, RefreshSuccess, RefreshFailure);
	}
	else if (ResponseCode == 401)
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesInventorySubsystem: Unauthorized - token may be expired"));
		OnFailure.ExecuteIfBound(TEXT("Unauthorized"));
	}
	else if (ResponseCode == 404)
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesInventorySubsystem: Ship or module not found"));
		OnFailure.ExecuteIfBound(TEXT("Ship or module not found"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("EchoesInventorySubsystem: Unexpected response code: %d"), ResponseCode);
		OnFailure.ExecuteIfBound(FString::Printf(TEXT("Server error: %d"), ResponseCode));
	}
}

void UEchoesInventorySubsystem::OnPersonalHangarReceived(
	FHttpRequestPtr Request,
	FHttpResponsePtr Response,
	bool bWasSuccessful,
	FOnHangarReceived OnSuccess,
	FOnInventoryFailure OnFailure)
{
	if (!bWasSuccessful || !Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Personal hangar request failed"));
		OnFailure.ExecuteIfBound(TEXT("Request failed"));
		return;
	}

	int32 ResponseCode = Response->GetResponseCode();
	FString ResponseContent = Response->GetContentAsString();

	UE_LOG(LogTemp, Log, TEXT("Personal hangar response: HTTP %d"), ResponseCode);

	if (ResponseCode == 200)
	{
		// Parse JSON response
		TSharedPtr<FJsonObject> JsonObject;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ResponseContent);

		if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
		{
			FString StorageIdStr = JsonObject->GetStringField(TEXT("storageId"));
			FGuid StorageId;
			
			if (FGuid::Parse(StorageIdStr, StorageId))
			{
				// Cache the hangar ID
				// Extract station ID from request URL
				FString RequestURL = Request->GetURL();
				int32 StationId = 0;
				
				// Parse station ID from URL (format: .../hangar/{stationId})
				int32 LastSlashIndex;
				if (RequestURL.FindLastChar('/', LastSlashIndex))
				{
					FString StationIdStr = RequestURL.RightChop(LastSlashIndex + 1);
					StationId = FCString::Atoi(*StationIdStr);
					
					if (StationId > 0)
					{
						CachedHangarIds.Add(StationId, StorageId);
						UE_LOG(LogTemp, Log, TEXT("Cached hangar ID %s for station %d"),
							*StorageId.ToString(), StationId);
					}
				}
				
				UE_LOG(LogTemp, Log, TEXT("Successfully retrieved personal hangar: %s"), *StorageId.ToString());
				OnSuccess.ExecuteIfBound(StorageId);
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("Failed to parse storage ID: %s"), *StorageIdStr);
				OnFailure.ExecuteIfBound(TEXT("Invalid storage ID format"));
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to parse personal hangar response"));
			OnFailure.ExecuteIfBound(TEXT("Failed to parse response"));
		}
	}
	else if (ResponseCode == 401)
	{
		UE_LOG(LogTemp, Error, TEXT("Unauthorized: Invalid or expired token"));
		OnFailure.ExecuteIfBound(TEXT("Authentication failed"));
	}
	else
	{
		FString ErrorMsg = FString::Printf(TEXT("HTTP %d: %s"), ResponseCode, *ResponseContent);
		UE_LOG(LogTemp, Error, TEXT("Personal hangar request failed: %s"), *ErrorMsg);
		OnFailure.ExecuteIfBound(ErrorMsg);
	}
}

// ==================== Item Definitions System ====================

bool UEchoesInventorySubsystem::TryGetItemDefinition(const FString& ItemId, FEchoesItemDefinitionRow& OutDefinition) const
{
	// Check cache first
	if (const FEchoesItemDefinitionRow* CachedDef = DefinitionCache.Find(ItemId))
	{
		OutDefinition = *CachedDef;
		return true;
	}

	// If not in cache and table exists, try to find it
	if (ItemDefinitionsTable)
	{
		FName RowName(*ItemId);
		if (const FEchoesItemDefinitionRow* Row = ItemDefinitionsTable->FindRow<FEchoesItemDefinitionRow>(RowName, TEXT("GetItemDefinition")))
		{
			OutDefinition = *Row;
			return true;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("EchoesInventorySubsystem: Item definition not found for ID: %s"), *ItemId);
	return false;
}

FEchoesItemDefinitionRow UEchoesInventorySubsystem::GetItemDefinitionData(const FString& ItemId) const
{
	FEchoesItemDefinitionRow Definition;
	if (TryGetItemDefinition(ItemId, Definition))
	{
		return Definition;
	}

	return FEchoesItemDefinitionRow();
}

bool UEchoesInventorySubsystem::TryGetItemDefinitionByTypeId(int32 TypeId, FEchoesItemDefinitionRow& OutDefinition) const
{
	return TryGetItemDefinition(FString::FromInt(TypeId), OutDefinition);
}

FEchoesItemDefinitionRow UEchoesInventorySubsystem::GetItemDefinitionDataByTypeId(int32 TypeId) const
{
	return GetItemDefinitionData(FString::FromInt(TypeId));
}

void UEchoesInventorySubsystem::AsyncLoadItemIcon(const FString& ItemId, FOnIconLoaded OnLoaded)
{
	FEchoesItemDefinitionRow Definition;
	if (!TryGetItemDefinition(ItemId, Definition))
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesInventorySubsystem: Cannot load icon - item definition not found: %s"), *ItemId);
		OnLoaded.ExecuteIfBound(nullptr);
		return;
	}

	// If icon is null, return null immediately
	if (Definition.Icon.IsNull())
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesInventorySubsystem: Item %s has no icon defined"), *ItemId);
		OnLoaded.ExecuteIfBound(nullptr);
		return;
	}

	// If already loaded, return immediately
	if (Definition.Icon.IsValid())
	{
		OnLoaded.ExecuteIfBound(Definition.Icon.Get());
		return;
	}

	// Load asynchronously
	FSoftObjectPath IconPath = Definition.Icon.ToSoftObjectPath();
	TSharedPtr<FStreamableHandle> Handle = StreamableManager.RequestAsyncLoad(
		IconPath,
		[OnLoaded, IconPath]()
		{
			UTexture2D* LoadedIcon = Cast<UTexture2D>(IconPath.ResolveObject());
			if (LoadedIcon)
			{
				UE_LOG(LogTemp, Log, TEXT("EchoesInventorySubsystem: Icon loaded: %s"), *IconPath.ToString());
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("EchoesInventorySubsystem: Failed to load icon: %s"), *IconPath.ToString());
			}
			OnLoaded.ExecuteIfBound(LoadedIcon);
		}
	);
}

void UEchoesInventorySubsystem::AsyncLoadItemWorldMesh(const FString& ItemId, FOnWorldMeshLoaded OnLoaded)
{
	FEchoesItemDefinitionRow Definition;
	if (!TryGetItemDefinition(ItemId, Definition))
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesInventorySubsystem: Cannot load mesh - item definition not found: %s"), *ItemId);
		OnLoaded.ExecuteIfBound(nullptr);
		return;
	}

	// If mesh is null, return null immediately
	if (Definition.WorldMesh.IsNull())
	{
		UE_LOG(LogTemp, Warning, TEXT("EchoesInventorySubsystem: Item %s has no world mesh defined"), *ItemId);
		OnLoaded.ExecuteIfBound(nullptr);
		return;
	}

	// If already loaded, return immediately
	if (Definition.WorldMesh.IsValid())
	{
		OnLoaded.ExecuteIfBound(Definition.WorldMesh.Get());
		return;
	}

	// Load asynchronously
	FSoftObjectPath MeshPath = Definition.WorldMesh.ToSoftObjectPath();
	TSharedPtr<FStreamableHandle> Handle = StreamableManager.RequestAsyncLoad(
		MeshPath,
		[OnLoaded, MeshPath]()
		{
			UStaticMesh* LoadedMesh = Cast<UStaticMesh>(MeshPath.ResolveObject());
			if (LoadedMesh)
			{
				UE_LOG(LogTemp, Log, TEXT("EchoesInventorySubsystem: World mesh loaded: %s"), *MeshPath.ToString());
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("EchoesInventorySubsystem: Failed to load world mesh: %s"), *MeshPath.ToString());
			}
			OnLoaded.ExecuteIfBound(LoadedMesh);
		}
	);
}

bool UEchoesInventorySubsystem::HasItemDefinition(const FString& ItemId) const
{
	FEchoesItemDefinitionRow Definition;
	return TryGetItemDefinition(ItemId, Definition);
}

bool UEchoesInventorySubsystem::TryGetItemFromRegistry(int32 TypeId, FEchoesItemDefinitionRow& OutDefinition) const
{
	if (const FEchoesItemDefinitionRow* Found = ItemTypeRegistry.Find(TypeId))
	{
		OutDefinition = *Found;
		return true;
	}

	return false;
}

FEchoesItemDefinitionRow UEchoesInventorySubsystem::GetItemFromRegistryData(int32 TypeId) const
{
	FEchoesItemDefinitionRow Definition;
	if (TryGetItemFromRegistry(TypeId, Definition))
	{
		return Definition;
	}

	return FEchoesItemDefinitionRow();
}

bool UEchoesInventorySubsystem::HasItemInRegistry(int32 TypeId) const
{
	return ItemTypeRegistry.Contains(TypeId);
}

void UEchoesInventorySubsystem::BuildDefinitionCache()
{
	DefinitionCache.Empty();
	ItemTypeRegistry.Empty();

	if (!ItemDefinitionsTable)
	{
		return;
	}

	// Get all row names from the data table
	TArray<FName> RowNames = ItemDefinitionsTable->GetRowNames();

	for (const FName& RowName : RowNames)
	{
		if (const FEchoesItemDefinitionRow* Row = ItemDefinitionsTable->FindRow<FEchoesItemDefinitionRow>(RowName, TEXT("BuildDefinitionCache")))
		{
			// Add to string-based cache (legacy)
			DefinitionCache.Add(RowName.ToString(), *Row);

			// Add to typed registry
			// Parse RowName as integer TypeId
			FString RowNameStr = RowName.ToString();
			if (RowNameStr.IsNumeric())
			{
				int32 TypeId = FCString::Atoi(*RowNameStr);
				ItemTypeRegistry.Add(TypeId, *Row);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("BuildDefinitionCache: Row name '%s' is not numeric, skipping typed registry"), *RowNameStr);
			}
		}
	}

	UE_LOG(LogTemp, Log, TEXT("EchoesInventorySubsystem: Built definition cache with %d entries"), DefinitionCache.Num());
	UE_LOG(LogTemp, Log, TEXT("EchoesInventorySubsystem: Built typed registry with %d entries"), ItemTypeRegistry.Num());
}
