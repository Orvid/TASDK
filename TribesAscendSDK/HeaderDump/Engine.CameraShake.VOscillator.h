#pragma once
#include "Engine.CameraShake.FOscillator.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct CameraShake__VOscillator
	{
	public:
		ADD_STRUCT(CameraShake__FOscillator, X, 0)
		ADD_STRUCT(CameraShake__FOscillator, Y, 12)
		ADD_STRUCT(CameraShake__FOscillator, Z, 24)
	};
}
#undef ADD_STRUCT
