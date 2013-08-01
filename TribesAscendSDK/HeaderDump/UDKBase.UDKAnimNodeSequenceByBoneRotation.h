#pragma once
#include "Engine.AnimNodeSequence.h"
#include "UDKBase.UDKAnimNodeSequenceByBoneRotation.AnimByRotation.h"
#include "Core.Object.EAxis.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UDKAnimNodeSequenceByBoneRotation : public AnimNodeSequence
	{
	public:
		ADD_STRUCT(ScriptArray<UDKAnimNodeSequenceByBoneRotation__AnimByRotation>, AnimList, 332)
		ADD_STRUCT(Object__EAxis, BoneAxis, 328)
		ADD_STRUCT(ScriptName, BoneName, 320)
		void OnBecomeRelevant()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34628);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
