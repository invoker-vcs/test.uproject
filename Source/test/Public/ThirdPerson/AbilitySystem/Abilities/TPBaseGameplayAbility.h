// © 2025 1nvoker - MIT License

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "TPBaseGameplayAbility.generated.h"

class UTPPawnCombatComponent;
class UTPAbilitySystemComponent;

UENUM(BlueprintType)
enum class ETPAbilityActivationPolicy : uint8
{
	OnTriggered,
	OnGiven
};

/**
 *
 */
UCLASS()
class TEST_API UTPBaseGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

protected:
	// Begin UGameplayAbility Interface
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	// End UGameplayAbility Interface

	UPROPERTY(EditDefaultsOnly, Category="ThirdPerson|Ability")
	ETPAbilityActivationPolicy AbilityActivationPolicy = ETPAbilityActivationPolicy::OnTriggered;

	UFUNCTION(BlueprintPure, Category="ThirdPerson|Ability")
	UTPPawnCombatComponent* GetPawnCombatComponentFromActorInfo();

	UFUNCTION(BlueprintPure, Category="ThirdPerson|Ability")
	UTPAbilitySystemComponent* GetTPAbilitySystemComponentFromActorInfo();


};
