#pragma once
namespace UnrealScript
{
	class TrPlayerVoice;
}
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.SoundCue.h"
#include "TribesGame.TrDevice.h"
#include "TribesGame.TrPlayerController.h"
#include "TribesGame.TrPlayerVoice.VGSCommandToVoiceMap.h"
#include "TribesGame.TrPlayerVoice.VGSContextCommandToVoiceMap.h"
#include "TribesGame.TrVGSCommandList.EVGSContextActor.h"
#include "TribesGame.TrVGSCommandList.EVGSContextLocation.h"
#include "TribesGame.TrVGSCommandList.VGSCommandType.h"
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
	class TrPlayerVoice : public TrDevice
	{
	public:
		typedef TrPlayerVoice__VGSCommandToVoiceMap VGSCommandToVoiceMap;
		typedef TrPlayerVoice__VGSContextCommandToVoiceMap VGSContextCommandToVoiceMap;
		ADD_STRUCT(ScriptArray<TrPlayerVoice__VGSCommandToVoiceMap>, m_VGSCommandToVoiceMap, 2148)
		ADD_STRUCT(ScriptArray<class SoundCue*>, m_VGSSampleMap, 2160)
		ADD_STRUCT(ScriptArray<TrPlayerVoice__VGSContextCommandToVoiceMap>, m_VGSContextCommandToVoiceMap, 2172)
		void PlaySoundEx(TrVGSCommandList__VGSCommandType Command, class TrPlayerController* TrPC, class PlayerReplicationInfo* InstigatorPRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(101604);
			byte params[9] = { NULL };
			*(TrVGSCommandList__VGSCommandType*)params = Command;
			*(class TrPlayerController**)&params[4] = TrPC;
			*(class PlayerReplicationInfo**)&params[8] = InstigatorPRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlaySoundContext(class TrPlayerController* TrPC, TrVGSCommandList__EVGSContextActor ContextActor, TrVGSCommandList__EVGSContextLocation ContextLocation, bool bEnemyLocation, class PlayerReplicationInfo* InstigatorPRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(101610);
			byte params[14] = { NULL };
			*(class TrPlayerController**)params = TrPC;
			*(TrVGSCommandList__EVGSContextActor*)&params[4] = ContextActor;
			*(TrVGSCommandList__EVGSContextLocation*)&params[5] = ContextLocation;
			*(bool*)&params[8] = bEnemyLocation;
			*(class PlayerReplicationInfo**)&params[12] = InstigatorPRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayRandomSample(class TrPlayerController* TrPC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(101618);
			byte params[4] = { NULL };
			*(class TrPlayerController**)params = TrPC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
