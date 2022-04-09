// Copyright Epic Games, Inc. All Rights Reserved.


#include "ToonTanks2GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "Tower.h"

void AToonTanks2GameModeBase::ActorDied(AActor* DeadActor)
{
	if (DeadActor == Tank)
	{
		Tank->HandleDestruction();
		if (Tank->GetTankPlayerController())
		{
			Tank->DisableInput(Tank->GetTankPlayerController());
			Tank->GetTankPlayerController()->bShowMouseCursor = false;
		}
		
	}
	else if (ATower* DestroyedTower = Cast<ATower>(DeadActor))
	{
		DestroyedTower->HandleDestruction();
	}
}

void AToonTanks2GameModeBase::BeginPlay()
{
	Super::BeginPlay();

	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
}