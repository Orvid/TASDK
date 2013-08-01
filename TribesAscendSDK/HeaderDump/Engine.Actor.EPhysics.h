#pragma once
namespace UnrealScript
{
	enum Actor__EPhysics : byte
	{
		PHYS_None = 0,
		PHYS_Walking = 1,
		PHYS_Falling = 2,
		PHYS_Swimming = 3,
		PHYS_Flying = 4,
		PHYS_Rotating = 5,
		PHYS_Projectile = 6,
		PHYS_Interpolating = 7,
		PHYS_Spider = 8,
		PHYS_Ladder = 9,
		PHYS_RigidBody = 10,
		PHYS_SoftBody = 11,
		PHYS_NavMeshWalking = 12,
		PHYS_Skiing = 13,
		PHYS_Unused = 14,
		PHYS_Custom = 15,
		PHYS_MAX = 16,
	};
}
