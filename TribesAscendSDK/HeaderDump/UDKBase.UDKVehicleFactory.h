#pragma once
#include "Engine.NavigationPoint.h"
#include "UDKBase.UDKVehicle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKVehicleFactory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKVehicleFactory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKVehicleFactory." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKVehicleFactory : public NavigationPoint
	{
	public:
		ADD_VAR(::IntProperty, TeamNum, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, HUDLocation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RespawnProgress, 0xFFFFFFFF)
		ADD_OBJECT(UDKVehicle, ChildVehicle)
		ADD_OBJECT(ScriptClass, VehicleClass)
		ADD_VAR(::BoolProperty, bReplicateChildVehicle, 0x2)
		ADD_VAR(::BoolProperty, bHasLockedVehicle, 0x1)
		ADD_VAR(::StrProperty, VehicleClassPath, 0xFFFFFFFF)
		void SpawnVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKVehicleFactory.SpawnVehicle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetHUDLocation(Vector NewHUDLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKVehicleFactory.SetHUDLocation");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = NewHUDLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		byte GetTeamNum()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKVehicleFactory.GetTeamNum");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT