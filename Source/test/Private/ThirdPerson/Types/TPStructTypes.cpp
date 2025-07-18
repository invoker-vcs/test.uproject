// © 2025 1nvoker - MIT License


#include "ThirdPerson/Types/TPStructTypes.h"
#include "ThirdPerson/AbilitySystem/Abilities/TPHeroGameplayAbility.h"

bool FTPHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}