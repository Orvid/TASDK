#pragma once
namespace UnrealScript
{
	class UTSeqAct_ToggleAnnouncements;
}
#include "Engine.SequenceAction.h"
namespace UnrealScript
{
	class UTSeqAct_ToggleAnnouncements : public SequenceAction
	{
	public:
		void Activated()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49158);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
