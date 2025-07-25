// © 2025 1nvoker - MIT License

#pragma once

#include "CoreMinimal.h"
#include "ThirdPerson/AbilitySystem/Abilities/TPBaseGameplayAbility.h"
#include "TPHeroGameplayAbility.generated.h"

class ATPHeroCharacter;
class ATPHeroController;

/**
 *
 */
UCLASS()
class TEST_API UTPHeroGameplayAbility : public UTPBaseGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="ThirdPerson|Ability")
	ATPHeroCharacter* GetHeroCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category="ThirdPerson|Ability")
	ATPHeroController* GetHeroControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category="ThirdPerson|Ability")
	UTPHeroCombatComponent* GetHeroCombatComponentFromActorInfo();

	UFUNCTION(BlueprintPure, Category="ThirdPerson|Ability")
	FGameplayEffectSpecHandle MakeHeroDamageEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass, float InWeaponBaseDamage, FGameplayTag InCurrentAttackTypeTag, int32 InUsedComboCount);

private:
	TWeakObjectPtr<ATPHeroCharacter> CachedTPHeroCharacter;
	TWeakObjectPtr<ATPHeroController> CachedTPHeroController;



};
