#pragma once
namespace UnrealScript
{
	struct TgGameEngine__MAR_EVENT;
}
#include "Core.Object.Pointer.h"
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
	struct TgGameEngine__MAR_EVENT
	{
	public:
		ADD_STRUCT(Object__Pointer, pMarshal, 40)
		ADD_STRUCT(ScriptString*, fsMessage, 28)
		ADD_STRUCT(int, nStmMsgId, 24)
		ADD_STRUCT(QWord, qwInfo, 16)
		ADD_STRUCT(QWord, qwId, 8)
		ADD_STRUCT(int, nFunction, 4)
		ADD_BOOL(bSuccess, 0, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
