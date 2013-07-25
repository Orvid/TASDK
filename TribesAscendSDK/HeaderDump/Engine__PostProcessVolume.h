#pragma once
#include "Engine__Volume.h"
#include "Engine__SeqAct_Toggle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PostProcessVolume." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.PostProcessVolume." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.PostProcessVolume." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PostProcessVolume : public Volume
	{
	public:
		ADD_VAR(::BoolProperty, bEnabled, 0x1)
		ADD_OBJECT(PostProcessVolume, NextLowerPriorityVolume)
		// WARNING: Unknown structure type 'ScriptStruct Engine.PostProcessVolume.PostProcessSettings' for the property named 'Settings'!
		ADD_VAR(::FloatProperty, Priority, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'OnToggle'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
