#pragma once
namespace UnrealScript
{
	class UDKAnimBlendByVehicle;
}
#include "Engine.Vehicle.h"
#include "UDKBase.UDKAnimBlendBase.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UDKAnimBlendByVehicle : public UDKAnimBlendBase
	{
	public:
		ADD_OBJECT(Vehicle, LastVehicle, 300)
		ADD_BOOL(bLastPawnDriving, 296, 0x1)
		void UpdateVehicleState()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34552);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_OBJECT
