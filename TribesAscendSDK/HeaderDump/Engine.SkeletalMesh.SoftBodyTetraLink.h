#pragma once
namespace UnrealScript
{
	struct SkeletalMesh__SoftBodyTetraLink;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct SkeletalMesh__SoftBodyTetraLink
	{
	public:
		ADD_STRUCT(int, Index, 0)
		ADD_STRUCT(Vector, Bary, 4)
	};
}
#undef ADD_STRUCT
