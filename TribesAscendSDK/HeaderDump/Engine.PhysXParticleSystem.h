#pragma once
#include "Engine.PrimitiveComponent.ERBCollisionChannel.h"
#include "Engine.PhysXParticleSystem.EPacketSizeMultiplier.h"
#include "Core.Object.h"
#include "Core.Object.Pointer.h"
#include "Engine.PhysXParticleSystem.ESimulationMethod.h"
#include "Core.Object.Vector.h"
#include "Engine.PrimitiveComponent.RBCollisionChannelContainer.h"
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
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class PhysXParticleSystem : public Object
	{
	public:
		ADD_STRUCT(Object__Pointer, PSys, 156)
		ADD_STRUCT(Object__Pointer, CascadeScene, 152)
		ADD_STRUCT(float, CollisionResponseCoefficient, 148)
		ADD_STRUCT(float, Viscosity, 144)
		ADD_STRUCT(float, Stiffness, 140)
		ADD_STRUCT(float, KernelRadiusMultiplier, 136)
		ADD_STRUCT(float, RestDensity, 132)
		ADD_STRUCT(float, RestParticleDistance, 128)
		ADD_STRUCT(Vector, ExternalAcceleration, 116)
		ADD_STRUCT(float, Damping, 112)
		ADD_STRUCT(float, MaxMotionDistance, 108)
		ADD_BOOL(bIsInGame, 104, 0x40)
		ADD_BOOL(bSyncFailed, 104, 0x20)
		ADD_BOOL(bDestroy, 104, 0x10)
		ADD_BOOL(bTwoWayCollision, 104, 0x8)
		ADD_BOOL(bStaticCollision, 104, 0x4)
		ADD_BOOL(bDisableGravity, 104, 0x2)
		ADD_BOOL(bDynamicCollision, 104, 0x1)
		ADD_STRUCT(float, StaticFrictionWithDynamicShapes, 100)
		ADD_STRUCT(float, StaticFrictionWithStaticShapes, 96)
		ADD_STRUCT(float, FrictionWithDynamicShapes, 92)
		ADD_STRUCT(float, FrictionWithStaticShapes, 88)
		ADD_STRUCT(float, RestitutionWithDynamicShapes, 84)
		ADD_STRUCT(float, RestitutionWithStaticShapes, 80)
		ADD_STRUCT(float, CollisionDistance, 76)
		ADD_STRUCT(PrimitiveComponent__RBCollisionChannelContainer, RBCollideWithChannels, 72)
		ADD_STRUCT(PhysXParticleSystem__EPacketSizeMultiplier, PacketSizeMultiplier, 70)
		ADD_STRUCT(PhysXParticleSystem__ESimulationMethod, SimulationMethod, 69)
		ADD_STRUCT(PrimitiveComponent__ERBCollisionChannel, RBChannel, 68)
		ADD_STRUCT(int, ParticleSpawnReserve, 64)
		ADD_STRUCT(int, MaxParticles, 60)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
