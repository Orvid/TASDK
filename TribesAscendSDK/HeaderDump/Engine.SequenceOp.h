#pragma once
namespace UnrealScript
{
	class SequenceOp;
}
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.Controller.h"
#include "Engine.InterpData.h"
#include "Engine.Pawn.h"
#include "Engine.SequenceObject.h"
#include "Engine.SequenceOp.SeqEventLink.h"
#include "Engine.SequenceOp.SeqOpInputLink.h"
#include "Engine.SequenceOp.SeqOpOutputInputLink.h"
#include "Engine.SequenceOp.SeqOpOutputLink.h"
#include "Engine.SequenceOp.SeqVarLink.h"
#include "Engine.SequenceVariable.h"
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
	class SequenceOp : public SequenceObject
	{
	public:
		typedef SequenceOp__SeqOpInputLink SeqOpInputLink;
		typedef SequenceOp__SeqOpOutputLink SeqOpOutputLink;
		typedef SequenceOp__SeqVarLink SeqVarLink;
		typedef SequenceOp__SeqEventLink SeqEventLink;
		typedef SequenceOp__SeqOpOutputInputLink SeqOpOutputInputLink;
		ADD_STRUCT(ScriptArray<SequenceOp__SeqOpInputLink>, InputLinks, 144)
		ADD_STRUCT(ScriptArray<SequenceOp__SeqOpOutputLink>, OutputLinks, 156)
		ADD_STRUCT(ScriptArray<SequenceOp__SeqVarLink>, VariableLinks, 168)
		ADD_STRUCT(ScriptArray<SequenceOp__SeqEventLink>, EventLinks, 180)
		ADD_STRUCT(int, SearchTag, 204)
		ADD_STRUCT(int, ActivateCount, 200)
		ADD_STRUCT(byte, GamepadID, 196)
		ADD_STRUCT(int, PlayerIndex, 192)
		ADD_BOOL(bPendingOutputConnectorRecalc, 140, 0x100)
		ADD_BOOL(bPendingInputConnectorRecalc, 140, 0x80)
		ADD_BOOL(bPendingVarConnectorRecalc, 140, 0x40)
		ADD_BOOL(bHaveMovingOutputConnector, 140, 0x20)
		ADD_BOOL(bHaveMovingInputConnector, 140, 0x10)
		ADD_BOOL(bHaveMovingVarConnector, 140, 0x8)
		ADD_BOOL(bAutoActivateOutputLinks, 140, 0x4)
		ADD_BOOL(bLatentExecution, 140, 0x2)
		ADD_BOOL(bActive, 140, 0x1)
		void GetObjectVars(ScriptArray<class Object*>& objVars, ScriptString* inDesc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4369);
			byte params[24] = { NULL };
			*(ScriptArray<class Object*>*)params = objVars;
			*(ScriptString**)&params[12] = inDesc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			objVars = *(ScriptArray<class Object*>*)params;
		}
		bool HasLinkedOps(bool bConsiderInputLinks)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6801);
			byte params[8] = { NULL };
			*(bool*)params = bConsiderInputLinks;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void GetLinkedObjects(ScriptArray<class SequenceObject*>& out_Objects, ScriptClass* ObjectType, bool bRecurse)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6804);
			byte params[20] = { NULL };
			*(ScriptArray<class SequenceObject*>*)params = out_Objects;
			*(ScriptClass**)&params[12] = ObjectType;
			*(bool*)&params[16] = bRecurse;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Objects = *(ScriptArray<class SequenceObject*>*)params;
		}
		void GetInterpDataVars(ScriptArray<class InterpData*>& outIData, ScriptString* inDesc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6812);
			byte params[24] = { NULL };
			*(ScriptArray<class InterpData*>*)params = outIData;
			*(ScriptString**)&params[12] = inDesc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			outIData = *(ScriptArray<class InterpData*>*)params;
		}
		void GetBoolVars(ScriptArray<byte>& boolVars, ScriptString* inDesc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6816);
			byte params[24] = { NULL };
			*(ScriptArray<byte>*)params = boolVars;
			*(ScriptString**)&params[12] = inDesc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			boolVars = *(ScriptArray<byte>*)params;
		}
		void LinkedVariables(ScriptClass* VarClass, class SequenceVariable*& OutVariable, ScriptString* inDesc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6820);
			byte params[20] = { NULL };
			*(ScriptClass**)params = VarClass;
			*(class SequenceVariable**)&params[4] = OutVariable;
			*(ScriptString**)&params[8] = inDesc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutVariable = *(class SequenceVariable**)&params[4];
		}
		bool ActivateOutputLink(int OutputIdx)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6824);
			byte params[8] = { NULL };
			*(int*)params = OutputIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ActivateNamedOutputLink(ScriptString* LinkDesc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6827);
			byte params[16] = { NULL };
			*(ScriptString**)params = LinkDesc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void Activated()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6830);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Deactivated()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6831);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void VersionUpdated(int OldVersion, int NewVersion)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6832);
			byte params[8] = { NULL };
			*(int*)params = OldVersion;
			*(int*)&params[4] = NewVersion;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PopulateLinkedVariableValues()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6835);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PublishLinkedVariableValues()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6836);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6837);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Pawn* GetPawn(class Actor* TheActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6838);
			byte params[8] = { NULL };
			*(class Actor**)params = TheActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Pawn**)&params[4];
		}
		class Controller* GetController(class Actor* TheActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6843);
			byte params[8] = { NULL };
			*(class Actor**)params = TheActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Controller**)&params[4];
		}
		void ForceActivateInput(int InputIdx)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6848);
			byte params[4] = { NULL };
			*(int*)params = InputIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ForceActivateOutput(int OutputIdx)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6850);
			byte params[4] = { NULL };
			*(int*)params = OutputIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
