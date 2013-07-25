#pragma once
#include "Engine__ActorComponent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ExponentialHeightFogComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ExponentialHeightFogComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ExponentialHeightFogComponent : public ActorComponent
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'LightInscatteringColor'!
		ADD_VAR(::FloatProperty, LightInscatteringBrightness, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'OppositeLightColor'!
		ADD_VAR(::FloatProperty, OppositeLightBrightness, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LightTerminatorAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StartDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FogMaxOpacity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FogHeightFalloff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FogDensity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FogHeight, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEnabled, 0x1)
		// Here lies the not-yet-implemented method 'SetEnabled'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
