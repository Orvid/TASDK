#pragma once
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
	struct Input__KeyBind
	{
	public:
		ADD_BOOL(bIgnoreAlt, 20, 0x20)
		ADD_BOOL(bIgnoreShift, 20, 0x10)
		ADD_BOOL(bIgnoreCtrl, 20, 0x8)
		ADD_BOOL(Alt, 20, 0x4)
		ADD_BOOL(Shift, 20, 0x2)
		ADD_BOOL(Control, 20, 0x1)
		ADD_STRUCT(ScriptString*, Command, 8)
		ADD_STRUCT(ScriptName, Name, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
