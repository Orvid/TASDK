#pragma once
#include "GameFramework.MobileInputZone.EZoneTouchEvent.h"
#include "Core.Object.Vector2D.h"
#include "GameFramework.MobileInputZone.h"
#include "GameFramework.MobilePlayerInput.TouchDataEvent.h"
#include "Core.Object.Double.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	struct MobilePlayerInput__TouchData
	{
	public:
		ADD_BOOL(bInUse, 40, 0x1)
		ADD_STRUCT(MobileInputZone__EZoneTouchEvent, State, 48)
		ADD_OBJECT(MobileInputZone, Zone, 44)
		ADD_STRUCT(int, Handle, 0)
		ADD_STRUCT(ScriptArray<MobilePlayerInput__TouchDataEvent>, Events, 52)
		ADD_STRUCT(float, LastActiveTime, 64)
		ADD_STRUCT(float, MoveDeltaTime, 36)
		ADD_STRUCT(Object__Double, MoveEventDeviceTime, 28)
		ADD_STRUCT(float, TouchDuration, 24)
		ADD_STRUCT(Object__Double, InitialDeviceTime, 16)
		ADD_STRUCT(float, TotalMoveDistance, 12)
		ADD_STRUCT(Object__Vector2D, Location, 4)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
