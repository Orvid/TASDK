#pragma once
namespace UnrealScript
{
	class OnlineGameplayEvents;
}
#include "Core.Object.h"
#include "Core.Object.Guid.h"
#include "Engine.OnlineGameplayEvents.GameplayEvent.h"
#include "Engine.OnlineGameplayEvents.PlayerEvent.h"
#include "Engine.OnlineGameplayEvents.PlayerInformation.h"
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
	class OnlineGameplayEvents : public Object
	{
	public:
		typedef OnlineGameplayEvents__PlayerInformation PlayerInformation;
		typedef OnlineGameplayEvents__GameplayEvent GameplayEvent;
		typedef OnlineGameplayEvents__PlayerEvent PlayerEvent;
		ADD_STRUCT(ScriptArray<OnlineGameplayEvents__PlayerInformation>, PlayerList, 60)
		ADD_STRUCT(ScriptArray<ScriptString*>, EventDescList, 72)
		ADD_STRUCT(ScriptArray<ScriptName>, EventNames, 84)
		ADD_STRUCT(ScriptArray<OnlineGameplayEvents__GameplayEvent>, GameplayEvents, 96)
		ADD_STRUCT(ScriptArray<OnlineGameplayEvents__PlayerEvent>, PlayerEvents, 108)
		ADD_STRUCT(Object__Guid, GameplaySessionID, 136)
		ADD_BOOL(bGameplaySessionInProgress, 132, 0x1)
		ADD_STRUCT(ScriptString*, GameplaySessionStartTime, 120)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
