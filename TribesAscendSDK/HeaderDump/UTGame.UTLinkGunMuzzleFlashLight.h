#pragma once
namespace UnrealScript
{
	class UTLinkGunMuzzleFlashLight;
}
#include "UDKBase.UDKExplosionLight.h"
#include "UDKBase.UDKExplosionLight.LightValues.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UTLinkGunMuzzleFlashLight : public UDKExplosionLight
	{
	public:
		ADD_STRUCT(ScriptArray<UDKExplosionLight__LightValues>, RedTeamTimeShift, 624)
		ADD_STRUCT(ScriptArray<UDKExplosionLight__LightValues>, BlueTeamTimeShift, 636)
		void SetTeam(byte NewTeam)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48308);
			byte params[1] = { NULL };
			*params = NewTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
