#pragma once
namespace UnrealScript
{
	class SeqAct_MultiLevelStreaming;
}
#include "Engine.SeqAct_LevelStreamingBase.h"
#include "Engine.SeqAct_MultiLevelStreaming.LevelStreamingNameCombo.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	class SeqAct_MultiLevelStreaming : public SeqAct_LevelStreamingBase
	{
	public:
		typedef SeqAct_MultiLevelStreaming__LevelStreamingNameCombo LevelStreamingNameCombo;
		ADD_STRUCT(ScriptArray<SeqAct_MultiLevelStreaming__LevelStreamingNameCombo>, Levels, 252)
		ADD_BOOL(bStatusIsOk, 264, 0x2)
		ADD_BOOL(bUnloadAllOtherLevels, 264, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
