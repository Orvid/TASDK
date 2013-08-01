#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GFxUDKFrontEnd_Multiplayer__Option
	{
	public:
		ADD_STRUCT(ScriptString*, OptionDesc, 24)
		ADD_STRUCT(ScriptString*, OptionLabel, 12)
		ADD_STRUCT(ScriptString*, OptionName, 0)
	};
}
#undef ADD_STRUCT
