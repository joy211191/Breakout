// Fill out your copyright notice in the Description page of Project Settings.


#include "BallBound.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Paddle_Player_Controller.h"

// Sets default values
ABallBound::ABallBound()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Box_Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box_Collision"));
	RootComponent = Box_Collision;
}

// Called when the game starts or when spawned
void ABallBound::BeginPlay()
{
	Super::BeginPlay();

	Box_Collision->OnComponentBeginOverlap.AddDynamic(this, &ABallBound::OnOverlapBegin);
	playerController_Ref = Cast<APaddle_Player_Controller>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	
}

// Called every frame
void ABallBound::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ABallBound::OnOverlapBegin(UPrimitiveComponent* OverlapComponent, AActor* OtherActor, UPrimitiveComponent* otherComponent, int32 otherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Ball")) {
		OtherActor->Destroy();
		playerController_Ref->SpawnNewBall();
	}
}

