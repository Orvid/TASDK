#pragma once
#include "Core.Object.Pointer.h"
#include "Engine.PrimitiveComponent.h"
#include "Engine.Model.h"
#include "Engine.BrushComponent.KCachedConvexData_Mirror.h"
#include "Engine.KMeshProps.KAggregateGeom.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	class BrushComponent : public PrimitiveComponent
	{
	public:
		ADD_BOOL(bBlockComplexCollisionTrace, 568, 0x1)
		ADD_STRUCT(int, CachedPhysBrushDataVersion, 564)
		ADD_STRUCT(BrushComponent__KCachedConvexData_Mirror, CachedPhysBrushData, 552)
		ADD_STRUCT(Object__Pointer, BrushPhysDesc, 548)
		ADD_STRUCT(KMeshProps__KAggregateGeom, BrushAggGeom, 492)
		ADD_OBJECT(Model, Brush, 488)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
