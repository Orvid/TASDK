#pragma once
namespace UnrealScript
{
	class LightmassPrimitiveSettingsObject;
}
#include "Core.Object.h"
#include "Engine.EngineTypes.LightmassPrimitiveSettings.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class LightmassPrimitiveSettingsObject : public Object
	{
	public:
		ADD_STRUCT(EngineTypes__LightmassPrimitiveSettings, LightmassSettings, 60)
	};
}
#undef ADD_STRUCT
