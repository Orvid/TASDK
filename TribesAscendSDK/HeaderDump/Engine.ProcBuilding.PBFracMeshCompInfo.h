#pragma once
namespace UnrealScript
{
	struct ProcBuilding__PBFracMeshCompInfo;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct ProcBuilding__PBFracMeshCompInfo
	{
	public:
		ADD_STRUCT(int, TopLevelScopeIndex, 4)
	};
}
#undef ADD_STRUCT
