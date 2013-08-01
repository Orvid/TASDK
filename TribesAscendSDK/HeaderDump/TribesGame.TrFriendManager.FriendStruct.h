#pragma once
#include "TribesGame.TrFriendManager.EOnlineState.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct TrFriendManager__FriendStruct
	{
	public:
		ADD_STRUCT(ScriptString*, PlayerName, 4)
		ADD_STRUCT(TrFriendManager__EOnlineState, OnlineState, 16)
		ADD_STRUCT(int, PlayerID, 0)
	};
}
#undef ADD_STRUCT
