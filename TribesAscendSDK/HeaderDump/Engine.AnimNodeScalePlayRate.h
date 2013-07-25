#pragma once
#include "Engine.AnimNodeBlendBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNodeScalePlayRate." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AnimNodeScalePlayRate : public AnimNodeBlendBase
	{
	public:
		ADD_VAR(::FloatProperty, ScaleByValue, 0xFFFFFFFF)
	};
}
#undef ADD_VAR