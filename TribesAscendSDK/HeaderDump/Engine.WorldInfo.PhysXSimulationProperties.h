#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " WorldInfo.PhysXSimulationProperties." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PhysXSimulationProperties
	{
	public:
		ADD_VAR(::BoolProperty, bUseHardware, 0x1)
		ADD_VAR(::BoolProperty, bFixedTimeStep, 0x2)
		ADD_VAR(::FloatProperty, TimeStep, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxSubSteps, 0xFFFFFFFF)
	};
}
#undef ADD_VAR