#pragma once
#include "Engine.Light.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.StaticLightCollectionActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class StaticLightCollectionActor : public Light
	{
	public:
		ADD_VAR(::IntProperty, MaxLightComponents, 0xFFFFFFFF)
	};
}
#undef ADD_VAR