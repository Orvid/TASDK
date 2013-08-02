#pragma once
namespace UnrealScript
{
	struct OnlinePlayerStorage__OnlineProfileSetting;
}
#include "Engine.OnlinePlayerStorage.EOnlineProfilePropertyOwner.h"
#include "Engine.Settings.SettingsProperty.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct OnlinePlayerStorage__OnlineProfileSetting
	{
	public:
		ADD_STRUCT(Settings__SettingsProperty, ProfileSetting, 4)
		ADD_STRUCT(OnlinePlayerStorage__EOnlineProfilePropertyOwner, Owner, 0)
	};
}
#undef ADD_STRUCT
