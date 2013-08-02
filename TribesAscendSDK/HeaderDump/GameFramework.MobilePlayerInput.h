#pragma once
namespace UnrealScript
{
	class MobilePlayerInput;
}
#include "Core.Object.EInputEvent.h"
#include "Core.Object.Vector2D.h"
#include "Engine.Actor.ETravelType.h"
#include "Engine.Canvas.h"
#include "Engine.PlayerInput.h"
#include "GameFramework.MobileInputZone.h"
#include "GameFramework.MobileInputZone.EZoneTouchEvent.h"
#include "GameFramework.MobileMenuObject.h"
#include "GameFramework.MobileMenuScene.h"
#include "GameFramework.MobilePlayerInput.EUIOrientation.h"
#include "GameFramework.MobilePlayerInput.MobileInputGroup.h"
#include "GameFramework.MobilePlayerInput.MobileInputZoneClassMap.h"
#include "GameFramework.MobilePlayerInput.TouchData.h"
#include "GameFramework.MobilePlayerInput.TouchDataEvent.h"
#include "GameFramework.SeqEvent_MobileBase.h"
#include "GameFramework.SeqEvent_MobileRawInput.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class MobilePlayerInput : public PlayerInput
	{
	public:
		typedef MobilePlayerInput__EUIOrientation EUIOrientation;
		typedef MobilePlayerInput__TouchData TouchData;
		typedef MobilePlayerInput__MobileInputGroup MobileInputGroup;
		typedef MobilePlayerInput__MobileInputZoneClassMap MobileInputZoneClassMap;
		typedef MobilePlayerInput__TouchDataEvent TouchDataEvent;
		static const auto NumTouchDataEntries = 5;
		ADD_STRUCT(Vector, DeviceAccelerometerRawData, 928)
		ADD_BOOL(bDeviceHasGyroscope, 764, 0x10)
		ADD_STRUCT(Vector, DeviceGyroRawData, 916)
		ADD_STRUCT(Vector, DeviceMotionAttitude, 844)
		ADD_STRUCT(Vector, DeviceMotionRotationRate, 856)
		ADD_STRUCT(Vector, DeviceMotionGravity, 868)
		ADD_STRUCT(Vector, DeviceMotionAcceleration, 880)
		ADD_STRUCT(MobilePlayerInput__TouchData, Touches, 380)
		ADD_STRUCT(float, MobileYaw, 780)
		ADD_STRUCT(float, MobileYawCenter, 784)
		ADD_STRUCT(float, MobileYawMultiplier, 788)
		ADD_STRUCT(float, MobilePitch, 768)
		ADD_STRUCT(float, MobilePitchCenter, 772)
		ADD_STRUCT(float, MobilePitchMultiplier, 776)
		ADD_STRUCT(ScriptArray<MobilePlayerInput__MobileInputGroup>, MobileInputGroups, 724)
		ADD_STRUCT(ScriptArray<class MobileInputZone*>, MobileInputZones, 740)
		ADD_STRUCT(ScriptArray<MobilePlayerInput__MobileInputZoneClassMap>, MobileInputZoneClasses, 752)
		ADD_STRUCT(ScriptArray<class MobileMenuScene*>, MobileMenuStack, 816)
		ADD_STRUCT(ScriptArray<class SeqEvent_MobileBase*>, MobileSeqEventHandlers, 892)
		ADD_STRUCT(ScriptArray<class SeqEvent_MobileRawInput*>, MobileRawInputSeqEventHandlers, 904)
		ADD_STRUCT(float, MobileInactiveTime, 840)
		ADD_STRUCT(ScriptString*, NativeDebugString, 828)
		ADD_STRUCT(float, ZoneTimeout, 812)
		ADD_STRUCT(float, MobileTapRepeatTime, 808)
		ADD_STRUCT(float, MobileMinHoldForTap, 804)
		ADD_STRUCT(float, MobileDoubleTapTime, 800)
		ADD_STRUCT(float, MobileYawDeadzoneSize, 796)
		ADD_STRUCT(float, MobilePitchDeadzoneSize, 792)
		ADD_BOOL(bDeviceHasAccelerometer, 764, 0x20)
		ADD_BOOL(bFakeMobileTouches, 764, 0x8)
		ADD_BOOL(bDisableTouchInput, 764, 0x4)
		ADD_BOOL(bAllowTouchesInCinematic, 764, 0x2)
		ADD_BOOL(bSupportsAccelerometer, 764, 0x1)
		ADD_STRUCT(int, CurrentMobileGroup, 736)
		ADD_OBJECT(MobileMenuObject, InteractiveObject, 720)
		bool HasZones()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32366);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		ScriptArray<class MobileInputZone*> GetCurrentZones()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32368);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptArray<class MobileInputZone*>*)params;
		}
		class MobileMenuScene* OpenMenuScene(ScriptClass* SceneClass, ScriptString* Mode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32638);
			byte params[20] = { NULL };
			*(ScriptClass**)params = SceneClass;
			*(ScriptString**)&params[4] = Mode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class MobileMenuScene**)&params[16];
		}
		void OnInputTouch(int Handle, MobileInputZone__EZoneTouchEvent Type, Object__Vector2D TouchLocation, float DeviceTimestamp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32759);
			byte params[17] = { NULL };
			*(int*)params = Handle;
			*(MobileInputZone__EZoneTouchEvent*)&params[4] = Type;
			*(Object__Vector2D*)&params[8] = TouchLocation;
			*(float*)&params[16] = DeviceTimestamp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool OnPreviewTouch(float X, float Y)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32761);
			byte params[12] = { NULL };
			*(float*)params = X;
			*(float*)&params[4] = Y;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void OnTouchNotHandledInMenu()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32763);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnMobileMotion(class PlayerInput* PlayerInput, Vector CurrentAttitude, Vector CurrentRotationRate, Vector CurrentGravity, Vector CurrentAcceleration)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32765);
			byte params[52] = { NULL };
			*(class PlayerInput**)params = PlayerInput;
			*(Vector*)&params[4] = CurrentAttitude;
			*(Vector*)&params[16] = CurrentRotationRate;
			*(Vector*)&params[28] = CurrentGravity;
			*(Vector*)&params[40] = CurrentAcceleration;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NativeInitializeInputSystem()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32798);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NativeInitializeInputZones()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32799);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SendInputKey(ScriptName Key, Object__EInputEvent Event, float AmountDepressed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32800);
			byte params[13] = { NULL };
			*(ScriptName*)params = Key;
			*(Object__EInputEvent*)&params[8] = Event;
			*(float*)&params[12] = AmountDepressed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendInputAxis(ScriptName Key, float Delta, float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32804);
			byte params[16] = { NULL };
			*(ScriptName*)params = Key;
			*(float*)&params[8] = Delta;
			*(float*)&params[12] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitInputSystem()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32808);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientInitInputSystem()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32809);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitTouchSystem()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32810);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitializeInputZones()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32811);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RefreshKismetLinks()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32816);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddKismetEventHandler(class SeqEvent_MobileBase* NewHandler)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32821);
			byte params[4] = { NULL };
			*(class SeqEvent_MobileBase**)params = NewHandler;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddKismetRawInputEventHandler(class SeqEvent_MobileRawInput* NewHandler)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32824);
			byte params[4] = { NULL };
			*(class SeqEvent_MobileRawInput**)params = NewHandler;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class MobileInputZone* FindZone(ScriptString* ZoneName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32827);
			byte params[16] = { NULL };
			*(ScriptString**)params = ZoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class MobileInputZone**)&params[12];
		}
		class MobileInputZone* FindorAddZone(ScriptString* ZoneName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32831);
			byte params[16] = { NULL };
			*(ScriptString**)params = ZoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class MobileInputZone**)&params[12];
		}
		void CloseMenuScene(class MobileMenuScene* SceneToClose)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32842);
			byte params[4] = { NULL };
			*(class MobileMenuScene**)params = SceneToClose;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CloseAllMenus()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32847);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RenderMenus(class Canvas* Canvas, float RenderDelta)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32848);
			byte params[8] = { NULL };
			*(class Canvas**)params = Canvas;
			*(float*)&params[4] = RenderDelta;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PreClientTravel(ScriptString* PendingURL, Actor__ETravelType TravelType, bool bIsSeamlessTravel)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32852);
			byte params[17] = { NULL };
			*(ScriptString**)params = PendingURL;
			*(Actor__ETravelType*)&params[12] = TravelType;
			*(bool*)&params[16] = bIsSeamlessTravel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
