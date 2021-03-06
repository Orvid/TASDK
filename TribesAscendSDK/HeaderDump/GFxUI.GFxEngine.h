#pragma once
namespace UnrealScript
{
	class GFxEngine;
}
#include "Core.Object.h"
#include "GFxUI.GFxEngine.GCReference.h"
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
	class GFxEngine : public Object
	{
	public:
		typedef GFxEngine__GCReference GCReference;
		ADD_STRUCT(ScriptArray<GFxEngine__GCReference>, GCReferences, 60)
		ADD_STRUCT(int, RefCount, 72)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
