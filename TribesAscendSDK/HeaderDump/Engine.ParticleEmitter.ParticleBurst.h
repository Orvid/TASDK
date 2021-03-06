#pragma once
namespace UnrealScript
{
	struct ParticleEmitter__ParticleBurst;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct ParticleEmitter__ParticleBurst
	{
	public:
		ADD_STRUCT(float, Time, 8)
		ADD_STRUCT(int, CountLow, 4)
		ADD_STRUCT(int, Count, 0)
	};
}
#undef ADD_STRUCT
