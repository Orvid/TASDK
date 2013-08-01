#pragma once
#include "Core.Object.Vector2D.h"
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
	struct AnimNodeRandom__RandomAnimInfo
	{
	public:
		ADD_STRUCT(float, LastPosition, 28)
		ADD_STRUCT(byte, LoopCount, 24)
		ADD_BOOL(bStillFrame, 20, 0x1)
		ADD_STRUCT(Object__Vector2D, PlayRateRange, 12)
		ADD_STRUCT(float, BlendInTime, 8)
		ADD_STRUCT(byte, LoopCountMax, 5)
		ADD_STRUCT(byte, LoopCountMin, 4)
		ADD_STRUCT(float, Chance, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
