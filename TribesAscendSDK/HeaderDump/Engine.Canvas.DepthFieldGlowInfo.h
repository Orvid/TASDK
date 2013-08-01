#pragma once
#include "Core.Object.Vector2D.h"
#include "Core.Object.LinearColor.h"
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
	struct Canvas__DepthFieldGlowInfo
	{
	public:
		ADD_STRUCT(Object__Vector2D, GlowInnerRadius, 28)
		ADD_STRUCT(Object__Vector2D, GlowOuterRadius, 20)
		ADD_STRUCT(Object__LinearColor, GlowColor, 4)
		ADD_BOOL(bEnableGlow, 0, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
