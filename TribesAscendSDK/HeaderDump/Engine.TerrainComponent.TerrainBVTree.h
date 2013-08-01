#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct TerrainComponent__TerrainBVTree
	{
	public:
		ADD_STRUCT(ScriptArray<int>, Nodes, 0)
	};
}
#undef ADD_STRUCT
