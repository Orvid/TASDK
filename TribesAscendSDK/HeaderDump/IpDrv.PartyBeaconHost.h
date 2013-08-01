#pragma once
#include "IpDrv.PartyBeacon.PartyReservation.h"
#include "IpDrv.PartyBeacon.h"
#include "Engine.OnlineGameSearch.h"
#include "IpDrv.PartyBeacon.EPartyReservationResult.h"
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#include "IpDrv.PartyBeaconHost.ClientBeaconConnection.h"
#include "IpDrv.PartyBeaconHost.EPartyBeaconHostState.h"
#include "IpDrv.PartyBeacon.PlayerReservation.h"
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
	class PartyBeaconHost : public PartyBeacon
	{
	public:
		ADD_STRUCT(ScriptArray<PartyBeaconHost__ClientBeaconConnection>, Clients, 104)
		ADD_STRUCT(ScriptArray<PartyBeacon__PartyReservation>, Reservations, 132)
		ADD_STRUCT(PartyBeaconHost__EPartyBeaconHostState, BeaconState, 168)
		ADD_BOOL(bBestFitTeamAssignment, 164, 0x1)
		ADD_STRUCT(int, ReservedHostTeamNum, 160)
		ADD_STRUCT(int, ForceTeamNum, 156)
		ADD_STRUCT(int, ConnectionBacklog, 152)
		ADD_STRUCT(ScriptName, OnlineSessionName, 144)
		ADD_STRUCT(int, NumConsumedReservations, 128)
		ADD_STRUCT(int, NumReservations, 124)
		ADD_STRUCT(int, NumPlayersPerTeam, 120)
		ADD_STRUCT(int, NumTeams, 116)
		void OnClientCancellationReceived(OnlineSubsystem__UniqueNetId PartyLeader)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33961);
			byte params[8] = { NULL };
			*(OnlineSubsystem__UniqueNetId*)params = PartyLeader;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnReservationsFull()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33963);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnReservationChange()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33965);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PauseReservationRequests(bool bPause)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33977);
			byte params[4] = { NULL };
			*(bool*)params = bPause;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool InitHostBeacon(int InNumTeams, int InNumPlayersPerTeam, int InNumReservations, ScriptName InSessionName, int InForceTeamNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33979);
			byte params[28] = { NULL };
			*(int*)params = InNumTeams;
			*(int*)&params[4] = InNumPlayersPerTeam;
			*(int*)&params[8] = InNumReservations;
			*(ScriptName*)&params[12] = InSessionName;
			*(int*)&params[20] = InForceTeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		PartyBeacon__EPartyReservationResult AddPartyReservationEntry(OnlineSubsystem__UniqueNetId PartyLeader, ScriptArray<PartyBeacon__PlayerReservation>& PlayerMembers, int TeamNum, bool bIsHost)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33986);
			byte params[29] = { NULL };
			*(OnlineSubsystem__UniqueNetId*)params = PartyLeader;
			*(ScriptArray<PartyBeacon__PlayerReservation>*)&params[8] = PlayerMembers;
			*(int*)&params[20] = TeamNum;
			*(bool*)&params[24] = bIsHost;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PlayerMembers = *(ScriptArray<PartyBeacon__PlayerReservation>*)&params[8];
			return *(PartyBeacon__EPartyReservationResult*)&params[28];
		}
		PartyBeacon__EPartyReservationResult UpdatePartyReservationEntry(OnlineSubsystem__UniqueNetId PartyLeader, ScriptArray<PartyBeacon__PlayerReservation>& PlayerMembers)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33993);
			byte params[21] = { NULL };
			*(OnlineSubsystem__UniqueNetId*)params = PartyLeader;
			*(ScriptArray<PartyBeacon__PlayerReservation>*)&params[8] = PlayerMembers;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PlayerMembers = *(ScriptArray<PartyBeacon__PlayerReservation>*)&params[8];
			return *(PartyBeacon__EPartyReservationResult*)&params[20];
		}
		int GetExistingReservation(OnlineSubsystem__UniqueNetId& PartyLeader)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33998);
			byte params[12] = { NULL };
			*(OnlineSubsystem__UniqueNetId*)params = PartyLeader;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PartyLeader = *(OnlineSubsystem__UniqueNetId*)params;
			return *(int*)&params[8];
		}
		void HandlePlayerLogout(OnlineSubsystem__UniqueNetId PlayerID, bool bMaintainParty)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34001);
			byte params[12] = { NULL };
			*(OnlineSubsystem__UniqueNetId*)params = PlayerID;
			*(bool*)&params[8] = bMaintainParty;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DestroyBeacon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34005);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TellClientsToTravel(ScriptName SessionName, ScriptClass* SearchClass, byte PlatformSpecificInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34006);
			byte params[13] = { NULL };
			*(ScriptName*)params = SessionName;
			*(ScriptClass**)&params[8] = SearchClass;
			params[12] = PlatformSpecificInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TellClientsHostIsReady()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34010);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TellClientsHostHasCancelled()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34011);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool AreReservationsFull()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34012);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void RegisterPartyMembers()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34014);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UnregisterPartyMembers()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34022);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UnregisterParty(OnlineSubsystem__UniqueNetId PartyLeader)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34027);
			byte params[8] = { NULL };
			*(OnlineSubsystem__UniqueNetId*)params = PartyLeader;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AppendReservationSkillsToSearch(class OnlineGameSearch* Search)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34033);
			byte params[4] = { NULL };
			*(class OnlineGameSearch**)params = Search;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetPlayers(ScriptArray<OnlineSubsystem__UniqueNetId>& Players)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34035);
			byte params[12] = { NULL };
			*(ScriptArray<OnlineSubsystem__UniqueNetId>*)params = Players;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Players = *(ScriptArray<OnlineSubsystem__UniqueNetId>*)params;
		}
		void GetPartyLeaders(ScriptArray<OnlineSubsystem__UniqueNetId>& PartyLeaders)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34041);
			byte params[12] = { NULL };
			*(ScriptArray<OnlineSubsystem__UniqueNetId>*)params = PartyLeaders;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PartyLeaders = *(ScriptArray<OnlineSubsystem__UniqueNetId>*)params;
		}
		int GetMaxAvailableTeamSize()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34045);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
