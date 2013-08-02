#pragma once
namespace UnrealScript
{
	struct SplineActor__SplineConnection;
}
#include "Engine.SplineActor.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct SplineActor__SplineConnection
	{
	public:
		ADD_OBJECT(SplineActor, ConnectTo, 4)
	};
}
#undef ADD_OBJECT
