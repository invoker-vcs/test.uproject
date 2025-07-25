// © 2025 1nvoker - MIT License

#pragma once

#include "CoreMinimal.h"
#include "ThirdPerson/Components/UI/TPPawnUIComponent.h"
#include "TPHeroUIComponent.generated.h"

/**
 *
 */
UCLASS()
class TEST_API UTPHeroUIComponent : public UTPPawnUIComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnPercentChangedDelegate OnCurrentRageChanged;

};
