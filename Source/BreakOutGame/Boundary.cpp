// Fill out your copyright notice in the Description page of Project Settings.


#include "Boundary.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Paddle_Controller.h"

// Sets default values
ABoundary::ABoundary()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box_Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	RootComponent = Box_Collider;

}

// Called when the game starts or when spawned
void ABoundary::BeginPlay()
{
	Super::BeginPlay();
	
	Box_Collider->OnComponentBeginOverlap.AddDynamic(this, &ABoundary::OnOverlapBegin);
	playerController = Cast<APaddle_Controller>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
}

void ABoundary::OnOverlapBegin(UPrimitiveComponent* OverlapComponent, AActor* OtherActor, UPrimitiveComponent* otherComponent, int32 otherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	OtherActor->Destroy();
	playerController->SpawnNewBall();
}

// Called every frame
void ABoundary::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}