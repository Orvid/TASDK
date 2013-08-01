#pragma once
#include "TribesGame.TrVGSCommandList.EVGSScope.h"
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
	struct TrVGSCommandList__TrVGSCommand
	{
	public:
		ADD_BOOL(bIsContext, 48, 0x1)
		ADD_STRUCT(ScriptString*, MenuString, 36)
		ADD_STRUCT(ScriptString*, ChatString, 24)
		ADD_STRUCT(ScriptString*, KeyBindPath, 12)
		ADD_STRUCT(ScriptName, KeyBind, 4)
		ADD_STRUCT(TrVGSCommandList__EVGSScope, VGSScope, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
