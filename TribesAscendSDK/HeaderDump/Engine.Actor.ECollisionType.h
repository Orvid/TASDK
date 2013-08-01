#pragma once
namespace UnrealScript
{
	enum Actor__ECollisionType : byte
	{
		COLLIDE_CustomDefault = 0,
		COLLIDE_NoCollision = 1,
		COLLIDE_BlockAll = 2,
		COLLIDE_BlockWeapons = 3,
		COLLIDE_BlockVehicles = 4,
		COLLIDE_TouchAll = 5,
		COLLIDE_TouchWeapons = 6,
		COLLIDE_BlockAllButWeapons = 7,
		COLLIDE_TouchAllButWeapons = 8,
		COLLIDE_BlockWeaponsKickable = 9,
		COLLIDE_MAX = 10,
	};
}
