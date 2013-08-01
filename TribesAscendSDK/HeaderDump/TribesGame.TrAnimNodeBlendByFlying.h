#pragma once
#include "TribesGame.TrAnimNodeBlendByFlying.EFlyDirTypes.h"
#include "TribesGame.TrAnimNodeBlendList.h"
#include "TribesGame.TrPawn.h"
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
	class TrAnimNodeBlendByFlying : public TrAnimNodeBlendList
	{
	public:
		ADD_OBJECT(TrPawn, m_TrPawn, 296)
		ADD_STRUCT(TrAnimNodeBlendByFlying__EFlyDirTypes, LastDirection, 292)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
