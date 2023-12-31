// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SBInteractionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ACTIONROGUELIKE_API USBInteractionComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:
	// Sets default values for this component's properties
	USBInteractionComponent();

	UPROPERTY(EditAnywhere, Category = Debug)
	bool DebugVisualization;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void PrimaryInteract();		
};
