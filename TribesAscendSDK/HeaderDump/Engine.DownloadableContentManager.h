#pragma once
namespace UnrealScript
{
	class DownloadableContentManager;
}
#include "Core.Object.h"
#include "Core.Object.Map_Mirror.h"
#include "Core.Object.Pointer.h"
#include "Engine.GameEngine.h"
#include "Engine.OnlineSubsystem.OnlineContent.h"
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
	class DownloadableContentManager : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<Object__Pointer>, DLCConfigCacheChanges, 60)
		ADD_STRUCT(ScriptArray<ScriptString*>, InstalledDLC, 72)
		ADD_STRUCT(ScriptArray<ScriptClass*>, ClassesToReload, 144)
		ADD_STRUCT(ScriptArray<class Object*>, ObjectsToReload, 156)
		ADD_OBJECT(GameEngine, GameEngine, 168)
		ADD_STRUCT(Object__Map_Mirror, TextureCachePathMap, 84)
		bool InstallDLC(OnlineSubsystem__OnlineContent& DLCBundle)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14711);
			byte params[72] = { NULL };
			*(OnlineSubsystem__OnlineContent*)params = DLCBundle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DLCBundle = *(OnlineSubsystem__OnlineContent*)params;
			return *(bool*)&params[68];
		}
		void InstallDLCs(ScriptArray<OnlineSubsystem__OnlineContent>& DLCBundles)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14714);
			byte params[12] = { NULL };
			*(ScriptArray<OnlineSubsystem__OnlineContent>*)params = DLCBundles;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DLCBundles = *(ScriptArray<OnlineSubsystem__OnlineContent>*)params;
		}
		void ClearDLC()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14717);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool GetDLCTextureCachePath(ScriptName TextureCacheName, ScriptString*& Path)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14718);
			byte params[24] = { NULL };
			*(ScriptName*)params = TextureCacheName;
			*(ScriptString**)&params[8] = Path;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Path = *(ScriptString**)&params[8];
			return *(bool*)&params[20];
		}
		void AddSectionToObjectList(ScriptString* Section)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14722);
			byte params[12] = { NULL };
			*(ScriptString**)params = Section;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MarkPerObjectConfigPendingKill(ScriptString* Section)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14724);
			byte params[12] = { NULL };
			*(ScriptString**)params = Section;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateObjectLists()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14726);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InstallPackages(OnlineSubsystem__OnlineContent& DLCBundle)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14727);
			byte params[68] = { NULL };
			*(OnlineSubsystem__OnlineContent*)params = DLCBundle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DLCBundle = *(OnlineSubsystem__OnlineContent*)params;
		}
		void InstallNonPackageFiles(OnlineSubsystem__OnlineContent& DLCBundle)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14729);
			byte params[68] = { NULL };
			*(OnlineSubsystem__OnlineContent*)params = DLCBundle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DLCBundle = *(OnlineSubsystem__OnlineContent*)params;
		}
		void Init()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14731);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnLoginChange(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14733);
			byte params[1] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnStorageDeviceChange()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14735);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnContentChange()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14736);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RefreshDLC()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14737);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RefreshDLCEnumComplete()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14741);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddPackagesToFullyLoad(ScriptString* Filename)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14743);
			byte params[12] = { NULL };
			*(ScriptString**)params = Filename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
