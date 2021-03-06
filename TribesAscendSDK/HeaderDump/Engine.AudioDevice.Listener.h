#pragma once
namespace UnrealScript
{
	struct AudioDevice__Listener;
}
#include "Engine.PortalVolume.h"
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
	struct AudioDevice__Listener
	{
	public:
		ADD_STRUCT(Vector, Front, 40)
		ADD_STRUCT(Vector, Right, 28)
		ADD_STRUCT(Vector, Up, 16)
		ADD_STRUCT(Vector, Location, 4)
		ADD_OBJECT(PortalVolume, PortalVolume, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
