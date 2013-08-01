#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct MorphNodeWeightByBoneAngle__BoneAngleMorph
	{
	public:
		ADD_STRUCT(float, TargetWeight, 4)
		ADD_STRUCT(float, Angle, 0)
	};
}
#undef ADD_STRUCT
