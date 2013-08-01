#pragma once
#include "Core.Object.Color.h"
#include "Engine.LightComponent.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SkyLightComponent : public LightComponent
	{
	public:
		ADD_STRUCT(Object__Color, LowerColor, 436)
		ADD_STRUCT(float, LowerBrightness, 432)
	};
}
#undef ADD_STRUCT
