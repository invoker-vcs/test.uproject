// © 2025 1nvoker - MIT License

#pragma once

#include "CoreMinimal.h"
#include "ThirdPerson/AnimInstances/TPBaseAnimInstance.h"
#include "TPHeroLinkedAnimLayer.generated.h"

class UTPHeroAnimInstance;

/**
 *
 */
UCLASS()
class TEST_API UTPHeroLinkedAnimLayer : public UTPBaseAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta=(BlueprintThreadSafe))
	UTPHeroAnimInstance* GetHeroAnimInstance() const;

};
