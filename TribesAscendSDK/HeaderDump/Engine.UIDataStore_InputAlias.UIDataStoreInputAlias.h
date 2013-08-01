#pragma once
#include "Engine.UIDataStore_InputAlias.UIInputKeyData.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UIDataStore_InputAlias__UIDataStoreInputAlias
	{
	public:
		ADD_STRUCT(UIDataStore_InputAlias__UIInputKeyData, PlatformInputKeys, 8)
		ADD_STRUCT(ScriptName, AliasName, 0)
	};
}
#undef ADD_STRUCT
