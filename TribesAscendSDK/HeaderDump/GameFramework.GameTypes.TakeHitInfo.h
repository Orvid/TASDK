#pragma once
#include "Core.Object.Vector.h"
#include "Engine.Pawn.h"
#include "Engine.PhysicalMaterial.h"
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
	struct GameTypes__TakeHitInfo
	{
	public:
		ADD_STRUCT(Vector, HitLocation, 0)
		ADD_STRUCT(Vector, Momentum, 12)
		ADD_OBJECT(ScriptClass, DamageType, 24)
		ADD_OBJECT(Pawn, InstigatedBy, 28)
		ADD_STRUCT(byte, HitBoneIndex, 32)
		ADD_OBJECT(PhysicalMaterial, PhysicalMaterial, 36)
		ADD_STRUCT(float, Damage, 40)
		ADD_STRUCT(Vector, RadialDamageOrigin, 44)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
