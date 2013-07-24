#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_VideoTexture." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_VideoTexture : public GFxTrPage
	{
	public:
		ADD_VAR(::IntProperty, CurrGraphics, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SettingIndex, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
