#pragma once
#include "Engine.CoverLink.ECoverType.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct CoverReplicator__ManualCoverTypeInfo
	{
	public:
		ADD_STRUCT(CoverLink__ECoverType, ManualCoverType, 1)
		ADD_STRUCT(byte, SlotIndex, 0)
	};
}
#undef ADD_STRUCT
