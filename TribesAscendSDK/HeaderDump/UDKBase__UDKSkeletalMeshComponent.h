#pragma once
#include "Engine__SkeletalMeshComponent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKSkeletalMeshComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKSkeletalMeshComponent : public SkeletalMeshComponent
	{
	public:
		ADD_VAR(::FloatProperty, ClearStreamingTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bForceLoadTextures, 0x1)
		ADD_VAR(::FloatProperty, FOV, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'PreloadTextures'
		// Here lies the not-yet-implemented method 'SetFOV'
	};
}
#undef ADD_VAR
