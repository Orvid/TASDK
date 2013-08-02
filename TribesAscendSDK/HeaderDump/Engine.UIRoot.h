#pragma once
namespace UnrealScript
{
	class UIRoot;
	class GameUISceneClient;
	class UIDataStore;
	class UIInteraction;
}
#include "Core.Object.h"
#include "Engine.LocalPlayer.h"
#include "Engine.UIRoot.EInputPlatformType.h"
#include "Engine.UIRoot.EUIDataProviderFieldType.h"
#include "Engine.UIRoot.InputEventParameters.h"
#include "Engine.UIRoot.InputKeyAction.h"
#include "Engine.UIRoot.RawInputKeyEventData.h"
#include "Engine.UIRoot.SubscribedInputEventParameters.h"
#include "Engine.UIRoot.TextureCoordinates.h"
#include "Engine.UIRoot.UIAxisEmulationDefinition.h"
#include "Engine.UIRoot.UIDataStoreBinding.h"
#include "Engine.UIRoot.UIProviderFieldValue.h"
#include "Engine.UIRoot.UIProviderScriptFieldValue.h"
#include "Engine.UIRoot.UIRangeData.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UIRoot : public Object
	{
	public:
		typedef UIRoot__EInputPlatformType EInputPlatformType;
		typedef UIRoot__EUIDataProviderFieldType EUIDataProviderFieldType;
		typedef UIRoot__UIRangeData UIRangeData;
		typedef UIRoot__TextureCoordinates TextureCoordinates;
		typedef UIRoot__UIProviderScriptFieldValue UIProviderScriptFieldValue;
		typedef UIRoot__UIProviderFieldValue UIProviderFieldValue;
		typedef UIRoot__InputKeyAction InputKeyAction;
		typedef UIRoot__UIDataStoreBinding UIDataStoreBinding;
		typedef UIRoot__InputEventParameters InputEventParameters;
		typedef UIRoot__SubscribedInputEventParameters SubscribedInputEventParameters;
		typedef UIRoot__UIAxisEmulationDefinition UIAxisEmulationDefinition;
		typedef UIRoot__RawInputKeyEventData RawInputKeyEventData;
		static const auto DEFAULT_SIZE_X = 1024;
		static const auto DEFAULT_SIZE_Y = 768;
		static const auto MAX_SUPPORTED_GAMEPADS = 4;
		bool GetDataStoreStringValue(ScriptString* InDataStoreMarkup, ScriptString*& OutStringValue, class LocalPlayer* OwnerPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9285);
			byte params[32] = { NULL };
			*(ScriptString**)params = InDataStoreMarkup;
			*(ScriptString**)&params[12] = OutStringValue;
			*(class LocalPlayer**)&params[24] = OwnerPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutStringValue = *(ScriptString**)&params[12];
			return *(bool*)&params[28];
		}
		bool SetDataStoreStringValue(ScriptString* InDataStoreMarkup, ScriptString* InStringValue, class LocalPlayer* OwnerPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9287);
			byte params[32] = { NULL };
			*(ScriptString**)params = InDataStoreMarkup;
			*(ScriptString**)&params[12] = InStringValue;
			*(class LocalPlayer**)&params[24] = OwnerPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		UIRoot__EInputPlatformType GetInputPlatformType(class LocalPlayer* OwningPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12858);
			byte params[5] = { NULL };
			*(class LocalPlayer**)params = OwningPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(UIRoot__EInputPlatformType*)&params[4];
		}
		class UIInteraction* GetCurrentUIController()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12861);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UIInteraction**)params;
		}
		class GameUISceneClient* GetSceneClient()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12863);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GameUISceneClient**)params;
		}
		class UIDataStore* StaticResolveDataStore(ScriptName DataStoreTag, class LocalPlayer* InPlayerOwner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12865);
			byte params[16] = { NULL };
			*(ScriptName*)params = DataStoreTag;
			*(class LocalPlayer**)&params[8] = InPlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UIDataStore**)&params[12];
		}
		bool SetDataStoreFieldValue(ScriptString* InDataStoreMarkup, UIRoot__UIProviderFieldValue& InFieldValue, class LocalPlayer* OwnerPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12871);
			byte params[108] = { NULL };
			*(ScriptString**)params = InDataStoreMarkup;
			*(UIRoot__UIProviderFieldValue*)&params[12] = InFieldValue;
			*(class LocalPlayer**)&params[100] = OwnerPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InFieldValue = *(UIRoot__UIProviderFieldValue*)&params[12];
			return *(bool*)&params[104];
		}
		bool GetDataStoreFieldValue(ScriptString* InDataStoreMarkup, UIRoot__UIProviderFieldValue& OutFieldValue, class LocalPlayer* OwnerPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12880);
			byte params[108] = { NULL };
			*(ScriptString**)params = InDataStoreMarkup;
			*(UIRoot__UIProviderFieldValue*)&params[12] = OutFieldValue;
			*(class LocalPlayer**)&params[100] = OwnerPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutFieldValue = *(UIRoot__UIProviderFieldValue*)&params[12];
			return *(bool*)&params[104];
		}
		
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* GetOnlineGameInterface()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12890);
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)params;
		}
		
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* GetOnlinePlayerInterface()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12894);
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)params;
		}
		
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* GetOnlinePlayerInterfaceEx()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12898);
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
#include "Engine.GameUISceneClient.h"
#include "Engine.UIDataStore.h"
#include "Engine.UIInteraction.h"
