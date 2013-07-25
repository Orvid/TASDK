#pragma once
#include "Engine.InterpTrackInst.h"
#include "Engine.InterpTrackVectorMaterialParam.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.InterpTrackInstVectorMaterialParam." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class InterpTrackInstVectorMaterialParam : public InterpTrackInst
	{
	public:
		ADD_OBJECT(InterpTrackVectorMaterialParam, InstancedTrack)
	};
}
#undef ADD_OBJECT
