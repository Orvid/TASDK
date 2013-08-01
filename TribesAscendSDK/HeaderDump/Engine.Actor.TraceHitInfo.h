#pragma once
#include "Engine.Material.h"
#include "Engine.PhysicalMaterial.h"
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
	struct Actor__TraceHitInfo
	{
	public:
		ADD_OBJECT(Material, Material, 0)
		ADD_OBJECT(PhysicalMaterial, PhysMaterial, 4)
		ADD_STRUCT(int, Item, 8)
		ADD_STRUCT(int, LevelIndex, 12)
		ADD_STRUCT(ScriptName, BoneName, 16)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
