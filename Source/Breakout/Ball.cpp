// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SynthComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Math.h"
#include "Components/BoxComponent.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball"));
	RootComponent = SM_Ball;
	SM_Ball->SetSimulatePhysics(true);
	SM_Ball->SetEnableGravity(false);
	SM_Ball->SetConstraintMode(EDOFMode::XZPlane);
	SM_Ball->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Ball->SetCollisionProfileName(TEXT("PhysicsActor"));

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->Bounciness = 1.1f;
	ProjectileMovement->Friction = 0.0f;
	ProjectileMovement->Velocity.X = 0.0f;

	//ynthComponent = CreateDefaultSubobject<USynthComponent>(TEXT("Audio"));
	//SynthComponent->CreateAudioComponent();
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
}

/*void ABall::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
}*/

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//This does not get called hence I programmed it via Blueprints
void ABall::OnOverlapBegin(UPrimitiveComponent* OverlapComponent, AActor* OtherActor, UPrimitiveComponent* otherComponent, int32 otherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag("Brick")) {
		OtherActor->Destroy();
		AudioPlay();
	}
}

//Linker errors on enabling the USynthComponent and this is why I added in an audio component in the blueprint that gets called everytime the ball collides
void ABall::AudioPlay()
{
	/*if (!SynthComponent->IsPlaying()) {
		SynthComponent->BeginPlay();
	}*/
}

void ABall::Launch()
{
	if (!BallLaunched) {
		SM_Ball->AddImpulse(FVector(FMath::RandRange(750.0f, 1000.0f), 0.0f, FMath::RandRange(750.0f, 1000.0f)), FName(), true);
		BallLaunched = true;
	}
}

UStaticMeshComponent* ABall::GetBall()
{
	return SM_Ball;
}

