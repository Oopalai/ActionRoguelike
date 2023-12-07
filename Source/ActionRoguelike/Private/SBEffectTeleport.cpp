// Fill out your copyright notice in the Description page of Project Settings.


#include "SBEffectTeleport.h"

#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"

ASBEffectTeleport::ASBEffectTeleport()
{
	PrimaryActorTick.bCanEverTick = true;
	
	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	RootComponent = SphereComp;
	EffectComp = CreateDefaultSubobject<UParticleSystemComponent>("ParticleEffectComp");
}

void ASBEffectTeleport::TeleportInstigator() const
{
	GetInstigator()->TeleportTo(this->GetActorLocation(), GetInstigator()->GetActorRotation());
}

void ASBEffectTeleport::BeginPlay()
{
	Super::BeginPlay();
	TeleportInstigator();
	Destroy();
}