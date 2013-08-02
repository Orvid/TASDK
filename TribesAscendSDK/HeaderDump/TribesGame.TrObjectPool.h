#pragma once
namespace UnrealScript
{
	class TrObjectPool;
}
#include "Engine.Actor.h"
#include "TribesGame.TrObject.EWeaponTracerType.h"
#include "TribesGame.TrObjectPool.TracerCacheInfo.h"
#include "TribesGame.TrProj_Tracer.h"
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
	class TrObjectPool : public Actor
	{
	public:
		typedef TrObjectPool__TracerCacheInfo TracerCacheInfo;
		static const auto MAX_TRACERS = 20;
		ADD_STRUCT(TrObjectPool__TracerCacheInfo, m_TracerCache, 476)
		class TrProj_Tracer* GetTracer(TrObject__EWeaponTracerType TracerType, byte ActiveReloadTier, Vector SpawnLocation, Rotator SpawnRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(67440);
			byte params[30] = { NULL };
			*(TrObject__EWeaponTracerType*)params = TracerType;
			params[1] = ActiveReloadTier;
			*(Vector*)&params[4] = SpawnLocation;
			*(Rotator*)&params[16] = SpawnRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrProj_Tracer**)&params[28];
		}
		void PreBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100300);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreatePools()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100301);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100302);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CleanUpPools()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100303);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreateTracers()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100304);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CleanupTracers()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100305);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreateTracer(TrObject__EWeaponTracerType TracerType, ScriptClass* TracerClass, int Idx, bool bForceCreate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100309);
			byte params[13] = { NULL };
			*(TrObject__EWeaponTracerType*)params = TracerType;
			*(ScriptClass**)&params[4] = TracerClass;
			*(int*)&params[8] = Idx;
			*(bool*)&params[12] = bForceCreate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
