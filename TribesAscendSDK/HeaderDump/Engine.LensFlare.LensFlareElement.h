#pragma once
#include "Engine.MaterialInterface.h"
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Core.Object.Vector.h"
#include "Core.DistributionVector.RawDistributionVector.h"
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
	struct LensFlare__LensFlareElement
	{
	public:
		ADD_STRUCT(ScriptArray<class MaterialInterface*>, LFMaterials, 28)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, DistMap_Alpha, 296)
		ADD_STRUCT(DistributionVector__RawDistributionVector, DistMap_Color, 268)
		ADD_STRUCT(DistributionVector__RawDistributionVector, DistMap_Scale, 240)
		ADD_STRUCT(DistributionVector__RawDistributionVector, Offset, 212)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, Alpha, 184)
		ADD_STRUCT(DistributionVector__RawDistributionVector, Color, 156)
		ADD_BOOL(bOrientTowardsSource, 152, 0x1)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, Rotation, 124)
		ADD_STRUCT(DistributionVector__RawDistributionVector, AxisScaling, 96)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, Scaling, 68)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, LFMaterialIndex, 40)
		ADD_STRUCT(Vector, Size, 16)
		ADD_BOOL(bModulateColorBySource, 12, 0x8)
		ADD_BOOL(bNormalizeRadialDistance, 12, 0x4)
		ADD_BOOL(bUseSourceDistance, 12, 0x2)
		ADD_BOOL(bIsEnabled, 12, 0x1)
		ADD_STRUCT(float, RayDistance, 8)
		ADD_STRUCT(ScriptName, ElementName, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
