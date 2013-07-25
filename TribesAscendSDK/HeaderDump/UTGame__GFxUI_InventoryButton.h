#pragma once
#include "GFxUI__GFxClikWidget.h"
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GFxUI_InventoryButton." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxUI_InventoryButton." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxUI_InventoryButton : public GFxClikWidget
	{
	public:
		ADD_OBJECT(GFxObject, IconMC)
		ADD_VAR(::StrProperty, Content, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'SetContent'
		// Here lies the not-yet-implemented method 'SetIconMC'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
