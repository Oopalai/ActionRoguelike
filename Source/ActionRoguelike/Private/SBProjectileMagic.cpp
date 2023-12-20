// Fill out your copyright notice in the Description page of Project Settings.


#include "SBProjectileMagic.h"

#include "SBAttributeComponent.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"


// Sets default values
ASBProjectileMagic::ASBProjectileMagic()
{
	EffectComp = CreateDefaultSubobject<UParticleSystemComponent>("EffectComp");
	EffectComp->SetupAttachment(SphereComp);
	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &ASBProjectileMagic::OnActorOverlap);
}

void ASBProjectileMagic::OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		if (USBAttributeComponent* AttributeComp = Cast<USBAttributeComponent>(OtherActor->GetComponentByClass(USBAttributeComponent::StaticClass())))
		{
			AttributeComp->ApplyHealthChange(-20.0f);
			Destroy();
		}
	}
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