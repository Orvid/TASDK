#pragma once
#include "TribesGame.TrQueueManager.ProfileConfig.h"
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
	struct TrQueueManager__ServerConfig
	{
	public:
		ADD_STRUCT(ScriptArray<TrQueueManager__ProfileConfig>, Profiles, 28)
		ADD_STRUCT(ScriptString*, ServerName, 16)
		ADD_BOOL(bCanExpire, 12, 0x8)
		ADD_BOOL(bActive, 12, 0x4)
		ADD_BOOL(bOwner, 12, 0x2)
		ADD_BOOL(bOpen, 12, 0x1)
		ADD_STRUCT(int, MinutesRented, 8)
		ADD_STRUCT(int, MatchQueueId, 4)
		ADD_STRUCT(int, ActiveConfig, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
