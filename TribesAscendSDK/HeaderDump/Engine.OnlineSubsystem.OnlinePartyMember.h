#pragma once
namespace UnrealScript
{
	struct OnlineSubsystem__OnlinePartyMember;
}
#include "Engine.OnlineSubsystem.ENATType.h"
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
	struct OnlineSubsystem__OnlinePartyMember
	{
	public:
		ADD_STRUCT(OnlineSubsystem__UniqueNetId, UniqueId, 0)
		ADD_STRUCT(ScriptString*, NickName, 8)
		ADD_STRUCT(byte, LocalUserNum, 20)
		ADD_STRUCT(OnlineSubsystem__ENATType, NatType, 21)
		ADD_STRUCT(int, TitleId, 24)
		ADD_BOOL(bIsLocal, 28, 0x1)
		ADD_BOOL(bIsInPartyVoice, 28, 0x2)
		ADD_BOOL(bIsTalking, 28, 0x4)
		ADD_BOOL(bIsInGameSession, 28, 0x8)
		ADD_BOOL(bIsPlayingThisGame, 28, 0x10)
		ADD_STRUCT(QWord, SessionId, 32)
		ADD_STRUCT(int, Data1, 40)
		ADD_STRUCT(int, Data2, 44)
		ADD_STRUCT(int, Data3, 48)
		ADD_STRUCT(int, Data4, 52)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
