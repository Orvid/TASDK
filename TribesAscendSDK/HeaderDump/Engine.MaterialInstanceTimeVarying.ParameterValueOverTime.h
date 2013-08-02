#pragma once
namespace UnrealScript
{
	struct MaterialInstanceTimeVarying__ParameterValueOverTime;
}
#include "Core.Object.Guid.h"
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
	struct MaterialInstanceTimeVarying__ParameterValueOverTime
	{
	public:
		ADD_BOOL(bOffsetFromEnd, 44, 0x1)
		ADD_STRUCT(float, OffsetTime, 40)
		ADD_BOOL(bNormalizeTime, 36, 0x1)
		ADD_STRUCT(float, CycleTime, 32)
		ADD_BOOL(bAutoActivate, 28, 0x2)
		ADD_BOOL(bLoop, 28, 0x1)
		ADD_STRUCT(ScriptName, ParameterName, 20)
		ADD_STRUCT(float, StartTime, 16)
		ADD_STRUCT(Object__Guid, ExpressionGUID, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
