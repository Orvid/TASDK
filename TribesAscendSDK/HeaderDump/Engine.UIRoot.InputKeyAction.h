#pragma once
#include "Engine.SequenceOp.SeqOpOutputInputLink.h"
#include "Engine.SequenceOp.h"
#include "Core.Object.EInputEvent.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UIRoot__InputKeyAction
	{
	public:
		ADD_STRUCT(ScriptArray<SequenceOp__SeqOpOutputInputLink>, TriggeredOps, 12)
		ADD_STRUCT(ScriptArray<class SequenceOp*>, ActionsToExecute, 24)
		ADD_STRUCT(Object__EInputEvent, InputKeyState, 8)
		ADD_STRUCT(ScriptName, InputKeyName, 0)
	};
}
#undef ADD_STRUCT
