#pragma once
namespace UnrealScript
{
	struct AnimNodeBlendMultiBone__ChildBoneBlendInfo;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct AnimNodeBlendMultiBone__ChildBoneBlendInfo
	{
	public:
		ADD_STRUCT(ScriptArray<float>, TargetPerBoneWeight, 0)
		ADD_STRUCT(ScriptArray<byte>, TargetRequiredBones, 36)
		ADD_STRUCT(float, OldBoneIncrease, 32)
		ADD_STRUCT(ScriptName, OldStartBone, 24)
		ADD_STRUCT(float, InitPerBoneIncrease, 20)
		ADD_STRUCT(ScriptName, InitTargetStartBone, 12)
	};
}
#undef ADD_STRUCT
