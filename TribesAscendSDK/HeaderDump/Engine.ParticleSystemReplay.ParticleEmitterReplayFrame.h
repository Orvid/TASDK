#pragma once
namespace UnrealScript
{
	struct ParticleSystemReplay__ParticleEmitterReplayFrame;
}
#include "Core.Object.Pointer.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct ParticleSystemReplay__ParticleEmitterReplayFrame
	{
	public:
		ADD_STRUCT(Object__Pointer, FrameState, 8)
		ADD_STRUCT(int, OriginalEmitterIndex, 4)
		ADD_STRUCT(int, EmitterType, 0)
	};
}
#undef ADD_STRUCT
