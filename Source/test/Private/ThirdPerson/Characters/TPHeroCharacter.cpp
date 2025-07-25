// © 2025 1nvoker - MIT License


#include "ThirdPerson/Characters/TPHeroCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputSubsystems.h"
#include "ThirdPerson/DataAssets/Input/TPDataAsset_InputConfig.h"
#include "ThirdPerson/Components/Input/TPInputComponent.h"
#include "ThirdPerson/TPGameplayTags.h"
#include "ThirdPerson/AbilitySystem/TPAbilitySystemComponent.h"
#include "ThirdPerson/DataAssets/StartupData/TPDataAsset_HeroStartupData.h"
#include "ThirdPerson/Components/Combat/TPHeroCombatComponent.h"
#include "ThirdPerson/Components/UI/TPHeroUIComponent.h"

#include "ThirdPerson/TPDebugHelper.h"

ATPHeroCharacter::ATPHeroCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CamerBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 200.f;
	CameraBoom->SocketOffset = FVector(0.f, 55.f, 65.f);
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation =false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	HeroCombatComponent = CreateDefaultSubobject<UTPHeroCombatComponent>(TEXT("HeroCombatComponent"));
	HeroUIComponent = CreateDefaultSubobject<UTPHeroUIComponent>(TEXT("HeroUIComponent"));
}

UTPPawnCombatComponent* ATPHeroCharacter::GetPawnCombatComponent() const
{
	return HeroCombatComponent;
}

UTPPawnUIComponent* ATPHeroCharacter::GetPawnUIComponent() const
{
	return HeroUIComponent;
}

UTPHeroUIComponent* ATPHeroCharacter::GetHeroUIComponent() const
{
	return HeroUIComponent;
}

void ATPHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (!CharacterStartupData.IsNull())
	{
		if (UTPDataAsset_BaseStartupData* LoadedData = CharacterStartupData.LoadSynchronous())
		{
			LoadedData->GiveToAbilitySystemComponent(TPAbilitySystemComponent);
		}
	}

	/*
	if (TPAbilitySystemComponent && TPAttributeSet)
	{
		const FString ASCText = FString::Printf(TEXT("Owner Actor: %s, Avatar Actor: %s"), *TPAbilitySystemComponent->GetOwnerActor()->GetActorLabel(), *TPAbilitySystemComponent->GetAvatarActor()->GetActorLabel());

		Debug::Print(TEXT("Ability system component valid. ") + ASCText, FColor::Green);
		Debug::Print(TEXT("Attribute Set valid. "), FColor::Green);

	}
	*/
}

void ATPHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	checkf(InputConfigDataAsset, TEXT("Forgot to assign a valid data asset as input config"))

	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

	check(Subsystem);

	Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);

	UTPInputComponent* TPInputComponent = CastChecked<UTPInputComponent>(PlayerInputComponent);

	TPInputComponent->BindNativeInputAction(InputConfigDataAsset, TPGameplayTags::InputTag_Move, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
	TPInputComponent->BindNativeInputAction(InputConfigDataAsset, TPGameplayTags::InputTag_Look, ETriggerEvent::Triggered, this, &ThisClass::Input_Look);

	TPInputComponent->BindAbilityInputAction(InputConfigDataAsset, this, &ThisClass::Input_AbilityInputPressed, &ThisClass::Input_AbilityInputReleased);
}

void ATPHeroCharacter::BeginPlay()
{
	Super::BeginPlay();

}

void ATPHeroCharacter::Input_Move(const FInputActionValue& InputActionValue)
{
	const FVector2D MovementVector = InputActionValue.Get<FVector2D>();
	const FRotator MovementRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);

	if (MovementVector.Y != 0.f)
	{
		const FVector ForwardDirection = MovementRotation.RotateVector(FVector::ForwardVector);
		AddMovementInput(ForwardDirection, MovementVector.Y);
	}

	if (MovementVector.X != 0.f)
	{
		const FVector RightDirection = MovementRotation.RotateVector(FVector::RightVector);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ATPHeroCharacter::Input_Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();

	if (LookAxisVector.X != 0.f)
	{
		AddControllerYawInput(LookAxisVector.X);
	}

	if (LookAxisVector.Y != 0.f)
	{
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ATPHeroCharacter::Input_AbilityInputPressed(FGameplayTag InInputTag)
{
	TPAbilitySystemComponent->OnAbilityInputPressed(InInputTag);
}

void ATPHeroCharacter::Input_AbilityInputReleased(FGameplayTag InInputTag)
{
	TPAbilitySystemComponent->OnAbilityInputReleased(InInputTag);
}