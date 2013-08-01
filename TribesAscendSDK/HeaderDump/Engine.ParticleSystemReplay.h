#pragma once
#include "Core.Object.h"
#include "Engine.ParticleSystemReplay.ParticleSystemReplayFrame.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleSystemReplay : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<ParticleSystemReplay__ParticleSystemReplayFrame>, Frames, 64)
		ADD_STRUCT(int, ClipIDNumber, 60)
	};
}
#undef ADD_STRUCT
