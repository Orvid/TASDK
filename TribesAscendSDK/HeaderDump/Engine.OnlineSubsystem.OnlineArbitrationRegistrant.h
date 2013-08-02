#pragma once
namespace UnrealScript
{
	struct OnlineSubsystem__OnlineArbitrationRegistrant;
}
#include "Engine.OnlineSubsystem.OnlineRegistrant.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct OnlineSubsystem__OnlineArbitrationRegistrant : public OnlineSubsystem__OnlineRegistrant
	{
	public:
		ADD_STRUCT(QWord, MachineId, 8)
		ADD_STRUCT(int, Trustworthiness, 16)
	};
}
#undef ADD_STRUCT
