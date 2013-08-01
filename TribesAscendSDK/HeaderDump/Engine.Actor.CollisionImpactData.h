#pragma once
#include "Engine.Actor.RigidBodyContactInfo.h"
#include "Core.Object.Vector.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Actor__CollisionImpactData
	{
	public:
		ADD_STRUCT(ScriptArray<Actor__RigidBodyContactInfo>, ContactInfos, 0)
		ADD_STRUCT(Vector, TotalFrictionForceVector, 24)
		ADD_STRUCT(Vector, TotalNormalForceVector, 12)
	};
}
#undef ADD_STRUCT
