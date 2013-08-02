#pragma once
namespace UnrealScript
{
	struct GameplayEvents__GameplayEventMetaData;
}
#include "Engine.GameplayEvents.GameStatGroup.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GameplayEvents__GameplayEventMetaData
	{
	public:
		ADD_STRUCT(int, EventDataType, 20)
		ADD_STRUCT(GameplayEvents__GameStatGroup, StatGroup, 12)
		ADD_STRUCT(ScriptName, EventName, 4)
		ADD_STRUCT(int, EventID, 0)
	};
}
#undef ADD_STRUCT
