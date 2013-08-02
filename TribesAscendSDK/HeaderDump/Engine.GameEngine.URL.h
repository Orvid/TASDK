#pragma once
namespace UnrealScript
{
	struct GameEngine__URL;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GameEngine__URL
	{
	public:
		ADD_STRUCT(ScriptString*, Protocol, 0)
		ADD_STRUCT(ScriptString*, Host, 12)
		ADD_STRUCT(int, Port, 24)
		ADD_STRUCT(ScriptString*, Map, 28)
		ADD_STRUCT(ScriptArray<ScriptString*>, Op, 40)
		ADD_STRUCT(ScriptString*, Portal, 52)
		ADD_STRUCT(int, Valid, 64)
	};
}
#undef ADD_STRUCT
