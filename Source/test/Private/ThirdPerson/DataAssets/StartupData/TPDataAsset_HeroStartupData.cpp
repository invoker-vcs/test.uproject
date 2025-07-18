// © 2025 1nvoker - MIT License


#include "ThirdPerson/DataAssets/StartupData/TPDataAsset_HeroStartupData.h"
#include "ThirdPerson/AbilitySystem/Abilities/TPBaseGameplayAbility.h"
#include "ThirdPerson/AbilitySystem/TPAbilitySystemComponent.h"

void UTPDataAsset_HeroStartupData::GiveToAbilitySystemComponent(UTPAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

	for (const FTPHeroAbilitySet& AbilitySet : HeroStartupAbilitySets)
	{
		if (!AbilitySet.IsValid()) continue;

		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.GetDynamicSpecSourceTags().AddTag(AbilitySet.InputTag);

		InASCToGive->GiveAbility(AbilitySpec);
	}
}