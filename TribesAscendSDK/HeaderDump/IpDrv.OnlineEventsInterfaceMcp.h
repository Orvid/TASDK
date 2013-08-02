#pragma once
namespace UnrealScript
{
	class OnlineEventsInterfaceMcp;
}
#include "Core.Object.Pointer.h"
#include "Engine.OnlineMatchmakingStats.h"
#include "Engine.OnlinePlayerStorage.h"
#include "Engine.OnlineProfileSettings.h"
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#include "IpDrv.MCPBase.h"
#include "IpDrv.OnlineEventsInterfaceMcp.EEventUploadType.h"
#include "IpDrv.OnlineEventsInterfaceMcp.EventUploadConfig.h"
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
	class OnlineEventsInterfaceMcp : public MCPBase
	{
	public:
		typedef OnlineEventsInterfaceMcp__EEventUploadType EEventUploadType;
		typedef OnlineEventsInterfaceMcp__EventUploadConfig EventUploadConfig;
		ADD_STRUCT(ScriptArray<OnlineEventsInterfaceMcp__EventUploadConfig>, EventUploadConfigs, 64)
		ADD_STRUCT(ScriptArray<Object__Pointer>, HttpPostObjects, 76)
		ADD_STRUCT(ScriptArray<OnlineEventsInterfaceMcp__EEventUploadType>, DisabledUploadTypes, 88)
		ADD_BOOL(bBinaryStats, 100, 0x1)
		bool UploadPlayerData(OnlineSubsystem__UniqueNetId UniqueId, ScriptString* PlayerNick, class OnlineProfileSettings* ProfileSettings, class OnlinePlayerStorage* PlayerStorage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33357);
			byte params[32] = { NULL };
			*(OnlineSubsystem__UniqueNetId*)params = UniqueId;
			*(ScriptString**)&params[8] = PlayerNick;
			*(class OnlineProfileSettings**)&params[20] = ProfileSettings;
			*(class OnlinePlayerStorage**)&params[24] = PlayerStorage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		bool UploadGameplayEventsData(OnlineSubsystem__UniqueNetId UniqueId, ScriptArray<byte>& Payload)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33363);
			byte params[24] = { NULL };
			*(OnlineSubsystem__UniqueNetId*)params = UniqueId;
			*(ScriptArray<byte>*)&params[8] = Payload;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Payload = *(ScriptArray<byte>*)&params[8];
			return *(bool*)&params[20];
		}
		bool UpdatePlaylistPopulation(int PlaylistId, int NumPlayers)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33368);
			byte params[12] = { NULL };
			*(int*)params = PlaylistId;
			*(int*)&params[4] = NumPlayers;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool UploadMatchmakingStats(OnlineSubsystem__UniqueNetId UniqueId, class OnlineMatchmakingStats* MMStats)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33372);
			byte params[16] = { NULL };
			*(OnlineSubsystem__UniqueNetId*)params = UniqueId;
			*(class OnlineMatchmakingStats**)&params[8] = MMStats;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
