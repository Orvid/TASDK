#pragma once
namespace UnrealScript
{
	class SeqAct_RangeSwitch;
}
#include "Engine.SeqAct_RangeSwitch.SwitchRange.h"
#include "Engine.SequenceAction.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqAct_RangeSwitch : public SequenceAction
	{
	public:
		typedef SeqAct_RangeSwitch__SwitchRange SwitchRange;
		ADD_STRUCT(ScriptArray<SeqAct_RangeSwitch__SwitchRange>, Ranges, 232)
	};
}
#undef ADD_STRUCT
