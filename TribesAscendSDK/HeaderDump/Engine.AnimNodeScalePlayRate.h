#pragma once
namespace UnrealScript
{
	class AnimNodeScalePlayRate;
}
#include "Engine.AnimNodeBlendBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class AnimNodeScalePlayRate : public AnimNodeBlendBase
	{
	public:
		ADD_STRUCT(float, ScaleByValue, 244)
	};
}
#undef ADD_STRUCT
