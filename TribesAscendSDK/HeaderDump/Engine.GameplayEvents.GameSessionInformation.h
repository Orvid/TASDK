#pragma once
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
	struct GameplayEvents__GameSessionInformation
	{
	public:
		ADD_STRUCT(OnlineSubsystem__UniqueNetId, OwningNetId, 100)
		ADD_STRUCT(int, GameTypeId, 96)
		ADD_STRUCT(int, SessionInstance, 92)
		ADD_STRUCT(ScriptString*, MapURL, 80)
		ADD_STRUCT(ScriptString*, MapName, 68)
		ADD_STRUCT(ScriptString*, GameClassName, 56)
		ADD_STRUCT(ScriptString*, GameplaySessionID, 44)
		ADD_BOOL(bGameplaySessionInProgress, 40, 0x1)
		ADD_STRUCT(float, GameplaySessionEndTime, 36)
		ADD_STRUCT(float, GameplaySessionStartTime, 32)
		ADD_STRUCT(ScriptString*, GameplaySessionTimestamp, 20)
		ADD_STRUCT(ScriptString*, Language, 8)
		ADD_STRUCT(int, PlatformType, 4)
		ADD_STRUCT(int, AppTitleID, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
