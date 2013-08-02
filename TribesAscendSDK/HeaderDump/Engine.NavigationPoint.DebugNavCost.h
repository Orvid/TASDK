#pragma once
namespace UnrealScript
{
	struct NavigationPoint__DebugNavCost;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct NavigationPoint__DebugNavCost
	{
	public:
		ADD_STRUCT(int, Cost, 12)
		ADD_STRUCT(ScriptString*, Desc, 0)
	};
}
#undef ADD_STRUCT
