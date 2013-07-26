#pragma once
#include "TribesGame.TrStormControlPoint.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrGame_TrStorm.Missile." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TrGame_TrStorm.Missile." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Missile
	{
	public:
		ADD_VAR(::ByteProperty, TargetTeam, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RemainingFlightTime, 0xFFFFFFFF)
		ADD_OBJECT(TrStormControlPoint, FiredFrom)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT