#pragma once
namespace UnrealScript
{
	struct UTDataStore_GameSearchDM__GameSearchSettingsStorage;
}
#include "UTGame.UTDataStore_GameSearchDM.PersistentLocalizedSettingValue.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UTDataStore_GameSearchDM__GameSearchSettingsStorage
	{
	public:
		ADD_STRUCT(ScriptArray<UTDataStore_GameSearchDM__PersistentLocalizedSettingValue>, StoredValues, 8)
		ADD_STRUCT(ScriptName, GameSearchName, 0)
	};
}
#undef ADD_STRUCT
