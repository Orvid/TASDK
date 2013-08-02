#pragma once
namespace UnrealScript
{
	struct KMeshProps__KAggregateGeom;
}
#include "Core.Object.Pointer.h"
#include "Engine.KMeshProps.KBoxElem.h"
#include "Engine.KMeshProps.KConvexElem.h"
#include "Engine.KMeshProps.KSphereElem.h"
#include "Engine.KMeshProps.KSphylElem.h"
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
namespace UnrealScript
{
	struct KMeshProps__KAggregateGeom
	{
	public:
		ADD_STRUCT(ScriptArray<KMeshProps__KSphereElem>, SphereElems, 0)
		ADD_STRUCT(ScriptArray<KMeshProps__KBoxElem>, BoxElems, 12)
		ADD_STRUCT(ScriptArray<KMeshProps__KSphylElem>, SphylElems, 24)
		ADD_STRUCT(ScriptArray<KMeshProps__KConvexElem>, ConvexElems, 36)
		ADD_BOOL(bSkipCloseAndParallelChecks, 52, 0x1)
		ADD_STRUCT(Object__Pointer, RenderInfo, 48)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
