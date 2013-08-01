#pragma once
#include "Engine.SequenceAction.h"
#include "TribesGame.TrVGSCommandList.VGSCommandType.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrSeqAct_PlayVGSCommand : public SequenceAction
	{
	public:
		ADD_STRUCT(ScriptString*, CommandInstigatorName, 236)
		ADD_STRUCT(TrVGSCommandList__VGSCommandType, VGSCommand, 232)
	};
}
#undef ADD_STRUCT
