#pragma once
namespace UnrealScript
{
	struct Console__AutoCompleteNode;
}
#include "Core.Object.Pointer.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Console__AutoCompleteNode
	{
	public:
		ADD_STRUCT(ScriptArray<int>, AutoCompleteListIndices, 4)
		ADD_STRUCT(ScriptArray<Object__Pointer>, ChildNodes, 16)
		ADD_STRUCT(int, IndexChar, 0)
	};
}
#undef ADD_STRUCT
