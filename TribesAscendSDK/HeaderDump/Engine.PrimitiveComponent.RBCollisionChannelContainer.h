#pragma once
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
namespace UnrealScript
{
	struct PrimitiveComponent__RBCollisionChannelContainer
	{
	public:
		ADD_BOOL(Default, 0, 0x1)
		ADD_BOOL(Nothing, 0, 0x2)
		ADD_BOOL(Pawn, 0, 0x4)
		ADD_BOOL(Vehicle, 0, 0x8)
		ADD_BOOL(Water, 0, 0x10)
		ADD_BOOL(GameplayPhysics, 0, 0x20)
		ADD_BOOL(EffectPhysics, 0, 0x40)
		ADD_BOOL(Untitled1, 0, 0x80)
		ADD_BOOL(Untitled2, 0, 0x100)
		ADD_BOOL(Untitled3, 0, 0x200)
		ADD_BOOL(Untitled4, 0, 0x400)
		ADD_BOOL(Cloth, 0, 0x800)
		ADD_BOOL(FluidDrain, 0, 0x1000)
		ADD_BOOL(SoftBody, 0, 0x2000)
		ADD_BOOL(FracturedMeshPart, 0, 0x4000)
		ADD_BOOL(BlockingVolume, 0, 0x8000)
		ADD_BOOL(DeadPawn, 0, 0x10000)
		ADD_BOOL(Clothing, 0, 0x20000)
		ADD_BOOL(ClothingCollision, 0, 0x40000)
	};
}
#undef ADD_BOOL
