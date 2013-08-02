#pragma once
namespace UnrealScript
{
	class GameplayEvents;
}
#include "Core.Object.h"
#include "Core.Object.Pointer.h"
#include "Engine.GameplayEvents.DamageClassEventData.h"
#include "Engine.GameplayEvents.EGameStatGroups.h"
#include "Engine.GameplayEvents.GameSessionInformation.h"
#include "Engine.GameplayEvents.GameStatGroup.h"
#include "Engine.GameplayEvents.GameplayEventMetaData.h"
#include "Engine.GameplayEvents.GameplayEventsHeader.h"
#include "Engine.GameplayEvents.PawnClassEventData.h"
#include "Engine.GameplayEvents.PlayerInformationNew.h"
#include "Engine.GameplayEvents.ProjectileClassEventData.h"
#include "Engine.GameplayEvents.TeamInformation.h"
#include "Engine.GameplayEvents.WeaponClassEventData.h"
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
	class GameplayEvents : public Object
	{
	public:
		typedef GameplayEvents__EGameStatGroups EGameStatGroups;
		typedef GameplayEvents__PlayerInformationNew PlayerInformationNew;
		typedef GameplayEvents__TeamInformation TeamInformation;
		typedef GameplayEvents__GameplayEventMetaData GameplayEventMetaData;
		typedef GameplayEvents__WeaponClassEventData WeaponClassEventData;
		typedef GameplayEvents__DamageClassEventData DamageClassEventData;
		typedef GameplayEvents__ProjectileClassEventData ProjectileClassEventData;
		typedef GameplayEvents__PawnClassEventData PawnClassEventData;
		typedef GameplayEvents__GameStatGroup GameStatGroup;
		typedef GameplayEvents__GameplayEventsHeader GameplayEventsHeader;
		typedef GameplayEvents__GameSessionInformation GameSessionInformation;
		static const auto HeaderFlags_NoEventStrings = 1;
		ADD_STRUCT(ScriptArray<GameplayEvents__PlayerInformationNew>, PlayerList, 228)
		ADD_STRUCT(ScriptArray<GameplayEvents__TeamInformation>, TeamList, 240)
		ADD_STRUCT(ScriptArray<GameplayEvents__GameplayEventMetaData>, SupportedEvents, 252)
		ADD_STRUCT(ScriptArray<GameplayEvents__WeaponClassEventData>, WeaponClassArray, 264)
		ADD_STRUCT(ScriptArray<GameplayEvents__DamageClassEventData>, DamageClassArray, 276)
		ADD_STRUCT(ScriptArray<GameplayEvents__ProjectileClassEventData>, ProjectileClassArray, 288)
		ADD_STRUCT(ScriptArray<GameplayEvents__PawnClassEventData>, PawnClassArray, 300)
		ADD_STRUCT(ScriptArray<ScriptString*>, ActorArray, 312)
		ADD_STRUCT(ScriptArray<ScriptString*>, SoundCueArray, 324)
		ADD_STRUCT(GameplayEvents__GameSessionInformation, CurrentSessionInfo, 120)
		ADD_STRUCT(GameplayEvents__GameplayEventsHeader, Header, 76)
		ADD_STRUCT(ScriptString*, StatsFileName, 64)
		ADD_STRUCT(Object__Pointer, Archive, 60)
		bool OpenStatsFile(ScriptString* Filename)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17548);
			byte params[16] = { NULL };
			*(ScriptString**)params = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void CloseStatsFile()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17551);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* GetFilename()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17552);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
