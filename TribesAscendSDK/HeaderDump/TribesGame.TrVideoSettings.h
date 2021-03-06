#pragma once
namespace UnrealScript
{
	class TrVideoSettings;
}
#include "GFxUI.GFxObject.h"
#include "PlatformCommon.TgPlayerProfile.PropertyPair.h"
#include "TribesGame.TrVideoSettings.EAntiAliasing.h"
#include "TribesGame.TrVideoSettings.EScreenFrameType.h"
#include "TribesGame.TrVideoSettings.EVideoSettingType.h"
#include "TribesGame.TrVideoSettings.EVisualDetail.h"
#include "TribesGame.TrVideoSettings.ResolutionData.h"
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
	class TrVideoSettings : public GFxObject
	{
	public:
		typedef TrVideoSettings__EVideoSettingType EVideoSettingType;
		typedef TrVideoSettings__EScreenFrameType EScreenFrameType;
		typedef TrVideoSettings__EAntiAliasing EAntiAliasing;
		typedef TrVideoSettings__EVisualDetail EVisualDetail;
		typedef TrVideoSettings__ResolutionData ResolutionData;
		ADD_STRUCT(int, m_Cached_Resolution, 156)
		ADD_STRUCT(int, m_VideoSettingsCount, 124)
		ADD_OBJECT(GFxObject, m_VideoSettingsList, 132)
		ADD_STRUCT(int, m_ResolutionCount, 120)
		ADD_OBJECT(GFxObject, m_ResolutionList, 128)
		ADD_STRUCT(int, m_Cached_ShadowDetail, 136)
		ADD_STRUCT(int, m_Cached_TextureDetail, 140)
		ADD_STRUCT(int, m_Cached_ScreenType, 144)
		ADD_STRUCT(int, m_Cached_MotionBlur, 148)
		ADD_STRUCT(int, m_Cached_VerticalSync, 152)
		ADD_STRUCT(int, m_Cached_SmoothFramerate, 160)
		int GetCurrentSettingValue(TrVideoSettings__EVideoSettingType Type)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61372);
			byte params[5] = { NULL };
			*(TrVideoSettings__EVideoSettingType*)params = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int GetSmoothFramerateValue()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61451);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void GetAllowedResolutions(ScriptArray<TrVideoSettings__ResolutionData>& ResolutionList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115534);
			byte params[12] = { NULL };
			*(ScriptArray<TrVideoSettings__ResolutionData>*)params = ResolutionList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ResolutionList = *(ScriptArray<TrVideoSettings__ResolutionData>*)params;
		}
		void ApplyVideoSettings()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115537);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ChangeScreenType(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115538);
			byte params[4] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ChangeResolution(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115540);
			byte params[4] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ChangeShadowDetail(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115542);
			byte params[4] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ChangeTextureDetail(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115544);
			byte params[4] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetResolutions(ScriptArray<TgPlayerProfile__PropertyPair>& ResolutionList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115546);
			byte params[12] = { NULL };
			*(ScriptArray<TgPlayerProfile__PropertyPair>*)params = ResolutionList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ResolutionList = *(ScriptArray<TgPlayerProfile__PropertyPair>*)params;
		}
		void SetVSync(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115549);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetMotionBlur(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115551);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoadVideoSettings(class GFxObject* List)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115553);
			byte params[4] = { NULL };
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddVideoSettingToList(ScriptString* SettingName, int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115560);
			byte params[16] = { NULL };
			*(ScriptString**)params = SettingName;
			*(int*)&params[12] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoadVideoResolutions(class GFxObject* List)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115564);
			byte params[4] = { NULL };
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoadResolutions(class GFxObject* List)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115566);
			byte params[4] = { NULL };
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddResolutionToList(ScriptString* Resolution)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115574);
			byte params[12] = { NULL };
			*(ScriptString**)params = Resolution;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetSettingNameFromType(TrVideoSettings__EVideoSettingType Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115577);
			byte params[13] = { NULL };
			*(TrVideoSettings__EVideoSettingType*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		TrVideoSettings__EVideoSettingType GetSettingTypeFromName(ScriptString* val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115580);
			byte params[13] = { NULL };
			*(ScriptString**)params = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(TrVideoSettings__EVideoSettingType*)&params[12];
		}
		void CacheVideoSetting(int Index, int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115583);
			byte params[8] = { NULL };
			*(int*)params = Index;
			*(int*)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSmoothFramerateValue(int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(115593);
			byte params[4] = { NULL };
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
