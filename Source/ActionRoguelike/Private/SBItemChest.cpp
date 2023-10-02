// Fill out your copyright notice in the Description page of Project Settings.


#include "SBItemChest.h"

void ASBItemChest::Interact_Implementation(APawn* InstigatorPawn)
{
	LidMesh->SetRelativeRotation(FRotator(TargetPitch, 0, 0));
}

// Sets default values
ASBItemChest::ASBItemChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	RootComponent = BaseMesh;

	LidMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LidMesh"));
	LidMesh->SetupAttachment(BaseMesh);

	TargetPitch = 110;
}

// Called when the game starts or when spawned
void ASBItemChest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASBItemChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

