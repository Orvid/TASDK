#pragma once
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrDevice_SpikeLauncher." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrDevice_SpikeLauncher : public TrDevice
	{
	public:
		ADD_OBJECT(SoundCue, m_SpikeIdleSound)
	};
}
#undef ADD_OBJECT
