#pragma once
#include "Engine.PrimitiveComponent.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.RB_RadialImpulseComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class RB_RadialImpulseComponent : public PrimitiveComponent
	{
	public:
		ADD_VAR(::BoolProperty, bCauseFracture, 0x2)
		ADD_VAR(::BoolProperty, bVelChange, 0x1)
		ADD_VAR(::FloatProperty, ImpulseRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ImpulseStrength, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ImpulseFalloff, 0xFFFFFFFF)
		void FireImpulse(Vector Origin)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.RB_RadialImpulseComponent.FireImpulse");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = Origin;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR