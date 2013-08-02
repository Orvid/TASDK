#pragma once
namespace UnrealScript
{
	struct OnlineSubsystem__RemoteTalker;
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
	struct OnlineSubsystem__RemoteTalker
	{
	public:
		ADD_STRUCT(OnlineSubsystem__UniqueNetId, TalkerId, 0)
		ADD_STRUCT(float, LastNotificationTime, 8)
		ADD_BOOL(bWasTalking, 12, 0x1)
		ADD_BOOL(bIsTalking, 12, 0x2)
		ADD_BOOL(bIsRegistered, 12, 0x4)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
