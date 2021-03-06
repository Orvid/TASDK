#pragma once
namespace UnrealScript
{
	struct TrRabbitLeaderboard__LeaderboardSlot;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct TrRabbitLeaderboard__LeaderboardSlot
	{
	public:
		ADD_STRUCT(int, Score, 8)
		ADD_STRUCT(ScriptName, PRIName, 0)
	};
}
#undef ADD_STRUCT
