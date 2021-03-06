#pragma once
namespace UnrealScript
{
	class UDKAnimBlendByFlying;
}
#include "Engine.AnimNodeAimOffset.h"
#include "UDKBase.UDKAnimBlendBase.h"
#include "UDKBase.UDKAnimBlendByFlying.EFlyingState.h"
#include "UDKBase.UDKPawn.h"
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
	class UDKAnimBlendByFlying : public UDKAnimBlendBase
	{
	public:
		typedef UDKAnimBlendByFlying__EFlyingState EFlyingState;
		ADD_STRUCT(ScriptName, EndingAnimName, 324)
		ADD_BOOL(bHasEndingAnim, 320, 0x2)
		ADD_BOOL(bHasStartingAnim, 320, 0x1)
		ADD_STRUCT(ScriptName, StartingAnimName, 312)
		ADD_OBJECT(AnimNodeAimOffset, FlyingDir, 308)
		ADD_OBJECT(UDKAnimBlendBase, FlyingMode, 304)
		ADD_STRUCT(UDKAnimBlendByFlying__EFlyingState, FlyingState, 296)
		void UpdateFlyingState()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34511);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
