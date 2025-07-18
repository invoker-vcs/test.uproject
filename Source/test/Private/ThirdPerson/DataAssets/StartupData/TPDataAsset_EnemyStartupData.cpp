// © 2025 1nvoker - MIT License


#include "ThirdPerson/DataAssets/StartupData/TPDataAsset_EnemyStartupData.h"
#include "ThirdPerson/AbilitySystem/TPAbilitySystemComponent.h"
#include "ThirdPerson/AbilitySystem/Abilities/TPEnemyGameplayAbility.h"

void UTPDataAsset_EnemyStartupData::GiveToAbilitySystemComponent(UTPAbilitySystemComponent* InASCToGive, int32  ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

	if (!EnemyCombatAbilities.IsEmpty())
	{
		for (const TSubclassOf<UTPEnemyGameplayAbility>& AbilityClass : EnemyCombatAbilities)
		{
			if (!AbilityClass) continue;

			FGameplayAbilitySpec AbilitySpec(AbilityClass);
			AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
			AbilitySpec.Level = ApplyLevel;

			InASCToGive->GiveAbility(AbilitySpec);
		}
	}
}