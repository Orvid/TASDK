#pragma once
namespace UnrealScript
{
	class ApexDynamicComponent;
}
#include "Core.Object.Pointer.h"
#include "Engine.ApexComponentBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ApexDynamicComponent : public ApexComponentBase
	{
	public:
		ADD_STRUCT(Object__Pointer, ComponentDynamicResources, 520)
	};
}
#undef ADD_STRUCT
