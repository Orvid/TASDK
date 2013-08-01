#pragma once
#include "Engine.AnimNodeBlendBase.h"
#include "Engine.AnimNodeBlendMultiBone.ChildBoneBlendInfo.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class AnimNodeBlendMultiBone : public AnimNodeBlendBase
	{
	public:
		ADD_STRUCT(ScriptArray<AnimNodeBlendMultiBone__ChildBoneBlendInfo>, BlendTargetList, 244)
		ADD_STRUCT(ScriptArray<byte>, SourceRequiredBones, 256)
		void SetTargetStartBone(int TargetIdx, ScriptName StartBoneName, float PerBoneIncrease)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10875);
			byte params[16] = { NULL };
			*(int*)params = TargetIdx;
			*(ScriptName*)&params[4] = StartBoneName;
			*(float*)&params[12] = PerBoneIncrease;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
