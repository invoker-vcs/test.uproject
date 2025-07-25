// © 2025 1nvoker - MIT License


#include "ThirdPerson/Characters/TPEnemyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ThirdPerson/Components/Combat/TPEnemyCombatComponent.h"
#include "Engine/AssetManager.h"
#include "ThirdPerson/DataAssets/StartupData/TPDataAsset_EnemyStartupData.h"
#include "ThirdPerson/Components/UI/TPEnemyUIComponent.h"
#include "Components/WidgetComponent.h"
#include "ThirdPerson/Widgets/TPBaseWidget.h"

#include "ThirdPerson/TPDebugHelper.h"

ATPEnemyCharacter::ATPEnemyCharacter()
{
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bUseControllerDesiredRotation = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 180.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 300.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 1000.f;

	EnemyCombatComponent = CreateDefaultSubobject<UTPEnemyCombatComponent>("EnemyCombatComponent");
	EnemyUIComponent = CreateDefaultSubobject<UTPEnemyUIComponent>("EnemyUIComponent");
	EnemyHealthWidgetComponent = CreateDefaultSubobject<UWidgetComponent>("EnemyHealthWidgetComponent");
	EnemyHealthWidgetComponent->SetupAttachment(GetMesh());

}

UTPPawnCombatComponent* ATPEnemyCharacter::GetPawnCombatComponent() const
{
	return EnemyCombatComponent;
}

UTPPawnUIComponent* ATPEnemyCharacter::GetPawnUIComponent() const
{
	return EnemyUIComponent;
}

UTPEnemyUIComponent* ATPEnemyCharacter::GetEnemyUIComponent() const
{
	return EnemyUIComponent;
}

void ATPEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (UTPBaseWidget* HealthWidget = Cast<UTPBaseWidget>(EnemyHealthWidgetComponent->GetUserWidgetObject()))
	{
		HealthWidget->InitEnemyCreatedWidget(this);
	}
}

void ATPEnemyCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitEnemyStartupData();
}

void ATPEnemyCharacter::InitEnemyStartupData()
{
	if (CharacterStartupData.IsNull())
	{
		return;
	}

	UAssetManager::GetStreamableManager().RequestAsyncLoad(
		CharacterStartupData.ToSoftObjectPath(),
		FStreamableDelegate::CreateLambda(
			[this]()
			{
				if (UTPDataAsset_BaseStartupData* LoadedData = CharacterStartupData.Get())
				{
					LoadedData->GiveToAbilitySystemComponent(TPAbilitySystemComponent);

					// Debug::Print(TEXT("Enemy Startup Data Loaded"), FColor::Green);
				}
			}
		)
	);
}