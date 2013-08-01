#pragma once
#include "Engine.AnimSequence.TimeModifier.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct AnimSequence__SkelControlModifier
	{
	public:
		ADD_STRUCT(ScriptName, SkelControlName, 0)
		ADD_STRUCT(ScriptArray<AnimSequence__TimeModifier>, Modifiers, 8)
	};
}
#undef ADD_STRUCT
