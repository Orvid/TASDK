#pragma once
namespace UnrealScript
{
	struct LensFlareComponent__LensFlareElementMaterials;
}
#include "Engine.MaterialInterface.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct LensFlareComponent__LensFlareElementMaterials
	{
	public:
		ADD_STRUCT(ScriptArray<class MaterialInterface*>, ElementMaterials, 0)
	};
}
#undef ADD_STRUCT
