// © 2025 1nvoker - MIT License


#include "ThirdPerson/DataAssets/StartupData/TPDataAsset_BaseStartupData.h"
#include "ThirdPerson/AbilitySystem/TPAbilitySystemComponent.h"
#include "ThirdPerson/AbilitySystem/Abilities/TPBaseGameplayAbility.h"

void UTPDataAsset_BaseStartupData::GiveToAbilitySystemComponent(UTPAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	check(InASCToGive);

	GrantAbilities(ActivateOnGivenAbilities, InASCToGive, ApplyLevel);
	GrantAbilities(ReactiveAbilities, InASCToGive, ApplyLevel);

	if (!StartupGameplayEffects.IsEmpty())
	{
		for (const TSubclassOf<UGameplayEffect>& EffectClass : StartupGameplayEffects)
		{
			if (!EffectClass) continue;

			UGameplayEffect* EffectCDO = EffectClass->GetDefaultObject<UGameplayEffect>();
			InASCToGive->ApplyGameplayEffectToSelf(EffectCDO, ApplyLevel, InASCToGive->MakeEffectContext());
		}
	}
}

void UTPDataAsset_BaseStartupData::GrantAbilities(const TArray<TSubclassOf<UTPBaseGameplayAbility>>& InAbilitiesToGive, UTPAbilitySystemComponent *InASCToGive, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty())
	{
		return;
	}

	for (const TSubclassOf<UTPBaseGameplayAbility>& Ability : InAbilitiesToGive)
	{
		if (!Ability) continue;

		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;

		InASCToGive->GiveAbility(AbilitySpec);
	}
}