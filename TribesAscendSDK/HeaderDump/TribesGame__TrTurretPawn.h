#pragma once
#include "TribesGame__TrPawn.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrTurretPawn." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrTurretPawn : public TrPawn
	{
	public:
		ADD_OBJECT(TrDeployable, m_OwnerDeployable)
	};
}
#undef ADD_OBJECT
