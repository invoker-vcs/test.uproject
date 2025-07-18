// © 2025 1nvoker - MIT License

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TPPawnCombatInterface.generated.h"

class UTPPawnCombatComponent;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UTPPawnCombatInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 *
 */
class TEST_API ITPPawnCombatInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual UTPPawnCombatComponent* GetPawnCombatComponent() const = 0;
};
