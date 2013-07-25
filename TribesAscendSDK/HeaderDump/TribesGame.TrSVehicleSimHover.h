#pragma once
#include "UDKBase.UDKVehicleSimHover.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrSVehicleSimHover." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrSVehicleSimHover." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrSVehicleSimHover : public UDKVehicleSimHover
	{
	public:
		ADD_VAR(::BoolProperty, bShouldStabilizeRotation, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct UDKBase.UDKVehicleSimChopper.AnglePID' for the property named 'RollGain'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
