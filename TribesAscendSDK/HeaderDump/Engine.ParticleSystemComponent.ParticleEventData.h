#pragma once
#include "Core.Object.Vector.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct ParticleSystemComponent__ParticleEventData
	{
	public:
		ADD_STRUCT(Vector, Velocity, 40)
		ADD_STRUCT(Vector, Direction, 28)
		ADD_STRUCT(Vector, Location, 16)
		ADD_STRUCT(float, EmitterTime, 12)
		ADD_STRUCT(ScriptName, EventName, 4)
		ADD_STRUCT(int, Type, 0)
	};
}
#undef ADD_STRUCT
