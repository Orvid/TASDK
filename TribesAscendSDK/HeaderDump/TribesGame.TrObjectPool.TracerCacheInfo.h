#pragma once
#include "TribesGame.TrProj_Tracer.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct TrObjectPool__TracerCacheInfo
	{
	public:
		ADD_OBJECT(TrProj_Tracer, List, 12)
		ADD_STRUCT(int, ListIdx, 8)
		ADD_OBJECT(ScriptClass, TracerClass, 4)
		ADD_STRUCT(int, Type, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
