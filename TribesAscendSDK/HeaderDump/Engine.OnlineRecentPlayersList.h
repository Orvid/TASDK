#pragma once
#include "Core.Object.h"
#include "Engine.OnlineRecentPlayersList.CurrentPlayerMet.h"
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#include "Engine.OnlineRecentPlayersList.RecentParty.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class OnlineRecentPlayersList : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<OnlineSubsystem__UniqueNetId>, RecentPlayers, 60)
		ADD_STRUCT(ScriptArray<OnlineRecentPlayersList__RecentParty>, RecentParties, 72)
		ADD_STRUCT(ScriptArray<OnlineRecentPlayersList__CurrentPlayerMet>, CurrentPlayers, 120)
		ADD_STRUCT(int, RecentPartiesAddIndex, 116)
		ADD_STRUCT(int, RecentPlayersAddIndex, 112)
		ADD_STRUCT(int, MaxRecentParties, 108)
		ADD_STRUCT(int, MaxRecentPlayers, 104)
		ADD_STRUCT(OnlineRecentPlayersList__RecentParty, LastParty, 84)
		void AddPlayerToRecentPlayers(OnlineSubsystem__UniqueNetId NewPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22681);
			byte params[8] = { NULL };
			*(OnlineSubsystem__UniqueNetId*)params = NewPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearRecentPlayers()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22684);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddPartyToRecentParties(OnlineSubsystem__UniqueNetId PartyLeader, ScriptArray<OnlineSubsystem__UniqueNetId>& PartyMembers)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22685);
			byte params[20] = { NULL };
			*(OnlineSubsystem__UniqueNetId*)params = PartyLeader;
			*(ScriptArray<OnlineSubsystem__UniqueNetId>*)&params[8] = PartyMembers;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PartyMembers = *(ScriptArray<OnlineSubsystem__UniqueNetId>*)&params[8];
		}
		void ClearRecentParties()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22690);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GetPlayersFromRecentParties(ScriptArray<OnlineSubsystem__UniqueNetId>& Players)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22691);
			byte params[12] = { NULL };
			*(ScriptArray<OnlineSubsystem__UniqueNetId>*)params = Players;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Players = *(ScriptArray<OnlineSubsystem__UniqueNetId>*)params;
		}
		void GetPlayersFromCurrentPlayers(ScriptArray<OnlineSubsystem__UniqueNetId>& Players)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22697);
			byte params[12] = { NULL };
			*(ScriptArray<OnlineSubsystem__UniqueNetId>*)params = Players;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Players = *(ScriptArray<OnlineSubsystem__UniqueNetId>*)params;
		}
		int GetSkillForCurrentPlayer(OnlineSubsystem__UniqueNetId Player)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22701);
			byte params[12] = { NULL };
			*(OnlineSubsystem__UniqueNetId*)params = Player;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int GetTeamForCurrentPlayer(OnlineSubsystem__UniqueNetId Player)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22705);
			byte params[12] = { NULL };
			*(OnlineSubsystem__UniqueNetId*)params = Player;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		void SetLastParty(OnlineSubsystem__UniqueNetId PartyLeader, ScriptArray<OnlineSubsystem__UniqueNetId>& PartyMembers)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22709);
			byte params[20] = { NULL };
			*(OnlineSubsystem__UniqueNetId*)params = PartyLeader;
			*(ScriptArray<OnlineSubsystem__UniqueNetId>*)&params[8] = PartyMembers;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PartyMembers = *(ScriptArray<OnlineSubsystem__UniqueNetId>*)&params[8];
		}
		bool ShowRecentPlayerList(byte LocalUserNum, ScriptString* Title, ScriptString* Description)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22713);
			byte params[29] = { NULL };
			*params = LocalUserNum;
			*(ScriptString**)&params[4] = Title;
			*(ScriptString**)&params[16] = Description;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		bool ShowRecentPartiesPlayerList(byte LocalUserNum, ScriptString* Title, ScriptString* Description)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22719);
			byte params[29] = { NULL };
			*params = LocalUserNum;
			*(ScriptString**)&params[4] = Title;
			*(ScriptString**)&params[16] = Description;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		bool ShowLastPartyPlayerList(byte LocalUserNum, ScriptString* Title, ScriptString* Description)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22727);
			byte params[29] = { NULL };
			*params = LocalUserNum;
			*(ScriptString**)&params[4] = Title;
			*(ScriptString**)&params[16] = Description;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		bool ShowCurrentPlayersList(byte LocalUserNum, ScriptString* Title, ScriptString* Description)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22733);
			byte params[29] = { NULL };
			*params = LocalUserNum;
			*(ScriptString**)&params[4] = Title;
			*(ScriptString**)&params[16] = Description;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		void SetCurrentPlayersList(ScriptArray<OnlineRecentPlayersList__CurrentPlayerMet> Players)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22741);
			byte params[12] = { NULL };
			*(ScriptArray<OnlineRecentPlayersList__CurrentPlayerMet>*)params = Players;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetCurrentPlayersListCount()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22744);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
	};
}
#undef ADD_STRUCT
