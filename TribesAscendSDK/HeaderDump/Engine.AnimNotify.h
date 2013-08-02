#pragma once
namespace UnrealScript
{
	class AnimNotify;
}
#include "Core.Object.h"
#include "Core.Object.Color.h"
#include "Engine.AnimNodeSequence.h"
#include "Engine.AnimSequence.AnimNotifyEvent.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class AnimNotify : public Object
	{
	public:
		ADD_STRUCT(Object__Color, NotifyColor, 60)
		bool FindNextNotifyOfClass(class AnimNodeSequence* AnimSeqInstigator, ScriptClass* NotifyClass, AnimSequence__AnimNotifyEvent& OutEvent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11128);
			byte params[32] = { NULL };
			*(class AnimNodeSequence**)params = AnimSeqInstigator;
			*(ScriptClass**)&params[4] = NotifyClass;
			*(AnimSequence__AnimNotifyEvent*)&params[8] = OutEvent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutEvent = *(AnimSequence__AnimNotifyEvent*)&params[8];
			return *(bool*)&params[28];
		}
	};
}
#undef ADD_STRUCT
