#pragma once
namespace UnrealScript
{
	struct AnimNodeSequenceBlendBase__AnimBlendInfo;
}
#include "Engine.AnimNodeSequenceBlendBase.AnimInfo.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct AnimNodeSequenceBlendBase__AnimBlendInfo
	{
	public:
		ADD_STRUCT(float, Weight, 24)
		ADD_STRUCT(AnimNodeSequenceBlendBase__AnimInfo, AnimInfo, 8)
		ADD_STRUCT(ScriptName, AnimName, 0)
	};
}
#undef ADD_STRUCT
