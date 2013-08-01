#pragma once
#include "Engine.CameraShake.FOscillator.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct CameraShake__ROscillator
	{
	public:
		ADD_STRUCT(CameraShake__FOscillator, Pitch, 0)
		ADD_STRUCT(CameraShake__FOscillator, Yaw, 12)
		ADD_STRUCT(CameraShake__FOscillator, Roll, 24)
	};
}
#undef ADD_STRUCT
