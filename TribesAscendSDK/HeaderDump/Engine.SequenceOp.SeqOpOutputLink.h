#pragma once
namespace UnrealScript
{
	struct SequenceOp__SeqOpOutputLink;
}
#include "Engine.SequenceOp.h"
#include "Engine.SequenceOp.SeqOpOutputInputLink.h"
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
	struct SequenceOp__SeqOpOutputLink
	{
	public:
		ADD_STRUCT(ScriptArray<SequenceOp__SeqOpOutputInputLink>, Links, 0)
		ADD_STRUCT(int, OverrideDelta, 44)
		ADD_BOOL(bClampedMin, 40, 0x8)
		ADD_BOOL(bClampedMax, 40, 0x4)
		ADD_BOOL(bMoving, 40, 0x2)
		ADD_BOOL(bHidden, 40, 0x1)
		ADD_STRUCT(int, DrawY, 36)
		ADD_STRUCT(float, ActivateDelay, 32)
		ADD_OBJECT(SequenceOp, LinkedOp, 28)
		ADD_BOOL(bDisabledPIE, 24, 0x4)
		ADD_BOOL(bDisabled, 24, 0x2)
		ADD_BOOL(bHasImpulse, 24, 0x1)
		ADD_STRUCT(ScriptString*, LinkDesc, 12)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
