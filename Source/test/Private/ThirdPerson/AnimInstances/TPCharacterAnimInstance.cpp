// © 2025 1nvoker - MIT License


#include "ThirdPerson/AnimInstances/TPCharacterAnimInstance.h"
#include "ThirdPerson/Characters/TPBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UTPCharacterAnimInstance::NativeInitializeAnimation()
{
	OwningCharacter = Cast<ATPBaseCharacter>(TryGetPawnOwner());

	if (OwningCharacter)
	{
		OwningMovementComponent = OwningCharacter->GetCharacterMovement();
	}
}

void UTPCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if (!OwningCharacter && !OwningMovementComponent)
	{
		return;
	}

	GroundSpeed = OwningCharacter->GetVelocity().Size2D();
	bHasAcceleration = OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D()>0.f;
}