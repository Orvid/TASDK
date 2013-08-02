#pragma once
namespace UnrealScript
{
	struct HUD__HudLocalizedMessage;
}
#include "Core.Object.h"
#include "Core.Object.Color.h"
#include "Engine.Font.h"
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
	struct HUD__HudLocalizedMessage
	{
	public:
		ADD_OBJECT(Object, OptionalObject, 60)
		ADD_STRUCT(int, Count, 56)
		ADD_BOOL(Drawn, 52, 0x1)
		ADD_STRUCT(float, DY, 48)
		ADD_STRUCT(float, DX, 44)
		ADD_OBJECT(Font, StringFont, 40)
		ADD_STRUCT(int, FontSize, 36)
		ADD_STRUCT(Object__Color, DrawColor, 32)
		ADD_STRUCT(float, PosY, 28)
		ADD_STRUCT(float, Lifetime, 24)
		ADD_STRUCT(float, EndOfLife, 20)
		ADD_STRUCT(int, Switch, 16)
		ADD_STRUCT(ScriptString*, StringMessage, 4)
		ADD_OBJECT(ScriptClass, Message, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
