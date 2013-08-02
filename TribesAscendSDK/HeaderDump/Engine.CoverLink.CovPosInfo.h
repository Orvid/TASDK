#pragma once
namespace UnrealScript
{
	struct CoverLink__CovPosInfo;
}
#include "Engine.CoverLink.h"
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
	struct CoverLink__CovPosInfo
	{
	public:
		ADD_OBJECT(CoverLink, Link, 0)
		ADD_STRUCT(int, LtSlotIdx, 4)
		ADD_STRUCT(int, RtSlotIdx, 8)
		ADD_STRUCT(float, LtToRtPct, 12)
		ADD_STRUCT(Vector, Location, 16)
		ADD_STRUCT(Vector, Normal, 28)
		ADD_STRUCT(Vector, Tangent, 40)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
