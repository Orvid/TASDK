#pragma once
namespace UnrealScript
{
	struct ParticleModuleTypeDataBeam2__BeamTargetData;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct ParticleModuleTypeDataBeam2__BeamTargetData
	{
	public:
		ADD_STRUCT(float, TargetPercentage, 8)
		ADD_STRUCT(ScriptName, TargetName, 0)
	};
}
#undef ADD_STRUCT
