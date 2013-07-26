#pragma once
#include "Core.Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Actor.TimerData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Actor.TimerData." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TimerData
	{
	public:
		ADD_VAR(::BoolProperty, bLoop, 0x1)
		ADD_VAR(::BoolProperty, bPaused, 0x2)
		ADD_VAR(::NameProperty, FuncName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Rate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Count, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TimerTimeDilation, 0xFFFFFFFF)
		ADD_OBJECT(Object, TimerObj)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT