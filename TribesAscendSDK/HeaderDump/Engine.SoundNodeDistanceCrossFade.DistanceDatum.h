#pragma once
namespace UnrealScript
{
	struct SoundNodeDistanceCrossFade__DistanceDatum;
}
#include "Core.DistributionFloat.RawDistributionFloat.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct SoundNodeDistanceCrossFade__DistanceDatum
	{
	public:
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, FadeOutDistance, 48)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, FadeInDistance, 20)
		ADD_STRUCT(float, Volume, 16)
		ADD_STRUCT(float, FadeOutDistanceEnd, 12)
		ADD_STRUCT(float, FadeOutDistanceStart, 8)
		ADD_STRUCT(float, FadeInDistanceEnd, 4)
		ADD_STRUCT(float, FadeInDistanceStart, 0)
	};
}
#undef ADD_STRUCT
