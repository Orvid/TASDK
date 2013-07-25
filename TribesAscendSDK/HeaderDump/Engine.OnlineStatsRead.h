#pragma once
#include "Engine.OnlineStats.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.OnlineStatsRead." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlineStatsRead : public OnlineStats
	{
	public:
		ADD_VAR(::IntProperty, TitleId, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ViewName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TotalRowsInView, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SortColumnId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ViewId, 0xFFFFFFFF)
		void OnReadComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsRead.OnReadComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool GetIntStatValueForPlayer(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PlayerID, int StatColumnNo, int& StatValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsRead.GetIntStatValueForPlayer");
			byte* params = (byte*)malloc(20);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = PlayerID;
			*(int*)(params + 8) = StatColumnNo;
			*(int*)(params + 12) = StatValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			StatValue = *(int*)(params + 12);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool SetIntStatValueForPlayer(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PlayerID, int StatColumnNo, int StatValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsRead.SetIntStatValueForPlayer");
			byte* params = (byte*)malloc(20);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = PlayerID;
			*(int*)(params + 8) = StatColumnNo;
			*(int*)(params + 12) = StatValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool GetFloatStatValueForPlayer(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PlayerID, int StatColumnNo, float& StatValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsRead.GetFloatStatValueForPlayer");
			byte* params = (byte*)malloc(20);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = PlayerID;
			*(int*)(params + 8) = StatColumnNo;
			*(float*)(params + 12) = StatValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			StatValue = *(float*)(params + 12);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool SetFloatStatValueForPlayer(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PlayerID, int StatColumnNo, float StatValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsRead.SetFloatStatValueForPlayer");
			byte* params = (byte*)malloc(20);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = PlayerID;
			*(int*)(params + 8) = StatColumnNo;
			*(float*)(params + 12) = StatValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void AddPlayer(ScriptArray<wchar_t> PlayerName, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsRead.AddPlayer");
			byte* params = (byte*)malloc(20);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 12) = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetRankForPlayer(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsRead.GetRankForPlayer");
			byte* params = (byte*)malloc(12);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR