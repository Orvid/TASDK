#pragma once
#include "Engine.AnimNodeSequence.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct AnimTree__AnimGroup
	{
	public:
		ADD_STRUCT(ScriptArray<class AnimNodeSequence*>, SeqNodes, 0)
		ADD_STRUCT(float, SynchPctPosition, 32)
		ADD_STRUCT(float, RateScale, 28)
		ADD_STRUCT(ScriptName, GroupName, 20)
		ADD_OBJECT(AnimNodeSequence, NotifyMaster, 16)
		ADD_OBJECT(AnimNodeSequence, SynchMaster, 12)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
