// Fill out your copyright notice in the Description page of Project Settings.

#include "SBCharacter.h"

#include "Kismet/KismetMathLibrary.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "SBInteractionComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ASBCharacter::ASBCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->SetupAttachment(RootComponent);
	
	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComp->SetupAttachment(SpringArmComp);

	InteractionComp = CreateDefaultSubobject<USBInteractionComponent>("InteractionComp");
	
	GetCharacterMovement()->bOrientRotationToMovement = true;
	
	bUseControllerRotationYaw = false;
	FAttackDelay = 0.2f;
}

void ASBCharacter::Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller)
	{
		FRotator ControlRotation = GetControlRotation();
		ControlRotation.Roll = 0;
		ControlRotation.Pitch = 0;
		
		AddMovementInput(ControlRotation.Vector(), MovementVector.X);

		//The right movement uses the Rotation Matrix to get the vector pointing right using the GetScaledAxis on the Y. 
		AddMovementInput(FRotationMatrix(ControlRotation).GetScaledAxis(EAxis::Y), MovementVector.Y);
	}
}

void ASBCharacter::Look(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller)
	{
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y );
	}
}

void ASBCharacter::Jump()
{
	Super::Jump();
}

// Called when the game starts or when spawned
void ASBCharacter::BeginPlay()
{
	Super::BeginPlay();

	//Add the input mapping context.
	if (const APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

// Called every frame
void ASBCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASBCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent); // TODO: Is this needed?

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		//Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ASBCharacter::Look);
		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASBCharacter::Move);
		//Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ASBCharacter::Jump);
		//Attacking
		EnhancedInputComponent->BindAction(PrimaryAttackAction, ETriggerEvent::Triggered, this, &ASBCharacter::PrimaryAttack);
		//Primary Interaction
		EnhancedInputComponent->BindAction(PrimaryInteractAction, ETriggerEvent::Triggered, this, &ASBCharacter::PrimaryInteract);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("'%s' Failed to find an Enhanced Input Component. This character is not set up to use legacy inputs."), *GetNameSafe(this));
	}
}

void ASBCharacter::PrimaryAttack()
{
	//Play the attack animation.
	PlayAnimMontage(AttackAnimation);

	//HACK: This should be redone to use Animation Notifiers once we learn about them. 
	GetWorldTimerManager().SetTimer(TimerHandle_PrimaryAttack, this, &ASBCharacter::PrimaryAttack_TimeElapse, FAttackDelay);
}

void ASBCharacter::PrimaryAttack_TimeElapse()
{
	const FVector HandLoc = GetMesh()->GetSocketLocation("Muzzle_01");
	FHitResult HitR;
	GetWorld()->LineTraceSingleByProfile(HitR, CameraComp->GetComponentLocation(), CameraComp->GetComponentLocation() + CameraComp->GetForwardVector()*1250, "Projectile");
	FRotator ProjRotation =	UKismetMathLibrary::FindLookAtRotation(HandLoc, HitR.IsValidBlockingHit() ? HitR.ImpactPoint : HitR.TraceEnd);
	
	const FTransform SpawnT = FTransform(ProjRotation, HandLoc);

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnParams.Instigator = this;

	GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnT, SpawnParams);
}

void ASBCharacter::PrimaryInteract()
{
	//The 'If' check here is not particularly necessary and could be optimized out. 
	if (InteractionComp)
	{
		InteractionComp->PrimaryInteract();	
	}
}
