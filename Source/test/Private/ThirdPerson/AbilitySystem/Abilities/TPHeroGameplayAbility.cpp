// © 2025 1nvoker - MIT License


#include "ThirdPerson/AbilitySystem/Abilities/TPHeroGameplayAbility.h"
#include "ThirdPerson/Characters/TPHeroCharacter.h"
#include "ThirdPerson/Controllers/TPHeroController.h"
#include "ThirdPerson/AbilitySystem/TPAbilitySystemComponent.h"
#include "ThirdPerson/TPGameplayTags.h"

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

FGameplayEffectSpecHandle UTPHeroGameplayAbility::MakeHeroDamageEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass, float InWeaponBaseDamage, FGameplayTag InCurrentAttackTypeTag, int32 InUsedComboCount)
{
	check(EffectClass);

	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponentFromActorInfo()->MakeEffectContext();
	ContextHandle.SetAbility(this);
	ContextHandle.AddSourceObject(GetAvatarActorFromActorInfo());
	ContextHandle.AddInstigator(GetAvatarActorFromActorInfo(), GetAvatarActorFromActorInfo());

	FGameplayEffectSpecHandle EffectSpecHandle = GetTPAbilitySystemComponentFromActorInfo()->MakeOutgoingSpec(EffectClass, GetAbilityLevel(), ContextHandle);
	EffectSpecHandle.Data->SetSetByCallerMagnitude(TPGameplayTags::Shared_SetByCaller_BaseDamage, InWeaponBaseDamage);

	if (InCurrentAttackTypeTag.IsValid())
	{
		EffectSpecHandle.Data->SetSetByCallerMagnitude(InCurrentAttackTypeTag, InUsedComboCount);
	}

	return EffectSpecHandle;
}