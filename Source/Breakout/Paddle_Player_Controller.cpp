// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle_Player_Controller.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"
#include "Paddle.h"
#include "Ball.h"

APaddle_Player_Controller::APaddle_Player_Controller()
{


}

void APaddle_Player_Controller::BeginPlay()
{
	TArray<AActor*> CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);

	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActors[0], Params);

	SpawnNewBall();

}

void APaddle_Player_Controller::SetupInputComponent()
{
	Super::SetupInputComponent();
	EnableInput(this);
	InputComponent->BindAxis("MoveHorizontal", this, &APaddle_Player_Controller::MoveHorizontal);
	InputComponent->BindAction("Launch", IE_Pressed, this, &APaddle_Player_Controller::Launch);

}


void APaddle_Player_Controller::MoveHorizontal(float AxisValue)
{
	auto myPawn = Cast<APaddle>(GetPawn());
	if (myPawn) {
		myPawn->MoveHorizontal(AxisValue);
	}
}

void APaddle_Player_Controller::Launch()
{
	Myball->Launch();
}

void APaddle_Player_Controller::SpawnNewBall()
{
	if (!Myball) {
		Myball = nullptr;
	}

	if (BallObj) {
		Myball = GetWorld()->SpawnActor<ABall>(BallObj,SpawnLocation,SpawnRotation,SpawnInfo);
	}

}
