#pragma once
namespace UnrealScript
{
	class InterpFilter;
}
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class InterpFilter : public Object
	{
	public:
		ADD_STRUCT(ScriptString*, Caption, 60)
	};
}
#undef ADD_STRUCT
