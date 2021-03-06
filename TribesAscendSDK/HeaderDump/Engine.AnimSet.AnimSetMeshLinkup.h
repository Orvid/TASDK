#pragma once
namespace UnrealScript
{
	struct AnimSet__AnimSetMeshLinkup;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct AnimSet__AnimSetMeshLinkup
	{
	public:
		ADD_STRUCT(ScriptArray<int>, BoneToTrackTable, 0)
	};
}
#undef ADD_STRUCT
