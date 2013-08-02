#pragma once
namespace UnrealScript
{
	class CameraShake;
}
#include "Core.Object.h"
#include "Engine.CameraAnim.h"
#include "Engine.CameraShake.EInitialOscillatorOffset.h"
#include "Engine.CameraShake.FOscillator.h"
#include "Engine.CameraShake.ROscillator.h"
#include "Engine.CameraShake.VOscillator.h"
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
	class CameraShake : public Object
	{
	public:
		typedef CameraShake__EInitialOscillatorOffset EInitialOscillatorOffset;
		typedef CameraShake__FOscillator FOscillator;
		typedef CameraShake__VOscillator VOscillator;
		typedef CameraShake__ROscillator ROscillator;
		ADD_STRUCT(CameraShake__VOscillator, LocOscillation, 112)
		ADD_STRUCT(CameraShake__ROscillator, RotOscillation, 76)
		ADD_BOOL(bSingleInstance, 60, 0x1)
		ADD_BOOL(bRandomAnimSegment, 60, 0x2)
		ADD_STRUCT(float, OscillationDuration, 64)
		ADD_STRUCT(float, OscillationBlendInTime, 68)
		ADD_STRUCT(float, OscillationBlendOutTime, 72)
		ADD_STRUCT(CameraShake__FOscillator, FOVOscillation, 148)
		ADD_OBJECT(CameraAnim, Anim, 160)
		ADD_STRUCT(float, AnimPlayRate, 164)
		ADD_STRUCT(float, AnimScale, 168)
		ADD_STRUCT(float, AnimBlendInTime, 172)
		ADD_STRUCT(float, AnimBlendOutTime, 176)
		ADD_STRUCT(float, RandomAnimSegmentDuration, 180)
		float GetLocOscillationMagnitude()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12227);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		float GetRotOscillationMagnitude()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12228);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
