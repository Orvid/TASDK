#pragma once
namespace UnrealScript
{
	class SeqAct_AddRemoveFaceFXAnimSet;
}
#include "Engine.FaceFXAnimSet.h"
#include "Engine.SequenceAction.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqAct_AddRemoveFaceFXAnimSet : public SequenceAction
	{
	public:
		ADD_STRUCT(ScriptArray<class FaceFXAnimSet*>, FaceFXAnimSets, 232)
	};
}
#undef ADD_STRUCT
