#pragma once
#include "Engine.PhysXParticleSystem.h"
#include "Engine.ParticleModuleTypeDataMeshPhysX.EPhysXMeshRotationMethod.h"
#include "Engine.ParticleModuleTypeDataMesh.h"
#include "Engine.ParticleModuleTypeDataPhysX.PhysXEmitterVerticalLodProperties.h"
#include "Core.Object.Pointer.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class ParticleModuleTypeDataMeshPhysX : public ParticleModuleTypeDataMesh
	{
	public:
		ADD_STRUCT(ParticleModuleTypeDataPhysX__PhysXEmitterVerticalLodProperties, VerticalLod, 112)
		ADD_STRUCT(Object__Pointer, RenderInstance, 108)
		ADD_STRUCT(float, FluidRotationCoefficient, 104)
		ADD_STRUCT(ParticleModuleTypeDataMeshPhysX__EPhysXMeshRotationMethod, PhysXRotationMethod, 100)
		ADD_OBJECT(PhysXParticleSystem, PhysXParSys, 96)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
