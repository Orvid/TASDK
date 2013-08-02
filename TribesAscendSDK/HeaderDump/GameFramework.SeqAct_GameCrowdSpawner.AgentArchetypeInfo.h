#pragma once
namespace UnrealScript
{
	struct SeqAct_GameCrowdSpawner__AgentArchetypeInfo;
}
#include "Core.Object.h"
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
	struct SeqAct_GameCrowdSpawner__AgentArchetypeInfo
	{
	public:
		ADD_STRUCT(ScriptArray<class Object*>, GroupMembers, 16)
		ADD_STRUCT(int, CurrSpawned, 12)
		ADD_STRUCT(int, MaxAllowed, 8)
		ADD_STRUCT(float, FrequencyModifier, 4)
		ADD_OBJECT(Object, AgentArchetype, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
