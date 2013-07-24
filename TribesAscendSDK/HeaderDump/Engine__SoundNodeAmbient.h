#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SoundNodeAmbient." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SoundNodeAmbient." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SoundNodeAmbient." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SoundNodeAmbient : public SoundNode
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'VolumeModulation'!
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'PitchModulation'!
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'LPFMaxRadius'!
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'LPFMinRadius'!
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'MaxRadius'!
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'MinRadius'!
		ADD_OBJECT(SoundNodeWave, Wave)
		ADD_VAR(::FloatProperty, VolumeMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, VolumeMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PitchMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PitchMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LPFRadiusMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LPFRadiusMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RadiusMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RadiusMin, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, DistanceModel, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, dBAttenuationAtMax, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAttenuateWithLowPassFilter, 0x8)
		ADD_VAR(::BoolProperty, bAttenuateWithLPF, 0x4)
		ADD_VAR(::BoolProperty, bSpatialize, 0x2)
		ADD_VAR(::BoolProperty, bAttenuate, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
