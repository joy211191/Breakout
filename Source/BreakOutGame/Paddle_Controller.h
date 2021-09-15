// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Paddle_Controller.generated.h"


UCLASS()
class BREAKOUTGAME_API APaddle_Controller : public APlayerController
{
	GENERATED_BODY()
		APaddle_Controller();
	UFUNCTION() 
		virtual void SetupInputComponent() override;
protected:
	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget> LivesUIClass;
	UUserWidget* LivesUI;


	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ballCount = 3;
	void MoveHorizontal(float AxisValue);

	void Launch();
	UPROPERTY(EditAnywhere)
		TSubclassOf<class ABall>Ball;
	ABall* Myball;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget> GameOverScreenClass;
	UUserWidget* GameOverWidget;

	FVector SpawnLocation = FVector(0.0f, 0.0f, 600.0f);
	FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Score;

	void SpawnNewBall();

	UFUNCTION()
		int GetLives();
};