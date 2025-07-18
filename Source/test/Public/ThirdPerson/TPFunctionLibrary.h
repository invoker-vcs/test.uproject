// © 2025 1nvoker - MIT License

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ThirdPerson/Types/TPEnumTypes.h"
#include "TPFunctionLibrary.generated.h"

class UTPAbilitySystemComponent;
class UTPPawnCombatComponent;

/**
 *
 */
UCLASS()
class TEST_API UTPFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static UTPAbilitySystemComponent* NativeGetTPASCFromActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category="ThirdPerson|FunctionLibrary")
	static void AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd);

	UFUNCTION(BlueprintCallable, Category="ThirdPerson|FunctionLibrary")
	static void RemoveGameplayTagFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove);

	static bool NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck);

	UFUNCTION(BlueprintCallable, Category="ThirdPerson|FunctionLibrary", meta=(DisplayName="Does Actor Have Tag", ExpandEnumAsExecs="OutConfirmType"))
	static void  BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, ETPConfirmType& OutConfirmType);

	static UTPPawnCombatComponent* NativeGetPawnCombatComponentFromActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category="ThirdPerson|FunctionLibrary", meta=(DisplayName="Get Pawn Combat Component From Actor", ExpandEnumAsExecs="OutValidType"))
	static UTPPawnCombatComponent* BP_GetPawnCombatComponentFromActor(AActor* InActor, ETPValidType& OutValidType);

};
