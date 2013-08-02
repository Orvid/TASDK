#pragma once
namespace UnrealScript
{
	struct Camera__TCameraCache;
}
#include "Core.Object.TPOV.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Camera__TCameraCache
	{
	public:
		ADD_STRUCT(Object__TPOV, POV, 4)
		ADD_STRUCT(float, TimeStamp, 0)
	};
}
#undef ADD_STRUCT
