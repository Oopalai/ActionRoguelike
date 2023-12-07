// Fill out your copyright notice in the Description page of Project Settings.


#include "SBProjectile.h"

#include "SBAttributeComponent.h"
#include "SBProjectileMagic.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

void ASBProjectile::OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		USBAttributeComponent* AttributeComp = Cast<USBAttributeComponent>(OtherActor->GetComponentByClass(USBAttributeComponent::StaticClass()));
		if (AttributeComp)
		{
			AttributeComp->ApplyHealthChange(-20.0f);
			Destroy();
		}
	}
} 

// Sets default values
ASBProjectile::ASBProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	SphereComp->SetCollisionProfileName("Projectile");
	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &ASBProjectileMagic::OnActorOverlap);
	RootComponent = SphereComp;
	
	MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComp");
	MovementComp->InitialSpeed = 1000.0f;
	MovementComp->bRotationFollowsVelocity = true;
	MovementComp->bInitialVelocityInLocalSpace = true;
	MovementComp->ProjectileGravityScale = 0.0f;
}

// Called when the game starts or when spawned
void ASBProjectile::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASBProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

