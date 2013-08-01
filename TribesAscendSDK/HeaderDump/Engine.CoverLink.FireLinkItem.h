#pragma once
#include "Engine.CoverLink.ECoverAction.h"
#include "Engine.CoverLink.ECoverType.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct CoverLink__FireLinkItem
	{
	public:
		ADD_STRUCT(CoverLink__ECoverAction, DestAction, 3)
		ADD_STRUCT(CoverLink__ECoverType, DestType, 2)
		ADD_STRUCT(CoverLink__ECoverAction, SrcAction, 1)
		ADD_STRUCT(CoverLink__ECoverType, SrcType, 0)
	};
}
#undef ADD_STRUCT
