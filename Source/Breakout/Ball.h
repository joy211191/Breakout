// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

class UProjectileMovementComponent;
//class USynthComponent;

UCLASS()
class BREAKOUT_API ABall : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABall();

	virtual void Launch();
	bool BallLaunched;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_Ball;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UProjectileMovementComponent* ProjectileMovement;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		//USynthComponent* SynthComponent;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlapComponent, class AActor* OtherActor, class UPrimitiveComponent* otherComponent, int32 otherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void AudioPlay();

	/*UFUNCTION()
		void OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);*/

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
		UStaticMeshComponent* GetBall();

};
