#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKJumpPad." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKJumpPad." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKJumpPad." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKJumpPad : public NavigationPoint
	{
	public:
		ADD_VAR(::FloatProperty, JumpAirControl, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, JumpTime, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, JumpSound)
		ADD_OBJECT(PathNode, JumpTarget)
		ADD_STRUCT(::VectorProperty, JumpVelocity, 0xFFFFFFFF
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
