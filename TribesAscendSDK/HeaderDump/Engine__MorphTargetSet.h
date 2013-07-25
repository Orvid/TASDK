#pragma once
#include "Core__Object.h"
#include "Engine__SkeletalMesh.h"
#include "Engine__MorphTarget.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.MorphTargetSet." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.MorphTargetSet." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MorphTargetSet : public Object
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Array_Mirror' for the property named 'RawWedgePointIndices'!
		ADD_OBJECT(SkeletalMesh, BaseSkelMesh)
		// Here lies the not-yet-implemented method 'FindMorphTarget'
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
