#pragma once
#include "Core.Object.h"
#include "Engine.PlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Player." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Player." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Player." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Player : public Object
	{
	public:
		ADD_VAR(::IntProperty, CurrentNetSpeed, 0xFFFFFFFF)
		ADD_OBJECT(PlayerController, Actor)
		ADD_VAR(::FloatProperty, PP_ShadowsMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PP_MidTonesMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PP_HighlightsMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PP_DesaturationMultiplier, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ConfiguredLanSpeed, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ConfiguredInternetSpeed, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_FExec'!
		void SwitchController(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Player.SwitchController");
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT