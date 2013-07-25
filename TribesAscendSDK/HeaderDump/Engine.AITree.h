#pragma once
#include "Engine.K2GraphBase.h"
#include "Engine.AIController.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.AITree." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AITree : public K2GraphBase
	{
	public:
		ADD_OBJECT(K2GraphBase, GatherList)
		bool SetActiveRoot(ScriptName InName, 
// WARNING: Unknown structure type 'ScriptStruct Engine.AITree.AITreeHandle'!
void*& Handle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AITree.SetActiveRoot");
			byte* params = (byte*)malloc(60);
			*(ScriptName*)params = InName;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.AITree.AITreeHandle'!
void**)(params + 8) = Handle;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Handle = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.AITree.AITreeHandle'!
void**)(params + 8);
			auto returnVal = *(bool*)(params + 56);
			free(params);
			return returnVal;
		}
		
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* EvaluateTree(class AIController* InAI, 
// WARNING: Unknown structure type 'ScriptStruct Engine.AITree.AITreeHandle'!
void*& Handle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AITree.EvaluateTree");
			byte* params = (byte*)malloc(64);
			*(class AIController**)params = InAI;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.AITree.AITreeHandle'!
void**)(params + 4) = Handle;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Handle = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.AITree.AITreeHandle'!
void**)(params + 4);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 52);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_OBJECT
