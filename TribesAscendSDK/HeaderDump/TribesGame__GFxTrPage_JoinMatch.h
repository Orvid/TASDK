#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_JoinMatch." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_JoinMatch : public GFxTrPage
	{
	public:
		ADD_VAR(::IntProperty, DollMesh, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, queueId, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
