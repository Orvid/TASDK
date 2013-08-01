#pragma once
#include "Core.Object.Vector.h"
#include "GameFramework.GameSkelCtrl_Recoil.RecoilParams.h"
#include "Core.Object.Rotator.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GameSkelCtrl_Recoil__RecoilDef
	{
	public:
		ADD_STRUCT(Vector, LocOffset, 100)
		ADD_STRUCT(GameSkelCtrl_Recoil__RecoilParams, LocParams, 96)
		ADD_STRUCT(Vector, LocSinOffset, 84)
		ADD_STRUCT(Vector, LocFrequency, 72)
		ADD_STRUCT(Vector, LocAmplitude, 60)
		ADD_STRUCT(Rotator, RotOffset, 48)
		ADD_STRUCT(GameSkelCtrl_Recoil__RecoilParams, RotParams, 44)
		ADD_STRUCT(Vector, RotSinOffset, 32)
		ADD_STRUCT(Vector, RotFrequency, 20)
		ADD_STRUCT(Vector, RotAmplitude, 8)
		ADD_STRUCT(float, TimeDuration, 4)
		ADD_STRUCT(float, TimeToGo, 0)
	};
}
#undef ADD_STRUCT
