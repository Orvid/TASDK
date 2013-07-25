#pragma once
#include "UDKBase.UDKSkelControl_Damage.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKSkelControl_DamageHinge." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKSkelControl_DamageHinge : public UDKSkelControl_Damage
	{
	public:
		ADD_VAR(::FloatProperty, SpringStiffness, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AVModifier, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, PivotAxis, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxAngle, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
