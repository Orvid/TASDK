#pragma once
#include "Engine__MaterialInterface.h"
#include "Engine__InterpTrackVectorBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InterpTrackVectorMaterialParam." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.InterpTrackVectorMaterialParam." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class InterpTrackVectorMaterialParam : public InterpTrackVectorBase
	{
	public:
		ADD_VAR(::BoolProperty, bNeedsMaterialRefsUpdate, 0x1)
		ADD_VAR(::NameProperty, ParamName, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInterface, Material)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
