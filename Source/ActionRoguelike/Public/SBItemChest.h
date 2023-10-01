// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SBGameplayInterface.h"
#include "GameFramework/Actor.h"
#include "SBItemChest.generated.h"

UCLASS()
class ACTIONROGUELIKE_API ASBItemChest : public AActor, public ISBGameplayInterface
{
	GENERATED_BODY()

	virtual void Interact_Implementation(APawn* InstigatorPawn) override;
	
public:	
	// Sets default values for this actor's properties
	ASBItemChest();

	UPROPERTY(EditAnywhere)
	float TargetPitch;
		
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* LidMesh;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
