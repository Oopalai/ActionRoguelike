// Fill out your copyright notice in the Description page of Project Settings.


#include "SBInteractionComponent.h"
#include "SBGameplayInterface.h"

// Sets default values for this component's properties
USBInteractionComponent::USBInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	DebugVisualization = false;
	// ...
}


// Called when the game starts
void USBInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USBInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USBInteractionComponent::PrimaryInteract()
{
	TArray<FHitResult> Hits;
	
	FCollisionObjectQueryParams ObjectQueryParams;
	ObjectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);

	AActor* MyOwner = GetOwner();

	FVector EyeLocation;
	FRotator EyeRotation;
	MyOwner->GetActorEyesViewPoint(EyeLocation, EyeRotation);

	FVector End = EyeLocation + EyeRotation.Vector() * 250;

	float Radius = 45.0f;
	FCollisionShape Shape;
	Shape.SetSphere(Radius);
	
	bool bBlockingHit = GetWorld()->SweepMultiByObjectType(Hits,EyeLocation, End, FQuat::Identity, ObjectQueryParams, Shape);
	
	for (auto Hit : Hits)
	{
		if (AActor* HitActor = Hit.GetActor())
		{
			if (DebugVisualization)
			{
				DrawDebugSphere(GetWorld(), Hit.ImpactPoint, Radius, 32, FColor::Cyan);
			}
			if (HitActor->Implements<USBGameplayInterface>())
			{
				APawn* MyPawn = Cast<APawn>(MyOwner);
				ISBGameplayInterface::Execute_Interact(HitActor, MyPawn);

				break;
			}
		}
	}
	
	if (DebugVisualization)
	{
		FColor LineColor = bBlockingHit ? FColor::Cyan : FColor::Red;
		DrawDebugLine(GetWorld(), EyeLocation, End, LineColor, false, 2.0f, 0, 2.0f);
	}
}

