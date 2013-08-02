#pragma once
namespace UnrealScript
{
	struct GFxObject__ASDisplayInfo;
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
	struct GFxObject__ASDisplayInfo
	{
	public:
		ADD_BOOL(hasVisible, 40, 0x800)
		ADD_BOOL(hasAlpha, 40, 0x400)
		ADD_BOOL(hasZScale, 40, 0x200)
		ADD_BOOL(hasYScale, 40, 0x100)
		ADD_BOOL(hasXScale, 40, 0x80)
		ADD_BOOL(hasYRotation, 40, 0x40)
		ADD_BOOL(hasXRotation, 40, 0x20)
		ADD_BOOL(hasRotation, 40, 0x10)
		ADD_BOOL(hasZ, 40, 0x8)
		ADD_BOOL(hasY, 40, 0x4)
		ADD_BOOL(hasX, 40, 0x2)
		ADD_BOOL(Visible, 40, 0x1)
		ADD_STRUCT(float, Alpha, 36)
		ADD_STRUCT(float, ZScale, 32)
		ADD_STRUCT(float, YScale, 28)
		ADD_STRUCT(float, XScale, 24)
		ADD_STRUCT(float, YRotation, 20)
		ADD_STRUCT(float, XRotation, 16)
		ADD_STRUCT(float, Rotation, 12)
		ADD_STRUCT(float, Z, 8)
		ADD_STRUCT(float, Y, 4)
		ADD_STRUCT(float, X, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
