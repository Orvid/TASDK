#pragma once
namespace UnrealScript
{
	struct ParticleModuleTypeDataPhysX__PhysXEmitterVerticalLodProperties;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct ParticleModuleTypeDataPhysX__PhysXEmitterVerticalLodProperties
	{
	public:
		ADD_STRUCT(float, RelativeFadeoutTime, 12)
		ADD_STRUCT(float, SpawnLodRateVsLifeBias, 8)
		ADD_STRUCT(float, WeightForSpawnLod, 4)
		ADD_STRUCT(float, WeightForFifo, 0)
	};
}
#undef ADD_STRUCT
