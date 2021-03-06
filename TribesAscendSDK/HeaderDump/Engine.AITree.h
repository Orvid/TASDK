#pragma once
namespace UnrealScript
{
	class AITree;
}
#include "Engine.AICommandNodeRoot.h"
#include "Engine.AIController.h"
#include "Engine.AITree.AITreeHandle.h"
#include "Engine.AITree.AITreeUtilityInfo.h"
#include "Engine.K2GraphBase.h"
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
	class AITree : public K2GraphBase
	{
	public:
		typedef AITree__AITreeUtilityInfo AITreeUtilityInfo;
		typedef AITree__AITreeHandle AITreeHandle;
		ADD_STRUCT(ScriptArray<class AICommandNodeRoot*>, RootList, 72)
		ADD_OBJECT(K2GraphBase, GatherList, 84)
		bool SetActiveRoot(ScriptName InName, AITree__AITreeHandle& Handle)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9992);
			byte params[60] = { NULL };
			*(ScriptName*)params = InName;
			*(AITree__AITreeHandle*)&params[8] = Handle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Handle = *(AITree__AITreeHandle*)&params[8];
			return *(bool*)&params[56];
		}
		ScriptArray<ScriptClass*> EvaluateTree(class AIController* InAI, AITree__AITreeHandle& Handle)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9996);
			byte params[64] = { NULL };
			*(class AIController**)params = InAI;
			*(AITree__AITreeHandle*)&params[4] = Handle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Handle = *(AITree__AITreeHandle*)&params[4];
			return *(ScriptArray<ScriptClass*>*)&params[52];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
