#pragma once
#include "UDKBase__UDKVehicleBase.h"
#include "UDKBase__UDKWeapon.h"
#include "UDKBase__UDKVehicle.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKWeaponPawn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKWeaponPawn." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKWeaponPawn : public UDKVehicleBase
	{
	public:
		ADD_VAR(::IntProperty, MySeatIndex, 0xFFFFFFFF)
		ADD_OBJECT(UDKWeapon, MyVehicleWeapon)
		ADD_OBJECT(UDKVehicle, MyVehicle)
		// Here lies the not-yet-implemented method 'GetTargetLocation'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
