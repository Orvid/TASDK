#pragma once
namespace UnrealScript
{
	class DistributionVectorConstantCurve;
}
#include "Core.DistributionVector.h"
#include "Core.DistributionVector.EDistributionVectorLockFlags.h"
#include "Core.Object.InterpCurveVector.h"
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
	class DistributionVectorConstantCurve : public DistributionVector
	{
	public:
		ADD_STRUCT(DistributionVector__EDistributionVectorLockFlags, LockedAxes, 100)
		ADD_BOOL(bLockAxes, 96, 0x1)
		ADD_STRUCT(Object__InterpCurveVector, ConstantCurve, 80)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
