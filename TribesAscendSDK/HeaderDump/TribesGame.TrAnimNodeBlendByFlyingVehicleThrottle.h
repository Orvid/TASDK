#pragma once
#include "TribesGame.TrAnimNodeBlendList.h"
#include "TribesGame.TrVehicle.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrAnimNodeBlendByFlyingVehicleThrottle." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrAnimNodeBlendByFlyingVehicleThrottle : public TrAnimNodeBlendList
	{
	public:
		ADD_OBJECT(TrVehicle, m_TrVehicle)
	};
}
#undef ADD_OBJECT