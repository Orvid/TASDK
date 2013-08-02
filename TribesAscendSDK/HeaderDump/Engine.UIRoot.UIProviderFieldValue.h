#pragma once
namespace UnrealScript
{
	struct UIRoot__UIProviderFieldValue;
}
#include "Core.Object.Pointer.h"
#include "Engine.UIRoot.UIProviderScriptFieldValue.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UIRoot__UIProviderFieldValue : public UIRoot__UIProviderScriptFieldValue
	{
	public:
		ADD_STRUCT(Object__Pointer, CustomStringNode, 84)
	};
}
#undef ADD_STRUCT
