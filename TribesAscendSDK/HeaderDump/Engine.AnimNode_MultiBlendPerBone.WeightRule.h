#pragma once
#include "Engine.AnimNode_MultiBlendPerBone.WeightNodeRule.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct AnimNode_MultiBlendPerBone__WeightRule
	{
	public:
		ADD_STRUCT(AnimNode_MultiBlendPerBone__WeightNodeRule, SecondNode, 24)
		ADD_STRUCT(AnimNode_MultiBlendPerBone__WeightNodeRule, FirstNode, 0)
	};
}
#undef ADD_STRUCT
