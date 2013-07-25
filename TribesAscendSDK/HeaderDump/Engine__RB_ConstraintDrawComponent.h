#pragma once
#include "Engine__PrimitiveComponent.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.RB_ConstraintDrawComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class RB_ConstraintDrawComponent : public PrimitiveComponent
	{
	public:
		ADD_OBJECT(MaterialInterface, LimitMaterial)
	};
}
#undef ADD_OBJECT
