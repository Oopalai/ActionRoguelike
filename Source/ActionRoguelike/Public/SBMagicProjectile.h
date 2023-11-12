// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SBProjectile.h"
#include "GameFramework/Actor.h"
#include "SBMagicProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UParticleSystemComponent;

UCLASS()
class ACTIONROGUELIKE_API ASBMagicProjectile : public ASBProjectile
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASBMagicProjectile();

protected:
	//The effect that gets played by the magical projectile.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UParticleSystemComponent* EffectComp;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
