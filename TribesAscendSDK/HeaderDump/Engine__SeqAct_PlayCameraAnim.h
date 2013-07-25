#pragma once
#include "Engine__SequenceAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_PlayCameraAnim." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SeqAct_PlayCameraAnim." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_PlayCameraAnim : public SequenceAction
	{
	public:
		ADD_OBJECT(Actor, UserDefinedSpaceActor)
		ADD_VAR(::ByteProperty, PlaySpace, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, IntensityScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Rate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BlendOutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BlendInTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bRandomStartTime, 0x2)
		ADD_VAR(::BoolProperty, bLoop, 0x1)
		ADD_OBJECT(CameraAnim, CameraAnim)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
