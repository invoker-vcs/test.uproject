// © 2025 1nvoker - MIT License


#include "ThirdPerson/AbilitySystem/TPAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "ThirdPerson/TPFunctionLibrary.h"
#include "ThirdPerson/TPGameplayTags.h"
#include "ThirdPerson/Interfaces/TPPawnUIInterface.h"
#include "ThirdPerson/Components/UI/TPPawnUIComponent.h"
#include "ThirdPerson/Components/UI/TPHeroUIComponent.h"

#include "ThirdPerson/TPDebugHelper.h"

UTPAttributeSet::UTPAttributeSet()
{
	InitCurrentHealth(1.f);
	InitMaxHealth(1.f);
	InitCurrentRage(1.f);
	InitMaxRage(1.f);
	InitAttackPower(1.f);
	InitDefensePower(1.f);
}

void UTPAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	if (!CachedPawnUIInterface.IsValid())
	{
		CachedPawnUIInterface = TWeakInterfacePtr<ITPPawnUIInterface>(Data.Target.GetAvatarActor());
	}
	checkf(CachedPawnUIInterface.IsValid(), TEXT("%s didn't implement ITPPawnUIInterface"), *Data.Target.GetAvatarActor()->GetActorNameOrLabel());

	UTPPawnUIComponent* PawnUIComponent = CachedPawnUIInterface->GetPawnUIComponent();
	checkf(PawnUIComponent, TEXT("Couldn't extract a PawnUIComponent from %s"), *Data.Target.GetAvatarActor()->GetActorNameOrLabel());

	//* current health attribute
	if (Data.EvaluatedData.Attribute == GetCurrentHealthAttribute())
	{
		const float NewCurrentHealth = FMath::Clamp(GetCurrentHealth(), 0.f, GetMaxHealth());

		SetCurrentHealth(NewCurrentHealth);

		PawnUIComponent->OnCurrentHealthChanged.Broadcast(GetCurrentHealth()/GetMaxHealth());
	}

	//* current rage attribute
	if (Data.EvaluatedData.Attribute == GetCurrentRageAttribute())
	{
		const float NewCurrentRage = FMath::Clamp(GetCurrentRage(), 0.f, GetCurrentRage());

		SetCurrentRage(NewCurrentRage);

		if (UTPHeroUIComponent* HeroUIComponent = CachedPawnUIInterface->GetHeroUIComponent())
		{
			HeroUIComponent->OnCurrentRageChanged.Broadcast(GetCurrentRage()/GetMaxRage());
		}
	}

	//* damage taken attribute
	if (Data.EvaluatedData.Attribute == GetDamageTakenAttribute())
	{
		const float OldHealth = GetCurrentHealth();
		const float DamageDone = GetDamageTaken();

		const float NewCurrentHealth = FMath::Clamp(OldHealth - DamageDone, 0.f, GetMaxHealth());

		SetCurrentHealth(NewCurrentHealth);

		const FString DebugString = FString::Printf(TEXT("Old Health: %f, Damge Done: %f, NewCurrentHealth: %f"), OldHealth, DamageDone, NewCurrentHealth);
		Debug::Print(DebugString, FColor::Green);

		PawnUIComponent->OnCurrentHealthChanged.Broadcast(GetCurrentHealth()/GetMaxHealth());

		if (GetCurrentHealth() == 0.f)
		{
			UTPFunctionLibrary::AddGameplayTagToActorIfNone(Data.Target.GetAvatarActor(), TPGameplayTags::Shared_Status_Dead);
		}
	}

}
