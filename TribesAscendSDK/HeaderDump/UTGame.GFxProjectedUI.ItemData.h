#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GFxProjectedUI__ItemData
	{
	public:
		ADD_STRUCT(byte, ItemFrame, 24)
		ADD_STRUCT(ScriptString*, ItemName, 12)
		ADD_STRUCT(ScriptString*, ItemInfo, 0)
	};
}
#undef ADD_STRUCT
