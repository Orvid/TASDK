#pragma once
namespace UnrealScript
{
	class MeshComponentFactory;
}
#include "Engine.MaterialInterface.h"
#include "Engine.PrimitiveComponentFactory.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MeshComponentFactory : public PrimitiveComponentFactory
	{
	public:
		ADD_STRUCT(ScriptArray<class MaterialInterface*>, Materials, 64)
	};
}
#undef ADD_STRUCT
