#pragma once
namespace UnrealScript
{
	class UDKAnimBlendByFall;
}
#include "UDKBase.UDKAnimBlendBase.h"
#include "UDKBase.UDKAnimBlendByFall.EBlendFallTypes.h"
#include "UDKBase.UDKAnimNodeJumpLeanOffset.h"
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
	class UDKAnimBlendByFall : public UDKAnimBlendBase
	{
	public:
		typedef UDKAnimBlendByFall__EBlendFallTypes EBlendFallTypes;
		ADD_OBJECT(UDKAnimNodeJumpLeanOffset, CachedLeanNode, 320)
		ADD_STRUCT(float, LastFallingVelocity, 316)
		ADD_STRUCT(UDKAnimBlendByFall__EBlendFallTypes, FallState, 312)
		ADD_STRUCT(float, ToDblJumpUprightTime, 308)
		ADD_STRUCT(float, PreLandStartUprightTime, 304)
		ADD_STRUCT(float, PreLandTime, 300)
		ADD_BOOL(bDodgeFall, 296, 0x4)
		ADD_BOOL(bDidDoubleJump, 296, 0x2)
		ADD_BOOL(bIgnoreDoubleJumps, 296, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
