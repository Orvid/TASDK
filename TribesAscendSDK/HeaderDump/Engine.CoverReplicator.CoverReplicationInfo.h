#pragma once
#include "Engine.CoverLink.h"
#include "Engine.CoverReplicator.ManualCoverTypeInfo.h"
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
	struct CoverReplicator__CoverReplicationInfo
	{
	public:
		ADD_STRUCT(ScriptArray<byte>, SlotsEnabled, 4)
		ADD_STRUCT(ScriptArray<byte>, SlotsDisabled, 16)
		ADD_STRUCT(ScriptArray<byte>, SlotsAdjusted, 28)
		ADD_STRUCT(ScriptArray<CoverReplicator__ManualCoverTypeInfo>, SlotsCoverTypeChanged, 40)
		ADD_OBJECT(CoverLink, Link, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
