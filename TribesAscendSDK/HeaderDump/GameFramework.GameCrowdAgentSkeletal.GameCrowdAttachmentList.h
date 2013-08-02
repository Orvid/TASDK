#pragma once
namespace UnrealScript
{
	struct GameCrowdAgentSkeletal__GameCrowdAttachmentList;
}
#include "GameFramework.GameCrowdAgentSkeletal.GameCrowdAttachmentInfo.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GameCrowdAgentSkeletal__GameCrowdAttachmentList
	{
	public:
		ADD_STRUCT(ScriptArray<GameCrowdAgentSkeletal__GameCrowdAttachmentInfo>, List, 8)
		ADD_STRUCT(ScriptName, SocketName, 0)
	};
}
#undef ADD_STRUCT
