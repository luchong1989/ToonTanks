// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ToonTanks2GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS2_API AToonTanks2GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	void ActorDied(AActor* DeadActor);

protected:

	virtual void BeginPlay() override;

private:

	class ATank* Tank;
};
