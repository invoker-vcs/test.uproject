// © 2025 1nvoker - MIT License


#include "ThirdPerson/Widgets/TPBaseWidget.h"
#include "ThirdPerson/Interfaces/TPPawnUIInterface.h"

void UTPBaseWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (ITPPawnUIInterface* PawnUIInterface = Cast<ITPPawnUIInterface>(GetOwningPlayerPawn()))
	{
		if (UTPHeroUIComponent* HeroUIComponent = PawnUIInterface->GetHeroUIComponent())
		{
			BP_OnOwningHeroUIComponentInitialized(HeroUIComponent);
		}
	}
}

void UTPBaseWidget::InitEnemyCreatedWidget(AActor* OwningEnemyActor)
{
	if (ITPPawnUIInterface* PawnUIInterface = Cast<ITPPawnUIInterface>(OwningEnemyActor))
	{
		UTPEnemyUIComponent* EnemyUIComponent = PawnUIInterface->GetEnemyUIComponent();
		checkf(EnemyUIComponent, TEXT("Failed to extract an EnemyUIComponent from %s"), *OwningEnemyActor->GetActorNameOrLabel());

		BP_OnOwningEnemyUIComponentInitialized(EnemyUIComponent);
	}
}