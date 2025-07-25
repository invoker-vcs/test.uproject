// © 2025 1nvoker - MIT License


#include "ThirdPerson/Components/Combat/TPHeroCombatComponent.h"
#include "ThirdPerson/Items/Weapons/TPHeroWeapon.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "ThirdPerson/TPGameplayTags.h"

#include "ThirdPerson/TPDebugHelper.h"

ATPHeroWeapon* UTPHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	return Cast<ATPHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}

ATPHeroWeapon* UTPHeroCombatComponent::GetHeroCurrentEquippedWeapon() const
{
	return Cast<ATPHeroWeapon>(GetCharacterCurrentEquippedWeapon());
}

float UTPHeroCombatComponent::GetHeroCurrentEquippedWeaponDamageAtLevel(float InLevel) const
{
	return GetHeroCurrentEquippedWeapon()->HeroWeaponData.WeaponBaseDamage.GetValueAtLevel(InLevel);
}

void UTPHeroCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	if (OverlappedActors.Contains(HitActor))
	{
		return;
	}

	// Debug::Print(GetOwningPawn()->GetActorNameOrLabel() + TEXT(" hit ") + HitActor->GetActorNameOrLabel(), FColor::Green);

	OverlappedActors.AddUnique(HitActor);

	FGameplayEventData Data;
	Data.Instigator = GetOwningPawn();
	Data.Target = HitActor;

	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetOwningPawn(), TPGameplayTags::Shared_Event_MeleeHit, Data);
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetOwningPawn(), TPGameplayTags::Player_Event_HitPause, FGameplayEventData());

}

void UTPHeroCombatComponent::OnWeaponPulledFromTargetActor(AActor* InteractedActor)
{
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetOwningPawn(), TPGameplayTags::Player_Event_HitPause, FGameplayEventData());
	// Debug::Print(GetOwningPawn()->GetActorNameOrLabel() + TEXT("'s weapon pulled from ") + InteractedActor->GetActorNameOrLabel(), FColor::Red);
}