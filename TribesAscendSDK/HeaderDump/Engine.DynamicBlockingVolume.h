#pragma once
#include "Engine.BlockingVolume.h"
#include "Engine.DynamicBlockingVolume.CheckpointRecord.h"
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
namespace UnrealScript
{
	class DynamicBlockingVolume : public BlockingVolume
	{
	public:
		ADD_BOOL(bEnabled, 524, 0x1)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14840);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CreateCheckpointRecord(DynamicBlockingVolume__CheckpointRecord& Record)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14841);
			byte params[28] = { NULL };
			*(DynamicBlockingVolume__CheckpointRecord*)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(DynamicBlockingVolume__CheckpointRecord*)params;
		}
		void ApplyCheckpointRecord(DynamicBlockingVolume__CheckpointRecord& Record)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(14843);
			byte params[28] = { NULL };
			*(DynamicBlockingVolume__CheckpointRecord*)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(DynamicBlockingVolume__CheckpointRecord*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
