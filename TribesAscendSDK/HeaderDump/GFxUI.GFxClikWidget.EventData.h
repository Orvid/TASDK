#pragma once
namespace UnrealScript
{
	struct GFxClikWidget__EventData;
}
#include "GFxUI.GFxObject.h"
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
	struct GFxClikWidget__EventData
	{
	public:
		ADD_STRUCT(int, lastIndex, 32)
		ADD_STRUCT(int, Index, 28)
		ADD_STRUCT(int, Button, 24)
		ADD_STRUCT(int, mouseIndex, 20)
		ADD_STRUCT(int, Data, 16)
		ADD_STRUCT(ScriptString*, Type, 4)
		ADD_OBJECT(GFxObject, Target, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
