#pragma once
namespace UnrealScript
{
	struct EngineTypes__LightmassLightSettings;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct EngineTypes__LightmassLightSettings
	{
	public:
		ADD_STRUCT(float, ShadowExponent, 8)
		ADD_STRUCT(float, IndirectLightingSaturation, 4)
		ADD_STRUCT(float, IndirectLightingScale, 0)
	};
}
#undef ADD_STRUCT
