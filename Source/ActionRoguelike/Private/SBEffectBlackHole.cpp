// Fill out your copyright notice in the Description page of Project Settings.


#include "SBEffectBlackHole.h"

#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"

// Sets default values
ASBEffectBlackHole::ASBEffectBlackHole()
{
	PrimaryActorTick.bCanEverTick = true;

	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	RootComponent = SphereComp;
	EffectComp = CreateDefaultSubobject<UParticleSystemComponent>("EffectComp");
	EffectComp->SetupAttachment(SphereComp);
	RadialForceComponent = CreateDefaultSubobject<URadialForceComponent>("RadialForceComp");
	RadialForceComponent->SetupAttachment(SphereComp);
	RadialForceComponent->ForceStrength = -10000;
	
}

// Called when the game starts or when spawned
void ASBEffectBlackHole::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASBEffectBlackHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

