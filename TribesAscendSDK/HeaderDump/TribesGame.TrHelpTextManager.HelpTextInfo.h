#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrHelpTextManager.HelpTextInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class HelpTextInfo
	{
	public:
		ADD_VAR(::BoolProperty, bSelfSuppress, 0x1)
		ADD_VAR(::IntProperty, Priority, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, HelpTextType, 0xFFFFFFFF)
	};
}
#undef ADD_VAR