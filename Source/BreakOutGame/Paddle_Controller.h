// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Paddle_Controller.generated.h"

class ABall;
UCLASS()
class BREAKOUTGAME_API APaddle_Controller : public APlayerController
{
	GENERATED_BODY()
		APaddle_Controller();
	UFUNCTION()
		virtual void SetupInputComponent() override;

protected:
	virtual void BeginPlay() override;
	int ballCount = 3;
	void MoveHorizontal(float AxisValue);

	void Launch();
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABall>Ball;
	ABall* Myball;

	FVector SpawnLocation = FVector(0.0f, 0.0f, 600.0f);
	FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
public:
	void SpawnNewBall();
	
};