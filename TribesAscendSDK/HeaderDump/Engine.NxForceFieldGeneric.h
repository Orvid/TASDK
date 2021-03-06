#pragma once
namespace UnrealScript
{
	class NxForceFieldGeneric;
}
#include "Core.Object.Pointer.h"
#include "Engine.ForceFieldShape.h"
#include "Engine.NxForceField.h"
#include "Engine.NxForceFieldGeneric.FFG_ForceFieldCoordinates.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class NxForceFieldGeneric : public NxForceField
	{
	public:
		typedef NxForceFieldGeneric__FFG_ForceFieldCoordinates FFG_ForceFieldCoordinates;
		ADD_STRUCT(Object__Pointer, LinearKernel, 712)
		ADD_STRUCT(float, TorusRadius, 708)
		ADD_STRUCT(Vector, FalloffQuadratic, 696)
		ADD_STRUCT(Vector, FalloffLinear, 684)
		ADD_STRUCT(Vector, Noise, 672)
		ADD_STRUCT(Vector, VelocityTarget, 660)
		ADD_STRUCT(Vector, VelocityMultiplierZ, 648)
		ADD_STRUCT(Vector, VelocityMultiplierY, 636)
		ADD_STRUCT(Vector, VelocityMultiplierX, 624)
		ADD_STRUCT(Vector, PositionTarget, 612)
		ADD_STRUCT(Vector, PositionMultiplierZ, 600)
		ADD_STRUCT(Vector, PositionMultiplierY, 588)
		ADD_STRUCT(Vector, PositionMultiplierX, 576)
		ADD_STRUCT(Vector, Constant, 564)
		ADD_STRUCT(NxForceFieldGeneric__FFG_ForceFieldCoordinates, Coordinates, 560)
		ADD_OBJECT(ForceFieldShape, Shape, 540)
		ADD_STRUCT(float, RoughExtentZ, 556)
		ADD_STRUCT(float, RoughExtentY, 552)
		ADD_STRUCT(float, RoughExtentX, 548)
		void DoInitRBPhys()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21201);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
