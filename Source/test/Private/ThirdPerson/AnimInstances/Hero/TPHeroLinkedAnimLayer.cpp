// © 2025 1nvoker - MIT License


#include "ThirdPerson/AnimInstances/Hero/TPHeroLinkedAnimLayer.h"
#include "ThirdPerson/AnimInstances/Hero/TPHeroAnimInstance.h"

UTPHeroAnimInstance* UTPHeroLinkedAnimLayer::GetHeroAnimInstance() const
{
	return Cast<UTPHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());
}