#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct InterpTrackMove__InterpLookupPoint
	{
	public:
		ADD_STRUCT(float, Time, 8)
		ADD_STRUCT(ScriptName, GroupName, 0)
	};
}
#undef ADD_STRUCT
