// Fill out your copyright notice in the Description page of Project Settings.


#include "Brick.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Ball.h"

// Sets default values
ABrick::ABrick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	SM_Brick = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Brick"));
	SM_Brick->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Brick->SetCollisionProfileName(TEXT("PhysicsActor"));
	Box_Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	Box_Collision->SetBoxExtent(FVector(50.0f, 25.0f, 25.0f));

	RootComponent = Box_Collision;
}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();
	
	Box_Collision->OnComponentBeginOverlap.AddDynamic (this, &ABrick::OnOverlapBegin);

}

// Called every frame
void ABrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ABrick::OnOverlapBegin(UPrimitiveComponent* OverlapComponent, AActor* OtherActor, UPrimitiveComponent* otherComponent, int32 otherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	/*if (OtherActor->ActorHasTag("Ball")) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Ball Collided"));
		ABall* MyBall = Cast<ABall>(OtherActor);
		this->Destroy();
		
		//FTimerHandle unUsedHandle;
		//GetWorldTimerManager().SetTimer(unUsedHandle,this,&ABrick::DestroyBrick,0.1f,false);
	}*/
}

void ABrick::DestroyBrick()
{
	this->Destroy();
}

