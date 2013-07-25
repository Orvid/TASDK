#pragma once
#include "Engine.Pawn.h"
#include "Engine.PlayerController.h"
#include "UTGame.UTTeamGame.h"
#include "Engine.Actor.h"
#include "Engine.Controller.h"
#include "TribesGame.TrStatsInterface.h"
#include "TribesGame.TrSeekingMissileManager.h"
#include "TribesGame.TrPlayerController.h"
#include "Engine.PlayerReplicationInfo.h"
#include "UTGame.UTBot.h"
#include "UTGame.UTTeamInfo.h"
#include "Engine.NavigationPoint.h"
#include "UTGame.UTPlayerReplicationInfo.h"
#include "TribesGame.TrPowerGenerator.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrGame." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrGame." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrGame : public UTTeamGame
	{
	public:
		ADD_OBJECT(TrStatsInterface, Stats)
		ADD_VAR(::BoolProperty, bFirstBloodAchieved, 0x8)
		ADD_VAR(::FloatProperty, m_fFriendlyFireDamageScale, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bRoamingMap, 0x200)
		ADD_VAR(::FloatProperty, m_fForcedRespawnTime, 0xFFFFFFFF)
		ADD_OBJECT(TrSeekingMissileManager, m_SeekingMissileManager)
		ADD_VAR(::IntProperty, m_nMinNetPlayers, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nRoundCountdownRemainingTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nRoundCountdownTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nAutoBalanceTeamDifference, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAutoBalanceTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nPlayerTrackingInterval, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nPlayerTrackingCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CountdownWait, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SummaryWait, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, EndGameWait, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MINIMUM_CREDITS_FOR_EXPERIENCE, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_OvertimeTimeLimit, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nNextEffectInstanceId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nEndMatchCounter, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nWinningTeam, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_sWinnerName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bShouldAutoBalance, 0x100)
		ADD_VAR(::BoolProperty, PlayedEndOfGame, 0x80)
		ADD_VAR(::BoolProperty, bPlayedDSWinning, 0x40)
		ADD_VAR(::BoolProperty, bPlayedBEWinning, 0x20)
		ADD_VAR(::BoolProperty, bPlayTeamAudio, 0x10)
		ADD_VAR(::BoolProperty, bForceRoundStart, 0x4)
		ADD_VAR(::BoolProperty, bForceEndGame, 0x2)
		ADD_VAR(::BoolProperty, m_bPostedStats, 0x1)
		bool RequestTeam(byte RequestedTeamNum, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.RequestTeam");
			byte* params = (byte*)malloc(9);
			*params = RequestedTeamNum;
			*(class Controller**)(params + 4) = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool AutoAssignTeam(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.AutoAssignTeam");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool AllowRespawn(class TrPlayerController* TrPC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.AllowRespawn");
			byte* params = (byte*)malloc(8);
			*(class TrPlayerController**)params = TrPC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool CanEnterSpectate(class TrPlayerController* TrPC, bool bNeutral)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.CanEnterSpectate");
			byte* params = (byte*)malloc(12);
			*(class TrPlayerController**)params = TrPC;
			*(bool*)(params + 4) = bNeutral;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		int CreditsSortViaPC(class PlayerController* A, class PlayerController* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.CreditsSortViaPC");
			byte* params = (byte*)malloc(12);
			*(class PlayerController**)params = A;
			*(class PlayerController**)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int CreditSort(class PlayerReplicationInfo* A, class PlayerReplicationInfo* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.CreditSort");
			byte* params = (byte*)malloc(12);
			*(class PlayerReplicationInfo**)params = A;
			*(class PlayerReplicationInfo**)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int ScoreSort(class PlayerReplicationInfo* A, class PlayerReplicationInfo* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.ScoreSort");
			byte* params = (byte*)malloc(12);
			*(class PlayerReplicationInfo**)params = A;
			*(class PlayerReplicationInfo**)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int GetNextEffectInstanceId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.GetNextEffectInstanceId");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void LocalLeaveGame()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.LocalLeaveGame");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnServerInitialized()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.OnServerInitialized");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetOnlinePlayerName(class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.SetOnlinePlayerName");
			byte* params = (byte*)malloc(4);
			*(class PlayerReplicationInfo**)params = PRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ApplyServerSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.ApplyServerSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReduceDamage(int& Damage, class Pawn* injured, class Controller* InstigatedBy, Vector HitLocation, Vector& Momentum, ScriptClass* DamageType, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.ReduceDamage");
			byte* params = (byte*)malloc(44);
			*(int*)params = Damage;
			*(class Pawn**)(params + 4) = injured;
			*(class Controller**)(params + 8) = InstigatedBy;
			*(Vector*)(params + 12) = HitLocation;
			*(Vector*)(params + 24) = Momentum;
			*(ScriptClass**)(params + 36) = DamageType;
			*(class Actor**)(params + 40) = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Damage = *(int*)params;
			Momentum = *(Vector*)(params + 24);
			free(params);
		}
		void PreBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.PreBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddInitialBots()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.AddInitialBots");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class UTBot* AddBot(ScriptArray<wchar_t> BotName, bool bUseTeamIndex, int TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.AddBot");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = BotName;
			*(bool*)(params + 12) = bUseTeamIndex;
			*(int*)(params + 16) = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UTBot**)(params + 20);
			free(params);
			return returnVal;
		}
		void AddBots(int Num)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.AddBots");
			byte* params = (byte*)malloc(4);
			*(int*)params = Num;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class UTBot* SpawnBot(ScriptArray<wchar_t> BotName, bool bUseTeamIndex, int TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.SpawnBot");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = BotName;
			*(bool*)(params + 12) = bUseTeamIndex;
			*(int*)(params + 16) = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UTBot**)(params + 20);
			free(params);
			return returnVal;
		}
		void InitializeBot(class UTBot* NewBot, class UTTeamInfo* BotTeam, 
// WARNING: Unknown structure type 'ScriptStruct UTGame.UTCharInfo.CharacterInfo'!
void*& BotInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.InitializeBot");
			byte* params = (byte*)malloc(120);
			*(class UTBot**)params = NewBot;
			*(class UTTeamInfo**)(params + 4) = BotTeam;
			*(
// WARNING: Unknown structure type 'ScriptStruct UTGame.UTCharInfo.CharacterInfo'!
void**)(params + 8) = BotInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			BotInfo = *(
// WARNING: Unknown structure type 'ScriptStruct UTGame.UTCharInfo.CharacterInfo'!
void**)(params + 8);
			free(params);
		}
		void StartBots()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.StartBots");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KickIdler(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.KickIdler");
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class PlayerController* Login(ScriptArray<wchar_t> Portal, ScriptArray<wchar_t> Options, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* UniqueId, ScriptArray<wchar_t>& ErrorMessage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.Login");
			byte* params = (byte*)malloc(48);
			*(ScriptArray<wchar_t>*)params = Portal;
			*(ScriptArray<wchar_t>*)(params + 12) = Options;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 24) = UniqueId;
			*(ScriptArray<wchar_t>*)(params + 32) = ErrorMessage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ErrorMessage = *(ScriptArray<wchar_t>*)(params + 32);
			auto returnVal = *(class PlayerController**)(params + 44);
			free(params);
			return returnVal;
		}
		class Pawn* SpawnDefaultPawnFor(class Controller* NewPlayer, class NavigationPoint* StartSpot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.SpawnDefaultPawnFor");
			byte* params = (byte*)malloc(12);
			*(class Controller**)params = NewPlayer;
			*(class NavigationPoint**)(params + 4) = StartSpot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Pawn**)(params + 8);
			free(params);
			return returnVal;
		}
		int DetermineWinningTeam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.DetermineWinningTeam");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void EndGame(class PlayerReplicationInfo* Winner, ScriptArray<wchar_t> Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.EndGame");
			byte* params = (byte*)malloc(16);
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptArray<wchar_t>*)(params + 4) = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EndOnlineGame()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.EndOnlineGame");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetEndGameFocus(class PlayerReplicationInfo* Winner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.SetEndGameFocus");
			byte* params = (byte*)malloc(4);
			*(class PlayerReplicationInfo**)params = Winner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TrackPlayerMovement()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.TrackPlayerMovement");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RespawnPlayers()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.RespawnPlayers");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetScores()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.ResetScores");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetRound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.ResetRound");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ForceRoundStart()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.ForceRoundStart");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifySpree(class UTPlayerReplicationInfo* Other, int Num)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.NotifySpree");
			byte* params = (byte*)malloc(8);
			*(class UTPlayerReplicationInfo**)params = Other;
			*(int*)(params + 4) = Num;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EndSpree(class UTPlayerReplicationInfo* Killer, class UTPlayerReplicationInfo* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.EndSpree");
			byte* params = (byte*)malloc(8);
			*(class UTPlayerReplicationInfo**)params = Killer;
			*(class UTPlayerReplicationInfo**)(params + 4) = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GenericPlayerInitialization(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.GenericPlayerInitialization");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptClass* SetGameType(ScriptArray<wchar_t> MapName, ScriptArray<wchar_t> Options, ScriptArray<wchar_t> Portal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.SetGameType");
			byte* params = (byte*)malloc(40);
			*(ScriptArray<wchar_t>*)params = MapName;
			*(ScriptArray<wchar_t>*)(params + 12) = Options;
			*(ScriptArray<wchar_t>*)(params + 24) = Portal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)(params + 36);
			free(params);
			return returnVal;
		}
		void PlayEndOfMatchMessage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.PlayEndOfMatchMessage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendMatchOver()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.SendMatchOver");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendShowSummary()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.SendShowSummary");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendNextMatchCountdown(int Seconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.SendNextMatchCountdown");
			byte* params = (byte*)malloc(4);
			*(int*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SendMatchCountdown(int Seconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.SendMatchCountdown");
			byte* params = (byte*)malloc(4);
			*(int*)params = Seconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ScoreKill(class Controller* Killer, class Controller* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.ScoreKill");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = Killer;
			*(class Controller**)(params + 4) = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ForceRespawn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.ForceRespawn");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void RestartPlayer(class Controller* aPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.RestartPlayer");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = aPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ChangeTeam(class Controller* Other, int Num, bool bNewTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.ChangeTeam");
			byte* params = (byte*)malloc(16);
			*(class Controller**)params = Other;
			*(int*)(params + 4) = Num;
			*(bool*)(params + 8) = bNewTeam;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		byte PickTeam(byte Num, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.PickTeam");
			byte* params = (byte*)malloc(6);
			*params = Num;
			*(class Controller**)(params + 4) = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 8);
			free(params);
			return returnVal;
		}
		byte PickTeamForMigration(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.PickTeamForMigration");
			byte* params = (byte*)malloc(5);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 4);
			free(params);
			return returnVal;
		}
		void HandleSeamlessTravelPlayer(class Controller*& C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.HandleSeamlessTravelPlayer");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			C = *(class Controller**)params;
			free(params);
		}
		void SetPlayerDefaults(class Pawn* PlayerPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.SetPlayerDefaults");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = PlayerPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Killed(class Controller* Killer, class Controller* KilledPlayer, class Pawn* KilledPawn, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.Killed");
			byte* params = (byte*)malloc(16);
			*(class Controller**)params = Killer;
			*(class Controller**)(params + 4) = KilledPlayer;
			*(class Pawn**)(params + 8) = KilledPawn;
			*(ScriptClass**)(params + 12) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AllowCheats(class PlayerController* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.AllowCheats");
			byte* params = (byte*)malloc(8);
			*(class PlayerController**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool AreTeamsUnbalanced()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.AreTeamsUnbalanced");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void CheckForAutoBalance()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.CheckForAutoBalance");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AutoBalanceInTwenty()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.AutoBalanceInTwenty");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AutoBalanceInFive()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.AutoBalanceInFive");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AutoBalanceTeams()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.AutoBalanceTeams");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void MoveRandomPlayerFromTeam(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* TeamList, int PlayersToMove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.MoveRandomPlayerFromTeam");
			byte* params = (byte*)malloc(16);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = TeamList;
			*(int*)(params + 12) = PlayersToMove;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InitGame(ScriptArray<wchar_t> Options, ScriptArray<wchar_t>& ErrorMessage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.InitGame");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Options;
			*(ScriptArray<wchar_t>*)(params + 12) = ErrorMessage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ErrorMessage = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
		}
		void SetPRI(class PlayerController* PC, class PlayerReplicationInfo* NewPRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.SetPRI");
			byte* params = (byte*)malloc(8);
			*(class PlayerController**)params = PC;
			*(class PlayerReplicationInfo**)(params + 4) = NewPRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetRankFromXP(int XP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.GetRankFromXP");
			byte* params = (byte*)malloc(8);
			*(int*)params = XP;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		bool CanSpectate(class PlayerController* Viewer, class PlayerReplicationInfo* ViewTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.CanSpectate");
			byte* params = (byte*)malloc(12);
			*(class PlayerController**)params = Viewer;
			*(class PlayerReplicationInfo**)(params + 4) = ViewTarget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void BroadcastAccolade(ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.BroadcastAccolade");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SendMessageToAll(ScriptClass* InMessageClass, int Switch)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.SendMessageToAll");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = InMessageClass;
			*(int*)(params + 4) = Switch;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnServerSpawnedPlayer(class TrPlayerController* TrPC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.OnServerSpawnedPlayer");
			byte* params = (byte*)malloc(4);
			*(class TrPlayerController**)params = TrPC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int FindGameTypeId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.FindGameTypeId");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		int GetGameTypeId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.GetGameTypeId");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void OnGeneratorPowerChange(class TrPowerGenerator* G)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.OnGeneratorPowerChange");
			byte* params = (byte*)malloc(4);
			*(class TrPowerGenerator**)params = G;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TgStartGame(ScriptArray<wchar_t>& Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.TgStartGame");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Reason = *(ScriptArray<wchar_t>*)params;
			free(params);
		}
		void TgEndGame(ScriptArray<wchar_t>& Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.TgEndGame");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Reason = *(ScriptArray<wchar_t>*)params;
			free(params);
		}
		void TgChangeScore(int nTeam, int nCount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.TgChangeScore");
			byte* params = (byte*)malloc(8);
			*(int*)params = nTeam;
			*(int*)(params + 4) = nCount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TgChangeTime(int nSeconds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.TgChangeTime");
			byte* params = (byte*)malloc(4);
			*(int*)params = nSeconds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TgGetSpectators(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.TgGetSpectators");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			List = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		class NavigationPoint* FindPlayerStart(class Controller* Player, byte InTeam, ScriptArray<wchar_t> IncomingName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame.FindPlayerStart");
			byte* params = (byte*)malloc(21);
			*(class Controller**)params = Player;
			*(params + 4) = InTeam;
			*(ScriptArray<wchar_t>*)(params + 8) = IncomingName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class NavigationPoint**)(params + 20);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT