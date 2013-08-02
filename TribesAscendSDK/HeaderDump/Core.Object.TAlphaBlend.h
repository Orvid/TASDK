#pragma once
namespace UnrealScript
{
	struct Object__TAlphaBlend;
}
#include "Core.Object.AlphaBlendType.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__TAlphaBlend
	{
	public:
		ADD_STRUCT(float, AlphaIn, 0)
		ADD_STRUCT(float, AlphaOut, 4)
		ADD_STRUCT(float, AlphaTarget, 8)
		ADD_STRUCT(float, BlendTime, 12)
		ADD_STRUCT(float, BlendTimeToGo, 16)
		ADD_STRUCT(Object__AlphaBlendType, BlendType, 20)
	};
}
#undef ADD_STRUCT
