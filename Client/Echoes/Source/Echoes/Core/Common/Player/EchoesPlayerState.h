// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "EchoesPlayerState.generated.h"

/**
 * AEchoesPlayerState
 *
 * Stores per-player server-side data such as authenticated token.
 */
UCLASS()
class ECHOES_API AEchoesPlayerState : public APlayerState
{
    GENERATED_BODY()

public:
    AEchoesPlayerState();

    // Store client's auth token for server-side subsystems
    UPROPERTY(Replicated, BlueprintReadWrite, Category = "Auth")
    FString AuthToken;

    UFUNCTION(BlueprintCallable, Category = "Auth")
    void SetAuthToken(const FString& NewToken);

protected:
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    UFUNCTION()
    void OnRep_AuthToken();
};
