#pragma once
namespace UnrealScript
{
	struct ApexDestructibleDamageParameters__DamageParameters;
}
#include "Engine.ApexDestructibleDamageParameters.EDamageParameterOverrideMode.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct ApexDestructibleDamageParameters__DamageParameters
	{
	public:
		ADD_STRUCT(float, Momentum, 12)
		ADD_STRUCT(float, Radius, 8)
		ADD_STRUCT(float, BaseDamage, 4)
		ADD_STRUCT(ApexDestructibleDamageParameters__EDamageParameterOverrideMode, OverrideMode, 0)
	};
}
#undef ADD_STRUCT
