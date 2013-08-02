#pragma once
namespace UnrealScript
{
	class CameraModifier_CameraShake;
}
#include "Core.Object.TPOV.h"
#include "Engine.Camera.h"
#include "Engine.Camera.ECameraAnimPlaySpace.h"
#include "Engine.CameraModifier.h"
#include "Engine.CameraModifier_CameraShake.CameraShakeInstance.h"
#include "Engine.CameraShake.h"
#include "Engine.CameraShake.FOscillator.h"
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
	class CameraModifier_CameraShake : public CameraModifier
	{
	public:
		typedef CameraModifier_CameraShake__CameraShakeInstance CameraShakeInstance;
		ADD_STRUCT(ScriptArray<CameraModifier_CameraShake__CameraShakeInstance>, ActiveShakes, 88)
		ADD_STRUCT(float, SplitScreenShakeScale, 100)
		float InitializeOffset(CameraShake__FOscillator& Param)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12278);
			byte params[16] = { NULL };
			*(CameraShake__FOscillator*)params = Param;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Param = *(CameraShake__FOscillator*)params;
			return *(float*)&params[12];
		}
		void ReinitShake(int ActiveShakeIdx, float Scale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12281);
			byte params[8] = { NULL };
			*(int*)params = ActiveShakeIdx;
			*(float*)&params[4] = Scale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		CameraModifier_CameraShake__CameraShakeInstance InitializeShake(class CameraShake* NewShake, float Scale, Camera__ECameraAnimPlaySpace PlaySpace, Rotator UserPlaySpaceRot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12290);
			byte params[165] = { NULL };
			*(class CameraShake**)params = NewShake;
			*(float*)&params[4] = Scale;
			*(Camera__ECameraAnimPlaySpace*)&params[8] = PlaySpace;
			*(Rotator*)&params[12] = UserPlaySpaceRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(CameraModifier_CameraShake__CameraShakeInstance*)&params[32];
		}
		void AddCameraShake(class CameraShake* NewShake, float Scale, Camera__ECameraAnimPlaySpace PlaySpace, Rotator UserPlaySpaceRot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12300);
			byte params[21] = { NULL };
			*(class CameraShake**)params = NewShake;
			*(float*)&params[4] = Scale;
			*(Camera__ECameraAnimPlaySpace*)&params[8] = PlaySpace;
			*(Rotator*)&params[12] = UserPlaySpaceRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveCameraShake(class CameraShake* Shake)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12307);
			byte params[4] = { NULL };
			*(class CameraShake**)params = Shake;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveAllCameraShakes()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12311);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateCameraShake(float DeltaTime, CameraModifier_CameraShake__CameraShakeInstance& Shake, Object__TPOV& OutPOV)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12314);
			byte params[176] = { NULL };
			*(float*)params = DeltaTime;
			*(CameraModifier_CameraShake__CameraShakeInstance*)&params[16] = Shake;
			*(Object__TPOV*)&params[160] = OutPOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Shake = *(CameraModifier_CameraShake__CameraShakeInstance*)&params[16];
			OutPOV = *(Object__TPOV*)&params[160];
		}
		bool ModifyCamera(class Camera* Camera, float DeltaTime, Object__TPOV& OutPOV)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12318);
			byte params[40] = { NULL };
			*(class Camera**)params = Camera;
			*(float*)&params[4] = DeltaTime;
			*(Object__TPOV*)&params[8] = OutPOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutPOV = *(Object__TPOV*)&params[8];
			return *(bool*)&params[36];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
