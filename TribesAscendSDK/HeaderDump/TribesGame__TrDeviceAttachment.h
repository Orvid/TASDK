#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDeviceAttachment." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDeviceAttachment." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDeviceAttachment : public UTWeaponAttachment
	{
	public:
		ADD_VAR(::NameProperty, m_nmRidingAsPassengerFireAnimName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fShowTracerDistance, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_TracerType, 0xFFFFFFFF)
		ADD_OBJECT(ParticleSystem, m_TracerBeamTemplate)
		ADD_VAR(::BoolProperty, m_bScaleFireAnimRate, 0x4)
		ADD_VAR(::BoolProperty, m_bSpawnTracerBeams, 0x2)
		ADD_VAR(::BoolProperty, m_bSpawnTracers, 0x1)
		ADD_VAR(::NameProperty, m_nmHeavyAimProfileName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, m_nmLightMedAimProfileName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
