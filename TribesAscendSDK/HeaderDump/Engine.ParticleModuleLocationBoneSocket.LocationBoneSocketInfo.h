#pragma once
namespace UnrealScript
{
	struct ParticleModuleLocationBoneSocket__LocationBoneSocketInfo;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct ParticleModuleLocationBoneSocket__LocationBoneSocketInfo
	{
	public:
		ADD_STRUCT(Vector, Offset, 8)
		ADD_STRUCT(ScriptName, BoneSocketName, 0)
	};
}
#undef ADD_STRUCT
