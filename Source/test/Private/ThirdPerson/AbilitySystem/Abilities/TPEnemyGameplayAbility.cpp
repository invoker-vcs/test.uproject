// © 2025 1nvoker - MIT License


#include "ThirdPerson/AbilitySystem/Abilities/TPEnemyGameplayAbility.h"
#include "ThirdPerson/Characters/TPEnemyCharacter.h"

ATPEnemyCharacter* UTPEnemyGameplayAbility::GetEnemyCharacterFromActorInfo()
{
	if (!CachedTPEnemyCharacter.IsValid())
	{
		CachedTPEnemyCharacter = Cast<ATPEnemyCharacter>(CurrentActorInfo->AvatarActor);
	}

	return CachedTPEnemyCharacter.IsValid() ? CachedTPEnemyCharacter.Get() : nullptr;
}

UTPEnemyCombatComponent* UTPEnemyGameplayAbility::GetEnemyCombatComponentFromActorInfo()
{
	return GetEnemyCharacterFromActorInfo()->GetEnemyCombatComponent();
}