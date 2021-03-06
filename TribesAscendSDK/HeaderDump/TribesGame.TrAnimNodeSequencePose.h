#pragma once
namespace UnrealScript
{
	class TrAnimNodeSequencePose;
}
#include "Core.Object.BoneAtom.h"
#include "Engine.AnimNodeSequence.h"
#include "TribesGame.TrPawn.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrAnimNodeSequencePose : public AnimNodeSequence
	{
	public:
		ADD_STRUCT(ScriptArray<Object__BoneAtom>, m_PoseSpaceBases, 320)
		void FillWithPose(class TrPawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66481);
			byte params[4] = { NULL };
			*(class TrPawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
