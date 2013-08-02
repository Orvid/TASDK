#pragma once
namespace UnrealScript
{
	struct InterpGroup__InterpEdSelKey;
}
#include "Engine.InterpGroup.h"
#include "Engine.InterpTrack.h"
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
	struct InterpGroup__InterpEdSelKey
	{
	public:
		ADD_STRUCT(float, UnsnappedPosition, 12)
		ADD_STRUCT(int, KeyIndex, 8)
		ADD_OBJECT(InterpTrack, Track, 4)
		ADD_OBJECT(InterpGroup, Group, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
