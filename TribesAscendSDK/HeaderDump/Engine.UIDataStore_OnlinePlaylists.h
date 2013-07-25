#pragma once
#include "Engine.UIDataStore.h"
#include "Engine.UIResourceDataProvider.h"
#include "Engine.OnlinePlaylistProvider.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIDataStore_OnlinePlaylists." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIDataStore_OnlinePlaylists." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.UIDataStore_OnlinePlaylists." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UIDataStore_OnlinePlaylists : public UIDataStore
	{
	public:
		ADD_OBJECT(ScriptClass, ProviderClass)
		ADD_VAR(::StrProperty, ProviderClassName, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IUIListElementProvider'!
		int GetProviderCount(ScriptName ProviderTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlinePlaylists.GetProviderCount");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = ProviderTag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		bool GetResourceProviders(ScriptName ProviderTag, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& out_Providers)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlinePlaylists.GetResourceProviders");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = ProviderTag;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8) = out_Providers;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_Providers = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		bool GetResourceProviderFields(ScriptName ProviderTag, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& ProviderFieldTags)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlinePlaylists.GetResourceProviderFields");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = ProviderTag;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8) = ProviderFieldTags;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ProviderFieldTags = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		bool GetProviderFieldValue(ScriptName ProviderTag, ScriptName SearchField, int ProviderIndex, 
// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.UIProviderScriptFieldValue'!
void*& out_FieldValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlinePlaylists.GetProviderFieldValue");
			byte* params = (byte*)malloc(108);
			*(ScriptName*)params = ProviderTag;
			*(ScriptName*)(params + 8) = SearchField;
			*(int*)(params + 16) = ProviderIndex;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.UIProviderScriptFieldValue'!
void**)(params + 20) = out_FieldValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_FieldValue = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.UIProviderScriptFieldValue'!
void**)(params + 20);
			auto returnVal = *(bool*)(params + 104);
			free(params);
			return returnVal;
		}
		int FindProviderIndexByFieldValue(ScriptName ProviderTag, ScriptName SearchField, 
// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.UIProviderScriptFieldValue'!
void*& ValueToSearchFor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlinePlaylists.FindProviderIndexByFieldValue");
			byte* params = (byte*)malloc(104);
			*(ScriptName*)params = ProviderTag;
			*(ScriptName*)(params + 8) = SearchField;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.UIProviderScriptFieldValue'!
void**)(params + 16) = ValueToSearchFor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ValueToSearchFor = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.UIProviderScriptFieldValue'!
void**)(params + 16);
			auto returnVal = *(int*)(params + 100);
			free(params);
			return returnVal;
		}
		bool GetPlaylistProvider(ScriptName ProviderTag, int ProviderIndex, class UIResourceDataProvider*& out_Provider)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlinePlaylists.GetPlaylistProvider");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = ProviderTag;
			*(int*)(params + 8) = ProviderIndex;
			*(class UIResourceDataProvider**)(params + 12) = out_Provider;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_Provider = *(class UIResourceDataProvider**)(params + 12);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		class OnlinePlaylistProvider* GetOnlinePlaylistProvider(ScriptName ProviderTag, int PlaylistId, int& ProviderIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_OnlinePlaylists.GetOnlinePlaylistProvider");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = ProviderTag;
			*(int*)(params + 8) = PlaylistId;
			*(int*)(params + 12) = ProviderIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ProviderIndex = *(int*)(params + 12);
			auto returnVal = *(class OnlinePlaylistProvider**)(params + 16);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT