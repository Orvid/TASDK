#pragma once
#include "PlatformCommon.TgStructures.CMTargetType.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct TgStructures__CombatMessageInfo
	{
	public:
		ADD_STRUCT(int, nSourceItemId, 32)
		ADD_STRUCT(int, nAmount2, 28)
		ADD_STRUCT(int, nAmount1, 24)
		ADD_STRUCT(TgStructures__CMTargetType, eTargetType, 20)
		ADD_STRUCT(int, nTargetId, 16)
		ADD_STRUCT(int, nSourceOwnerId, 12)
		ADD_STRUCT(TgStructures__CMTargetType, eSourceType, 8)
		ADD_STRUCT(int, nSourceId, 4)
		ADD_STRUCT(int, nMsgId, 0)
	};
}
#undef ADD_STRUCT
