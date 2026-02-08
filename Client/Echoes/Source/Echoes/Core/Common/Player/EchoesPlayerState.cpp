// Copyright Epic Games, Inc. All Rights Reserved.

#include "EchoesPlayerState.h"
#include "Net/UnrealNetwork.h"

AEchoesPlayerState::AEchoesPlayerState()
{
}

void AEchoesPlayerState::SetAuthToken(const FString& NewToken)
{
    if (HasAuthority())
    {
        AuthToken = NewToken;
        // Replication will notify clients if needed
    }
}

void AEchoesPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(AEchoesPlayerState, AuthToken);
}

void AEchoesPlayerState::OnRep_AuthToken()
{
    // No-op for now; can be used by client UI when token changes
}
