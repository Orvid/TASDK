#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " PBRuleNodeSplit.RBSplitInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class RBSplitInfo
	{
	public:
		ADD_VAR(::NameProperty, SplitName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExpandRatio, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FixedSize, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bFixSize, 0x1)
	};
}
#undef ADD_VAR