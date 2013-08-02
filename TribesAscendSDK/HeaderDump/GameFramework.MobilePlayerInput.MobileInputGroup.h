#pragma once
namespace UnrealScript
{
	struct MobilePlayerInput__MobileInputGroup;
}
#include "GameFramework.MobileInputZone.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct MobilePlayerInput__MobileInputGroup
	{
	public:
		ADD_STRUCT(ScriptArray<class MobileInputZone*>, AssociatedZones, 12)
		ADD_STRUCT(ScriptString*, GroupName, 0)
	};
}
#undef ADD_STRUCT
