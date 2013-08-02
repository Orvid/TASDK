#pragma once
namespace UnrealScript
{
	struct GameStatsAggregator__AggregateEventMapping;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GameStatsAggregator__AggregateEventMapping
	{
	public:
		ADD_STRUCT(int, TargetAggregateID, 8)
		ADD_STRUCT(int, AggregateID, 4)
		ADD_STRUCT(int, EventID, 0)
	};
}
#undef ADD_STRUCT
