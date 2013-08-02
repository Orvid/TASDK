#pragma once
namespace UnrealScript
{
	struct TrObject__ObjectiveMICInfo;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct TrObject__ObjectiveMICInfo
	{
	public:
		ADD_STRUCT(int, MyTeam, 0)
		ADD_STRUCT(float, AmountFilled, 4)
		ADD_STRUCT(int, ObjStatus, 8)
		ADD_STRUCT(int, IsContested, 12)
		ADD_STRUCT(int, Flip, 16)
	};
}
#undef ADD_STRUCT
