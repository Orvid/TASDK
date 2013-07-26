#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrSummaryHelper.MVPAward." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class MVPAward
	{
	public:
		ADD_VAR(::IntProperty, Value, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, AwardId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PlayerID, 0xFFFFFFFF)
	};
}
#undef ADD_VAR