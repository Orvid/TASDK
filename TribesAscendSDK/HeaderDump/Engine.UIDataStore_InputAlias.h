#pragma once
namespace UnrealScript
{
	class UIDataStore_InputAlias;
}
#include "Engine.UIDataStore_InputAlias.UIDataStoreInputAlias.h"
#include "Engine.UIDataStore_InputAlias.UIInputKeyData.h"
#include "Engine.UIDataStore_StringBase.h"
#include "Engine.UIRoot.EInputPlatformType.h"
#include "Engine.UIRoot.RawInputKeyEventData.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UIDataStore_InputAlias : public UIDataStore_StringBase
	{
	public:
		typedef UIDataStore_InputAlias__UIDataStoreInputAlias UIDataStoreInputAlias;
		typedef UIDataStore_InputAlias__UIInputKeyData UIInputKeyData;
		ADD_STRUCT(ScriptArray<UIDataStore_InputAlias__UIDataStoreInputAlias>, InputAliases, 120)
		ScriptString* GetAliasFontMarkup(ScriptName DesiredAlias, UIRoot__EInputPlatformType OverridePlatform)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28570);
			byte params[21] = { NULL };
			*(ScriptName*)params = DesiredAlias;
			*(UIRoot__EInputPlatformType*)&params[8] = OverridePlatform;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		ScriptString* GetAliasFontMarkupByIndex(int AliasIndex, UIRoot__EInputPlatformType OverridePlatform)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28574);
			byte params[17] = { NULL };
			*(int*)params = AliasIndex;
			*(UIRoot__EInputPlatformType*)&params[4] = OverridePlatform;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[8];
		}
		ScriptName GetAliasInputKeyName(ScriptName DesiredAlias, UIRoot__EInputPlatformType OverridePlatform)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28578);
			byte params[17] = { NULL };
			*(ScriptName*)params = DesiredAlias;
			*(UIRoot__EInputPlatformType*)&params[8] = OverridePlatform;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[12];
		}
		ScriptName GetAliasInputKeyNameByIndex(int AliasIndex, UIRoot__EInputPlatformType OverridePlatform)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28582);
			byte params[13] = { NULL };
			*(int*)params = AliasIndex;
			*(UIRoot__EInputPlatformType*)&params[4] = OverridePlatform;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[8];
		}
		bool GetAliasInputKeyData(UIRoot__RawInputKeyEventData& out_InputKeyData, ScriptName DesiredAlias, UIRoot__EInputPlatformType OverridePlatform)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28586);
			byte params[25] = { NULL };
			*(UIRoot__RawInputKeyEventData*)params = out_InputKeyData;
			*(ScriptName*)&params[12] = DesiredAlias;
			*(UIRoot__EInputPlatformType*)&params[20] = OverridePlatform;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_InputKeyData = *(UIRoot__RawInputKeyEventData*)params;
			return *(bool*)&params[24];
		}
		bool GetAliasInputKeyDataByIndex(UIRoot__RawInputKeyEventData& out_InputKeyData, int AliasIndex, UIRoot__EInputPlatformType OverridePlatform)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28591);
			byte params[21] = { NULL };
			*(UIRoot__RawInputKeyEventData*)params = out_InputKeyData;
			*(int*)&params[12] = AliasIndex;
			*(UIRoot__EInputPlatformType*)&params[16] = OverridePlatform;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_InputKeyData = *(UIRoot__RawInputKeyEventData*)params;
			return *(bool*)&params[20];
		}
		int FindInputAliasIndex(ScriptName DesiredAlias)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28596);
			byte params[12] = { NULL };
			*(ScriptName*)params = DesiredAlias;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		bool HasAliasMappingForPlatform(ScriptName DesiredAlias, UIRoot__EInputPlatformType DesiredPlatform)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28599);
			byte params[13] = { NULL };
			*(ScriptName*)params = DesiredAlias;
			*(UIRoot__EInputPlatformType*)&params[8] = DesiredPlatform;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
	};
}
#undef ADD_STRUCT
