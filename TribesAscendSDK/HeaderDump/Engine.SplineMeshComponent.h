#pragma once
#include "Engine.StaticMeshComponent.h"
#include "Engine.SplineMeshComponent.SplineMeshParams.h"
#include "Core.Object.Vector.h"
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
	class SplineMeshComponent : public StaticMeshComponent
	{
	public:
		ADD_BOOL(bSmoothInterpRollScale, 708, 0x1)
		ADD_STRUCT(Vector, SplineXDir, 696)
		ADD_STRUCT(SplineMeshComponent__SplineMeshParams, SplineParams, 608)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
