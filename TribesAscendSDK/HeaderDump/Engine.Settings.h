#pragma once
#include "Engine.Settings.ESettingsDataType.h"
#include "Engine.Settings.LocalizedStringSettingMetaData.h"
#include "Core.Object.h"
#include "Engine.Settings.IdToStringMapping.h"
#include "Engine.GameInfo.h"
#include "Engine.Settings.LocalizedStringSetting.h"
#include "Engine.Settings.SettingsProperty.h"
#include "Engine.Settings.SettingsPropertyPropertyMetaData.h"
#include "Engine.Settings.EPropertyValueMappingType.h"
#include "Engine.Settings.SettingsData.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class Settings : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<Settings__LocalizedStringSetting>, LocalizedSettings, 60)
		ADD_STRUCT(ScriptArray<Settings__SettingsProperty>, Properties, 72)
		ADD_STRUCT(ScriptArray<Settings__LocalizedStringSettingMetaData>, LocalizedSettingsMappings, 84)
		ADD_STRUCT(ScriptArray<Settings__SettingsPropertyPropertyMetaData>, PropertyMappings, 96)
		void UpdateFromURL(ScriptString*& URL, class GameInfo* Game)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5197);
			byte params[16] = { NULL };
			*(ScriptString**)params = URL;
			*(class GameInfo**)&params[12] = Game;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			URL = *(ScriptString**)params;
		}
		void BuildURL(ScriptString*& URL)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5198);
			byte params[12] = { NULL };
			*(ScriptString**)params = URL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			URL = *(ScriptString**)params;
		}
		void AppendContextsToURL(ScriptString*& URL)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5201);
			byte params[12] = { NULL };
			*(ScriptString**)params = URL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			URL = *(ScriptString**)params;
		}
		void AppendPropertiesToURL(ScriptString*& URL)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5203);
			byte params[12] = { NULL };
			*(ScriptString**)params = URL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			URL = *(ScriptString**)params;
		}
		void AppendDataBindingsToURL(ScriptString*& URL)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5205);
			byte params[12] = { NULL };
			*(ScriptString**)params = URL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			URL = *(ScriptString**)params;
		}
		void GetQoSAdvertisedStringSettings(ScriptArray<Settings__LocalizedStringSetting>& QoSSettings)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5207);
			byte params[12] = { NULL };
			*(ScriptArray<Settings__LocalizedStringSetting>*)params = QoSSettings;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			QoSSettings = *(ScriptArray<Settings__LocalizedStringSetting>*)params;
		}
		void GetQoSAdvertisedProperties(ScriptArray<Settings__SettingsProperty>& QoSProps)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5209);
			byte params[12] = { NULL };
			*(ScriptArray<Settings__SettingsProperty>*)params = QoSProps;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			QoSProps = *(ScriptArray<Settings__SettingsProperty>*)params;
		}
		bool GetRangedPropertyValue(int PropertyId, float& OutValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5217);
			byte params[12] = { NULL };
			*(int*)params = PropertyId;
			*(float*)&params[4] = OutValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutValue = *(float*)&params[4];
			return *(bool*)&params[8];
		}
		bool SetRangedPropertyValue(int PropertyId, float NewValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5229);
			byte params[12] = { NULL };
			*(int*)params = PropertyId;
			*(float*)&params[4] = NewValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool GetPropertyRange(int PropertyId, float& OutMinValue, float& OutMaxValue, float& RangeIncrement, byte& bFormatAsInt)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5233);
			byte params[21] = { NULL };
			*(int*)params = PropertyId;
			*(float*)&params[4] = OutMinValue;
			*(float*)&params[8] = OutMaxValue;
			*(float*)&params[12] = RangeIncrement;
			params[16] = bFormatAsInt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutMinValue = *(float*)&params[4];
			OutMaxValue = *(float*)&params[8];
			RangeIncrement = *(float*)&params[12];
			bFormatAsInt = params[16];
			return *(bool*)&params[20];
		}
		bool GetPropertyMappingType(int PropertyId, Settings__EPropertyValueMappingType& OutType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5237);
			byte params[9] = { NULL };
			*(int*)params = PropertyId;
			*(Settings__EPropertyValueMappingType*)&params[4] = OutType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutType = *(Settings__EPropertyValueMappingType*)&params[4];
			return *(bool*)&params[8];
		}
		bool HasStringSetting(int SettingId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5244);
			byte params[8] = { NULL };
			*(int*)params = SettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool HasProperty(int PropertyId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5250);
			byte params[8] = { NULL };
			*(int*)params = PropertyId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void UpdateProperties(ScriptArray<Settings__SettingsProperty>& Props, bool bShouldAddIfMissing)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5253);
			byte params[16] = { NULL };
			*(ScriptArray<Settings__SettingsProperty>*)params = Props;
			*(bool*)&params[12] = bShouldAddIfMissing;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Props = *(ScriptArray<Settings__SettingsProperty>*)params;
		}
		void UpdateStringSettings(ScriptArray<Settings__LocalizedStringSetting>& Settings, bool bShouldAddIfMissing)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5256);
			byte params[16] = { NULL };
			*(ScriptArray<Settings__LocalizedStringSetting>*)params = Settings;
			*(bool*)&params[12] = bShouldAddIfMissing;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Settings = *(ScriptArray<Settings__LocalizedStringSetting>*)params;
		}
		Settings__ESettingsDataType GetPropertyType(int PropertyId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5260);
			byte params[5] = { NULL };
			*(int*)params = PropertyId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Settings__ESettingsDataType*)&params[4];
		}
		bool GetPropertyValueId(int PropertyId, int& ValueId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5264);
			byte params[12] = { NULL };
			*(int*)params = PropertyId;
			*(int*)&params[4] = ValueId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ValueId = *(int*)&params[4];
			return *(bool*)&params[8];
		}
		bool SetPropertyValueId(int PropertyId, int ValueId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5267);
			byte params[12] = { NULL };
			*(int*)params = PropertyId;
			*(int*)&params[4] = ValueId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool GetStringProperty(int PropertyId, ScriptString*& Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5271);
			byte params[20] = { NULL };
			*(int*)params = PropertyId;
			*(ScriptString**)&params[4] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Value = *(ScriptString**)&params[4];
			return *(bool*)&params[16];
		}
		void SetStringProperty(int PropertyId, ScriptString* Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5275);
			byte params[16] = { NULL };
			*(int*)params = PropertyId;
			*(ScriptString**)&params[4] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetIntProperty(int PropertyId, int& Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5279);
			byte params[12] = { NULL };
			*(int*)params = PropertyId;
			*(int*)&params[4] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Value = *(int*)&params[4];
			return *(bool*)&params[8];
		}
		void SetIntProperty(int PropertyId, int Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5282);
			byte params[8] = { NULL };
			*(int*)params = PropertyId;
			*(int*)&params[4] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetFloatProperty(int PropertyId, float& Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5286);
			byte params[12] = { NULL };
			*(int*)params = PropertyId;
			*(float*)&params[4] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Value = *(float*)&params[4];
			return *(bool*)&params[8];
		}
		void SetFloatProperty(int PropertyId, float Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5289);
			byte params[8] = { NULL };
			*(int*)params = PropertyId;
			*(float*)&params[4] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SetPropertyFromStringByName(ScriptName PropertyName, ScriptString*& NewValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5293);
			byte params[24] = { NULL };
			*(ScriptName*)params = PropertyName;
			*(ScriptString**)&params[8] = NewValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			NewValue = *(ScriptString**)&params[8];
			return *(bool*)&params[20];
		}
		ScriptString* GetPropertyAsStringByName(ScriptName PropertyName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5296);
			byte params[20] = { NULL };
			*(ScriptName*)params = PropertyName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[8];
		}
		ScriptString* GetPropertyAsString(int PropertyId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5300);
			byte params[16] = { NULL };
			*(int*)params = PropertyId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptString* GetPropertyColumnHeader(int PropertyId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5303);
			byte params[16] = { NULL };
			*(int*)params = PropertyId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptName GetPropertyName(int PropertyId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5306);
			byte params[12] = { NULL };
			*(int*)params = PropertyId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[4];
		}
		bool GetPropertyId(ScriptName PropertyName, int& PropertyId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5309);
			byte params[16] = { NULL };
			*(ScriptName*)params = PropertyName;
			*(int*)&params[8] = PropertyId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PropertyId = *(int*)&params[8];
			return *(bool*)&params[12];
		}
		bool SetStringSettingValueFromStringByName(ScriptName StringSettingName, ScriptString*& NewValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5312);
			byte params[24] = { NULL };
			*(ScriptName*)params = StringSettingName;
			*(ScriptString**)&params[8] = NewValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			NewValue = *(ScriptString**)&params[8];
			return *(bool*)&params[20];
		}
		ScriptName GetStringSettingValueNameByName(ScriptName StringSettingName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5316);
			byte params[16] = { NULL };
			*(ScriptName*)params = StringSettingName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[8];
		}
		ScriptName GetStringSettingValueName(int StringSettingId, int ValueIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5320);
			byte params[16] = { NULL };
			*(int*)params = StringSettingId;
			*(int*)&params[4] = ValueIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[8];
		}
		bool IsWildcardStringSetting(int StringSettingId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5323);
			byte params[8] = { NULL };
			*(int*)params = StringSettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		ScriptString* GetStringSettingColumnHeader(int StringSettingId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5327);
			byte params[16] = { NULL };
			*(int*)params = StringSettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptName GetStringSettingName(int StringSettingId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5330);
			byte params[12] = { NULL };
			*(int*)params = StringSettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[4];
		}
		bool GetStringSettingId(ScriptName StringSettingName, int& StringSettingId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5333);
			byte params[16] = { NULL };
			*(ScriptName*)params = StringSettingName;
			*(int*)&params[8] = StringSettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			StringSettingId = *(int*)&params[8];
			return *(bool*)&params[12];
		}
		bool GetStringSettingValueByName(ScriptName StringSettingName, int& ValueIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5336);
			byte params[16] = { NULL };
			*(ScriptName*)params = StringSettingName;
			*(int*)&params[8] = ValueIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ValueIndex = *(int*)&params[8];
			return *(bool*)&params[12];
		}
		void SetStringSettingValueByName(ScriptName StringSettingName, int ValueIndex, bool bShouldAutoAdd)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5340);
			byte params[16] = { NULL };
			*(ScriptName*)params = StringSettingName;
			*(int*)&params[8] = ValueIndex;
			*(bool*)&params[12] = bShouldAutoAdd;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetStringSettingValueNames(int StringSettingId, ScriptArray<Settings__IdToStringMapping>& Values)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5344);
			byte params[20] = { NULL };
			*(int*)params = StringSettingId;
			*(ScriptArray<Settings__IdToStringMapping>*)&params[4] = Values;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Values = *(ScriptArray<Settings__IdToStringMapping>*)&params[4];
			return *(bool*)&params[16];
		}
		bool IncrementStringSettingValue(int StringSettingId, int Direction, bool bShouldWrap)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5348);
			byte params[16] = { NULL };
			*(int*)params = StringSettingId;
			*(int*)&params[4] = Direction;
			*(bool*)&params[8] = bShouldWrap;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool GetStringSettingValue(int StringSettingId, int& ValueIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5356);
			byte params[12] = { NULL };
			*(int*)params = StringSettingId;
			*(int*)&params[4] = ValueIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ValueIndex = *(int*)&params[4];
			return *(bool*)&params[8];
		}
		void SetStringSettingValue(int StringSettingId, int ValueIndex, bool bShouldAutoAdd)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5361);
			byte params[12] = { NULL };
			*(int*)params = StringSettingId;
			*(int*)&params[4] = ValueIndex;
			*(bool*)&params[8] = bShouldAutoAdd;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetSettingsDataDateTime(Settings__SettingsData& Data, int& OutInt1, int& OutInt2)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5365);
			byte params[20] = { NULL };
			*(Settings__SettingsData*)params = Data;
			*(int*)&params[12] = OutInt1;
			*(int*)&params[16] = OutInt2;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Data = *(Settings__SettingsData*)params;
			OutInt1 = *(int*)&params[12];
			OutInt2 = *(int*)&params[16];
		}
		void GetSettingsDataBlob(Settings__SettingsData& Data, ScriptArray<byte>& OutBlob)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5369);
			byte params[24] = { NULL };
			*(Settings__SettingsData*)params = Data;
			*(ScriptArray<byte>*)&params[12] = OutBlob;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Data = *(Settings__SettingsData*)params;
			OutBlob = *(ScriptArray<byte>*)&params[12];
		}
		int GetSettingsDataInt(Settings__SettingsData& Data)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5373);
			byte params[16] = { NULL };
			*(Settings__SettingsData*)params = Data;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Data = *(Settings__SettingsData*)params;
			return *(int*)&params[12];
		}
		float GetSettingsDataFloat(Settings__SettingsData& Data)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5377);
			byte params[16] = { NULL };
			*(Settings__SettingsData*)params = Data;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Data = *(Settings__SettingsData*)params;
			return *(float*)&params[12];
		}
		ScriptString* GetSettingsDataString(Settings__SettingsData& Data)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5380);
			byte params[24] = { NULL };
			*(Settings__SettingsData*)params = Data;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Data = *(Settings__SettingsData*)params;
			return *(ScriptString**)&params[12];
		}
		void EmptySettingsData(Settings__SettingsData& Data)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5383);
			byte params[12] = { NULL };
			*(Settings__SettingsData*)params = Data;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Data = *(Settings__SettingsData*)params;
		}
		void SetSettingsData(Settings__SettingsData& Data, Settings__SettingsData& Data2Copy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5386);
			byte params[24] = { NULL };
			*(Settings__SettingsData*)params = Data;
			*(Settings__SettingsData*)&params[12] = Data2Copy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Data = *(Settings__SettingsData*)params;
			Data2Copy = *(Settings__SettingsData*)&params[12];
		}
		void SetSettingsDataBlob(Settings__SettingsData& Data, ScriptArray<byte>& InBlob)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5388);
			byte params[24] = { NULL };
			*(Settings__SettingsData*)params = Data;
			*(ScriptArray<byte>*)&params[12] = InBlob;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Data = *(Settings__SettingsData*)params;
			InBlob = *(ScriptArray<byte>*)&params[12];
		}
		void SetSettingsDataDateTime(Settings__SettingsData& Data, int InInt1, int InInt2)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5391);
			byte params[20] = { NULL };
			*(Settings__SettingsData*)params = Data;
			*(int*)&params[12] = InInt1;
			*(int*)&params[16] = InInt2;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Data = *(Settings__SettingsData*)params;
		}
		void SetSettingsDataInt(Settings__SettingsData& Data, int InInt)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5395);
			byte params[16] = { NULL };
			*(Settings__SettingsData*)params = Data;
			*(int*)&params[12] = InInt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Data = *(Settings__SettingsData*)params;
		}
		void SetSettingsDataFloat(Settings__SettingsData& Data, float InFloat)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5399);
			byte params[16] = { NULL };
			*(Settings__SettingsData*)params = Data;
			*(float*)&params[12] = InFloat;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Data = *(Settings__SettingsData*)params;
		}
		void SetSettingsDataString(Settings__SettingsData& Data, ScriptString* InString)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5402);
			byte params[24] = { NULL };
			*(Settings__SettingsData*)params = Data;
			*(ScriptString**)&params[12] = InString;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Data = *(Settings__SettingsData*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
