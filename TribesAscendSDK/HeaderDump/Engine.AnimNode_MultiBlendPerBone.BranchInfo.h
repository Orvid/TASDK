#pragma once
namespace UnrealScript
{
	struct AnimNode_MultiBlendPerBone__BranchInfo;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct AnimNode_MultiBlendPerBone__BranchInfo
	{
	public:
		ADD_STRUCT(float, PerBoneWeightIncrease, 8)
		ADD_STRUCT(ScriptName, BoneName, 0)
	};
}
#undef ADD_STRUCT
