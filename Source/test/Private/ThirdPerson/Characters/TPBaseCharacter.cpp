// © 2025 1nvoker - MIT License


#include "ThirdPerson/Characters/TPBaseCharacter.h"
#include "ThirdPerson/AbilitySystem/TPAbilitySystemComponent.h"
#include "ThirdPerson/AbilitySystem/TPAttributeSet.h"

ATPBaseCharacter::ATPBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

	TPAbilitySystemComponent = CreateDefaultSubobject<UTPAbilitySystemComponent>(TEXT("TPAbilitySystemComponent"));
	TPAttributeSet = CreateDefaultSubobject<UTPAttributeSet>(TEXT("TPAttributeSet"));

}

UAbilitySystemComponent* ATPBaseCharacter::GetAbilitySystemComponent() const
{
	return GetTPAbilitySystemComponent();
}

UTPPawnCombatComponent* ATPBaseCharacter::GetPawnCombatComponent() const
{
	return nullptr;
}

UTPPawnUIComponent* ATPBaseCharacter::GetPawnUIComponent() const
{
	return nullptr;
}

void ATPBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (TPAbilitySystemComponent)
	{
		TPAbilitySystemComponent->InitAbilityActorInfo(this, this);

		ensureMsgf(!CharacterStartupData.IsNull(), TEXT("Forgot to assign startup data to %s"), *GetName());
	}
}