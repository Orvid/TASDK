#pragma once
#include "Engine.K2NodeBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AIGatherNodeBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AIGatherNodeBase : public K2NodeBase
	{
	public:
		ADD_VAR(::StrProperty, NodeName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastUpdateTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR