#pragma once
namespace UnrealScript
{
	struct AnimSequence__RawAnimSequenceTrack;
}
#include "Core.Object.Quat.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct AnimSequence__RawAnimSequenceTrack
	{
	public:
		ADD_STRUCT(ScriptArray<Vector>, PosKeys, 0)
		ADD_STRUCT(ScriptArray<Object__Quat>, RotKeys, 12)
	};
}
#undef ADD_STRUCT
