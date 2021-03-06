#pragma once
namespace UnrealScript
{
	struct WorldInfo__PhysXVerticalProperties;
}
#include "Engine.WorldInfo.PhysXEmitterVerticalProperties.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct WorldInfo__PhysXVerticalProperties
	{
	public:
		ADD_STRUCT(WorldInfo__PhysXEmitterVerticalProperties, Emitters, 0)
	};
}
#undef ADD_STRUCT
