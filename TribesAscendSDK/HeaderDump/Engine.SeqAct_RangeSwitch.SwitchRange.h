#pragma once
namespace UnrealScript
{
	struct SeqAct_RangeSwitch__SwitchRange;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct SeqAct_RangeSwitch__SwitchRange
	{
	public:
		ADD_STRUCT(int, Max, 4)
		ADD_STRUCT(int, Min, 0)
	};
}
#undef ADD_STRUCT
