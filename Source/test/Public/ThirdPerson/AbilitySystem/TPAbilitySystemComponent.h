// © 2025 1nvoker - MIT License

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "ThirdPerson/Types/TPStructTypes.h"
#include "TPAbilitySystemComponent.generated.h"

/**
 *
 */
UCLASS()
class TEST_API UTPAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void OnAbilityInputPressed(const FGameplayTag& InInputTag);
	void OnAbilityInputReleased(const FGameplayTag& InInputTag);

	UFUNCTION(BlueprintCallable, Category="ThirdPerson|Ability", meta=(ApplyLevel="1"))
	void GrantHeroWeaponAbilities(const TArray<FTPHeroAbilitySet>& InDefaultWeaponAbilities, int32 ApplyLevel, TArray<FGameplayAbilitySpecHandle>& OutGrantedAbilitySpecHandle);

	UFUNCTION(BlueprintCallable, Category="ThirdPerson|Ability")
	void RemoveGrantedHeroWeaponAbilities(UPARAM(ref) TArray<FGameplayAbilitySpecHandle>& InSpecHandlesToRemove);



};
