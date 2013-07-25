#pragma once
#include "Engine__SequenceCondition.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTSeqCond_IsUsingWeapon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTSeqCond_IsUsingWeapon." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTSeqCond_IsUsingWeapon : public SequenceCondition
	{
	public:
		ADD_VAR(::BoolProperty, bMustBeImpactHammer, 0x2)
		ADD_VAR(::BoolProperty, bAllowSubclass, 0x1)
		ADD_OBJECT(Actor, Target)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
