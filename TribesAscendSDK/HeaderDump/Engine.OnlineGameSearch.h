#pragma once
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#include "Engine.Settings.h"
#include "Engine.OnlineGameSearch.OverrideSkill.h"
#include "Engine.Settings.LocalizedStringSetting.h"
#include "Engine.OnlineGameSearch.OnlineGameSearchResult.h"
#include "Engine.OnlineGameSearch.NamedObjectProperty.h"
#include "Engine.OnlineGameSearch.OnlineGameSearchQuery.h"
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
	class OnlineGameSearch : public Settings
	{
	public:
		ADD_STRUCT(OnlineGameSearch__OverrideSkill, ManualSkillOverride, 144)
		ADD_STRUCT(int, MaxSearchResults, 108)
		ADD_STRUCT(Settings__LocalizedStringSetting, Query, 112)
		ADD_BOOL(bIsLanQuery, 124, 0x1)
		ADD_BOOL(bUsesArbitration, 124, 0x2)
		ADD_BOOL(bIsSearchInProgress, 124, 0x4)
		ADD_OBJECT(ScriptClass, GameSettingsClass, 128)
		ADD_STRUCT(ScriptArray<OnlineGameSearch__OnlineGameSearchResult>, Results, 132)
		ADD_STRUCT(ScriptArray<OnlineGameSearch__NamedObjectProperty>, NamedProperties, 184)
		ADD_STRUCT(OnlineGameSearch__OnlineGameSearchQuery, FilterQuery, 196)
		ADD_STRUCT(ScriptString*, AdditionalSearchCriteria, 220)
		ADD_STRUCT(int, PingBucketSize, 232)
		void SortSearchResults()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6865);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetSkillOverride(int LeaderboardId, ScriptArray<OnlineSubsystem__UniqueNetId>& Players)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6866);
			byte params[16] = { NULL };
			*(int*)params = LeaderboardId;
			*(ScriptArray<OnlineSubsystem__UniqueNetId>*)&params[4] = Players;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Players = *(ScriptArray<OnlineSubsystem__UniqueNetId>*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
