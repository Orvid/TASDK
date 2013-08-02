#pragma once
namespace UnrealScript
{
	struct EngineTypes__LightmassPointLightSettings;
}
#include "Engine.EngineTypes.LightmassLightSettings.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct EngineTypes__LightmassPointLightSettings : public EngineTypes__LightmassLightSettings
	{
	public:
		ADD_STRUCT(float, LightSourceRadius, 12)
	};
}
#undef ADD_STRUCT
