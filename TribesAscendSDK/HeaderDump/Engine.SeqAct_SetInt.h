#pragma once
namespace UnrealScript
{
	class SeqAct_SetInt;
}
#include "Engine.SeqAct_SetSequenceVariable.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqAct_SetInt : public SeqAct_SetSequenceVariable
	{
	public:
		ADD_STRUCT(ScriptArray<int>, Value, 236)
		ADD_STRUCT(int, Target, 232)
		int GetObjClassVersion()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25884);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
	};
}
#undef ADD_STRUCT
