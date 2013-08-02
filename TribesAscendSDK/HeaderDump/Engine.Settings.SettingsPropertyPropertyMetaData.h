#pragma once
namespace UnrealScript
{
	struct Settings__SettingsPropertyPropertyMetaData;
}
#include "Engine.Settings.EPropertyValueMappingType.h"
#include "Engine.Settings.IdToStringMapping.h"
#include "Engine.Settings.SettingsData.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Settings__SettingsPropertyPropertyMetaData
	{
	public:
		ADD_STRUCT(int, Id, 0)
		ADD_STRUCT(ScriptName, Name, 4)
		ADD_STRUCT(ScriptString*, ColumnHeaderText, 12)
		ADD_STRUCT(Settings__EPropertyValueMappingType, MappingType, 24)
		ADD_STRUCT(ScriptArray<Settings__IdToStringMapping>, ValueMappings, 28)
		ADD_STRUCT(ScriptArray<Settings__SettingsData>, PredefinedValues, 40)
		ADD_STRUCT(float, MinVal, 52)
		ADD_STRUCT(float, MaxVal, 56)
		ADD_STRUCT(float, RangeIncrement, 60)
	};
}
#undef ADD_STRUCT
