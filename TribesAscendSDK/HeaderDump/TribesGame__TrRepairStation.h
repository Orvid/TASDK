#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrRepairStation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrRepairStation." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrRepairStation : public TrStation
	{
	public:
		ADD_OBJECT(SkelControlSingleBone, m_RepairGunControl)
		ADD_OBJECT(TrAnimNodeBlendList, m_RepairStationBlendList)
		ADD_VAR(::FloatProperty, m_fStationOpenDelay, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bIsStationOpen, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
