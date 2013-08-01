#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct TrGame_TrStorm__Carrier
	{
	public:
		ADD_STRUCT(byte, TeamNum, 8)
		ADD_STRUCT(int, CoreHealth, 4)
		ADD_STRUCT(int, ShieldHealth, 0)
	};
}
#undef ADD_STRUCT
