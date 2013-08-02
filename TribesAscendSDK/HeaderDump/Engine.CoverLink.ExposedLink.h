#pragma once
namespace UnrealScript
{
	struct CoverLink__ExposedLink;
}
#include "Engine.CoverLink.CoverReference.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct CoverLink__ExposedLink
	{
	public:
		ADD_STRUCT(byte, ExposedScale, 24)
		ADD_STRUCT(CoverLink__CoverReference, TargetActor, 0)
	};
}
#undef ADD_STRUCT
