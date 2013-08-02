#pragma once
namespace UnrealScript
{
	class AnimNotify_Sound;
}
#include "Engine.AnimNotify.h"
#include "Engine.SoundCue.h"
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
	class AnimNotify_Sound : public AnimNotify
	{
	public:
		ADD_STRUCT(float, PitchMultiplier, 88)
		ADD_STRUCT(float, VolumeMultiplier, 84)
		ADD_STRUCT(float, PercentToPlay, 80)
		ADD_STRUCT(ScriptName, BoneName, 72)
		ADD_BOOL(bIgnoreIfActorHidden, 68, 0x2)
		ADD_BOOL(bFollowActor, 68, 0x1)
		ADD_OBJECT(SoundCue, SoundCue, 64)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
