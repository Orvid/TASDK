#pragma once
#include "IpDrv.PartyBeaconClient.EPartyBeaconClientRequest.h"
#include "IpDrv.PartyBeacon.PartyReservation.h"
#include "IpDrv.PartyBeaconClient.EPartyBeaconClientState.h"
#include "IpDrv.PartyBeacon.h"
#include "IpDrv.ClientBeaconAddressResolver.h"
#include "IpDrv.PartyBeacon.PlayerReservation.h"
#include "Engine.OnlineGameSearch.OnlineGameSearchResult.h"
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#include "IpDrv.PartyBeacon.EPartyReservationResult.h"
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
	class PartyBeaconClient : public PartyBeacon
	{
	public:
		ADD_OBJECT(ClientBeaconAddressResolver, Resolver, 164)
		ADD_OBJECT(ScriptClass, ResolverClass, 160)
		ADD_STRUCT(ScriptString*, ResolverClassName, 148)
		ADD_STRUCT(float, ReservationRequestElapsedTime, 144)
		ADD_STRUCT(float, ReservationRequestTimeout, 140)
		ADD_STRUCT(PartyBeaconClient__EPartyBeaconClientRequest, ClientBeaconRequestType, 137)
		ADD_STRUCT(PartyBeaconClient__EPartyBeaconClientState, ClientBeaconState, 136)
		ADD_STRUCT(OnlineGameSearch__OnlineGameSearchResult, HostPendingRequest, 104)
		ADD_STRUCT(PartyBeacon__PartyReservation, PendingRequest, 112)
		void OnHostHasCancelled()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33911);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnHostIsReady()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33913);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnTravelRequestReceived(ScriptName SessionName, ScriptClass* SearchClass, byte PlatformSpecificInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33915);
			byte params[13] = { NULL };
			*(ScriptName*)params = SessionName;
			*(ScriptClass**)&params[8] = SearchClass;
			params[12] = PlatformSpecificInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnReservationCountUpdated(int ReservationRemaining)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33917);
			byte params[4] = { NULL };
			*(int*)params = ReservationRemaining;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnReservationRequestComplete(PartyBeacon__EPartyReservationResult ReservationResult)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33919);
			byte params[1] = { NULL };
			*(PartyBeacon__EPartyReservationResult*)params = ReservationResult;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool RequestReservation(OnlineGameSearch__OnlineGameSearchResult& DesiredHost, OnlineSubsystem__UniqueNetId RequestingPartyLeader, ScriptArray<PartyBeacon__PlayerReservation>& Players)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33936);
			byte params[32] = { NULL };
			*(OnlineGameSearch__OnlineGameSearchResult*)params = DesiredHost;
			*(OnlineSubsystem__UniqueNetId*)&params[8] = RequestingPartyLeader;
			*(ScriptArray<PartyBeacon__PlayerReservation>*)&params[16] = Players;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DesiredHost = *(OnlineGameSearch__OnlineGameSearchResult*)params;
			Players = *(ScriptArray<PartyBeacon__PlayerReservation>*)&params[16];
			return *(bool*)&params[28];
		}
		bool RequestReservationUpdate(OnlineGameSearch__OnlineGameSearchResult& DesiredHost, OnlineSubsystem__UniqueNetId RequestingPartyLeader, ScriptArray<PartyBeacon__PlayerReservation>& PlayersToAdd)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33942);
			byte params[32] = { NULL };
			*(OnlineGameSearch__OnlineGameSearchResult*)params = DesiredHost;
			*(OnlineSubsystem__UniqueNetId*)&params[8] = RequestingPartyLeader;
			*(ScriptArray<PartyBeacon__PlayerReservation>*)&params[16] = PlayersToAdd;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DesiredHost = *(OnlineGameSearch__OnlineGameSearchResult*)params;
			PlayersToAdd = *(ScriptArray<PartyBeacon__PlayerReservation>*)&params[16];
			return *(bool*)&params[28];
		}
		bool CancelReservation(OnlineSubsystem__UniqueNetId CancellingPartyLeader)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33948);
			byte params[12] = { NULL };
			*(OnlineSubsystem__UniqueNetId*)params = CancellingPartyLeader;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void DestroyBeacon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33951);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
