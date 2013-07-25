#pragma once
#include "Engine.ActorFactory.h"
#include "Engine.SpeedTree.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SpeedTreeActorFactory." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SpeedTreeActorFactory : public ActorFactory
	{
	public:
		ADD_OBJECT(SpeedTree, SpeedTree)
	};
}
#undef ADD_OBJECT