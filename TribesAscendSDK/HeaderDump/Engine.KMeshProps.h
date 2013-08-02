#pragma once
namespace UnrealScript
{
	class KMeshProps;
}
#include "Core.Object.h"
#include "Engine.KMeshProps.KAggregateGeom.h"
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
	class KMeshProps : public Object
	{
	public:
		typedef KMeshProps__KSphereElem KSphereElem;
		typedef KMeshProps__KBoxElem KBoxElem;
		typedef KMeshProps__KSphylElem KSphylElem;
		typedef KMeshProps__KConvexElem KConvexElem;
		typedef KMeshProps__KAggregateGeom KAggregateGeom;
		ADD_STRUCT(KMeshProps__KAggregateGeom, AggGeom, 72)
		ADD_STRUCT(Vector, COMNudge, 60)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
