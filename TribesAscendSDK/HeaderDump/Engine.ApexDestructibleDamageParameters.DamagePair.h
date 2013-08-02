#pragma once
namespace UnrealScript
{
	struct ApexDestructibleDamageParameters__DamagePair;
}
#include "Engine.ApexDestructibleDamageParameters.DamageParameters.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct ApexDestructibleDamageParameters__DamagePair
	{
	public:
		ADD_STRUCT(ApexDestructibleDamageParameters__DamageParameters, Params, 8)
		ADD_STRUCT(ScriptName, DamageCauserName, 0)
	};
}
#undef ADD_STRUCT
