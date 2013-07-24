#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTCTFSquadAI." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTCTFSquadAI." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTCTFSquadAI : public UTSquadAI
	{
	public:
		ADD_OBJECT(UTCTFFlag, EnemyFlag)
		ADD_OBJECT(UTCTFFlag, FriendlyFlag)
		ADD_OBJECT(NavigationPoint, HidePath)
		ADD_VAR(::FloatProperty, LastSeeFlagCarrier, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
