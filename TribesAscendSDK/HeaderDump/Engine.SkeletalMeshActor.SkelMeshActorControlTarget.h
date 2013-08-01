#pragma once
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
	struct SkeletalMeshActor__SkelMeshActorControlTarget
	{
	public:
		ADD_OBJECT(Actor, TargetActor, 8)
		ADD_STRUCT(ScriptName, ControlName, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
