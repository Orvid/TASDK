#pragma once
#include "Core.Object.Rotator.h"
#include "Core.Object.Vector.h"
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
	struct EmitterPool__EmitterBaseInfo
	{
	public:
		ADD_BOOL(bInheritBaseScale, 32, 0x1)
		ADD_STRUCT(Rotator, RelativeRotation, 20)
		ADD_STRUCT(Vector, RelativeLocation, 8)
		ADD_OBJECT(Actor, Base, 4)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT