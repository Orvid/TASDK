#pragma once
#include "Engine.Actor.h"
#include "TribesGame.TrDaDCore.h"
#include "UTGame.UTGameReplicationInfo.h"
#include "TribesGame.TrDaDCapacitor.h"
#include "TribesGame.TrServerSettingsInfo.h"
#include "TribesGame.TrPlayerReplicationInfo.h"
#include "TribesGame.TrObjectPool.h"
#include "TribesGame.TrFlagBase.h"
#include "Engine.PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrGameReplicationInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrGameReplicationInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrGameReplicationInfo : public UTGameReplicationInfo
	{
	public:
		ADD_OBJECT(TrServerSettingsInfo, r_ServerConfig)
		ADD_OBJECT(TrPlayerReplicationInfo, r_BEPlayerList)
		ADD_OBJECT(TrPlayerReplicationInfo, r_DSPlayerList)
		ADD_VAR(::IntProperty, r_nRoundScore, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, r_nCurrentRound, 0xFFFFFFFF)
		ADD_OBJECT(TrObjectPool, m_TrObjectPool)
		ADD_VAR(::ByteProperty, r_PhysType, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCurrentSensorBlipOpacity, 0xFFFFFFFF)
		ADD_OBJECT(TrFlagBase, m_Flags)
		ADD_VAR(::BoolProperty, r_bSkiEnabled, 0x10)
		ADD_VAR(::IntProperty, r_nNumCapturePointsHeld, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, GeneratorPower, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, r_bPoweredCallins, 0x2)
		ADD_OBJECT(PlayerReplicationInfo, m_CurrentRabbitPRI)
		ADD_OBJECT(TrDaDCore, r_DaDCore)
		ADD_OBJECT(TrDaDCapacitor, r_DaDCapacitorBE)
		ADD_OBJECT(TrDaDCapacitor, r_DaDCapacitorDS)
		ADD_VAR(::IntProperty, FlagReturnTime, 0xFFFFFFFF)
		ADD_OBJECT(PlayerReplicationInfo, m_RabbitLeaderBoard)
		ADD_VAR(::IntProperty, r_CarrierCoreHealth, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, r_CarrierShieldHealth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, r_fGlobalMaxJetpackThrustSpeedMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, r_fGlobalAirSpeedMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, r_fGlobalAccelerationMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, r_fGlobalSpeedCapMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSensorBlipFadeSpeed, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, r_nBlip, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, r_nPhase0SeigeEnded, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, r_ResetGame, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bGivePerfBonus, 0x8)
		ADD_VAR(::BoolProperty, bGivePrivateXP, 0x4)
		ADD_VAR(::BoolProperty, r_bCanPlaceDeployables, 0x1)
		ADD_VAR(::IntProperty, GeneratorDowntime, 0xFFFFFFFF)
		bool IsClassAllowed(int TeamNum, ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameReplicationInfo.IsClassAllowed");
			byte* params = (byte*)malloc(12);
			*(int*)params = TeamNum;
			*(ScriptClass**)(params + 4) = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		int GetTeamSize(byte TeamNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameReplicationInfo.GetTeamSize");
			byte* params = (byte*)malloc(5);
			*params = TeamNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		bool CanJoinTeam(byte RequestedTeam, byte CurrentTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameReplicationInfo.CanJoinTeam");
			byte* params = (byte*)malloc(6);
			*params = RequestedTeam;
			*(params + 1) = CurrentTeam;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		float GetGlobalSpeedCapMultiplier()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameReplicationInfo.GetGlobalSpeedCapMultiplier");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float GetGlobalAccelerationMultiplier()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameReplicationInfo.GetGlobalAccelerationMultiplier");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float GetGlobalAirSpeedMultiplier()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameReplicationInfo.GetGlobalAirSpeedMultiplier");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float GetGlobalMaxJetpackThrustSpeedMultiplier()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameReplicationInfo.GetGlobalMaxJetpackThrustSpeedMultiplier");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameReplicationInfo.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PreBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameReplicationInfo.PreBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameReplicationInfo.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ApplyServerSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameReplicationInfo.ApplyServerSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CanPlaceDeployables(bool Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameReplicationInfo.CanPlaceDeployables");
			byte* params = (byte*)malloc(4);
			*(bool*)params = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnPhase0SiegeEnded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameReplicationInfo.OnPhase0SiegeEnded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnResetGame()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameReplicationInfo.OnResetGame");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Timer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameReplicationInfo.Timer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool OnSameTeam(class Actor* A, class Actor* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameReplicationInfo.OnSameTeam");
			byte* params = (byte*)malloc(12);
			*(class Actor**)params = A;
			*(class Actor**)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void Blip()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameReplicationInfo.Blip");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameReplicationInfo.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ChangePhysicsType(int Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameReplicationInfo.ChangePhysicsType");
			byte* params = (byte*)malloc(4);
			*(int*)params = Type;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsValidTeamPlayer(class TrPlayerReplicationInfo* TrPRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameReplicationInfo.IsValidTeamPlayer");
			byte* params = (byte*)malloc(8);
			*(class TrPlayerReplicationInfo**)params = TrPRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void SetWarmingUp(bool bWarmup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameReplicationInfo.SetWarmingUp");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWarmup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddPRI(class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGameReplicationInfo.AddPRI");
			byte* params = (byte*)malloc(4);
			*(class PlayerReplicationInfo**)params = PRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT