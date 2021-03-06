#pragma once
namespace UnrealScript
{
	struct SequenceOp__SeqOpInputLink;
}
#include "Engine.SequenceOp.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct SequenceOp__SeqOpInputLink
	{
	public:
		ADD_BOOL(bHasImpulse, 12, 0x1)
		ADD_STRUCT(int, OverrideDelta, 44)
		ADD_BOOL(bClampedMin, 40, 0x4)
		ADD_BOOL(bClampedMax, 40, 0x2)
		ADD_BOOL(bMoving, 40, 0x1)
		ADD_STRUCT(float, ActivateDelay, 36)
		ADD_BOOL(bHidden, 32, 0x1)
		ADD_STRUCT(int, DrawY, 28)
		ADD_OBJECT(SequenceOp, LinkedOp, 24)
		ADD_BOOL(bDisabledPIE, 20, 0x2)
		ADD_BOOL(bDisabled, 20, 0x1)
		ADD_STRUCT(int, QueuedActivations, 16)
		ADD_STRUCT(ScriptString*, LinkDesc, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
