// © 2025 1nvoker - MIT License

#pragma once

#include "NativeGameplayTags.h"

namespace TPGameplayTags
{
	//? Input Tags
	TEST_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
	TEST_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look);
	TEST_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_EquipAxe);
	TEST_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_UnEquipAxe);
	TEST_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_LightAttack_Axe);
	TEST_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_HeavyAttack_Axe);

	//? Player Tags
	TEST_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_EquipAxe);
	TEST_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_UnEquipAxe);
	TEST_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Light_Axe);
	TEST_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Heavy_Axe);

	TEST_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Axe);

	//? Anim Notify
	TEST_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_EquipAxe);
	TEST_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_UnEquipAxe);

	//? Status Tags
	TEST_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Status_JumpToFinisher);

	//? Enemy Tags
	TEST_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_Weapon);

	//? Shared Tags
	TEST_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Event_MeleeHit);


}