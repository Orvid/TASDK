#pragma once
namespace UnrealScript
{
	struct PBRuleNodeMesh__BuildingMeshInfo;
}
#include "Engine.MaterialInterface.h"
#include "Engine.PBRuleNodeMesh.BuildingMatOverrides.h"
#include "Engine.StaticMesh.h"
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
	struct PBRuleNodeMesh__BuildingMeshInfo
	{
	public:
		ADD_STRUCT(ScriptArray<class MaterialInterface*>, MaterialOverrides, 32)
		ADD_STRUCT(ScriptArray<PBRuleNodeMesh__BuildingMatOverrides>, SectionOverrides, 44)
		ADD_STRUCT(int, OverriddenMeshLightMapRes, 28)
		ADD_BOOL(bOverrideMeshLightMapRes, 24, 0x2)
		ADD_BOOL(bMeshScaleTranslation, 24, 0x1)
		ADD_STRUCT(float, Chance, 12)
		ADD_STRUCT(float, DimZ, 8)
		ADD_STRUCT(float, DimX, 4)
		ADD_OBJECT(StaticMesh, Mesh, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
