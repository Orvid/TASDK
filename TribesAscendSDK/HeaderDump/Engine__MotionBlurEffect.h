#pragma once
#include "Engine__PostProcessEffect.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.MotionBlurEffect." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MotionBlurEffect : public PostProcessEffect
	{
	public:
		ADD_VAR(::FloatProperty, CameraTranslationThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CameraRotationThreshold, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, FullMotionBlur, 0x1)
		ADD_VAR(::FloatProperty, MotionBlurAmount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxVelocity, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
