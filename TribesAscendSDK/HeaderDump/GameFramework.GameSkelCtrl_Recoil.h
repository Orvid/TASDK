#pragma once
#include "Engine.SkelControlBase.h"
#include "Core.Object.Vector2D.h"
#include "GameFramework.GameSkelCtrl_Recoil.RecoilDef.h"
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
	class GameSkelCtrl_Recoil : public SkelControlBase
	{
	public:
		ADD_STRUCT(Object__Vector2D, Aim, 304)
		ADD_STRUCT(GameSkelCtrl_Recoil__RecoilDef, Recoil, 192)
		ADD_BOOL(bApplyControl, 188, 0x8)
		ADD_BOOL(bOldPlayRecoil, 188, 0x4)
		ADD_BOOL(bPlayRecoil, 188, 0x2)
		ADD_BOOL(bBoneSpaceRecoil, 188, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
