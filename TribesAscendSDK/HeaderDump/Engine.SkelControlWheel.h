#pragma once
namespace UnrealScript
{
	class SkelControlWheel;
}
#include "Core.Object.EAxis.h"
#include "Engine.SkelControlSingleBone.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SkelControlWheel : public SkelControlSingleBone
	{
	public:
		ADD_BOOL(bInvertWheelSteering, 256, 0x2)
		ADD_BOOL(bInvertWheelRoll, 256, 0x1)
		ADD_STRUCT(float, WheelSteering, 252)
		ADD_STRUCT(Object__EAxis, WheelSteeringAxis, 249)
		ADD_STRUCT(Object__EAxis, WheelRollAxis, 248)
		ADD_STRUCT(float, WheelRoll, 244)
		ADD_STRUCT(float, WheelMaxRenderDisplacement, 240)
		ADD_STRUCT(float, WheelDisplacement, 236)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
