#pragma once
namespace UnrealScript
{
	struct CameraShake__FOscillator;
}
#include "Engine.CameraShake.EInitialOscillatorOffset.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct CameraShake__FOscillator
	{
	public:
		ADD_STRUCT(float, Amplitude, 0)
		ADD_STRUCT(float, Frequency, 4)
		ADD_STRUCT(CameraShake__EInitialOscillatorOffset, InitialOffset, 8)
	};
}
#undef ADD_STRUCT
