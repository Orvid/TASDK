#pragma once
#include "GameFramework__GameCrowdForcePoint.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameCrowdAttractor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GameCrowdAttractor : public GameCrowdForcePoint
	{
	public:
		ADD_VAR(::BoolProperty, bAttractionFalloff, 0x1)
		ADD_VAR(::FloatProperty, Attraction, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
