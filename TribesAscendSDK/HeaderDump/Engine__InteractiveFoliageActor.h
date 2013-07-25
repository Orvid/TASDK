#pragma once
#include "Engine__StaticMeshActor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InteractiveFoliageActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.InteractiveFoliageActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InteractiveFoliageActor : public StaticMeshActor
	{
	public:
		ADD_VAR(::FloatProperty, Mass, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxForce, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxTouchImpulse, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxDamageImpulse, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FoliageDamping, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FoliageStiffnessQuadratic, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FoliageStiffness, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FoliageTouchImpulseScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FoliageDamageImpulseScale, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, FoliagePosition, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, FoliageForce, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, FoliageVelocity, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, TouchingActorEntryPosition, 0xFFFFFFFF
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
