#pragma once
namespace UnrealScript
{
	class DrawBoxComponent;
}
#include "Core.Object.Color.h"
#include "Engine.Material.h"
#include "Engine.PrimitiveComponent.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class DrawBoxComponent : public PrimitiveComponent
	{
	public:
		ADD_BOOL(bDrawOnlyIfSelected, 508, 0x4)
		ADD_BOOL(bDrawLitBox, 508, 0x2)
		ADD_BOOL(bDrawWireBox, 508, 0x1)
		ADD_STRUCT(Vector, BoxExtent, 496)
		ADD_OBJECT(Material, BoxMaterial, 492)
		ADD_STRUCT(Object__Color, BoxColor, 488)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
