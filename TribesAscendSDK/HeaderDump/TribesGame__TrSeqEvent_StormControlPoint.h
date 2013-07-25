#pragma once
#include "Engine__SequenceEvent.h"
namespace UnrealScript
{
	class TrSeqEvent_StormControlPoint : public SequenceEvent
	{
	public:
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrSeqEvent_StormControlPoint.GetObjClassVersion");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
