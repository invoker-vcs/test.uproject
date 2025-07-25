// © 2025 1nvoker - MIT License

#pragma once

#include "CoreMinimal.h"
#include "ThirdPerson/Components/TPBasePawnExtensionComponent.h"
#include "GameplayTagContainer.h"
#include "TPPawnCombatComponent.generated.h"

UENUM(BlueprintType)
enum class EToggleDamageType : uint8
{
	CurrentEquippedWeapon,
	LeftHand,
	RightHand
};

class ATPBaseWeapon;

/**
 *
 */
UCLASS()
class TEST_API UTPPawnCombatComponent : public UTPBasePawnExtensionComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="ThirdPerson|Combat")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, ATPBaseWeapon* InWeaponToRegister, bool bRegisterAsEquippedWeapon = false);

	UFUNCTION(BlueprintCallable, Category="ThirdPerson|Combat")
	ATPBaseWeapon* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;

	UPROPERTY(BlueprintReadWrite, Category="ThirdPerson|Combat")
	FGameplayTag CurrentEquippedWeaponTag;

	UFUNCTION(BlueprintCallable, Category="ThirdPerson|Combat")
	ATPBaseWeapon* GetCharacterCurrentEquippedWeapon() const;

	UFUNCTION(BlueprintCallable, Category="ThirdPerson|Combat")
	void ToggleWeaponCollision(bool bShouldEnable, EToggleDamageType ToggleDamageType = EToggleDamageType::CurrentEquippedWeapon);

	virtual void OnHitTargetActor(AActor* HitActor);
	virtual void OnWeaponPulledFromTargetActor(AActor* InteractedActor);

protected:
	TArray<AActor*> OverlappedActors;

private:
	TMap<FGameplayTag, ATPBaseWeapon*> CharacterCarriedWeaponMap;

};
