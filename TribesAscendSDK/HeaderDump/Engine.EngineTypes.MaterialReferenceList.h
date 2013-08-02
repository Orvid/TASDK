#pragma once
namespace UnrealScript
{
	struct EngineTypes__MaterialReferenceList;
}
#include "Engine.EngineTypes.PrimitiveMaterialRef.h"
#include "Engine.MaterialInterface.h"
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
	struct EngineTypes__MaterialReferenceList
	{
	public:
		ADD_STRUCT(ScriptArray<EngineTypes__PrimitiveMaterialRef>, AffectedMaterialRefs, 4)
		ADD_OBJECT(MaterialInterface, TargetMaterial, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
