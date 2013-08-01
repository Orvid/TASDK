#pragma once
#include "Engine.SoundCue.h"
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
	struct UDKVehicle__VehicleSound
	{
	public:
		ADD_OBJECT(SoundCue, SoundTemplate, 16)
		ADD_STRUCT(ScriptName, SoundEndTag, 8)
		ADD_STRUCT(ScriptName, SoundStartTag, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
