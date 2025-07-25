// © 2025 1nvoker - MIT License


#include "ThirdPerson/Components/Combat/TPPawnCombatComponent.h"
#include "ThirdPerson/Items/Weapons/TPBaseWeapon.h"
#include "Components/BoxComponent.h"

#include "ThirdPerson/TPDebugHelper.h"

void UTPPawnCombatComponent::RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, ATPBaseWeapon* InWeaponToRegister, bool bRegisterAsEquippedWeapon)
{
	checkf(!CharacterCarriedWeaponMap.Contains(InWeaponTagToRegister), TEXT("A Tag named %s has already been added as carried weapon"), *InWeaponTagToRegister.ToString());
	check(InWeaponToRegister);

	CharacterCarriedWeaponMap.Emplace(InWeaponTagToRegister, InWeaponToRegister);

	InWeaponToRegister->OnWeaponHitTarget.BindUObject(this, &ThisClass::OnHitTargetActor);
	InWeaponToRegister->OnWeaponPulledFromTarget.BindUObject(this, &ThisClass::OnWeaponPulledFromTargetActor);

	if (bRegisterAsEquippedWeapon)
	{
		CurrentEquippedWeaponTag  = InWeaponTagToRegister;
	}

	/*
	const FString WeaponString = FString::Printf(TEXT("A weapon named: %s has been registered using the tag %s"), *InWeaponToRegister->GetName(), *InWeaponTagToRegister.ToString());
	Debug::Print(WeaponString);
	*/
}

ATPBaseWeapon* UTPPawnCombatComponent::GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const
{
	if (CharacterCarriedWeaponMap.Contains(InWeaponTagToGet))
	{
		if (ATPBaseWeapon* const* FoundWeapon = CharacterCarriedWeaponMap.Find(InWeaponTagToGet))
		{
			return *FoundWeapon;
		}
	}

	return nullptr;
}

ATPBaseWeapon* UTPPawnCombatComponent::GetCharacterCurrentEquippedWeapon() const
{
	if (!CurrentEquippedWeaponTag.IsValid())
	{
		return nullptr;
	}

	return GetCharacterCarriedWeaponByTag(CurrentEquippedWeaponTag);
}

void UTPPawnCombatComponent::ToggleWeaponCollision(bool bShouldEnable, EToggleDamageType ToggleDamageType)
{
	if (ToggleDamageType == EToggleDamageType::CurrentEquippedWeapon)
	{
		ATPBaseWeapon* WeaponToToggle = GetCharacterCurrentEquippedWeapon();

		check(WeaponToToggle);

		if (bShouldEnable)
		{
			WeaponToToggle->GetWeaponCollisionBox()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
			// Debug::Print(WeaponToToggle->GetName() + TEXT("Collision Enabled"), FColor::Green);
		}
		else
		{
			WeaponToToggle->GetWeaponCollisionBox()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			// Debug::Print(WeaponToToggle->GetName() + TEXT("Collision Disabled"), FColor::Red);

			OverlappedActors.Empty();
		}
	}

	// TODO : Handle body collision boxes
}

void UTPPawnCombatComponent::OnHitTargetActor(AActor* HitActor)
{

}

void UTPPawnCombatComponent::OnWeaponPulledFromTargetActor(AActor* InteractedActor)
{

}