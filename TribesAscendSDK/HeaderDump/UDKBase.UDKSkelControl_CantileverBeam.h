#pragma once
#include "Engine.SkelControlLookAt.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKSkelControl_CantileverBeam." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKSkelControl_CantileverBeam." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKSkelControl_CantileverBeam : public SkelControlLookAt
	{
	public:
		ADD_VAR(::FloatProperty, PercentBeamVelocityTransfer, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SpringDamping, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SpringStiffness, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Velocity, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, InitialWorldSpaceGoalOffset, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, WorldSpaceGoal, 0xFFFFFFFF)
		Vector EntireBeamVelocity()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKSkelControl_CantileverBeam.EntireBeamVelocity");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT