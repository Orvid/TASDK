#pragma once
#include "Engine__Settings.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.OnlineGameSearch." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.OnlineGameSearch." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.OnlineGameSearch." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class OnlineGameSearch : public Settings
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineGameSearch.OverrideSkill' for the property named 'ManualSkillOverride'!
		ADD_VAR(::IntProperty, MaxSearchResults, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.LocalizedStringSetting' for the property named 'Query'!
		ADD_VAR(::BoolProperty, bIsLanQuery, 0x1)
		ADD_VAR(::BoolProperty, bUsesArbitration, 0x2)
		ADD_VAR(::BoolProperty, bIsSearchInProgress, 0x4)
		ADD_OBJECT(ScriptClass, GameSettingsClass)
		// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineGameSearch.OnlineGameSearchQuery' for the property named 'FilterQuery'!
		ADD_VAR(::StrProperty, AdditionalSearchCriteria, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PingBucketSize, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'SortSearchResults'
		// Here lies the not-yet-implemented method 'SetSkillOverride'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
