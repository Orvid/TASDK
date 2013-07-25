#pragma once
#include "TribesGame__TrAnimNodeBlendList.h"
#include "TribesGame__TrDeployable.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrAnimNodeBlendByDeployableState." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrAnimNodeBlendByDeployableState : public TrAnimNodeBlendList
	{
	public:
		ADD_OBJECT(TrDeployable, m_TrDeployable)
	};
}
#undef ADD_OBJECT
