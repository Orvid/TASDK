#pragma once
namespace UnrealScript
{
	struct Controller__VisiblePortalInfo;
}
#include "Engine.Actor.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct Controller__VisiblePortalInfo
	{
	public:
		ADD_OBJECT(Actor, Destination, 4)
		ADD_OBJECT(Actor, Source, 0)
	};
}
#undef ADD_OBJECT
