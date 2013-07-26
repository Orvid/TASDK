#pragma once
#include "Engine.SoundCue.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKVehicle.VehicleSound." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKVehicle.VehicleSound." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class VehicleSound
	{
	public:
		ADD_OBJECT(SoundCue, SoundTemplate)
		ADD_VAR(::NameProperty, SoundEndTag, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, SoundStartTag, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT