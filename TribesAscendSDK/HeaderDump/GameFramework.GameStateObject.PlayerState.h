#pragma once
namespace UnrealScript
{
	struct GameStateObject__PlayerState;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GameStateObject__PlayerState
	{
	public:
		ADD_STRUCT(float, TimeAliveSinceLastDeath, 12)
		ADD_STRUCT(float, TimeSpawned, 8)
		ADD_STRUCT(int, CurrentTeamIndex, 4)
		ADD_STRUCT(int, PlayerIndex, 0)
	};
}
#undef ADD_STRUCT
