#pragma once
#include "Engine__NavigationPoint.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.TriggeredPath." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.TriggeredPath." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TriggeredPath : public NavigationPoint
	{
	public:
		ADD_OBJECT(Actor, MyTrigger)
		ADD_VAR(::BoolProperty, bOpen, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
