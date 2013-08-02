#pragma once
namespace UnrealScript
{
	class DominantDirectionalLightComponent;
}
#include "Core.Object.Array_Mirror.h"
#include "Engine.DirectionalLightComponent.h"
#include "Engine.EngineTypes.DominantShadowInfo.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class DominantDirectionalLightComponent : public DirectionalLightComponent
	{
	public:
		ADD_STRUCT(Object__Array_Mirror, DominantLightShadowMap, 640)
		ADD_STRUCT(EngineTypes__DominantShadowInfo, DominantLightShadowInfo, 464)
	};
}
#undef ADD_STRUCT
