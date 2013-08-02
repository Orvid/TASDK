#pragma once
namespace UnrealScript
{
	struct UIRoot__RawInputKeyEventData;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UIRoot__RawInputKeyEventData
	{
	public:
		ADD_STRUCT(byte, ModifierKeyFlags, 8)
		ADD_STRUCT(ScriptName, InputKeyName, 0)
	};
}
#undef ADD_STRUCT
