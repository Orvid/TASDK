#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.RB_ConstraintActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.RB_ConstraintActor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class RB_ConstraintActor : public RigidBodyBase
	{
	public:
		ADD_OBJECT(Actor, PulleyPivotActor2)
		ADD_OBJECT(Actor, PulleyPivotActor1)
		ADD_VAR(::BoolProperty, bUpdateActor2RefFrame, 0x4)
		ADD_VAR(::BoolProperty, bUpdateActor1RefFrame, 0x2)
		ADD_VAR(::BoolProperty, bDisableCollision, 0x1)
		ADD_OBJECT(RB_ConstraintInstance, ConstraintInstance)
		ADD_OBJECT(RB_ConstraintSetup, ConstraintSetup)
		ADD_OBJECT(Actor, ConstraintActor2)
		ADD_OBJECT(Actor, ConstraintActor1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
