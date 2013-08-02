#pragma once
namespace UnrealScript
{
	class SeqAct_Switch;
}
#include "Engine.SequenceAction.h"
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
	class SeqAct_Switch : public SequenceAction
	{
	public:
		ADD_STRUCT(ScriptArray<int>, Indices, 244)
		ADD_BOOL(bAutoDisableLinks, 240, 0x2)
		ADD_BOOL(bLooping, 240, 0x1)
		ADD_STRUCT(int, IncrementAmount, 236)
		ADD_STRUCT(int, LinkCount, 232)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
