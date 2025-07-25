// © 2025 1nvoker - MIT License

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TPBaseWidget.generated.h"

class UTPHeroUIComponent;
class UTPEnemyUIComponent;

/**
 *
 */
UCLASS()
class TEST_API UTPBaseWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void InitEnemyCreatedWidget(AActor* OwningEnemyActor);

protected:
	virtual void NativeOnInitialized() override;

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Owning Hero UI Component Initialized"))
	void BP_OnOwningHeroUIComponentInitialized(UTPHeroUIComponent* OwningHeroUIComponent);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Owning Enemy UI Component Initialized"))
	void BP_OnOwningEnemyUIComponentInitialized(UTPEnemyUIComponent* OwningEnemyUIComponent);

};
