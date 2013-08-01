#pragma once
namespace UnrealScript
{
	enum PrimitiveComponent__ERBCollisionChannel : byte
	{
		RBCC_Default = 0,
		RBCC_Nothing = 1,
		RBCC_Pawn = 2,
		RBCC_Vehicle = 3,
		RBCC_Water = 4,
		RBCC_GameplayPhysics = 5,
		RBCC_EffectPhysics = 6,
		RBCC_Untitled1 = 7,
		RBCC_Untitled2 = 8,
		RBCC_Untitled3 = 9,
		RBCC_Untitled4 = 10,
		RBCC_Cloth = 11,
		RBCC_FluidDrain = 12,
		RBCC_SoftBody = 13,
		RBCC_FracturedMeshPart = 14,
		RBCC_BlockingVolume = 15,
		RBCC_DeadPawn = 16,
		RBCC_Clothing = 17,
		RBCC_ClothingCollision = 18,
		RBCC_MAX = 19,
	};
}
