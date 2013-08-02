#pragma once
namespace UnrealScript
{
	struct GameThirdPersonCamera__CamFocusPointParams;
}
#include "Core.Object.Vector2D.h"
#include "Engine.Actor.h"
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
	struct GameThirdPersonCamera__CamFocusPointParams
	{
	public:
		ADD_STRUCT(float, FocusPitchOffsetDeg, 48)
		ADD_BOOL(bIgnoreTrace, 44, 0x4)
		ADD_BOOL(bAdjustCamera, 44, 0x2)
		ADD_BOOL(bAlwaysFocus, 44, 0x1)
		ADD_STRUCT(Object__Vector2D, InFocusFOV, 36)
		ADD_STRUCT(Object__Vector2D, InterpSpeedRange, 28)
		ADD_STRUCT(float, CameraFOV, 24)
		ADD_STRUCT(Vector, FocusWorldLoc, 12)
		ADD_STRUCT(ScriptName, FocusBoneName, 4)
		ADD_OBJECT(Actor, FocusActor, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
