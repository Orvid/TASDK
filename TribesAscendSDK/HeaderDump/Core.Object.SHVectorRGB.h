#pragma once
namespace UnrealScript
{
	struct Object__SHVectorRGB;
}
#include "Core.Object.SHVector.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__SHVectorRGB
	{
	public:
		ADD_STRUCT(Object__SHVector, R, 0)
		ADD_STRUCT(Object__SHVector, G, 48)
		ADD_STRUCT(Object__SHVector, B, 96)
	};
}
#undef ADD_STRUCT
