#pragma once
namespace UnrealScript
{
	class SoundCue;
}
#include "Core.Object.h"
#include "Engine.AudioDevice.ESoundClassName.h"
#include "Engine.FaceFXAnimSet.h"
#include "Engine.SoundCue.SoundNodeEditorData.h"
#include "Engine.SoundNode.h"
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
	class SoundCue : public Object
	{
	public:
		typedef SoundCue__SoundNodeEditorData SoundNodeEditorData;
		ADD_STRUCT(ScriptString*, FaceFXAnimName, 168)
		ADD_OBJECT(FaceFXAnimSet, FaceFXAnimSetRef, 152)
		ADD_STRUCT(ScriptString*, FaceFXGroupName, 156)
		ADD_STRUCT(ScriptName, SoundGroup, 188)
		ADD_STRUCT(int, CurrentPlayCount, 184)
		ADD_STRUCT(int, MaxConcurrentPlayCount, 180)
		ADD_STRUCT(float, Duration, 148)
		ADD_STRUCT(float, PitchMultiplier, 144)
		ADD_STRUCT(float, VolumeMultiplier, 140)
		ADD_STRUCT(float, MaxAudibleDistance, 136)
		ADD_OBJECT(SoundNode, FirstNode, 72)
		ADD_STRUCT(AudioDevice__ESoundClassName, SoundClassName, 68)
		ADD_STRUCT(ScriptName, SoundClass, 60)
		float GetCueDuration()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10380);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
