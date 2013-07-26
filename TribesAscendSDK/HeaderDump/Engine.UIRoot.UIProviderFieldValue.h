#pragma once
#include "Engine.UIRoot.UIProviderScriptFieldValue.h"
#include "Core.Object.Pointer.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UIRoot.UIProviderFieldValue." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIProviderFieldValue : public UIProviderScriptFieldValue
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, CustomStringNode, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT