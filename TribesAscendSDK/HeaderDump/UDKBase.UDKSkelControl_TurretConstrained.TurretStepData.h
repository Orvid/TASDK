#pragma once
#include "UDKBase.UDKSkelControl_TurretConstrained.TurretConstraintData.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UDKSkelControl_TurretConstrained__TurretStepData
	{
	public:
		ADD_STRUCT(UDKSkelControl_TurretConstrained__TurretConstraintData, MinAngle, 20)
		ADD_STRUCT(UDKSkelControl_TurretConstrained__TurretConstraintData, MaxAngle, 8)
		ADD_STRUCT(int, StepEndAngle, 4)
		ADD_STRUCT(int, StepStartAngle, 0)
	};
}
#undef ADD_STRUCT
