#pragma once
#include "Engine__NavigationPoint.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PickupFactory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.PickupFactory." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PickupFactory : public NavigationPoint
	{
	public:
		ADD_OBJECT(PickupFactory, OriginalFactory)
		ADD_OBJECT(PickupFactory, ReplacementFactory)
		ADD_VAR(::FloatProperty, MaxDesireability, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RespawnEffectTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bRespawnPaused, 0x10)
		ADD_VAR(::BoolProperty, bIsSuperItem, 0x8)
		ADD_VAR(::BoolProperty, bPredictRespawns, 0x4)
		ADD_VAR(::BoolProperty, bPickupHidden, 0x2)
		ADD_VAR(::BoolProperty, bOnlyReplicateHidden, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
