// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS2_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:

	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void HandleDestruction() override;

	APlayerController* GetTankPlayerController() const { return TankPlayerController; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* FollowCamera;

	void Move(float Value);
	void Turn(float Value);
	

	UPROPERTY(EditAnywhere)
	float Speed = 200.f;

	UPROPERTY(EditAnywhere)
	float TurnRate = 200.f;

	APlayerController* TankPlayerController;
	
};
