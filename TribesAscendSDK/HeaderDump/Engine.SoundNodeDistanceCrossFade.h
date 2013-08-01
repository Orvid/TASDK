#pragma once
#include "Engine.SoundNode.h"
#include "Engine.SoundNodeDistanceCrossFade.DistanceDatum.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SoundNodeDistanceCrossFade : public SoundNode
	{
	public:
		ADD_STRUCT(ScriptArray<SoundNodeDistanceCrossFade__DistanceDatum>, CrossFadeInput, 76)
	};
}
#undef ADD_STRUCT
