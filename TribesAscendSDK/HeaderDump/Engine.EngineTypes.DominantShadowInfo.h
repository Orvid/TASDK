#pragma once
namespace UnrealScript
{
	struct EngineTypes__DominantShadowInfo;
}
#include "Core.Object.Box.h"
#include "Core.Object.Matrix.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct EngineTypes__DominantShadowInfo
	{
	public:
		ADD_STRUCT(int, ShadowMapSizeY, 160)
		ADD_STRUCT(int, ShadowMapSizeX, 156)
		ADD_STRUCT(Object__Box, LightSpaceImportanceBounds, 128)
		ADD_STRUCT(Object__Matrix, LightToWorld, 64)
		ADD_STRUCT(Object__Matrix, WorldToLight, 0)
	};
}
#undef ADD_STRUCT
