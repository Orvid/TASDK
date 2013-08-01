#pragma once
#include "Engine.Info.KeyValuePair.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Info__PlayerResponseLine
	{
	public:
		ADD_STRUCT(ScriptArray<Info__KeyValuePair>, PlayerInfo, 32)
		ADD_STRUCT(int, StatsID, 28)
		ADD_STRUCT(int, Score, 24)
		ADD_STRUCT(int, Ping, 20)
		ADD_STRUCT(ScriptString*, PlayerName, 8)
		ADD_STRUCT(int, PlayerID, 4)
		ADD_STRUCT(int, PlayerNum, 0)
	};
}
#undef ADD_STRUCT
