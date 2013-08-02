#pragma once
namespace UnrealScript
{
	struct UTGameReplicationInfo__MeshEffect;
}
#include "Engine.MaterialInterface.h"
#include "Engine.StaticMesh.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct UTGameReplicationInfo__MeshEffect
	{
	public:
		ADD_OBJECT(StaticMesh, Mesh, 0)
		ADD_OBJECT(MaterialInterface, Material, 4)
	};
}
#undef ADD_OBJECT
