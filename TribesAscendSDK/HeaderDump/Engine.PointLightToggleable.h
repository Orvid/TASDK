#pragma once
#include "Engine.PointLight.h"
#include "Engine.PointLightToggleable.CheckpointRecord.h"
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
	class PointLightToggleable : public PointLight
	{
	public:
		bool ShouldSaveForCheckpoint()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24664);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void CreateCheckpointRecord(PointLightToggleable__CheckpointRecord& Record)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24666);
			byte params[4] = { NULL };
			*(PointLightToggleable__CheckpointRecord*)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(PointLightToggleable__CheckpointRecord*)params;
		}
		void ApplyCheckpointRecord(PointLightToggleable__CheckpointRecord& Record)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24668);
			byte params[4] = { NULL };
			*(PointLightToggleable__CheckpointRecord*)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(PointLightToggleable__CheckpointRecord*)params;
		}
	};
}
#undef ADD_BOOL
