// Fill out your copyright notice in the Description page of Project Settings.


#include "SBExplosiveObject.h"

#include "PhysicsEngine/RadialForceComponent.h"

void ASBExplosiveObject::ExplodeOnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
                                      UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& HitResult)
{
	Explode();
}

void ASBExplosiveObject::Explode() const
{
	UE_LOG(LogTemp, Log, TEXT("%s was hit at %f and exploded."), *GetNameSafe(this), GetWorld()->GetTimeSeconds())
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

	RadialForceComponent->SetAutoActivate(false);
	RadialForceComponent->Radius = 10.0f;
	RadialForceComponent->ForceStrength = 1.0f;
	RadialForceComponent->ImpulseStrength = 1.0f;
	RadialForceComponent->bImpulseVelChange = true;
	
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

