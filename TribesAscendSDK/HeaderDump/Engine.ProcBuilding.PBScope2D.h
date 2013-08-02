#pragma once
namespace UnrealScript
{
	struct ProcBuilding__PBScope2D;
}
#include "Core.Object.Matrix.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct ProcBuilding__PBScope2D
	{
	public:
		ADD_STRUCT(Object__Matrix, ScopeFrame, 0)
		ADD_STRUCT(float, DimX, 64)
		ADD_STRUCT(float, DimZ, 68)
	};
}
#undef ADD_STRUCT
