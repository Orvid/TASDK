#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GFxUDKFrontEnd_Mutators." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxUDKFrontEnd_Mutators." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxUDKFrontEnd_Mutators : public GFxUDKFrontEnd_Screen
	{
	public:
		ADD_VAR(::BoolProperty, bFirstUpdateAfterActivation, 0x1)
		ADD_OBJECT(GFxObject, ConfigListDataProvider)
		ADD_OBJECT(GFxClikWidget, ConfigListMC)
		ADD_OBJECT(GFxObject, ListDataProvider)
		ADD_OBJECT(GFxObject, MenuMC)
		ADD_OBJECT(GFxClikWidget, ListMC)
		ADD_OBJECT(UTUIDataStore_MenuItems, MenuDataStore)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
