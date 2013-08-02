#pragma once
namespace UnrealScript
{
	class UIDataStore_DynamicResource;
}
#include "Core.Object.MultiMap_Mirror.h"
#include "Core.Object.Pointer.h"
#include "Engine.LocalPlayer.h"
#include "Engine.UIDataProvider_OnlineProfileSettings.h"
#include "Engine.UIDataStore.h"
#include "Engine.UIDataStore_DynamicResource.DynamicResourceProviderDefinition.h"
#include "Engine.UIDataStore_GameResource.h"
#include "Engine.UIResourceCombinationProvider.h"
#include "Engine.UIRoot.UIProviderScriptFieldValue.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UIDataStore_DynamicResource : public UIDataStore
	{
	public:
		typedef UIDataStore_DynamicResource__DynamicResourceProviderDefinition DynamicResourceProviderDefinition;
		ADD_STRUCT(ScriptArray<UIDataStore_DynamicResource__DynamicResourceProviderDefinition>, ResourceProviderDefinitions, 132)
		ADD_STRUCT(Object__MultiMap_Mirror, ResourceProviders, 144)
		ADD_OBJECT(UIDataStore_GameResource, GameResourceDataStore, 128)
		ADD_OBJECT(UIDataProvider_OnlineProfileSettings, ProfileProvider, 124)
		ADD_STRUCT(Object__Pointer, VfTable_IUIListElementProvider, 120)
		int FindProviderTypeIndex(ScriptName ProviderTag)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28471);
			byte params[12] = { NULL };
			*(ScriptName*)params = ProviderTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		ScriptName GenerateProviderAccessTag(int ProviderIndex, int InstanceIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28474);
			byte params[16] = { NULL };
			*(int*)params = ProviderIndex;
			*(int*)&params[4] = InstanceIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[8];
		}
		int GetProviderCount(ScriptName ProviderTag)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28478);
			byte params[12] = { NULL };
			*(ScriptName*)params = ProviderTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		bool GetResourceProviders(ScriptName ProviderTag, ScriptArray<class UIResourceCombinationProvider*>& out_Providers)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28481);
			byte params[24] = { NULL };
			*(ScriptName*)params = ProviderTag;
			*(ScriptArray<class UIResourceCombinationProvider*>*)&params[8] = out_Providers;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Providers = *(ScriptArray<class UIResourceCombinationProvider*>*)&params[8];
			return *(bool*)&params[20];
		}
		bool GetResourceProviderFields(ScriptName ProviderTag, ScriptArray<ScriptName>& ProviderFieldTags)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28486);
			byte params[24] = { NULL };
			*(ScriptName*)params = ProviderTag;
			*(ScriptArray<ScriptName>*)&params[8] = ProviderFieldTags;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ProviderFieldTags = *(ScriptArray<ScriptName>*)&params[8];
			return *(bool*)&params[20];
		}
		bool GetProviderFieldValue(ScriptName ProviderTag, ScriptName SearchField, int ProviderIndex, UIRoot__UIProviderScriptFieldValue& out_FieldValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28491);
			byte params[108] = { NULL };
			*(ScriptName*)params = ProviderTag;
			*(ScriptName*)&params[8] = SearchField;
			*(int*)&params[16] = ProviderIndex;
			*(UIRoot__UIProviderScriptFieldValue*)&params[20] = out_FieldValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_FieldValue = *(UIRoot__UIProviderScriptFieldValue*)&params[20];
			return *(bool*)&params[104];
		}
		int FindProviderIndexByFieldValue(ScriptName ProviderTag, ScriptName SearchField, UIRoot__UIProviderScriptFieldValue& ValueToSearchFor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28497);
			byte params[104] = { NULL };
			*(ScriptName*)params = ProviderTag;
			*(ScriptName*)&params[8] = SearchField;
			*(UIRoot__UIProviderScriptFieldValue*)&params[16] = ValueToSearchFor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ValueToSearchFor = *(UIRoot__UIProviderScriptFieldValue*)&params[16];
			return *(int*)&params[100];
		}
		void OnLoginChange(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28502);
			byte params[1] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Registered(class LocalPlayer* PlayerOwner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28504);
			byte params[4] = { NULL };
			*(class LocalPlayer**)params = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Unregistered(class LocalPlayer* PlayerOwner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28509);
			byte params[4] = { NULL };
			*(class LocalPlayer**)params = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
