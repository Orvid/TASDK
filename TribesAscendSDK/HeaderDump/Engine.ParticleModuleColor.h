#pragma once
namespace UnrealScript
{
	class ParticleModuleColor;
}
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#include "Engine.ParticleModuleColorBase.h"
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
	class ParticleModuleColor : public ParticleModuleColorBase
	{
	public:
		ADD_BOOL(bClampAlpha, 128, 0x1)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, StartAlpha, 100)
		ADD_STRUCT(DistributionVector__RawDistributionVector, StartColor, 72)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
