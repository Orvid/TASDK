#pragma once
namespace UnrealScript
{
	class AnimNodeAimOffset;
}
#include "Core.Object.Vector2D.h"
#include "Engine.AnimNodeAimOffset.AimComponent.h"
#include "Engine.AnimNodeAimOffset.AimOffsetProfile.h"
#include "Engine.AnimNodeAimOffset.AimTransform.h"
#include "Engine.AnimNodeAimOffset.EAimID.h"
#include "Engine.AnimNodeAimOffset.EAnimAimDir.h"
#include "Engine.AnimNodeBlendBase.h"
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
	class AnimNodeAimOffset : public AnimNodeBlendBase
	{
	public:
		typedef AnimNodeAimOffset__EAnimAimDir EAnimAimDir;
		typedef AnimNodeAimOffset__EAimID EAimID;
		typedef AnimNodeAimOffset__AimTransform AimTransform;
		typedef AnimNodeAimOffset__AimComponent AimComponent;
		typedef AnimNodeAimOffset__AimOffsetProfile AimOffsetProfile;
		ADD_STRUCT(ScriptArray<byte>, RequiredBones, 272)
		ADD_STRUCT(ScriptArray<byte>, AimCpntIndexLUT, 284)
		ADD_STRUCT(ScriptArray<AnimNodeAimOffset__AimOffsetProfile>, Profiles, 300)
		ADD_STRUCT(int, CurrentProfileIndex, 312)
		ADD_OBJECT(AnimNodeAimOffset, TemplateNode, 296)
		ADD_STRUCT(AnimNodeAimOffset__EAnimAimDir, ForcedAimDir, 268)
		ADD_STRUCT(int, PassThroughAtOrAboveLOD, 264)
		ADD_BOOL(bSynchronizeNodesInEditor, 260, 0x8)
		ADD_BOOL(bPassThroughWhenNotRendered, 260, 0x4)
		ADD_BOOL(bBakeFromAnimations, 260, 0x2)
		ADD_BOOL(bForceAimDir, 260, 0x1)
		ADD_STRUCT(Object__Vector2D, AngleOffset, 252)
		ADD_STRUCT(Object__Vector2D, Aim, 244)
		void SetActiveProfileByName(ScriptName ProfileName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10809);
			byte params[8] = { NULL };
			*(ScriptName*)params = ProfileName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetActiveProfileByIndex(int ProfileIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10811);
			byte params[4] = { NULL };
			*(int*)params = ProfileIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
