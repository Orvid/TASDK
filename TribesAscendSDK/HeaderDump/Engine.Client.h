#pragma once
#include "Core.Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Client." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Client : public Object
	{
	public:
		ADD_VAR(::FloatProperty, DisplayGamma, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinDesiredFrameRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InitialButtonRepeatDelay, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ButtonRepeatDelay, 0xFFFFFFFF)
	};
}
#undef ADD_VAR