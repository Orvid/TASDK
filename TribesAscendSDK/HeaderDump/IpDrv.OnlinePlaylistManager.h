#pragma once
namespace UnrealScript
{
	class OnlinePlaylistManager;
}
#include "Core.Object.h"
#include "Core.Object.Pointer.h"
#include "Engine.OnlineGameSettings.h"
#include "IpDrv.OnlinePlaylistManager.ConfiguredGameSetting.h"
#include "IpDrv.OnlinePlaylistManager.InventorySwap.h"
#include "IpDrv.OnlinePlaylistManager.Playlist.h"
#include "IpDrv.OnlinePlaylistManager.PlaylistPopulation.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class OnlinePlaylistManager : public Object
	{
	public:
		typedef OnlinePlaylistManager__Playlist Playlist;
		typedef OnlinePlaylistManager__PlaylistPopulation PlaylistPopulation;
		typedef OnlinePlaylistManager__ConfiguredGameSetting ConfiguredGameSetting;
		typedef OnlinePlaylistManager__InventorySwap InventorySwap;
		ADD_STRUCT(ScriptArray<OnlinePlaylistManager__Playlist>, Playlists, 64)
		ADD_STRUCT(ScriptArray<ScriptString*>, PlaylistFileNames, 76)
		ADD_STRUCT(ScriptArray<ScriptName>, DatastoresToRefresh, 88)
		ADD_STRUCT(ScriptArray<OnlinePlaylistManager__PlaylistPopulation>, PopulationData, 112)
		ADD_STRUCT(ScriptString*, DataCenterFileName, 180)
		ADD_STRUCT(int, DataCenterId, 176)
		ADD_STRUCT(ScriptName, EventsInterfaceName, 168)
		ADD_STRUCT(int, CurrentPlaylistId, 164)
		ADD_STRUCT(int, MinPlaylistIdToReport, 160)
		ADD_STRUCT(float, PlaylistPopulationUpdateInterval, 156)
		ADD_STRUCT(float, NextPlaylistPopulationUpdateTime, 152)
		ADD_STRUCT(ScriptString*, PopulationFileName, 140)
		ADD_STRUCT(int, RegionTotalPlayers, 128)
		ADD_STRUCT(int, WorldwideTotalPlayers, 124)
		ADD_STRUCT(int, VersionNumber, 108)
		ADD_STRUCT(int, SuccessfulCount, 104)
		ADD_STRUCT(int, DownloadCount, 100)
		ADD_STRUCT(Object__Pointer, VfTable_FTickableObject, 60)
		void OnPlaylistPopulationDataUpdated()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33686);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnReadPlaylistComplete()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33688);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DownloadPlaylist()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33733);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DetermineFilesToDownload()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33736);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnReadTitleFileComplete(bool bWasSuccessful, ScriptString* Filename)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33737);
			byte params[16] = { NULL };
			*(bool*)params = bWasSuccessful;
			*(ScriptString**)&params[4] = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FinalizePlaylistObjects()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33742);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class OnlineGameSettings* GetGameSettings(int PlaylistId, int GameSettingsId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33743);
			byte params[12] = { NULL };
			*(int*)params = PlaylistId;
			*(int*)&params[4] = GameSettingsId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class OnlineGameSettings**)&params[8];
		}
		bool HasAnyGameSettings(int PlaylistId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33749);
			byte params[8] = { NULL };
			*(int*)params = PlaylistId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool PlaylistSupportsDedicatedServers(int PlaylistId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33754);
			byte params[8] = { NULL };
			*(int*)params = PlaylistId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void GetTeamInfoFromPlaylist(int PlaylistId, int& TeamSize, int& TeamCount, int& MaxPartySize)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33758);
			byte params[16] = { NULL };
			*(int*)params = PlaylistId;
			*(int*)&params[4] = TeamSize;
			*(int*)&params[8] = TeamCount;
			*(int*)&params[12] = MaxPartySize;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			TeamSize = *(int*)&params[4];
			TeamCount = *(int*)&params[8];
			MaxPartySize = *(int*)&params[12];
		}
		void GetLoadBalanceIdFromPlaylist(int PlaylistId, int& LoadBalanceId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33764);
			byte params[8] = { NULL };
			*(int*)params = PlaylistId;
			*(int*)&params[4] = LoadBalanceId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			LoadBalanceId = *(int*)&params[4];
		}
		bool IsPlaylistArbitrated(int PlaylistId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33768);
			byte params[8] = { NULL };
			*(int*)params = PlaylistId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		ScriptString* GetUrlFromPlaylist(int PlaylistId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33772);
			byte params[16] = { NULL };
			*(int*)params = PlaylistId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		void GetMapCycleFromPlaylist(int PlaylistId, ScriptArray<ScriptName>& MapCycle)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33776);
			byte params[16] = { NULL };
			*(int*)params = PlaylistId;
			*(ScriptArray<ScriptName>*)&params[4] = MapCycle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			MapCycle = *(ScriptArray<ScriptName>*)&params[4];
		}
		ScriptClass* GetInventorySwapFromPlaylist(int PlaylistId, ScriptClass* SourceInventory)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33781);
			byte params[12] = { NULL };
			*(int*)params = PlaylistId;
			*(ScriptClass**)&params[4] = SourceInventory;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[8];
		}
		void GetContentIdsFromPlaylist(int PlaylistId, ScriptArray<int>& ContentIds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33787);
			byte params[16] = { NULL };
			*(int*)params = PlaylistId;
			*(ScriptArray<int>*)&params[4] = ContentIds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ContentIds = *(ScriptArray<int>*)&params[4];
		}
		void Reset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33792);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReadPlaylistPopulation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33794);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnReadPlaylistPopulationComplete(bool bWasSuccessful, ScriptString* Filename)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33796);
			byte params[16] = { NULL };
			*(bool*)params = bWasSuccessful;
			*(ScriptString**)&params[4] = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ParsePlaylistPopulationData(ScriptArray<byte>& Data)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33801);
			byte params[12] = { NULL };
			*(ScriptArray<byte>*)params = Data;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Data = *(ScriptArray<byte>*)params;
		}
		void GetPopulationInfoFromPlaylist(int PlaylistId, int& WorldwideTotal, int& RegionTotal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33804);
			byte params[12] = { NULL };
			*(int*)params = PlaylistId;
			*(int*)&params[4] = WorldwideTotal;
			*(int*)&params[8] = RegionTotal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			WorldwideTotal = *(int*)&params[4];
			RegionTotal = *(int*)&params[8];
		}
		void SendPlaylistPopulationUpdate(int NumPlayers)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33809);
			byte params[4] = { NULL };
			*(int*)params = NumPlayers;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReadDataCenterId()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33813);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnReadDataCenterIdComplete(bool bWasSuccessful, ScriptString* Filename)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33815);
			byte params[16] = { NULL };
			*(bool*)params = bWasSuccessful;
			*(ScriptString**)&params[4] = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ParseDataCenterId(ScriptArray<byte>& Data)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33820);
			byte params[12] = { NULL };
			*(ScriptArray<byte>*)params = Data;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Data = *(ScriptArray<byte>*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
