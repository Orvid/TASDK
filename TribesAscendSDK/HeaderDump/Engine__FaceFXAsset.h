#pragma once
#include "Core__Object.h"
#include "Engine__SkeletalMesh.h"
#include "Engine__FaceFXAnimSet.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.FaceFXAsset." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.FaceFXAsset." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.FaceFXAsset." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class FaceFXAsset : public Object
	{
	public:
		ADD_VAR(::IntProperty, NumLoadErrors, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'FaceFXActor'!
		ADD_OBJECT(SkeletalMesh, DefaultSkelMesh)
		// Here lies the not-yet-implemented method 'MountFaceFXAnimSet'
		// Here lies the not-yet-implemented method 'UnmountFaceFXAnimSet'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
