#pragma once
namespace UnrealScript
{
	struct Pawn__LastHitInfoStruct;
}
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
	struct Pawn__LastHitInfoStruct
	{
	public:
		ADD_OBJECT(ScriptClass, Type, 16)
		ADD_OBJECT(Actor, Causer, 12)
		ADD_STRUCT(float, Distance, 8)
		ADD_STRUCT(float, Amount, 4)
		ADD_BOOL(bDirectHit, 0, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
