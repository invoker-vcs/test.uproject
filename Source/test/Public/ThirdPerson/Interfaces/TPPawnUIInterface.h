// © 2025 1nvoker - MIT License

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TPPawnUIInterface.generated.h"

class UTPPawnUIComponent;
class UTPHeroUIComponent;
class UTPEnemyUIComponent;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UTPPawnUIInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 *
 */
class TEST_API ITPPawnUIInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual UTPPawnUIComponent* GetPawnUIComponent() const = 0;

	virtual UTPHeroUIComponent* GetHeroUIComponent() const;

	virtual UTPEnemyUIComponent* GetEnemyUIComponent() const;


};
