// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SBEffectBlackHole.generated.h"

class USphereComponent;
class URadialForceComponent;

UCLASS()
class ACTIONROGUELIKE_API ASBEffectBlackHole : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASBEffectBlackHole();

	//Sphere Collider for centering the effect.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effects")
	USphereComponent* SphereComp;
	
	//The Black Hole Effect.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Effects")
	UParticleSystemComponent* EffectComp;
	
	//The Gravitational Effects are done through this.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
	URadialForceComponent* RadialForceComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
