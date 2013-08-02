#pragma once
namespace UnrealScript
{
	struct PrimitiveComponent__MaterialViewRelevance;
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
namespace UnrealScript
{
	struct PrimitiveComponent__MaterialViewRelevance
	{
	public:
		ADD_BOOL(bOpaque, 0, 0x1)
		ADD_BOOL(bTranslucent, 0, 0x2)
		ADD_BOOL(bDistortion, 0, 0x4)
		ADD_BOOL(bOneLayerDistortionRelevance, 0, 0x8)
		ADD_BOOL(bLit, 0, 0x10)
		ADD_BOOL(bUsesSceneColor, 0, 0x20)
	};
}
#undef ADD_BOOL
