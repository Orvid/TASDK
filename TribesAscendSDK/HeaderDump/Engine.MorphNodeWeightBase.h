#pragma once
namespace UnrealScript
{
	class MorphNodeWeightBase;
}
#include "Engine.MorphNodeBase.h"
#include "Engine.MorphNodeWeightBase.MorphNodeConn.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MorphNodeWeightBase : public MorphNodeBase
	{
	public:
		typedef MorphNodeWeightBase__MorphNodeConn MorphNodeConn;
		ADD_STRUCT(ScriptArray<MorphNodeWeightBase__MorphNodeConn>, NodeConns, 108)
	};
}
#undef ADD_STRUCT
