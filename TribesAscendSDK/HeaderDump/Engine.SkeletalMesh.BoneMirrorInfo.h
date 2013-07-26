#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " SkeletalMesh.BoneMirrorInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class BoneMirrorInfo
	{
	public:
		ADD_VAR(::IntProperty, SourceIndex, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, BoneFlipAxis, 0xFFFFFFFF)
	};
}
#undef ADD_VAR