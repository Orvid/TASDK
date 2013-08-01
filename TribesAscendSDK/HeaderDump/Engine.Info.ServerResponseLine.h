#pragma once
#include "Engine.Info.KeyValuePair.h"
#include "Engine.Info.PlayerResponseLine.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Info__ServerResponseLine
	{
	public:
		ADD_STRUCT(ScriptArray<Info__KeyValuePair>, ServerInfo, 72)
		ADD_STRUCT(ScriptArray<Info__PlayerResponseLine>, PlayerInfo, 84)
		ADD_STRUCT(int, Ping, 68)
		ADD_STRUCT(int, MaxPlayers, 64)
		ADD_STRUCT(int, CurrentPlayers, 60)
		ADD_STRUCT(ScriptString*, GameType, 48)
		ADD_STRUCT(ScriptString*, MapName, 36)
		ADD_STRUCT(ScriptString*, ServerName, 24)
		ADD_STRUCT(int, QueryPort, 20)
		ADD_STRUCT(int, Port, 16)
		ADD_STRUCT(ScriptString*, IP, 4)
		ADD_STRUCT(int, ServerID, 0)
	};
}
#undef ADD_STRUCT
