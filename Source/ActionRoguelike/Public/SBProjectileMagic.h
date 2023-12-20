// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SBProjectile.h"
#include "GameFramework/Actor.h"
#include "SBProjectileMagic.generated.h"

class UParticleSystemComponent;
UCLASS()
class ACTIONROGUELIKE_API ASBProjectileMagic : public ASBProjectile
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASBProjectileMagic();

	UFUNCTION()
	void OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	                    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

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
