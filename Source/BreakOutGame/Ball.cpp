// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Components/StaticMeshComponent.h"
//#include "Components/SynthComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Math.h"
#include "Components/BoxComponent.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"

// Sets default values
ABall::ABall()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball"));
	RootComponent = SM_Ball;
	SM_Ball->SetSimulatePhysics(true);
	SM_Ball->SetEnableGravity(false);
	SM_Ball->SetConstraintMode(EDOFMode::YZPlane);
	SM_Ball->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Ball->SetCollisionProfileName(TEXT("PhysicsActor"));
	SM_Ball->UpdateChildTransforms(EUpdateTransformFlags::PropagateFromParent, ETeleportType::TeleportPhysics);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("BallPhysics"));
	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->Bounciness = 1.1f;
	ProjectileMovement->Friction = 0.0f;
	ProjectileMovement->Velocity.Z = 0.0f;
	ProjectileMovement->Velocity.Y = 0.0f;

	//SynthComponent = CreateDefaultSubobject<USynthComponent>(TEXT("Audio"));
	//SynthComponent->Activate(true);

	//Have to define notes
	//SynthComponent->
}

void ABall::Launch()
{
	if (!bBallLaunched) {
		SM_Ball->AddImpulse(FVector(0, FMath::RandRange(-750.f, 750.f), FMath::RandRange(750.f, 1000.f)),FName(),true);
		bBallLaunched = true;
	}
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();

}

void ABall::OnOverlapBegin(UPrimitiveComponent* OverlapComponent, AActor* OtherActor, UPrimitiveComponent* OtherCompenent, int32 OtherBodyIndex, bool bFroomSweep, const FHitResult& SweepResult)
{
}

void ABall::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("BALL: Other actor tag, %d"), OtherActor->ActorHasTag("Brick"));
	if (OtherActor->ActorHasTag("Brick")) {
		OtherActor->Destroy();
		UE_LOG(LogTemp, Warning, TEXT("Collision Registered"));
		PlayAudio();
	}
}

void ABall::PlayAudio()
{
	/*if (!SynthComponent->HasBegunPlay())
		SynthComponent->BeginPlay();*/
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

UStaticMeshComponent* ABall::GetBall()
{
	return SM_Ball;
}
