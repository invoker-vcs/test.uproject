// © 2025 1nvoker - MIT License

#pragma once

#include "CoreMinimal.h"
#include "ThirdPerson/Characters/TPBaseCharacter.h"
#include "TPEnemyCharacter.generated.h"

class UTPEnemyCombatComponent;
class UTPEnemyUIComponent;
class UWidgetComponent;

/**
 *
 */
UCLASS()
class TEST_API ATPEnemyCharacter : public ATPBaseCharacter
{
	GENERATED_BODY()

public:
	ATPEnemyCharacter();

	// Begin ITPPawnCombatInterface Interface
	virtual UTPPawnCombatComponent* GetPawnCombatComponent() const override;
	// End ITPPawnCombatInterface Interface

	// Begin ITPPawnUIInterface Interface
	virtual UTPPawnUIComponent* GetPawnUIComponent() const override;
	virtual UTPEnemyUIComponent* GetEnemyUIComponent() const override;
	// End ITPPawnUIInterface Interface

protected:
	virtual void BeginPlay() override;

	// Begin APawn Interface
	virtual void PossessedBy(AController* NewController) override;
	// End APawn Interface

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Combat")
	UTPEnemyCombatComponent* EnemyCombatComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="UI")
	UTPEnemyUIComponent* EnemyUIComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="UI")
	UWidgetComponent* EnemyHealthWidgetComponent;

private:
	void InitEnemyStartupData();

public:
	FORCEINLINE	UTPEnemyCombatComponent* GetEnemyCombatComponent() const { return EnemyCombatComponent; }


};
