#pragma once
#include "Engine.UIDataProvider_Settings.h"
#include "Engine.OnlineGameSearch.h"
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
	struct UIDataStore_OnlineGameSearch__GameSearchCfg
	{
	public:
		ADD_STRUCT(ScriptArray<class UIDataProvider_Settings*>, SearchResults, 16)
		ADD_STRUCT(ScriptName, SearchName, 32)
		ADD_OBJECT(OnlineGameSearch, Search, 28)
		ADD_OBJECT(UIDataProvider_Settings, DesiredSettingsProvider, 12)
		ADD_OBJECT(ScriptClass, SearchResultsProviderClass, 8)
		ADD_OBJECT(ScriptClass, DefaultGameSettingsClass, 4)
		ADD_OBJECT(ScriptClass, GameSearchClass, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
