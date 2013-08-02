#pragma once
namespace UnrealScript
{
	struct TrSkin__SkinStruct;
}
#include "Engine.ParticleSystem.h"
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
	struct TrSkin__SkinStruct
	{
	public:
		ADD_STRUCT(int, skinId, 0)
		ADD_STRUCT(ScriptString*, SkinContentPath3p, 16)
		ADD_STRUCT(ScriptString*, SkinContentPath1p, 4)
		ADD_OBJECT(ParticleSystem, JetpackThrustTemplate, 36)
		ADD_OBJECT(ParticleSystem, JetpackRibbonTemplate, 32)
		ADD_OBJECT(ParticleSystem, SkiThrustTemplate, 28)
		ADD_STRUCT(ScriptArray<ScriptName>, JetpackThrustEffectSockets, 40)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
