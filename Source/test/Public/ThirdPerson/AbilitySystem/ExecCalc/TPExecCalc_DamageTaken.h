// © 2025 1nvoker - MIT License

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "TPExecCalc_DamageTaken.generated.h"

/**
 *
 */
UCLASS()
class TEST_API UTPExecCalc_DamageTaken : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()

public:
	UTPExecCalc_DamageTaken();

	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;



};
