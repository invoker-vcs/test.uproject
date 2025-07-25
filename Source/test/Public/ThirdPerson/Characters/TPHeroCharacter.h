// © 2025 1nvoker - MIT License

#pragma once

#include "CoreMinimal.h"
#include "ThirdPerson/Characters/TPBaseCharacter.h"
#include "GameplayTagContainer.h"
#include "TPHeroCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UTPDataAsset_InputConfig;
struct FInputActionValue;
class UTPHeroCombatComponent;
class UTPHeroUIComponent;

/**
 *
 */
UCLASS()
class TEST_API ATPHeroCharacter : public ATPBaseCharacter
{
	GENERATED_BODY()

public:
	ATPHeroCharacter();

	// Begin ITPPawnCombatInterface Interface
	virtual UTPPawnCombatComponent* GetPawnCombatComponent() const override;
	// End ITPPawnCombatInterface Interface

protected:
	// Begin APawn Interface
	virtual void PossessedBy(AController* NewController) override;
	// End APawn Interface

	// Begin ITPPawnUIInterface Interface
	virtual UTPPawnUIComponent* GetPawnUIComponent() const override;
	virtual UTPHeroUIComponent* GetHeroUIComponent() const override;
	// End ITPPawnUIInterface Interface

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;

private:
	#pragma region Components
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera", meta=(AllowPrivateAccess="true"))
		USpringArmComponent* CameraBoom;

		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera", meta=(AllowPrivateAccess="true"))
		UCameraComponent* FollowCamera;

		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Combat", meta=(AllowPrivateAccess="true"))
		UTPHeroCombatComponent* HeroCombatComponent;

		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="UI", meta=(AllowPrivateAccess="true"))
		UTPHeroUIComponent* HeroUIComponent;
		#pragma endregion

	#pragma region Inputs
		UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CharacterData", meta=(AllowPrivateAccess="true"))
		UTPDataAsset_InputConfig* InputConfigDataAsset;

		void Input_Move(const FInputActionValue& InputActionValue);
		void Input_Look(const FInputActionValue& InputActionValue);

		void Input_AbilityInputPressed(FGameplayTag InInputTag);
		void Input_AbilityInputReleased(FGameplayTag InInputTag);
	#pragma endregion

public:
	FORCEINLINE UTPHeroCombatComponent* GetHeroCombatComponent() const { return HeroCombatComponent; }
};
