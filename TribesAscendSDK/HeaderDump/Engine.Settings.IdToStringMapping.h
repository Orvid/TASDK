#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Settings__IdToStringMapping
	{
	public:
		ADD_STRUCT(int, Id, 0)
		ADD_STRUCT(ScriptName, Name, 4)
	};
}
#undef ADD_STRUCT
