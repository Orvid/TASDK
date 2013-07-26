#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GameMapCycle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GameMapCycle
	{
	public:
		ADD_VAR(::NameProperty, GameClassName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR