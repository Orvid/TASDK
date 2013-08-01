#pragma once
#include "Engine.MaterialInterface.h"
#include "Engine.ParticleSystem.h"
#include "Engine.SoundCue.h"
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
	struct UDKPawn__MaterialImpactEffect
	{
	public:
		ADD_STRUCT(ScriptArray<class MaterialInterface*>, DecalMaterials, 12)
		ADD_OBJECT(ParticleSystem, ParticleTemplate, 44)
		ADD_STRUCT(float, DecalHeight, 40)
		ADD_STRUCT(float, DecalWidth, 36)
		ADD_STRUCT(ScriptName, DecalDissolveParamName, 28)
		ADD_STRUCT(float, DurationOfDecal, 24)
		ADD_OBJECT(SoundCue, Sound, 8)
		ADD_STRUCT(ScriptName, MaterialType, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
