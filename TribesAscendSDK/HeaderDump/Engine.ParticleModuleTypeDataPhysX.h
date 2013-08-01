#pragma once
#include "Engine.ParticleModuleTypeDataBase.h"
#include "Engine.ParticleModuleTypeDataPhysX.PhysXEmitterVerticalLodProperties.h"
#include "Engine.PhysXParticleSystem.h"
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
	class ParticleModuleTypeDataPhysX : public ParticleModuleTypeDataBase
	{
	public:
		ADD_STRUCT(ParticleModuleTypeDataPhysX__PhysXEmitterVerticalLodProperties, VerticalLod, 76)
		ADD_OBJECT(PhysXParticleSystem, PhysXParSys, 72)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
