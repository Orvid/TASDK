#pragma once
#include "Engine.AnimSet.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct AnimTree__PreviewAnimSetsStruct
	{
	public:
		ADD_STRUCT(ScriptArray<class AnimSet*>, PreviewAnimSets, 8)
		ADD_STRUCT(ScriptName, DisplayName, 0)
	};
}
#undef ADD_STRUCT
