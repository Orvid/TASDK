#pragma once
namespace UnrealScript
{
	class Sequence;
}
#include "Core.Object.Pointer.h"
#include "Engine.Sequence.ActivateOp.h"
#include "Engine.Sequence.QueuedActivationInfo.h"
#include "Engine.SequenceEvent.h"
#include "Engine.SequenceObject.h"
#include "Engine.SequenceOp.h"
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
	class Sequence : public SequenceOp
	{
	public:
		typedef Sequence__ActivateOp ActivateOp;
		typedef Sequence__QueuedActivationInfo QueuedActivationInfo;
		ADD_STRUCT(ScriptArray<class SequenceObject*>, SequenceObjects, 212)
		ADD_STRUCT(ScriptArray<class SequenceOp*>, ActiveSequenceOps, 224)
		ADD_STRUCT(ScriptArray<class Sequence*>, NestedSequences, 236)
		ADD_STRUCT(ScriptArray<class SequenceEvent*>, UnregisteredEvents, 248)
		ADD_STRUCT(ScriptArray<Sequence__ActivateOp>, DelayedActivatedOps, 260)
		ADD_STRUCT(ScriptArray<Sequence__QueuedActivationInfo>, QueuedActivations, 276)
		ADD_STRUCT(float, DefaultViewZoom, 296)
		ADD_STRUCT(int, DefaultViewY, 292)
		ADD_STRUCT(int, DefaultViewX, 288)
		ADD_BOOL(bEnabled, 272, 0x1)
		ADD_STRUCT(Object__Pointer, LogFile, 208)
		void FindSeqObjectsByClass(ScriptClass* DesiredClass, bool bRecursive, ScriptArray<class SequenceObject*>& OutputObjects)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4291);
			byte params[20] = { NULL };
			*(ScriptClass**)params = DesiredClass;
			*(bool*)&params[4] = bRecursive;
			*(ScriptArray<class SequenceObject*>*)&params[8] = OutputObjects;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutputObjects = *(ScriptArray<class SequenceObject*>*)&params[8];
		}
		void FindSeqObjectsByName(ScriptString* SeqObjName, bool bCheckComment, ScriptArray<class SequenceObject*>& OutputObjects, bool bRecursive)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24824);
			byte params[32] = { NULL };
			*(ScriptString**)params = SeqObjName;
			*(bool*)&params[12] = bCheckComment;
			*(ScriptArray<class SequenceObject*>*)&params[16] = OutputObjects;
			*(bool*)&params[28] = bRecursive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutputObjects = *(ScriptArray<class SequenceObject*>*)&params[16];
		}
		void Reset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24830);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetEnabled(bool bInEnabled)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24833);
			byte params[4] = { NULL };
			*(bool*)params = bInEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
