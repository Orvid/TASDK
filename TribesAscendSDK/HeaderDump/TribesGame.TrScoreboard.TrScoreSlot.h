#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct TrScoreboard__TrScoreSlot
	{
	public:
		ADD_STRUCT(int, RankIcon, 44)
		ADD_STRUCT(int, Rank, 40)
		ADD_STRUCT(int, Ping, 36)
		ADD_STRUCT(int, Score, 32)
		ADD_STRUCT(int, Assists, 28)
		ADD_STRUCT(int, Kills, 24)
		ADD_STRUCT(ScriptString*, ClassAbb, 12)
		ADD_STRUCT(ScriptString*, PlayerName, 0)
	};
}
#undef ADD_STRUCT
