#pragma once
namespace UnrealScript
{
	struct UDKVehicle__FDamageMorphTargets;
}
#include "Engine.MorphNodeWeight.h"
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
	struct UDKVehicle__FDamageMorphTargets
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptName>, DamagePropNames, 36)
		ADD_STRUCT(int, Health, 32)
		ADD_STRUCT(ScriptName, InfluenceBone, 24)
		ADD_STRUCT(int, LinkedMorphNodeIndex, 20)
		ADD_STRUCT(ScriptName, LinkedMorphNodeName, 12)
		ADD_OBJECT(MorphNodeWeight, MorphNode, 8)
		ADD_STRUCT(ScriptName, MorphNodeName, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
