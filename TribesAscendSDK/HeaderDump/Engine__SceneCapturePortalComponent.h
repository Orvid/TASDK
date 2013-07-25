#pragma once
#include "Engine__SceneCaptureComponent.h"
#include "Engine__Actor.h"
#include "Engine__TextureRenderTarget2D.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SceneCapturePortalComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SceneCapturePortalComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SceneCapturePortalComponent : public SceneCaptureComponent
	{
	public:
		ADD_OBJECT(Actor, ViewDestination)
		ADD_VAR(::FloatProperty, ScaleFOV, 0xFFFFFFFF)
		ADD_OBJECT(TextureRenderTarget2D, TextureTarget)
		// Here lies the not-yet-implemented method 'SetCaptureParameters'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
