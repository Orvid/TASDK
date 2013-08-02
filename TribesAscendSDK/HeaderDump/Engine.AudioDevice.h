#pragma once
namespace UnrealScript
{
	class AudioDevice;
}
#include "Core.Object.Double.h"
#include "Core.Object.Pointer.h"
#include "Core.Subsystem.h"
#include "Engine.AudioDevice.AudioClassInfo.h"
#include "Engine.AudioDevice.EDebugState.h"
#include "Engine.AudioDevice.ESoundClassName.h"
#include "Engine.AudioDevice.ETTSSpeaker.h"
#include "Engine.AudioDevice.Listener.h"
#include "Engine.ReverbVolume.InteriorSettings.h"
#include "Engine.SoundClass.h"
#include "Engine.SoundMode.h"
#include "Engine.SoundNodeWave.h"
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
	class AudioDevice : public Subsystem
	{
	public:
		typedef AudioDevice__EDebugState EDebugState;
		typedef AudioDevice__ESoundClassName ESoundClassName;
		typedef AudioDevice__ETTSSpeaker ETTSSpeaker;
		typedef AudioDevice__Listener Listener;
		typedef AudioDevice__AudioClassInfo AudioClassInfo;
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, AudioComponents, 128)
		ADD_STRUCT(ScriptArray<Object__Pointer>, Sources, 140)
		ADD_STRUCT(ScriptArray<Object__Pointer>, FreeSources, 152)
		ADD_STRUCT(ScriptArray<AudioDevice__Listener>, Listeners, 224)
		ADD_STRUCT(float, LastUpdateTime, 704)
		ADD_STRUCT(float, TransientMasterVolume, 700)
		ADD_STRUCT(AudioDevice__EDebugState, DebugState, 696)
		ADD_STRUCT(Object__Pointer, TextToSpeech, 692)
		ADD_STRUCT(float, ExteriorLPFInterp, 684)
		ADD_STRUCT(float, ExteriorVolumeInterp, 680)
		ADD_STRUCT(float, InteriorLPFInterp, 676)
		ADD_STRUCT(float, InteriorVolumeInterp, 672)
		ADD_STRUCT(Object__Double, ExteriorLPFEndTime, 664)
		ADD_STRUCT(Object__Double, InteriorLPFEndTime, 656)
		ADD_STRUCT(Object__Double, ExteriorEndTime, 648)
		ADD_STRUCT(Object__Double, InteriorEndTime, 640)
		ADD_STRUCT(Object__Double, InteriorStartTime, 632)
		ADD_STRUCT(ReverbVolume__InteriorSettings, ListenerInteriorSettings, 596)
		ADD_STRUCT(int, ListenerVolumeIndex, 592)
		ADD_STRUCT(Object__Double, SoundModeEndTime, 584)
		ADD_STRUCT(Object__Double, SoundModeFadeInEndTime, 576)
		ADD_STRUCT(Object__Double, SoundModeFadeInStartTime, 568)
		ADD_STRUCT(Object__Double, SoundModeStartTime, 560)
		ADD_OBJECT(SoundMode, CurrentMode, 556)
		ADD_STRUCT(ScriptName, BaseSoundModeName, 548)
		ADD_STRUCT(Object__Pointer, Effects, 544)
		ADD_STRUCT(QWord, CurrentTick, 236)
		ADD_STRUCT(int, CommonAudioPoolFreeBytes, 124)
		ADD_STRUCT(Object__Pointer, CommonAudioPool, 120)
		ADD_BOOL(bGameWasTicking, 116, 0x2)
		ADD_BOOL(m_bEnableBassBoost, 116, 0x1)
		ADD_OBJECT(SoundNodeWave, ChirpOutSoundNodeWave, 112)
		ADD_STRUCT(ScriptString*, ChirpOutSoundNodeWaveName, 100)
		ADD_OBJECT(SoundNodeWave, ChirpInSoundNodeWave, 96)
		ADD_STRUCT(ScriptString*, ChirpInSoundNodeWaveName, 84)
		ADD_STRUCT(float, MinCompressedDurationGame, 80)
		ADD_STRUCT(float, MinCompressedDurationEditor, 76)
		ADD_STRUCT(float, LowPassFilterResonance, 72)
		ADD_STRUCT(int, CommonAudioPoolSize, 68)
		ADD_STRUCT(int, MaxChannels, 64)
		bool SetSoundMode(ScriptName NewMode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9511);
			byte params[12] = { NULL };
			*(ScriptName*)params = NewMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		class SoundClass* FindSoundClass(ScriptName SoundClassName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10363);
			byte params[12] = { NULL };
			*(ScriptName*)params = SoundClassName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SoundClass**)&params[8];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
