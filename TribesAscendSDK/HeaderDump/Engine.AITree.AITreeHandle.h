#pragma once
namespace UnrealScript
{
	struct AITree__AITreeHandle;
}
#include "Engine.AICommandNodeBase.h"
#include "Engine.AICommandNodeRoot.h"
#include "Engine.AITree.AITreeUtilityInfo.h"
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
	struct AITree__AITreeHandle
	{
	public:
		ADD_STRUCT(ScriptArray<class AICommandNodeBase*>, DisabledNodes, 12)
		ADD_STRUCT(ScriptArray<AITree__AITreeUtilityInfo>, LastUtilityRatingList, 24)
		ADD_STRUCT(ScriptArray<AITree__AITreeUtilityInfo>, LastUtilityRatingListAtChange, 36)
		ADD_OBJECT(AICommandNodeRoot, ActiveRoot, 8)
		ADD_STRUCT(ScriptName, ActiveRootName, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
