#pragma once
namespace UnrealScript
{
	struct SpeedTreeComponent__SpeedTreeStaticLight;
}
#include "Core.Object.Guid.h"
#include "Engine.ShadowMap1D.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct SpeedTreeComponent__SpeedTreeStaticLight
	{
	public:
		ADD_OBJECT(ShadowMap1D, BillboardShadowMap, 32)
		ADD_OBJECT(ShadowMap1D, LeafCardShadowMap, 28)
		ADD_OBJECT(ShadowMap1D, LeafMeshShadowMap, 24)
		ADD_OBJECT(ShadowMap1D, FrondShadowMap, 20)
		ADD_OBJECT(ShadowMap1D, BranchShadowMap, 16)
		ADD_STRUCT(Object__Guid, Guid, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
