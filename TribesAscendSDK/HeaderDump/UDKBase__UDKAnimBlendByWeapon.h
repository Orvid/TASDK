#pragma once
#include "Engine__AnimNodeBlendPerBone.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKAnimBlendByWeapon." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKAnimBlendByWeapon : public AnimNodeBlendPerBone
	{
	public:
		ADD_VAR(::FloatProperty, BlendTime, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, LoopingAnim, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bLooping, 0x1)
		// Here lies the not-yet-implemented method 'AnimFire'
		// Here lies the not-yet-implemented method 'AnimStopFire'
	};
}
#undef ADD_VAR
