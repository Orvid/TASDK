#pragma once
namespace UnrealScript
{
	struct Material__ColorMaterialInput;
}
#include "Core.Object.Color.h"
#include "Engine.Material.MaterialInput.h"
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
	struct Material__ColorMaterialInput : public Material__MaterialInput
	{
	public:
		ADD_STRUCT(Object__Color, Constant, 32)
		ADD_BOOL(UseConstant, 28, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
