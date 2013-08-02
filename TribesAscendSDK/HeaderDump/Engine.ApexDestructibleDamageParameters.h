#pragma once
namespace UnrealScript
{
	class ApexDestructibleDamageParameters;
}
#include "Core.Object.h"
#include "Engine.ApexDestructibleDamageParameters.DamagePair.h"
#include "Engine.ApexDestructibleDamageParameters.DamageParameters.h"
#include "Engine.ApexDestructibleDamageParameters.EDamageParameterOverrideMode.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ApexDestructibleDamageParameters : public Object
	{
	public:
		typedef ApexDestructibleDamageParameters__EDamageParameterOverrideMode EDamageParameterOverrideMode;
		typedef ApexDestructibleDamageParameters__DamagePair DamagePair;
		typedef ApexDestructibleDamageParameters__DamageParameters DamageParameters;
		ADD_STRUCT(ScriptArray<ApexDestructibleDamageParameters__DamagePair>, DamageMap, 60)
	};
}
#undef ADD_STRUCT
