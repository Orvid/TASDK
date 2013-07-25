#pragma once
#include "Engine.MorphNodeBase.h"
#include "Engine.MorphTarget.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.MorphNodePose." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.MorphNodePose." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MorphNodePose : public MorphNodeBase
	{
	public:
		ADD_VAR(::FloatProperty, Weight, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, MorphName, 0xFFFFFFFF)
		ADD_OBJECT(MorphTarget, Target)
		void SetMorphTarget(ScriptName MorphTargetName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MorphNodePose.SetMorphTarget");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = MorphTargetName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT