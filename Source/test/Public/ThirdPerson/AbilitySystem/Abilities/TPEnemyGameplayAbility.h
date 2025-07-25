// © 2025 1nvoker - MIT License

#pragma once

#include "CoreMinimal.h"
#include "ThirdPerson/AbilitySystem/Abilities/TPBaseGameplayAbility.h"
#include "TPEnemyGameplayAbility.generated.h"

class ATPEnemyCharacter;
class UTPEnemyCombatComponent;

/**
 *
 */
UCLASS()
class TEST_API UTPEnemyGameplayAbility : public UTPBaseGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="ThirdPerson|Ability")
	ATPEnemyCharacter* GetEnemyCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category="ThirdPerson|Ability")
	UTPEnemyCombatComponent* GetEnemyCombatComponentFromActorInfo();

private:
	TWeakObjectPtr<ATPEnemyCharacter> CachedTPEnemyCharacter;

};
