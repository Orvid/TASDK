#pragma once
#include "TribesGame.TrObject.TrCreditEventType.h"
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
	struct TrObject__TrEventCredits
	{
	public:
		ADD_STRUCT(TrObject__TrCreditEventType, EventType, 0)
		ADD_STRUCT(int, eventCredits, 4)
		ADD_STRUCT(int, proxyEventCredits, 8)
		ADD_STRUCT(int, MsgIdx, 12)
		ADD_BOOL(bIsBroadcast, 16, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
