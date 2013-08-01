#pragma once
#include "Engine.SoundNodeAttenuation.SoundDistanceModel.h"
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Engine.SoundNode.h"
#include "Engine.SoundNodeAttenuation.ESoundDistanceCalc.h"
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
	class SoundNodeAttenuation : public SoundNode
	{
	public:
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, LPFMaxRadius, 188)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, LPFMinRadius, 160)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, MaxRadius, 132)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, MinRadius, 104)
		ADD_STRUCT(float, LPFRadiusMax, 100)
		ADD_STRUCT(float, LPFRadiusMin, 96)
		ADD_STRUCT(float, RadiusMax, 92)
		ADD_STRUCT(float, RadiusMin, 88)
		ADD_STRUCT(SoundNodeAttenuation__SoundDistanceModel, DistanceModel, 86)
		ADD_STRUCT(SoundNodeAttenuation__ESoundDistanceCalc, DistanceType, 85)
		ADD_STRUCT(SoundNodeAttenuation__SoundDistanceModel, DistanceAlgorithm, 84)
		ADD_STRUCT(float, dBAttenuationAtMax, 80)
		ADD_BOOL(bAttenuateWithLowPassFilter, 76, 0x8)
		ADD_BOOL(bAttenuateWithLPF, 76, 0x4)
		ADD_BOOL(bSpatialize, 76, 0x2)
		ADD_BOOL(bAttenuate, 76, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
