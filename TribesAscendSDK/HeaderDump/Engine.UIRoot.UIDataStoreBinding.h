#pragma once
#include "Engine.UIDataStore.h"
#include "Engine.UIRoot.EUIDataProviderFieldType.h"
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
	struct UIRoot__UIDataStoreBinding
	{
	public:
		ADD_OBJECT(UIDataStore, ResolvedDataStore, 44)
		ADD_STRUCT(ScriptName, DataStoreField, 36)
		ADD_STRUCT(ScriptName, DataStoreName, 28)
		ADD_STRUCT(int, BindingIndex, 24)
		ADD_STRUCT(ScriptString*, MarkupString, 12)
		ADD_STRUCT(UIRoot__EUIDataProviderFieldType, RequiredFieldType, 8)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
