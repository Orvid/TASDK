#pragma once
#include "Engine.LevelStreaming.h"
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
	struct SeqAct_MultiLevelStreaming__LevelStreamingNameCombo
	{
	public:
		ADD_STRUCT(ScriptName, LevelName, 4)
		ADD_OBJECT(LevelStreaming, Level, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
