// © 2025 1nvoker - MIT License


#include "ThirdPerson/TPGameplayTags.h"

namespace TPGameplayTags
{
	//? Input Tags
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_EquipAxe, "InputTag.EquipAxe");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_UnEquipAxe, "InputTag.UnEquipAxe");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_LightAttack_Axe, "InputTag.LightAttack.Axe");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_HeavyAttack_Axe, "InputTag.HeavyAttack.Axe");

	//? Player Tags
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_EquipAxe, "Player.Ability.EquipAxe");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_UnEquipAxe, "Player.Ability.UnEquipAxe");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Light_Axe, "Player.Ability.Attack.Light.Axe");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Heavy_Axe, "Player.Ability.Attack.Heavy.Axe");

	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Axe, "Player.Weapon.Axe");

	//? Anim Notify
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_EquipAxe, "Player.Event.EquipAxe");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_UnEquipAxe, "Player.Event.UnEquipAxe");

	//? Status Tags
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_JumpToFinisher, "Player.Status.JumpToFinisher");

	//? Enemy Tags
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Weapon, "Enemy.Weapon");

	//? Shared Tags
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_MeleeHit, "Shared.Enemy.MeleeHit");


}