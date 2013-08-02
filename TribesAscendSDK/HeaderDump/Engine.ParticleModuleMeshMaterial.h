#pragma once
namespace UnrealScript
{
	class ParticleModuleMeshMaterial;
}
#include "Engine.MaterialInterface.h"
#include "Engine.ParticleModuleMaterialBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleMeshMaterial : public ParticleModuleMaterialBase
	{
	public:
		ADD_STRUCT(ScriptArray<class MaterialInterface*>, MeshMaterials, 72)
	};
}
#undef ADD_STRUCT
