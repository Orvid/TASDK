#pragma once
namespace UnrealScript
{
	class FractureMaterial;
}
#include "Core.Object.h"
#include "Engine.ParticleSystem.h"
#include "Engine.SoundCue.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class FractureMaterial : public Object
	{
	public:
		ADD_OBJECT(SoundCue, FractureSound, 64)
		ADD_OBJECT(ParticleSystem, FractureEffect, 60)
	};
}
#undef ADD_OBJECT
