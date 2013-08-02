#pragma once
namespace UnrealScript
{
	class InteractiveFoliageComponent;
}
#include "Core.Object.Pointer.h"
#include "Engine.StaticMeshComponent.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class InteractiveFoliageComponent : public StaticMeshComponent
	{
	public:
		ADD_STRUCT(Object__Pointer, FoliageSceneProxy, 608)
	};
}
#undef ADD_STRUCT
