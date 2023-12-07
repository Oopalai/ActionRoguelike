// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SBProjectile.h"
#include "SBProjectileEffect.generated.h"

class ASBEffectBlackHole;
/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ASBProjectileEffect : public ASBProjectile
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ASBProjectileEffect();

protected:
	//The effect that gets played by the magical projectile.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Projectile")
	UParticleSystemComponent* ProjectileEffectComp;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
