#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct InterpTrackParticleReplay__ParticleReplayTrackKey
	{
	public:
		ADD_STRUCT(int, ClipIDNumber, 8)
		ADD_STRUCT(float, Duration, 4)
		ADD_STRUCT(float, Time, 0)
	};
}
#undef ADD_STRUCT
