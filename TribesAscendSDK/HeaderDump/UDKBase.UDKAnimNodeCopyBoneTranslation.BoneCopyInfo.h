#pragma once
namespace UnrealScript
{
	struct UDKAnimNodeCopyBoneTranslation__BoneCopyInfo;
}
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct UDKAnimNodeCopyBoneTranslation__BoneCopyInfo
	{
	public:
		ADD_STRUCT(int, DstBoneIndex, 20)
		ADD_STRUCT(int, SrcBoneIndex, 16)
		ADD_STRUCT(ScriptName, DstBoneName, 8)
		ADD_STRUCT(ScriptName, SrcBoneName, 0)
	};
}
#undef ADD_STRUCT
