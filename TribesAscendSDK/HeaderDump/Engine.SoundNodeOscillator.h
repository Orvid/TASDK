#pragma once
#include "Engine.SoundNode.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SoundNodeOscillator." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SoundNodeOscillator." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SoundNodeOscillator : public SoundNode
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'Center'!
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'Offset'!
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'Frequency'!
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'Amplitude'!
		ADD_VAR(::FloatProperty, CenterMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CenterMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OffsetMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OffsetMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FrequencyMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FrequencyMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AmplitudeMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AmplitudeMin, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bModulatePitch, 0x2)
		ADD_VAR(::BoolProperty, bModulateVolume, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
