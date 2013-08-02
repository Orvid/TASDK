#pragma once
namespace UnrealScript
{
	struct TrStreamManager__GameStream;
}
#include "TribesGame.TrStreamManager.STREAMTYPE.h"
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
	struct TrStreamManager__GameStream
	{
	public:
		ADD_STRUCT(TrStreamManager__STREAMTYPE, Type, 4)
		ADD_BOOL(bFeatured, 0, 0x2)
		ADD_STRUCT(ScriptString*, Title, 8)
		ADD_BOOL(bLive, 0, 0x1)
		ADD_STRUCT(ScriptString*, Viewers, 32)
		ADD_STRUCT(ScriptString*, Description, 56)
		ADD_STRUCT(ScriptString*, ChannelName, 44)
		ADD_STRUCT(ScriptString*, Stream, 20)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
