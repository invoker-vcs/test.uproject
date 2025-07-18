// © 2025 1nvoker - MIT License

#pragma once

#include "CoreMinimal.h"
#include "ThirdPerson/DataAssets/StartupData/TPDataAsset_BaseStartupData.h"
#include "ThirdPerson/Types/TPStructTypes.h"
#include "TPDataAsset_HeroStartupData.generated.h"

/**
 *
 */
UCLASS()
class TEST_API UTPDataAsset_HeroStartupData : public UTPDataAsset_BaseStartupData
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UTPAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1) override;

private:
	UPROPERTY(EditDefaultsOnly, Category="StartupData", meta=(TitleProperty="InputTag"))
	TArray<FTPHeroAbilitySet> HeroStartupAbilitySets;

};
