#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UTPlayerReplicationInfo__TimeStat
	{
	public:
		ADD_STRUCT(float, CurrentStart, 12)
		ADD_STRUCT(float, TotalTime, 8)
		ADD_STRUCT(ScriptName, StatName, 0)
	};
}
#undef ADD_STRUCT
