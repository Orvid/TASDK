#pragma once
namespace UnrealScript
{
	class OnlineSuppliedUIInterface;
}
#include "Core.Interface.h"
#include "Engine.OnlineGameSearch.h"
#include "Engine.OnlineGameSettings.h"
#include "Engine.OnlineStatsRead.h"
#include "Engine.OnlineSubsystem.UniqueNetId.h"
namespace UnrealScript
{
	class OnlineSuppliedUIInterface : public Interface
	{
	public:
		void OnShowOnlineStatsUIComplete()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22903);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShowOnlineStatsUI(ScriptArray<OnlineSubsystem__UniqueNetId>& Players, class OnlineStatsRead* StatsRead)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22905);
			byte params[20] = { NULL };
			*(ScriptArray<OnlineSubsystem__UniqueNetId>*)params = Players;
			*(class OnlineStatsRead**)&params[12] = StatsRead;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Players = *(ScriptArray<OnlineSubsystem__UniqueNetId>*)params;
			return *(bool*)&params[16];
		}
		void AddShowOnlineStatsUICompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ShowOnlineStatsUICompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22910);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ShowOnlineStatsUICompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearShowOnlineStatsUICompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ShowOnlineStatsUICompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22912);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ShowOnlineStatsUICompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShowMatchmakingUI(byte SearchingPlayerNum, class OnlineGameSearch* SearchSettings, class OnlineGameSettings* GameSettings)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22914);
			byte params[13] = { NULL };
			*params = SearchingPlayerNum;
			*(class OnlineGameSearch**)&params[4] = SearchSettings;
			*(class OnlineGameSettings**)&params[8] = GameSettings;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
	};
}
