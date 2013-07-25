#pragma once
#include "TribesGame.GFxTrReticules.h"
#include "UTGame.GFxMinimapHud.h"
#include "TribesGame.GFxDeviceAmmoCount.h"
#include "GFxUI.GFxObject.h"
#include "Engine.TeamInfo.h"
#include "Engine.MaterialInstanceConstant.h"
#include "TribesGame.TrPlayerController.h"
#include "Engine.MaterialEffect.h"
#include "TribesGame.TrDevice.h"
#include "TribesGame.TrHUD.h"
#include "Engine.LocalPlayer.h"
#include "Engine.Weapon.h"
#include "TribesGame.TrVehicle.h"
#include "TribesGame.TrPlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GfxTrHud." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.GfxTrHud." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.GfxTrHud." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GfxTrHud : public GFxMinimapHud
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.GfxTrHud.TrTempMessage' for the property named 'm_HeroStatusTempMessage'!
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.GfxTrHud.TrTempMessage' for the property named 'm_PromptPanelTempMessage'!
		ADD_VAR(::StrProperty, m_sRound, 0xFFFFFFFF)
		ADD_OBJECT(GFxObject, VGSMenuList)
		ADD_OBJECT(GFxObject, _global)
		ADD_OBJECT(MaterialInstanceConstant, m_DirDamageMaterialInstance)
		ADD_OBJECT(MaterialEffect, m_DirectionalDamageEffect)
		ADD_VAR(::FloatProperty, m_fDirectionalDamageFadeTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nNearDeathHealthMax, 0xFFFFFFFF)
		ADD_OBJECT(GFxObject, KillCamInfoObject)
		ADD_OBJECT(GFxObject, VGSMenuEntry)
		ADD_OBJECT(GFxObject, SpecHelp_LockViewTF)
		ADD_OBJECT(GFxObject, SpecHelp_ZoomOutTF)
		ADD_OBJECT(GFxObject, SpecHelp_ZoomInTF)
		ADD_OBJECT(GFxObject, SpecHelp_FreeCameraTF)
		ADD_OBJECT(GFxObject, SpecHelp_FastestPlayerTF)
		ADD_OBJECT(GFxObject, SpecHelp_ChangeVehiclesTF)
		ADD_OBJECT(GFxObject, SpecHelp_ChangeBookmarksTF)
		ADD_OBJECT(GFxObject, SpecHelp_ChangeFlagstandsTF)
		ADD_OBJECT(GFxObject, SpecHelp_ChangeFlagsTF)
		ADD_OBJECT(GFxObject, SpecHelp_ChangeGeneratorsTF)
		ADD_OBJECT(GFxObject, SpecHelp_ChangePlayersTF)
		ADD_OBJECT(GFxObject, SpecHelp_DecreaseSpeedTF)
		ADD_OBJECT(GFxObject, SpecHelp_IncreaseSpeedTF)
		ADD_OBJECT(GFxObject, SpecHelp_StrafeRightTF)
		ADD_OBJECT(GFxObject, SpecHelp_StrafeLeftTF)
		ADD_OBJECT(GFxObject, SpecHelp_MoveBackTF)
		ADD_OBJECT(GFxObject, SpecHelp_MoveForwardTF)
		ADD_OBJECT(GFxObject, SpecHelp_MoveDownTF)
		ADD_OBJECT(GFxObject, SpecHelp_MoveUpTF)
		ADD_OBJECT(GFxObject, SpecHelp_ObjKaratsTF)
		ADD_OBJECT(GFxObject, SpecHelp_SpecHudTF)
		ADD_OBJECT(GFxObject, SpecHelp_MainmenuTF)
		ADD_OBJECT(GFxObject, SpecHelp_ScoreboardTF)
		ADD_OBJECT(GFxObject, SpecHelp_TeamSelectTF)
		ADD_OBJECT(GFxObject, SpecHelp_HelpTF)
		ADD_OBJECT(GFxObject, SpecFloat_DescriptionTF)
		ADD_OBJECT(GFxObject, SpecFloat_FloatCameraNameTF)
		ADD_OBJECT(GFxObject, SpecObjective_HealthTF)
		ADD_OBJECT(GFxObject, SpecObjective_HealthFillBar)
		ADD_OBJECT(GFxObject, SpecObjective_DescriptionTF)
		ADD_OBJECT(GFxObject, SpecObjective_ObjectiveNameTF)
		ADD_OBJECT(GFxObject, SpecBookmark_DescriptionTF)
		ADD_OBJECT(GFxObject, SpecBookmark_BookmarkNameTF)
		ADD_OBJECT(GFxObject, SpecVehicle_SkiIndicator_fillBar_speedoTF)
		ADD_OBJECT(GFxObject, SpecVehicle_SkiIndicator_fillBar)
		ADD_OBJECT(GFxObject, SpecVehicle_VehicleGroup_secondaryReady)
		ADD_OBJECT(GFxObject, SpecVehicle_SecondaryNameTF)
		ADD_OBJECT(GFxObject, SpecVehicle_VehicleGroup_primaryReady)
		ADD_OBJECT(GFxObject, SpecVehicle_PrimaryNameTF)
		ADD_OBJECT(GFxObject, SpecVehicle_EnergyTF)
		ADD_OBJECT(GFxObject, SpecVehicle_EnergyFillBar)
		ADD_OBJECT(GFxObject, SpecVehicle_HealthTF)
		ADD_OBJECT(GFxObject, SpecVehicle_HealthFillBar)
		ADD_OBJECT(GFxObject, SpecVehicle_PassengerNameTF)
		ADD_OBJECT(GFxObject, SpecVehicle_DriverNameTF)
		ADD_OBJECT(GFxObject, SpecVehicle_VehicleNameTF)
		ADD_OBJECT(GFxObject, SpecVehicle_FlagCarried)
		ADD_OBJECT(GFxObject, SpecPlayer_SkiIndicator_fillBar_speedoTF)
		ADD_OBJECT(GFxObject, SpecPlayer_SkiIndicator_fillBar)
		ADD_OBJECT(GFxObject, SpecPlayer_Perk2TF)
		ADD_OBJECT(GFxObject, SpecPlayer_PerkItem2)
		ADD_OBJECT(GFxObject, SpecPlayer_Perk1TF)
		ADD_OBJECT(GFxObject, SpecPlayer_PerkItem1)
		ADD_OBJECT(GFxObject, SpecPlayer_PackNameTF)
		ADD_OBJECT(GFxObject, SpecPlayer_PackIcons_count)
		ADD_OBJECT(GFxObject, SpecPlayer_PackIcons_icon)
		ADD_OBJECT(GFxObject, SpecPlayer_OffhandNameTF)
		ADD_OBJECT(GFxObject, SpecPlayer_OffhandIcons_count)
		ADD_OBJECT(GFxObject, SpecPlayer_OffhandIcons_icon)
		ADD_OBJECT(GFxObject, SpecPlayer_SecondaryAmmoTF)
		ADD_OBJECT(GFxObject, SpecPlayer_SecondaryNameTF)
		ADD_OBJECT(GFxObject, SpecPlayer_PrimaryAmmoTF)
		ADD_OBJECT(GFxObject, SpecPlayer_PrimaryNameTF)
		ADD_OBJECT(GFxObject, SpecPlayer_EnergyTF)
		ADD_OBJECT(GFxObject, SpecPlayer_EnergyFillBar)
		ADD_OBJECT(GFxObject, SpecPlayer_HealthTF)
		ADD_OBJECT(GFxObject, SpecPlayer_HealthFillBar)
		ADD_OBJECT(GFxObject, SpecPlayer_RegenTF)
		ADD_OBJECT(GFxObject, SpecPlayer_ClassNameTF)
		ADD_OBJECT(GFxObject, SpecPlayer_PlayerNameTF)
		ADD_OBJECT(GFxObject, SpecPlayer_FlagCarried)
		ADD_OBJECT(GFxObject, SpecObjective)
		ADD_OBJECT(GFxObject, SpecBookmark)
		ADD_OBJECT(GFxObject, SpawnCounter)
		ADD_OBJECT(GFxObject, SpecVehicle)
		ADD_OBJECT(GFxObject, SpecPlayer)
		ADD_OBJECT(GFxObject, SpecFloat)
		ADD_OBJECT(GFxObject, SpecHelp)
		ADD_OBJECT(GFxObject, VGS)
		ADD_OBJECT(GFxObject, NotificationPopup)
		ADD_OBJECT(GFxObject, DeployStatus)
		ADD_OBJECT(GFxObject, GlobalAlertTF)
		ADD_OBJECT(GFxObject, Credits_And_Streaks_CallItem)
		ADD_OBJECT(GFxObject, PlayerStats_Offhand1_Count)
		ADD_OBJECT(GFxObject, PlayerStats_Offhand1_Icon)
		ADD_OBJECT(GFxObject, PlayerStats_PackCount)
		ADD_OBJECT(GFxObject, PlayerStats_PackMC)
		ADD_OBJECT(GFxObject, PlayerStats_Pack)
		ADD_OBJECT(GFxObject, playerStats_Offhand1)
		ADD_OBJECT(GFxObject, VehicleStats_VehicleSlot)
		ADD_OBJECT(GFxObject, VehicleStats_VehicleEnergyFill)
		ADD_OBJECT(GFxObject, VehicleStats_EnergyTF_TextField)
		ADD_OBJECT(GFxObject, VehicleStats_VehicleHealthFill)
		ADD_OBJECT(GFxObject, VehicleStats_HealthTF_TextField)
		ADD_OBJECT(GFxObject, VehicleStats)
		ADD_OBJECT(GFxObject, TeamStats)
		ADD_OBJECT(GFxObject, Offhands_And_Flag_FlagInHand)
		ADD_OBJECT(GFxObject, Credits_And_Streaks_CreditsGroup_CreditsMC_CreditsN)
		ADD_OBJECT(GFxObject, RabbitScoreboard)
		ADD_OBJECT(GFxObject, TeamScoreBoard)
		ADD_OBJECT(GFxObject, ArenaStats)
		ADD_OBJECT(GFxObject, ArenaStats_EnemyScoreTF)
		ADD_OBJECT(GFxObject, ArenaStats_FriendlyScoreTF)
		ADD_OBJECT(GFxObject, ArenaStats_roundCountTF)
		ADD_OBJECT(GFxObject, ArenaStats_arenaGameTimerTF)
		ADD_OBJECT(GFxObject, ArenaStats_EnemyManGraphic08)
		ADD_OBJECT(GFxObject, ArenaStats_EnemyManGraphic07)
		ADD_OBJECT(GFxObject, ArenaStats_EnemyManGraphic06)
		ADD_OBJECT(GFxObject, ArenaStats_EnemyManGraphic05)
		ADD_OBJECT(GFxObject, ArenaStats_EnemyManGraphic04)
		ADD_OBJECT(GFxObject, ArenaStats_EnemyManGraphic03)
		ADD_OBJECT(GFxObject, ArenaStats_EnemyManGraphic02)
		ADD_OBJECT(GFxObject, ArenaStats_EnemyManGraphic01)
		ADD_OBJECT(GFxObject, ArenaStats_FriendlyManGraphic08)
		ADD_OBJECT(GFxObject, ArenaStats_FriendlyManGraphic07)
		ADD_OBJECT(GFxObject, ArenaStats_FriendlyManGraphic06)
		ADD_OBJECT(GFxObject, ArenaStats_FriendlyManGraphic05)
		ADD_OBJECT(GFxObject, ArenaStats_FriendlyManGraphic04)
		ADD_OBJECT(GFxObject, ArenaStats_FriendlyManGraphic03)
		ADD_OBJECT(GFxObject, ArenaStats_FriendlyManGraphic02)
		ADD_OBJECT(GFxObject, ArenaStats_FriendlyManGraphic01)
		ADD_OBJECT(GFxObject, CaHControlPointE)
		ADD_OBJECT(GFxObject, CaHControlPointD)
		ADD_OBJECT(GFxObject, CaHControlPointC)
		ADD_OBJECT(GFxObject, CaHControlPointB)
		ADD_OBJECT(GFxObject, CaHControlPointA)
		ADD_OBJECT(GFxObject, CaHStats)
		ADD_OBJECT(GFxObject, DaDStats)
		ADD_OBJECT(GFxObject, TdmStats)
		ADD_OBJECT(GFxObject, TdmStats_gameTimer)
		ADD_OBJECT(GFxObject, TdmStats_rightFlagStatus)
		ADD_OBJECT(GFxObject, TdmStats_leftFlagStatus)
		ADD_OBJECT(GFxObject, CTFStats)
		ADD_OBJECT(GFxObject, CTFStats_Timer)
		ADD_OBJECT(GFxObject, CTFStats_RightScore)
		ADD_OBJECT(GFxObject, CTFStats_LeftScore)
		ADD_OBJECT(GFxObject, CTFStats_RightFlagTimer)
		ADD_OBJECT(GFxObject, CTFStats_LeftFlagTimer)
		ADD_OBJECT(GFxObject, CTFStats_RightFlagStatus)
		ADD_OBJECT(GFxObject, CTFStats_LeftFlagStatus)
		ADD_OBJECT(GFxObject, CTFStats_RightGenTimer)
		ADD_OBJECT(GFxObject, CTFStats_LeftGenTimer)
		ADD_OBJECT(GFxObject, CTFStats_RightGenStatus)
		ADD_OBJECT(GFxObject, CTFStats_LeftGenStatus)
		ADD_OBJECT(GFxObject, RabbitStats_Timer)
		ADD_OBJECT(GFxObject, RabbitStats_LeaderScore)
		ADD_OBJECT(GFxObject, RabbitStats_LeaderText)
		ADD_OBJECT(GFxObject, RabbitStats)
		ADD_OBJECT(GFxObject, RabbitScoreboard_PlayerHighlight)
		ADD_OBJECT(GFxObject, RabbitScoreboard_RankIcon)
		ADD_OBJECT(GFxObject, RabbitScoreboard_RankTF)
		ADD_OBJECT(GFxObject, RabbitScoreboard_ClassTF)
		ADD_OBJECT(GFxObject, RabbitScoreboard_PingTF)
		ADD_OBJECT(GFxObject, RabbitScoreboard_AssistsTF)
		ADD_OBJECT(GFxObject, RabbitScoreboard_KillsTF)
		ADD_OBJECT(GFxObject, RabbitScoreboard_ScoreT)
		ADD_OBJECT(GFxObject, RabbitScoreboard_PlayerTF)
		ADD_OBJECT(GFxObject, TeamScoreboard_Blue_RankTF)
		ADD_OBJECT(GFxObject, TeamScoreboard_Blue_RankIcon)
		ADD_OBJECT(GFxObject, TeamScoreboard_Blue_ClassTF)
		ADD_OBJECT(GFxObject, TeamScoreboard_Blue_PingTF)
		ADD_OBJECT(GFxObject, TeamScoreboard_Blue_AssistsTF)
		ADD_OBJECT(GFxObject, TeamScoreboard_Blue_KillsTF)
		ADD_OBJECT(GFxObject, TeamScoreboard_Blue_ScoreTF)
		ADD_OBJECT(GFxObject, TeamScoreboard_Blue_PlayerNameTF)
		ADD_OBJECT(GFxObject, TeamScoreboard_Red_RankTF)
		ADD_OBJECT(GFxObject, TeamScoreboard_Red_RankIcon)
		ADD_OBJECT(GFxObject, TeamScoreboard_Red_ClassTF)
		ADD_OBJECT(GFxObject, TeamScoreboard_Red_PingTF)
		ADD_OBJECT(GFxObject, TeamScoreboard_Red_AssistsTF)
		ADD_OBJECT(GFxObject, TeamScoreboard_Red_KillsTF)
		ADD_OBJECT(GFxObject, TeamScoreboard_Red_ScoreTF)
		ADD_OBJECT(GFxObject, TeamScoreboard_Red_PlayerNameTF)
		ADD_OBJECT(GFxObject, PlayerStats_EnergyFillBar)
		ADD_OBJECT(GFxObject, PlayerStats_GhostHealthBar)
		ADD_OBJECT(GFxObject, PlayerStats_HealthFillBar)
		ADD_OBJECT(GFxObject, SpawnCounter_TimeLabel)
		ADD_OBJECT(GFxObject, SpawnCounter_StatusMessage)
		ADD_OBJECT(GFxObject, CreditsAndStreaks_Streak)
		ADD_OBJECT(GFxObject, CreditsAndStreaks)
		ADD_OBJECT(GFxObject, SkiIndicatorFillBar)
		ADD_OBJECT(GFxObject, SkiIndicatorTF)
		ADD_OBJECT(GFxObject, SkiIndicator)
		ADD_OBJECT(GFxObject, CombatLog)
		ADD_OBJECT(GFxObject, KillMessageArea)
		ADD_OBJECT(GFxObject, KillCamInfo)
		ADD_OBJECT(GFxObject, PromptPanel)
		ADD_OBJECT(GFxObject, HeroStatus_outputTF)
		ADD_OBJECT(GFxObject, PlayerStats)
		ADD_OBJECT(GFxObject, Visor)
		ADD_OBJECT(GFxDeviceAmmoCount, deviceAmmoPoolMP)
		ADD_OBJECT(GFxDeviceAmmoCount, deviceAmmoCountMP)
		ADD_OBJECT(GFxTrReticules, Reticules)
		ADD_OBJECT(GFxObject, sniperPowerUp)
		ADD_OBJECT(TrDevice, m_LastOffhand)
		ADD_OBJECT(TeamInfo, m_LastTeam)
		ADD_VAR(::IntProperty, m_nLastVehicleAmmoPool, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLastVehicleEnergy, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastVehicleHealth, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastSeatMask, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSpeedometerUpdateInterval, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_SkiSpeedSteps, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_VGSMenuListCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLastSpeedometerUpdateTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCurrentGhostHealth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLastActualHealth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLastMaxHealth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLastRotation, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bVGSLoadouts, 0x200)
		ADD_VAR(::BoolProperty, m_bNearDeathOn, 0x100)
		ADD_VAR(::BoolProperty, bShowingBadge, 0x80)
		ADD_VAR(::BoolProperty, m_bLastIn3P, 0x40)
		ADD_VAR(::BoolProperty, m_bShowingAmmoClip, 0x20)
		ADD_VAR(::BoolProperty, m_bLastInVehicle, 0x10)
		ADD_VAR(::BoolProperty, m_bGameOver, 0x8)
		ADD_VAR(::BoolProperty, m_bShowPlayerStats, 0x4)
		ADD_VAR(::BoolProperty, m_bLastHasFlag, 0x2)
		ADD_VAR(::BoolProperty, m_bLastSkiing, 0x1)
		ADD_VAR(::FloatProperty, m_fCrosshairDepth, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastFriendlyGeneratorTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastEnemyGeneratorTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastOffhandCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastPercentReload, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastPercentLaser, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastSkiSpeedStep, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nStreakEvent, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nCrossHairMode, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastAmmoPool, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastCredits, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastPercent, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_HUDStageHeight, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_HUDStageWidth, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_HUDStageOriginY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_HUDStageOriginX, 0xFFFFFFFF)
		ADD_OBJECT(TrPlayerController, m_TrPC)
		ADD_OBJECT(TrHUD, m_TrHUD)
		void DelegateSoundAccolade()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.DelegateSoundAccolade");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DelegateLoadVGSMenu(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.DelegateLoadVGSMenu");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool Start(bool StartPaused)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.Start");
			byte* params = (byte*)malloc(8);
			*(bool*)params = StartPaused;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void registerReticules(class GFxTrReticules* MC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.registerReticules");
			byte* params = (byte*)malloc(4);
			*(class GFxTrReticules**)params = MC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Init(class LocalPlayer* Player)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.Init");
			byte* params = (byte*)malloc(4);
			*(class LocalPlayer**)params = Player;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetLoadVGSMenuDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetLoadVGSMenuDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = InDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSoundAccoladeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* InDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSoundAccoladeDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = InDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RabbitLeaderboardUpdateSlot(int Index, ScriptArray<wchar_t> PlayerName, ScriptArray<wchar_t> Score)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.RabbitLeaderboardUpdateSlot");
			byte* params = (byte*)malloc(28);
			*(int*)params = Index;
			*(ScriptArray<wchar_t>*)(params + 4) = PlayerName;
			*(ScriptArray<wchar_t>*)(params + 16) = Score;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RabbitLeaderboardUpdateTime(ScriptArray<wchar_t> Time)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.RabbitLeaderboardUpdateTime");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Time;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFontIndex(int FontIdx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetFontIndex");
			byte* params = (byte*)malloc(4);
			*(int*)params = FontIdx;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearPromptPanel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ClearPromptPanel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RemoveFromPromptPanel(ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.RemoveFromPromptPanel");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearPromptPanelMessage(ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ClearPromptPanelMessage");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LoadVGSMenu(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.LoadVGSMenu");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddVGSEntry(ScriptArray<wchar_t> Command, bool bBold)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.AddVGSEntry");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Command;
			*(bool*)(params + 12) = bBold;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddToPromptPanelTime(ScriptArray<wchar_t> Message, float EndTime, byte messagePriority)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.AddToPromptPanelTime");
			byte* params = (byte*)malloc(17);
			*(ScriptArray<wchar_t>*)params = Message;
			*(float*)(params + 12) = EndTime;
			*(params + 16) = messagePriority;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddtoPromptPanelAS(ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.AddtoPromptPanelAS");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateHeroStatus(ScriptArray<wchar_t> Message, float ShowTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateHeroStatus");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Message;
			*(float*)(params + 12) = ShowTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearHeroStatus()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ClearHeroStatus");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetSpeedometer(int Speed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpeedometer");
			byte* params = (byte*)malloc(4);
			*(int*)params = Speed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPlayerRankIcon(int IconIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetPlayerRankIcon");
			byte* params = (byte*)malloc(4);
			*(int*)params = IconIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPlayerTeamIcon(int Team)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetPlayerTeamIcon");
			byte* params = (byte*)malloc(4);
			*(int*)params = Team;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPlayerClassObjects(ScriptArray<wchar_t> ClassName, int PerkIcon1, int PerkIcon2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetPlayerClassObjects");
			byte* params = (byte*)malloc(20);
			*(ScriptArray<wchar_t>*)params = ClassName;
			*(int*)(params + 12) = PerkIcon1;
			*(int*)(params + 16) = PerkIcon2;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ShouldShowSpectatorReticule()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ShouldShowSpectatorReticule");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SystemEnableNotifies(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SystemEnableNotifies");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ConfigureSpectatorHUD(bool bIsNeutral)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ConfigureSpectatorHUD");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bIsNeutral;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ConfigureHUDState(bool bAlive, bool bReady, bool bForceCredits)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ConfigureHUDState");
			byte* params = (byte*)malloc(12);
			*(bool*)params = bAlive;
			*(bool*)(params + 4) = bReady;
			*(bool*)(params + 8) = bForceCredits;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShowChatLog()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ShowChatLog");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideChatLog()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.HideChatLog");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowCenterHUDElements(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ShowCenterHUDElements");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateCreditsAndStreaks(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateCreditsAndStreaks");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetScoreboardTitle(ScriptArray<wchar_t> sValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetScoreboardTitle");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = sValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateRespawnText(ScriptArray<wchar_t> Text)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateRespawnText");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Text;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetRespawnText(ScriptArray<wchar_t> Text)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetRespawnText");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Text;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateRespawnTimer(int TimeRemaining)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateRespawnTimer");
			byte* params = (byte*)malloc(4);
			*(int*)params = TimeRemaining;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateHUDCredits(int changeAmount, int newTotal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateHUDCredits");
			byte* params = (byte*)malloc(8);
			*(int*)params = changeAmount;
			*(int*)(params + 4) = newTotal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void registerHUDView(class GFxObject* MovieClip, bool secondPass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.registerHUDView");
			byte* params = (byte*)malloc(8);
			*(class GFxObject**)params = MovieClip;
			*(bool*)(params + 4) = secondPass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetHUDStageSize(int HUDOriginX, int HUDOriginY, int Width, int Height)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetHUDStageSize");
			byte* params = (byte*)malloc(16);
			*(int*)params = HUDOriginX;
			*(int*)(params + 4) = HUDOriginY;
			*(int*)(params + 8) = Width;
			*(int*)(params + 12) = Height;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetAmmoCountTF(class Weapon* Wep, ScriptArray<wchar_t> Ammo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetAmmoCountTF");
			byte* params = (byte*)malloc(16);
			*(class Weapon**)params = Wep;
			*(ScriptArray<wchar_t>*)(params + 4) = Ammo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearStats(bool clearScores)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ClearStats");
			byte* params = (byte*)malloc(4);
			*(bool*)params = clearScores;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ForceHealthUpdate(int NewHealth, int NewMaxHealth)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ForceHealthUpdate");
			byte* params = (byte*)malloc(8);
			*(int*)params = NewHealth;
			*(int*)(params + 4) = NewMaxHealth;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetSkiSpeedStep(float Speed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.GetSkiSpeedStep");
			byte* params = (byte*)malloc(8);
			*(float*)params = Speed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		void ConfigureSkiSpeedSteps(float SoftCap)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ConfigureSkiSpeedSteps");
			byte* params = (byte*)malloc(4);
			*(float*)params = SoftCap;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetFrameNumberForVehicle(class TrVehicle* V)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.GetFrameNumberForVehicle");
			byte* params = (byte*)malloc(8);
			*(class TrVehicle**)params = V;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		void TickHud(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TickHud");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ASSetHeading(int Heading)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ASSetHeading");
			byte* params = (byte*)malloc(4);
			*(int*)params = Heading;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TickDirectionalDamageEffect(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TickDirectionalDamageEffect");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ChangeDamageEffectParameter(ScriptName ParamName, float changeValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ChangeDamageEffectParameter");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = ParamName;
			*(float*)(params + 8) = changeValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void PlayDamageEffectWithNoDirectionalIndicator(float Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.PlayDamageEffectWithNoDirectionalIndicator");
			byte* params = (byte*)malloc(4);
			*(float*)params = Amount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ApplyDirectionalDamageEffect(int EffectIndex, float addValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ApplyDirectionalDamageEffect");
			byte* params = (byte*)malloc(8);
			*(int*)params = EffectIndex;
			*(float*)(params + 4) = addValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ApplyNearDeathEffect(float Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ApplyNearDeathEffect");
			byte* params = (byte*)malloc(4);
			*(float*)params = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DisplayHit(Vector HitDir, int Damage, ScriptClass* DamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.DisplayHit");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = HitDir;
			*(int*)(params + 12) = Damage;
			*(ScriptClass**)(params + 16) = DamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateHealth(
// WARNING: Unknown structure type 'ScriptStruct UTGame.GFxMinimapHud.HeEnDisplay'!
void*& Info, float NewHealth, float HealthMax)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateHealth");
			byte* params = (byte*)malloc(44);
			*(
// WARNING: Unknown structure type 'ScriptStruct UTGame.GFxMinimapHud.HeEnDisplay'!
void**)params = Info;
			*(float*)(params + 36) = NewHealth;
			*(float*)(params + 40) = HealthMax;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Info = *(
// WARNING: Unknown structure type 'ScriptStruct UTGame.GFxMinimapHud.HeEnDisplay'!
void**)params;
			free(params);
		}
		void TickGhostHealth(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TickGhostHealth");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateEnergy(
// WARNING: Unknown structure type 'ScriptStruct UTGame.GFxMinimapHud.HeEnDisplay'!
void*& Info, float NewEnergy, float EnergyMax)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateEnergy");
			byte* params = (byte*)malloc(44);
			*(
// WARNING: Unknown structure type 'ScriptStruct UTGame.GFxMinimapHud.HeEnDisplay'!
void**)params = Info;
			*(float*)(params + 36) = NewEnergy;
			*(float*)(params + 40) = EnergyMax;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Info = *(
// WARNING: Unknown structure type 'ScriptStruct UTGame.GFxMinimapHud.HeEnDisplay'!
void**)params;
			free(params);
		}
		void SetOwnership()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetOwnership");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TeamScoreboardUpdateSlot(int Index, ScriptArray<wchar_t> PlayerName, ScriptArray<wchar_t> Score, ScriptArray<wchar_t> Kills, ScriptArray<wchar_t> Assists, ScriptArray<wchar_t> Ping, ScriptArray<wchar_t> ClassAbb, int Rank, int RankIcon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamScoreboardUpdateSlot");
			byte* params = (byte*)malloc(84);
			*(int*)params = Index;
			*(ScriptArray<wchar_t>*)(params + 4) = PlayerName;
			*(ScriptArray<wchar_t>*)(params + 16) = Score;
			*(ScriptArray<wchar_t>*)(params + 28) = Kills;
			*(ScriptArray<wchar_t>*)(params + 40) = Assists;
			*(ScriptArray<wchar_t>*)(params + 52) = Ping;
			*(ScriptArray<wchar_t>*)(params + 64) = ClassAbb;
			*(int*)(params + 76) = Rank;
			*(int*)(params + 80) = RankIcon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RabbitScoreboardUpdateSlot(int Index, ScriptArray<wchar_t> PlayerName, ScriptArray<wchar_t> Score, ScriptArray<wchar_t> Kills, ScriptArray<wchar_t> Assists, ScriptArray<wchar_t> Ping, ScriptArray<wchar_t> ClassAbb, int Rank, int RankIcon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.RabbitScoreboardUpdateSlot");
			byte* params = (byte*)malloc(84);
			*(int*)params = Index;
			*(ScriptArray<wchar_t>*)(params + 4) = PlayerName;
			*(ScriptArray<wchar_t>*)(params + 16) = Score;
			*(ScriptArray<wchar_t>*)(params + 28) = Kills;
			*(ScriptArray<wchar_t>*)(params + 40) = Assists;
			*(ScriptArray<wchar_t>*)(params + 52) = Ping;
			*(ScriptArray<wchar_t>*)(params + 64) = ClassAbb;
			*(int*)(params + 76) = Rank;
			*(int*)(params + 80) = RankIcon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RabbitScoreboardActivePlayer(int Index, bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.RabbitScoreboardActivePlayer");
			byte* params = (byte*)malloc(8);
			*(int*)params = Index;
			*(bool*)(params + 4) = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RabbitLeaderboardShow(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.RabbitLeaderboardShow");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TeamCTFStatsUpdateGeneratorStatus(int Team, bool bPowered)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamCTFStatsUpdateGeneratorStatus");
			byte* params = (byte*)malloc(8);
			*(int*)params = Team;
			*(bool*)(params + 4) = bPowered;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TeamCTFStatsUpdateGeneratorTimer(int Team, ScriptArray<wchar_t> Time)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamCTFStatsUpdateGeneratorTimer");
			byte* params = (byte*)malloc(16);
			*(int*)params = Team;
			*(ScriptArray<wchar_t>*)(params + 4) = Time;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TeamCTFStatsUpdateFlagReturnTime(int Team, ScriptArray<wchar_t> Time)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamCTFStatsUpdateFlagReturnTime");
			byte* params = (byte*)malloc(16);
			*(int*)params = Team;
			*(ScriptArray<wchar_t>*)(params + 4) = Time;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TeamCTFStatsUpdateFlagStatus(int Team, bool bAtBase)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamCTFStatsUpdateFlagStatus");
			byte* params = (byte*)malloc(8);
			*(int*)params = Team;
			*(bool*)(params + 4) = bAtBase;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TeamCTFStatsUpdateTeamScore(int Team, int Score)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamCTFStatsUpdateTeamScore");
			byte* params = (byte*)malloc(8);
			*(int*)params = Team;
			*(int*)(params + 4) = Score;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TeamCTFStatsUpdateTime(ScriptArray<wchar_t> Time)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamCTFStatsUpdateTime");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Time;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TeamCTFStatsShow(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamCTFStatsShow");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TeamRabbitStatsUpdateFlagStatus(int Team)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamRabbitStatsUpdateFlagStatus");
			byte* params = (byte*)malloc(4);
			*(int*)params = Team;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TeamRabbitStatsUpdateTeamScore(int Team, int Score)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamRabbitStatsUpdateTeamScore");
			byte* params = (byte*)malloc(8);
			*(int*)params = Team;
			*(int*)(params + 4) = Score;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ASC_FriendlyTDMScoreUpdate(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ASC_FriendlyTDMScoreUpdate");
			byte* params = (byte*)malloc(4);
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ASC_EnemyTDMScoreUpdate(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ASC_EnemyTDMScoreUpdate");
			byte* params = (byte*)malloc(4);
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TeamRabbitStatsPointBreak(int Team, ScriptArray<wchar_t> val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamRabbitStatsPointBreak");
			byte* params = (byte*)malloc(16);
			*(int*)params = Team;
			*(ScriptArray<wchar_t>*)(params + 4) = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ASC_FriendlyTDMPointBreak(ScriptArray<wchar_t> val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ASC_FriendlyTDMPointBreak");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ASC_EnemyTDMPointBreak(ScriptArray<wchar_t> val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ASC_EnemyTDMPointBreak");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShowNotification(ScriptArray<wchar_t> val, ScriptArray<wchar_t> Val2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ShowNotification");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = val;
			*(ScriptArray<wchar_t>*)(params + 12) = Val2;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HideNotification()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.HideNotification");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TeamRabbitStatsUpdateTime(ScriptArray<wchar_t> Time)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamRabbitStatsUpdateTime");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Time;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TeamRabbitStatsShow(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamRabbitStatsShow");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ArenaUpdateManGraphic(class GFxObject* Obj, ScriptArray<wchar_t> Path, int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ArenaUpdateManGraphic");
			byte* params = (byte*)malloc(20);
			*(class GFxObject**)params = Obj;
			*(ScriptArray<wchar_t>*)(params + 4) = Path;
			*(int*)(params + 16) = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ArenaStatsUpdateTime(ScriptArray<wchar_t> Time)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ArenaStatsUpdateTime");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Time;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ArenaStatsUpdateRoundCount(int RoundNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ArenaStatsUpdateRoundCount");
			byte* params = (byte*)malloc(4);
			*(int*)params = RoundNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ArenaStatsUpdateFriendlyRoundScore(int Score)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ArenaStatsUpdateFriendlyRoundScore");
			byte* params = (byte*)malloc(4);
			*(int*)params = Score;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ArenaStatsUpdateEnemyRoundScore(int Score)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ArenaStatsUpdateEnemyRoundScore");
			byte* params = (byte*)malloc(4);
			*(int*)params = Score;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ArenaStatsShow(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ArenaStatsShow");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ArenaStatsPointBreak(int Team, ScriptArray<wchar_t> val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ArenaStatsPointBreak");
			byte* params = (byte*)malloc(16);
			*(int*)params = Team;
			*(ScriptArray<wchar_t>*)(params + 4) = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ASC_FriendlyArenaPointBreak(ScriptArray<wchar_t> val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ASC_FriendlyArenaPointBreak");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ASC_EnemyArenaPointBreak(ScriptArray<wchar_t> val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ASC_EnemyArenaPointBreak");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ArenaStatsUpdateTeamScore(int Team, int Score)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ArenaStatsUpdateTeamScore");
			byte* params = (byte*)malloc(8);
			*(int*)params = Team;
			*(int*)(params + 4) = Score;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ASC_FriendlyArenaLivesUpdate(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ASC_FriendlyArenaLivesUpdate");
			byte* params = (byte*)malloc(4);
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ASC_EnemyArenaLivesUpdate(int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ASC_EnemyArenaLivesUpdate");
			byte* params = (byte*)malloc(4);
			*(int*)params = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DaDStatsShow(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.DaDStatsShow");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DaDUpdateFriendlyStats(int bGenOnline, ScriptArray<wchar_t> RemainingGenTime, int CapAOnline, int CapBOnline, int CapCOnline, int CoreHealth)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.DaDUpdateFriendlyStats");
			byte* params = (byte*)malloc(32);
			*(int*)params = bGenOnline;
			*(ScriptArray<wchar_t>*)(params + 4) = RemainingGenTime;
			*(int*)(params + 16) = CapAOnline;
			*(int*)(params + 20) = CapBOnline;
			*(int*)(params + 24) = CapCOnline;
			*(int*)(params + 28) = CoreHealth;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DaDUpdateEnemyStats(int bGenOnline, ScriptArray<wchar_t> RemainingGenTime, int CapAOnline, int CapBOnline, int CapCOnline, int CoreHealth)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.DaDUpdateEnemyStats");
			byte* params = (byte*)malloc(32);
			*(int*)params = bGenOnline;
			*(ScriptArray<wchar_t>*)(params + 4) = RemainingGenTime;
			*(int*)(params + 16) = CapAOnline;
			*(int*)(params + 20) = CapBOnline;
			*(int*)(params + 24) = CapCOnline;
			*(int*)(params + 28) = CoreHealth;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CaHStatsShow(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.CaHStatsShow");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CaHControlPointAShow(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.CaHControlPointAShow");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CaHControlPointBShow(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.CaHControlPointBShow");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CaHControlPointCShow(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.CaHControlPointCShow");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CaHControlPointDShow(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.CaHControlPointDShow");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CaHControlPointEShow(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.CaHControlPointEShow");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CaHUpdate(int FriendlyHeld, int FriendlyPoints, int FriendlyPct, int EnemyHeld, int EnemyPoints, int EnemyPct, ScriptArray<wchar_t> GenTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.CaHUpdate");
			byte* params = (byte*)malloc(36);
			*(int*)params = FriendlyHeld;
			*(int*)(params + 4) = FriendlyPoints;
			*(int*)(params + 8) = FriendlyPct;
			*(int*)(params + 12) = EnemyHeld;
			*(int*)(params + 16) = EnemyPoints;
			*(int*)(params + 20) = EnemyPct;
			*(ScriptArray<wchar_t>*)(params + 24) = GenTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CaHPointUpdate(ScriptArray<wchar_t> PointName, int PointType, int PctHeld)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.CaHPointUpdate");
			byte* params = (byte*)malloc(20);
			*(ScriptArray<wchar_t>*)params = PointName;
			*(int*)(params + 12) = PointType;
			*(int*)(params + 16) = PctHeld;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CaHFriendlyPointBreak(ScriptArray<wchar_t> Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.CaHFriendlyPointBreak");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CaHEnemyPointBreak(ScriptArray<wchar_t> Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.CaHEnemyPointBreak");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TeamScoreboardShow(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamScoreboardShow");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RabbitScoreboardShow(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.RabbitScoreboardShow");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateCredits(int Credits)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateCredits");
			byte* params = (byte*)malloc(4);
			*(int*)params = Credits;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateFlagInHand(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateFlagInHand");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateSkiing(bool bSkiing)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateSkiing");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bSkiing;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateSkiLevel(int Level)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateSkiLevel");
			byte* params = (byte*)malloc(4);
			*(int*)params = Level;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateTeamStats(int Team)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateTeamStats");
			byte* params = (byte*)malloc(4);
			*(int*)params = Team;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateVehicleStats(bool bVisible, int FrameId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateVehicleStats");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bVisible;
			*(int*)(params + 4) = FrameId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateVehicleHealth(int Health, int FrameId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateVehicleHealth");
			byte* params = (byte*)malloc(8);
			*(int*)params = Health;
			*(int*)(params + 4) = FrameId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateVehicleEnergy(float Energy, int FrameId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateVehicleEnergy");
			byte* params = (byte*)malloc(8);
			*(float*)params = Energy;
			*(int*)(params + 4) = FrameId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateVehicleSeat(int Index, int FrameId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateVehicleSeat");
			byte* params = (byte*)malloc(8);
			*(int*)params = Index;
			*(int*)(params + 4) = FrameId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateOffhand(int Index, bool bVisible, int FrameId, int Count)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateOffhand");
			byte* params = (byte*)malloc(16);
			*(int*)params = Index;
			*(bool*)(params + 4) = bVisible;
			*(int*)(params + 8) = FrameId;
			*(int*)(params + 12) = Count;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateOwnedItem(int Index, bool bVisible, int FrameId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateOwnedItem");
			byte* params = (byte*)malloc(12);
			*(int*)params = Index;
			*(bool*)(params + 4) = bVisible;
			*(int*)(params + 8) = FrameId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SoundAccolade()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SoundAccolade");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateCallIn(int Index, bool bEnable, bool bAvailable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateCallIn");
			byte* params = (byte*)malloc(12);
			*(int*)params = Index;
			*(bool*)(params + 4) = bEnable;
			*(bool*)(params + 8) = bAvailable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class GFxObject* RetrieveGFxObject(class GFxObject*& Obj, ScriptArray<wchar_t> ObjName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.RetrieveGFxObject");
			byte* params = (byte*)malloc(20);
			*(class GFxObject**)params = Obj;
			*(ScriptArray<wchar_t>*)(params + 4) = ObjName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Obj = *(class GFxObject**)params;
			auto returnVal = *(class GFxObject**)(params + 16);
			free(params);
			return returnVal;
		}
		void SetGlobalAlert(ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetGlobalAlert");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HideGlobalAlert()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.HideGlobalAlert");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreateKillCamInfo(class TrPlayerReplicationInfo* KillerPRI, class TrPlayerReplicationInfo* VictimPRI, ScriptClass* KillDamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.CreateKillCamInfo");
			byte* params = (byte*)malloc(12);
			*(class TrPlayerReplicationInfo**)params = KillerPRI;
			*(class TrPlayerReplicationInfo**)(params + 4) = VictimPRI;
			*(ScriptClass**)(params + 8) = KillDamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShowKillCamInfo(class GFxObject* Data)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ShowKillCamInfo");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = Data;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetWeaponNameFromDamageType(class TrPlayerReplicationInfo* PRI, ScriptClass* FamilyInfo, ScriptClass* KillDamageType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.GetWeaponNameFromDamageType");
			byte* params = (byte*)malloc(24);
			*(class TrPlayerReplicationInfo**)params = PRI;
			*(ScriptClass**)(params + 4) = FamilyInfo;
			*(ScriptClass**)(params + 8) = KillDamageType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		void SetSpectatorPlayerPanel_FlagCarried(bool bCarried)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_FlagCarried");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bCarried;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorPlayerPanel_PlayerName(ScriptArray<wchar_t> PlayerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_PlayerName");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorPlayerPanel_ClassName(ScriptArray<wchar_t> ClassName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_ClassName");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = ClassName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorPlayerPanel_NextRegen(ScriptArray<wchar_t> NextRegen)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_NextRegen");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = NextRegen;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorPlayerPanel_HealthFillBar(int FrameIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_HealthFillBar");
			byte* params = (byte*)malloc(4);
			*(int*)params = FrameIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorPlayerPanel_Health(ScriptArray<wchar_t> Health)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_Health");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Health;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorPlayerPanel_EnergyFillBar(int FrameIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_EnergyFillBar");
			byte* params = (byte*)malloc(4);
			*(int*)params = FrameIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorPlayerPanel_Energy(ScriptArray<wchar_t> Energy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_Energy");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Energy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorPlayerPanel_PrimaryWeaponName(ScriptArray<wchar_t> PrimaryWeaponName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_PrimaryWeaponName");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = PrimaryWeaponName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorPlayerPanel_PrimaryAmmoCount(ScriptArray<wchar_t> PrimaryAmmoCount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_PrimaryAmmoCount");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = PrimaryAmmoCount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorPlayerPanel_SecondaryWeaponName(ScriptArray<wchar_t> SecondaryWeaponName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_SecondaryWeaponName");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = SecondaryWeaponName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorPlayerPanel_SecondaryAmmoCount(ScriptArray<wchar_t> SecondaryAmmoCount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_SecondaryAmmoCount");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = SecondaryAmmoCount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorPlayerPanel_OffhandIcon(int FrameIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_OffhandIcon");
			byte* params = (byte*)malloc(4);
			*(int*)params = FrameIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorPlayerPanel_OffhandAmmo(ScriptArray<wchar_t> OffhandAmmo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_OffhandAmmo");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = OffhandAmmo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorPlayerPanel_OffhandName(ScriptArray<wchar_t> OffhandName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_OffhandName");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = OffhandName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorPlayerPanel_PackIcon(int FrameIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_PackIcon");
			byte* params = (byte*)malloc(4);
			*(int*)params = FrameIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorPlayerPanel_PackAmmo(ScriptArray<wchar_t> PackAmmo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_PackAmmo");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = PackAmmo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorPlayerPanel_PackName(ScriptArray<wchar_t> PackName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_PackName");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = PackName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorPlayerPanel_Perk1Icon(int FrameIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_Perk1Icon");
			byte* params = (byte*)malloc(4);
			*(int*)params = FrameIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorPlayerPanel_Perk1Name(ScriptArray<wchar_t> PerkName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_Perk1Name");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = PerkName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorPlayerPanel_Perk2Icon(int FrameIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_Perk2Icon");
			byte* params = (byte*)malloc(4);
			*(int*)params = FrameIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorPlayerPanel_Perk2Name(ScriptArray<wchar_t> PerkName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_Perk2Name");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = PerkName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorPlayerPanel_SkiIndicatorFillBar(int FrameIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_SkiIndicatorFillBar");
			byte* params = (byte*)malloc(4);
			*(int*)params = FrameIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorPlayerPanel_SkiIndicatorSpeed(ScriptArray<wchar_t> Speed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_SkiIndicatorSpeed");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Speed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorPlayerPanel_Selected(int FrameIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorPlayerPanel_Selected");
			byte* params = (byte*)malloc(4);
			*(int*)params = FrameIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorVehiclePanel_FlagCarried(bool bCarried)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_FlagCarried");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bCarried;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorVehiclePanel_VehicleName(ScriptArray<wchar_t> VehicleName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_VehicleName");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = VehicleName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorVehiclePanel_DriverName(ScriptArray<wchar_t> DriverName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_DriverName");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = DriverName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorVehiclePanel_PassengerName(ScriptArray<wchar_t> PassengerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_PassengerName");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = PassengerName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorVehiclePanel_HealthFillBar(int FrameIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_HealthFillBar");
			byte* params = (byte*)malloc(4);
			*(int*)params = FrameIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorVehiclePanel_Health(ScriptArray<wchar_t> Health)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_Health");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Health;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorVehiclePanel_EnergyFillBar(int FrameIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_EnergyFillBar");
			byte* params = (byte*)malloc(4);
			*(int*)params = FrameIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorVehiclePanel_Energy(ScriptArray<wchar_t> Energy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_Energy");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Energy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorVehiclePanel_PrimaryWeaponName(ScriptArray<wchar_t> PrimaryWeaponName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_PrimaryWeaponName");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = PrimaryWeaponName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorVehiclePanel_PrimaryWeaponReady(int Ready)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_PrimaryWeaponReady");
			byte* params = (byte*)malloc(4);
			*(int*)params = Ready;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorVehiclePanel_PrimaryWeaponVisible(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_PrimaryWeaponVisible");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorVehiclePanel_SecondaryWeaponName(ScriptArray<wchar_t> SecondaryWeaponName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_SecondaryWeaponName");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = SecondaryWeaponName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorVehiclePanel_SecondaryWeaponReady(int Ready)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_SecondaryWeaponReady");
			byte* params = (byte*)malloc(4);
			*(int*)params = Ready;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorVehiclePanel_SecondaryWeaponVisible(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_SecondaryWeaponVisible");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorVehiclePanel_SkiIndicatorFillBar(int FrameIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_SkiIndicatorFillBar");
			byte* params = (byte*)malloc(4);
			*(int*)params = FrameIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorVehiclePanel_SkiIndicatorSpeed(ScriptArray<wchar_t> Speed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_SkiIndicatorSpeed");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Speed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorVehiclePanel_Selected(int FrameIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorVehiclePanel_Selected");
			byte* params = (byte*)malloc(4);
			*(int*)params = FrameIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorBookmarkPanel_BookmarkName(ScriptArray<wchar_t> BookmarkName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorBookmarkPanel_BookmarkName");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = BookmarkName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorObjectivePanel_ObjectiveName(ScriptArray<wchar_t> ObjectiveName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorObjectivePanel_ObjectiveName");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = ObjectiveName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorObjectivePanel_ObjectiveDescription(ScriptArray<wchar_t> ObjectiveDescription)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorObjectivePanel_ObjectiveDescription");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = ObjectiveDescription;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorObjectivePanel_HealthFillBar(int FrameIndex, int Health)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorObjectivePanel_HealthFillBar");
			byte* params = (byte*)malloc(8);
			*(int*)params = FrameIndex;
			*(int*)(params + 4) = Health;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorFloatCameraPanel_Name(ScriptArray<wchar_t> FloatCameraName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorFloatCameraPanel_Name");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = FloatCameraName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectatorFloatCameraPanel_Description(ScriptArray<wchar_t> Description)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetSpectatorFloatCameraPanel_Description");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Description;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShowSpectatorControls(bool bShowControls)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ShowSpectatorControls");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bShowControls;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HideVGSMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.HideVGSMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideTutorial()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.HideTutorial");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowFlagCarried()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ShowFlagCarried");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideFlagCarried()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.HideFlagCarried");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideKillCamInfo()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.HideKillCamInfo");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateVGSMenuList()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateVGSMenuList");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowEnding(int Winner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ShowEnding");
			byte* params = (byte*)malloc(4);
			*(int*)params = Winner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateChatLog(ScriptArray<wchar_t> Message, int ChannelColor, bool bPublic)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateChatLog");
			byte* params = (byte*)malloc(20);
			*(ScriptArray<wchar_t>*)params = Message;
			*(int*)(params + 12) = ChannelColor;
			*(bool*)(params + 16) = bPublic;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPowerOscillation(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.SetPowerOscillation");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateChatLogInput(ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateChatLogInput");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TeamScoreboardActivePlayer(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamScoreboardActivePlayer");
			byte* params = (byte*)malloc(4);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TeamScoreboardUpdateTime(ScriptArray<wchar_t> Time)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamScoreboardUpdateTime");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Time;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RabbitScoreboardUpdateTime(ScriptArray<wchar_t> Time)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.RabbitScoreboardUpdateTime");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Time;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TeamScoreboardUpdateTeamScore(int Index, int Score)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.TeamScoreboardUpdateTeamScore");
			byte* params = (byte*)malloc(8);
			*(int*)params = Index;
			*(int*)(params + 4) = Score;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateTutorial(ScriptArray<wchar_t> Title, ScriptArray<wchar_t> Body, float Icon, ScriptArray<wchar_t> footer, ScriptArray<wchar_t> Suppress)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.UpdateTutorial");
			byte* params = (byte*)malloc(52);
			*(ScriptArray<wchar_t>*)params = Title;
			*(ScriptArray<wchar_t>*)(params + 12) = Body;
			*(float*)(params + 24) = Icon;
			*(ScriptArray<wchar_t>*)(params + 28) = footer;
			*(ScriptArray<wchar_t>*)(params + 40) = Suppress;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddUpdateToCombatLog(int CombatType, ScriptArray<wchar_t> Aggressor, int WeaponIcon, ScriptArray<wchar_t> Victim)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.AddUpdateToCombatLog");
			byte* params = (byte*)malloc(32);
			*(int*)params = CombatType;
			*(ScriptArray<wchar_t>*)(params + 4) = Aggressor;
			*(int*)(params + 16) = WeaponIcon;
			*(ScriptArray<wchar_t>*)(params + 20) = Victim;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddUpdateToKillMessage(int RankIcon, int PlayerIcon, ScriptArray<wchar_t> PlayerName, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.AddUpdateToKillMessage");
			byte* params = (byte*)malloc(32);
			*(int*)params = RankIcon;
			*(int*)(params + 4) = PlayerIcon;
			*(ScriptArray<wchar_t>*)(params + 8) = PlayerName;
			*(ScriptArray<wchar_t>*)(params + 20) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShowSpectatorPlayer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ShowSpectatorPlayer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideSpectatorPlayer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.HideSpectatorPlayer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowSpectatorVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ShowSpectatorVehicle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideSpectatorVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.HideSpectatorVehicle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowSpectatorBookmark()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ShowSpectatorBookmark");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideSpectatorBookmark()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.HideSpectatorBookmark");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowSpectatorObjectivePanel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ShowSpectatorObjectivePanel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideSpectatorObjectivePanel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.HideSpectatorObjectivePanel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowSpectatorFloatCameraPanel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.ShowSpectatorFloatCameraPanel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideSpectatorFloatCameraPanel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.HideSpectatorFloatCameraPanel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddFlyingIcon(int iconNumber, ScriptArray<wchar_t> Description, ScriptArray<wchar_t> Points, int bIsBadge)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GfxTrHud.AddFlyingIcon");
			byte* params = (byte*)malloc(32);
			*(int*)params = iconNumber;
			*(ScriptArray<wchar_t>*)(params + 4) = Description;
			*(ScriptArray<wchar_t>*)(params + 16) = Points;
			*(int*)(params + 28) = bIsBadge;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
