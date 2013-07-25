#pragma once
#include "Engine__UberPostProcessEffect.h"
#include "UTGame__UTGFxHudWrapper.h"
#include "TribesGame__TrSpectatorHUDCache.h"
#include "Engine__MaterialInstanceConstant.h"
#include "TribesGame__TrHUDTeamCTFStats.h"
#include "TribesGame__TrPlayerController.h"
#include "TribesGame__GFxTrUI_TeamSelectionMenu.h"
#include "Engine__Texture2D.h"
#include "TribesGame__TrDeployable.h"
#include "TribesGame__GfxTrHud.h"
#include "Engine__MaterialEffect.h"
#include "TribesGame__TrDaDStats.h"
#include "TribesGame__TrCaHStats.h"
#include "TribesGame__TrArenaStats.h"
#include "TribesGame__TrTeamRabbitStats.h"
#include "TribesGame__TrRabbitLeaderboard.h"
#include "TribesGame__TrScoreboard.h"
#include "TribesGame__GFxTrUI_VehicleMenu.h"
#include "Engine__Material.h"
#include "Engine__Canvas.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Core__Object.h"
#include "TribesGame__TrPawn.h"
#include "TribesGame__TrVehicle.h"
#include "TribesGame__TrCamera_SpectatorBookmark.h"
#include "Engine__Actor.h"
#include "Engine__PlayerController.h"
#include "TribesGame__TrProj_Mine.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrHUD." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrHUD." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrHUD." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrHUD : public UTGFxHudWrapper
	{
	public:
		ADD_VAR(::BoolProperty, m_bIsControllerSkiing, 0x8)
		ADD_OBJECT(TrSpectatorHUDCache, m_SpectatorHUDCache)
		ADD_OBJECT(GFxTrUI_TeamSelectionMenu, TeamSelectionMenuMovie)
		ADD_OBJECT(TrPlayerController, TrPlayerOwner)
		ADD_VAR(::BoolProperty, bIsMainMenuOpen, 0x1000)
		ADD_OBJECT(MaterialInstanceConstant, MarkerBaseMIC)
		ADD_VAR(::BoolProperty, bShowObjectives, 0x4)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'MarkerColorFriendly'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'MarkerColorEnemy'!
		ADD_OBJECT(Texture2D, BaseDeployableLevel1)
		ADD_OBJECT(Texture2D, BaseDeployableLevel2)
		ADD_OBJECT(Texture2D, BaseDeployableLevel3)
		ADD_OBJECT(Texture2D, BaseDeployableLevel4)
		ADD_OBJECT(Texture2D, BaseDeployableLevel5)
		ADD_OBJECT(Texture2D, BaseNoPower)
		ADD_OBJECT(Texture2D, DeployableTurret)
		ADD_OBJECT(Texture2D, BaseTurretLevel1)
		ADD_OBJECT(Texture2D, BaseTurretLevel2)
		ADD_OBJECT(Texture2D, BaseTurretLevel3)
		ADD_OBJECT(Texture2D, BaseTurretLevel4)
		ADD_OBJECT(Texture2D, BaseTurretLevel5)
		ADD_OBJECT(Texture2D, BaseTurretLevel1_Down)
		ADD_OBJECT(Texture2D, BaseTurretLevel2_Down)
		ADD_OBJECT(Texture2D, BaseTurretLevel3_Down)
		ADD_OBJECT(Texture2D, BaseTurretLevel4_Down)
		ADD_OBJECT(Texture2D, BaseTurretLevel5_Down)
		ADD_VAR(::IntProperty, m_nPotentialSeekingTargetHUDRotationRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPotentialSeekingTargetHUDZoomTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSeekingTargetHUDZoomTime, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, HUDMarkerMissileLocked)
		ADD_VAR(::FloatProperty, m_fSeekingTargetHUDZoomEnd, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSeekingTargetHUDZoomOpacityStart, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSeekingTargetHUDZoomOpacityEnd, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSeekingTargetHUDZoomStart, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fInitialSeekingTargetYaw, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, HUDMarkerMissileLocking)
		ADD_OBJECT(Texture2D, HUDMarkerMissileTargetLocked)
		ADD_OBJECT(Texture2D, HUDMarkerMissileTarget)
		ADD_VAR(::FloatProperty, m_fPotentialSeekingTargetHUDZoomOpacityStart, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPotentialSeekingTargetHUDZoomOpacityEnd, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPotentialSeekingTargetHUDZoomStart, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPotentialSeekingTargetHUDZoomEnd, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCaratPlacementX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCaratPlacementY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMarker2DDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCurrentWhiteoutValue, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TeamPlayerInfoMaxDist, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, DeployableSensor)
		ADD_OBJECT(Texture2D, MarkerLight)
		ADD_OBJECT(Texture2D, MarkerMedium)
		ADD_OBJECT(Texture2D, MarkerHeavy)
		ADD_OBJECT(Texture2D, FlagHeldLight)
		ADD_OBJECT(Texture2D, FlagHeldMedium)
		ADD_OBJECT(Texture2D, FlagHeldHeavy)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'MarkerColorEnemy_IsFriend'!
		ADD_VAR(::FloatProperty, m_fNamePlacementX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fNamePlacementY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fHealthBarPlacementX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fHealthBarPlacementY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fHealthBarWidth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fHealthBarHeight, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'MarkerColorFriendly_IsFriend'!
		ADD_OBJECT(GfxTrHud, m_GFxHud)
		ADD_VAR(::IntProperty, FriendlyChatColorIdx, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'FriendlyChatColor'!
		ADD_VAR(::IntProperty, EnemyChatColorIdx, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'EnemyChatColor'!
		ADD_VAR(::IntProperty, WhisperChatColorIdx, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'WhisperChatColor'!
		ADD_VAR(::IntProperty, InfoChatColorIdx, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bVotePending, 0x800)
		ADD_OBJECT(Texture2D, FlagEmptyBase)
		ADD_OBJECT(Texture2D, BaseGeneratorLevel1)
		ADD_OBJECT(Texture2D, BaseGeneratorLevel1_Down)
		ADD_OBJECT(Texture2D, DeployableJammer)
		ADD_OBJECT(Texture2D, DeployableShield)
		ADD_OBJECT(Texture2D, BaseSensorLevel1)
		ADD_OBJECT(Texture2D, BaseSensorLevel2)
		ADD_OBJECT(Texture2D, BaseSensorLevel3)
		ADD_OBJECT(Texture2D, BaseSensorLevel4)
		ADD_OBJECT(Texture2D, BaseSensorLevel5)
		ADD_OBJECT(Texture2D, BaseSensorLevel1_Down)
		ADD_OBJECT(Texture2D, BaseSensorLevel2_Down)
		ADD_OBJECT(Texture2D, BaseSensorLevel3_Down)
		ADD_OBJECT(Texture2D, BaseSensorLevel4_Down)
		ADD_OBJECT(Texture2D, BaseSensorLevel5_Down)
		ADD_OBJECT(Texture2D, HUDMarkerLaserTargetAimPoint)
		ADD_OBJECT(Texture2D, HUDMarkerLaserTarget)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'LaserTargetTracePossible'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'LaserTargetTraceImprobable'!
		ADD_OBJECT(Texture2D, AmmoDropPickup)
		ADD_OBJECT(Texture2D, FlagAtBase)
		ADD_OBJECT(Texture2D, FlagDropped)
		ADD_VAR(::FloatProperty, m_fOverheadNumberColorizeTimeMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fOverheadNumberColorizeTimeMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fOverheadNumberMaxScaleAmount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fOverheadNumberScaleTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fOverheadNumberFadeTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fOverheadNumberTotalTime, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'm_OverheadNumberColorMax'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'm_OverheadNumberColorMin'!
		ADD_VAR(::FloatProperty, m_fOverheadNumberZSpeed, 0xFFFFFFFF)
		ADD_OBJECT(UberPostProcessEffect, m_UperPPEffect)
		// WARNING: Unknown structure type 'ScriptStruct Engine.Canvas.FontRenderInfo' for the property named 'm_nNameFontRenderInfo'!
		ADD_VAR(::FloatProperty, m_fMineDeployerNamePlacementY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMineDeployerNamePlacementX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMineNamePlacementY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMineNamePlacementX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fVehicleNamePlacementY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fVehicleNamePlacementX, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, AwardMIC)
		ADD_VAR(::FloatProperty, AwardTimelineLoc, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AwardFadeInScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AwardTimelineLength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AwardBaseHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AwardBaseSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCurrentFumbledFlagValue, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_FumbledFlagFadeOutSpeed, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_FumbledFlagMaterialInstance)
		ADD_OBJECT(MaterialEffect, m_FumbledFlagMaterialEffect)
		ADD_VAR(::FloatProperty, m_WhiteoutFadeOutSpeed, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_WhiteoutMaterialInstance)
		ADD_OBJECT(MaterialEffect, m_WhiteoutMaterialEffect)
		ADD_VAR(::FloatProperty, m_VignetteValueMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_VignetteFadeTarget, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_VignetteFadeSpeed, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_VignetteMaterialInstance)
		ADD_OBJECT(MaterialEffect, m_VignetteMaterialEffect)
		ADD_VAR(::IntProperty, LastChangeResCheckTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastChangeResTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastCreditTotal, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_JammerPackFadeOutSpeed, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_JammerPackMaterialInstance)
		ADD_OBJECT(MaterialEffect, m_JammerPackMaterialEffect)
		ADD_VAR(::FloatProperty, m_ShieldHitFadeOutSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_ShieldHitFadeInSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_ShieldFadeOutSpeed, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_ShieldMaterialInstance)
		ADD_OBJECT(MaterialEffect, m_ShieldMaterialEffect)
		ADD_VAR(::FloatProperty, m_InvulnerableFadeOutSpeed, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_InvulnerableMaterialInstance)
		ADD_OBJECT(MaterialEffect, m_InvulnerableMaterialEffect)
		ADD_VAR(::FloatProperty, m_PickupFlashFadeOutSpeed, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_PickupFlashMaterialInstance)
		ADD_OBJECT(MaterialEffect, m_PickupFlashMaterialEffect)
		ADD_VAR(::FloatProperty, m_fSkiEffectStrobeTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSkiEffectFadeOutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSkiEffectFadeInTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSkiEffectMinIntensity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSkiEffectMaxIntensity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fControllerSkiSpeed, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_SkiEffectMaterialInstance)
		ADD_OBJECT(MaterialEffect, m_SkiEffect)
		ADD_OBJECT(ScriptClass, m_GameClass)
		ADD_OBJECT(ScriptClass, m_MusicManagerClass)
		ADD_VAR(::FloatProperty, m_fEnemyGeneratorRestoreTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFriendlyGeneratorRestoreTime, 0xFFFFFFFF)
		ADD_OBJECT(TrCaHStats, CaHStats)
		ADD_OBJECT(TrDaDStats, DaDStats)
		ADD_OBJECT(TrArenaStats, ArenaStats)
		ADD_OBJECT(TrTeamRabbitStats, TeamRabbitStats)
		ADD_OBJECT(TrHUDTeamCTFStats, HUDTeamCTFStats)
		ADD_OBJECT(TrRabbitLeaderboard, RabbitLeaderboard)
		ADD_OBJECT(TrScoreboard, Scoreboard)
		ADD_OBJECT(GFxTrUI_VehicleMenu, VehicleMenuMovie)
		ADD_OBJECT(Material, MapMaterialReference)
		ADD_OBJECT(MaterialInstanceConstant, LowAmmoMic)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'TeamChatColor'!
		ADD_VAR(::IntProperty, SelfChatColorIdx, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, SpottedTarget_MotionMine)
		ADD_OBJECT(Texture2D, SpottedTarget)
		ADD_OBJECT(Texture2D, DeployableMine)
		ADD_OBJECT(Texture2D, DeployableClaymore)
		ADD_OBJECT(Texture2D, BaseGeneratorLevel5_Down)
		ADD_OBJECT(Texture2D, BaseGeneratorLevel4_Down)
		ADD_OBJECT(Texture2D, BaseGeneratorLevel3_Down)
		ADD_OBJECT(Texture2D, BaseGeneratorLevel2_Down)
		ADD_OBJECT(Texture2D, BaseGeneratorLevel5)
		ADD_OBJECT(Texture2D, BaseGeneratorLevel4)
		ADD_OBJECT(Texture2D, BaseGeneratorLevel3)
		ADD_OBJECT(Texture2D, BaseGeneratorLevel2)
		ADD_OBJECT(Texture2D, BaseVehicleStation)
		ADD_OBJECT(Texture2D, BaseRepairStation)
		ADD_OBJECT(Texture2D, BaseInventoryStation)
		ADD_OBJECT(Texture2D, HUDMarkerMissileIncoming)
		ADD_OBJECT(Texture2D, FlagHeldVehicle)
		ADD_OBJECT(Texture2D, VehicleMarkerNoDriver)
		ADD_OBJECT(Texture2D, VehicleMarkerHeavy)
		ADD_OBJECT(Texture2D, VehicleMarkerMedium)
		ADD_OBJECT(Texture2D, VehicleMarkerLight)
		ADD_OBJECT(Texture2D, VehicleMarker)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'MarkerColorNone'!
		ADD_VAR(::IntProperty, m_LastDeployableCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_LastMineCount, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'ColorEnemy'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'ColorFriend'!
		ADD_VAR(::FloatProperty, ObjectiveInfoMaxDist, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_sLastClassName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_sWinningPlayer, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAccoladePlaying, 0x40000)
		ADD_VAR(::BoolProperty, m_bIsSpectatorFloatCameraPanelVisible, 0x20000)
		ADD_VAR(::BoolProperty, m_bIsSpectatorObjectivePanelVisible, 0x10000)
		ADD_VAR(::BoolProperty, m_bIsSpectatorBookmarkPanelVisible, 0x8000)
		ADD_VAR(::BoolProperty, m_bIsSpectatorVehiclePanelVisible, 0x4000)
		ADD_VAR(::BoolProperty, m_bIsSpectatorPlayerPanelVisible, 0x2000)
		ADD_VAR(::BoolProperty, bPlayAward, 0x400)
		ADD_VAR(::BoolProperty, m_bUpdateFumbledFlagEffect, 0x200)
		ADD_VAR(::BoolProperty, m_bUpdateWhiteoutEffect, 0x100)
		ADD_VAR(::BoolProperty, bLoadSequenceComplete, 0x80)
		ADD_VAR(::BoolProperty, bRestoreHUDState, 0x40)
		ADD_VAR(::BoolProperty, m_bEffectFadingIn, 0x20)
		ADD_VAR(::BoolProperty, m_bStrobeIn, 0x10)
		ADD_VAR(::BoolProperty, HasGlobalChatAsAlert, 0x2)
		ADD_VAR(::BoolProperty, m_bGameOver, 0x1)
		ADD_VAR(::IntProperty, m_nLastPerk2Icon, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastPerk1Icon, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nWinningTeam, 0xFFFFFFFF)
		Vector DrawMarkerText(ScriptArray<wchar_t> ShowText, bool bFriend, Vector Placement, class Canvas* DrawCanvas, bool bBuddy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.DrawMarkerText");
			byte* params = (byte*)malloc(48);
			*(ScriptArray<wchar_t>*)params = ShowText;
			*(bool*)(params + 12) = bFriend;
			*(Vector*)(params + 16) = Placement;
			*(class Canvas**)(params + 28) = DrawCanvas;
			*(bool*)(params + 32) = bBuddy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 36);
			free(params);
			return returnVal;
		}
		Vector DrawMICMarker(class MaterialInstanceConstant* MarkerMIC, Vector Placement, class Canvas* DrawCanvas, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* MarkerSize, ScriptArray<wchar_t> markText, bool bFriend, float distScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.DrawMICMarker");
			byte* params = (byte*)malloc(60);
			*(class MaterialInstanceConstant**)params = MarkerMIC;
			*(Vector*)(params + 4) = Placement;
			*(class Canvas**)(params + 16) = DrawCanvas;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 20) = MarkerSize;
			*(ScriptArray<wchar_t>*)(params + 28) = markText;
			*(bool*)(params + 40) = bFriend;
			*(float*)(params + 44) = distScale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 48);
			free(params);
			return returnVal;
		}
		bool GetEdgeScreenCoordinates(class Canvas* inCanvas, Vector CameraPosition, Vector CameraDir, Vector ObjectLocation, Vector& ScreenLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.GetEdgeScreenCoordinates");
			byte* params = (byte*)malloc(56);
			*(class Canvas**)params = inCanvas;
			*(Vector*)(params + 4) = CameraPosition;
			*(Vector*)(params + 16) = CameraDir;
			*(Vector*)(params + 28) = ObjectLocation;
			*(Vector*)(params + 40) = ScreenLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ScreenLocation = *(Vector*)(params + 40);
			auto returnVal = *(bool*)(params + 52);
			free(params);
			return returnVal;
		}
		Vector DrawMarker(class Texture2D* Marker, Vector Placement, class Canvas* DrawCanvas, ScriptArray<wchar_t> markText, bool bFriend, float Alpha, float distScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.DrawMarker");
			byte* params = (byte*)malloc(56);
			*(class Texture2D**)params = Marker;
			*(Vector*)(params + 4) = Placement;
			*(class Canvas**)(params + 16) = DrawCanvas;
			*(ScriptArray<wchar_t>*)(params + 20) = markText;
			*(bool*)(params + 32) = bFriend;
			*(float*)(params + 36) = Alpha;
			*(float*)(params + 40) = distScale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 44);
			free(params);
			return returnVal;
		}
		Vector DrawRotatedMarker(class Texture2D* Marker, Vector Placement, Rotator Rot, class Canvas* DrawCanvas, ScriptArray<wchar_t> markText, bool bFriend, float Alpha, float distScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.DrawRotatedMarker");
			byte* params = (byte*)malloc(68);
			*(class Texture2D**)params = Marker;
			*(Vector*)(params + 4) = Placement;
			*(Rotator*)(params + 16) = Rot;
			*(class Canvas**)(params + 28) = DrawCanvas;
			*(ScriptArray<wchar_t>*)(params + 32) = markText;
			*(bool*)(params + 44) = bFriend;
			*(float*)(params + 48) = Alpha;
			*(float*)(params + 52) = distScale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 56);
			free(params);
			return returnVal;
		}
		void ShowDebugInfo(float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.ShowDebugInfo");
			byte* params = (byte*)malloc(8);
			*(float*)params = out_YL;
			*(float*)(params + 4) = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_YL = *(float*)params;
			out_YPos = *(float*)(params + 4);
			free(params);
		}
		void CreateHUDMovie()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.CreateHUDMovie");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowSpectatorControls(bool bForceEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.ShowSpectatorControls");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bForceEnabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetShowScores(bool bEnableShowScores)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.SetShowScores");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnableShowScores;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitializeGameHUD()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.InitializeGameHUD");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FadeInTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.FadeInTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Fade(float FadeTarget, float FadeSpeed, float bForceFadeInStartAlpha)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.Fade");
			byte* params = (byte*)malloc(12);
			*(float*)params = FadeTarget;
			*(float*)(params + 4) = FadeSpeed;
			*(float*)(params + 8) = bForceFadeInStartAlpha;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayRoundOver(int WinningTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.PlayRoundOver");
			byte* params = (byte*)malloc(4);
			*(int*)params = WinningTeam;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShowRoundEnding()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.ShowRoundEnding");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayMatchOver(int Winner, ScriptArray<wchar_t> WinnerName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.PlayMatchOver");
			byte* params = (byte*)malloc(16);
			*(int*)params = Winner;
			*(ScriptArray<wchar_t>*)(params + 4) = WinnerName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShowEnding()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.ShowEnding");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FadeInSummary()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.FadeInSummary");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ScaleformJoystickInputEvent(float leftAngle, float rightAngle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.ScaleformJoystickInputEvent");
			byte* params = (byte*)malloc(8);
			*(float*)params = leftAngle;
			*(float*)(params + 4) = rightAngle;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ToggleSkiEffect(bool bEnabled, float fSpeed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.ToggleSkiEffect");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bEnabled;
			*(float*)(params + 4) = fSpeed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TogglePauseMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.TogglePauseMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleMovieHUD()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.ToggleMovieHUD");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleVehicleMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.ToggleVehicleMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ToggleTeamSelectionMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.ToggleTeamSelectionMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPowerOscillation(bool bEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.SetPowerOscillation");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddUpdateToCombatLog(int CombatType, ScriptArray<wchar_t> Aggressor, int WeaponIcon, ScriptArray<wchar_t> Victim)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.AddUpdateToCombatLog");
			byte* params = (byte*)malloc(32);
			*(int*)params = CombatType;
			*(ScriptArray<wchar_t>*)(params + 4) = Aggressor;
			*(int*)(params + 16) = WeaponIcon;
			*(ScriptArray<wchar_t>*)(params + 20) = Victim;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddToPromptPanel(ScriptArray<wchar_t> Message, byte Priority)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.AddToPromptPanel");
			byte* params = (byte*)malloc(13);
			*(ScriptArray<wchar_t>*)params = Message;
			*(params + 12) = Priority;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddToPromptPanelTime(ScriptArray<wchar_t> Message, float EndTime, byte Priority)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.AddToPromptPanelTime");
			byte* params = (byte*)malloc(17);
			*(ScriptArray<wchar_t>*)params = Message;
			*(float*)(params + 12) = EndTime;
			*(params + 16) = Priority;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearPromptPanel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.ClearPromptPanel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddToHeroStatus(ScriptArray<wchar_t> Message, float ShowTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.AddToHeroStatus");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Message;
			*(float*)(params + 12) = ShowTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearHeroStatus()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.ClearHeroStatus");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearPromptPanelMessage(ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.ClearPromptPanelMessage");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateVGSMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.UpdateVGSMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideVGSMenu()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.HideVGSMenu");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddToHelpText(ScriptArray<wchar_t> Title, ScriptArray<wchar_t> Body, float PictureIndex, ScriptArray<wchar_t> footer, ScriptArray<wchar_t> SuppressString)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.AddToHelpText");
			byte* params = (byte*)malloc(52);
			*(ScriptArray<wchar_t>*)params = Title;
			*(ScriptArray<wchar_t>*)(params + 12) = Body;
			*(float*)(params + 24) = PictureIndex;
			*(ScriptArray<wchar_t>*)(params + 28) = footer;
			*(ScriptArray<wchar_t>*)(params + 40) = SuppressString;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearHelpText()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.ClearHelpText");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddUpdateToKillMessage(int RankIcon, int PlayerIcon, ScriptArray<wchar_t> PlayerName, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.AddUpdateToKillMessage");
			byte* params = (byte*)malloc(32);
			*(int*)params = RankIcon;
			*(int*)(params + 4) = PlayerIcon;
			*(ScriptArray<wchar_t>*)(params + 8) = PlayerName;
			*(ScriptArray<wchar_t>*)(params + 20) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddFlyingIcon(int iconNumber, ScriptArray<wchar_t> Description, ScriptArray<wchar_t> Points, int bIsBadge)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.AddFlyingIcon");
			byte* params = (byte*)malloc(32);
			*(int*)params = iconNumber;
			*(ScriptArray<wchar_t>*)(params + 4) = Description;
			*(ScriptArray<wchar_t>*)(params + 16) = Points;
			*(int*)(params + 28) = bIsBadge;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnSpectate(bool bUpdateTeamState)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.OnSpectate");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bUpdateTeamState;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CreateSpectatorHUDCache()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.CreateSpectatorHUDCache");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearSpectatorHUDCache()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.ClearSpectatorHUDCache");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideHUDElements(bool bShowStats, bool bForceCredits)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.HideHUDElements");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bShowStats;
			*(bool*)(params + 4) = bForceCredits;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShowHUDPlayerSpawning()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.ShowHUDPlayerSpawning");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowHUDPlayerAlive()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.ShowHUDPlayerAlive");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowCenterHUDElements(bool bShow)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.ShowCenterHUDElements");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bShow;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateRespawnText(ScriptArray<wchar_t> Text)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.UpdateRespawnText");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Text;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateRespawnTimer(int TimeRemaining)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.UpdateRespawnTimer");
			byte* params = (byte*)malloc(4);
			*(int*)params = TimeRemaining;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateHUDCredits(int changeAmount, int newTotal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.UpdateHUDCredits");
			byte* params = (byte*)malloc(8);
			*(int*)params = changeAmount;
			*(int*)(params + 4) = newTotal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TeamScoreboardShow(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.TeamScoreboardShow");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RabbitScoreboardShow(bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.RabbitScoreboardShow");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TeamScoreboardUpdateSlot(int Index, ScriptArray<wchar_t> PlayerName, ScriptArray<wchar_t> Score, ScriptArray<wchar_t> Kills, ScriptArray<wchar_t> Assists, ScriptArray<wchar_t> Ping, ScriptArray<wchar_t> ClassAbb, int Rank, int RankIcon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.TeamScoreboardUpdateSlot");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.RabbitScoreboardUpdateSlot");
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
		void TeamScoreboardUpdateTeamScore(int Index, int Score)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.TeamScoreboardUpdateTeamScore");
			byte* params = (byte*)malloc(8);
			*(int*)params = Index;
			*(int*)(params + 4) = Score;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TeamScoreboardUpdateTime(ScriptArray<wchar_t> Time)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.TeamScoreboardUpdateTime");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Time;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RabbitScoreboardUpdateTime(ScriptArray<wchar_t> Time)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.RabbitScoreboardUpdateTime");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Time;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TeamScoreboardActivePlayer(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.TeamScoreboardActivePlayer");
			byte* params = (byte*)malloc(4);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RabbitScoreboardActivePlayer(int Index, bool bVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.RabbitScoreboardActivePlayer");
			byte* params = (byte*)malloc(8);
			*(int*)params = Index;
			*(bool*)(params + 4) = bVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ResolutionChanged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.ResolutionChanged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RestoreHUDState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.RestoreHUDState");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideMenus()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.HideMenus");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RemoveMovies()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.RemoveMovies");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CompleteVehicleMenuClose()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.CompleteVehicleMenuClose");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CompleteTeamSelectionMenuClose()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.CompleteTeamSelectionMenuClose");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearCrosshairOnFriendly()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.ClearCrosshairOnFriendly");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CheckCrosshairOnFriendly()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.CheckCrosshairOnFriendly");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		Vector DrawColoredMarkerText(ScriptArray<wchar_t> ShowText, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* TextColor, Vector Placement, class Canvas* DrawCanvas, float ScaleX, float ScaleY)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.DrawColoredMarkerText");
			byte* params = (byte*)malloc(52);
			*(ScriptArray<wchar_t>*)params = ShowText;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 12) = TextColor;
			*(Vector*)(params + 16) = Placement;
			*(class Canvas**)(params + 28) = DrawCanvas;
			*(float*)(params + 32) = ScaleX;
			*(float*)(params + 36) = ScaleY;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 40);
			free(params);
			return returnVal;
		}
		void DrawSmallText(ScriptArray<wchar_t> ShowText, bool bFriend, Vector Placement, class Canvas* DrawCanvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.DrawSmallText");
			byte* params = (byte*)malloc(32);
			*(ScriptArray<wchar_t>*)params = ShowText;
			*(bool*)(params + 12) = bFriend;
			*(Vector*)(params + 16) = Placement;
			*(class Canvas**)(params + 28) = DrawCanvas;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawHealthBar(class MaterialInstanceConstant* HealthBarMIC, bool bFriend, Vector Placement, class Canvas* DrawCanvas, float PlacementX, float PlacementY, float Width, float Height)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.DrawHealthBar");
			byte* params = (byte*)malloc(40);
			*(class MaterialInstanceConstant**)params = HealthBarMIC;
			*(bool*)(params + 4) = bFriend;
			*(Vector*)(params + 8) = Placement;
			*(class Canvas**)(params + 20) = DrawCanvas;
			*(float*)(params + 24) = PlacementX;
			*(float*)(params + 28) = PlacementY;
			*(float*)(params + 32) = Width;
			*(float*)(params + 36) = Height;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostRender()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.PostRender");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetRemainingFriendlyGeneratorRestoreTime()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.GetRemainingFriendlyGeneratorRestoreTime");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float GetRemainingEnemyGeneratorRestoreTime()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.GetRemainingEnemyGeneratorRestoreTime");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void UpdateSkiEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.UpdateSkiEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdatePickupFlashEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.UpdatePickupFlashEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PulsePickupFlashEffect(float PulseAmount, float PulseSpeed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.PulsePickupFlashEffect");
			byte* params = (byte*)malloc(8);
			*(float*)params = PulseAmount;
			*(float*)(params + 4) = PulseSpeed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateInvulnerableEfect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.UpdateInvulnerableEfect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateShieldEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.UpdateShieldEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PulseShieldEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.PulseShieldEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateJammerEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.UpdateJammerEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateFadeEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.UpdateFadeEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FumbleFlag(float Speed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.FumbleFlag");
			byte* params = (byte*)malloc(4);
			*(float*)params = Speed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateFumbledFlagEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.UpdateFumbledFlagEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Whiteout(float Speed, float Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.Whiteout");
			byte* params = (byte*)malloc(8);
			*(float*)params = Speed;
			*(float*)(params + 4) = Amount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearWhiteout()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.ClearWhiteout");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateWhiteoutEffect()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.UpdateWhiteoutEffect");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LocalizedMessage(ScriptClass* InMessageClass, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, ScriptArray<wchar_t> CriticalString, int Switch, float Position, float Lifetime, int FontSize, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void* DrawColor, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.LocalizedMessage");
			byte* params = (byte*)malloc(48);
			*(ScriptClass**)params = InMessageClass;
			*(class PlayerReplicationInfo**)(params + 4) = RelatedPRI;
			*(class PlayerReplicationInfo**)(params + 8) = RelatedPRI;
			*(ScriptArray<wchar_t>*)(params + 12) = CriticalString;
			*(int*)(params + 24) = Switch;
			*(float*)(params + 28) = Position;
			*(float*)(params + 32) = Lifetime;
			*(int*)(params + 36) = FontSize;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color'!
void**)(params + 40) = DrawColor;
			*(class Object**)(params + 44) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ChatMessageReceived(int Channel, ScriptArray<wchar_t> Sender, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.ChatMessageReceived");
			byte* params = (byte*)malloc(28);
			*(int*)params = Channel;
			*(ScriptArray<wchar_t>*)(params + 4) = Sender;
			*(ScriptArray<wchar_t>*)(params + 16) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> StripTag(ScriptArray<wchar_t> sValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.StripTag");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = sValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		void SendLocalMessageToGlobalAlert(ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.SendLocalMessageToGlobalAlert");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SendLocalMessageToChat(ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.SendLocalMessageToChat");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPlayerClassObjects(ScriptArray<wchar_t> ClassName, int PerkIcon1, int PerkIcon2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.SetPlayerClassObjects");
			byte* params = (byte*)malloc(20);
			*(ScriptArray<wchar_t>*)params = ClassName;
			*(int*)(params + 12) = PerkIcon1;
			*(int*)(params + 16) = PerkIcon2;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HideGlobalAlert()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.HideGlobalAlert");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KickVoteMessage(bool bComplete, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.KickVoteMessage");
			byte* params = (byte*)malloc(16);
			*(bool*)params = bComplete;
			*(ScriptArray<wchar_t>*)(params + 4) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableGameTypeHUD()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.EnableGameTypeHUD");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowSpectatorPlayer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.ShowSpectatorPlayer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideSpectatorPlayer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.HideSpectatorPlayer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateSpectatorPlayerPanel(class TrPawn* ViewTargetTrPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.UpdateSpectatorPlayerPanel");
			byte* params = (byte*)malloc(4);
			*(class TrPawn**)params = ViewTargetTrPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShowSpectatorVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.ShowSpectatorVehicle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideSpectatorVehicle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.HideSpectatorVehicle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateSpectatorVehiclePanel(class TrVehicle* ViewTargetVehicle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.UpdateSpectatorVehiclePanel");
			byte* params = (byte*)malloc(4);
			*(class TrVehicle**)params = ViewTargetVehicle;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShowSpectatorBookmark()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.ShowSpectatorBookmark");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideSpectatorBookmark()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.HideSpectatorBookmark");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateSpectatorBookmarkPanel(class TrCamera_SpectatorBookmark* BookMark)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.UpdateSpectatorBookmarkPanel");
			byte* params = (byte*)malloc(4);
			*(class TrCamera_SpectatorBookmark**)params = BookMark;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShowSpectatorObjectivePanel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.ShowSpectatorObjectivePanel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideSpectatorObjectivePanel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.HideSpectatorObjectivePanel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateSpectatorObjectivePanel(class Actor* ObjectiveActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.UpdateSpectatorObjectivePanel");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = ObjectiveActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShowSpectatorFloatCameraPanel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.ShowSpectatorFloatCameraPanel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideSpectatorFloatCameraPanel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.HideSpectatorFloatCameraPanel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateSpectatorFloatCameraPanel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.UpdateSpectatorFloatCameraPanel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void HideAllSpectatorPanels()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.HideAllSpectatorPanels");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnViewTargetChange(class Actor* NewViewTarget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.OnViewTargetChange");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = NewViewTarget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TestNumber(int Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.TestNumber");
			byte* params = (byte*)malloc(4);
			*(int*)params = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddOverheadNumber(int Value, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector4'!
void* WorldLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.AddOverheadNumber");
			byte* params = (byte*)malloc(20);
			*(int*)params = Value;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector4'!
void**)(params + 16) = WorldLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateOverheadNumbers(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.UpdateOverheadNumbers");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostRenderFor(class PlayerController* PC, class Canvas* DrawCanvas, Vector CameraPosition, Vector CameraDir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.PostRenderFor");
			byte* params = (byte*)malloc(32);
			*(class PlayerController**)params = PC;
			*(class Canvas**)(params + 4) = DrawCanvas;
			*(Vector*)(params + 8) = CameraPosition;
			*(Vector*)(params + 20) = CameraDir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayAward(class Canvas* DrawCanvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.PlayAward");
			byte* params = (byte*)malloc(4);
			*(class Canvas**)params = DrawCanvas;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void QueueAccolade(int Icon, ScriptArray<wchar_t> Title, ScriptArray<wchar_t> Subtitle, bool bIsBadge)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.QueueAccolade");
			byte* params = (byte*)malloc(32);
			*(int*)params = Icon;
			*(ScriptArray<wchar_t>*)(params + 4) = Title;
			*(ScriptArray<wchar_t>*)(params + 16) = Subtitle;
			*(bool*)(params + 28) = bIsBadge;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CheckQueuedAccolades()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.CheckQueuedAccolades");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RunQueuedAccoladesTimer(bool bIsBadge)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.RunQueuedAccoladesTimer");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bIsBadge;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearQueuedAccoladesTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.ClearQueuedAccoladesTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DeployableReplicated(class TrDeployable* NewDep)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.DeployableReplicated");
			byte* params = (byte*)malloc(4);
			*(class TrDeployable**)params = NewDep;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void MineReplicated(class TrProj_Mine* NewMine)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.MineReplicated");
			byte* params = (byte*)malloc(4);
			*(class TrProj_Mine**)params = NewMine;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateOwnedItems()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHUD.UpdateOwnedItems");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
