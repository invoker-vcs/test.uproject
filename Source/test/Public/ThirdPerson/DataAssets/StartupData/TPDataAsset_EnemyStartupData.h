// © 2025 1nvoker - MIT License

#pragma once

#include "CoreMinimal.h"
#include "ThirdPerson/DataAssets/StartupData/TPDataAsset_BaseStartupData.h"
#include "TPDataAsset_EnemyStartupData.generated.h"

class UTPEnemyGameplayAbility;

/**
 *
 */
UCLASS()
class TEST_API UTPDataAsset_EnemyStartupData : public UTPDataAsset_BaseStartupData
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UTPAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1) override;

private:
	UPROPERTY(EditDefaultsOnly, Category="StartupData")
	TArray<TSubclassOf<UTPEnemyGameplayAbility>> EnemyCombatAbilities;




};
