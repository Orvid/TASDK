#pragma once
namespace UnrealScript
{
	struct PBRuleNodeCorner__RBCornerAngleInfo;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct PBRuleNodeCorner__RBCornerAngleInfo
	{
	public:
		ADD_STRUCT(float, CornerSize, 4)
		ADD_STRUCT(float, Angle, 0)
	};
}
#undef ADD_STRUCT
