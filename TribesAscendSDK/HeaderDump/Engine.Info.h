#pragma once
namespace UnrealScript
{
	class Info;
}
#include "Engine.Actor.h"
#include "Engine.Info.KeyValuePair.h"
#include "Engine.Info.PlayerResponseLine.h"
#include "Engine.Info.ServerResponseLine.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class Info : public Actor
	{
	public:
		typedef Info__KeyValuePair KeyValuePair;
		typedef Info__PlayerResponseLine PlayerResponseLine;
		typedef Info__ServerResponseLine ServerResponseLine;
	};
}
#undef ADD_STRUCT
