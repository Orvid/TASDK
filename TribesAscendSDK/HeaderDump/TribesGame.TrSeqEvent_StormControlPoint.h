#pragma once
namespace UnrealScript
{
	class TrSeqEvent_StormControlPoint;
}
#include "Engine.SequenceEvent.h"
namespace UnrealScript
{
	class TrSeqEvent_StormControlPoint : public SequenceEvent
	{
	public:
		int GetObjClassVersion()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(110929);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
	};
}
