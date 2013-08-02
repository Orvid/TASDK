#pragma once
namespace UnrealScript
{
	struct TrFamilyInfo__DeviceSelectionList;
}
#include "TribesGame.TrObject.TR_EQUIP_POINT.h"
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
	struct TrFamilyInfo__DeviceSelectionList
	{
	public:
		ADD_OBJECT(ScriptClass, DeviceClass, 4)
		ADD_STRUCT(TrObject__TR_EQUIP_POINT, EquipPoint, 0)
		ADD_STRUCT(ScriptString*, ContentDeviceClassString, 8)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
