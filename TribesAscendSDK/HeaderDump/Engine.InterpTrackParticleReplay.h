#pragma once
namespace UnrealScript
{
	class InterpTrackParticleReplay;
}
#include "Engine.InterpTrack.h"
#include "Engine.InterpTrackParticleReplay.ParticleReplayTrackKey.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class InterpTrackParticleReplay : public InterpTrack
	{
	public:
		typedef InterpTrackParticleReplay__ParticleReplayTrackKey ParticleReplayTrackKey;
		ADD_STRUCT(ScriptArray<InterpTrackParticleReplay__ParticleReplayTrackKey>, TrackKeys, 128)
		ADD_STRUCT(float, FixedTimeStep, 144)
		ADD_BOOL(bIsCapturingReplay, 140, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
