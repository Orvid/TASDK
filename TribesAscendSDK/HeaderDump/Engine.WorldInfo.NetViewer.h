#pragma once
namespace UnrealScript
{
	struct WorldInfo__NetViewer;
}
#include "Engine.Actor.h"
#include "Engine.PlayerController.h"
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
	struct WorldInfo__NetViewer
	{
	public:
		ADD_OBJECT(PlayerController, InViewer, 0)
		ADD_OBJECT(Actor, Viewer, 4)
		ADD_STRUCT(Vector, ViewLocation, 8)
		ADD_STRUCT(Vector, ViewDir, 20)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
