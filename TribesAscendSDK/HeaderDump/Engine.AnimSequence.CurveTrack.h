#pragma once
namespace UnrealScript
{
	struct AnimSequence__CurveTrack;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct AnimSequence__CurveTrack
	{
	public:
		ADD_STRUCT(ScriptName, CurveName, 0)
		ADD_STRUCT(ScriptArray<float>, CurveWeights, 8)
	};
}
#undef ADD_STRUCT
