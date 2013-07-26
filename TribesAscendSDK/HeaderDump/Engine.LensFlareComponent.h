#pragma once
#include "Core.Object.Pointer.h"
#include "Engine.PrimitiveComponent.h"
#include "Core.Object.LinearColor.h"
#include "Engine.LensFlare.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.LensFlareComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.LensFlareComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.LensFlareComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class LensFlareComponent : public PrimitiveComponent
	{
	public:
		ADD_VAR(::FloatProperty, NextTraceTime, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, ReleaseResourcesFence, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<LinearColor>, SourceColor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Radius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ConeFudgeFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InnerCone, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OuterCone, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bVisibleForMobile, 0x40)
		ADD_VAR(::BoolProperty, bUsesSceneColor, 0x20)
		ADD_VAR(::BoolProperty, bHasUnlitDistortion, 0x10)
		ADD_VAR(::BoolProperty, bHasUnlitTranslucency, 0x8)
		ADD_VAR(::BoolProperty, bHasTranslucency, 0x4)
		ADD_VAR(::BoolProperty, bIsActive, 0x2)
		ADD_VAR(::BoolProperty, bAutoActivate, 0x1)
		ADD_OBJECT(LensFlare, Template)
		void SetTemplate(class LensFlare* NewTemplate, bool bForceSet)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LensFlareComponent.SetTemplate");
			byte* params = (byte*)malloc(8);
			*(class LensFlare**)params = NewTemplate;
			*(bool*)(params + 4) = bForceSet;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSourceColor(LinearColor InSourceColor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LensFlareComponent.SetSourceColor");
			byte* params = (byte*)malloc(16);
			*(LinearColor*)params = InSourceColor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetIsActive(bool bInIsActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.LensFlareComponent.SetIsActive");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bInIsActive;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
