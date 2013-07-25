#pragma once
#include "Engine.Canvas.h"
#include "UTGame.UTPlayerReplicationInfo.h"
#include "UDKBase.UDKCarriedObject.h"
#include "Engine.ForceFeedbackWaveform.h"
#include "Engine.PlayerController.h"
#include "Engine.Texture2D.h"
#include "Engine.Pawn.h"
#include "Engine.SoundCue.h"
#include "Engine.Controller.h"
#include "UTGame.UTMapInfo.h"
#include "UTGame.UTPlayerController.h"
#include "UTGame.UTGameObjective.h"
#include "Engine.Actor.h"
#include "UDKBase.UDKGameObjective.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTCarriedObject." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTCarriedObject." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTCarriedObject." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTCarriedObject : public UDKCarriedObject
	{
	public:
		ADD_VAR(::NameProperty, GameObjBone3P, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, GameObjRot3P, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, GameObjOffset3P, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, GameObjRot1P, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, GameObjOffset1P, 0xFFFFFFFF)
		ADD_OBJECT(ForceFeedbackWaveform, PickUpWaveForm)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'GoldColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'BlueColor'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'RedColor'!
		ADD_VAR(::IntProperty, LastSeeMessageIndex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastFlagSeeTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastHighlightUpdate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HighlightSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxHighlightScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HighlightScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DefaultHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DefaultRadius, 0xFFFFFFFF)
		ADD_OBJECT(Pawn, OldHolder)
		ADD_OBJECT(SoundCue, ReturnedSound)
		ADD_OBJECT(SoundCue, DroppedSound)
		ADD_OBJECT(SoundCue, PickupSound)
		ADD_OBJECT(Texture2D, IconTexture)
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'IconCoords'!
		ADD_VAR(::FloatProperty, MapSize, 0xFFFFFFFF)
		ADD_OBJECT(Controller, FirstTouch)
		ADD_VAR(::FloatProperty, MaxDropTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TakenTime, 0xFFFFFFFF)
		ADD_OBJECT(Pawn, Holder)
		ADD_OBJECT(UTPlayerReplicationInfo, HolderPRI)
		ADD_VAR(::FloatProperty, TossDistance, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bUseTeamColorForIcon, 0x4)
		ADD_VAR(::BoolProperty, bLeavingDroppedState, 0x2)
		ADD_VAR(::BoolProperty, bLastSecondSave, 0x1)
		bool FlagUse(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.FlagUse");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldMinimapRenderFor(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.ShouldMinimapRenderFor");
			byte* params = (byte*)malloc(8);
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void HighlightOnMinimap(int Switch)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.HighlightOnMinimap");
			byte* params = (byte*)malloc(4);
			*(int*)params = Switch;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Texture2D* GetIconTexture()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.GetIconTexture");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Texture2D**)params;
			free(params);
			return returnVal;
		}
		void DrawIcon(class Canvas* Canvas, Vector IconLocation, float IconWidth, float IconAlpha)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.DrawIcon");
			byte* params = (byte*)malloc(24);
			*(class Canvas**)params = Canvas;
			*(Vector*)(params + 4) = IconLocation;
			*(float*)(params + 16) = IconWidth;
			*(float*)(params + 20) = IconAlpha;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RenderMapIcon(class UTMapInfo* MP, class Canvas* Canvas, class UTPlayerController* PlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.RenderMapIcon");
			byte* params = (byte*)malloc(12);
			*(class UTMapInfo**)params = MP;
			*(class Canvas**)(params + 4) = Canvas;
			*(class UTPlayerController**)(params + 8) = PlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RenderEnemyMapIcon(class UTMapInfo* MP, class Canvas* Canvas, class UTPlayerController* PlayerOwner, class UTGameObjective* NearbyObjective)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.RenderEnemyMapIcon");
			byte* params = (byte*)malloc(16);
			*(class UTMapInfo**)params = MP;
			*(class Canvas**)(params + 4) = Canvas;
			*(class UTPlayerController**)(params + 8) = PlayerOwner;
			*(class UTGameObjective**)(params + 12) = NearbyObjective;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetHolder(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.SetHolder");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SendFlagMessage(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.SendFlagMessage");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Score()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.Score");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Drop(class Controller* Killer, bool bNoThrow)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.Drop");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = Killer;
			*(bool*)(params + 4) = bNoThrow;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SendHome(class Controller* Returner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.SendHome");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = Returner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void KismetSendHome()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.KismetSendHome");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BroadcastReturnedMessage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.BroadcastReturnedMessage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BroadcastDroppedMessage(class Controller* EventInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.BroadcastDroppedMessage");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BroadcastTakenFromBaseMessage(class Controller* EventInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.BroadcastTakenFromBaseMessage");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BroadcastTakenDroppedMessage(class Controller* EventInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.BroadcastTakenDroppedMessage");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CalcSetHome()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.CalcSetHome");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearHolder()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.ClearHolder");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Actor* Position()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.Position");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)params;
			free(params);
			return returnVal;
		}
		bool ValidHolder(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.ValidHolder");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.Touch");
			byte* params = (byte*)malloc(32);
			*(class Actor**)params = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4) = OtherComp;
			*(Vector*)(params + 8) = HitLocation;
			*(Vector*)(params + 20) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.FellOutOfWorld");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientReturnedHome()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.ClientReturnedHome");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotReachableBy(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.NotReachableBy");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Landed(Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.Landed");
			byte* params = (byte*)malloc(16);
			*(Vector*)params = HitNormal;
			*(class Actor**)(params + 12) = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class UDKGameObjective* GetKismetEventObjective()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.GetKismetEventObjective");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UDKGameObjective**)params;
			free(params);
			return returnVal;
		}
		void LogTaken(class Controller* EventInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.LogTaken");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LogReturned(class Controller* EventInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.LogReturned");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LogDropped(class Controller* EventInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.LogDropped");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = EventInstigator;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CheckTouching()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.CheckTouching");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AutoSendHome()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.AutoSendHome");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckFit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.CheckFit");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckPain()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCarriedObject.CheckPain");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT