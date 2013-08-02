#pragma once
namespace UnrealScript
{
	struct AnimNode_MultiBlendPerBone__WeightNodeRule;
}
#include "Engine.AnimNodeBlendBase.h"
#include "Engine.AnimNodeSlot.h"
#include "Engine.AnimNode_MultiBlendPerBone.EWeightCheck.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct AnimNode_MultiBlendPerBone__WeightNodeRule
	{
	public:
		ADD_STRUCT(int, ChildIndex, 20)
		ADD_STRUCT(AnimNode_MultiBlendPerBone__EWeightCheck, WeightCheck, 16)
		ADD_OBJECT(AnimNodeSlot, CachedSlotNode, 12)
		ADD_OBJECT(AnimNodeBlendBase, CachedNode, 8)
		ADD_STRUCT(ScriptName, NodeName, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
