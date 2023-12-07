// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SBEffect.h"
#include "SBEffectTeleport.generated.h"

class USphereComponent;

UCLASS()
class ACTIONROGUELIKE_API ASBEffectTeleport : public ASBEffect
{
	GENERATED_BODY()

public:
	ASBEffectTeleport();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Effects")
	USphereComponent* SphereComp;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Effects")
	UParticleSystemComponent* EffectComp;
	
	void TeleportInstigator() const;

protected:
	virtual void BeginPlay() override;
};
