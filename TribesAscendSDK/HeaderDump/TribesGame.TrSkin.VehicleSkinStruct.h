#pragma once
#include "Engine.AnimSet.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct TrSkin__VehicleSkinStruct
	{
	public:
		ADD_OBJECT(AnimSet, SeatAnimSet, 4)
		ADD_OBJECT(ScriptClass, VehicleClass, 0)
	};
}
#undef ADD_OBJECT
