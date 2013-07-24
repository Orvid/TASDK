#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIDataProvider_OnlinePlayerDataBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIDataProvider_OnlinePlayerDataBase : public UIDataProvider
	{
	public:
		ADD_VAR(::IntProperty, PlayerControllerId, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
