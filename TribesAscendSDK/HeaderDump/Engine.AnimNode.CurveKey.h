#pragma once
namespace UnrealScript
{
	struct AnimNode__CurveKey;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct AnimNode__CurveKey
	{
	public:
		ADD_STRUCT(float, Weight, 8)
		ADD_STRUCT(ScriptName, CurveName, 0)
	};
}
#undef ADD_STRUCT
