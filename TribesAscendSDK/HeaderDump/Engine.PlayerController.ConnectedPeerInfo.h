#pragma once
namespace UnrealScript
{
	struct PlayerController__ConnectedPeerInfo;
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
	struct PlayerController__ConnectedPeerInfo
	{
	public:
		ADD_STRUCT(OnlineSubsystem__UniqueNetId, PlayerID, 0)
		ADD_STRUCT(OnlineSubsystem__ENATType, NatType, 8)
		ADD_BOOL(bLostConnectionToHost, 12, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
