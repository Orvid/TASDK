#pragma once
namespace UnrealScript
{
	struct TrSummaryHelper__MVPAward;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct TrSummaryHelper__MVPAward
	{
	public:
		ADD_STRUCT(int, Value, 0)
		ADD_STRUCT(int, AwardId, 8)
		ADD_STRUCT(int, PlayerID, 4)
	};
}
#undef ADD_STRUCT
