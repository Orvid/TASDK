#pragma once
namespace UnrealScript
{
	struct OnlineSubsystem__OnlineRegistrant;
}
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct OnlineSubsystem__OnlineRegistrant
	{
	public:
		ADD_STRUCT(OnlineSubsystem__UniqueNetId, PlayerNetId, 0)
	};
}
#undef ADD_STRUCT
