#pragma once
#include "Core.Object.Rotator.h"
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " SkeletalMeshActor.CheckpointRecord." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty SkeletalMeshActor.CheckpointRecord." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class CheckpointRecord
	{
	public:
		ADD_STRUCT(::RotatorProperty, Rotation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Location, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSavedPosition, 0x4)
		ADD_VAR(::BoolProperty, bHidden, 0x2)
		ADD_VAR(::BoolProperty, bReplicated, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT