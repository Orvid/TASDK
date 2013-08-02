#pragma once
namespace UnrealScript
{
	class AlienFXManager;
}
#include "Core.Object.h"
#include "TribesGame.AlienFXManager.FXArea.h"
#include "TribesGame.AlienFXManager.FXOverlay.h"
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
	class AlienFXManager : public Object
	{
	public:
		typedef AlienFXManager__FXOverlay FXOverlay;
		typedef AlienFXManager__FXArea FXArea;
		ADD_STRUCT(AlienFXManager__FXOverlay, eLastOverlay, 141)
		ADD_STRUCT(AlienFXManager__FXOverlay, eCurrOverlay, 140)
		ADD_STRUCT(float, fIntervalCount, 136)
		ADD_STRUCT(float, fInterval, 132)
		ADD_STRUCT(float, fSpeed, 128)
		ADD_STRUCT(float, fBoundsPct, 124)
		ADD_STRUCT(float, fHighBounds, 120)
		ADD_STRUCT(float, fLowBounds, 116)
		ADD_STRUCT(int, nTarget, 112)
		ADD_STRUCT(float, fDamages, 80)
		ADD_STRUCT(float, fObjectiveTime, 76)
		ADD_STRUCT(float, fDamageTime, 72)
		ADD_BOOL(bBrighten, 68, 0x8)
		ADD_BOOL(bMenuOpen, 68, 0x4)
		ADD_BOOL(bLoaded, 68, 0x2)
		ADD_BOOL(bShowFX, 68, 0x1)
		ADD_STRUCT(int, nHealth, 64)
		ADD_STRUCT(int, nTeam, 60)
		void Init(bool bEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50990);
			byte params[4] = { NULL };
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Close()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50992);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Queued()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50993);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Objective()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50994);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SwapWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50995);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckHealth()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50996);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void menu(bool bOpen)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50997);
			byte params[4] = { NULL };
			*(bool*)params = bOpen;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Damage(AlienFXManager__FXArea Area)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(50999);
			byte params[1] = { NULL };
			*(AlienFXManager__FXArea*)params = Area;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetTeam(int TeamNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(51001);
			byte params[4] = { NULL };
			*(int*)params = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetHealth(int Health)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(51003);
			byte params[4] = { NULL };
			*(int*)params = Health;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(51005);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Overlay(AlienFXManager__FXOverlay Type)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(51007);
			byte params[1] = { NULL };
			*(AlienFXManager__FXOverlay*)params = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DamageConvert(ScriptString* Area)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(51009);
			byte params[12] = { NULL };
			*(ScriptString**)params = Area;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
