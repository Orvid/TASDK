#pragma once
namespace UnrealScript
{
	struct ForceFeedbackWaveform__WaveformSample;
}
#include "Engine.ForceFeedbackWaveform.EWaveformFunction.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct ForceFeedbackWaveform__WaveformSample
	{
	public:
		ADD_STRUCT(float, Duration, 4)
		ADD_STRUCT(ForceFeedbackWaveform__EWaveformFunction, RightFunction, 3)
		ADD_STRUCT(ForceFeedbackWaveform__EWaveformFunction, LeftFunction, 2)
		ADD_STRUCT(byte, RightAmplitude, 1)
		ADD_STRUCT(byte, LeftAmplitude, 0)
	};
}
#undef ADD_STRUCT
