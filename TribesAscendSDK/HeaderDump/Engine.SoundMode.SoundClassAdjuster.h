#pragma once
#include "Engine.AudioDevice.ESoundClassName.h"
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
	struct SoundMode__SoundClassAdjuster
	{
	public:
		ADD_STRUCT(float, VoiceCenterChannelVolumeAdjuster, 24)
		ADD_BOOL(bApplyToChildren, 20, 0x1)
		ADD_STRUCT(float, PitchAdjuster, 16)
		ADD_STRUCT(float, VolumeAdjuster, 12)
		ADD_STRUCT(ScriptName, SoundClass, 4)
		ADD_STRUCT(AudioDevice__ESoundClassName, SoundClassName, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
