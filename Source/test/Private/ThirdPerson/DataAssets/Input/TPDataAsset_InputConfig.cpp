// © 2025 1nvoker - MIT License


#include "ThirdPerson/DataAssets/Input/TPDataAsset_InputConfig.h"

UInputAction* UTPDataAsset_InputConfig::FindNativeInputActionByTag(const FGameplayTag& InInputTag) const
{
	for(const FTPInputActionConfig& InputActionConfig : NativeInputActions)
	{
		if (InputActionConfig.InputTag == InInputTag && InputActionConfig.InputAction)
		{
			return InputActionConfig.InputAction;
		}
	}

	return nullptr;
}