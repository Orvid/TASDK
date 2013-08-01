#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct TrScoreboard__TrScoreboardState
	{
	public:
		ADD_STRUCT(int, DiamondSwordScore, 8)
		ADD_STRUCT(int, BloodEagleScore, 4)
		ADD_STRUCT(int, RemainingTime, 0)
	};
}
#undef ADD_STRUCT
