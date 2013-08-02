#pragma once
namespace UnrealScript
{
	class LevelStreamingVolume;
}
#include "Engine.LevelStreaming.h"
#include "Engine.LevelStreamingVolume.CheckpointRecord.h"
#include "Engine.LevelStreamingVolume.EStreamingVolumeUsage.h"
#include "Engine.SeqAct_Toggle.h"
#include "Engine.Volume.h"
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
	class LevelStreamingVolume : public Volume
	{
	public:
		typedef LevelStreamingVolume__EStreamingVolumeUsage EStreamingVolumeUsage;
		typedef LevelStreamingVolume__CheckpointRecord CheckpointRecord;
		ADD_STRUCT(ScriptArray<class LevelStreaming*>, StreamingLevels, 520)
		ADD_STRUCT(float, TestVolumeDistance, 540)
		ADD_STRUCT(LevelStreamingVolume__EStreamingVolumeUsage, Usage, 537)
		ADD_STRUCT(LevelStreamingVolume__EStreamingVolumeUsage, StreamingUsage, 536)
		ADD_BOOL(bTestDistanceToVolume, 532, 0x4)
		ADD_BOOL(bDisabled, 532, 0x2)
		ADD_BOOL(bEditorPreVisOnly, 532, 0x1)
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19395);
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CreateCheckpointRecord(LevelStreamingVolume__CheckpointRecord& Record)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19397);
			byte params[4] = { NULL };
			*(LevelStreamingVolume__CheckpointRecord*)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(LevelStreamingVolume__CheckpointRecord*)params;
		}
		void ApplyCheckpointRecord(LevelStreamingVolume__CheckpointRecord& Record)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19399);
			byte params[4] = { NULL };
			*(LevelStreamingVolume__CheckpointRecord*)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(LevelStreamingVolume__CheckpointRecord*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
