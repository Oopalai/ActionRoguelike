// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SBProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UParticleSystem;

UCLASS(Abstract)
class ACTIONROGUELIKE_API ASBProjectile : public AActor
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	void OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	// Sets default values for this actor's properties
	ASBProjectile();

protected:
	//The sphere component is the collision component for the projectile.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USphereComponent* SphereComp;

	//The movement component is responsible for making the sphere component move.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UProjectileMovementComponent* MovementComp;
	
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
