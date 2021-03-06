#pragma once
namespace UnrealScript
{
	class SceneCaptureComponent;
}
#include "Core.Object.Color.h"
#include "Core.Object.Pointer.h"
#include "Engine.ActorComponent.h"
#include "Engine.PostProcessChain.h"
#include "Engine.SceneCaptureComponent.ESceneCaptureViewMode.h"
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
	class SceneCaptureComponent : public ActorComponent
	{
	public:
		typedef SceneCaptureComponent__ESceneCaptureViewMode ESceneCaptureViewMode;
		ADD_BOOL(bEnabled, 88, 0x1)
		ADD_STRUCT(ScriptArray<Object__Pointer>, PostProcessProxies, 132)
		ADD_STRUCT(Object__Pointer, ViewState, 128)
		ADD_STRUCT(Object__Pointer, CaptureInfo, 124)
		ADD_STRUCT(float, MaxStreamingUpdateDist, 120)
		ADD_STRUCT(float, MaxViewDistanceOverride, 116)
		ADD_STRUCT(float, MaxUpdateDist, 112)
		ADD_OBJECT(PostProcessChain, PostProcess, 108)
		ADD_STRUCT(float, FrameRate, 104)
		ADD_STRUCT(int, SceneLOD, 100)
		ADD_STRUCT(SceneCaptureComponent__ESceneCaptureViewMode, ViewMode, 96)
		ADD_STRUCT(Object__Color, ClearColor, 92)
		ADD_BOOL(bSkipRenderingDepthPrepass, 88, 0x40)
		ADD_BOOL(bSkipUpdateIfOwnerOccluded, 88, 0x20)
		ADD_BOOL(bSkipUpdateIfTextureUsersOccluded, 88, 0x10)
		ADD_BOOL(bUseMainScenePostProcessSettings, 88, 0x8)
		ADD_BOOL(bEnableFog, 88, 0x4)
		ADD_BOOL(bEnablePostProcess, 88, 0x2)
		void SetEnabled(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24681);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFrameRate(float NewFrameRate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24701);
			byte params[4] = { NULL };
			*(float*)params = NewFrameRate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
