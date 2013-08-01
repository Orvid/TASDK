#pragma once
#include "Core.Object.h"
#include "Core.Object.Color.h"
#include "GameFramework.SeqEvent_MobileZoneBase.h"
#include "GameFramework.MobileInputZone.EZoneSlideType.h"
#include "GameFramework.MobileInputZone.EZoneState.h"
#include "GameFramework.MobileInputZone.EZoneType.h"
#include "Core.Object.Vector2D.h"
#include "Engine.Texture2D.h"
#include "GameFramework.MobileInputZone.TextureUVs.h"
#include "GameFramework.MobilePlayerInput.h"
#include "Engine.Canvas.h"
#include "GameFramework.MobileInputZone.EZoneTouchEvent.h"
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
	class MobileInputZone : public Object
	{
	public:
		ADD_BOOL(bIsInvisible, 128, 0x200)
		ADD_STRUCT(Object__Color, RenderColor, 180)
		ADD_STRUCT(float, AnimatingFadeOpacity, 376)
		ADD_STRUCT(MobileInputZone__EZoneState, State, 61)
		ADD_STRUCT(float, InactiveAlpha, 184)
		ADD_STRUCT(float, TransitionTime, 384)
		ADD_STRUCT(float, ActivateTime, 172)
		ADD_STRUCT(float, DeactivateTime, 176)
		ADD_STRUCT(MobileInputZone__EZoneType, Type, 60)
		ADD_STRUCT(float, X, 132)
		ADD_STRUCT(float, Y, 136)
		ADD_STRUCT(float, SizeX, 140)
		ADD_STRUCT(float, SizeY, 144)
		ADD_OBJECT(Texture2D, OverrideTexture1, 196)
		ADD_STRUCT(MobileInputZone__TextureUVs, OverrideUVs1, 212)
		ADD_OBJECT(Texture2D, OverrideTexture2, 228)
		ADD_STRUCT(MobileInputZone__TextureUVs, OverrideUVs2, 244)
		ADD_STRUCT(float, ActiveSizeX, 148)
		ADD_STRUCT(float, ActiveSizeY, 152)
		ADD_STRUCT(ScriptString*, Caption, 64)
		ADD_STRUCT(float, CaptionXAdjustment, 188)
		ADD_STRUCT(float, CaptionYAdjustment, 192)
		ADD_STRUCT(Object__Vector2D, CurrentCenter, 276)
		ADD_STRUCT(Object__Vector2D, CurrentLocation, 268)
		ADD_BOOL(bRenderGuides, 128, 0x8000)
		ADD_STRUCT(MobileInputZone__EZoneSlideType, SlideType, 62)
		ADD_STRUCT(ScriptArray<class SeqEvent_MobileZoneBase*>, MobileSeqEventHandlers, 396)
		ADD_STRUCT(float, LastWentActiveTime, 420)
		ADD_STRUCT(float, TotalActiveTime, 416)
		ADD_STRUCT(Object__Vector2D, LastAxisValues, 408)
		ADD_STRUCT(Object__Vector2D, EscapeVelocity, 388)
		ADD_OBJECT(MobilePlayerInput, InputOwner, 380)
		ADD_STRUCT(float, TimeSinceLastTapRepeat, 372)
		ADD_STRUCT(float, LastTouchTime, 368)
		ADD_STRUCT(int, PreviousLocationCount, 364)
		ADD_STRUCT(float, PreviousMoveDeltaTimes, 340)
		ADD_STRUCT(Object__Vector2D, PreviousLocations, 292)
		ADD_STRUCT(Object__Vector2D, InitialCenter, 284)
		ADD_STRUCT(Object__Vector2D, InitialLocation, 260)
		ADD_STRUCT(ScriptString*, OverrideTexture2Name, 232)
		ADD_STRUCT(ScriptString*, OverrideTexture1Name, 200)
		ADD_STRUCT(float, TapDistanceConstraint, 168)
		ADD_STRUCT(float, ResetCenterAfterInactivityTime, 164)
		ADD_STRUCT(float, Border, 160)
		ADD_STRUCT(float, AuthoredGlobalScale, 156)
		ADD_BOOL(bIsDoubleTapAndHold, 128, 0x10000)
		ADD_BOOL(bAllowFirstDeltaForTrackballZone, 128, 0x4000)
		ADD_BOOL(bUseGentleTransitions, 128, 0x2000)
		ADD_BOOL(bFloatingTiltZone, 128, 0x1000)
		ADD_BOOL(bCenterOnEvent, 128, 0x800)
		ADD_BOOL(bQuickDoubleTap, 128, 0x400)
		ADD_BOOL(bCenterY, 128, 0x100)
		ADD_BOOL(bCenterX, 128, 0x80)
		ADD_BOOL(bSizeYFromSizeX, 128, 0x40)
		ADD_BOOL(bActiveSizeYFromX, 128, 0x20)
		ADD_BOOL(bRelativeSizeY, 128, 0x10)
		ADD_BOOL(bRelativeSizeX, 128, 0x8)
		ADD_BOOL(bRelativeY, 128, 0x4)
		ADD_BOOL(bRelativeX, 128, 0x2)
		ADD_BOOL(bScalePawnMovement, 128, 0x1)
		ADD_STRUCT(float, EscapeVelocityStrength, 124)
		ADD_STRUCT(float, Smoothing, 120)
		ADD_STRUCT(float, Acceleration, 116)
		ADD_STRUCT(float, HorizMultiplier, 112)
		ADD_STRUCT(float, VertMultiplier, 108)
		ADD_STRUCT(ScriptName, DoubleTapInputKey, 100)
		ADD_STRUCT(ScriptName, TapInputKey, 92)
		ADD_STRUCT(ScriptName, HorizontalInputKey, 84)
		ADD_STRUCT(ScriptName, InputKey, 76)
		bool OnPreDrawZone(class MobileInputZone* Zone, class Canvas* Canvas)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32378);
			byte params[12] = { NULL };
			*(class MobileInputZone**)params = Zone;
			*(class Canvas**)&params[4] = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void OnPostDrawZone(class MobileInputZone* Zone, class Canvas* Canvas)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32471);
			byte params[8] = { NULL };
			*(class MobileInputZone**)params = Zone;
			*(class Canvas**)&params[4] = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool OnProcessSlide(class MobileInputZone* Zone, MobileInputZone__EZoneTouchEvent EventType, int SlideValue, Object__Vector2D ViewportSize)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32473);
			byte params[21] = { NULL };
			*(class MobileInputZone**)params = Zone;
			*(MobileInputZone__EZoneTouchEvent*)&params[4] = EventType;
			*(int*)&params[8] = SlideValue;
			*(Object__Vector2D*)&params[12] = ViewportSize;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		bool OnDoubleTapDelegate(class MobileInputZone* Zone, MobileInputZone__EZoneTouchEvent EventType, Object__Vector2D TouchLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32475);
			byte params[17] = { NULL };
			*(class MobileInputZone**)params = Zone;
			*(MobileInputZone__EZoneTouchEvent*)&params[4] = EventType;
			*(Object__Vector2D*)&params[8] = TouchLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool OnTapDelegate(class MobileInputZone* Zone, MobileInputZone__EZoneTouchEvent EventType, Object__Vector2D TouchLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32477);
			byte params[17] = { NULL };
			*(class MobileInputZone**)params = Zone;
			*(MobileInputZone__EZoneTouchEvent*)&params[4] = EventType;
			*(Object__Vector2D*)&params[8] = TouchLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool OnProcessInputDelegate(class MobileInputZone* Zone, float DeltaTime, int Handle, MobileInputZone__EZoneTouchEvent EventType, Object__Vector2D TouchLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32479);
			byte params[25] = { NULL };
			*(class MobileInputZone**)params = Zone;
			*(float*)&params[4] = DeltaTime;
			*(int*)&params[8] = Handle;
			*(MobileInputZone__EZoneTouchEvent*)&params[12] = EventType;
			*(Object__Vector2D*)&params[16] = TouchLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		void ActivateZone()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32522);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DeactivateZone()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32523);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddKismetEventHandler(class SeqEvent_MobileZoneBase* NewHandler)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32547);
			byte params[4] = { NULL };
			*(class SeqEvent_MobileZoneBase**)params = NewHandler;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
