#pragma once
namespace UnrealScript
{
	class UTSeqAct_HoverboardSpinJump;
}
#include "Engine.SequenceAction.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UTSeqAct_HoverboardSpinJump : public SequenceAction
	{
	public:
		ADD_STRUCT(float, WarmupTime, 232)
	};
}
#undef ADD_STRUCT
