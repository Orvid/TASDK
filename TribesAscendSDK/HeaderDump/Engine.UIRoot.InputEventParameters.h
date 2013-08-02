#pragma once
namespace UnrealScript
{
	struct UIRoot__InputEventParameters;
}
#include "Core.Object.EInputEvent.h"
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
namespace UnrealScript
{
	struct UIRoot__InputEventParameters
	{
	public:
		ADD_BOOL(bShiftPressed, 28, 0x4)
		ADD_BOOL(bCtrlPressed, 28, 0x2)
		ADD_BOOL(bAltPressed, 28, 0x1)
		ADD_STRUCT(float, DeltaTime, 24)
		ADD_STRUCT(float, InputDelta, 20)
		ADD_STRUCT(Object__EInputEvent, EventType, 16)
		ADD_STRUCT(ScriptName, InputKeyName, 8)
		ADD_STRUCT(int, ControllerId, 4)
		ADD_STRUCT(int, PlayerIndex, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
