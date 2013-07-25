#pragma once
#include "Engine__SequenceEvent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqEvent_TakeDamage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_TakeDamage : public SequenceEvent
	{
	public:
		ADD_VAR(::BoolProperty, bResetDamageOnToggle, 0x1)
		ADD_VAR(::FloatProperty, CurrentDamage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DamageThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinDamageAmount, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
