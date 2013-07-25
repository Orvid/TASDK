#pragma once
#include "Engine.SoundCue.h"
#include "TribesGame.TrInventory.h"
#include "Engine.Pawn.h"
#include "Engine.Canvas.h"
#include "Engine.HUD.h"
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrTimedPowerup." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrTimedPowerup." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrTimedPowerup." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrTimedPowerup : public TrInventory
	{
	public:
		ADD_VAR(::FloatProperty, PP_Scene_Desaturation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, PP_Scene_HighLights, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WarningTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TransitionDuration, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TransitionTime, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.TextureCoordinates' for the property named 'IconCoords'!
		ADD_VAR(::NameProperty, PowerupStatName, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, PowerupOverSound)
		ADD_VAR(::IntProperty, HudIndex, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TimeRemaining, 0xFFFFFFFF)
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTimedPowerup.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GivenTo(class Pawn* NewOwner, bool bDoNotActivate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTimedPowerup.GivenTo");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = NewOwner;
			*(bool*)(params + 4) = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientGivenTo(class Pawn* NewOwner, bool bDoNotActivate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTimedPowerup.ClientGivenTo");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = NewOwner;
			*(bool*)(params + 4) = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AdjustPPEffects(class Pawn* P, bool bRemove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTimedPowerup.AdjustPPEffects");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			*(bool*)(params + 4) = bRemove;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientLostItem()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTimedPowerup.ClientLostItem");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientSetTimeRemaining(float NewTimeRemaining)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTimedPowerup.ClientSetTimeRemaining");
			byte* params = (byte*)malloc(4);
			*(float*)params = NewTimeRemaining;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TimeRemaingUpdated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTimedPowerup.TimeRemaingUpdated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisplayPowerup(class Canvas* Canvas, class HUD* HUD, float ResolutionScale, float& YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTimedPowerup.DisplayPowerup");
			byte* params = (byte*)malloc(16);
			*(class Canvas**)params = Canvas;
			*(class HUD**)(params + 4) = HUD;
			*(float*)(params + 8) = ResolutionScale;
			*(float*)(params + 12) = YPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			YPos = *(float*)(params + 12);
			free(params);
		}
		bool DenyPickupQuery(ScriptClass* ItemClass, class Actor* Pickup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTimedPowerup.DenyPickupQuery");
			byte* params = (byte*)malloc(12);
			*(ScriptClass**)params = ItemClass;
			*(class Actor**)(params + 4) = Pickup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void TimeExpired()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTimedPowerup.TimeExpired");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float BotDesireability(class Actor* PickupHolder, class Pawn* P, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTimedPowerup.BotDesireability");
			byte* params = (byte*)malloc(16);
			*(class Actor**)params = PickupHolder;
			*(class Pawn**)(params + 4) = P;
			*(class Controller**)(params + 8) = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		float DetourWeight(class Pawn* Other, float PathWeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTimedPowerup.DetourWeight");
			byte* params = (byte*)malloc(12);
			*(class Pawn**)params = Other;
			*(float*)(params + 4) = PathWeight;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		ScriptName GetPowerupStatName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrTimedPowerup.GetPowerupStatName");
			byte* params = (byte*)malloc(8);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
