// © 2025 1nvoker - MIT License


#include "ThirdPerson/Interfaces/TPPawnUIInterface.h"

// Add default functionality here for any ITPPawnUIInterface functions that are not pure virtual.
UTPHeroUIComponent* ITPPawnUIInterface::GetHeroUIComponent() const
{
	return nullptr;
}

UTPEnemyUIComponent* ITPPawnUIInterface::GetEnemyUIComponent() const
{
	return nullptr;
}