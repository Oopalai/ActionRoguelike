// Fill out your copyright notice in the Description page of Project Settings.


#include "SBMagicProjectile.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"


// Sets default values
ASBMagicProjectile::ASBMagicProjectile()
{
	EffectComp = CreateDefaultSubobject<UParticleSystemComponent>("EffectComp");
	EffectComp->SetupAttachment(SphereComp);
}

// Called when the game starts or when spawned
void ASBMagicProjectile::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASBMagicProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}