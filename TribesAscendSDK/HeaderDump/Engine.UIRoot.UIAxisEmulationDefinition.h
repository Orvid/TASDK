#pragma once
namespace UnrealScript
{
	struct UIRoot__UIAxisEmulationDefinition;
}
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UIRoot__UIAxisEmulationDefinition
	{
	public:
		ADD_STRUCT(ScriptName, InputKeyToEmulate, 20)
		ADD_BOOL(bEmulateButtonPress, 16, 0x1)
		ADD_STRUCT(ScriptName, AdjacentAxisInputKey, 8)
		ADD_STRUCT(ScriptName, AxisInputKey, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
