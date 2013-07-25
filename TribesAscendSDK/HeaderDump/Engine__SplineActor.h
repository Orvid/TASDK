#pragma once
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SplineActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SplineActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SplineActor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SplineActor : public Actor
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.InterpCurveFloat' for the property named 'SplineVelocityOverTime'!
		ADD_VAR(::IntProperty, visitedWeight, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, bestPathWeight, 0xFFFFFFFF)
		ADD_OBJECT(SplineActor, previousPath)
		ADD_OBJECT(SplineActor, prevOrdered)
		ADD_OBJECT(SplineActor, nextOrdered)
		ADD_VAR(::BoolProperty, bAlreadyVisited, 0x2)
		ADD_VAR(::BoolProperty, bDisableDestination, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'SplineColor'!
		ADD_STRUCT(::VectorProperty, SplineActorTangent, 0xFFFFFFFF
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
