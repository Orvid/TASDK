#pragma once
#include "Engine.StaticMesh.StaticMeshLODElement.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct StaticMesh__StaticMeshLODInfo
	{
	public:
		ADD_STRUCT(ScriptArray<StaticMesh__StaticMeshLODElement>, Elements, 0)
	};
}
#undef ADD_STRUCT
