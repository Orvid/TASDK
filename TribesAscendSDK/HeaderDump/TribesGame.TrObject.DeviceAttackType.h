#pragma once
namespace UnrealScript
{
	enum TrObject__DeviceAttackType : byte
	{
		TRTT_ATTCK_NA = 0,
		TRTT_ATTACK_INSTANT = 1,
		TRTT_ATTACK_PROJECTILE = 2,
		TRTT_ATTACK_DEPLOYABLE = 3,
		TRTT_ATTACK_SPAWN_PET = 4,
		TRTT_ATTACK_TELEPORT = 5,
		TRTT_MAX = 6,
	};
}
