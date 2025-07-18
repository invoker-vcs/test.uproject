// © 2025 1nvoker - MIT License

#pragma once

#include "CoreMinimal.h"
#include "ThirdPerson/AnimInstances/TPBaseAnimInstance.h"
#include "TPCharacterAnimInstance.generated.h"

class ATPBaseCharacter;
class UCharacterMovementComponent;

/**
 *
 */
UCLASS()
class TEST_API UTPCharacterAnimInstance : public UTPBaseAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY()
	ATPBaseCharacter* OwningCharacter;

	UPROPERTY()
	UCharacterMovementComponent* OwningMovementComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimData|LocomotionData")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimData|LocomotionData")
	bool bHasAcceleration;
};
