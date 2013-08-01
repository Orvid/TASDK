#pragma once
#include "TribesGame.TrAnimNodeBlendList.h"
#include "Engine.AnimNodeAdditiveBlending.h"
#include "TribesGame.TrFlagBase.h"
#include "TribesGame.TrAnimNodeBlendByFlagDirection.EFlagAnimTypes.h"
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
	class TrAnimNodeBlendByFlagDirection : public TrAnimNodeBlendList
	{
	public:
		ADD_STRUCT(float, m_fIdleBlendOutTime, 320)
		ADD_STRUCT(float, m_fIdleBlendInTime, 316)
		ADD_OBJECT(AnimNodeAdditiveBlending, m_AdditiveBlendNode, 312)
		ADD_STRUCT(ScriptName, m_nmAdditiveAnimNodeName, 304)
		ADD_STRUCT(float, m_fIdleSpeedSizeSq, 300)
		ADD_OBJECT(TrFlagBase, m_TrFlagOwner, 296)
		ADD_STRUCT(TrAnimNodeBlendByFlagDirection__EFlagAnimTypes, LastDirection, 292)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
