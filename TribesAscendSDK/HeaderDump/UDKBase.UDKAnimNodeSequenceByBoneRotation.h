#pragma once
#include "Engine.AnimNodeSequence.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKAnimNodeSequenceByBoneRotation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKAnimNodeSequenceByBoneRotation : public AnimNodeSequence
	{
	public:
		ADD_VAR(::ByteProperty, BoneAxis, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BoneName, 0xFFFFFFFF)
		void OnBecomeRelevant()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKAnimNodeSequenceByBoneRotation.OnBecomeRelevant");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR