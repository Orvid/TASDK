#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Console__AutoCompleteCommand
	{
	public:
		ADD_STRUCT(ScriptString*, Desc, 12)
		ADD_STRUCT(ScriptString*, Command, 0)
	};
}
#undef ADD_STRUCT
