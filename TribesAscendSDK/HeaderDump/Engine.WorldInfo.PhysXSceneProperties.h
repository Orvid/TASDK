#pragma once
#include "Engine.WorldInfo.PhysXSimulationProperties.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct WorldInfo__PhysXSceneProperties
	{
	public:
		ADD_STRUCT(WorldInfo__PhysXSimulationProperties, PrimaryScene, 0)
		ADD_STRUCT(WorldInfo__PhysXSimulationProperties, CompartmentRigidBody, 12)
		ADD_STRUCT(WorldInfo__PhysXSimulationProperties, CompartmentFluid, 24)
		ADD_STRUCT(WorldInfo__PhysXSimulationProperties, CompartmentCloth, 36)
		ADD_STRUCT(WorldInfo__PhysXSimulationProperties, CompartmentSoftBody, 48)
	};
}
#undef ADD_STRUCT
