#pragma once
namespace UnrealScript
{
	struct OnlineGameplayEvents__GameplayEvent;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct OnlineGameplayEvents__GameplayEvent
	{
	public:
		ADD_STRUCT(int, EventNameAndDesc, 4)
		ADD_STRUCT(int, PlayerEventAndTarget, 0)
	};
}
#undef ADD_STRUCT
