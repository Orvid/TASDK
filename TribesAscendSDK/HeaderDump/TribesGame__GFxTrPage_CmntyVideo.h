#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_CmntyVideo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_CmntyVideo : public GFxTrPage
	{
	public:
		ADD_VAR(::BoolProperty, bValid, 0x1)
	};
}
#undef ADD_VAR
