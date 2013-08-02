#pragma once
namespace UnrealScript
{
	struct CoverLink__CoverSlot;
}
#include "Engine.CoverLink.CoverInfo.h"
#include "Engine.CoverLink.ECoverAction.h"
#include "Engine.CoverLink.ECoverLocationDescription.h"
#include "Engine.CoverLink.ECoverType.h"
#include "Engine.CoverLink.FireLink.h"
#include "Engine.CoverLink.SlotMoveRef.h"
#include "Engine.Pawn.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct CoverLink__CoverSlot
	{
	public:
		ADD_STRUCT(ScriptArray<CoverLink__ECoverAction>, Actions, 36)
		ADD_STRUCT(ScriptArray<CoverLink__FireLink>, FireLinks, 48)
		ADD_STRUCT(ScriptArray<CoverLink__FireLink>, RejectedFireLinks, 60)
		ADD_STRUCT(ScriptArray<int>, ExposedCoverPackedProperties, 72)
		ADD_STRUCT(ScriptArray<CoverLink__SlotMoveRef>, SlipRefs, 88)
		ADD_STRUCT(ScriptArray<CoverLink__CoverInfo>, OverlapClaimsList, 100)
		ADD_BOOL(bFailedToFindSurface, 112, 0x200000)
		ADD_BOOL(bSelected, 112, 0x100000)
		ADD_BOOL(bPlayerOnly, 112, 0x80000)
		ADD_BOOL(bForceNoGroundAdjust, 112, 0x40000)
		ADD_BOOL(bAllowSwatTurn, 112, 0x20000)
		ADD_BOOL(bAllowClimbUp, 112, 0x10000)
		ADD_BOOL(bAllowCoverSlip, 112, 0x8000)
		ADD_BOOL(bAllowMantle, 112, 0x4000)
		ADD_BOOL(bAllowPopup, 112, 0x2000)
		ADD_BOOL(bEnabled, 112, 0x1000)
		ADD_BOOL(bCanSwatTurn_Right, 112, 0x800)
		ADD_BOOL(bCanSwatTurn_Left, 112, 0x400)
		ADD_BOOL(bCanCoverSlip_Right, 112, 0x200)
		ADD_BOOL(bCanCoverSlip_Left, 112, 0x100)
		ADD_BOOL(bForceCanCoverSlip_Right, 112, 0x80)
		ADD_BOOL(bForceCanCoverSlip_Left, 112, 0x40)
		ADD_BOOL(bCanClimbUp, 112, 0x20)
		ADD_BOOL(bCanMantle, 112, 0x10)
		ADD_BOOL(bCanPopUp, 112, 0x8)
		ADD_BOOL(bForceCanPopUp, 112, 0x4)
		ADD_BOOL(bLeanRight, 112, 0x2)
		ADD_BOOL(bLeanLeft, 112, 0x1)
		ADD_STRUCT(int, TurnTargetPackedProperties, 84)
		ADD_STRUCT(Rotator, RotationOffset, 24)
		ADD_STRUCT(Vector, LocationOffset, 12)
		ADD_STRUCT(CoverLink__ECoverLocationDescription, LocationDescription, 10)
		ADD_STRUCT(CoverLink__ECoverType, CoverType, 9)
		ADD_STRUCT(CoverLink__ECoverType, ForceCoverType, 8)
		ADD_STRUCT(float, SlotValidAfterTime, 4)
		ADD_OBJECT(Pawn, SlotOwner, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
