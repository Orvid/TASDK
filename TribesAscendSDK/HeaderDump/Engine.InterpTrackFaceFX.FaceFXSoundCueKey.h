#pragma once
namespace UnrealScript
{
	struct InterpTrackFaceFX__FaceFXSoundCueKey;
}
#include "Engine.SoundCue.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct InterpTrackFaceFX__FaceFXSoundCueKey
	{
	public:
		ADD_OBJECT(SoundCue, FaceFXSoundCue, 0)
	};
}
#undef ADD_OBJECT
