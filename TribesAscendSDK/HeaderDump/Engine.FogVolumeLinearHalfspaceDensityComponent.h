#pragma once
#include "Engine.FogVolumeDensityComponent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.FogVolumeLinearHalfspaceDensityComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.FogVolumeLinearHalfspaceDensityComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class FogVolumeLinearHalfspaceDensityComponent : public FogVolumeDensityComponent
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Plane' for the property named 'HalfspacePlane'!
		ADD_VAR(::FloatProperty, PlaneDistanceFactor, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT