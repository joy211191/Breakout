// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle_Controller.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"
#include "Paddle.h"
#include "Ball.h"

APaddle_Controller::APaddle_Controller()
{
	SpawnNewBall();
}

void APaddle_Controller::BeginPlay()
{
	TArray<AActor*> CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);

	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActors[0], Params);

	SpawnNewBall();

}

void APaddle_Controller::SetupInputComponent()
{
	Super::SetupInputComponent();
	EnableInput(this);
	InputComponent->BindAxis("Horizontal", this, &APaddle_Controller::MoveHorizontal);
	InputComponent->BindAction("Launch", IE_Pressed, this, &APaddle_Controller::Launch);
}

void APaddle_Controller::MoveHorizontal(float AxisValue)
{
	auto myPaddle = Cast<APaddle>(GetPawn());
	if (myPaddle) {
		myPaddle-> MoveHorizontal(AxisValue);
	}

}

void APaddle_Controller::Launch()
{
	Myball->Launch();
}

void APaddle_Controller::SpawnNewBall()
{
	if (!Myball)
		Myball = nullptr;
	if (Ball) {
		if (ballCount > 0) {
			Myball = GetWorld()->SpawnActor<ABall>(Ball, SpawnLocation, SpawnRotation, SpawnInfo);
			ballCount--;
		}
		else {
			UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
			//Add more functionality for gameover
		}
	}
}