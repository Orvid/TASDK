#pragma once
#include "Core.Object.Rotator.h"
#include "Core.Object.Vector.h"
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
	struct TrVehicleStation__VehicleSpawnInfo
	{
	public:
		ADD_STRUCT(Rotator, m_rSpawnRotOffset, 20)
		ADD_STRUCT(Vector, m_vSpawnLocOffset, 8)
		ADD_STRUCT(int, m_nMaxCount, 4)
		ADD_OBJECT(ScriptClass, m_VehicleClass, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
