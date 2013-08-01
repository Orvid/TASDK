#pragma once
#include "TribesGame.TrDevice.DeviceModification.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct TrDevice__DeviceUpgrade
	{
	public:
		ADD_STRUCT(int, DatabaseItemId, 4)
		ADD_STRUCT(int, IconId, 0)
		ADD_STRUCT(ScriptArray<TrDevice__DeviceModification>, Modifications, 8)
	};
}
#undef ADD_STRUCT
