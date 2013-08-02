#pragma once
namespace UnrealScript
{
	struct MobilePlayerInput__TouchDataEvent;
}
#include "Core.Object.Double.h"
#include "Core.Object.Vector2D.h"
#include "GameFramework.MobileInputZone.EZoneTouchEvent.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct MobilePlayerInput__TouchDataEvent
	{
	public:
		ADD_STRUCT(Object__Double, DeviceTime, 12)
		ADD_STRUCT(Object__Vector2D, Location, 4)
		ADD_STRUCT(MobileInputZone__EZoneTouchEvent, EventType, 0)
	};
}
#undef ADD_STRUCT
