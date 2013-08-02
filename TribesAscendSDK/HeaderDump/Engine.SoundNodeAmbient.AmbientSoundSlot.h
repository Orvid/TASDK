#pragma once
namespace UnrealScript
{
	struct SoundNodeAmbient__AmbientSoundSlot;
}
#include "Engine.SoundNodeWave.h"
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
	struct SoundNodeAmbient__AmbientSoundSlot
	{
	public:
		ADD_STRUCT(float, Weight, 12)
		ADD_STRUCT(float, VolumeScale, 8)
		ADD_STRUCT(float, PitchScale, 4)
		ADD_OBJECT(SoundNodeWave, Wave, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
