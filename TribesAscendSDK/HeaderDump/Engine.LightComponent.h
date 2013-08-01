#pragma once
#include "Engine.ActorComponent.h"
#include "Engine.LightComponent.ELightAffectsClassification.h"
#include "Core.Object.Color.h"
#include "Engine.Brush.h"
#include "Engine.LightFunction.h"
#include "Engine.Texture2D.h"
#include "Core.Object.Pointer.h"
#include "Core.Object.Guid.h"
#include "Engine.LightComponent.LightingChannelContainer.h"
#include "Core.Object.Matrix.h"
#include "Engine.LightComponent.ELightShadowMode.h"
#include "Core.Object.LinearColor.h"
#include "Engine.LightComponent.EShadowProjectionTechnique.h"
#include "Core.Object.Vector.h"
#include "Engine.LightComponent.EShadowFilterQuality.h"
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
	class LightComponent : public ActorComponent
	{
	public:
		ADD_STRUCT(float, Brightness, 256)
		ADD_STRUCT(Object__Color, LightColor, 260)
		ADD_OBJECT(LightFunction, Function, 264)
		ADD_STRUCT(Object__Pointer, SceneInfo, 88)
		ADD_STRUCT(Object__Matrix, WorldToLight, 96)
		ADD_STRUCT(Object__Matrix, LightToWorld, 160)
		ADD_STRUCT(Object__Guid, LightGuid, 224)
		ADD_STRUCT(Object__Guid, LightmapGuid, 240)
		ADD_STRUCT(float, LightEnv_BouncedLightBrightness, 268)
		ADD_STRUCT(Object__Color, LightEnv_BouncedModulationColor, 272)
		ADD_BOOL(bEnabled, 276, 0x1)
		ADD_BOOL(CastShadows, 276, 0x2)
		ADD_BOOL(CastStaticShadows, 276, 0x4)
		ADD_BOOL(CastDynamicShadows, 276, 0x8)
		ADD_BOOL(bCastCompositeShadow, 276, 0x10)
		ADD_BOOL(bAffectCompositeShadowDirection, 276, 0x20)
		ADD_BOOL(bNonModulatedSelfShadowing, 276, 0x40)
		ADD_BOOL(bSelfShadowOnly, 276, 0x80)
		ADD_BOOL(bAllowPreShadow, 276, 0x100)
		ADD_BOOL(bForceDynamicLight, 276, 0x200)
		ADD_BOOL(UseDirectLightMap, 276, 0x400)
		ADD_BOOL(bHasLightEverBeenBuiltIntoLightMap, 276, 0x800)
		ADD_BOOL(bOnlyAffectSameAndSpecifiedLevels, 276, 0x1000)
		ADD_BOOL(bCanAffectDynamicPrimitivesOutsideDynamicChannel, 276, 0x2000)
		ADD_BOOL(bUseVolumes, 276, 0x4000)
		ADD_BOOL(bRenderLightShafts, 276, 0x8000)
		ADD_BOOL(bUseImageReflectionSpecular, 276, 0x10000)
		ADD_BOOL(bPrecomputedLightingIsValid, 276, 0x20000)
		ADD_BOOL(bExplicitlyAssignedLight, 276, 0x40000)
		ADD_STRUCT(ScriptArray<ScriptName>, OtherLevelsToAffect, 284)
		ADD_STRUCT(LightComponent__LightingChannelContainer, LightingChannels, 296)
		ADD_STRUCT(ScriptArray<class Brush*>, InclusionVolumes, 300)
		ADD_STRUCT(ScriptArray<class Brush*>, ExclusionVolumes, 312)
		ADD_STRUCT(ScriptArray<Object__Pointer>, InclusionConvexVolumes, 324)
		ADD_STRUCT(ScriptArray<Object__Pointer>, ExclusionConvexVolumes, 336)
		ADD_STRUCT(LightComponent__ELightAffectsClassification, LightAffectsClassification, 348)
		ADD_STRUCT(LightComponent__ELightShadowMode, LightShadowMode, 349)
		ADD_STRUCT(Object__LinearColor, ModShadowColor, 352)
		ADD_STRUCT(float, ModShadowFadeoutTime, 368)
		ADD_STRUCT(float, ModShadowFadeoutExponent, 372)
		ADD_STRUCT(int, LightListIndex, 376)
		ADD_STRUCT(LightComponent__EShadowProjectionTechnique, ShadowProjectionTechnique, 380)
		ADD_STRUCT(LightComponent__EShadowFilterQuality, ShadowFilterQuality, 381)
		ADD_STRUCT(int, MinShadowResolution, 384)
		ADD_STRUCT(int, MaxShadowResolution, 388)
		ADD_STRUCT(int, ShadowFadeResolution, 392)
		ADD_STRUCT(float, OcclusionDepthRange, 396)
		ADD_STRUCT(float, BloomScale, 400)
		ADD_STRUCT(float, BloomThreshold, 404)
		ADD_STRUCT(float, BloomScreenBlendThreshold, 408)
		ADD_STRUCT(Object__Color, BloomTint, 412)
		ADD_STRUCT(float, RadialBlurPercent, 416)
		ADD_STRUCT(float, OcclusionMaskDarkness, 420)
		ADD_OBJECT(Texture2D, ReflectionTexture, 424)
		ADD_STRUCT(float, ReflectionScale, 428)
		void SetEnabled(bool bSetEnabled)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11644);
			byte params[4] = { NULL };
			*(bool*)params = bSetEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetLightProperties(float NewBrightness, Object__Color NewLightColor, class LightFunction* NewLightFunction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11647);
			byte params[12] = { NULL };
			*(float*)params = NewBrightness;
			*(Object__Color*)&params[4] = NewLightColor;
			*(class LightFunction**)&params[8] = NewLightFunction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Vector GetOrigin()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11654);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)params;
		}
		Vector GetDirection()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11656);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)params;
		}
		void UpdateColorAndBrightness()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11658);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateLightShaftParameters()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11659);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnUpdatePropertyBloomScale()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11660);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnUpdatePropertyBloomTint()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11661);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnUpdatePropertyOcclusionMaskDarkness()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11662);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnUpdatePropertyBrightness()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11663);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnUpdatePropertyLightColor()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11664);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
