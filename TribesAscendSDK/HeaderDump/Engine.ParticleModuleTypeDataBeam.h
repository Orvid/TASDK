#pragma once
namespace UnrealScript
{
	class ParticleModuleTypeDataBeam;
}
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#include "Engine.ParticleModuleTypeDataBase.h"
#include "Engine.ParticleModuleTypeDataBeam.EBeamEndPointMethod.h"
#include "Engine.ParticleModuleTypeDataBeam.EBeamMethod.h"
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
	class ParticleModuleTypeDataBeam : public ParticleModuleTypeDataBase
	{
	public:
		typedef ParticleModuleTypeDataBeam__EBeamMethod EBeamMethod;
		typedef ParticleModuleTypeDataBeam__EBeamEndPointMethod EBeamEndPointMethod;
		ADD_BOOL(RenderTessellation, 224, 0x8)
		ADD_BOOL(RenderLines, 224, 0x4)
		ADD_BOOL(RenderDirectLine, 224, 0x2)
		ADD_BOOL(RenderGeometry, 224, 0x1)
		ADD_STRUCT(int, TextureTile, 220)
		ADD_STRUCT(DistributionVector__RawDistributionVector, EndPointDirection, 192)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, TargetStrength, 164)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, EmitterStrength, 136)
		ADD_STRUCT(int, TessellationFactor, 132)
		ADD_STRUCT(DistributionVector__RawDistributionVector, EndPoint, 104)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, Distance, 76)
		ADD_STRUCT(ParticleModuleTypeDataBeam__EBeamEndPointMethod, EndPointMethod, 73)
		ADD_STRUCT(ParticleModuleTypeDataBeam__EBeamMethod, BeamMethod, 72)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
