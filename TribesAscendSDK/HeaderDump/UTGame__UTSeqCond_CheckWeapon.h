#pragma once
#include "Engine__SequenceCondition.h"
#include "Engine__Actor.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTSeqCond_CheckWeapon." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTSeqCond_CheckWeapon : public SequenceCondition
	{
	public:
		ADD_OBJECT(ScriptClass, TestForWeaponClass)
		ADD_OBJECT(Actor, Target)
		// Here lies the not-yet-implemented method 'Activated'
	};
}
#undef ADD_OBJECT
