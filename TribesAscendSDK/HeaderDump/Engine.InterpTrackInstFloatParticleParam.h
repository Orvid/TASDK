#pragma once
namespace UnrealScript
{
	class InterpTrackInstFloatParticleParam;
}
#include "Engine.InterpTrackInst.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class InterpTrackInstFloatParticleParam : public InterpTrackInst
	{
	public:
		ADD_STRUCT(float, ResetFloat, 60)
	};
}
#undef ADD_STRUCT
