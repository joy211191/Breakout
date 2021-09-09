// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Paddle_Player_Controller.generated.h"

class ABall;

UCLASS()
class BREAKOUT_API APaddle_Player_Controller : public APlayerController
{
	GENERATED_BODY()

		APaddle_Player_Controller();
	
	UFUNCTION()
		virtual void SetupInputComponent() override;

protected:
	virtual void BeginPlay() override;
	int ballCount = 3;
	void MoveHorizontal(float AxisValue);

	void Launch();
	UPROPERTY(EditAnywhere)
		TSubclassOf<ABall>BallObj;
	ABall* Myball;

	//APaddle myPawn = Cast<APaddle>(GetPawn());
	//FVector SpawnLocation = myPawn->GetActorLocation;
	FVector SpawnLocation = FVector(10.0f, 0.0f, -700.0f);
	FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
public:
	void SpawnNewBall();
};
