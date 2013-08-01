#pragma once
#include "Engine.UIRoot.InputEventParameters.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UIRoot__SubscribedInputEventParameters : public UIRoot__InputEventParameters
	{
	public:
		ADD_STRUCT(ScriptName, InputAliasName, 32)
	};
}
#undef ADD_STRUCT
