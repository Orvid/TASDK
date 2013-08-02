#pragma once
namespace UnrealScript
{
	struct OnlineSubsystem__OnlineFriendMessage;
}
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct OnlineSubsystem__OnlineFriendMessage
	{
	public:
		ADD_STRUCT(OnlineSubsystem__UniqueNetId, SendingPlayerId, 0)
		ADD_STRUCT(ScriptString*, SendingPlayerNick, 8)
		ADD_BOOL(bIsFriendInvite, 20, 0x1)
		ADD_BOOL(bIsGameInvite, 20, 0x2)
		ADD_BOOL(bWasAccepted, 20, 0x4)
		ADD_BOOL(bWasDenied, 20, 0x8)
		ADD_STRUCT(ScriptString*, Message, 24)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
