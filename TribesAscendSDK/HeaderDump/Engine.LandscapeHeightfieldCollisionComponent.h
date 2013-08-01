#pragma once
#include "Core.Object.Pointer.h"
#include "Core.Object.BoxSphereBounds.h"
#include "Engine.PrimitiveComponent.h"
#include "Core.Object.UntypedBulkData_Mirror.h"
#include "Engine.PhysicalMaterial.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class LandscapeHeightfieldCollisionComponent : public PrimitiveComponent
	{
	public:
		ADD_STRUCT(ScriptArray<byte>, CollisionQuadFlags, 556)
		ADD_STRUCT(ScriptArray<class PhysicalMaterial*>, PhysicalMaterials, 568)
		ADD_STRUCT(Object__BoxSphereBounds, CachedBoxSphereBounds, 584)
		ADD_STRUCT(Object__Pointer, RBHeightfield, 580)
		ADD_STRUCT(float, CollisionScale, 552)
		ADD_STRUCT(int, CollisionSizeQuads, 548)
		ADD_STRUCT(int, SectionBaseY, 544)
		ADD_STRUCT(int, SectionBaseX, 540)
		ADD_STRUCT(Object__UntypedBulkData_Mirror, CollisionHeightData, 488)
	};
}
#undef ADD_STRUCT
