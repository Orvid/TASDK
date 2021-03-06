#pragma once
namespace UnrealScript
{
	struct Actor__BasedPosition;
}
#include "Engine.Actor.h"
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
	struct Actor__BasedPosition
	{
	public:
		ADD_STRUCT(Vector, CachedTransPosition, 40)
		ADD_STRUCT(Rotator, CachedBaseRotation, 28)
		ADD_STRUCT(Vector, CachedBaseLocation, 16)
		ADD_STRUCT(Vector, Position, 4)
		ADD_OBJECT(Actor, Base, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
