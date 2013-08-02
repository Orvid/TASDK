#pragma once
namespace UnrealScript
{
	struct GFxTrScene_MatchSummary__ScoreSlot;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GFxTrScene_MatchSummary__ScoreSlot
	{
	public:
		ADD_STRUCT(ScriptString*, PlayerName, 20)
		ADD_STRUCT(int, PlayerID, 16)
		ADD_STRUCT(int, Credits, 12)
		ADD_STRUCT(int, Assists, 8)
		ADD_STRUCT(int, Rank, 4)
		ADD_STRUCT(int, Kills, 0)
	};
}
#undef ADD_STRUCT
