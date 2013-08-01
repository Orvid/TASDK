#pragma once
#include "Engine.MaterialInterface.h"
#include "Engine.Actor.h"
#include "Core.Object.Color.h"
#include "Core.Object.Vector.h"
#include "Engine.ParticleSystemComponent.EParticleSysParamType.h"
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
	struct ParticleSystemComponent__ParticleSysParam
	{
	public:
		ADD_OBJECT(MaterialInterface, Material, 52)
		ADD_OBJECT(Actor, Actor, 48)
		ADD_STRUCT(Object__Color, Color, 44)
		ADD_STRUCT(Vector, Vector_Low, 32)
		ADD_STRUCT(Vector, Vector, 20)
		ADD_STRUCT(float, Scalar_Low, 16)
		ADD_STRUCT(float, Scalar, 12)
		ADD_STRUCT(ParticleSystemComponent__EParticleSysParamType, ParamType, 8)
		ADD_STRUCT(ScriptName, Name, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
