// © 2025 1nvoker - MIT License


#include "ThirdPerson/TPFunctionLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "ThirdPerson/AbilitySystem/TPAbilitySystemComponent.h"
#include "ThirdPerson/Interfaces/TPPawnCombatInterface.h"

UTPAbilitySystemComponent* UTPFunctionLibrary::NativeGetTPASCFromActor(AActor* InActor)
{
	check(InActor);

	return CastChecked<UTPAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
}

void UTPFunctionLibrary::AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd)
{
	UTPAbilitySystemComponent* ASC = NativeGetTPASCFromActor(InActor);

	if (!ASC->HasMatchingGameplayTag(TagToAdd))
	{
		ASC->AddLooseGameplayTag(TagToAdd);
	}
}

void UTPFunctionLibrary::RemoveGameplayTagFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove)
{
	UTPAbilitySystemComponent *ASC = NativeGetTPASCFromActor(InActor);

	if (ASC->HasMatchingGameplayTag(TagToRemove))
	{
		ASC->RemoveLooseGameplayTag(TagToRemove);
	}
}

bool UTPFunctionLibrary::NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck)
{
	UTPAbilitySystemComponent *ASC = NativeGetTPASCFromActor(InActor);

	return ASC->HasMatchingGameplayTag(TagToCheck);
}

void UTPFunctionLibrary::BP_DoesActorHaveTag(AActor *InActor, FGameplayTag TagToCheck, ETPConfirmType &OutConfirmType)
{
	OutConfirmType = NativeDoesActorHaveTag(InActor, TagToCheck) ? ETPConfirmType::Yes : ETPConfirmType::No;
}

UTPPawnCombatComponent* UTPFunctionLibrary::NativeGetPawnCombatComponentFromActor(AActor* InActor)
{
	check(InActor);

	if (ITPPawnCombatInterface* PawnCombatInterface = Cast<ITPPawnCombatInterface>(InActor))
	{
		return PawnCombatInterface->GetPawnCombatComponent();
	}

	return nullptr;
}

UTPPawnCombatComponent* UTPFunctionLibrary::BP_GetPawnCombatComponentFromActor(AActor* InActor, ETPValidType& OutValidType)
{
	UTPPawnCombatComponent* CombatComponent = NativeGetPawnCombatComponentFromActor(InActor);

	OutValidType = CombatComponent ? ETPValidType::Valid : ETPValidType::InValid;

	return CombatComponent;
}