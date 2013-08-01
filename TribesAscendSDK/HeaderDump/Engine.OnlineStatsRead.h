#pragma once
#include "Engine.OnlineStatsRead.ColumnMetaData.h"
#include "Engine.OnlineStats.h"
#include "Engine.OnlineStatsRead.OnlineStatsRow.h"
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class OnlineStatsRead : public OnlineStats
	{
	public:
		ADD_STRUCT(ScriptArray<int>, ColumnIds, 80)
		ADD_STRUCT(ScriptArray<OnlineStatsRead__OnlineStatsRow>, Rows, 96)
		ADD_STRUCT(ScriptArray<OnlineStatsRead__ColumnMetaData>, ColumnMappings, 108)
		ADD_STRUCT(int, TitleId, 132)
		ADD_STRUCT(ScriptString*, ViewName, 120)
		ADD_STRUCT(int, TotalRowsInView, 92)
		ADD_STRUCT(int, SortColumnId, 76)
		ADD_STRUCT(int, ViewId, 72)
		void OnReadComplete()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22839);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool GetIntStatValueForPlayer(OnlineSubsystem__UniqueNetId PlayerID, int StatColumnNo, int& StatValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22840);
			byte params[20] = { NULL };
			*(OnlineSubsystem__UniqueNetId*)params = PlayerID;
			*(int*)&params[8] = StatColumnNo;
			*(int*)&params[12] = StatValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			StatValue = *(int*)&params[12];
			return *(bool*)&params[16];
		}
		bool SetIntStatValueForPlayer(OnlineSubsystem__UniqueNetId PlayerID, int StatColumnNo, int StatValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22845);
			byte params[20] = { NULL };
			*(OnlineSubsystem__UniqueNetId*)params = PlayerID;
			*(int*)&params[8] = StatColumnNo;
			*(int*)&params[12] = StatValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool GetFloatStatValueForPlayer(OnlineSubsystem__UniqueNetId PlayerID, int StatColumnNo, float& StatValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22850);
			byte params[20] = { NULL };
			*(OnlineSubsystem__UniqueNetId*)params = PlayerID;
			*(int*)&params[8] = StatColumnNo;
			*(float*)&params[12] = StatValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			StatValue = *(float*)&params[12];
			return *(bool*)&params[16];
		}
		bool SetFloatStatValueForPlayer(OnlineSubsystem__UniqueNetId PlayerID, int StatColumnNo, float StatValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22855);
			byte params[20] = { NULL };
			*(OnlineSubsystem__UniqueNetId*)params = PlayerID;
			*(int*)&params[8] = StatColumnNo;
			*(float*)&params[12] = StatValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void AddPlayer(ScriptString* PlayerName, OnlineSubsystem__UniqueNetId PlayerID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22860);
			byte params[20] = { NULL };
			*(ScriptString**)params = PlayerName;
			*(OnlineSubsystem__UniqueNetId*)&params[12] = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetRankForPlayer(OnlineSubsystem__UniqueNetId PlayerID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22863);
			byte params[12] = { NULL };
			*(OnlineSubsystem__UniqueNetId*)params = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
	};
}
#undef ADD_STRUCT
