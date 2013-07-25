#pragma once
#include "TribesGame__TrEffect.h"
#include "TribesGame__TrPawn.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrEffect_Managed." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrEffect_Managed." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrEffect_Managed : public TrEffect
	{
	public:
		ADD_VAR(::FloatProperty, m_fLifeTime, 0xFFFFFFFF)
		ADD_OBJECT(TrPawn, m_PawnTarget)
		// Here lies the not-yet-implemented method 'Apply'
		// Here lies the not-yet-implemented method 'RemoveEffect'
		// Here lies the not-yet-implemented method 'Remove'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
