#pragma once
#include "Engine.UIDataProvider.h"
#include "Engine.UIRoot.EUIDataProviderFieldType.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UIDataProvider__UIDataProviderField
	{
	public:
		ADD_STRUCT(ScriptArray<class UIDataProvider*>, FieldProviders, 12)
		ADD_STRUCT(UIRoot__EUIDataProviderFieldType, FieldType, 8)
		ADD_STRUCT(ScriptName, FieldTag, 0)
	};
}
#undef ADD_STRUCT
