#pragma once
namespace UnrealScript
{
	struct RB_ConstraintSetup__LinearDOFSetup;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct RB_ConstraintSetup__LinearDOFSetup
	{
	public:
		ADD_STRUCT(float, LimitSize, 4)
		ADD_STRUCT(byte, bLimited, 0)
	};
}
#undef ADD_STRUCT
