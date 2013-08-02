#pragma once
namespace UnrealScript
{
	struct GameCrowdAgent__RecentInteraction;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GameCrowdAgent__RecentInteraction
	{
	public:
		ADD_STRUCT(float, InteractionDelay, 8)
		ADD_STRUCT(ScriptName, InteractionTag, 0)
	};
}
#undef ADD_STRUCT
