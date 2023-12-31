// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SBExplosiveObject.generated.h"

class URadialForceComponent;

UCLASS()
class ACTIONROGUELIKE_API ASBExplosiveObject : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ASBExplosiveObject();

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Mesh")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Reactivity")
	URadialForceComponent* RadialForceComponent;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void ExplodeOnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& HitResult);

	UFUNCTION(BlueprintCallable)
	void Explode() const;
};
