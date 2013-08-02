#pragma once
namespace UnrealScript
{
	struct Terrain__TerrainLayer;
}
#include "Core.Object.Color.h"
#include "Engine.TerrainLayerSetup.h"
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
	struct Terrain__TerrainLayer
	{
	public:
		ADD_STRUCT(int, MaxY, 44)
		ADD_STRUCT(int, MaxX, 40)
		ADD_STRUCT(int, MinY, 36)
		ADD_STRUCT(int, MinX, 32)
		ADD_STRUCT(Object__Color, WireframeColor, 28)
		ADD_STRUCT(Object__Color, HighlightColor, 24)
		ADD_BOOL(Hidden, 20, 0x4)
		ADD_BOOL(WireframeHighlighted, 20, 0x2)
		ADD_BOOL(Highlighted, 20, 0x1)
		ADD_STRUCT(int, AlphaMapIndex, 16)
		ADD_OBJECT(TerrainLayerSetup, Setup, 12)
		ADD_STRUCT(ScriptString*, Name, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
