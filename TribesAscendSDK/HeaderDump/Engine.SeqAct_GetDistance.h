#pragma once
#include "Engine.SequenceAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_GetDistance." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_GetDistance : public SequenceAction
	{
	public:
		ADD_VAR(::FloatProperty, Distance, 0xFFFFFFFF)
	};
}
#undef ADD_VAR