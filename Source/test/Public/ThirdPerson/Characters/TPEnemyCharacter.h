// © 2025 1nvoker - MIT License

#pragma once

#include "CoreMinimal.h"
#include "ThirdPerson/Characters/TPBaseCharacter.h"
#include "TPEnemyCharacter.generated.h"

class UTPEnemyCombatComponent;

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

protected:
	// Begin APawn Interface
	virtual void PossessedBy(AController* NewController) override;
	// End APawn Interface

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Combat")
	UTPEnemyCombatComponent* EnemyCombatComponent;

private:
	void InitEnemyStartupData();

public:
	FORCEINLINE	UTPEnemyCombatComponent* GetEnemyCombatComponent() const { return EnemyCombatComponent; }


};
