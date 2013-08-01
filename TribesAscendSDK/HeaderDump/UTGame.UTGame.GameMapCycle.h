#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UTGame__GameMapCycle
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptString*>, Maps, 8)
		ADD_STRUCT(ScriptName, GameClassName, 0)
	};
}
#undef ADD_STRUCT
