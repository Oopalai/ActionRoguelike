// Fill out your copyright notice in the Description page of Project Settings.


#include "SBExplosiveObject.h"

#include "PhysicsEngine/RadialForceComponent.h"

void ASBExplosiveObject::ExplodeOnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
                                      UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& HitResult)
{
	RadialForceComponent->FireImpulse();
}

// Sets default values
ASBExplosiveObject::ASBExplosiveObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("ObjectMesh");
	MeshComponent->SetSimulatePhysics(true);
	MeshComponent->SetCollisionProfileName("PhysicsActor");
	RootComponent = MeshComponent;

	RadialForceComponent = CreateDefaultSubobject<URadialForceComponent>("RadialForceComp");
	RadialForceComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ASBExplosiveObject::BeginPlay()
{
	Super::BeginPlay();
	MeshComponent->OnComponentHit.AddDynamic(this, &ASBExplosiveObject::ExplodeOnHit);
}

// Called every frame
void ASBExplosiveObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

