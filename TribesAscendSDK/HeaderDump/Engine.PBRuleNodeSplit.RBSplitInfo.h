#pragma once
namespace UnrealScript
{
	struct PBRuleNodeSplit__RBSplitInfo;
}
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct PBRuleNodeSplit__RBSplitInfo
	{
	public:
		ADD_STRUCT(ScriptName, SplitName, 12)
		ADD_STRUCT(float, ExpandRatio, 8)
		ADD_STRUCT(float, FixedSize, 4)
		ADD_BOOL(bFixSize, 0, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
