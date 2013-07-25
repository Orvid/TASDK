#pragma once
#include "Engine__SequenceAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTSeqAct_EnterVehicle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTSeqAct_EnterVehicle : public SequenceAction
	{
	public:
		ADD_VAR(::IntProperty, SeatIndex, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'Activated'
	};
}
#undef ADD_VAR
