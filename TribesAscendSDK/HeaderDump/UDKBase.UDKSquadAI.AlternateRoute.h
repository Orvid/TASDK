#pragma once
namespace UnrealScript
{
	struct UDKSquadAI__AlternateRoute;
}
#include "Engine.NavigationPoint.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UDKSquadAI__AlternateRoute
	{
	public:
		ADD_STRUCT(ScriptArray<class NavigationPoint*>, RouteCache, 0)
	};
}
#undef ADD_STRUCT
