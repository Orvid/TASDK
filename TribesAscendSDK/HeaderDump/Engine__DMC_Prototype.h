#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DMC_Prototype." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DMC_Prototype : public K2GraphBase
	{
	public:
		ADD_VAR(::StrProperty, DefaultPropText, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FunctionCode, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
