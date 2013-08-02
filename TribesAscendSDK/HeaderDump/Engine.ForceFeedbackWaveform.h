#pragma once
namespace UnrealScript
{
	class ForceFeedbackWaveform;
}
#include "Core.Object.h"
#include "Engine.ForceFeedbackWaveform.EWaveformFunction.h"
#include "Engine.ForceFeedbackWaveform.WaveformSample.h"
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
	class ForceFeedbackWaveform : public Object
	{
	public:
		typedef ForceFeedbackWaveform__EWaveformFunction EWaveformFunction;
		typedef ForceFeedbackWaveform__WaveformSample WaveformSample;
		ADD_STRUCT(ScriptArray<ForceFeedbackWaveform__WaveformSample>, Samples, 64)
		ADD_STRUCT(float, MaxWaveformDistance, 80)
		ADD_STRUCT(float, WaveformFalloffStartDistance, 76)
		ADD_BOOL(bIsLooping, 60, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
