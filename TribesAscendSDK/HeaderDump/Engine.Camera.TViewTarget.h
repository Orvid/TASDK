#pragma once
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "Core.Object.TPOV.h"
#include "Engine.PlayerReplicationInfo.h"
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
	struct Camera__TViewTarget
	{
	public:
		ADD_OBJECT(Actor, Target, 0)
		ADD_STRUCT(Object__TPOV, POV, 8)
		ADD_STRUCT(float, AspectRatio, 36)
		ADD_OBJECT(Controller, Controller, 4)
		ADD_OBJECT(PlayerReplicationInfo, PRI, 40)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
