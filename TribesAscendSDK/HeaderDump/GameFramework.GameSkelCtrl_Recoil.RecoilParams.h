#pragma once
namespace UnrealScript
{
	struct GameSkelCtrl_Recoil__RecoilParams;
}
#include "GameFramework.GameSkelCtrl_Recoil.ERecoilStart.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GameSkelCtrl_Recoil__RecoilParams
	{
	public:
		ADD_STRUCT(byte, Padding, 3)
		ADD_STRUCT(GameSkelCtrl_Recoil__ERecoilStart, Z, 2)
		ADD_STRUCT(GameSkelCtrl_Recoil__ERecoilStart, Y, 1)
		ADD_STRUCT(GameSkelCtrl_Recoil__ERecoilStart, X, 0)
	};
}
#undef ADD_STRUCT
