#pragma once
namespace UnrealScript
{
	struct SkeletalMeshComponent__BonePair;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct SkeletalMeshComponent__BonePair
	{
	public:
		ADD_STRUCT(ScriptName, Bones, 0)
	};
}
#undef ADD_STRUCT
