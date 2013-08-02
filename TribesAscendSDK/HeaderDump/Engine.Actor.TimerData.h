#pragma once
namespace UnrealScript
{
	struct Actor__TimerData;
}
#include "Core.Object.h"
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
	struct Actor__TimerData
	{
	public:
		ADD_BOOL(bLoop, 0, 0x1)
		ADD_BOOL(bPaused, 0, 0x2)
		ADD_STRUCT(ScriptName, FuncName, 4)
		ADD_STRUCT(float, Rate, 12)
		ADD_STRUCT(float, Count, 16)
		ADD_STRUCT(float, TimerTimeDilation, 20)
		ADD_OBJECT(Object, TimerObj, 24)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
