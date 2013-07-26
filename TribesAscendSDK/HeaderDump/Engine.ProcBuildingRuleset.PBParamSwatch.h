#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " ProcBuildingRuleset.PBParamSwatch." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PBParamSwatch
	{
	public:
		ADD_VAR(::NameProperty, SwatchName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR