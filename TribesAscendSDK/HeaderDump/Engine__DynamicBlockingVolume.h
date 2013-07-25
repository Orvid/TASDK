#pragma once
#include "Engine__BlockingVolume.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DynamicBlockingVolume." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DynamicBlockingVolume : public BlockingVolume
	{
	public:
		ADD_VAR(::BoolProperty, bEnabled, 0x1)
	};
}
#undef ADD_VAR
