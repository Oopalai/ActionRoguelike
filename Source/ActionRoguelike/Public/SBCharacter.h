// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SBCharacter.generated.h"

class USBAttributeComponent;
class USBInteractionComponent;
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
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	USpringArmComponent* SpringArmComp;
	
	/** Camera component added in Lecture 2.3. Used by the SpringArmComp.*/
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	UCameraComponent* CameraComp; 
	
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USBInteractionComponent* InteractionComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USBAttributeComponent* AttributeComp;

#pragma region "Input/Output Actions"
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

	/** The primary interact interaction*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* PrimaryInteractAction;
	
	/** The primary attack action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* PrimaryAttackAction;

	/** The secondary attack action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* SecondaryAttackAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* TeleportAction;
#pragma endregion
	
protected:
	UPROPERTY(EditAnywhere, Category = Attack)
	TSubclassOf<AActor> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = Attack)
	TSubclassOf<AActor> SecondaryProjectileClass;

	UPROPERTY(EditAnywhere, Category = Attack)
	TSubclassOf<AActor> TeleportProjectileClass;
	
	UPROPERTY(EditAnywhere, Category = Attack)
	UAnimMontage* AttackAnimation;

	UPROPERTY(EditAnywhere, Category = Attack)
	float FAttackDelay;

	FTimerHandle TimerHandle_PrimaryAttack;
	FTimerHandle TimerHandle_SecondaryAttack;
	FTimerHandle TimerHandle_Teleport;
	
public:
	// Sets default values for this character's properties
	ASBCharacter();

protected:
	/** Moves the character. Called by the MoveAction function.*/
	void Move(const FInputActionValue& Value);

	/** Makes the character look around. Called by the LookAction function.*/
	void Look(const FInputActionValue& Value);

	/** Makes the character jump, called by the Jump Action.*/
	virtual void Jump() override;
	
	/** Performs the primary attack action of the character. */
	void PrimaryAttack();

	void PrimaryAttack_TimeElapse();

	/** Performs the secondary attack action */
	void SecondaryAttack();

	void SecondaryAttack_TimeElapse();

	void Teleport();

	void Teleport_TimeElapsed();
	
	void PrimaryInteract();
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
};
