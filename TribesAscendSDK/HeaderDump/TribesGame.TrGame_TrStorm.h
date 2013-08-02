#pragma once
namespace UnrealScript
{
	class TrGame_TrStorm;
}
#include "Engine.PlayerReplicationInfo.h"
#include "TribesGame.TrGame.h"
#include "TribesGame.TrGame_TrStorm.Carrier.h"
#include "TribesGame.TrGame_TrStorm.Missile.h"
#include "TribesGame.TrStormCarrierShield.h"
#include "TribesGame.TrStormControlPoint.h"
#include "TribesGame.TrStormCore.h"
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
	class TrGame_TrStorm : public TrGame
	{
	public:
		typedef TrGame_TrStorm__Missile Missile;
		typedef TrGame_TrStorm__Carrier Carrier;
		ADD_STRUCT(ScriptArray<TrGame_TrStorm__Missile>, m_fActiveMissiles, 1480)
		ADD_STRUCT(float, MatchEndingTime, 1520)
		ADD_STRUCT(int, m_nMaxCoreHealth, 1516)
		ADD_STRUCT(int, m_nMaxShieldHealth, 1512)
		ADD_OBJECT(TrStormCore, m_CarrierCore, 1504)
		ADD_OBJECT(TrStormCarrierShield, m_CarrierShields, 1496)
		ADD_STRUCT(float, m_fMissileDamageAmount, 1492)
		ADD_STRUCT(TrGame_TrStorm__Carrier, m_Carriers, 1456)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90913);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MissileFired(class TrStormControlPoint* FiredFrom, float TimeTillExplosion, byte TargetTeam)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90919);
			byte params[9] = { NULL };
			*(class TrStormControlPoint**)params = FiredFrom;
			*(float*)&params[4] = TimeTillExplosion;
			params[8] = TargetTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90924);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ExplodeMissile(byte TeamNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90927);
			byte params[1] = { NULL };
			*params = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeHealthDamage(byte TeamNum, int DamageAmount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90936);
			byte params[5] = { NULL };
			*params = TeamNum;
			*(int*)&params[4] = DamageAmount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CarrierDestroyed(byte TeamNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90940);
			byte params[1] = { NULL };
			*params = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeDamageFromCore(byte TeamNum, int DamageAmount)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90942);
			byte params[5] = { NULL };
			*params = TeamNum;
			*(int*)&params[4] = DamageAmount;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CheckEndGame(class PlayerReplicationInfo* Winner, ScriptString* Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90962);
			byte params[20] = { NULL };
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptString**)&params[4] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void EndGame(class PlayerReplicationInfo* Winner, ScriptString* Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90968);
			byte params[16] = { NULL };
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptString**)&params[4] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int DetermineWinningTeam()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90971);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
