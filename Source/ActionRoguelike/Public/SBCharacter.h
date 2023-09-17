// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SBCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class ACTIONROGUELIKE_API ASBCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASBCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	
	/**
	 * Spring Arm component added in Lecture 2.3. Used for the 3rd person camera.
	 */
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	
	/**
	 * Camera component added in Lecture 2.3. Used by the SpringArmComp.
	 */
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;
};
