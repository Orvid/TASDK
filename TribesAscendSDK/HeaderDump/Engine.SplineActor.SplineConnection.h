#pragma once
#include "Engine.SplineActor.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty SplineActor.SplineConnection." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SplineConnection
	{
	public:
		ADD_OBJECT(SplineActor, ConnectTo)
	};
}
#undef ADD_OBJECT