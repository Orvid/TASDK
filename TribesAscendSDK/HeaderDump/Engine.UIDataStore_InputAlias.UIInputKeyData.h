#pragma once
namespace UnrealScript
{
	struct UIDataStore_InputAlias__UIInputKeyData;
}
#include "Engine.UIRoot.RawInputKeyEventData.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UIDataStore_InputAlias__UIInputKeyData
	{
	public:
		ADD_STRUCT(ScriptString*, ButtonFontMarkupString, 12)
		ADD_STRUCT(UIRoot__RawInputKeyEventData, InputKeyData, 0)
	};
}
#undef ADD_STRUCT
