#pragma once
#include "Engine.SkelControlSingleBone.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKSkelControl_VehicleFlap." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKSkelControl_VehicleFlap : public SkelControlSingleBone
	{
	public:
		ADD_VAR(::NameProperty, LeftFlapControl, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, RightFlapControl, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxPitchChange, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxPitchTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OldZPitch, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, maxPitch, 0xFFFFFFFF)
	};
}
#undef ADD_VAR