#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.LiftCenter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.LiftCenter." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.LiftCenter." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class LiftCenter : public NavigationPoint
	{
	public:
		ADD_OBJECT(Trigger, LiftTrigger)
		ADD_VAR(::FloatProperty, CollisionHeight, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bJumpLift, 0x1)
		ADD_STRUCT(::VectorProperty, LiftOffset, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, MaxDist2D, 0xFFFFFFFF)
		ADD_OBJECT(InterpActor, MyLift)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
