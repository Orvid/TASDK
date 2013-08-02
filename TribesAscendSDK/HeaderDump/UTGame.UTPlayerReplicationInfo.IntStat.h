#pragma once
namespace UnrealScript
{
	struct UTPlayerReplicationInfo__IntStat;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UTPlayerReplicationInfo__IntStat
	{
	public:
		ADD_STRUCT(int, StatValue, 8)
		ADD_STRUCT(ScriptName, StatName, 0)
	};
}
#undef ADD_STRUCT
