#pragma once
namespace UnrealScript
{
	struct TrPawn__AssistInfo;
}
#include "TribesGame.TrPlayerController.h"
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
	struct TrPawn__AssistInfo
	{
	public:
		ADD_STRUCT(float, m_fDamagerTime, 8)
		ADD_STRUCT(int, m_AccumulatedDamage, 4)
		ADD_OBJECT(TrPlayerController, m_Damager, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
