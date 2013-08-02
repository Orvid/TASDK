#pragma once
namespace UnrealScript
{
	class ParticleSystem;
}
#include "Core.Object.h"
#include "Core.Object.Box.h"
#include "Core.Object.Color.h"
#include "Engine.InterpCurveEdSetup.h"
#include "Engine.ParticleEmitter.h"
#include "Engine.ParticleSystem.EParticleSystemOcclusionBoundsMethod.h"
#include "Engine.ParticleSystem.EParticleSystemUpdateMode.h"
#include "Engine.ParticleSystem.LODSoloTrack.h"
#include "Engine.ParticleSystem.ParticleSystemLOD.h"
#include "Engine.ParticleSystem.ParticleSystemLODMethod.h"
#include "Engine.Texture2D.h"
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
	class ParticleSystem : public Object
	{
	public:
		typedef ParticleSystem__ParticleSystemLODMethod ParticleSystemLODMethod;
		typedef ParticleSystem__EParticleSystemOcclusionBoundsMethod EParticleSystemOcclusionBoundsMethod;
		typedef ParticleSystem__EParticleSystemUpdateMode EParticleSystemUpdateMode;
		typedef ParticleSystem__ParticleSystemLOD ParticleSystemLOD;
		typedef ParticleSystem__LODSoloTrack LODSoloTrack;
		ADD_STRUCT(ParticleSystem__EParticleSystemUpdateMode, SystemUpdateMode, 60)
		ADD_STRUCT(ParticleSystem__ParticleSystemLODMethod, LODMethod, 61)
		ADD_STRUCT(ParticleSystem__EParticleSystemOcclusionBoundsMethod, OcclusionBoundsMethod, 62)
		ADD_STRUCT(float, UpdateTime_FPS, 64)
		ADD_STRUCT(float, UpdateTime_Delta, 68)
		ADD_STRUCT(float, WarmupTime, 72)
		ADD_STRUCT(ScriptArray<class ParticleEmitter*>, Emitters, 76)
		ADD_STRUCT(Rotator, ThumbnailAngle, 92)
		ADD_STRUCT(float, ThumbnailDistance, 104)
		ADD_STRUCT(float, ThumbnailWarmup, 108)
		ADD_BOOL(bLit, 112, 0x1)
		ADD_BOOL(bOrientZAxisTowardCamera, 112, 0x2)
		ADD_BOOL(bRegenerateLODDuplicate, 112, 0x4)
		ADD_BOOL(bUseFixedRelativeBoundingBox, 112, 0x8)
		ADD_BOOL(bShouldResetPeakCounts, 112, 0x10)
		ADD_BOOL(bHasPhysics, 112, 0x20)
		ADD_BOOL(bUseRealtimeThumbnail, 112, 0x40)
		ADD_BOOL(ThumbnailImageOutOfDate, 112, 0x80)
		ADD_BOOL(bSkipSpawnCountCheck, 112, 0x100)
		ADD_BOOL(bUseDelayRange, 112, 0x200)
		ADD_BOOL(bUseMobilePointSprites, 112, 0x400)
		ADD_OBJECT(InterpCurveEdSetup, CurveEdSetup, 116)
		ADD_STRUCT(float, LODDistanceCheckTime, 120)
		ADD_STRUCT(ScriptArray<float>, LODDistances, 124)
		ADD_STRUCT(int, EditorLODSetting, 136)
		ADD_STRUCT(ScriptArray<ParticleSystem__ParticleSystemLOD>, LODSettings, 140)
		ADD_STRUCT(Object__Box, FixedRelativeBoundingBox, 152)
		ADD_STRUCT(float, SecondsBeforeInactive, 180)
		ADD_STRUCT(ScriptString*, FloorMesh, 184)
		ADD_STRUCT(Vector, FloorPosition, 196)
		ADD_STRUCT(Rotator, FloorRotation, 208)
		ADD_STRUCT(float, FloorScale, 220)
		ADD_STRUCT(Vector, FloorScale3D, 224)
		ADD_STRUCT(Object__Color, BackgroundColor, 236)
		ADD_OBJECT(Texture2D, ThumbnailImage, 240)
		ADD_STRUCT(float, Delay, 244)
		ADD_STRUCT(float, DelayLow, 248)
		ADD_STRUCT(Vector, MacroUVPosition, 252)
		ADD_STRUCT(float, MacroUVRadius, 264)
		ADD_STRUCT(Object__Box, CustomOcclusionBounds, 268)
		ADD_STRUCT(ScriptArray<ParticleSystem__LODSoloTrack>, SoloTracking, 296)
		ParticleSystem__ParticleSystemLODMethod GetCurrentLODMethod()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23881);
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ParticleSystem__ParticleSystemLODMethod*)params;
		}
		int GetLODLevelCount()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23883);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		float GetLODDistance(int LODLevelIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23885);
			byte params[8] = { NULL };
			*(int*)params = LODLevelIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		void SetCurrentLODMethod(ParticleSystem__ParticleSystemLODMethod InMethod)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23888);
			byte params[1] = { NULL };
			*(ParticleSystem__ParticleSystemLODMethod*)params = InMethod;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SetLODDistance(int LODLevelIndex, float InDistance)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23890);
			byte params[12] = { NULL };
			*(int*)params = LODLevelIndex;
			*(float*)&params[4] = InDistance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
