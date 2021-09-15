// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

UCLASS()
class BREAKOUTGAME_API ABall : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABall();

	virtual void Launch();
	bool bBallLaunched;
	int Score;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* SM_Ball;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UProjectileMovementComponent* ProjectileMovement;


	//Getting linker errors with this particular class
	/*UPROPERTY(EditAnywhere)
		class USynthComponent* SynthComponent;*/

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlapComponent,class AActor* OtherActor,class UPrimitiveComponent* OtherCompenent,int32 OtherBodyIndex,bool bFroomSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	void PlayAudio();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		UStaticMeshComponent* GetBall();

};
