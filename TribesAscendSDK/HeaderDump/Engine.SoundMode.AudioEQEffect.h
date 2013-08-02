#pragma once
namespace UnrealScript
{
	struct SoundMode__AudioEQEffect;
}
#include "Core.Object.Double.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct SoundMode__AudioEQEffect
	{
	public:
		ADD_STRUCT(float, LFGain, 32)
		ADD_STRUCT(float, LFFrequency, 28)
		ADD_STRUCT(float, MFGain, 24)
		ADD_STRUCT(float, MFBandwidth, 20)
		ADD_STRUCT(float, MFCutoffFrequency, 16)
		ADD_STRUCT(float, HFGain, 12)
		ADD_STRUCT(float, HFFrequency, 8)
		ADD_STRUCT(Object__Double, RootTime, 0)
	};
}
#undef ADD_STRUCT
