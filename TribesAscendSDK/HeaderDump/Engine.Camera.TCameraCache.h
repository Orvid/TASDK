#pragma once
#include "Core.Object.TPOV.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Camera.TCameraCache." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Camera.TCameraCache." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TCameraCache
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<TPOV>, POV, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TimeStamp, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT