#pragma once
namespace UnrealScript
{
	class TrMusicManager;
}
#include "Engine.Info.h"
#include "Engine.SoundCue.h"
#include "TribesGame.TrMusicManager.ETgMusicState.h"
#include "TribesGame.TrPlayerController.h"
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
	class TrMusicManager : public Info
	{
	public:
		typedef TrMusicManager__ETgMusicState ETgMusicState;
		ADD_OBJECT(TrPlayerController, m_PlayerOwner, 476)
		ADD_STRUCT(float, m_fMusicVolume, 480)
		ADD_STRUCT(TrMusicManager__ETgMusicState, m_CurrentState, 488)
		ADD_STRUCT(TrMusicManager__ETgMusicState, m_PendingState, 489)
		ADD_STRUCT(float, m_fStingerVolumeMultiplier, 484)
		ADD_STRUCT(float, m_CTFTeamScores, 532)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100250);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* CreateNewTrack(class SoundCue* MusicCue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100251);
			byte params[8] = { NULL };
			*(class SoundCue**)params = MusicCue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4];
		}
		void StartMusic()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100256);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetStateBasedOnGameState()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100258);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100263);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MusicEvent(int NewEventIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100267);
			byte params[4] = { NULL };
			*(int*)params = NewEventIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPendingState(TrMusicManager__ETgMusicState NewState)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100273);
			byte params[1] = { NULL };
			*(TrMusicManager__ETgMusicState*)params = NewState;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCurrentState(TrMusicManager__ETgMusicState NewState)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100275);
			byte params[1] = { NULL };
			*(TrMusicManager__ETgMusicState*)params = NewState;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayerScoredFlag()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100280);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
