// © 2025 1nvoker - MIT License


#include "ThirdPerson/AbilitySystem/Abilities/TPHeroGameplayAbility.h"
#include "ThirdPerson/Characters/TPHeroCharacter.h"
#include "ThirdPerson/Controllers/TPHeroController.h"

ATPHeroCharacter* UTPHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedTPHeroCharacter.IsValid())
	{
		CachedTPHeroCharacter = Cast<ATPHeroCharacter>(CurrentActorInfo->AvatarActor);
	}

	return CachedTPHeroCharacter.IsValid() ? CachedTPHeroCharacter.Get() : nullptr;
}

ATPHeroController* UTPHeroGameplayAbility::GetHeroControllerFromActorInfo()
{
	if (!CachedTPHeroController.IsValid())
	{
		CachedTPHeroController = Cast<ATPHeroController>(CurrentActorInfo->PlayerController);
	}

	return CachedTPHeroController.IsValid() ? CachedTPHeroController.Get() : nullptr;
}

UTPHeroCombatComponent* UTPHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}