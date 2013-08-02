#pragma once
namespace UnrealScript
{
	struct MorphNodeWeightBase__MorphNodeConn;
}
#include "Engine.MorphNodeBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct MorphNodeWeightBase__MorphNodeConn
	{
	public:
		ADD_STRUCT(ScriptArray<class MorphNodeBase*>, ChildNodes, 0)
		ADD_STRUCT(int, DrawY, 20)
		ADD_STRUCT(ScriptName, ConnName, 12)
	};
}
#undef ADD_STRUCT
