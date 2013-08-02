#pragma once
namespace UnrealScript
{
	struct TrObject__TR_HUD_INFO;
}
#include "TribesGame.TrObject.OverlayType.h"
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
	struct TrObject__TR_HUD_INFO
	{
	public:
		ADD_STRUCT(Vector, vScreenLoc, 0)
		ADD_STRUCT(float, fScale, 12)
		ADD_STRUCT(float, fAlphaLevel, 16)
		ADD_STRUCT(float, fLastSeenTime, 20)
		ADD_STRUCT(float, fLastUnseenTime, 24)
		ADD_BOOL(bIsTarget, 28, 0x1)
		ADD_STRUCT(ScriptString*, sName, 32)
		ADD_STRUCT(int, nHealth, 44)
		ADD_STRUCT(int, nMaxHealth, 48)
		ADD_BOOL(bEnemy, 52, 0x1)
		ADD_BOOL(bDrawStat, 52, 0x2)
		ADD_BOOL(bDrawHealth, 52, 0x4)
		ADD_STRUCT(float, fDistance, 56)
		ADD_STRUCT(TrObject__OverlayType, eOverlayType, 60)
		ADD_STRUCT(int, nActorId, 64)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
