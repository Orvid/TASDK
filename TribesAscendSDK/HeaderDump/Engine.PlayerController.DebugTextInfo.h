#pragma once
#include "Engine.Actor.h"
#include "Engine.Font.h"
#include "Core.Object.Vector.h"
#include "Core.Object.Color.h"
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
	struct PlayerController__DebugTextInfo
	{
	public:
		ADD_OBJECT(Actor, SrcActor, 0)
		ADD_STRUCT(float, TimeRemaining, 40)
		ADD_OBJECT(Font, Font, 68)
		ADD_BOOL(bAbsoluteLocation, 52, 0x1)
		ADD_STRUCT(Vector, SrcActorOffset, 4)
		ADD_STRUCT(Vector, SrcActorDesiredOffset, 16)
		ADD_STRUCT(float, Duration, 44)
		ADD_BOOL(bKeepAttachedToActor, 52, 0x2)
		ADD_STRUCT(Vector, OrigActorLocation, 56)
		ADD_STRUCT(Object__Color, TextColor, 48)
		ADD_STRUCT(ScriptString*, DebugText, 28)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
