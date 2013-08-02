#pragma once
namespace UnrealScript
{
	struct GameplayEvents__PlayerInformationNew;
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
	struct GameplayEvents__PlayerInformationNew
	{
	public:
		ADD_BOOL(bIsBot, 32, 0x1)
		ADD_STRUCT(OnlineSubsystem__UniqueNetId, UniqueId, 24)
		ADD_STRUCT(ScriptString*, PlayerName, 12)
		ADD_STRUCT(ScriptString*, ControllerName, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
