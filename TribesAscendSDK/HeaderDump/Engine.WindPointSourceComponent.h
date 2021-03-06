#pragma once
namespace UnrealScript
{
	class WindPointSourceComponent;
}
#include "Engine.WindDirectionalSourceComponent.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class WindPointSourceComponent : public WindDirectionalSourceComponent
	{
	public:
		ADD_STRUCT(float, Radius, 112)
	};
}
#undef ADD_STRUCT
