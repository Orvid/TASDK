#pragma once
namespace UnrealScript
{
	class ParticleModuleSubUVSelect;
}
#include "Core.DistributionVector.RawDistributionVector.h"
#include "Engine.ParticleModuleSubUVBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleSubUVSelect : public ParticleModuleSubUVBase
	{
	public:
		ADD_STRUCT(DistributionVector__RawDistributionVector, SubImageSelect, 72)
	};
}
#undef ADD_STRUCT
