#pragma once
namespace UnrealScript
{
	class AnimMetaData_SkelControlKeyFrame;
}
#include "Engine.AnimMetaData_SkelControl.h"
#include "Engine.AnimSequence.TimeModifier.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class AnimMetaData_SkelControlKeyFrame : public AnimMetaData_SkelControl
	{
	public:
		ADD_STRUCT(ScriptArray<AnimSequence__TimeModifier>, KeyFrames, 84)
	};
}
#undef ADD_STRUCT
