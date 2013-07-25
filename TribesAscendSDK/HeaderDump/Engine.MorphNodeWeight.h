#pragma once
#include "Engine.MorphNodeWeightBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.MorphNodeWeight." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MorphNodeWeight : public MorphNodeWeightBase
	{
	public:
		ADD_VAR(::FloatProperty, NodeWeight, 0xFFFFFFFF)
		void SetNodeWeight(float NewWeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.MorphNodeWeight.SetNodeWeight");
			byte* params = (byte*)malloc(4);
			*(float*)params = NewWeight;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR