#pragma once
#include "Engine.PhysicalMaterial.h"
#include "Core.Object.Vector.h"
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
	struct Actor__RigidBodyContactInfo
	{
	public:
		ADD_OBJECT(PhysicalMaterial, PhysMaterial, 52)
		ADD_STRUCT(Vector, ContactVelocity, 28)
		ADD_STRUCT(float, ContactPenetration, 24)
		ADD_STRUCT(Vector, ContactNormal, 12)
		ADD_STRUCT(Vector, ContactPosition, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
