// © 2025 1nvoker - MIT License

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TPDataAsset_BaseStartupData.generated.h"

class UTPBaseGameplayAbility;
class UTPAbilitySystemComponent;
class UGameplayEffect;

/**
 *
 */
UCLASS()
class TEST_API UTPDataAsset_BaseStartupData : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UTPAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);

protected:
	UPROPERTY(EditDefaultsOnly, Category="StartupData")
	TArray<TSubclassOf<UTPBaseGameplayAbility>> ActivateOnGivenAbilities;

	UPROPERTY(EditDefaultsOnly, Category="StartupData")
	TArray<TSubclassOf<UTPBaseGameplayAbility>> ReactiveAbilities;

	UPROPERTY(EditDefaultsOnly, Category="StartupData")
	TArray<TSubclassOf<UGameplayEffect>> StartupGameplayEffects;

	void GrantAbilities(const TArray<TSubclassOf<UTPBaseGameplayAbility>>& InAbilitiesToGive, UTPAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);





};
