#pragma once
namespace UnrealScript
{
	class ApexComponentBase;
}
#include "Core.Object.Color.h"
#include "Core.Object.Pointer.h"
#include "Core.Object.RenderCommandFence_Mirror.h"
#include "Engine.ApexAsset.h"
#include "Engine.MeshComponent.h"
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
	class ApexComponentBase : public MeshComponent
	{
	public:
		ADD_BOOL(bAssetChanged, 516, 0x1)
		ADD_STRUCT(Object__Color, WireframeColor, 512)
		ADD_OBJECT(ApexAsset, Asset, 508)
		ADD_STRUCT(Object__RenderCommandFence_Mirror, ReleaseResourcesFence, 504)
		ADD_STRUCT(Object__Pointer, ComponentBaseResources, 500)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
