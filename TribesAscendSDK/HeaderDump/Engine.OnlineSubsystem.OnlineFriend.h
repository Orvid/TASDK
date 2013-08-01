#pragma once
#include "Core.Object.QWord.h"
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#include "Engine.OnlineSubsystem.EOnlineFriendState.h"
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
	struct OnlineSubsystem__OnlineFriend
	{
	public:
		ADD_STRUCT(OnlineSubsystem__UniqueNetId, UniqueId, 0)
		ADD_STRUCT(QWord, SessionId, 8)
		ADD_STRUCT(ScriptString*, NickName, 16)
		ADD_STRUCT(ScriptString*, PresenceInfo, 28)
		ADD_STRUCT(OnlineSubsystem__EOnlineFriendState, FriendState, 40)
		ADD_BOOL(bIsOnline, 44, 0x1)
		ADD_BOOL(bIsPlaying, 44, 0x2)
		ADD_BOOL(bIsPlayingThisGame, 44, 0x4)
		ADD_BOOL(bIsJoinable, 44, 0x8)
		ADD_BOOL(bHasVoiceSupport, 44, 0x10)
		ADD_BOOL(bHaveInvited, 44, 0x20)
		ADD_BOOL(bHasInvitedYou, 44, 0x40)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
