#pragma once
namespace UnrealScript
{
	struct GameStateObject__TeamState;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GameStateObject__TeamState
	{
	public:
		ADD_STRUCT(ScriptArray<int>, PlayerIndices, 4)
		ADD_STRUCT(int, TeamIndex, 0)
	};
}
#undef ADD_STRUCT
