#pragma once
namespace UnrealScript
{
	struct StaticMeshActorBasedOnExtremeContent__SMMaterialSetterDatum;
}
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
	struct StaticMeshActorBasedOnExtremeContent__SMMaterialSetterDatum
	{
	public:
		ADD_OBJECT(MaterialInterface, TheMaterial, 4)
		ADD_STRUCT(int, MaterialIndex, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
