#pragma once
namespace UnrealScript
{
	class CoverMeshComponent;
}
#include "Engine.CoverMeshComponent.CoverMeshes.h"
#include "Engine.StaticMesh.h"
#include "Engine.StaticMeshComponent.h"
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
	class CoverMeshComponent : public StaticMeshComponent
	{
	public:
		typedef CoverMeshComponent__CoverMeshes CoverMeshes;
		ADD_STRUCT(ScriptArray<CoverMeshComponent__CoverMeshes>, Meshes, 608)
		ADD_BOOL(bShowWhenNotSelected, 644, 0x1)
		ADD_OBJECT(StaticMesh, Disabled, 640)
		ADD_OBJECT(StaticMesh, AutoAdjustOff, 636)
		ADD_OBJECT(StaticMesh, AutoAdjustOn, 632)
		ADD_STRUCT(Vector, LocationOffset, 620)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
