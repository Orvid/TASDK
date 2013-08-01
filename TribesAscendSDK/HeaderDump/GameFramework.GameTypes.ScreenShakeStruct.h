#pragma once
#include "Core.Object.Vector.h"
#include "GameFramework.GameTypes.ShakeParams.h"
#include "GameFramework.GameTypes.EShakeParam.h"
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
	struct GameTypes__ScreenShakeStruct
	{
	public:
		ADD_STRUCT(float, TimeToGo, 0)
		ADD_STRUCT(float, TimeDuration, 4)
		ADD_STRUCT(Vector, RotAmplitude, 8)
		ADD_STRUCT(Vector, RotFrequency, 20)
		ADD_STRUCT(Vector, RotSinOffset, 32)
		ADD_STRUCT(GameTypes__ShakeParams, RotParam, 44)
		ADD_STRUCT(Vector, LocAmplitude, 48)
		ADD_STRUCT(Vector, LocFrequency, 60)
		ADD_STRUCT(Vector, LocSinOffset, 72)
		ADD_STRUCT(GameTypes__ShakeParams, LocParam, 84)
		ADD_STRUCT(float, FOVAmplitude, 88)
		ADD_STRUCT(float, FOVFrequency, 92)
		ADD_STRUCT(float, FOVSinOffset, 96)
		ADD_STRUCT(GameTypes__EShakeParam, FOVParam, 100)
		ADD_STRUCT(ScriptName, ShakeName, 104)
		ADD_BOOL(bOverrideTargetingDampening, 112, 0x1)
		ADD_STRUCT(float, TargetingDampening, 116)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
