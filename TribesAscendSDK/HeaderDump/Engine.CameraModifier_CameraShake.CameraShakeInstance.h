#pragma once
namespace UnrealScript
{
	struct CameraModifier_CameraShake__CameraShakeInstance;
}
#include "Core.Object.Matrix.h"
#include "Engine.Camera.ECameraAnimPlaySpace.h"
#include "Engine.CameraAnimInst.h"
#include "Engine.CameraShake.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct CameraModifier_CameraShake__CameraShakeInstance
	{
	public:
		ADD_STRUCT(Object__Matrix, UserPlaySpaceMatrix, 80)
		ADD_STRUCT(Camera__ECameraAnimPlaySpace, PlaySpace, 68)
		ADD_OBJECT(CameraAnimInst, AnimInst, 64)
		ADD_STRUCT(float, Scale, 60)
		ADD_STRUCT(float, FOVSinOffset, 56)
		ADD_STRUCT(Vector, RotSinOffset, 44)
		ADD_STRUCT(Vector, LocSinOffset, 32)
		ADD_STRUCT(float, CurrentBlendOutTime, 28)
		ADD_BOOL(bBlendingOut, 24, 0x1)
		ADD_STRUCT(float, CurrentBlendInTime, 20)
		ADD_BOOL(bBlendingIn, 16, 0x1)
		ADD_STRUCT(float, OscillatorTimeRemaining, 12)
		ADD_STRUCT(ScriptName, SourceShakeName, 4)
		ADD_OBJECT(CameraShake, SourceShake, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
