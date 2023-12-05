// Fill out your copyright notice in the Description page of Project Settings.


#include "SBProjectileEffect.h"

#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"

ASBProjectileEffect::ASBProjectileEffect()
{
	ProjectileEffectComp = CreateDefaultSubobject<UParticleSystemComponent>("EffectComp");
	ProjectileEffectComp->SetupAttachment(SphereComp);
}

void ASBProjectileEffect::BeginPlay()
{
	Super::BeginPlay();
}

void ASBProjectileEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


