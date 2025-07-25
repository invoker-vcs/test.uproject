// © 2025 1nvoker - MIT License


#include "ThirdPerson/AbilitySystem/Abilities/TPBaseGameplayAbility.h"
#include "ThirdPerson/AbilitySystem/TPAbilitySystemComponent.h"
#include "ThirdPerson/Components/Combat/TPPawnCombatComponent.h"
#include "AbilitySystemBlueprintLibrary.h"

void UTPBaseGameplayAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	if (AbilityActivationPolicy == ETPAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo && !Spec.IsActive())
		{
			ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
		}
	}
}

void UTPBaseGameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo *ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	if (AbilityActivationPolicy == ETPAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo)
		{
			ActorInfo->AbilitySystemComponent->ClearAbility(Handle);
		}
	}
}

UTPPawnCombatComponent* UTPBaseGameplayAbility::GetPawnCombatComponentFromActorInfo()
{
	return GetAvatarActorFromActorInfo()->FindComponentByClass<UTPPawnCombatComponent>();
}

UTPAbilitySystemComponent* UTPBaseGameplayAbility::GetTPAbilitySystemComponentFromActorInfo()
{
	return Cast<UTPAbilitySystemComponent>(CurrentActorInfo->AbilitySystemComponent);
}

FActiveGameplayEffectHandle UTPBaseGameplayAbility::NativeApplyEffectSpecHandleToTarget(AActor* TargetActor, const FGameplayEffectSpecHandle& InSpecHandle)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	check(TargetASC && InSpecHandle.IsValid());

	return GetTPAbilitySystemComponentFromActorInfo()->ApplyGameplayEffectSpecToTarget(*InSpecHandle.Data, TargetASC);
}

FActiveGameplayEffectHandle UTPBaseGameplayAbility::BP_ApplyEffectSpecHandleToTarget(AActor* TargetActor, const FGameplayEffectSpecHandle& InSpecHandle, ETPSuccessType& OutSuccessType)
{
	FActiveGameplayEffectHandle ActiveGameplayEffectHandle = NativeApplyEffectSpecHandleToTarget(TargetActor, InSpecHandle);

	OutSuccessType = ActiveGameplayEffectHandle.WasSuccessfullyApplied() ? ETPSuccessType::Successful : ETPSuccessType::Failed;

	return ActiveGameplayEffectHandle;
}