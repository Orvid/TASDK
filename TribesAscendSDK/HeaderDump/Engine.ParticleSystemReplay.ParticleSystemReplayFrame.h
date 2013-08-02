#pragma once
namespace UnrealScript
{
	struct ParticleSystemReplay__ParticleSystemReplayFrame;
}
#include "Engine.ParticleSystemReplay.ParticleEmitterReplayFrame.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct ParticleSystemReplay__ParticleSystemReplayFrame
	{
	public:
		ADD_STRUCT(ScriptArray<ParticleSystemReplay__ParticleEmitterReplayFrame>, Emitters, 0)
	};
}
#undef ADD_STRUCT
