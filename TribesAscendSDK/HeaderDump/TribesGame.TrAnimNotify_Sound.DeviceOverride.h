#pragma once
namespace UnrealScript
{
	struct TrAnimNotify_Sound__DeviceOverride;
}
#include "Engine.SoundCue.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct TrAnimNotify_Sound__DeviceOverride
	{
	public:
		ADD_OBJECT(ScriptClass, DeviceClass, 4)
		ADD_OBJECT(SoundCue, SoundCue, 0)
	};
}
#undef ADD_OBJECT
