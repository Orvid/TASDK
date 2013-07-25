#pragma once
#include "Core.Object.h"
#include "Engine.Console.h"
#include "Engine.Canvas.h"
#include "Engine.UIInteraction.h"
#include "Engine.LocalPlayer.h"
#include "Engine.Interaction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.GameViewportClient." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.GameViewportClient." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.GameViewportClient." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameViewportClient : public Object
	{
	public:
		ADD_OBJECT(Console, ViewportConsole)
		ADD_OBJECT(UIInteraction, UIController)
		ADD_VAR(::ByteProperty, ActiveSplitscreenType, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, DesiredSplitscreenType, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, UIControllerClass)
		ADD_VAR(::BoolProperty, bDebugNoGFxUI, 0x80)
		ADD_VAR(::ByteProperty, Default2PSplitType, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Default3PSplitType, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.GameViewportClient.TitleSafeZoneArea' for the property named 'TitleSafeZone'!
		ADD_VAR(::BoolProperty, bShowTitleSafeZone, 0x1)
		ADD_VAR(::FloatProperty, ProgressTimeOut, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ProgressFadeTime, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ProgressMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, LoadingMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SavingMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ConnectingMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PrecachingMessage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PausedMessage, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_FViewportClient'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_FExec'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'Viewport'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'ViewportFrame'!
		ADD_STRUCT(::QWordProperty, ShowFlags, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDisplayingUIMouseCursor, 0x2)
		ADD_VAR(::BoolProperty, bUIMouseCaptureOverride, 0x4)
		ADD_VAR(::BoolProperty, bOverrideDiffuseAndSpecular, 0x8)
		ADD_VAR(::BoolProperty, bIsPlayInEditorViewport, 0x10)
		ADD_VAR(::BoolProperty, bShowSystemMouseCursor, 0x20)
		ADD_VAR(::BoolProperty, bDisableWorldRendering, 0x40)
		ADD_VAR(::BoolProperty, bUseHardwareCursorWhenWindowed, 0x100)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'ScaleformInteraction'!
		ScriptArray<wchar_t> ConsoleCommand(ScriptArray<wchar_t> Command)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.ConsoleCommand");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Command;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		bool HandleInputKey(int ControllerId, ScriptName Key, byte EventType, float AmountDepressed, bool bGamepad)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.HandleInputKey");
			byte* params = (byte*)malloc(25);
			*(int*)params = ControllerId;
			*(ScriptName*)(params + 4) = Key;
			*(params + 12) = EventType;
			*(float*)(params + 16) = AmountDepressed;
			*(bool*)(params + 20) = bGamepad;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool HandleInputAxis(int ControllerId, ScriptName Key, float Delta, float DeltaTime, bool bGamepad)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.HandleInputAxis");
			byte* params = (byte*)malloc(28);
			*(int*)params = ControllerId;
			*(ScriptName*)(params + 4) = Key;
			*(float*)(params + 12) = Delta;
			*(float*)(params + 16) = DeltaTime;
			*(bool*)(params + 20) = bGamepad;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool HandleInputChar(int ControllerId, ScriptArray<wchar_t> Unicode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.HandleInputChar");
			byte* params = (byte*)malloc(20);
			*(int*)params = ControllerId;
			*(ScriptArray<wchar_t>*)(params + 4) = Unicode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void GetViewportSize(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void*& out_ViewportSize)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.GetViewportSize");
			byte* params = (byte*)malloc(8);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)params = out_ViewportSize;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_ViewportSize = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)params;
			free(params);
		}
		bool IsFullScreenViewport()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.IsFullScreenViewport");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool ShouldForceFullscreenViewport()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.ShouldForceFullscreenViewport");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		int GetNumCustomInteractions()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.GetNumCustomInteractions");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		ScriptClass* GetCustomInteractionClass(int InIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.GetCustomInteractionClass");
			byte* params = (byte*)malloc(8);
			*(int*)params = InIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)(params + 4);
			free(params);
			return returnVal;
		}
		void SetCustomInteractionObject(class Interaction* InInteraction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.SetCustomInteractionObject");
			byte* params = (byte*)malloc(4);
			*(class Interaction**)params = InInteraction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class LocalPlayer* CreatePlayer(int ControllerId, ScriptArray<wchar_t>& OutError, bool bSpawnActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.CreatePlayer");
			byte* params = (byte*)malloc(24);
			*(int*)params = ControllerId;
			*(ScriptArray<wchar_t>*)(params + 4) = OutError;
			*(bool*)(params + 16) = bSpawnActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutError = *(ScriptArray<wchar_t>*)(params + 4);
			auto returnVal = *(class LocalPlayer**)(params + 20);
			free(params);
			return returnVal;
		}
		int AddLocalPlayer(class LocalPlayer* NewPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.AddLocalPlayer");
			byte* params = (byte*)malloc(8);
			*(class LocalPlayer**)params = NewPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		int RemoveLocalPlayer(class LocalPlayer* ExistingPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.RemoveLocalPlayer");
			byte* params = (byte*)malloc(8);
			*(class LocalPlayer**)params = ExistingPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		void NotifyPlayerAdded(int PlayerIndex, class LocalPlayer* AddedPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.NotifyPlayerAdded");
			byte* params = (byte*)malloc(8);
			*(int*)params = PlayerIndex;
			*(class LocalPlayer**)(params + 4) = AddedPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool RemovePlayer(class LocalPlayer* ExPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.RemovePlayer");
			byte* params = (byte*)malloc(8);
			*(class LocalPlayer**)params = ExPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void NotifyPlayerRemoved(int PlayerIndex, class LocalPlayer* RemovedPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.NotifyPlayerRemoved");
			byte* params = (byte*)malloc(8);
			*(int*)params = PlayerIndex;
			*(class LocalPlayer**)(params + 4) = RemovedPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class LocalPlayer* FindPlayerByControllerId(int ControllerId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.FindPlayerByControllerId");
			byte* params = (byte*)malloc(8);
			*(int*)params = ControllerId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class LocalPlayer**)(params + 4);
			free(params);
			return returnVal;
		}
		bool CreateViewportConsole(ScriptClass* vpcClass, ScriptArray<wchar_t>& OutError)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.CreateViewportConsole");
			byte* params = (byte*)malloc(20);
			*(ScriptClass**)params = vpcClass;
			*(ScriptArray<wchar_t>*)(params + 4) = OutError;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutError = *(ScriptArray<wchar_t>*)(params + 4);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool Init(ScriptArray<wchar_t>& OutError)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.Init");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = OutError;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutError = *(ScriptArray<wchar_t>*)params;
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool CreateInitialPlayer(ScriptArray<wchar_t>& OutError)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.CreateInitialPlayer");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = OutError;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutError = *(ScriptArray<wchar_t>*)params;
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		int InsertInteraction(class Interaction* NewInteraction, int InIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.InsertInteraction");
			byte* params = (byte*)malloc(12);
			*(class Interaction**)params = NewInteraction;
			*(int*)(params + 4) = InIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		void GameSessionEnded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.GameSessionEnded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetSplitscreenConfiguration(byte SplitType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.SetSplitscreenConfiguration");
			byte* params = (byte*)malloc(1);
			*params = SplitType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		byte GetSplitscreenConfiguration()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.GetSplitscreenConfiguration");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
		void UpdateActiveSplitscreenType()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.UpdateActiveSplitscreenType");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LayoutPlayers()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.LayoutPlayers");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GetSubtitleRegion(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void*& MinPos, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void*& MaxPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.GetSubtitleRegion");
			byte* params = (byte*)malloc(16);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)params = MinPos;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 8) = MaxPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			MinPos = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)params;
			MaxPos = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 8);
			free(params);
		}
		int ConvertLocalPlayerToGamePlayerIndex(class LocalPlayer* LPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.ConvertLocalPlayerToGamePlayerIndex");
			byte* params = (byte*)malloc(8);
			*(class LocalPlayer**)params = LPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		bool HasTopSafeZone(int LocalPlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.HasTopSafeZone");
			byte* params = (byte*)malloc(8);
			*(int*)params = LocalPlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool HasBottomSafeZone(int LocalPlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.HasBottomSafeZone");
			byte* params = (byte*)malloc(8);
			*(int*)params = LocalPlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool HasLeftSafeZone(int LocalPlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.HasLeftSafeZone");
			byte* params = (byte*)malloc(8);
			*(int*)params = LocalPlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool HasRightSafeZone(int LocalPlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.HasRightSafeZone");
			byte* params = (byte*)malloc(8);
			*(int*)params = LocalPlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void GetPixelSizeOfScreen(float& out_Width, float& out_Height, class Canvas* Canvas, int LocalPlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.GetPixelSizeOfScreen");
			byte* params = (byte*)malloc(16);
			*(float*)params = out_Width;
			*(float*)(params + 4) = out_Height;
			*(class Canvas**)(params + 8) = Canvas;
			*(int*)(params + 12) = LocalPlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_Width = *(float*)params;
			out_Height = *(float*)(params + 4);
			free(params);
		}
		void CalculateSafeZoneValues(float& out_Horizontal, float& out_Vertical, class Canvas* Canvas, int LocalPlayerIndex, bool bUseMaxPercent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.CalculateSafeZoneValues");
			byte* params = (byte*)malloc(20);
			*(float*)params = out_Horizontal;
			*(float*)(params + 4) = out_Vertical;
			*(class Canvas**)(params + 8) = Canvas;
			*(int*)(params + 12) = LocalPlayerIndex;
			*(bool*)(params + 16) = bUseMaxPercent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_Horizontal = *(float*)params;
			out_Vertical = *(float*)(params + 4);
			free(params);
		}
		bool CalculateDeadZoneForAllSides(class LocalPlayer* LPlayer, class Canvas* Canvas, float& fTopSafeZone, float& fBottomSafeZone, float& fLeftSafeZone, float& fRightSafeZone, bool bUseMaxPercent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.CalculateDeadZoneForAllSides");
			byte* params = (byte*)malloc(32);
			*(class LocalPlayer**)params = LPlayer;
			*(class Canvas**)(params + 4) = Canvas;
			*(float*)(params + 8) = fTopSafeZone;
			*(float*)(params + 12) = fBottomSafeZone;
			*(float*)(params + 16) = fLeftSafeZone;
			*(float*)(params + 20) = fRightSafeZone;
			*(bool*)(params + 24) = bUseMaxPercent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			fTopSafeZone = *(float*)(params + 8);
			fBottomSafeZone = *(float*)(params + 12);
			fLeftSafeZone = *(float*)(params + 16);
			fRightSafeZone = *(float*)(params + 20);
			auto returnVal = *(bool*)(params + 28);
			free(params);
			return returnVal;
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawTitleSafeArea(class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.DrawTitleSafeArea");
			byte* params = (byte*)malloc(4);
			*(class Canvas**)params = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostRender(class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.PostRender");
			byte* params = (byte*)malloc(4);
			*(class Canvas**)params = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DisplayProgressMessage(class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.DisplayProgressMessage");
			byte* params = (byte*)malloc(4);
			*(class Canvas**)params = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawTransition(class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.DrawTransition");
			byte* params = (byte*)malloc(4);
			*(class Canvas**)params = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawTransitionMessage(class Canvas* Canvas, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.DrawTransitionMessage");
			byte* params = (byte*)malloc(16);
			*(class Canvas**)params = Canvas;
			*(ScriptArray<wchar_t>*)(params + 4) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetProgressMessage(byte MessageType, ScriptArray<wchar_t> Message, ScriptArray<wchar_t> Title, bool bIgnoreFutureNetworkMessages)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.SetProgressMessage");
			byte* params = (byte*)malloc(29);
			*params = MessageType;
			*(ScriptArray<wchar_t>*)(params + 4) = Message;
			*(ScriptArray<wchar_t>*)(params + 16) = Title;
			*(bool*)(params + 28) = bIgnoreFutureNetworkMessages;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyConnectionError(ScriptArray<wchar_t> Message, ScriptArray<wchar_t> Title)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.NotifyConnectionError");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Message;
			*(ScriptArray<wchar_t>*)(params + 12) = Title;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetProgressTime(float T)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.SetProgressTime");
			byte* params = (byte*)malloc(4);
			*(float*)params = T;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearProgressMessages()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.ClearProgressMessages");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class LocalPlayer* GetPlayerOwner(int PlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.GetPlayerOwner");
			byte* params = (byte*)malloc(8);
			*(int*)params = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class LocalPlayer**)(params + 4);
			free(params);
			return returnVal;
		}
		void FixupOwnerReferences()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.FixupOwnerReferences");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnPrimaryPlayerSwitch(class LocalPlayer* OldPrimaryPlayer, class LocalPlayer* NewPrimaryPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.OnPrimaryPlayerSwitch");
			byte* params = (byte*)malloc(8);
			*(class LocalPlayer**)params = OldPrimaryPlayer;
			*(class LocalPlayer**)(params + 4) = NewPrimaryPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BecomePrimaryPlayer(int PlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.BecomePrimaryPlayer");
			byte* params = (byte*)malloc(4);
			*(int*)params = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DebugSetUISystemEnabled(bool bOldUISystemActive, bool bGFxUISystemActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameViewportClient.DebugSetUISystemEnabled");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bOldUISystemActive;
			*(bool*)(params + 4) = bGFxUISystemActive;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT