#pragma once
#include "Engine.SpotLight.h"
#include "Engine.SpotLightToggleable.CheckpointRecord.h"
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
namespace UnrealScript
{
	class SpotLightToggleable : public SpotLight
	{
	public:
		bool ShouldSaveForCheckpoint()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27194);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void CreateCheckpointRecord(SpotLightToggleable__CheckpointRecord& Record)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27196);
			byte params[4] = { NULL };
			*(SpotLightToggleable__CheckpointRecord*)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(SpotLightToggleable__CheckpointRecord*)params;
		}
		void ApplyCheckpointRecord(SpotLightToggleable__CheckpointRecord& Record)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27198);
			byte params[4] = { NULL };
			*(SpotLightToggleable__CheckpointRecord*)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(SpotLightToggleable__CheckpointRecord*)params;
		}
	};
}
#undef ADD_BOOL
