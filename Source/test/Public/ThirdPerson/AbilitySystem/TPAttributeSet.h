// © 2025 1nvoker - MIT License

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "ThirdPerson/AbilitySystem/TPAbilitySystemComponent.h"
#include "TPAttributeSet.generated.h"

class ITPPawnUIInterface;

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName) \

/**
 *
 */
UCLASS()
class TEST_API UTPAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UTPAttributeSet();

	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData &Data) override;

	UPROPERTY(BlueprintReadOnly, Category="Health")
	FGameplayAttributeData CurrentHealth;
	ATTRIBUTE_ACCESSORS(UTPAttributeSet, CurrentHealth)

	UPROPERTY(BlueprintReadOnly, Category="Health")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UTPAttributeSet, MaxHealth)

	UPROPERTY(BlueprintReadOnly, Category="Rage")
	FGameplayAttributeData CurrentRage;
	ATTRIBUTE_ACCESSORS(UTPAttributeSet, CurrentRage)

	UPROPERTY(BlueprintReadOnly, Category="Rage")
	FGameplayAttributeData MaxRage;
	ATTRIBUTE_ACCESSORS(UTPAttributeSet, MaxRage)

	UPROPERTY(BlueprintReadOnly, Category="Damage")
	FGameplayAttributeData AttackPower;
	ATTRIBUTE_ACCESSORS(UTPAttributeSet, AttackPower)

	UPROPERTY(BlueprintReadOnly, Category="Damage")
	FGameplayAttributeData DefensePower;
	ATTRIBUTE_ACCESSORS(UTPAttributeSet, DefensePower)

	UPROPERTY(BlueprintReadOnly, Category="Damage")
	FGameplayAttributeData DamageTaken;
	ATTRIBUTE_ACCESSORS(UTPAttributeSet, DamageTaken)

private:
	TWeakInterfacePtr<ITPPawnUIInterface> CachedPawnUIInterface;

};
