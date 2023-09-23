// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SBCharacter.generated.h"

struct FInputActionValue;
class UCameraComponent;
class USpringArmComponent;
class UInputMappingContext;
class UInputAction;

UCLASS()
class ACTIONROGUELIKE_API ASBCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Spring Arm component added in Lecture 2.3. Used for the 3rd person camera.*/
	UPROPERTY(VisibleAnywhere, Category = Camera)
	USpringArmComponent* SpringArmComp;
	
	/** Camera component added in Lecture 2.3. Used by the SpringArmComp.*/
	UPROPERTY(VisibleAnywhere, Category = Camera)
	UCameraComponent* CameraComp;

	/** The default input mapping context for the character.*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;
	
	/** The move action. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** The rotate action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;
	
	/** The jump action.*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** The primary attack action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* PrimaryAttackAction;
	
protected:
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ProjectileClass;

public:
	// Sets default values for this character's properties
	ASBCharacter();

protected:
	/** Moves the character. Called by the MoveAction function.*/
	void Move(const FInputActionValue& Value);

	/** Makes the character look around. Called by the LookAction function.*/
	void Look(const FInputActionValue& Value);

	/** Performs the primary attack action of the character. */
	void PrimaryAttack();
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
