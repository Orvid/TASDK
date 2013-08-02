#pragma once
namespace UnrealScript
{
	struct UIDataStore_OnlineGameSettings__GameSettingsCfg;
}
#include "Engine.OnlineGameSettings.h"
#include "Engine.UIDataProvider_Settings.h"
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
	struct UIDataStore_OnlineGameSettings__GameSettingsCfg
	{
	public:
		ADD_STRUCT(ScriptName, SettingsName, 12)
		ADD_OBJECT(OnlineGameSettings, GameSettings, 8)
		ADD_OBJECT(UIDataProvider_Settings, Provider, 4)
		ADD_OBJECT(ScriptClass, GameSettingsClass, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
