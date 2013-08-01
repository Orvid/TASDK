#pragma once
#include "Engine.Actor.h"
#include "Core.Object.Vector.h"
#include "Engine.Actor.TraceHitInfo.h"
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
	struct Actor__ImpactInfo
	{
	public:
		ADD_OBJECT(Actor, HitActor, 0)
		ADD_STRUCT(Vector, HitLocation, 4)
		ADD_STRUCT(Vector, HitNormal, 16)
		ADD_STRUCT(Vector, RayDir, 28)
		ADD_STRUCT(Vector, StartTrace, 40)
		ADD_STRUCT(Actor__TraceHitInfo, HitInfo, 52)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
