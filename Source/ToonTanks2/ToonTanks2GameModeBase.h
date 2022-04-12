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

	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();

	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool bWonGame);

private:

	class ATank* Tank;
	class AToonTanksPlayerController* ToonTanksPlayerController;
	

	float StartDelay = 3.f;
	void HandleGameStart();

	int32 TargetTowers = 0;
	int32 GetTargetTowerCount();
};
