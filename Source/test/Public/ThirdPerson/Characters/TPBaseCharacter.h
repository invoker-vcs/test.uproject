// © 2025 1nvoker - MIT License

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "ThirdPerson/Interfaces/TPPawnCombatInterface.h"
#include "ThirdPerson/Interfaces/TPPawnUIInterface.h"
#include "TPBaseCharacter.generated.h"

class UTPAbilitySystemComponent;
class UTPAttributeSet;
class UTPDataAsset_BaseStartupData;

UCLASS()
class TEST_API ATPBaseCharacter : public ACharacter, public IAbilitySystemInterface, public ITPPawnCombatInterface, public ITPPawnUIInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATPBaseCharacter();

	// Begin IAbilitySystemInterface Interface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	// End IAbilitySystemInterface Interface

	// Begin ITPPawnCombatInterface Interface
	virtual UTPPawnCombatComponent* GetPawnCombatComponent() const override;
	// End ITPPawnCombatInterface Interface

	// Begin ITPPawnUIInterface Interface
	virtual UTPPawnUIComponent* GetPawnUIComponent() const override;
	// End ITPPawnUIInterface Interface

protected:
	// Begin APawn Interface
	virtual void PossessedBy(AController* NewController) override;
	// End APawn Interface

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AbilitySystem")
	UTPAbilitySystemComponent* TPAbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AbilitySystem")
	UTPAttributeSet* TPAttributeSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CharacterData")
	TSoftObjectPtr<UTPDataAsset_BaseStartupData> CharacterStartupData;

public:
	FORCEINLINE	UTPAbilitySystemComponent* GetTPAbilitySystemComponent() const { return TPAbilitySystemComponent; }
	FORCEINLINE UTPAttributeSet* GetTPAttributeSet() const { return TPAttributeSet; }


};
