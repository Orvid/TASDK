#pragma once
#include "Engine.K2NodeBase.h"
#include "Engine.DMC_Prototype.h"
#include "Engine.AIController.h"
#include "Engine.AITree.AITreeHandle.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class AICommandNodeBase : public K2NodeBase
	{
	public:
		ADD_OBJECT(DMC_Prototype, UtilityDMC, 96)
		ADD_OBJECT(ScriptClass, CommandClass, 92)
		class AICommandNodeBase* SelectBestChild(class AIController* InAI, AITree__AITreeHandle& Handle)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9704);
			byte params[56] = { NULL };
			*(class AIController**)params = InAI;
			*(AITree__AITreeHandle*)&params[4] = Handle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Handle = *(AITree__AITreeHandle*)&params[4];
			return *(class AICommandNodeBase**)&params[52];
		}
	};
}
#undef ADD_OBJECT
