#pragma once
namespace UnrealScript
{
	class NxForceFieldRadialComponent;
}
#include "Core.Object.Pointer.h"
#include "Engine.NxForceFieldComponent.h"
#include "Engine.PrimitiveComponent.ERadialImpulseFalloff.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class NxForceFieldRadialComponent : public NxForceFieldComponent
	{
	public:
		ADD_STRUCT(Object__Pointer, Kernel, 584)
		ADD_STRUCT(PrimitiveComponent__ERadialImpulseFalloff, ForceFalloff, 580)
		ADD_STRUCT(float, SelfRotationStrength, 576)
		ADD_STRUCT(float, ForceRadius, 572)
		ADD_STRUCT(float, ForceStrength, 568)
	};
}
#undef ADD_STRUCT
