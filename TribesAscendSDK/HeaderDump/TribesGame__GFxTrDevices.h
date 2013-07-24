#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrDevices." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.GFxTrDevices." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxTrDevices : public GFxObject
	{
	public:
		ADD_VAR(::BoolProperty, bNeedsUpdateData, 0x1)
		ADD_OBJECT(WorldInfo, ThisWorld)
		ADD_OBJECT(GFxMinimapHud, HUD)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
