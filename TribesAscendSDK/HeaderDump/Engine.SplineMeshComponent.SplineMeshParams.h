#pragma once
#include "Core.Object.Vector2D.h"
#include "Core.Object.Vector.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct SplineMeshComponent__SplineMeshParams
	{
	public:
		ADD_STRUCT(Object__Vector2D, EndOffset, 80)
		ADD_STRUCT(float, EndRoll, 76)
		ADD_STRUCT(Object__Vector2D, EndScale, 68)
		ADD_STRUCT(Vector, EndTangent, 56)
		ADD_STRUCT(Vector, EndPos, 44)
		ADD_STRUCT(Object__Vector2D, StartOffset, 36)
		ADD_STRUCT(float, StartRoll, 32)
		ADD_STRUCT(Object__Vector2D, StartScale, 24)
		ADD_STRUCT(Vector, StartTangent, 12)
		ADD_STRUCT(Vector, StartPos, 0)
	};
}
#undef ADD_STRUCT
