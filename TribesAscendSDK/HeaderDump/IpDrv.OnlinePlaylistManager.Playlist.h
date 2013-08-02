#pragma once
namespace UnrealScript
{
	struct OnlinePlaylistManager__Playlist;
}
#include "IpDrv.OnlinePlaylistManager.ConfiguredGameSetting.h"
#include "IpDrv.OnlinePlaylistManager.InventorySwap.h"
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
	struct OnlinePlaylistManager__Playlist
	{
	public:
		ADD_STRUCT(ScriptArray<OnlinePlaylistManager__ConfiguredGameSetting>, ConfiguredGames, 0)
		ADD_STRUCT(ScriptArray<int>, ContentIds, 32)
		ADD_STRUCT(ScriptArray<ScriptName>, MapCycle, 84)
		ADD_STRUCT(ScriptArray<OnlinePlaylistManager__InventorySwap>, InventorySwaps, 96)
		ADD_BOOL(bDisableDedicatedServerSearches, 80, 0x2)
		ADD_BOOL(bIsArbitrated, 80, 0x1)
		ADD_STRUCT(ScriptString*, URL, 68)
		ADD_STRUCT(ScriptString*, Name, 56)
		ADD_STRUCT(int, MaxPartySize, 52)
		ADD_STRUCT(int, TeamCount, 48)
		ADD_STRUCT(int, TeamSize, 44)
		ADD_STRUCT(ScriptString*, LocalizationString, 20)
		ADD_STRUCT(int, LoadBalanceId, 16)
		ADD_STRUCT(int, PlaylistId, 12)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
