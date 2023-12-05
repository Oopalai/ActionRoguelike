// Fill out your copyright notice in the Description page of Project Settings.


#include "SBProjectileMagic.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"


// Sets default values
ASBProjectileMagic::ASBProjectileMagic()
{
	EffectComp = CreateDefaultSubobject<UParticleSystemComponent>("EffectComp");
	EffectComp->SetupAttachment(SphereComp);
}

// Called when the game starts or when spawned
void ASBProjectileMagic::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASBProjectileMagic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}